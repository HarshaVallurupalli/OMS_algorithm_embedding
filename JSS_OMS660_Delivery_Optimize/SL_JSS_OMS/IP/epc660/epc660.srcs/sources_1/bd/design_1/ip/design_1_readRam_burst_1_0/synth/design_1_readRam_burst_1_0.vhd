-- (c) Copyright 1995-2020 Xilinx, Inc. All rights reserved.
-- 
-- This file contains confidential and proprietary information
-- of Xilinx, Inc. and is protected under U.S. and
-- international copyright and other intellectual property
-- laws.
-- 
-- DISCLAIMER
-- This disclaimer is not a license and does not grant any
-- rights to the materials distributed herewith. Except as
-- otherwise provided in a valid license issued to you by
-- Xilinx, and to the maximum extent permitted by applicable
-- law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
-- WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
-- AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
-- BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
-- INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
-- (2) Xilinx shall not be liable (whether in contract or tort,
-- including negligence, or under any other theory of
-- liability) for any loss or damage of any kind or nature
-- related to, arising under or in connection with these
-- materials, including for any direct, or any indirect,
-- special, incidental, or consequential loss or damage
-- (including loss of data, profits, goodwill, or any type of
-- loss or damage suffered as a result of any action brought
-- by a third party) even if such damage or loss was
-- reasonably foreseeable or Xilinx had been advised of the
-- possibility of the same.
-- 
-- CRITICAL APPLICATIONS
-- Xilinx products are not designed or intended to be fail-
-- safe, or for use in any application requiring fail-safe
-- performance, such as life-support or safety devices or
-- systems, Class III medical devices, nuclear facilities,
-- applications related to the deployment of airbags, or any
-- other applications that could lead to death, personal
-- injury, or severe property or environmental damage
-- (individually and collectively, "Critical
-- Applications"). Customer assumes the sole risk and
-- liability of any use of Xilinx products in Critical
-- Applications, subject only to applicable laws and
-- regulations governing limitations on product liability.
-- 
-- THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
-- PART OF THIS FILE AT ALL TIMES.
-- 
-- DO NOT MODIFY THIS FILE.

-- IP VLNV: xilinx.com:user:readRam_burst:1.0
-- IP Revision: 52

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY design_1_readRam_burst_1_0 IS
  PORT (
    clk_CI : IN STD_LOGIC;
    enable_SI : IN STD_LOGIC;
    ram_pulse_DI : IN STD_LOGIC;
    ram_data_DO : OUT STD_LOGIC_VECTOR(127 DOWNTO 0);
    ram_addr_DI : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    ram_index_DI : IN STD_LOGIC_VECTOR(4 DOWNTO 0);
    nbofdllsteps_DI : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
    roi_tl_x_DI : IN STD_LOGIC_VECTOR(8 DOWNTO 0);
    roi_br_x_DI : IN STD_LOGIC_VECTOR(8 DOWNTO 0);
    roi_tl_y_DI : IN STD_LOGIC_VECTOR(6 DOWNTO 0);
    roi_br_y_DI : IN STD_LOGIC_VECTOR(6 DOWNTO 0);
    roi_full_x_DI : IN STD_LOGIC_VECTOR(8 DOWNTO 0);
    roi_full_y_DI : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
    read_pulse_out_DO : OUT STD_LOGIC;
    m00_axi_awaddr : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    m00_axi_awlen : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
    m00_axi_awsize : OUT STD_LOGIC_VECTOR(2 DOWNTO 0);
    m00_axi_awburst : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
    m00_axi_awlock : OUT STD_LOGIC;
    m00_axi_awcache : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    m00_axi_awprot : OUT STD_LOGIC_VECTOR(2 DOWNTO 0);
    m00_axi_awqos : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    m00_axi_awuser : OUT STD_LOGIC_VECTOR(0 DOWNTO 0);
    m00_axi_awvalid : OUT STD_LOGIC;
    m00_axi_awready : IN STD_LOGIC;
    m00_axi_wdata : OUT STD_LOGIC_VECTOR(63 DOWNTO 0);
    m00_axi_wstrb : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
    m00_axi_wlast : OUT STD_LOGIC;
    m00_axi_wuser : OUT STD_LOGIC_VECTOR(0 DOWNTO 0);
    m00_axi_wvalid : OUT STD_LOGIC;
    m00_axi_wready : IN STD_LOGIC;
    m00_axi_bresp : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
    m00_axi_buser : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
    m00_axi_bvalid : IN STD_LOGIC;
    m00_axi_bready : OUT STD_LOGIC;
    m00_axi_araddr : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    m00_axi_arlen : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
    m00_axi_arsize : OUT STD_LOGIC_VECTOR(2 DOWNTO 0);
    m00_axi_arburst : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
    m00_axi_arlock : OUT STD_LOGIC;
    m00_axi_arcache : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    m00_axi_arprot : OUT STD_LOGIC_VECTOR(2 DOWNTO 0);
    m00_axi_arqos : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    m00_axi_aruser : OUT STD_LOGIC_VECTOR(0 DOWNTO 0);
    m00_axi_arvalid : OUT STD_LOGIC;
    m00_axi_arready : IN STD_LOGIC;
    m00_axi_rdata : IN STD_LOGIC_VECTOR(63 DOWNTO 0);
    m00_axi_rresp : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
    m00_axi_rlast : IN STD_LOGIC;
    m00_axi_ruser : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
    m00_axi_rvalid : IN STD_LOGIC;
    m00_axi_rready : OUT STD_LOGIC;
    m00_axi_aclk : IN STD_LOGIC;
    m00_axi_aresetn : IN STD_LOGIC
  );
END design_1_readRam_burst_1_0;

ARCHITECTURE design_1_readRam_burst_1_0_arch OF design_1_readRam_burst_1_0 IS
  ATTRIBUTE DowngradeIPIdentifiedWarnings : STRING;
  ATTRIBUTE DowngradeIPIdentifiedWarnings OF design_1_readRam_burst_1_0_arch: ARCHITECTURE IS "yes";
  COMPONENT readRam_burst_v1_0 IS
    GENERIC (
      C_M00_AXI_TARGET_SLAVE_BASE_ADDR : STD_LOGIC_VECTOR; -- Base address of targeted slave
      C_M00_AXI_BURST_LEN : INTEGER; -- Burst Length. Supports 1, 2, 4, 8, 16, 32, 64, 128, 256 burst lengths
      C_M00_AXI_ID_WIDTH : INTEGER; -- Thread ID Width
      C_M00_AXI_ADDR_WIDTH : INTEGER; -- Width of Address Bus
      C_M00_AXI_DATA_WIDTH : INTEGER; -- Width of Data Bus
      C_M00_AXI_AWUSER_WIDTH : INTEGER; -- Width of User Write Address Bus
      C_M00_AXI_ARUSER_WIDTH : INTEGER; -- Width of User Read Address Bus
      C_M00_AXI_WUSER_WIDTH : INTEGER; -- Width of User Write Data Bus
      C_M00_AXI_RUSER_WIDTH : INTEGER; -- Width of User Read Data Bus
      C_M00_AXI_BUSER_WIDTH : INTEGER; -- Width of User Response Bus
      NBITS_ADDR : INTEGER;
      NBITS_DATA : INTEGER;
      NBITS_RAM : INTEGER;
      NBITS_DLL_STEPS : INTEGER;
      NBITS_ROI_X : INTEGER;
      NBITS_ROI_Y : INTEGER;
      NBITS_DATA_LENGTH : INTEGER
    );
    PORT (
      clk_CI : IN STD_LOGIC;
      enable_SI : IN STD_LOGIC;
      ram_pulse_DI : IN STD_LOGIC;
      ram_data_DO : OUT STD_LOGIC_VECTOR(127 DOWNTO 0);
      ram_addr_DI : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
      ram_index_DI : IN STD_LOGIC_VECTOR(4 DOWNTO 0);
      nbofdllsteps_DI : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
      roi_tl_x_DI : IN STD_LOGIC_VECTOR(8 DOWNTO 0);
      roi_br_x_DI : IN STD_LOGIC_VECTOR(8 DOWNTO 0);
      roi_tl_y_DI : IN STD_LOGIC_VECTOR(6 DOWNTO 0);
      roi_br_y_DI : IN STD_LOGIC_VECTOR(6 DOWNTO 0);
      roi_full_x_DI : IN STD_LOGIC_VECTOR(8 DOWNTO 0);
      roi_full_y_DI : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
      read_pulse_out_DO : OUT STD_LOGIC;
      m00_axi_awid : OUT STD_LOGIC_VECTOR(0 DOWNTO 0);
      m00_axi_awaddr : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
      m00_axi_awlen : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
      m00_axi_awsize : OUT STD_LOGIC_VECTOR(2 DOWNTO 0);
      m00_axi_awburst : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
      m00_axi_awlock : OUT STD_LOGIC;
      m00_axi_awcache : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
      m00_axi_awprot : OUT STD_LOGIC_VECTOR(2 DOWNTO 0);
      m00_axi_awqos : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
      m00_axi_awuser : OUT STD_LOGIC_VECTOR(0 DOWNTO 0);
      m00_axi_awvalid : OUT STD_LOGIC;
      m00_axi_awready : IN STD_LOGIC;
      m00_axi_wdata : OUT STD_LOGIC_VECTOR(63 DOWNTO 0);
      m00_axi_wstrb : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
      m00_axi_wlast : OUT STD_LOGIC;
      m00_axi_wuser : OUT STD_LOGIC_VECTOR(0 DOWNTO 0);
      m00_axi_wvalid : OUT STD_LOGIC;
      m00_axi_wready : IN STD_LOGIC;
      m00_axi_bid : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
      m00_axi_bresp : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
      m00_axi_buser : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
      m00_axi_bvalid : IN STD_LOGIC;
      m00_axi_bready : OUT STD_LOGIC;
      m00_axi_arid : OUT STD_LOGIC_VECTOR(0 DOWNTO 0);
      m00_axi_araddr : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
      m00_axi_arlen : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
      m00_axi_arsize : OUT STD_LOGIC_VECTOR(2 DOWNTO 0);
      m00_axi_arburst : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
      m00_axi_arlock : OUT STD_LOGIC;
      m00_axi_arcache : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
      m00_axi_arprot : OUT STD_LOGIC_VECTOR(2 DOWNTO 0);
      m00_axi_arqos : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
      m00_axi_aruser : OUT STD_LOGIC_VECTOR(0 DOWNTO 0);
      m00_axi_arvalid : OUT STD_LOGIC;
      m00_axi_arready : IN STD_LOGIC;
      m00_axi_rid : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
      m00_axi_rdata : IN STD_LOGIC_VECTOR(63 DOWNTO 0);
      m00_axi_rresp : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
      m00_axi_rlast : IN STD_LOGIC;
      m00_axi_ruser : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
      m00_axi_rvalid : IN STD_LOGIC;
      m00_axi_rready : OUT STD_LOGIC;
      m00_axi_aclk : IN STD_LOGIC;
      m00_axi_aresetn : IN STD_LOGIC
    );
  END COMPONENT readRam_burst_v1_0;
  ATTRIBUTE X_CORE_INFO : STRING;
  ATTRIBUTE X_CORE_INFO OF design_1_readRam_burst_1_0_arch: ARCHITECTURE IS "readRam_burst_v1_0,Vivado 2018.2.2";
  ATTRIBUTE CHECK_LICENSE_TYPE : STRING;
  ATTRIBUTE CHECK_LICENSE_TYPE OF design_1_readRam_burst_1_0_arch : ARCHITECTURE IS "design_1_readRam_burst_1_0,readRam_burst_v1_0,{}";
  ATTRIBUTE CORE_GENERATION_INFO : STRING;
  ATTRIBUTE CORE_GENERATION_INFO OF design_1_readRam_burst_1_0_arch: ARCHITECTURE IS "design_1_readRam_burst_1_0,readRam_burst_v1_0,{x_ipProduct=Vivado 2018.2.2,x_ipVendor=xilinx.com,x_ipLibrary=user,x_ipName=readRam_burst,x_ipVersion=1.0,x_ipCoreRevision=52,x_ipLanguage=VHDL,x_ipSimLanguage=MIXED,C_M00_AXI_TARGET_SLAVE_BASE_ADDR=0x40000000,C_M00_AXI_BURST_LEN=2,C_M00_AXI_ID_WIDTH=0,C_M00_AXI_ADDR_WIDTH=32,C_M00_AXI_DATA_WIDTH=64,C_M00_AXI_AWUSER_WIDTH=1,C_M00_AXI_ARUSER_WIDTH=1,C_M00_AXI_WUSER_WIDTH=1,C_M00_AXI_RUSER_WIDTH=1,C_M00_AXI_BUSER_WIDTH=1,NBITS_ADDR=6,NBITS_DATA=128,NB" & 
"ITS_RAM=5,NBITS_DLL_STEPS=8,NBITS_ROI_X=9,NBITS_ROI_Y=7,NBITS_DATA_LENGTH=17}";
  ATTRIBUTE X_INTERFACE_INFO : STRING;
  ATTRIBUTE X_INTERFACE_PARAMETER : STRING;
  ATTRIBUTE X_INTERFACE_PARAMETER OF m00_axi_aresetn: SIGNAL IS "XIL_INTERFACENAME M00_AXI_RST, POLARITY ACTIVE_LOW";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_aresetn: SIGNAL IS "xilinx.com:signal:reset:1.0 M00_AXI_RST RST";
  ATTRIBUTE X_INTERFACE_PARAMETER OF m00_axi_aclk: SIGNAL IS "XIL_INTERFACENAME M00_AXI_CLK, ASSOCIATED_BUSIF M00_AXI, ASSOCIATED_RESET m00_axi_aresetn, FREQ_HZ 100000000, PHASE 0.000, CLK_DOMAIN design_1_processing_system7_1_0_FCLK_CLK0";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_aclk: SIGNAL IS "xilinx.com:signal:clock:1.0 M00_AXI_CLK CLK";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_rready: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI RREADY";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_rvalid: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI RVALID";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_ruser: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI RUSER";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_rlast: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI RLAST";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_rresp: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI RRESP";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_rdata: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI RDATA";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_arready: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI ARREADY";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_arvalid: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI ARVALID";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_aruser: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI ARUSER";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_arqos: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI ARQOS";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_arprot: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI ARPROT";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_arcache: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI ARCACHE";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_arlock: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI ARLOCK";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_arburst: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI ARBURST";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_arsize: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI ARSIZE";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_arlen: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI ARLEN";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_araddr: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI ARADDR";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_bready: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI BREADY";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_bvalid: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI BVALID";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_buser: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI BUSER";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_bresp: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI BRESP";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_wready: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI WREADY";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_wvalid: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI WVALID";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_wuser: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI WUSER";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_wlast: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI WLAST";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_wstrb: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI WSTRB";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_wdata: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI WDATA";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_awready: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI AWREADY";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_awvalid: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI AWVALID";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_awuser: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI AWUSER";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_awqos: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI AWQOS";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_awprot: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI AWPROT";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_awcache: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI AWCACHE";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_awlock: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI AWLOCK";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_awburst: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI AWBURST";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_awsize: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI AWSIZE";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_awlen: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI AWLEN";
  ATTRIBUTE X_INTERFACE_PARAMETER OF m00_axi_awaddr: SIGNAL IS "XIL_INTERFACENAME M00_AXI, WIZ_DATA_WIDTH 32, SUPPORTS_NARROW_BURST 0, DATA_WIDTH 64, PROTOCOL AXI4, FREQ_HZ 100000000, ID_WIDTH 0, ADDR_WIDTH 32, AWUSER_WIDTH 1, ARUSER_WIDTH 1, WUSER_WIDTH 1, RUSER_WIDTH 1, BUSER_WIDTH 1, READ_WRITE_MODE READ_WRITE, HAS_BURST 1, HAS_LOCK 1, HAS_PROT 1, HAS_CACHE 1, HAS_QOS 1, HAS_REGION 0, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, NUM_READ_OUTSTANDING 2, NUM_WRITE_OUTSTANDING 2, MAX_BURST_LENGTH 256, PHASE 0.000, CLK_DOMAIN design_1_processing_system7_1_0_FCLK_CL" & 
"K0, NUM_READ_THREADS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axi_awaddr: SIGNAL IS "xilinx.com:interface:aximm:1.0 M00_AXI AWADDR";
BEGIN
  U0 : readRam_burst_v1_0
    GENERIC MAP (
      C_M00_AXI_TARGET_SLAVE_BASE_ADDR => X"40000000",
      C_M00_AXI_BURST_LEN => 2,
      C_M00_AXI_ID_WIDTH => 0,
      C_M00_AXI_ADDR_WIDTH => 32,
      C_M00_AXI_DATA_WIDTH => 64,
      C_M00_AXI_AWUSER_WIDTH => 1,
      C_M00_AXI_ARUSER_WIDTH => 1,
      C_M00_AXI_WUSER_WIDTH => 1,
      C_M00_AXI_RUSER_WIDTH => 1,
      C_M00_AXI_BUSER_WIDTH => 1,
      NBITS_ADDR => 6,
      NBITS_DATA => 128,
      NBITS_RAM => 5,
      NBITS_DLL_STEPS => 8,
      NBITS_ROI_X => 9,
      NBITS_ROI_Y => 7,
      NBITS_DATA_LENGTH => 17
    )
    PORT MAP (
      clk_CI => clk_CI,
      enable_SI => enable_SI,
      ram_pulse_DI => ram_pulse_DI,
      ram_data_DO => ram_data_DO,
      ram_addr_DI => ram_addr_DI,
      ram_index_DI => ram_index_DI,
      nbofdllsteps_DI => nbofdllsteps_DI,
      roi_tl_x_DI => roi_tl_x_DI,
      roi_br_x_DI => roi_br_x_DI,
      roi_tl_y_DI => roi_tl_y_DI,
      roi_br_y_DI => roi_br_y_DI,
      roi_full_x_DI => roi_full_x_DI,
      roi_full_y_DI => roi_full_y_DI,
      read_pulse_out_DO => read_pulse_out_DO,
      m00_axi_awaddr => m00_axi_awaddr,
      m00_axi_awlen => m00_axi_awlen,
      m00_axi_awsize => m00_axi_awsize,
      m00_axi_awburst => m00_axi_awburst,
      m00_axi_awlock => m00_axi_awlock,
      m00_axi_awcache => m00_axi_awcache,
      m00_axi_awprot => m00_axi_awprot,
      m00_axi_awqos => m00_axi_awqos,
      m00_axi_awuser => m00_axi_awuser,
      m00_axi_awvalid => m00_axi_awvalid,
      m00_axi_awready => m00_axi_awready,
      m00_axi_wdata => m00_axi_wdata,
      m00_axi_wstrb => m00_axi_wstrb,
      m00_axi_wlast => m00_axi_wlast,
      m00_axi_wuser => m00_axi_wuser,
      m00_axi_wvalid => m00_axi_wvalid,
      m00_axi_wready => m00_axi_wready,
      m00_axi_bid => STD_LOGIC_VECTOR(TO_UNSIGNED(0, 1)),
      m00_axi_bresp => m00_axi_bresp,
      m00_axi_buser => m00_axi_buser,
      m00_axi_bvalid => m00_axi_bvalid,
      m00_axi_bready => m00_axi_bready,
      m00_axi_araddr => m00_axi_araddr,
      m00_axi_arlen => m00_axi_arlen,
      m00_axi_arsize => m00_axi_arsize,
      m00_axi_arburst => m00_axi_arburst,
      m00_axi_arlock => m00_axi_arlock,
      m00_axi_arcache => m00_axi_arcache,
      m00_axi_arprot => m00_axi_arprot,
      m00_axi_arqos => m00_axi_arqos,
      m00_axi_aruser => m00_axi_aruser,
      m00_axi_arvalid => m00_axi_arvalid,
      m00_axi_arready => m00_axi_arready,
      m00_axi_rid => STD_LOGIC_VECTOR(TO_UNSIGNED(0, 1)),
      m00_axi_rdata => m00_axi_rdata,
      m00_axi_rresp => m00_axi_rresp,
      m00_axi_rlast => m00_axi_rlast,
      m00_axi_ruser => m00_axi_ruser,
      m00_axi_rvalid => m00_axi_rvalid,
      m00_axi_rready => m00_axi_rready,
      m00_axi_aclk => m00_axi_aclk,
      m00_axi_aresetn => m00_axi_aresetn
    );
END design_1_readRam_burst_1_0_arch;
