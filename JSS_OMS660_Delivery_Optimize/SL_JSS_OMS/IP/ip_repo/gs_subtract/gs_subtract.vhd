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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity gs_subtract is
    Port ( clk_CI : in STD_LOGIC;
           gs_en_DI : in std_logic;
           gs_DI : in STD_LOGIC_VECTOR (12 downto 0);
           gs_DO : out STD_LOGIC_VECTOR (12 downto 0));
end gs_subtract;

architecture Behavioral of gs_subtract is
begin

    process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if gs_en_DI = '1' then
                if gs_DI(11) = '1' then
                    gs_DO <= gs_DI(12) & '0' & gs_DI(10 downto 0);
                else
                    gs_DO <= '1' & (11 downto 0 => '0');
                end if;
            else
                gs_DO <= gs_DI;
            end if;
        end if;
    end process;

end Behavioral;
