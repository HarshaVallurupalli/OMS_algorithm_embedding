----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 12/15/2017 08:53:09 AM
-- Design Name: 
-- Module Name: DCS_subtract - Behavioral
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

entity DCS_subtract is
    Port ( DCSin_DI : in STD_LOGIC_VECTOR (12 downto 0);
           DCSin_sub_DI : in STD_LOGIC_VECTOR (12 downto 0);
           clk_CI : in STD_LOGIC;
           en_DI : in STD_LOGIC;
           sign_DO : out STD_LOGIC;
           udiff_DO : out STD_LOGIC_VECTOR (11 downto 0);
           sat_DO : out STD_LOGIC);
end DCS_subtract;

architecture Behavioral of DCS_subtract is

    signal sign_D  : std_logic;
    signal udiff_D : std_logic_vector(12 downto 0);

begin

process(DCSin_DI, DCSin_sub_DI)
begin
    if DCSin_DI < DCSin_sub_DI then
        sign_D  <= '1';
        udiff_D <= std_logic_vector(unsigned(DCSin_sub_DI)-unsigned(DCSin_DI));
    else
        sign_D  <= '0';
        udiff_D <= std_logic_vector(unsigned(DCSin_DI)-unsigned(DCSin_sub_DI));
    end if;
end process;

process(clk_CI)
begin
	if rising_edge(clk_CI) then
		if en_DI = '0' then
			sign_DO  <= '0';
			sat_DO   <= '0';
			udiff_DO <= (others => '0');
		else
			sign_DO  <= sign_D;
			sat_DO   <= DCSin_DI(12) or DCSin_sub_DI(12) or udiff_D(12);
			udiff_DO <= udiff_D(11 downto 0);
		end if;
	end if;
end process;

end Behavioral;
