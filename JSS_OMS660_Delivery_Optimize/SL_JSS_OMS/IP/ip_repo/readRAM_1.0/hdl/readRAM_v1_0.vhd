library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity readRAM_v1_0 is
	generic (
		-- Users to add parameters here

		-- User parameters ends
		-- Do not modify the parameters beyond this line

		-- Parameters of Axi Master Bus Interface M00_AXI
		C_M00_AXI_START_DATA_VALUE	: std_logic_vector	:= x"AA000000";
		C_M00_AXI_TARGET_SLAVE_BASE_ADDR	: std_logic_vector	:= x"40000000";
		C_M00_AXI_ADDR_WIDTH	: integer	:= 32;
		C_M00_AXI_DATA_WIDTH	: integer	:= 32
	);
	port (
		-- Users to add ports here
		clk_CI        : in std_logic;
		enable_SI     : in std_logic;
        read_addr_DI  : in std_logic_vector(31 downto 0);
        --read_pulse_DI : in std_logic;
        read_data_DO  : out std_logic_vector(95 downto 0);
        debug         : out std_logic_vector(3 downto 0);
		-- User ports ends
		-- Do not modify the ports beyond this line

		-- Ports of Axi Master Bus Interface M00_AXI
		m00_axi_aclk	: in std_logic;
		m00_axi_aresetn	: in std_logic;
		m00_axi_awaddr	: out std_logic_vector(C_M00_AXI_ADDR_WIDTH-1 downto 0);
		m00_axi_awprot	: out std_logic_vector(2 downto 0);
		m00_axi_awvalid	: out std_logic;
		m00_axi_awready	: in std_logic;
		m00_axi_wdata	: out std_logic_vector(C_M00_AXI_DATA_WIDTH-1 downto 0);
		m00_axi_wstrb	: out std_logic_vector(C_M00_AXI_DATA_WIDTH/8-1 downto 0);
		m00_axi_wvalid	: out std_logic;
		m00_axi_wready	: in std_logic;
		m00_axi_bresp	: in std_logic_vector(1 downto 0);
		m00_axi_bvalid	: in std_logic;
		m00_axi_bready	: out std_logic;
		m00_axi_araddr	: out std_logic_vector(C_M00_AXI_ADDR_WIDTH-1 downto 0);
		m00_axi_arprot	: out std_logic_vector(2 downto 0);
		m00_axi_arvalid	: out std_logic;
		m00_axi_arready	: in std_logic;
		m00_axi_rdata	: in std_logic_vector(C_M00_AXI_DATA_WIDTH-1 downto 0);
		m00_axi_rresp	: in std_logic_vector(1 downto 0);
		m00_axi_rvalid	: in std_logic;
		m00_axi_rready	: out std_logic
	);
	
architecture arch_imp of readRAM_v1_0 is

	-- component declaration
	component readRAM_v1_0_M00_AXI is
		generic (
		C_M_START_DATA_VALUE	: std_logic_vector	:= x"AA000000";
		C_M_TARGET_SLAVE_BASE_ADDR	: std_logic_vector	:= x"40000000";
		C_M_AXI_ADDR_WIDTH	: integer	:= 32;
		C_M_AXI_DATA_WIDTH	: integer	:= 32
		);
		port (
		read_addr_DI  : in std_logic_vector(31 downto 0);
        read_pulse_DI : in std_logic;
        read_data_DO  : out std_logic_vector(31 downto 0);
		M_AXI_ACLK	: in std_logic;
		M_AXI_ARESETN	: in std_logic;
		M_AXI_AWADDR	: out std_logic_vector(C_M_AXI_ADDR_WIDTH-1 downto 0);
		M_AXI_AWPROT	: out std_logic_vector(2 downto 0);
		M_AXI_AWVALID	: out std_logic;
		M_AXI_AWREADY	: in std_logic;
		M_AXI_WDATA	: out std_logic_vector(C_M_AXI_DATA_WIDTH-1 downto 0);
		M_AXI_WSTRB	: out std_logic_vector(C_M_AXI_DATA_WIDTH/8-1 downto 0);
		M_AXI_WVALID	: out std_logic;
		M_AXI_WREADY	: in std_logic;
		M_AXI_BRESP	: in std_logic_vector(1 downto 0);
		M_AXI_BVALID	: in std_logic;
		M_AXI_BREADY	: out std_logic;
		M_AXI_ARADDR	: out std_logic_vector(C_M_AXI_ADDR_WIDTH-1 downto 0);
		M_AXI_ARPROT	: out std_logic_vector(2 downto 0);
		M_AXI_ARVALID	: out std_logic;
		M_AXI_ARREADY	: in std_logic;
		M_AXI_RDATA	: in std_logic_vector(C_M_AXI_DATA_WIDTH-1 downto 0);
		M_AXI_RRESP	: in std_logic_vector(1 downto 0);
		M_AXI_RVALID	: in std_logic;
		M_AXI_RREADY	: out std_logic
		);
	end component readRAM_v1_0_M00_AXI;
	
	signal read_pulse_D    : std_logic := '0';
	signal read_pulse_reg_D: std_logic := '0';
	signal read_addr_reg_D : std_logic_vector(31 downto 0);
	signal burst_cnt_D     : unsigned(1 downto 0) := (others => '0'); 
	signal read_data_D     : std_logic_vector(31 downto 0);

begin

-- Instantiation of Axi Bus Interface M00_AXI
readRAM_v1_0_M00_AXI_inst : readRAM_v1_0_M00_AXI
	generic map (
		C_M_START_DATA_VALUE	=> C_M00_AXI_START_DATA_VALUE,
		C_M_TARGET_SLAVE_BASE_ADDR	=> C_M00_AXI_TARGET_SLAVE_BASE_ADDR,
		C_M_AXI_ADDR_WIDTH	=> C_M00_AXI_ADDR_WIDTH,
		C_M_AXI_DATA_WIDTH	=> C_M00_AXI_DATA_WIDTH
	)
	port map (
	    read_addr_DI  => read_addr_DI,
        read_pulse_DI => read_pulse_D,
        read_data_DO  => read_data_D,
		M_AXI_ACLK	=> m00_axi_aclk,
		M_AXI_ARESETN	=> m00_axi_aresetn,
		M_AXI_AWADDR	=> m00_axi_awaddr,
		M_AXI_AWPROT	=> m00_axi_awprot,
		M_AXI_AWVALID	=> m00_axi_awvalid,
		M_AXI_AWREADY	=> m00_axi_awready,
		M_AXI_WDATA	=> m00_axi_wdata,
		M_AXI_WSTRB	=> m00_axi_wstrb,
		M_AXI_WVALID	=> m00_axi_wvalid,
		M_AXI_WREADY	=> m00_axi_wready,
		M_AXI_BRESP	=> m00_axi_bresp,
		M_AXI_BVALID	=> m00_axi_bvalid,
		M_AXI_BREADY	=> m00_axi_bready,
		M_AXI_ARADDR	=> m00_axi_araddr,
		M_AXI_ARPROT	=> m00_axi_arprot,
		M_AXI_ARVALID	=> m00_axi_arvalid,
		M_AXI_ARREADY	=> m00_axi_arready,
		M_AXI_RDATA	=> m00_axi_rdata,
		M_AXI_RRESP	=> m00_axi_rresp,
		M_AXI_RVALID	=> m00_axi_rvalid,
		M_AXI_RREADY	=> m00_axi_rready
	);

	-- Add user logic here
    -- Detect address change
    process(clk_CI)
    begin
        if (enable_SI = '0') then
            read_pulse_D <= '0';
			read_pulse_reg_D <= '0';
            read_addr_reg_D <= (others => '0'); 
			burst_cnt_D <= (others => '0');
			read_data_DO <= (others => '0');
        elsif rising_edge(clk_CI) then
            read_addr_reg_D <= std_logic_vector(unsigned(read_addr_DI) + burst_cnt_D);
			read_pulse_reg_D <= read_pulse_D;
            if (read_addr_reg_D /= read_addr_DI and read_pulse_D='0') or (read_pulse_reg_D='1' and read_pulse_D='0' and burst_cnt_D<2) then
                read_pulse_D <= '1';
            else
                read_pulse_D <= '0';
            end if;
			if read_pulse_D = '1' then
				if burst_cnt_D(1) = '0' then
					burst_cnt_D <= burst_cnt_D + 1;
				else
					burst_cnt_D <= (others => '0');
				end if;
			end if;
			-- connect output data
			if burst_cnt_D(1) = '1' then
				read_data_DO(95 downto 64) <= read_data_D;
			elsif burst_cnt_D(0) = '1' then
				read_data_DO(63 downto 32) <= read_data_D;
			else
				read_data_DO(31 downto 0) <= read_data_D;
			end if;
        end if;
    end process;
    
    debug <= std_logic_vector(burst_cnt_D) & read_pulse_reg_D & read_pulse_D;

	-- User logic ends

end arch_imp;
