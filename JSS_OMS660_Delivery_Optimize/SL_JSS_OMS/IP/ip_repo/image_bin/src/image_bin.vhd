----------------------------------------------------------------------------------
-- Company: ESPROS		
-- Engineer: msc
-- 
-- Create Date: 05/30/2018 09:58:51 AM
-- Design Name: image_bin	
-- Module Name: image_bin - Behavioral
--
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 2x2 Binning; can be bypassed by setting en_DI to '0'
-- 
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

-- image_bin
entity image_bin is
	Generic (
		NBITS_DATA : integer := 13;
		NBITS_ADDR : integer := 10
	);
	Port ( 
		-- inputs
		clk_CI              : in std_logic;
		en_DI               : in std_logic;
		reset_RBI           : in std_logic;
		pulse_DI            : in std_logic;
        data_in_DI          : in std_logic_vector(NBITS_DATA-1 downto 0);
        bad_pixel_DI        : in std_logic;
		bram_data_in_DI     : in std_logic_vector(NBITS_DATA+2 downto 0);
		reg_line_length_DI  : in std_logic_vector(8 downto 0);
		reg_pix_inter_en_SI : in std_logic;
		reg_adc_en_SI       : in std_logic;
		reg_remove_sat_en_SI : in std_logic;
		hsync_DI            : in std_logic; -- to add robustness; if needed
		vsync_DI            : in std_logic; -- to generate data start / end signals
		last_pulse_DI       : in std_logic;
		dcs_SI              : in STD_LOGIC_VECTOR (2 downto 0);
        dcs_last_SI         : in STD_LOGIC_VECTOR (2 downto 0);
        dual_mgx_en_SI      : in std_logic;
		-- outputs
		mask_first_SO       : out std_logic;
		data_out_DO         : out std_logic_vector(NBITS_DATA-1 downto 0);
		bram_data_out_DO    : out std_logic_vector(NBITS_DATA+2 downto 0);
		bram_wr_en_DO       : out std_logic;
		bram_wr_addr_DO     : out std_logic_vector(NBITS_ADDR-1 downto 0);
		bram_rd_en_DO       : out std_logic;
		bram_rd_addr_DO     : out std_logic_vector(NBITS_ADDR-1 downto 0);
		grey_out_DO         : out STD_LOGIC;
        dcs0_out_DO         : out STD_LOGIC;
        dcs1_out_DO         : out STD_LOGIC;
        dcs2_out_DO         : out STD_LOGIC;
        dcs3_out_DO         : out STD_LOGIC;
        last_out_DO         : out STD_LOGIC;
        bad_pixel_DO        : out std_logic;
		image_bin_done_DO   : out STD_LOGIC;
		diff_bram_rd_en_SO  : out std_logic;
        ambient_en_SO       : out STD_LOGIC);
end image_bin;

architecture Behavioral of image_bin is

	-- clock generation
	signal vsync_reg_D : std_logic_vector(1 downto 0);
	signal hsync_reg_D : std_logic_vector(1 downto 0);
	signal hsync_reset_RB : std_logic; -- hsync rising edge
	signal vsync_reset_RB : std_logic; -- vsync falling edge
	signal skip_clock_S : std_logic;
	signal gen_clock_S : std_logic;
	signal gen_clock_del_S : std_logic;
	signal stop_clock_S : std_logic;
	signal clk_cnt_D : unsigned(1 downto 0); -- generate clock cycle every 4th input clk cycle; to be checked, can be made slower if needed
	signal image_bin_done_D : std_logic;
	signal pulse_out_D : std_logic;
	signal pulse_out_reg_D : std_logic;
	signal pulse_out_del_D : std_logic_vector(2 downto 0);
	signal pulse_in_del_D : std_logic_vector(4 downto 0);
	
	-- internal line counter
	signal data_cnt_D : unsigned(9 downto 0); -- Countes data of two lines, max 2x 320
	signal second_half : std_logic;
	signal second_dcs : std_logic;
	signal reg_rst_del_RB : std_logic_vector(4 downto 0);
	signal reg_rst_RB : std_logic;
	
	-- data processing
	signal store_data_D : std_logic;
	signal reg_data_in_D : std_logic_vector(NBITS_DATA downto 0);
	signal data_sum_D : std_logic_vector(NBITS_DATA downto 0);
	signal data_sum_bram_D : std_logic_vector(NBITS_DATA+1 downto 0);
	signal data_sum_bram_div3_D : std_logic_vector(NBITS_DATA+1 downto 0);
	signal bad_pixel_sum_D : std_logic_vector(1 downto 0);
	signal bad_pixel_sum_del_D : std_logic_vector(1 downto 0);
	signal add1 : unsigned(NBITS_DATA downto 0);
	signal add2 : unsigned(NBITS_DATA downto 0);
	
	-- bram control
	signal bram_wr_en_D : std_logic_vector(1 downto 0);
	signal bram_wr_addr_D : unsigned(NBITS_ADDR-1 downto 0);
	signal bram_rd_addr_D : unsigned(NBITS_ADDR-1 downto 0);
	
	-- output stage
	signal data_out_D  : std_logic_vector(NBITS_DATA-1 downto 0);
	signal bad_pixel_D : std_logic;
	
	-- last clock pulse
	signal wait_last_S : std_logic;
	signal last_pulse_D : std_logic_vector(6 downto 0);
	
	-- dual mgx
	signal mask_first_reg_D : std_logic;
	signal dcs_S : std_logic_vector(2 downto 0);
	
	-- bad pixel compensation
	signal bad_pixel_reg_D : std_logic_vector(3 downto 0);
	signal data_out_badpix_D : std_logic_vector(NBITS_DATA-1 downto 0);
	signal data_0_D : std_logic_vector(NBITS_DATA-1 downto 0);
	signal data_1_D : std_logic_vector(NBITS_DATA-1 downto 0);
	signal data_2_D : std_logic_vector(NBITS_DATA-1 downto 0);
	signal data_3_D : std_logic_vector(NBITS_DATA-1 downto 0);
	signal data_03_D : std_logic_vector(NBITS_DATA downto 0);
	signal data_13_D : std_logic_vector(NBITS_DATA downto 0);
    signal bad_pix_out_D : std_logic;
    signal line_cnt_D : unsigned(8 downto 0); -- Countes data of one line, max 320
	signal line_end_S : std_logic;
	signal second_half_out : std_logic;
	signal gen_start_S : std_logic;
	
begin
    -- vsync / hsync
	-- clock skip/generation
	process(clk_CI)
	begin
		if rising_edge(clk_CI) then
			if reset_RBI = '0' then
				vsync_reg_D    <= "11";
                hsync_reg_D    <= "11";   
				hsync_reset_RB <= '1';
				vsync_reset_RB <= '1';
				skip_clock_S   <= '1';
				gen_clock_S    <= '0';
				gen_clock_del_S <= '0';
				stop_clock_S   <= '0';
				clk_cnt_D 	   <= (others => '0');		
				image_bin_done_D <= '0';
				second_dcs     <= '0';
			else
				gen_clock_del_S <= gen_clock_S;
                vsync_reg_D <= vsync_reg_D(0) & vsync_DI;
                hsync_reg_D <= hsync_reg_D(0) & hsync_DI;  
				if gen_clock_S = '1' or wait_last_S = '1' then
				    clk_cnt_D   <= clk_cnt_D + 1;
				else
				    clk_cnt_D <= (others => '0');
				end if;
				-- reset on hsync rising edge
				if (hsync_reg_D(1) = '0' and hsync_reg_D(0) = '1') then
					hsync_reset_RB <= '0';
				else
					hsync_reset_RB <= '1';
				end if;
				-- reset on vsync falling edge
				if (vsync_reg_D(0) = '0' and vsync_reg_D(1) = '1') then
					vsync_reset_RB <= '0';
				else
					vsync_reset_RB <= '1';
				end if;
				-- set skip on falling edge of vsync; reset on hsync_reset; line_clk = max
				if ((vsync_reg_D(1) = '1' and vsync_reg_D(0)  = '0') or stop_clock_S = '1' or (hsync_reg_D(1) = '1' and line_cnt_D = unsigned(reg_line_length_DI)-1 and en_DI = '0')) then
					skip_clock_S <= '1';
				elsif (hsync_reset_RB = '0' and en_DI = '1') or (line_cnt_D > 1 and en_DI = '0') then
					skip_clock_S <= '0';
				end if;
				-- generate clock after vsync high
				if (vsync_reg_D(1)  = '1' and vsync_reg_D(0)  = '0') or stop_clock_S = '1' or (line_cnt_D = unsigned(reg_line_length_DI)-2 and en_DI = '0') then
					gen_clock_S <= '0';
				elsif (vsync_reg_D(1)  = '0' and vsync_reg_D(0)  = '1') or (line_cnt_D = unsigned(reg_line_length_DI)-3 and en_DI = '0' and second_half_out = '1') then
					gen_clock_S <= '1';
				end if;				
				-- stop clock after 1x line length clock pulses generated
				if (vsync_reg_D(1)  = '1' and vsync_reg_D(0)  = '0') then
					stop_clock_S <= '0';
					image_bin_done_D <= '0';
				elsif (gen_clock_S = '1' and ((en_DI = '1' and second_half = '1') or (reg_pix_inter_en_SI = '1' and line_cnt_D = unsigned(reg_line_length_DI))) and stop_clock_S = '0') then
					stop_clock_S <= '1';
					image_bin_done_D <= '1';
				else
					image_bin_done_D <= '0';
				end if;
				-- second_dcs toggles on rising_edge of hsync
				if hsync_reset_RB = '0' then
				    second_dcs <= not second_dcs;
				end if;
			end if;
		end if;
	end process;
	
	image_bin_done_DO <= image_bin_done_D;
	
	-- pulse generation
	process(clk_CI)
	begin
		if rising_edge(clk_CI) then
			if reset_RBI = '0' or (en_DI = '0' and reg_pix_inter_en_SI='0') then
				pulse_out_D <= '0';
				pulse_out_del_D <= (others => '0');
				pulse_in_del_D <= (others => '0');
			else
				if en_DI = '1' then
					pulse_in_del_D <= pulse_in_del_D(3 downto 0) & pulse_DI;
				else
					if gen_clock_S = '1' or gen_clock_del_S = '1' then
						pulse_in_del_D <= pulse_in_del_D(3 downto 0) & pulse_out_D;
					else
						pulse_in_del_D <= pulse_in_del_D(3 downto 0) & pulse_DI;
					end if;
				end if;
				pulse_out_del_D <= pulse_out_del_D(1 downto 0) & pulse_out_D;
				if skip_clock_S = '1' and (second_half = '0' or en_DI = '0') then
					pulse_out_D <= '0';
				elsif gen_clock_S = '0' then
					pulse_out_D <= pulse_DI;
				elsif stop_clock_S = '0' then
					if clk_cnt_D = 3 then
						pulse_out_D <= '1';
					else
						pulse_out_D <= '0';
					end if;
				else
					pulse_out_D <= '0';
				end if;
			end if;
		end if;
	end process;
	
	-- internal data counter
	process(clk_CI)
	begin
		if rising_edge(clk_CI) then
			if reset_RBI = '0' or hsync_reset_RB = '0' or stop_clock_S = '1' then
				data_cnt_D <= (others => '0');
				reg_rst_del_RB <= (others => '1');
				reg_rst_RB <= '0';
				second_half <= '0';
			elsif pulse_DI = '1' or (clk_cnt_D = 3 and stop_clock_S = '0' and gen_clock_S = '1') then
				-- Reset data_cnt if line_length is reached
				if data_cnt_D = unsigned(reg_line_length_DI)-1 then
					data_cnt_D <= (others => '0');
					second_half <= '1'; -- after first line is done
				else
					data_cnt_D <= data_cnt_D + 1;
				end if;
				reg_rst_RB <= reg_rst_del_RB(4);
			else
				if data_cnt_D = unsigned(reg_line_length_DI)-1 and reg_rst_del_RB(2 downto 0) = "111" and reg_rst_RB = '1' and second_half = '0' then
					reg_rst_del_RB <= reg_rst_del_RB(3 downto 0) & '0';
				else
					reg_rst_del_RB <= reg_rst_del_RB(3 downto 0) & '1';
				end if;
				reg_rst_RB <= reg_rst_del_RB(4);
				if data_cnt_D = unsigned(reg_line_length_DI)-1 and (reg_rst_del_RB(3) = '0' or reg_rst_RB = '0') then
					second_half <= '1'; -- after first line is done
				end if;
			end if;
		end if;
	end process;
	
	-- data processing
	process(clk_CI)
	begin
		if rising_edge(clk_CI) then
			if reset_RBI = '0' or en_DI = '0' or reg_rst_RB ='0' then
				reg_data_in_D <= (others => '0');
			elsif pulse_in_del_D(1) = '1' then
				reg_data_in_D <= bad_pixel_DI & data_in_DI;
			end if;
		end if;
	end process;
	
	process(reg_data_in_D, data_in_DI, bad_pixel_DI, reg_pix_inter_en_SI, reg_adc_en_SI, line_cnt_D, reg_remove_sat_en_SI, reg_line_length_DI)
	begin
	    if (bad_pixel_DI = '0' or reg_pix_inter_en_SI = '0') and (reg_adc_en_SI = '0' or unsigned(data_in_DI(NBITS_DATA-2 downto 0))>0) and (reg_adc_en_SI = '0' or unsigned(data_in_DI(NBITS_DATA-2 downto 0))<4095) and (reg_remove_sat_en_SI = '0' or data_in_DI(NBITS_DATA-1) = '0') then
			add1 <= unsigned(data_in_DI(NBITS_DATA-1) & '0' & data_in_DI(NBITS_DATA-2 downto 0));
			if (reg_data_in_D(NBITS_DATA) = '0' or reg_pix_inter_en_SI = '0') and (reg_adc_en_SI = '0' or (unsigned(reg_data_in_D(NBITS_DATA-2 downto 0))>0) or (line_cnt_D < 2 and (en_DI = '0' or second_half = '0')) or (en_DI = '1' and line_cnt_D > unsigned(reg_line_length_DI)-1)) and (reg_adc_en_SI = '0' or unsigned(reg_data_in_D(NBITS_DATA-2 downto 0))<4095) and (reg_remove_sat_en_SI = '0' or reg_data_in_D(NBITS_DATA-1) = '0') then
				add2 <= unsigned(reg_data_in_D(NBITS_DATA-1) & '0' & reg_data_in_D(NBITS_DATA-2 downto 0));
				bad_pixel_sum_D <= "00";
			else
				add2 <= (others => '0');
				bad_pixel_sum_D <= "01";
			end if;
	    else
			add1 <= (others => '0');
			bad_pixel_sum_D(0) <= '1';	    
			if (reg_data_in_D(NBITS_DATA) = '0' or reg_pix_inter_en_SI = '0') and (reg_adc_en_SI = '0' or (unsigned(reg_data_in_D(NBITS_DATA-2 downto 0))>0 or (line_cnt_D < 2 and (en_DI = '0' or second_half = '0')) or (en_DI = '1' and line_cnt_D > unsigned(reg_line_length_DI)-1))) and (reg_adc_en_SI = '0' or unsigned(reg_data_in_D(NBITS_DATA-2 downto 0))<4095) and (reg_remove_sat_en_SI = '0' or reg_data_in_D(NBITS_DATA-1) = '0') then
				add2 <= unsigned(reg_data_in_D(NBITS_DATA-1) & '0' & reg_data_in_D(NBITS_DATA-2 downto 0));
				bad_pixel_sum_D <= "01";
			else
				add2 <= (others => '0');
				bad_pixel_sum_D <= "10";
			end if;
		end if;
	end process;
	
	process(clk_CI)
    begin
		if rising_edge(clk_CI) then
			if reset_RBI = '0' or en_DI = '0' or hsync_reset_RB = '0' then
			    store_data_D      <= '0';
				data_sum_D        <= (others => '0');
			elsif pulse_DI = '1' or (clk_cnt_D = 3 and stop_clock_S = '0' and gen_clock_S = '1') then
			    store_data_D      <= '1';
			elsif store_data_D = '1' then
				data_sum_D <= (add1(NBITS_DATA) or add2(NBITS_DATA)) & std_logic_vector(add1(NBITS_DATA-1 downto 0) + add2(NBITS_DATA-1 downto 0));
				store_data_D <= '0';
		    else
		        store_data_D <= '0';
			end if;
		end if;
    end process;
	
	bram_data_out_DO <= bad_pixel_sum_D & data_sum_D;
	
	-- bram control
	process(clk_CI)
	begin
		if rising_edge(clk_CI) then
			if reset_RBI = '0' or en_DI = '0' or hsync_reset_RB = '0' then
				bram_wr_en_D        <= (others => '0');
				bram_wr_en_DO       <= '0'; 
				bram_wr_addr_D      <= (others => '1');
				bram_rd_en_DO       <= '0';
				bram_rd_addr_D      <= (others => '1');
			elsif pulse_DI = '1' or (clk_cnt_D = 3 and stop_clock_S = '0' and gen_clock_S = '1') then
				if skip_clock_S = '1' then -- only write to BRAM
					bram_wr_en_D        <= bram_wr_en_D(0) & '1';
					bram_wr_addr_D      <= bram_wr_addr_D + 1;
					-- Read First line, while processing 2nd one
					if second_half = '1' then
						bram_rd_en_DO       <= '1';
						bram_rd_addr_D      <= bram_rd_addr_D + 1;
					else
						bram_rd_en_DO       <= '0';
						bram_rd_addr_D      <= (others => '1');
					end if;
				elsif gen_clock_S = '1' then -- only read from BRAM
					bram_wr_en_D        <= bram_wr_en_D(0) & '0';
					bram_wr_addr_D      <= (others => '1');	
					bram_rd_en_DO       <= '1';
					bram_rd_addr_D      <= bram_rd_addr_D + 1;						
				else
					bram_wr_en_D        <= bram_wr_en_D(0) & '1';
					bram_wr_addr_D      <= bram_wr_addr_D + 1;
					bram_rd_en_DO       <= '1';
					bram_rd_addr_D      <= bram_rd_addr_D + 1;				
				end if;
			 else
				 bram_wr_en_D <= bram_wr_en_D(0) & '0';
			     bram_wr_en_DO <= bram_wr_en_D(0);
			     bram_rd_en_DO <= '0';
			 end if;
		end if;
	end process;
	
	bram_wr_addr_DO <= std_logic_vector(bram_wr_addr_D);
	bram_rd_addr_DO <= std_logic_vector(bram_rd_addr_D);
	
	-- sum input data & bram
	process(data_sum_D, bram_data_in_DI)
	begin
		data_sum_bram_D <= (data_sum_D(NBITS_DATA) or bram_data_in_DI(NBITS_DATA+1) or bram_data_in_DI(NBITS_DATA)) & std_logic_vector(unsigned('0' & data_sum_D(NBITS_DATA-1 downto 0)) + unsigned('0' & bram_data_in_DI(NBITS_DATA-1 downto 0)));
	end process;
	
	-- divide by 3
	process(data_sum_bram_D)
	begin
	   data_sum_bram_div3_D <= data_sum_bram_D(NBITS_DATA+1) & std_logic_vector(unsigned(data_sum_bram_D(NBITS_DATA downto 0))/3);
	end process;
	
	-- sample bad_pixel_sum_D
	process(clk_CI)
	begin
		if rising_edge(clk_CI) then
			if reset_RBI = '0' then
				bad_pixel_sum_del_D <= "00";
			else
				bad_pixel_sum_del_D <= bad_pixel_sum_D;
			end if;
		end if;
	end process;
	
	-- output data
	process(data_sum_D, bram_data_in_DI, data_sum_bram_D, skip_clock_S, stop_clock_S, data_cnt_D, gen_clock_S, second_half, bad_pixel_sum_del_D, data_sum_bram_div3_D)
	begin
		-- if data_cnt_D == 0 -> divide by 1 less, because input_reg is 0
		if data_cnt_D = 1 then 
			if skip_clock_S = '1' and second_half = '0' and stop_clock_S = '0' then -- division by 1 
				data_out_D <= data_sum_D(NBITS_DATA) & data_sum_D(NBITS_DATA-2 downto 0); -- Sat + Data
			elsif gen_clock_S = '1' or stop_clock_S = '1' then -- division by 1 ; added or stop_clock for the last pixel data, where gen_clock is already '0'
				data_out_D <= bram_data_in_DI(NBITS_DATA) & bram_data_in_DI(NBITS_DATA-2 downto 0); 
			else -- division by 2
			    if bram_data_in_DI(NBITS_DATA+1) = '0' and bram_data_in_DI(NBITS_DATA+2) = '0' then
				    data_out_D <= data_sum_bram_D(NBITS_DATA downto 1); 
				else
				    data_out_D <= data_sum_bram_D(NBITS_DATA) & data_sum_bram_D(NBITS_DATA-2 downto 0); -- division by 1, if one of the inputs is a bad pixel
				end if;
			end if;
		else
			if skip_clock_S = '1' and second_half = '0' and stop_clock_S = '0' then -- division by 2
			    if bad_pixel_sum_del_D(0) = '0' and bad_pixel_sum_del_D(1) = '0'  then
				    data_out_D <= data_sum_D(NBITS_DATA downto 1);
				else
				    data_out_D <= data_sum_D(NBITS_DATA) & data_sum_D(NBITS_DATA-2 downto 0);
				end if;
			elsif gen_clock_S = '1' or stop_clock_S = '1' then -- division by 2 ; added or stop_clock for the last pixel data, where gen_clock is already '0'
			    if bram_data_in_DI(NBITS_DATA+1) = '0' and bram_data_in_DI(NBITS_DATA+2) = '0' then
				    data_out_D <= bram_data_in_DI(NBITS_DATA downto 1); 
				else
				    data_out_D <= bram_data_in_DI(NBITS_DATA) & bram_data_in_DI(NBITS_DATA-2 downto 0); 
				end if;
			else -- division by 4
			    if (bram_data_in_DI(NBITS_DATA+2) = '1' and bad_pixel_sum_del_D(0) = '1') or (bram_data_in_DI(NBITS_DATA+1) = '1' and bad_pixel_sum_del_D(1) = '1') then -- -3
				    data_out_D <= data_sum_bram_D(NBITS_DATA) & data_sum_bram_D(NBITS_DATA-2 downto 0); 
				elsif (bram_data_in_DI(NBITS_DATA+2) = '1' or bad_pixel_sum_del_D(1) = '1' or (bad_pixel_sum_del_D(0) = '1' and bram_data_in_DI(NBITS_DATA+1) = '1')) then -- -2
				    data_out_D <= data_sum_bram_D(NBITS_DATA downto 1);
				elsif bad_pixel_sum_del_D(0) = '1' or bram_data_in_DI(NBITS_DATA+1) = '1' then
				    data_out_D <= data_sum_bram_div3_D(NBITS_DATA) & data_sum_bram_div3_D(NBITS_DATA-2 downto 0);
				else
				    data_out_D <= data_sum_bram_D(NBITS_DATA+1 downto 2);
				end if;
			end if;
		end if;
	end process;
	
	process(bram_data_in_DI, bad_pixel_sum_del_D)
	begin
	   if bram_data_in_DI(NBITS_DATA+2) = '1' and bad_pixel_sum_del_D(1) = '1' then
	       bad_pixel_D <= '1';
	   else
	       bad_pixel_D <= '0';
	   end if;
	end process;
	
	-- bad pixel interpolation
	process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if reset_RBI = '0' or line_end_S = '1' then
				line_end_S <= '0';
                bad_pixel_reg_D <= (others => '0');
                data_0_D <= (others => '0');
                data_1_D <= (others => '0');
                data_2_D <= (others => '0');
                data_3_D <= (others => '0');
                line_cnt_D <= (others => '0');
				second_half_out <= '0';
				gen_start_S <= '0';
            elsif pulse_in_del_D(1) = '1' then
				if gen_clock_S = '1' then
					gen_start_S <= '1';
				end if;
                bad_pixel_reg_D <= bad_pixel_reg_D(2 downto 0) & bad_pixel_DI;
                data_0_D <= data_in_DI;
                data_1_D <= data_0_D;
                data_2_D <= data_1_D;
                data_3_D <= data_2_D;
                if line_cnt_D < unsigned(reg_line_length_DI)+2 then
                    line_cnt_D <= line_cnt_D + 1;
                else
                    line_cnt_D <= (others => '0');
					second_half_out <= '1';
                end if;
			elsif pulse_in_del_D(4) = '1' and second_half_out = '1' and (line_cnt_D = unsigned(reg_line_length_DI)-1 or (line_cnt_D = unsigned(reg_line_length_DI)-3 and en_DI = '1')) then
				line_end_S <= '1';
            end if;	
        end if;
    end process;
    
    -- data sum
    process(data_0_D, data_1_D, data_3_D)
    begin
        data_13_D <= std_logic_vector((data_1_D(NBITS_DATA-1) or data_3_D(NBITS_DATA-1)) & unsigned('0' & data_1_D(NBITS_DATA-2 downto 0)) + unsigned('0' & data_3_D(NBITS_DATA-2 downto 0)));
        data_03_D <= std_logic_vector((data_0_D(NBITS_DATA-1) or data_3_D(NBITS_DATA-1)) & unsigned('0' & data_0_D(NBITS_DATA-2 downto 0)) + unsigned('0' & data_3_D(NBITS_DATA-2 downto 0)));
    end process;
    
    -- data out bad pix
    process(data_13_D, data_03_D, data_2_D, data_3_D, data_0_D, data_1_D, line_cnt_D, bad_pixel_reg_D, reg_adc_en_SI, reg_remove_sat_en_SI, reg_line_length_DI)
    begin
        if (line_cnt_D = 3 and second_half = '0') or (line_cnt_D = 0 and second_half = '1') then -- first element
            -- No saturation or disabled
            if bad_pixel_reg_D(2) = '0' and (reg_adc_en_SI = '0' or (unsigned(data_2_D(NBITS_DATA-2 downto 0))>0 and unsigned(data_2_D(NBITS_DATA-2 downto 0))<4095)) and (reg_remove_sat_en_SI = '0' or data_2_D(NBITS_DATA-1) = '0') then
                data_out_badpix_D <= data_2_D;
                bad_pix_out_D <= '0';
            elsif bad_pixel_reg_D(1) = '0' and (reg_adc_en_SI = '0' or (unsigned(data_1_D(NBITS_DATA-2 downto 0))>0 and unsigned(data_1_D(NBITS_DATA-2 downto 0))<4095)) and (reg_remove_sat_en_SI = '0' or data_1_D(NBITS_DATA-1) = '0') then
                data_out_badpix_D <= data_1_D;
                bad_pix_out_D <= '0';
            else
                data_out_badpix_D <= data_0_D;
                if bad_pixel_reg_D(0) = '0' then
                    bad_pix_out_D <= '0';
                else
                    bad_pix_out_D <= '1';
                end if;
            end if;
         elsif line_cnt_D = unsigned(reg_line_length_DI)+1 then -- second last element
            -- if 2 is ok
            if bad_pixel_reg_D(2) = '0' and (reg_adc_en_SI = '0' or (unsigned(data_2_D(NBITS_DATA-2 downto 0))>0 and unsigned(data_2_D(NBITS_DATA-2 downto 0))<4095)) and (reg_remove_sat_en_SI = '0' or data_2_D(NBITS_DATA-1) = '0') then
                data_out_badpix_D <= data_2_D;
                bad_pix_out_D <= '0';
            -- Check if 1 and 3 are ok
            elsif bad_pixel_reg_D(1) = '0' and (reg_adc_en_SI = '0' or (unsigned(data_1_D(NBITS_DATA-2 downto 0))>0 and unsigned(data_1_D(NBITS_DATA-2 downto 0))<4095)) and (reg_remove_sat_en_SI = '0' or data_1_D(NBITS_DATA-1) = '0') and bad_pixel_reg_D(3) = '0' and (reg_adc_en_SI = '0' or (unsigned(data_3_D(NBITS_DATA-2 downto 0))>0 and unsigned(data_3_D(NBITS_DATA-2 downto 0))<4095)) and (reg_remove_sat_en_SI = '0' or data_3_D(NBITS_DATA-1) = '0') then
                data_out_badpix_D <= data_13_D(NBITS_DATA downto 1);
                bad_pix_out_D <= '0';
            -- Check 3 is ok
            elsif  bad_pixel_reg_D(3) = '0' and (reg_adc_en_SI = '0' or (unsigned(data_3_D(NBITS_DATA-2 downto 0))>0 and unsigned(data_3_D(NBITS_DATA-2 downto 0))<4095)) and (reg_remove_sat_en_SI = '0' or data_3_D(NBITS_DATA-1) = '0') then
                data_out_badpix_D <= data_3_D;
                bad_pix_out_D <= '0';                
            else
                data_out_badpix_D <= data_1_D;
                if bad_pixel_reg_D(1) = '0' then
                    bad_pix_out_D <= '0';
                else
                    bad_pix_out_D <= '1';
                end if;                              
            end if;         
         elsif line_cnt_D = unsigned(reg_line_length_DI)+2 then -- last element
            -- No saturation or disabled
            if bad_pixel_reg_D(2) = '0' and (reg_adc_en_SI = '0' or (unsigned(data_2_D(NBITS_DATA-2 downto 0))>0 and unsigned(data_2_D(NBITS_DATA-2 downto 0))<4095)) and (reg_remove_sat_en_SI = '0' or data_2_D(NBITS_DATA-1) = '0') then
                data_out_badpix_D <= data_2_D;
                bad_pix_out_D <= '0';
            else
                data_out_badpix_D <= data_3_D;
                if bad_pixel_reg_D(3) = '0' then
                    bad_pix_out_D <= '0';
                else
                    bad_pix_out_D <= '1';
                end if; 
            end if;       
         else --if line_cnt_D > 3 then -- intermediate element
            -- if 2 is ok
            if bad_pixel_reg_D(2) = '0' and (reg_adc_en_SI = '0' or (unsigned(data_2_D(NBITS_DATA-2 downto 0))>0 and unsigned(data_2_D(NBITS_DATA-2 downto 0))<4095)) and (reg_remove_sat_en_SI = '0' or data_2_D(NBITS_DATA-1) = '0') then
                data_out_badpix_D <= data_2_D;
                bad_pix_out_D <= '0';
            -- check if 3 is ok
            elsif bad_pixel_reg_D(3) = '0' and (reg_adc_en_SI = '0' or (unsigned(data_3_D(NBITS_DATA-2 downto 0))>0 and unsigned(data_3_D(NBITS_DATA-2 downto 0))<4095)) and (reg_remove_sat_en_SI = '0' or data_3_D(NBITS_DATA-1) = '0') then
                -- check if 1 is ok
                if bad_pixel_reg_D(1) = '0' and (reg_adc_en_SI = '0' or (unsigned(data_1_D(NBITS_DATA-2 downto 0))>0 and unsigned(data_1_D(NBITS_DATA-2 downto 0))<4095)) and (reg_remove_sat_en_SI = '0' or data_1_D(NBITS_DATA-1) = '0') then
                    data_out_badpix_D <= data_13_D(NBITS_DATA downto 1);
                    bad_pix_out_D <= '0';       
                -- check if 0 i s ok
                elsif bad_pixel_reg_D(0) = '0' and (reg_adc_en_SI = '0' or (unsigned(data_0_D(NBITS_DATA-2 downto 0))>0 and unsigned(data_0_D(NBITS_DATA-2 downto 0))<4095)) and (reg_remove_sat_en_SI = '0' or data_0_D(NBITS_DATA-1) = '0') then
                    data_out_badpix_D <= data_03_D(NBITS_DATA downto 1);
                    bad_pix_out_D <= '0'; 
                else -- take 3
                    data_out_badpix_D <= data_3_D;
                    bad_pix_out_D <= '0';
                end if;
            -- Check 1
            elsif bad_pixel_reg_D(1) = '0' and (reg_adc_en_SI = '0' or (unsigned(data_1_D(NBITS_DATA-2 downto 0))>0 and unsigned(data_1_D(NBITS_DATA-2 downto 0))<4095)) and (reg_remove_sat_en_SI = '0' or data_1_D(NBITS_DATA-1) = '0') then
                data_out_badpix_D <= data_1_D;
                bad_pix_out_D <= '0';   
            -- Check 0
            elsif bad_pixel_reg_D(0) = '0' and (reg_adc_en_SI = '0' or (unsigned(data_0_D(NBITS_DATA-2 downto 0))>0 and unsigned(data_0_D(NBITS_DATA-2 downto 0))<4095)) and (reg_remove_sat_en_SI = '0' or data_0_D(NBITS_DATA-1) = '0') then
                data_out_badpix_D <= data_0_D;
                bad_pix_out_D <= '0';
            -- Take 2
            else     
                data_out_badpix_D <= data_2_D;
                bad_pix_out_D <= bad_pixel_reg_D(2);                                                 
            end if;
         end if;
    end process;
    
	-- output stage
	process(clk_CI)
	begin
		if rising_edge(clk_CI) then
			if reset_RBI = '0' then
				data_out_DO  <= (others => '0');
				pulse_out_reg_D <= '0';
				last_out_DO  <= '0';
				mask_first_SO  <= '1'; 
				mask_first_reg_D <= '1';
				bad_pixel_DO <= '0';
			elsif en_DI = '0' and reg_pix_inter_en_SI = '0' then -- bypass
			    data_out_DO  <= data_in_DI;
				pulse_out_reg_D <= pulse_DI;
				bad_pixel_DO <= bad_pixel_DI;
				if (vsync_reg_D(1)  = '1' and vsync_reg_D(0)  = '0') then
				    mask_first_SO  <= '1';
				    mask_first_reg_D <= '1';
				elsif hsync_reset_RB = '0' then
					mask_first_reg_D <= '0';
				elsif pulse_out_reg_D = '1' then
				    if dual_mgx_en_SI = '1' then
				        mask_first_SO <= mask_first_reg_D; 
				    else
				        mask_first_SO  <= '0';
				    end if;
				end if; 
				if dcs_SI = dcs_last_SI then
				    last_out_DO <= last_pulse_DI or last_pulse_D(4);
				else
				    last_out_DO <= '0';
				end if;
			elsif en_DI = '0' then -- interpolate bad pixels
			    data_out_DO <= data_out_badpix_D;
				if gen_clock_S = '1' or gen_start_S = '1' then
					if pulse_out_reg_D = '0' then -- prevent double pulses, when switching gen_clock_S to 1
						pulse_out_reg_D <= pulse_out_del_D(2);
					else
						pulse_out_reg_D <= '0'; 
					end if;
				else
					pulse_out_reg_D <= pulse_out_del_D(1);
				end if;
			    bad_pixel_DO <= bad_pix_out_D;
			    last_out_DO <= last_pulse_D(2) or last_pulse_D(6);
			    if (vsync_reg_D(1)  = '1' and vsync_reg_D(0)  = '0') then
                    mask_first_SO  <= '1';
                elsif pulse_out_del_D(2) = '1' then
                    mask_first_SO <= '0'; 
                end if;
			else
				if pulse_out_del_D(1) = '1' then
					data_out_DO   <= data_out_D;
					bad_pixel_DO  <= bad_pixel_D; -- only if all 4 pixels are bad
				end if;
				if (vsync_reg_D(1)  = '1' and vsync_reg_D(0)  = '0') then
                    mask_first_SO  <= '1';
                elsif pulse_out_del_D(2) = '1' then
                    mask_first_SO <= '0'; 
                end if;
				pulse_out_reg_D <= pulse_out_del_D(1);
				last_out_DO <= last_pulse_D(2) or last_pulse_D(6);
			end if;
		end if;
	end process;
	
	-- generate last pulse
	process(clk_CI)
	begin
	   if rising_edge(clk_CI) then
          if reset_RBI = '0' then
             wait_last_S <= '0';
             last_pulse_D <= (others => '0');	
          else
			if en_DI = '1' then
				if wait_last_S = '0' and gen_clock_S = '1' and dcs_SI = dcs_last_SI then
				wait_last_S <= '1';
				elsif wait_last_S = '1' and clk_cnt_D = 3 and stop_clock_S = '1' then
				wait_last_S <= '0';
				last_pulse_D <= last_pulse_D(5 downto 0) & '1';
				else
				last_pulse_D <= last_pulse_D(5 downto 0) & '0';
				end if;   
			else
				last_pulse_D <= last_pulse_D(5 downto 0) & last_pulse_DI;
			end if;
          end if;
       end if;
	end process;
	
	-- generate dcs_S depending on mode
	process(dcs_SI, dual_mgx_en_SI, second_dcs)
	begin
	   if dual_mgx_en_SI = '1' and dcs_SI = "010" then
	       dcs_S <= "01" & second_dcs;
	   else
	       dcs_S <= dcs_SI;
	   end if;
	end process;
	
	-- output pulse
	process(dcs_S, pulse_out_reg_D)
	begin
        dcs0_out_DO <= '0';
        dcs1_out_DO <= '0';
        dcs2_out_DO <= '0';
        dcs3_out_DO <= '0';
        grey_out_DO <= '0';
        case dcs_S is
            when "000" =>
                dcs0_out_DO <= pulse_out_reg_D;
            when "001" =>
                dcs1_out_DO <= pulse_out_reg_D;
            when "010" =>
                dcs2_out_DO <= pulse_out_reg_D;
            when "011" => 
                dcs3_out_DO <= pulse_out_reg_D;
            when "100" =>
                grey_out_DO <= pulse_out_reg_D;
            when others =>
         end case;	   
	end process;
	
	--diff bram read enable depending on dcs
	diff_bram_rd_en_SO <= dcs_S(0);
	
	--ambient_en
    process(dcs_SI)
    begin
        if dcs_SI(2 downto 1) = "00" then -- Enabled for DCS0 and 1
            ambient_en_SO <= '1';
        else
            ambient_en_SO <= '0';
        end if;
    end process;	

end Behavioral;
-- End image_bin
