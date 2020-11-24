----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 12/21/2016 03:06:58 PM
-- Design Name: 
-- Module Name: tb_edge_detector - Behavioral
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity tb_edge_detector is
--  Port ( );
end tb_edge_detector;

architecture Behavioral of tb_edge_detector is
    component edge_detector_v1_0
	generic (
		RISING	: boolean	:= false;
		FALLING	: boolean	:= true;
		PULSE_LENGTH: integer := 5;
		NEG_OUTPUT : boolean := true
	);
	port (
	    clk_CI : in std_logic;
	    en_DI : in std_logic;
        in_DI : in std_logic;
        out_DO : out std_logic
	);
    end component;

    signal clk : std_logic := '0';
    signal en : std_logic := '0';
    signal in_D : std_logic := '0';
	signal out_D : std_logic;
    
begin
    clk <= not clk after 2.5 ns;
    
    UUT: edge_detector_v1_0 port map(
        clk_CI => clk,
        en_DI => en,
        in_DI => in_D,
		out_DO => out_D);
        
    process
    begin
        wait for 10 ns;
        en <= '1';
        wait for 100 ns;
        in_D <= '1';
		wait for 5 ns;
		in_D <= '0';
        wait;
    end process;
end Behavioral;
