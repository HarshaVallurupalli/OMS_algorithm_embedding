----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02/19/2018 01:02:40 PM
-- Design Name: 
-- Module Name: tb_dist_offset - Behavioral
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

entity tb_dist_offset is
--  Port ( );
end tb_dist_offset;

architecture Behavioral of tb_dist_offset is
	component dist_offset_v1_0 is
		generic (
			-- Users to add parameters here
			NBITS_DIST      : integer := 16;
			NBITS_DATA      : integer := 128;
			NBITS_INDEX     : integer := 4;
			RAM_READ_CYCLES : integer := 4
		);
		port (
		-- Users to add ports here
        clk_CI      : in  std_logic;
        en_DI       : in  std_logic;
        -- distance in/out
        pulse_in_DI : in  std_logic;
        dist_DI     : in  std_logic_vector(NBITS_DIST-1 downto 0);
        dist_sat_DI : in  std_logic;
        dist_DO     : out std_logic_vector(NBITS_DIST-1 downto 0);
        dist_sat_DO : out std_logic;
        pulse_out_DO: out std_logic;
        -- FIFO in
        dist_fifo_DI : in std_logic_vector(NBITS_DIST downto 0); -- includes saturation bit
        -- RAM control/data
        ram_read_pulse_DI : in std_logic;
        ram_data_DI       : in  std_logic_vector(NBITS_DATA-1 downto 0);
        ram_read_pulse_DO : out std_logic;
        ram_index_DO      : out std_logic_vector(NBITS_INDEX-1 downto 0);
        -- division / delay data
        dividend_DO       : out std_logic_vector(2*NBITS_DIST-1 downto 0);
        divisor_DO        : out std_logic_vector(NBITS_DIST-1 downto 0);
        div_pulse_DO      : out std_logic;
        div_res_DI        : in  std_logic_vector(NBITS_DIST-1 downto 0);
        div_pulse_DI      : in  std_logic;
        dist_delay_DI     : in  std_logic_vector(NBITS_DIST+NBITS_INDEX+2 downto 0);
        dist_delay_DO     : out std_logic_vector(NBITS_DIST+NBITS_INDEX+2 downto 0);
        -- from/to reg_bank
        dist_corr_en_SI  : in std_logic;
        dist_corr_dll_DI : in std_logic_vector(15 downto 0);
        dist_index_trunc_DO : out std_logic_vector(7 downto 0);
        dist_fail_pos_DO    : out std_logic_vector(16 downto 0);
        dist_index_low_SO   : out std_logic;
        dist_index_high_SO  : out std_logic);
	end component;
	
	constant NBITS_DIST      : integer := 16;
	constant NBITS_DATA      : integer := 128;
	constant REFVAL          : integer := 1030;
	
	signal clk : std_logic := '0';
	signal en : std_logic := '0';
	signal pulse : std_logic := '0';
	signal ram_pulse : std_logic := '0';
	
	signal ram_data : std_logic_vector(NBITS_DATA-1 downto 0) := (others => '0');
	
	signal dist_in : std_logic_vector(NBITS_DIST-1 downto 0) := (others => '0');
	signal dist_fifo : std_logic_vector(NBITS_DIST downto 0) := (others => '0');
	signal dist_out : std_logic_vector(NBITS_DIST-1 downto 0) := (others => '0');
	
	signal div_res : std_logic_vector(15 downto 0) := (others => '0');
	signal div_del : std_logic_vector(22 downto 0) := (others => '0');
	signal div_pulse : std_logic := '0';
	
begin
    clk <= not clk after 2.5 ns;
    
    UUT: dist_offset_v1_0 port map(
		clk_CI            => clk,
		en_DI             => en,
		dist_DI           => dist_in,
		pulse_in_DI       => pulse,
		dist_sat_DI       => '0',
		dist_DO           => dist_out,
		dist_sat_DO       => open,
		dist_fifo_DI      => dist_fifo,
		ram_read_pulse_DI => ram_pulse,
		ram_data_DI       => ram_data,
		ram_read_pulse_DO => open,
		ram_index_DO      => open,
		pulse_out_DO      => open,
        dividend_DO       => open,
        divisor_DO        => open,
        div_pulse_DO      => open,
        div_res_DI        => div_res,
        div_pulse_DI      => div_pulse,
        dist_delay_DI     => div_del,
        dist_delay_DO     => open,
        -- from/to reg_bank
        dist_corr_en_SI  => '1',
        dist_corr_dll_DI => "0000010000000101",
        dist_index_trunc_DO => open,
        dist_fail_pos_DO    => open,
        dist_index_low_SO   => open,
        dist_index_high_SO  => open
	);

	process
	begin
		wait for 10 us;
		en <= '1';
		wait for 10 us;
		dist_in   <= "0111001101101110";
		dist_fifo <= "00111001101101110";
		ram_data  <= std_logic_vector(to_unsigned(17060,16)) &std_logic_vector(to_unsigned(16030,16)) &std_logic_vector(to_unsigned(15002,16)) &std_logic_vector(to_unsigned(13972,16)) &std_logic_vector(to_unsigned(12944,16)) & std_logic_vector(to_unsigned(11914,16)) & std_logic_vector(to_unsigned(10886,16)) & std_logic_vector(to_unsigned(9856,16));
		wait for 12.6 us;
		ram_pulse <= '1';
		wait for 5 ns;
		ram_pulse <= '0';
		wait;
	end process;
	
end Behavioral;
