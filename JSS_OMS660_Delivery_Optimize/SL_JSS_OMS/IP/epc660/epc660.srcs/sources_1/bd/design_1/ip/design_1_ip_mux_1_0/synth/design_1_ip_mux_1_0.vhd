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

-- IP VLNV: xilinx.com:module_ref:ip_mux:1.0
-- IP Revision: 1

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY design_1_ip_mux_1_0 IS
  PORT (
    data_in : IN STD_LOGIC_VECTOR(11 DOWNTO 0);
    hsync_in : IN STD_LOGIC;
    vsync_in : IN STD_LOGIC;
    xsync_sat_in : IN STD_LOGIC;
    data_in1 : IN STD_LOGIC_VECTOR(11 DOWNTO 0);
    hsync_in1 : IN STD_LOGIC;
    vsync_in1 : IN STD_LOGIC;
    xsync_sat_in1 : IN STD_LOGIC;
    data_in2 : IN STD_LOGIC_VECTOR(11 DOWNTO 0);
    hsync_in2 : IN STD_LOGIC;
    vsync_in2 : IN STD_LOGIC;
    xsync_sat_in2 : IN STD_LOGIC;
    data_in3 : IN STD_LOGIC_VECTOR(11 DOWNTO 0);
    hsync_in3 : IN STD_LOGIC;
    vsync_in3 : IN STD_LOGIC;
    xsync_sat_in3 : IN STD_LOGIC;
    data_out : OUT STD_LOGIC_VECTOR(11 DOWNTO 0);
    hsync_out : OUT STD_LOGIC;
    vsync_out : OUT STD_LOGIC;
    xsync_sat_out : OUT STD_LOGIC;
    sel1 : IN STD_LOGIC;
    sel2 : IN STD_LOGIC
  );
END design_1_ip_mux_1_0;

ARCHITECTURE design_1_ip_mux_1_0_arch OF design_1_ip_mux_1_0 IS
  ATTRIBUTE DowngradeIPIdentifiedWarnings : STRING;
  ATTRIBUTE DowngradeIPIdentifiedWarnings OF design_1_ip_mux_1_0_arch: ARCHITECTURE IS "yes";
  COMPONENT ip_mux IS
    PORT (
      data_in : IN STD_LOGIC_VECTOR(11 DOWNTO 0);
      hsync_in : IN STD_LOGIC;
      vsync_in : IN STD_LOGIC;
      xsync_sat_in : IN STD_LOGIC;
      data_in1 : IN STD_LOGIC_VECTOR(11 DOWNTO 0);
      hsync_in1 : IN STD_LOGIC;
      vsync_in1 : IN STD_LOGIC;
      xsync_sat_in1 : IN STD_LOGIC;
      data_in2 : IN STD_LOGIC_VECTOR(11 DOWNTO 0);
      hsync_in2 : IN STD_LOGIC;
      vsync_in2 : IN STD_LOGIC;
      xsync_sat_in2 : IN STD_LOGIC;
      data_in3 : IN STD_LOGIC_VECTOR(11 DOWNTO 0);
      hsync_in3 : IN STD_LOGIC;
      vsync_in3 : IN STD_LOGIC;
      xsync_sat_in3 : IN STD_LOGIC;
      data_out : OUT STD_LOGIC_VECTOR(11 DOWNTO 0);
      hsync_out : OUT STD_LOGIC;
      vsync_out : OUT STD_LOGIC;
      xsync_sat_out : OUT STD_LOGIC;
      sel1 : IN STD_LOGIC;
      sel2 : IN STD_LOGIC
    );
  END COMPONENT ip_mux;
  ATTRIBUTE X_CORE_INFO : STRING;
  ATTRIBUTE X_CORE_INFO OF design_1_ip_mux_1_0_arch: ARCHITECTURE IS "ip_mux,Vivado 2018.2.2";
  ATTRIBUTE CHECK_LICENSE_TYPE : STRING;
  ATTRIBUTE CHECK_LICENSE_TYPE OF design_1_ip_mux_1_0_arch : ARCHITECTURE IS "design_1_ip_mux_1_0,ip_mux,{}";
  ATTRIBUTE CORE_GENERATION_INFO : STRING;
  ATTRIBUTE CORE_GENERATION_INFO OF design_1_ip_mux_1_0_arch: ARCHITECTURE IS "design_1_ip_mux_1_0,ip_mux,{x_ipProduct=Vivado 2018.2.2,x_ipVendor=xilinx.com,x_ipLibrary=module_ref,x_ipName=ip_mux,x_ipVersion=1.0,x_ipCoreRevision=1,x_ipLanguage=VHDL,x_ipSimLanguage=MIXED}";
  ATTRIBUTE IP_DEFINITION_SOURCE : STRING;
  ATTRIBUTE IP_DEFINITION_SOURCE OF design_1_ip_mux_1_0_arch: ARCHITECTURE IS "module_ref";
BEGIN
  U0 : ip_mux
    PORT MAP (
      data_in => data_in,
      hsync_in => hsync_in,
      vsync_in => vsync_in,
      xsync_sat_in => xsync_sat_in,
      data_in1 => data_in1,
      hsync_in1 => hsync_in1,
      vsync_in1 => vsync_in1,
      xsync_sat_in1 => xsync_sat_in1,
      data_in2 => data_in2,
      hsync_in2 => hsync_in2,
      vsync_in2 => vsync_in2,
      xsync_sat_in2 => xsync_sat_in2,
      data_in3 => data_in3,
      hsync_in3 => hsync_in3,
      vsync_in3 => vsync_in3,
      xsync_sat_in3 => xsync_sat_in3,
      data_out => data_out,
      hsync_out => hsync_out,
      vsync_out => vsync_out,
      xsync_sat_out => xsync_sat_out,
      sel1 => sel1,
      sel2 => sel2
    );
END design_1_ip_mux_1_0_arch;
