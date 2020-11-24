----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 12/21/2016 03:06:58 PM
-- Design Name: 
-- Module Name: alu_tb - Behavioral
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

entity alu_tb is
--  Port ( );
end alu_tb;

architecture Behavioral of alu_tb is
    component ip_alu
        port (
			clk_CI       : in STD_LOGIC;
		    en_DI        : in STD_LOGIC;
		    pulse_DI     : in std_logic;
		    pulse_out_DI : in std_logic;
            udiff0_DI    : in std_logic_vector(11 downto 0);
            sat0_DI      : in std_logic;
            sign0_DI     : in std_logic;
            udiff1_DI    : in std_logic_vector(11 downto 0);
            sat1_DI      : in std_logic;
            sign1_DI     : in std_logic;
            dcs_sat_DI   : in std_logic;        
            corr_d_DI    : in unsigned (11 downto 0);
            corr_a_DI    : in unsigned (11 downto 0);
		    dist_DO      : out std_logic_vector(15 downto 0);
		    dist_sat_DO  : out std_logic;
		    amp_DO       : out std_logic_vector(11 downto 0);
		    amp_sat_DO   : out std_logic;
		    dcssat_DO    : out std_logic;
		    sat_DO       : out std_logic);
    end component;

    signal clk : std_logic := '0';
    signal en : std_logic := '0';
    --signal rst : std_logic := '0';
    signal dcs0 : unsigned (12 downto 0) := (others => '0');
    signal dcs1 : unsigned (12 downto 0) := (others => '0');
    signal dcs2 : unsigned (12 downto 0) := (others => '0');
    signal dcs3 : unsigned (12 downto 0) := (others => '0');
    signal corr_d : unsigned (11 downto 0) := (others => '0');
    signal corr_a : unsigned (11 downto 0) := (others => '0');
    signal pulse_in  : std_logic := '0';
	signal pulse_out : std_logic := '0';
	signal dist      : std_logic_vector(15 downto 0);
	signal dist_sat  : std_logic;
	signal amp       : std_logic_vector(11 downto 0);
	signal amp_sat   : std_logic;
	signal dcssat    : std_logic;
	signal sat       : std_logic);
    
begin
    clk <= not clk after 2.5 ns;
    
    UUT: ip_alu port map(
        clk => clk,
        en => en,
        pulse => pulse,
        --rst => rst,
        dcs0 => dcs0,
        dcs1 => dcs1,
        dcs2 => dcs2,
        dcs3 => dcs3,
        corr_d => corr_d,
        corr_a => corr_a,
        out_data=>out_data);
        
    process
    begin
        wait for 10 ns;
        en <= '1';
        wait for 80 ns;
        -- Change input data
        dcs0 <= to_unsigned(512,13);
        dcs1 <= to_unsigned(408,13);
        dcs2 <= to_unsigned(379,13);
        dcs3 <= to_unsigned(646,13);
        corr_d <= to_unsigned(1,12);
        corr_a <= to_unsigned(2,12);
        pulse <= '1';
        wait for 5 ns;
        pulse <= '0';
        wait for 45 ns;
        dcs0 <= to_unsigned(10,13);
        dcs1 <= to_unsigned(12,13);
        dcs2 <= to_unsigned(20,13);
        dcs3 <= to_unsigned(5,13);
        corr_d <= to_unsigned(1,12);
        corr_a <= to_unsigned(2,12);
        pulse <= '1';
        wait for 5 ns;
        pulse <= '0';
        wait for 45 ns;
        dcs0 <= to_unsigned(4095,13);
        dcs1 <= to_unsigned(3679,13);
        dcs2 <= to_unsigned(3978,13);
        dcs3 <= to_unsigned(2048,13);
        corr_d <= to_unsigned(2,12);
        corr_a <= to_unsigned(1,12);
        pulse <= '1';
        wait for 5 ns;
        pulse <= '0';
        wait for 45 ns;
        dcs0 <= to_unsigned(5000,13);
        dcs1 <= to_unsigned(12,13);
        dcs2 <= to_unsigned(3216,13);
        dcs3 <= to_unsigned(4012,13);
        corr_d <= to_unsigned(2,12);
        corr_a <= to_unsigned(1,12);
        pulse <= '1';
        wait for 5 ns;
        pulse <= '0';
        wait for 45 ns;
        dcs0 <= to_unsigned(2096,13);
        dcs1 <= to_unsigned(2111,13);
        dcs2 <= to_unsigned(2111,13);
        dcs3 <= to_unsigned(2096,13);
        corr_d <= to_unsigned(2,12);
        corr_a <= to_unsigned(1,12);
        pulse <= '1';
        wait for 5 ns;
        pulse <= '0';
        wait for 45 ns;
        pulse <= '1';
        wait for 5 ns;
        pulse <= '0';
        wait for 45 ns;
        pulse <= '1';
        wait for 5 ns;
        pulse <= '0';
        wait for 45 ns;
        pulse <= '1';
        wait for 5 ns;
        pulse <= '0';
        wait for 45 ns;
        wait;
    end process;
end Behavioral;
