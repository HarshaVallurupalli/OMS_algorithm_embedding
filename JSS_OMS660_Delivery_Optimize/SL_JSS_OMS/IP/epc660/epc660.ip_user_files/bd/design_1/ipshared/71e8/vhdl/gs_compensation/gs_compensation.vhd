----------------------------------------------------------------------------------
-- Company: ESPROS		
-- Engineer: msc
-- 
-- Create Date: 16/10/2019 09:58:51 AM
-- Design Name: gs_compensation 
-- Module Name: gs_compensation - Behavioral
--
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

library xil_defaultlib;
use xil_defaultlib.pkg_xilinx_xci_components.all;
use xil_defaultlib.pkg_reg_stage.all;

library UNISIM;
use UNISIM.VComponents.all;

-- gs_compensation
entity ip_gs_compensation is
    Generic (
	  NBITS_DATA_IN : positive := 12;
	  NBITS_RAM_IN : positive := 16;
	  NB_SHIFT_LEFT : positive := 4
	);
	Port ( 
	  clk_CI : in STD_LOGIC;								               
	  en_SI  : in STD_LOGIC;
         
	  gs_pulse_in_SI   : in  STD_LOGIC;
	  gs_data_in_DI    : in  STD_LOGIC_VECTOR(NBITS_DATA_IN-1 downto 0); -- MSB is sat bit
	  ram_pulse_in_SI  : in  STD_LOGIC;
	  ram_data_in_DI   : in  STD_LOGIC_VECTOR(NBITS_RAM_IN-1 downto 0);
	  ram_pulse_req_SO : out STD_LOGIC;
	  gs_pulse_out_SO  : out STD_LOGIC;	  
	  gs_data_out_DO   : out STD_LOGIC_VECTOR(NBITS_DATA_IN-1 downto 0)  -- MSB is sat bit
	);
end ip_gs_compensation;

architecture Behavioral of ip_gs_compensation is
	-- RAM
	signal ram_D        : std_logic_vector(NBITS_RAM_IN-1 downto 0); -- Stored 16b RAM data
	signal ram_hi_sel_S : std_logic := '1';                          -- Selects if higer or lower part of RAM is used
	
	-- Compensation
	constant NBITS_SHIFT : positive := 12;
	constant HALF_AMPLITUDE : signed(NBITS_SHIFT downto 0) := to_signed(1024, NBITS_SHIFT+1); -- half pos amplitude
    constant HALF_AMPLITUDE_LOG2 : positive := 10; -- log2(half pos amplitude)
    constant FULL_AMPLITUDE : signed(NBITS_SHIFT downto 0) := to_signed(2048, NBITS_SHIFT+1); -- full pos amplitude
    
    function toZeros (bitCount : positive) return std_logic_vector is
        constant r : std_logic_vector (bitCount-1 downto 0) := (others => '0');
    begin
        return r;
    end;
    
    
    
    
	signal gs_data_in_D  : std_logic_vector(NBITS_DATA_IN-1 downto 0); -- MSB is sat bit
	signal gs_data_D     : std_logic_vector(NBITS_DATA_IN-1 downto 0); -- MSB is sat bit
	signal gs_data_del_D : std_logic_vector(NBITS_DATA_IN-1 downto 0); -- MSB is sat bit
	signal dsnu_D : std_logic_vector(NBITS_RAM_IN/4+NB_SHIFT_LEFT-1 downto 0);
	signal prnu_D : std_logic_vector(NBITS_RAM_IN/4+NB_SHIFT_LEFT-1 downto 0);
	signal gs_data_prod_D : std_logic_vector(31 downto 0); -- Fixed values for divider
	signal gs_data_sum_D  : std_logic_vector(15 downto 0); -- Fixed values for divider
	signal gs_data_div_D : std_logic_vector(47 downto 0);  -- Fixed values for divider
	signal gs_data_tmp_D : std_logic_vector(NBITS_DATA_IN+NBITS_SHIFT downto 0);
	signal gs_sat_S : std_logic;
	
	-- output
	signal gs_pulse_div_S : std_logic := '0';
	signal pulse_cal_S    : std_logic := '0';
	signal pulse_out_S    : std_logic := '0';
begin

    -- Note ASC: based on external parts, ram_pulse_in_SI seems to be high 1 cycle after gs_pulse_in_SI
    --           and occurs even without ram_pulse_req_SO ......


	-- RAM pulse request
	process(gs_pulse_in_SI, ram_hi_sel_S)
	begin
		if ram_hi_sel_S = '1' then
			ram_pulse_req_SO <= gs_pulse_in_SI;
		else
			ram_pulse_req_SO <= '0';
		end if;
	end process;

	-- Fill RAM
  	process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if en_SI = '0' then
                ram_D                   <= (others => '0');  
                ram_D(NBITS_RAM_IN-1)   <= '1';
                ram_D(NBITS_RAM_IN/2-1) <= '1'; 
				pulse_cal_S <= '0';
				gs_data_in_D <= gs_data_in_DI;
            else
                if gs_pulse_in_SI = '1' then
                    gs_data_in_D <= gs_data_in_DI;
                end if;
                if ram_pulse_in_SI = '1' then
					ram_D <= ram_data_in_DI;
					pulse_cal_S <= '1';
				else
					pulse_cal_S <= '0';
				end if;
            end if;
        end if;
    end process;
  
  -- Select RAM higer/lower part
  	process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if en_SI = '0' then
                ram_hi_sel_S     <= '1';
            else
                if gs_pulse_in_SI = '1' then
					ram_hi_sel_S <= not ram_hi_sel_S;
				end if;
            end if;
        end if;
    end process;  
	
	process(ram_hi_sel_S, ram_D)
	begin
		if ram_hi_sel_S = '1' then
			dsnu_D <= ram_D(NBITS_RAM_IN/4*3-1 downto NBITS_RAM_IN/2) & "0000";
			prnu_D <= ram_D(NBITS_RAM_IN-1 downto NBITS_RAM_IN/4*3) & "0000";
		else
			dsnu_D <= ram_D(NBITS_RAM_IN/4-1 downto 0) & "0000";
			prnu_D <= ram_D(NBITS_RAM_IN/2-1 downto NBITS_RAM_IN/4) & "0000";
		end if;
	end process;
	
    -- Output with compensation
  	process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if en_SI = '0' then
                gs_data_out_DO <= gs_data_in_DI;
				gs_pulse_out_SO <= gs_pulse_in_SI;
            else
				gs_pulse_out_SO <= pulse_out_S;
                if pulse_out_S = '1' then
                    gs_data_out_DO <= gs_sat_S & gs_data_tmp_D(NBITS_DATA_IN-2 downto 0);
				end if;
            end if;
        end if;
    end process;  	
    
-- TODO_ASC: change order of compensation, 1) first offset, than division    
    
  	process(clk_CI)
        variable tmp_prod_v : signed(NBITS_SHIFT downto 0);
    begin
        if rising_edge(clk_CI) then
            if en_SI = '0' then
				gs_data_D     <= (others => '0');
				gs_pulse_div_S <= '0';
			elsif pulse_cal_S = '1' then
				-- Resize to match divider input width
				--gs_data_prod_D <= std_logic_vector(resize(signed('0' & gs_data_in_D(NBITS_DATA_IN-2 downto 0))*HALF_AMPLITUDE, 32));
                
                tmp_prod_v := signed('0' & gs_data_in_D(NBITS_DATA_IN-2 downto 0)) - signed(FULL_AMPLITUDE); -- gs_data_in_D - FULL_AMPLITUDE 
                tmp_prod_v := tmp_prod_v - signed(dsnu_D);  -- - dsnu_D
                if tmp_prod_v(tmp_prod_v'high) = '1' then
                    -- negative: saturate at zero
                    gs_data_prod_D  <= (others => '0');
                else
                    gs_data_prod_D <= std_logic_vector(resize(tmp_prod_v,32-HALF_AMPLITUDE_LOG2)) & toZeros(HALF_AMPLITUDE_LOG2); -- *HALF_AMPLITUDE
                end if;
                
				gs_data_sum_D  <= std_logic_vector(resize(HALF_AMPLITUDE+signed(prnu_D),16));
				gs_data_D      <= gs_data_in_D;
				gs_pulse_div_S <= '1';
		    else
		        gs_pulse_div_S <= '0';
            end if;
        end if;
    end process;  		
	
    -- Add divider delay
	i_reg_stage_out_pulse : ip_reg_stage
	generic map (
        NB_STAGES => 34
	)
    port map (
        en_DI      => en_SI,
        clk_CI     => clk_CI,
        data_DI(0) => gs_pulse_div_S,
        data_DO(0) => pulse_out_S
	);		
	
	i_reg_stage_data_delayed : ip_reg_stage
	generic map (
		BIT_WIDTH  => NBITS_DATA_IN,
        NB_STAGES  => 34
	)
    port map (
        en_DI   => en_SI,
        clk_CI  => clk_CI,
        data_DI => gs_data_D,
        data_DO => gs_data_del_D
	);	
    
	-- GS COMP divider (Xilinx primitive)
    i_gs_comp_div : div_gen_gs_comp
    port map (
        aclk                   => clk_CI,
        s_axis_divisor_tvalid  => gs_pulse_div_S ,
        s_axis_divisor_tdata   => gs_data_sum_D, -- 16b
        s_axis_dividend_tvalid => gs_pulse_div_S ,
        s_axis_dividend_tdata  => gs_data_prod_D, -- 32b
        m_axis_dout_tdata      => gs_data_div_D
      );	
    
	--gs_data_tmp_D <= std_logic_vector(signed(gs_data_div_D(NBITS_DATA_IN+NBITS_SHIFT+16 downto 16))-signed(dsnu_D));
    gs_data_tmp_D <= std_logic_vector(signed(gs_data_div_D(NBITS_DATA_IN+NBITS_SHIFT+16 downto 16)));   -- resize
	
	process (gs_data_del_D(NBITS_DATA_IN-1), gs_data_tmp_D)
	begin
		if gs_data_del_D(NBITS_DATA_IN-1) = '1' or unsigned(gs_data_tmp_D(NBITS_DATA_IN+NBITS_SHIFT downto NBITS_DATA_IN-1))>0 then
			gs_sat_S <= '1';
		else
			gs_sat_S <= '0';
		end if;
	end process;
	
	

end Behavioral;
-- End gs_compensation