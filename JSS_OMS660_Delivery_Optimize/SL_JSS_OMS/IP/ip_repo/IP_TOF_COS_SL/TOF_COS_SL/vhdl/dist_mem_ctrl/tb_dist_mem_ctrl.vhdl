----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 01/29/2018 11:39:09 AM
-- Design Name: 
-- Module Name: tb_dist_mem_ctrl - Behavioral
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

entity tb_dist_mem_ctrl is
--  Port ( );
end tb_dist_mem_ctrl;

architecture Behavioral of tb_dist_mem_ctrl is

	component dist_mem_ctrl_v1_0 is
		generic (
			-- Users to add parameters here
			READ_BURST_SIZE         : integer   := 3;
			-- User parameters ends
			-- Do not modify the parameters beyond this line
	
			-- Parameters of Axi Slave Bus Interface S00_AXI
			C_S00_AXI_DATA_WIDTH	: integer	:= 32;
			C_S00_AXI_ADDR_WIDTH	: integer	:= 4
		);
		port (
			-- Users to add ports here
			clk_CI       : in std_logic;
			enable_SI    : in std_logic;
			init_bram_SI : in std_logic; -- Fill the BRAM with the first 8x50 tables
			-- ramRead
			write_pulse_DO : out std_logic;
			write_addr_DO  : out std_logic_vector(2 downto 0);
			-- BRAM
			read_bram_addr_DO : out std_logic_vector(8 downto 0);
			read_bram_en_DO   : out std_logic;
			read_bram_data_DI : in  std_logic_vector(31 downto 0);
			-- dist_offset
			read_pulse_DI : in  std_logic;
			read_index_DI : in  std_logic_vector(5 downto 0);
			read_data_DO  : out std_logic_vector(95 downto 0);
			-- User ports ends
			-- Do not modify the ports beyond this line
	
			-- Ports of Axi Slave Bus Interface S00_AXI
			s00_axi_aclk	: in std_logic;
			s00_axi_aresetn	: in std_logic;
			s00_axi_awaddr	: in std_logic_vector(C_S00_AXI_ADDR_WIDTH-1 downto 0);
			s00_axi_awprot	: in std_logic_vector(2 downto 0);
			s00_axi_awvalid	: in std_logic;
			s00_axi_awready	: out std_logic;
			s00_axi_wdata	: in std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
			s00_axi_wstrb	: in std_logic_vector((C_S00_AXI_DATA_WIDTH/8)-1 downto 0);
			s00_axi_wvalid	: in std_logic;
			s00_axi_wready	: out std_logic;
			s00_axi_bresp	: out std_logic_vector(1 downto 0);
			s00_axi_bvalid	: out std_logic;
			s00_axi_bready	: in std_logic;
			s00_axi_araddr	: in std_logic_vector(C_S00_AXI_ADDR_WIDTH-1 downto 0);
			s00_axi_arprot	: in std_logic_vector(2 downto 0);
			s00_axi_arvalid	: in std_logic;
			s00_axi_arready	: out std_logic;
			s00_axi_rdata	: out std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
			s00_axi_rresp	: out std_logic_vector(1 downto 0);
			s00_axi_rvalid	: out std_logic;
			s00_axi_rready	: in std_logic
		);
	end component;

    signal clk_C            : std_logic := '0';
    signal enable_S         : std_logic := '0';
    signal init_bram_S      : std_logic := '0';
    signal write_pulse_D    : std_logic := '0';
    signal write_addr_D     : std_logic_vector(2 downto 0) := (others => '0');
    signal read_bram_addr_D : std_logic_vector(8 downto 0) := (others => '0');
    signal read_bram_en_D   : std_logic := '0';
    signal read_bram_data_D : std_logic_vector(31 downto 0) := (others => '0');
    signal read_pulse_D     : std_logic := '0';
    signal read_index_D     : std_logic_vector(5 downto 0) := (others => '0');
    signal read_data_D      : std_logic_vector(95 downto 0) := (others => '0');

begin
    clk_C <= not clk_C after 5 ns;
    
    UUT: dist_mem_ctrl_v1_0 port map(
		clk_CI            => clk_C,
		enable_SI         => enable_S,
		init_bram_SI      => init_bram_S,
		write_pulse_DO    => write_pulse_D,
		write_addr_DO     => write_addr_D,
		read_bram_addr_DO => read_bram_addr_D,
		read_bram_en_DO   => read_bram_en_D,
		read_bram_data_DI => read_bram_data_D,
		read_pulse_DI     => read_pulse_D,
		read_index_DI     => read_index_D,
		read_data_DO      => read_data_D,
		s00_axi_aclk	  => '0',
		s00_axi_aresetn	  => '0',
		s00_axi_awaddr	  => (others => '0'),
		s00_axi_awprot	  => (others => '0'),
		s00_axi_awvalid	  => '0',
		s00_axi_awready	  => open,
		s00_axi_wdata	  => (others => '0'),
		s00_axi_wstrb	  => (others => '0'),
		s00_axi_wvalid	  => '0',
		s00_axi_wready	  => open,
		s00_axi_bresp	  => open,
		s00_axi_bvalid	  => open,
		s00_axi_bready	  => '0',
		s00_axi_araddr	  => (others => '0'),
		s00_axi_arprot	  => (others => '0'),
		s00_axi_arvalid	  => '0',
		s00_axi_arready	  => open,
		s00_axi_rdata	  => open,
		s00_axi_rresp	  => open,
		s00_axi_rvalid	  => open,
		s00_axi_rready	  => '0'
	);
	
	process
	begin
		wait for 100 ns;
		enable_S <= '1';
		wait for 100 ns;
		init_bram_S <= '1';
		wait for 20 ns;
		init_bram_S <= '0';
		wait for 1 us;
		read_index_D <= "010101";
		wait for 100 ns;
		read_pulse_D <= '1';
		wait for 10 ns;
		read_pulse_D <= '0';
		wait for 1 us;
		read_index_D <= "101010";
		wait for 100 ns;
		read_pulse_D <= '1';
		wait for 10 ns;
		read_pulse_D <= '0';		
		wait;
	end process;

end Behavioral;
