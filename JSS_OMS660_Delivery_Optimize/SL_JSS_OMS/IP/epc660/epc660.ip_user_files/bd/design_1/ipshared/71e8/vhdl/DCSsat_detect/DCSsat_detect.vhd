----------------------------------------------------------------------------------
-- Company: ESPROS		
-- Engineer: msc
-- 
-- Create Date: 19/12/2017 09:58:51 AM
-- Design Name: DCSsat_detect 
-- Module Name: DCSsat_detect - Behavioral
--
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ip_DCSsat_detect is
	generic (
		NBITS_DATA : integer
	);
	port (
        DCSin_DI : in std_logic_vector(NBITS_DATA downto 0);
        DCSsat_DO : out std_logic;
        ADCunderflow_en_SI : in std_logic;
        ADCoverflow_en_SI : in std_logic
	);
end ip_DCSsat_detect;

architecture arch_imp of ip_DCSsat_detect is
    
begin
    process(ADCunderflow_en_SI, ADCoverflow_en_SI, DCSin_DI)
    begin
        if (ADCoverflow_en_SI = '1' and unsigned(DCSin_DI(NBITS_DATA-1 downto 0)) > ((2**NBITS_DATA)-2)) or (ADCunderflow_en_SI = '1' and unsigned(DCSin_DI(NBITS_DATA-1 downto 0)) < 1) then
            DCSsat_DO <= '1';
        else
            DCSsat_DO <= '0';
        end if;
    end process;

end arch_imp;
