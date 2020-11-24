----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 01/11/2017 09:56:10 AM
-- Design Name: 
-- Module Name: divider - Behavioral
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

entity divider is
    GENERIC (
        CLK_DIVIDER : Integer := 100000000
    );
    Port ( 
           --en : in std_logic;
           clk : in STD_LOGIC;
           outclk : out STD_LOGIC);
end divider;

architecture Behavioral of divider is
    signal counter : unsigned(31 downto 0) := (others => '0');
    signal outclk_tmp: std_logic := '0';
begin
process(clk)
begin
    if rising_edge(clk) then
        --if en = '1' then
            if (counter < 1) then
                counter <= to_unsigned(CLK_DIVIDER-1, 32);
            else
                counter <= counter - 1;
            end if;
         --else
         --   counter <= (others => '0');
         --end if;
    end if;
end process;

process(clk)
begin
    if (rising_edge(clk)) then
        --if en = '1' then
            if (counter = 0) then   
                outclk_tmp <= not outclk_tmp;
            end if;
        --else
        --    outclk_tmp <= '0';
        --end if;
    end if;
end process;

outclk <= outclk_tmp;
end architecture;
