library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity data2axistream_v1_0 is
	generic (
		-- Users to add parameters here
        INPUT_BUS_WIDTH : integer := 13;
		INPUT_FIFO_BITS : integer :=  1; -- Input FIFO bits to handle dma not ready (1 or 2 bit possible)
		-- User parameters ends
		-- Do not modify the parameters beyond this lin

		-- Parameters of Axi Master Bus Interface M00_AXIS
		C_M00_AXIS_TDATA_WIDTH	: integer	:= 32;
		C_M00_AXIS_START_COUNT	: integer	:= 32
	);
	port (
		-- Users to add ports here
		en : in std_logic;
        clk : in std_logic;
        resetn : in std_logic;
        pulse : in std_logic;
        input_data : in std_logic_vector(INPUT_BUS_WIDTH-1 downto 0);
        NUMBER_OF_OUTPUT_WORDS : in unsigned(18 downto 0);
        --debug_1 : out std_logic_vector(4 downto 0);
		-- User ports ends
		-- Do not modify the ports beyond this line


		-- Ports of Axi Master Bus Interface M00_AXIS
		m00_axis_aclk	: in std_logic;
		m00_axis_aresetn	: in std_logic;
		m00_axis_tvalid	: out std_logic;
		m00_axis_tdata	: out std_logic_vector(C_M00_AXIS_TDATA_WIDTH-1 downto 0);
		m00_axis_tstrb	: out std_logic_vector((C_M00_AXIS_TDATA_WIDTH/8)-1 downto 0);
		m00_axis_tkeep	: out std_logic_vector((C_M00_AXIS_TDATA_WIDTH/8)-1 downto 0);
		m00_axis_tlast	: out std_logic;
		m00_axis_tready	: in std_logic
	);
end data2axistream_v1_0;

architecture arch_imp of data2axistream_v1_0 is

	-- component declaration
	component data2axistream_v1_0_M00_AXIS is
		generic (
		INPUT_FIFO_BITS : integer := 1;
		C_M_AXIS_TDATA_WIDTH	: integer	:= 32;
		C_M_START_COUNT	: integer	:= 32
		);
		port (
		en : in std_logic;
        clk : in std_logic;
        pulse : in std_logic;
        input_data : in std_logic_vector(31 downto 0);
        NUMBER_OF_OUTPUT_WORDS : in unsigned(18 downto 0);
        --debug_1 : out std_logic_vector(4 downto 0);
		M_AXIS_ACLK	: in std_logic;
		M_AXIS_ARESETN	: in std_logic;
		M_AXIS_TVALID	: out std_logic;
		M_AXIS_TDATA	: out std_logic_vector(C_M_AXIS_TDATA_WIDTH-1 downto 0);
		M_AXIS_TSTRB	: out std_logic_vector((C_M_AXIS_TDATA_WIDTH/8)-1 downto 0);
		M_AXIS_TKEEP	: out std_logic_vector((C_M_AXIS_TDATA_WIDTH/8)-1 downto 0);
		M_AXIS_TLAST	: out std_logic;
		M_AXIS_TREADY	: in std_logic
		);
	end component data2axistream_v1_0_M00_AXIS;
	
	signal input_data_full : std_logic_vector(31 downto 0);
	signal resetn_int : std_logic;

begin

-- Add zeros to fill input data up to 32b
input_data_full <= (31 downto INPUT_BUS_WIDTH => '0') & input_data;
resetn_int <= m00_axis_aresetn AND en AND resetn;

-- Instantiation of Axi Bus Interface M00_AXIS
data2axistream_v1_0_M00_AXIS_inst : data2axistream_v1_0_M00_AXIS
	generic map (
		INPUT_FIFO_BITS => INPUT_FIFO_BITS,
		C_M_AXIS_TDATA_WIDTH	=> C_M00_AXIS_TDATA_WIDTH,
		C_M_START_COUNT	=> C_M00_AXIS_START_COUNT
	)
	port map (
	    en => en,
        clk => clk,
        pulse => pulse,
        input_data => input_data_full,
        NUMBER_OF_OUTPUT_WORDS => NUMBER_OF_OUTPUT_WORDS,
        --debug_1 => debug_1,
		M_AXIS_ACLK	=> m00_axis_aclk,
		M_AXIS_ARESETN	=> resetn,
		M_AXIS_TVALID	=> m00_axis_tvalid,
		M_AXIS_TDATA	=> m00_axis_tdata,
		M_AXIS_TSTRB	=> m00_axis_tstrb,
		M_AXIS_TKEEP	=> m00_axis_tkeep,
		M_AXIS_TLAST	=> m00_axis_tlast,
		M_AXIS_TREADY	=> m00_axis_tready
	);

	-- Add user logic here

	-- User logic ends

end arch_imp;
