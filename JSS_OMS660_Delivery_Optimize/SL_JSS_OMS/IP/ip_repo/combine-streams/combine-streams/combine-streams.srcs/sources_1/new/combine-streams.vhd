----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02/13/2017 02:28:10 PM
-- Design Name: 
-- Module Name: combine-streams - Behavioral
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
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity combine_streams is
    Port ( data_in : in STD_LOGIC_VECTOR (12 downto 0);
           ram_in : in STD_LOGIC_VECTOR (31 downto 0);
           msb : in STD_LOGIC;
           ram_out : out STD_LOGIC_VECTOR (31 downto 0));
end combine_streams;

architecture Behavioral of combine_streams is
signal counter : unsigned(16 downto 0) := (others => '0');
begin

process(msb,data_in,ram_in)
begin
        if (msb = '1') then
            ram_out <= "000" & data_in & ram_in(15 downto 0);
        else
            ram_out <= ram_in(31 downto 16) & "000" & data_in;
        end if;
end process;

end Behavioral;
