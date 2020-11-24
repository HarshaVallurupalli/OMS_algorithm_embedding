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

-- IP VLNV: xilinx.com:user:axis_switch_2to1:1.0
-- IP Revision: 7

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY design_1_axis_switch_2to1_0_0 IS
  PORT (
    select_S01_SI : IN STD_LOGIC;
    m00_axis_tdata : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    m00_axis_tstrb : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    m00_axis_tkeep : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    m00_axis_tlast : OUT STD_LOGIC;
    m00_axis_tvalid : OUT STD_LOGIC;
    m00_axis_tready : IN STD_LOGIC;
    s01_axis_tdata : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    s01_axis_tstrb : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    s01_axis_tkeep : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    s01_axis_tlast : IN STD_LOGIC;
    s01_axis_tvalid : IN STD_LOGIC;
    s01_axis_tready : OUT STD_LOGIC;
    s00_axis_tdata : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    s00_axis_tstrb : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    s00_axis_tkeep : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    s00_axis_tlast : IN STD_LOGIC;
    s00_axis_tvalid : IN STD_LOGIC;
    s00_axis_tready : OUT STD_LOGIC
  );
END design_1_axis_switch_2to1_0_0;

ARCHITECTURE design_1_axis_switch_2to1_0_0_arch OF design_1_axis_switch_2to1_0_0 IS
  ATTRIBUTE DowngradeIPIdentifiedWarnings : STRING;
  ATTRIBUTE DowngradeIPIdentifiedWarnings OF design_1_axis_switch_2to1_0_0_arch: ARCHITECTURE IS "yes";
  COMPONENT axis_switch_2to1_v1_0 IS
    GENERIC (
      C_M00_AXIS_TDATA_WIDTH : INTEGER; -- Width of S_AXIS address bus. The slave accepts the read and write addresses of width C_M_AXIS_TDATA_WIDTH.
      C_M00_AXIS_START_COUNT : INTEGER; -- Start count is the numeber of clock cycles the master will wait before initiating/issuing any transaction.
      C_S01_AXIS_TDATA_WIDTH : INTEGER; -- AXI4Stream sink: Data Width
      C_S00_AXIS_TDATA_WIDTH : INTEGER -- AXI4Stream sink: Data Width
    );
    PORT (
      select_S01_SI : IN STD_LOGIC;
      m00_axis_tdata : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
      m00_axis_tstrb : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
      m00_axis_tkeep : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
      m00_axis_tlast : OUT STD_LOGIC;
      m00_axis_tvalid : OUT STD_LOGIC;
      m00_axis_tready : IN STD_LOGIC;
      s01_axis_tdata : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
      s01_axis_tstrb : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
      s01_axis_tkeep : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
      s01_axis_tlast : IN STD_LOGIC;
      s01_axis_tvalid : IN STD_LOGIC;
      s01_axis_tready : OUT STD_LOGIC;
      s00_axis_tdata : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
      s00_axis_tstrb : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
      s00_axis_tkeep : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
      s00_axis_tlast : IN STD_LOGIC;
      s00_axis_tvalid : IN STD_LOGIC;
      s00_axis_tready : OUT STD_LOGIC
    );
  END COMPONENT axis_switch_2to1_v1_0;
  ATTRIBUTE X_INTERFACE_INFO : STRING;
  ATTRIBUTE X_INTERFACE_PARAMETER : STRING;
  ATTRIBUTE X_INTERFACE_INFO OF s00_axis_tready: SIGNAL IS "xilinx.com:interface:axis:1.0 S00_AXIS TREADY";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axis_tvalid: SIGNAL IS "xilinx.com:interface:axis:1.0 S00_AXIS TVALID";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axis_tlast: SIGNAL IS "xilinx.com:interface:axis:1.0 S00_AXIS TLAST";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axis_tkeep: SIGNAL IS "xilinx.com:interface:axis:1.0 S00_AXIS TKEEP";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axis_tstrb: SIGNAL IS "xilinx.com:interface:axis:1.0 S00_AXIS TSTRB";
  ATTRIBUTE X_INTERFACE_PARAMETER OF s00_axis_tdata: SIGNAL IS "XIL_INTERFACENAME S00_AXIS, WIZ_DATA_WIDTH 32, TDATA_NUM_BYTES 4, TDEST_WIDTH 0, TID_WIDTH 0, TUSER_WIDTH 0, HAS_TREADY 1, HAS_TSTRB 1, HAS_TKEEP 1, HAS_TLAST 1, FREQ_HZ 100000000, PHASE 0.000, LAYERED_METADATA undef";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axis_tdata: SIGNAL IS "xilinx.com:interface:axis:1.0 S00_AXIS TDATA";
  ATTRIBUTE X_INTERFACE_INFO OF s01_axis_tready: SIGNAL IS "xilinx.com:interface:axis:1.0 S01_AXIS TREADY";
  ATTRIBUTE X_INTERFACE_INFO OF s01_axis_tvalid: SIGNAL IS "xilinx.com:interface:axis:1.0 S01_AXIS TVALID";
  ATTRIBUTE X_INTERFACE_INFO OF s01_axis_tlast: SIGNAL IS "xilinx.com:interface:axis:1.0 S01_AXIS TLAST";
  ATTRIBUTE X_INTERFACE_INFO OF s01_axis_tkeep: SIGNAL IS "xilinx.com:interface:axis:1.0 S01_AXIS TKEEP";
  ATTRIBUTE X_INTERFACE_INFO OF s01_axis_tstrb: SIGNAL IS "xilinx.com:interface:axis:1.0 S01_AXIS TSTRB";
  ATTRIBUTE X_INTERFACE_PARAMETER OF s01_axis_tdata: SIGNAL IS "XIL_INTERFACENAME S01_AXIS, WIZ_DATA_WIDTH 32, TDATA_NUM_BYTES 4, TDEST_WIDTH 0, TID_WIDTH 0, TUSER_WIDTH 0, HAS_TREADY 1, HAS_TSTRB 1, HAS_TKEEP 1, HAS_TLAST 1, FREQ_HZ 100000000, PHASE 0.000, LAYERED_METADATA undef";
  ATTRIBUTE X_INTERFACE_INFO OF s01_axis_tdata: SIGNAL IS "xilinx.com:interface:axis:1.0 S01_AXIS TDATA";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axis_tready: SIGNAL IS "xilinx.com:interface:axis:1.0 M00_AXIS TREADY";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axis_tvalid: SIGNAL IS "xilinx.com:interface:axis:1.0 M00_AXIS TVALID";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axis_tlast: SIGNAL IS "xilinx.com:interface:axis:1.0 M00_AXIS TLAST";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axis_tkeep: SIGNAL IS "xilinx.com:interface:axis:1.0 M00_AXIS TKEEP";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axis_tstrb: SIGNAL IS "xilinx.com:interface:axis:1.0 M00_AXIS TSTRB";
  ATTRIBUTE X_INTERFACE_PARAMETER OF m00_axis_tdata: SIGNAL IS "XIL_INTERFACENAME M00_AXIS, WIZ_DATA_WIDTH 32, TDATA_NUM_BYTES 4, TDEST_WIDTH 0, TID_WIDTH 0, TUSER_WIDTH 0, HAS_TREADY 1, HAS_TSTRB 1, HAS_TKEEP 1, HAS_TLAST 1, FREQ_HZ 100000000, PHASE 0.000, LAYERED_METADATA undef";
  ATTRIBUTE X_INTERFACE_INFO OF m00_axis_tdata: SIGNAL IS "xilinx.com:interface:axis:1.0 M00_AXIS TDATA";
BEGIN
  U0 : axis_switch_2to1_v1_0
    GENERIC MAP (
      C_M00_AXIS_TDATA_WIDTH => 32,
      C_M00_AXIS_START_COUNT => 32,
      C_S01_AXIS_TDATA_WIDTH => 32,
      C_S00_AXIS_TDATA_WIDTH => 32
    )
    PORT MAP (
      select_S01_SI => select_S01_SI,
      m00_axis_tdata => m00_axis_tdata,
      m00_axis_tstrb => m00_axis_tstrb,
      m00_axis_tkeep => m00_axis_tkeep,
      m00_axis_tlast => m00_axis_tlast,
      m00_axis_tvalid => m00_axis_tvalid,
      m00_axis_tready => m00_axis_tready,
      s01_axis_tdata => s01_axis_tdata,
      s01_axis_tstrb => s01_axis_tstrb,
      s01_axis_tkeep => s01_axis_tkeep,
      s01_axis_tlast => s01_axis_tlast,
      s01_axis_tvalid => s01_axis_tvalid,
      s01_axis_tready => s01_axis_tready,
      s00_axis_tdata => s00_axis_tdata,
      s00_axis_tstrb => s00_axis_tstrb,
      s00_axis_tkeep => s00_axis_tkeep,
      s00_axis_tlast => s00_axis_tlast,
      s00_axis_tvalid => s00_axis_tvalid,
      s00_axis_tready => s00_axis_tready
    );
END design_1_axis_switch_2to1_0_0_arch;
