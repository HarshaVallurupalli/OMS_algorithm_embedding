library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity axistream2data_v1_0 is
	generic (
		-- Users to add parameters here

		-- User parameters ends
		-- Do not modify the parameters beyond this line


		-- Parameters of Axi Slave Bus Interface S00_AXIS
		C_S00_AXIS_TDATA_WIDTH	: integer	:= 32
	);
	port (
		-- Users to add ports here
		--clk : in std_logic;
		pulse_in : in std_logic;
		--pulse_out : in std_logic;
        nb_of_words : in unsigned(18 downto 0);
        stream_out : out std_logic_vector(31 downto 0);
        enable : in std_logic;
		-- User ports ends
		-- Do not modify the ports beyond this line


		-- Ports of Axi Slave Bus Interface S00_AXIS
		s00_axis_aclk	: in std_logic;
		s00_axis_aresetn	: in std_logic;
		s00_axis_tready	: out std_logic;
		s00_axis_tdata	: in std_logic_vector(C_S00_AXIS_TDATA_WIDTH-1 downto 0);
		s00_axis_tstrb	: in std_logic_vector((C_S00_AXIS_TDATA_WIDTH/8)-1 downto 0);
		s00_axis_tlast	: in std_logic;
		s00_axis_tvalid	: in std_logic
	);
end axistream2data_v1_0;

architecture arch_imp of axistream2data_v1_0 is

	-- component declaration
	component axistream2data_v1_0_S00_AXIS is
		generic (
		C_S_AXIS_TDATA_WIDTH	: integer	:= 32
		);
		port (
		-- User
		nb_of_words : in unsigned(18 downto 0);
		pulse_in : in std_logic;
		stream_out : out std_logic_vector(31 downto 0);
		enable : in std_logic;
		-- Default
		S_AXIS_ACLK	: in std_logic;
		S_AXIS_ARESETN	: in std_logic;
		S_AXIS_TREADY	: out std_logic;
		S_AXIS_TDATA	: in std_logic_vector(C_S_AXIS_TDATA_WIDTH-1 downto 0);
		S_AXIS_TSTRB	: in std_logic_vector((C_S_AXIS_TDATA_WIDTH/8)-1 downto 0);
		S_AXIS_TLAST	: in std_logic;
		S_AXIS_TVALID	: in std_logic
		);
	end component axistream2data_v1_0_S00_AXIS;

begin

-- Instantiation of Axi Bus Interface S00_AXIS
axistream2data_v1_0_S00_AXIS_inst : axistream2data_v1_0_S00_AXIS
	generic map (
		C_S_AXIS_TDATA_WIDTH	=> C_S00_AXIS_TDATA_WIDTH
	)
	port map (
	    nb_of_words => nb_of_words,
	    pulse_in => pulse_in,
	    stream_out => stream_out,
	    enable => enable,
		S_AXIS_ACLK	=> s00_axis_aclk,
		S_AXIS_ARESETN	=> s00_axis_aresetn,
		S_AXIS_TREADY	=> s00_axis_tready,
		S_AXIS_TDATA	=> s00_axis_tdata,
		S_AXIS_TSTRB	=> s00_axis_tstrb,
		S_AXIS_TLAST	=> s00_axis_tlast,
		S_AXIS_TVALID	=> s00_axis_tvalid
	);

	-- Add user logic here

	-- User logic ends

end arch_imp;
