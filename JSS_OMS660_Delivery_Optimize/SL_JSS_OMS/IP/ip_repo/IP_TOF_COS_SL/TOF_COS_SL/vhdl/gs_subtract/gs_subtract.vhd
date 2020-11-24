----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03/21/2018 08:33:10 AM
-- Design Name: 
-- Module Name: gs_subtract - Behavioral
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

entity ip_gs_subtract is
	generic (
		NBITS_DATA : integer
	);
    port ( 
		clk_CI          : in STD_LOGIC;
        gs_en_DI        : in std_logic;
        gs_DI           : in STD_LOGIC_VECTOR (NBITS_DATA-1 downto 0);
        gs_pulse_in_SI  : in STD_LOGIC;
        gs_DO           : out STD_LOGIC_VECTOR (NBITS_DATA-1 downto 0);
        gs_pulse_out_SO : out STD_LOGIC
	);
end ip_gs_subtract;

architecture Behavioral of ip_gs_subtract is
begin

    process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            gs_pulse_out_SO <= gs_pulse_in_SI;
            if gs_en_DI = '1' then
                if gs_DI(NBITS_DATA-2) = '1' then
                    gs_DO <= gs_DI(NBITS_DATA-1) & '0' & gs_DI(NBITS_DATA-3 downto 0);
                else
                    gs_DO <= '1' & (NBITS_DATA-2 downto 0 => '0');
                end if;
            else
                gs_DO <= gs_DI;
            end if;
        end if;
    end process;

end Behavioral;
