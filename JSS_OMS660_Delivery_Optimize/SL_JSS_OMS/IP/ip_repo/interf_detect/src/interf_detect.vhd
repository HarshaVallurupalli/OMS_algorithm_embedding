----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 06/27/2018 01:36:52 PM
-- Design Name: 
-- Module Name: interf_detect - Behavioral
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

entity interf_detect is
    Port ( clk_CI : in STD_LOGIC;
           resetn_RB : in STD_LOGIC;
           reg_interf_thr_DI : in STD_LOGIC_VECTOR (12 downto 0);
           data_in0_DI : in STD_LOGIC_VECTOR (12 downto 0);
           data_in1_DI : in STD_LOGIC_VECTOR (12 downto 0);
           interf_flag_DO : out STD_LOGIC);
end interf_detect;

architecture Behavioral of interf_detect is

begin
process(clk_CI)
begin
    if rising_edge(clk_CI) then
        if resetn_RB = '0' then
            interf_flag_DO <= '0';
        else
            if (signed(data_in0_DI(11 downto 0)) + signed(data_in1_DI(11 downto 0)) + signed('0' & reg_interf_thr_DI)) < signed('0' & reg_interf_thr_DI & '0') then
                interf_flag_DO <= '0';
            else -- set interference flag
                interf_flag_DO <= '1';
            end if;
        end if;
    end if;
end process;


end Behavioral;
