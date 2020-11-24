----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03/28/2018 10:46:35 AM
-- Design Name: 
-- Module Name: multiplexer - Behavioral
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity multiplexer is
 	Generic (
    NBITS_DATA : integer := 32
    );   
    Port ( A_DI : in STD_LOGIC_VECTOR (NBITS_DATA-1 downto 0);
           B_DI : in STD_LOGIC_VECTOR (NBITS_DATA-1 downto 0);
           sel_SI : in STD_LOGIC;
           OUT_DO : out STD_LOGIC_VECTOR (NBITS_DATA-1 downto 0));
end multiplexer;

architecture Behavioral of multiplexer is

begin

    process(A_DI, B_DI, sel_SI)
    begin
        if sel_SI = '1' then
            OUT_DO <= B_DI;
        else
            OUT_DO <= A_DI;
        end if;
    end process;

end Behavioral;
