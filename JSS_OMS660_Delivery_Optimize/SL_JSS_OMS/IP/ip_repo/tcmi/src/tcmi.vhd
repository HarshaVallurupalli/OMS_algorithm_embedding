----------------------------------------------------------------------------------
-- Company: ESPROS		
-- Engineer: msc
-- 
-- Create Date: 01/05/2017 09:58:51 AM
-- Design Name: tcmi 
-- Module Name: tcmi - Behavioral
--
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

-- TCMI
entity tcmi is
	Port ( 
		-- control signals
		clk : in STD_LOGIC;								-- clk has to be at least 4x faster than dclk!!!
		en : in STD_LOGIC;
		length : in std_logic_vector(16 downto 0);      -- dcs length (to generate a last pulse for alu and readout)
        
		-- signals from chip
		dclk_in : in std_logic; 										-- clk input
		vsync_in : in std_logic; 										-- dcs sync 
		hsync_in : in std_logic; 										-- row sync
		xsync_sat_in : in std_logic; 								    -- sat bit
		data_in : in std_logic_vector(11 downto 0); -- data
		
		-- control out
		active : out std_logic;
		pixel_cnt : out unsigned(16 downto 0);
		last_out : out std_logic;

		-- data to RAM
		vsync_DO : out std_logic;
		hsync_DO : out std_logic;
		pulse_out : out std_logic := '0';
		dout : out std_logic_vector(12 downto 0) := (others => '0'));
end tcmi;

architecture Behavioral of tcmi is
	signal vsync_in_0 : std_logic := '1';
	signal vsync_in_1 : std_logic := '1';
	signal vsync_in_2 : std_logic := '1';
	signal dclk_in_0 : std_logic := '1';
	signal dclk_in_1 : std_logic := '1';
	signal dclk_in_2 : std_logic := '1';
	signal pulse : std_logic := '0';
	signal hsync_0 : std_logic := '1';
	signal hsync_1 : std_logic := '1';
	signal pixel_cnt_int : unsigned(16 downto 0);
	signal last_pulse : std_logic := '0';
begin

-- synchronisation of vsync and hsync
process(clk)
begin
	if en='1' then
	      vsync_in_0 <= vsync_in;
	      vsync_in_1 <= vsync_in_0;
	      vsync_in_2 <= vsync_in_1;	      		  
	else
		vsync_in_0 <= '1';
		vsync_in_1 <= '1';
		vsync_in_2 <= '1';
	end if;
end process;

active <= not vsync_in_1;

-- synchronisation of dclk
process(clk)
begin
    if (rising_edge(clk)) then
	if vsync_in_1='0' then
		dclk_in_0 <= dclk_in;
		dclk_in_1 <= dclk_in_0;
		dclk_in_2 <= dclk_in_1;
		hsync_0 <= hsync_in;
        hsync_1 <= hsync_0;
	else
		dclk_in_0 <= '0';
		dclk_in_1 <= '0';
		dclk_in_2 <= '0';
		hsync_0 <= '1';
        hsync_1 <= '1';
	end if;
	end if;
end process;

process (clk)
begin
    if rising_edge(clk) then
		if en = '0' then 
			pixel_cnt_int <= (others => '0'); 
            last_pulse <= '0';
			pulse <= '0';
			pulse_out <= '0';
			last_out <= '0';			
		else
			if (dclk_in_0 = '1' and dclk_in_1 = '0' and (hsync_in ='0' or (unsigned(length) = pixel_cnt_int and last_pulse = '0'))) then
				pulse <= '1';
				if (unsigned(length) = pixel_cnt_int and last_pulse = '0' and pixel_cnt_int > 0) then
					last_pulse <= '1';
				end if;
				dout <= xsync_sat_in & data_in;
				pulse_out <= '0';
				if unsigned(length) = pixel_cnt_int then
					pixel_cnt_int <= (others => '0'); 
				else
					pixel_cnt_int <= pixel_cnt_int + 1;
				end if;
			elsif pulse = '1' then
				pulse <= '0';
				if last_pulse = '1' then
					last_out <= '1';
					last_pulse <= '0';
				else
					pulse_out <= '1';
				end if;
			else
				pulse <= '0';
				pulse_out <= '0';
				last_out <= '0';
			end if;
		end if;
	end if;
end process;

-- assign outputs
pixel_cnt <= pixel_cnt_int;
vsync_DO <= vsync_in_1;
hsync_DO <= hsync_1;

end Behavioral;
-- End tcmi