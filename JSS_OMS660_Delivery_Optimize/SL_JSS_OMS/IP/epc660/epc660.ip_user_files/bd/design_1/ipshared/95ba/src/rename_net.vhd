----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02/07/2017 04:17:41 PM
-- Design Name: 
-- Module Name: rename_net - Behavioral
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

entity rename_net is
    Generic ( INBITS : integer := 32;
              OFFSET : integer := 0;
              OUTBITS : integer := 32 );
    Port ( data_in : in STD_LOGIC_VECTOR (INBITS-1 downto 0);
           data_out : out STD_LOGIC_VECTOR (OUTBITS-1 downto 0));
end rename_net;

architecture Behavioral of rename_net is

begin

    process(data_in)
    begin
        if (INBITS+OFFSET<OUTBITS) then
            data_out <= (OUTBITS-1 downto INBITS+OFFSET => '0') & data_in(INBITS+OFFSET-1 downto OFFSET);
        elsif (OUTBITS+OFFSET>INBITS) then
            data_out <= data_in(INBITS-1 downto OFFSET);
        else
            data_out <= data_in(OUTBITS+OFFSET-1 downto OFFSET);
        end if;
        end process;
end Behavioral;
