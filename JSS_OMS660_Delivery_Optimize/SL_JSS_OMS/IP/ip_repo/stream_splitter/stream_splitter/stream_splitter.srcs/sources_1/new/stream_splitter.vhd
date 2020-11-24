----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02/13/2017 02:54:37 PM
-- Design Name: 
-- Module Name: stream_splitter - Behavioral
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

entity stream_splitter is
    Port ( stream0_in : in STD_LOGIC_VECTOR (31 downto 0);
           stream1_in : in STD_LOGIC_VECTOR (31 downto 0);
           pulse_in : in std_logic;
           clk : in STD_LOGIC;
           resetn : in STD_LOGIC;
           dcs0 : out STD_LOGIC_VECTOR (12 downto 0);
           dcs1 : out STD_LOGIC_VECTOR (12 downto 0);
           dcs2 : out STD_LOGIC_VECTOR (12 downto 0);
           dcs3 : out STD_LOGIC_VECTOR (12 downto 0));
end stream_splitter;

architecture Behavioral of stream_splitter is
begin

-- Split data
process(stream0_in, stream1_in)
begin
    --if (resetn = '0') then
    --    dcs0 <= (others => '0');
    --    dcs1 <= (others => '0');
    --    dcs2 <= (others => '0');
    --    dcs3 <= (others => '0');
   -- elsif rising_edge(clk) then
    --    if pulse_in ='1' then
            dcs0 <= stream0_in(12 downto 0);
            dcs2 <= stream0_in(28 downto 16);
            dcs1 <= stream1_in(12 downto 0);
            dcs3 <= stream1_in(28 downto 16);
    --    end if;
   -- end if;
end process;

end Behavioral;
