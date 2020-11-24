----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 09/25/2019
-- Design Name: 
-- Module Name: tb_ip_gs_compensation - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

Library xpm;
use xpm.vcomponents.all;

entity tb_ip_gs_compensation is
--  Port ( );
end tb_ip_gs_compensation ;

architecture Behavioral of tb_ip_gs_compensation  is
 
    constant T_CLK_PERIOD               : time      := 10.0 ns;
    
    constant NROWS                      : positive  := 24;
    constant NCOLS                      : positive  := 32;
	
    
    constant NBITS_DATA_IN              : positive  := 13;
    constant NBITS_RAM_IN               : positive  := 16;
    constant NB_SHIFT_LEFT              : positive  := 4;
    
    signal clk_C                        : std_logic := '0';
    signal en_SI                        : std_logic := '0';
    
    signal gs_pulse_in_SI               : STD_LOGIC;
    signal gs_data_in_DI                : STD_LOGIC_VECTOR(NBITS_DATA_IN-1 downto 0);
    signal ram_pulse_in_SI              : STD_LOGIC;
    signal ram_data_in_DI               : STD_LOGIC_VECTOR(NBITS_RAM_IN-1 downto 0);
    signal ram_pulse_req_SO             : STD_LOGIC;
    signal gs_pulse_out_SO              : STD_LOGIC;	  
    signal gs_data_out_DO               : STD_LOGIC_VECTOR(NBITS_DATA_IN-1 downto 0);
    
begin
    
    ----------------------------------------------------------------------------
    -- Clock generation
    ----------------------------------------------------------------------------
    clk_C     <= not clk_C after T_CLK_PERIOD/2;
    
    ----------------------------------------------------------------------------
    -- DUT instantiation
    ----------------------------------------------------------------------------
    i_dut : entity work.ip_gs_compensation
        generic map (
          NBITS_DATA_IN     => NBITS_DATA_IN,
          NBITS_RAM_IN      => NBITS_RAM_IN,
          NB_SHIFT_LEFT     => NB_SHIFT_LEFT)
        port map ( 
          clk_CI            => clk_C,				               
          en_SI             => en_SI,
             
          gs_pulse_in_SI    => gs_pulse_in_SI,
          gs_data_in_DI     => gs_data_in_DI,
          ram_pulse_in_SI   => ram_pulse_in_SI,
          ram_data_in_DI    => ram_data_in_DI,
          ram_pulse_req_SO  => ram_pulse_req_SO,
          gs_pulse_out_SO   => gs_pulse_out_SO,
          gs_data_out_DO    => gs_data_out_DO);  
    
    
    
    
    ----------------------------------------------------------------------------
    -- RAM data interface
    ----------------------------------------------------------------------------    
    p_ram : process (clk_C)
    begin
        if rising_edge(clk_C) then
            ram_pulse_in_SI <= gs_pulse_in_SI;  -- as done in TOF_cos_sl
            ram_data_in_DI  <= (others => '0');
        
        end if;
    end process;
    
    ----------------------------------------------------------------------------
    -- Stimuli procedure
    ----------------------------------------------------------------------------    

    process
    begin
    
        -- default
        gs_pulse_in_SI  <= '0';
        gs_data_in_DI   <= (others => '0');
        
        ------------------------
		-- disabled compensation
		------------------------
        wait for 100 ns;
        wait until rising_edge(clk_C);
		en_SI <= '0';
		
		---- Send GS image
		wait for 100 ns;
        
        
        for r in 0 to NROWS-1 loop
            for c in 0 to NCOLS-1 loop
                wait until rising_edge(clk_C);
                gs_pulse_in_SI  <= '1';    
                gs_data_in_DI   <= std_logic_vector(to_unsigned(2048 + 2**8*r + c, NBITS_DATA_IN));
                
                wait until rising_edge(clk_C);
                gs_pulse_in_SI  <= '0';         
                gs_data_in_DI   <= (others => 'X');
                wait until rising_edge(clk_C);
                wait until rising_edge(clk_C);
            end loop;
        end loop;
            
            
        ------------------------
		-- enabled compensation
		------------------------
        wait for 1 us;
        wait until rising_edge(clk_C);
		en_SI <= '1';
		
		---- Send GS image
		wait for 100 ns;
        
        
        for r in 0 to NROWS-1 loop
            for c in 0 to NCOLS-1 loop
                wait until rising_edge(clk_C);
                gs_pulse_in_SI  <= '1';    
                gs_data_in_DI   <= std_logic_vector(to_unsigned(2048 + 2**8*r + c, NBITS_DATA_IN));
                
                wait until rising_edge(clk_C);
                gs_pulse_in_SI  <= '0';         
                gs_data_in_DI   <= (others => 'X');
                wait until rising_edge(clk_C);
                wait until rising_edge(clk_C);
            end loop;
        end loop;            
            
            

        wait;
    end process;
end Behavioral;
