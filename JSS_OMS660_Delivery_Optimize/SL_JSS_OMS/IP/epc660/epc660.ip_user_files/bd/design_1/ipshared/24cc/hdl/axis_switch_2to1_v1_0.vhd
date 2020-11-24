library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity axis_switch_2to1_v1_0 is
	generic (
		-- Users to add parameters here

		-- User parameters ends
		-- Do not modify the parameters beyond this line

		-- Parameters of Axi Slave Bus Interface S00_AXIS
		C_S00_AXIS_TDATA_WIDTH	: integer	:= 32;

		-- Parameters of Axi Slave Bus Interface S01_AXIS
		C_S01_AXIS_TDATA_WIDTH	: integer	:= 32;

		-- Parameters of Axi Master Bus Interface M00_AXIS
		C_M00_AXIS_TDATA_WIDTH	: integer	:= 32;
		C_M00_AXIS_START_COUNT	: integer	:= 32
	);
	port (
		-- Users to add ports here
        select_S01_SI : in std_logic;
		-- User ports ends
		-- Do not modify the ports beyond this line

		-- Ports of Axi Slave Bus Interface S00_AXIS
		s00_axis_tready	: out std_logic;
		s00_axis_tdata	: in std_logic_vector(C_S00_AXIS_TDATA_WIDTH-1 downto 0);
		s00_axis_tstrb	: in std_logic_vector((C_S00_AXIS_TDATA_WIDTH/8)-1 downto 0);
		s00_axis_tkeep	: in std_logic_vector((C_S00_AXIS_TDATA_WIDTH/8)-1 downto 0);
		s00_axis_tlast	: in std_logic;
		s00_axis_tvalid	: in std_logic;

		-- Ports of Axi Slave Bus Interface S01_AXIS
		s01_axis_tready	: out std_logic;
		s01_axis_tdata	: in std_logic_vector(C_S01_AXIS_TDATA_WIDTH-1 downto 0);
		s01_axis_tstrb	: in std_logic_vector((C_S01_AXIS_TDATA_WIDTH/8)-1 downto 0);
		s01_axis_tkeep	: in std_logic_vector((C_S00_AXIS_TDATA_WIDTH/8)-1 downto 0);
		s01_axis_tlast	: in std_logic;
		s01_axis_tvalid	: in std_logic;

		-- Ports of Axi Master Bus Interface M00_AXIS
		m00_axis_tvalid	: out std_logic;
		m00_axis_tdata	: out std_logic_vector(C_M00_AXIS_TDATA_WIDTH-1 downto 0);
		m00_axis_tstrb	: out std_logic_vector((C_M00_AXIS_TDATA_WIDTH/8)-1 downto 0);
        m00_axis_tkeep	: out std_logic_vector((C_S00_AXIS_TDATA_WIDTH/8)-1 downto 0);   
		m00_axis_tlast	: out std_logic;
		m00_axis_tready	: in std_logic
	);
end axis_switch_2to1_v1_0;

architecture arch_imp of axis_switch_2to1_v1_0 is
begin
	-- Add user logic here
    process(select_S01_SI, m00_axis_tready, s01_axis_tvalid, s01_axis_tdata, s01_axis_tstrb, s01_axis_tlast, s01_axis_tkeep, s00_axis_tvalid, s00_axis_tdata, s00_axis_tstrb, s00_axis_tlast, s00_axis_tkeep)
    begin
        case(select_S01_SI) is
            when '1' =>
                m00_axis_tvalid  <= s01_axis_tvalid;
                m00_axis_tdata   <= s01_axis_tdata;
                m00_axis_tstrb   <= s01_axis_tstrb;
                m00_axis_tlast   <= s01_axis_tlast;
                m00_axis_tkeep   <= s01_axis_tkeep;
                s00_axis_tready  <= '0';
                s01_axis_tready  <= m00_axis_tready;
            when others =>
                m00_axis_tvalid  <= s00_axis_tvalid;
                m00_axis_tdata   <= s00_axis_tdata;
                m00_axis_tstrb   <= s00_axis_tstrb;
                m00_axis_tlast   <= s00_axis_tlast;
                m00_axis_tkeep   <= s00_axis_tkeep;
                s00_axis_tready  <= m00_axis_tready;
                s01_axis_tready  <= '0';
        end case;
    end process;
	-- User logic ends

end arch_imp;
