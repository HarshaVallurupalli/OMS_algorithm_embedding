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

-- IP VLNV: xilinx.com:user:reg_bank:1.0
-- IP Revision: 48

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY design_1_reg_bank_0_0 IS
  PORT (
    reset_cc_regs_RI : IN STD_LOGIC;
    cc_rst_RO : OUT STD_LOGIC;
    cc_update_reg_values_SO : OUT STD_LOGIC;
    cc_mode_SO : OUT STD_LOGIC_VECTOR(2 DOWNTO 0);
    cc_init_bad_pix_SO : OUT STD_LOGIC;
    cc_line_length_DO : OUT STD_LOGIC_VECTOR(8 DOWNTO 0);
    cc_data_length_DO : OUT STD_LOGIC_VECTOR(16 DOWNTO 0);
    alu_amp_corr_DO : OUT STD_LOGIC_VECTOR(11 DOWNTO 0);
    alu_dist_corr_DO : OUT STD_LOGIC_VECTOR(11 DOWNTO 0);
    alu_min_index_DO : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
    ambient_comp_DO : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
    interf_thr_DO : OUT STD_LOGIC_VECTOR(12 DOWNTO 0);
    temp_const_val_DO : OUT STD_LOGIC_VECTOR(16 DOWNTO 0);
    dist_dll_DO : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
    nb_dll_steps_DO : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
    dist_index_trunc_DI : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
    dist_index_low_SI : IN STD_LOGIC;
    dist_index_high_SI : IN STD_LOGIC;
    dist_fail_pos_DI : IN STD_LOGIC_VECTOR(16 DOWNTO 0);
    const_val_DO : OUT STD_LOGIC_VECTOR(16 DOWNTO 0);
    cc_en_SO : OUT STD_LOGIC;
    temp_comp_en_SO : OUT STD_LOGIC;
    dist_corr_en_SO : OUT STD_LOGIC;
    comp_en_SO : OUT STD_LOGIC;
    adc_ovrflow_en_SO : OUT STD_LOGIC;
    adc_udrflow_en_SO : OUT STD_LOGIC;
    gs_comp_en_SO : OUT STD_LOGIC;
    gs_subtract_en_SO : OUT STD_LOGIC;
    image_bin_en_SO : OUT STD_LOGIC;
    image_bin_rem_sat_SO : OUT STD_LOGIC;
    ambient_en_SO : OUT STD_LOGIC;
    pix_inter_dcs_en_SO : OUT STD_LOGIC;
    pix_inter_dist_en_SO : OUT STD_LOGIC;
    adc_inter_en_SO : OUT STD_LOGIC;
    ram_read_addr_DO : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    mult_fact_DO : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
    max_out_val_DO : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
    dcs_dma_addr_DO : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    gs_dma_addr_DO : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    dcs_dma_rdy_DI : IN STD_LOGIC;
    dcs_dma_busy_DI : IN STD_LOGIC;
    dcs_dma_done_DI : IN STD_LOGIC;
    dcs_wr_eof_done_SI : IN STD_LOGIC;
    gs_dma_rdy_DI : IN STD_LOGIC;
    gs_dma_busy_DI : IN STD_LOGIC;
    gs_dma_done_DI : IN STD_LOGIC;
    gs_wr_eof_done_SI : IN STD_LOGIC;
    roi_tl_x_DO : OUT STD_LOGIC_VECTOR(8 DOWNTO 0);
    roi_br_x_DO : OUT STD_LOGIC_VECTOR(8 DOWNTO 0);
    roi_tl_y_DO : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
    roi_br_y_DO : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
    roi_full_x_DO : OUT STD_LOGIC_VECTOR(8 DOWNTO 0);
    roi_full_y_DO : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
    dbg_en_SO : OUT STD_LOGIC;
    dbg_pxl_count_DO : OUT STD_LOGIC_VECTOR(16 DOWNTO 0);
    dbg_pxl_index_DO : OUT STD_LOGIC_VECTOR(16 DOWNTO 0);
    s00_axi_awaddr : IN STD_LOGIC_VECTOR(5 DOWNTO 0);
    s00_axi_awprot : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
    s00_axi_awvalid : IN STD_LOGIC;
    s00_axi_awready : OUT STD_LOGIC;
    s00_axi_wdata : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    s00_axi_wstrb : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    s00_axi_wvalid : IN STD_LOGIC;
    s00_axi_wready : OUT STD_LOGIC;
    s00_axi_bresp : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
    s00_axi_bvalid : OUT STD_LOGIC;
    s00_axi_bready : IN STD_LOGIC;
    s00_axi_araddr : IN STD_LOGIC_VECTOR(5 DOWNTO 0);
    s00_axi_arprot : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
    s00_axi_arvalid : IN STD_LOGIC;
    s00_axi_arready : OUT STD_LOGIC;
    s00_axi_rdata : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    s00_axi_rresp : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
    s00_axi_rvalid : OUT STD_LOGIC;
    s00_axi_rready : IN STD_LOGIC;
    s00_axi_aclk : IN STD_LOGIC;
    s00_axi_aresetn : IN STD_LOGIC
  );
END design_1_reg_bank_0_0;

ARCHITECTURE design_1_reg_bank_0_0_arch OF design_1_reg_bank_0_0 IS
  ATTRIBUTE DowngradeIPIdentifiedWarnings : STRING;
  ATTRIBUTE DowngradeIPIdentifiedWarnings OF design_1_reg_bank_0_0_arch: ARCHITECTURE IS "yes";
  COMPONENT reg_bank_v1_0 IS
    GENERIC (
      C_S00_AXI_DATA_WIDTH : INTEGER; -- Width of S_AXI data bus
      C_S00_AXI_ADDR_WIDTH : INTEGER; -- Width of S_AXI address bus
      NBITS_DLL_STEPS : INTEGER
    );
    PORT (
      reset_cc_regs_RI : IN STD_LOGIC;
      cc_rst_RO : OUT STD_LOGIC;
      cc_update_reg_values_SO : OUT STD_LOGIC;
      cc_mode_SO : OUT STD_LOGIC_VECTOR(2 DOWNTO 0);
      cc_init_bad_pix_SO : OUT STD_LOGIC;
      cc_line_length_DO : OUT STD_LOGIC_VECTOR(8 DOWNTO 0);
      cc_data_length_DO : OUT STD_LOGIC_VECTOR(16 DOWNTO 0);
      alu_amp_corr_DO : OUT STD_LOGIC_VECTOR(11 DOWNTO 0);
      alu_dist_corr_DO : OUT STD_LOGIC_VECTOR(11 DOWNTO 0);
      alu_min_index_DO : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
      ambient_comp_DO : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
      interf_thr_DO : OUT STD_LOGIC_VECTOR(12 DOWNTO 0);
      temp_const_val_DO : OUT STD_LOGIC_VECTOR(16 DOWNTO 0);
      dist_dll_DO : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
      nb_dll_steps_DO : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
      dist_index_trunc_DI : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
      dist_index_low_SI : IN STD_LOGIC;
      dist_index_high_SI : IN STD_LOGIC;
      dist_fail_pos_DI : IN STD_LOGIC_VECTOR(16 DOWNTO 0);
      const_val_DO : OUT STD_LOGIC_VECTOR(16 DOWNTO 0);
      cc_en_SO : OUT STD_LOGIC;
      temp_comp_en_SO : OUT STD_LOGIC;
      dist_corr_en_SO : OUT STD_LOGIC;
      comp_en_SO : OUT STD_LOGIC;
      adc_ovrflow_en_SO : OUT STD_LOGIC;
      adc_udrflow_en_SO : OUT STD_LOGIC;
      gs_comp_en_SO : OUT STD_LOGIC;
      gs_subtract_en_SO : OUT STD_LOGIC;
      image_bin_en_SO : OUT STD_LOGIC;
      image_bin_rem_sat_SO : OUT STD_LOGIC;
      ambient_en_SO : OUT STD_LOGIC;
      pix_inter_dcs_en_SO : OUT STD_LOGIC;
      pix_inter_dist_en_SO : OUT STD_LOGIC;
      adc_inter_en_SO : OUT STD_LOGIC;
      ram_read_addr_DO : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
      mult_fact_DO : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
      max_out_val_DO : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
      dcs_dma_addr_DO : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
      gs_dma_addr_DO : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
      dcs_dma_rdy_DI : IN STD_LOGIC;
      dcs_dma_busy_DI : IN STD_LOGIC;
      dcs_dma_done_DI : IN STD_LOGIC;
      dcs_wr_eof_done_SI : IN STD_LOGIC;
      gs_dma_rdy_DI : IN STD_LOGIC;
      gs_dma_busy_DI : IN STD_LOGIC;
      gs_dma_done_DI : IN STD_LOGIC;
      gs_wr_eof_done_SI : IN STD_LOGIC;
      roi_tl_x_DO : OUT STD_LOGIC_VECTOR(8 DOWNTO 0);
      roi_br_x_DO : OUT STD_LOGIC_VECTOR(8 DOWNTO 0);
      roi_tl_y_DO : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
      roi_br_y_DO : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
      roi_full_x_DO : OUT STD_LOGIC_VECTOR(8 DOWNTO 0);
      roi_full_y_DO : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
      dbg_en_SO : OUT STD_LOGIC;
      dbg_pxl_count_DO : OUT STD_LOGIC_VECTOR(16 DOWNTO 0);
      dbg_pxl_index_DO : OUT STD_LOGIC_VECTOR(16 DOWNTO 0);
      s00_axi_awaddr : IN STD_LOGIC_VECTOR(5 DOWNTO 0);
      s00_axi_awprot : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
      s00_axi_awvalid : IN STD_LOGIC;
      s00_axi_awready : OUT STD_LOGIC;
      s00_axi_wdata : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
      s00_axi_wstrb : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
      s00_axi_wvalid : IN STD_LOGIC;
      s00_axi_wready : OUT STD_LOGIC;
      s00_axi_bresp : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
      s00_axi_bvalid : OUT STD_LOGIC;
      s00_axi_bready : IN STD_LOGIC;
      s00_axi_araddr : IN STD_LOGIC_VECTOR(5 DOWNTO 0);
      s00_axi_arprot : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
      s00_axi_arvalid : IN STD_LOGIC;
      s00_axi_arready : OUT STD_LOGIC;
      s00_axi_rdata : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
      s00_axi_rresp : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
      s00_axi_rvalid : OUT STD_LOGIC;
      s00_axi_rready : IN STD_LOGIC;
      s00_axi_aclk : IN STD_LOGIC;
      s00_axi_aresetn : IN STD_LOGIC
    );
  END COMPONENT reg_bank_v1_0;
  ATTRIBUTE X_CORE_INFO : STRING;
  ATTRIBUTE X_CORE_INFO OF design_1_reg_bank_0_0_arch: ARCHITECTURE IS "reg_bank_v1_0,Vivado 2018.2.2";
  ATTRIBUTE CHECK_LICENSE_TYPE : STRING;
  ATTRIBUTE CHECK_LICENSE_TYPE OF design_1_reg_bank_0_0_arch : ARCHITECTURE IS "design_1_reg_bank_0_0,reg_bank_v1_0,{}";
  ATTRIBUTE CORE_GENERATION_INFO : STRING;
  ATTRIBUTE CORE_GENERATION_INFO OF design_1_reg_bank_0_0_arch: ARCHITECTURE IS "design_1_reg_bank_0_0,reg_bank_v1_0,{x_ipProduct=Vivado 2018.2.2,x_ipVendor=xilinx.com,x_ipLibrary=user,x_ipName=reg_bank,x_ipVersion=1.0,x_ipCoreRevision=48,x_ipLanguage=VHDL,x_ipSimLanguage=MIXED,C_S00_AXI_DATA_WIDTH=32,C_S00_AXI_ADDR_WIDTH=6,NBITS_DLL_STEPS=8}";
  ATTRIBUTE X_INTERFACE_INFO : STRING;
  ATTRIBUTE X_INTERFACE_PARAMETER : STRING;
  ATTRIBUTE X_INTERFACE_PARAMETER OF s00_axi_aresetn: SIGNAL IS "XIL_INTERFACENAME S00_AXI_RST, POLARITY ACTIVE_LOW";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_aresetn: SIGNAL IS "xilinx.com:signal:reset:1.0 S00_AXI_RST RST";
  ATTRIBUTE X_INTERFACE_PARAMETER OF s00_axi_aclk: SIGNAL IS "XIL_INTERFACENAME S00_AXI_CLK, ASSOCIATED_BUSIF S00_AXI, ASSOCIATED_RESET s00_axi_aresetn, FREQ_HZ 100000000, PHASE 0.000, CLK_DOMAIN design_1_processing_system7_1_0_FCLK_CLK0";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_aclk: SIGNAL IS "xilinx.com:signal:clock:1.0 S00_AXI_CLK CLK";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_rready: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI RREADY";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_rvalid: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI RVALID";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_rresp: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI RRESP";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_rdata: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI RDATA";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_arready: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI ARREADY";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_arvalid: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI ARVALID";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_arprot: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI ARPROT";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_araddr: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI ARADDR";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_bready: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI BREADY";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_bvalid: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI BVALID";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_bresp: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI BRESP";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_wready: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI WREADY";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_wvalid: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI WVALID";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_wstrb: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI WSTRB";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_wdata: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI WDATA";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_awready: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI AWREADY";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_awvalid: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI AWVALID";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_awprot: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI AWPROT";
  ATTRIBUTE X_INTERFACE_PARAMETER OF s00_axi_awaddr: SIGNAL IS "XIL_INTERFACENAME S00_AXI, WIZ_DATA_WIDTH 32, WIZ_NUM_REG 8, SUPPORTS_NARROW_BURST 0, DATA_WIDTH 32, PROTOCOL AXI4LITE, FREQ_HZ 100000000, ID_WIDTH 0, ADDR_WIDTH 6, AWUSER_WIDTH 0, ARUSER_WIDTH 0, WUSER_WIDTH 0, RUSER_WIDTH 0, BUSER_WIDTH 0, READ_WRITE_MODE READ_WRITE, HAS_BURST 0, HAS_LOCK 0, HAS_PROT 1, HAS_CACHE 0, HAS_QOS 0, HAS_REGION 0, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, NUM_READ_OUTSTANDING 1, NUM_WRITE_OUTSTANDING 1, MAX_BURST_LENGTH 1, PHASE 0.000, CLK_DOMAIN design_1_processing_sys" & 
"tem7_1_0_FCLK_CLK0, NUM_READ_THREADS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0";
  ATTRIBUTE X_INTERFACE_INFO OF s00_axi_awaddr: SIGNAL IS "xilinx.com:interface:aximm:1.0 S00_AXI AWADDR";
  ATTRIBUTE X_INTERFACE_PARAMETER OF reset_cc_regs_RI: SIGNAL IS "XIL_INTERFACENAME reset_cc_regs_RI, POLARITY ACTIVE_LOW";
  ATTRIBUTE X_INTERFACE_INFO OF reset_cc_regs_RI: SIGNAL IS "xilinx.com:signal:reset:1.0 reset_cc_regs_RI RST";
BEGIN
  U0 : reg_bank_v1_0
    GENERIC MAP (
      C_S00_AXI_DATA_WIDTH => 32,
      C_S00_AXI_ADDR_WIDTH => 6,
      NBITS_DLL_STEPS => 8
    )
    PORT MAP (
      reset_cc_regs_RI => reset_cc_regs_RI,
      cc_rst_RO => cc_rst_RO,
      cc_update_reg_values_SO => cc_update_reg_values_SO,
      cc_mode_SO => cc_mode_SO,
      cc_init_bad_pix_SO => cc_init_bad_pix_SO,
      cc_line_length_DO => cc_line_length_DO,
      cc_data_length_DO => cc_data_length_DO,
      alu_amp_corr_DO => alu_amp_corr_DO,
      alu_dist_corr_DO => alu_dist_corr_DO,
      alu_min_index_DO => alu_min_index_DO,
      ambient_comp_DO => ambient_comp_DO,
      interf_thr_DO => interf_thr_DO,
      temp_const_val_DO => temp_const_val_DO,
      dist_dll_DO => dist_dll_DO,
      nb_dll_steps_DO => nb_dll_steps_DO,
      dist_index_trunc_DI => dist_index_trunc_DI,
      dist_index_low_SI => dist_index_low_SI,
      dist_index_high_SI => dist_index_high_SI,
      dist_fail_pos_DI => dist_fail_pos_DI,
      const_val_DO => const_val_DO,
      cc_en_SO => cc_en_SO,
      temp_comp_en_SO => temp_comp_en_SO,
      dist_corr_en_SO => dist_corr_en_SO,
      comp_en_SO => comp_en_SO,
      adc_ovrflow_en_SO => adc_ovrflow_en_SO,
      adc_udrflow_en_SO => adc_udrflow_en_SO,
      gs_comp_en_SO => gs_comp_en_SO,
      gs_subtract_en_SO => gs_subtract_en_SO,
      image_bin_en_SO => image_bin_en_SO,
      image_bin_rem_sat_SO => image_bin_rem_sat_SO,
      ambient_en_SO => ambient_en_SO,
      pix_inter_dcs_en_SO => pix_inter_dcs_en_SO,
      pix_inter_dist_en_SO => pix_inter_dist_en_SO,
      adc_inter_en_SO => adc_inter_en_SO,
      ram_read_addr_DO => ram_read_addr_DO,
      mult_fact_DO => mult_fact_DO,
      max_out_val_DO => max_out_val_DO,
      dcs_dma_addr_DO => dcs_dma_addr_DO,
      gs_dma_addr_DO => gs_dma_addr_DO,
      dcs_dma_rdy_DI => dcs_dma_rdy_DI,
      dcs_dma_busy_DI => dcs_dma_busy_DI,
      dcs_dma_done_DI => dcs_dma_done_DI,
      dcs_wr_eof_done_SI => dcs_wr_eof_done_SI,
      gs_dma_rdy_DI => gs_dma_rdy_DI,
      gs_dma_busy_DI => gs_dma_busy_DI,
      gs_dma_done_DI => gs_dma_done_DI,
      gs_wr_eof_done_SI => gs_wr_eof_done_SI,
      roi_tl_x_DO => roi_tl_x_DO,
      roi_br_x_DO => roi_br_x_DO,
      roi_tl_y_DO => roi_tl_y_DO,
      roi_br_y_DO => roi_br_y_DO,
      roi_full_x_DO => roi_full_x_DO,
      roi_full_y_DO => roi_full_y_DO,
      dbg_en_SO => dbg_en_SO,
      dbg_pxl_count_DO => dbg_pxl_count_DO,
      dbg_pxl_index_DO => dbg_pxl_index_DO,
      s00_axi_awaddr => s00_axi_awaddr,
      s00_axi_awprot => s00_axi_awprot,
      s00_axi_awvalid => s00_axi_awvalid,
      s00_axi_awready => s00_axi_awready,
      s00_axi_wdata => s00_axi_wdata,
      s00_axi_wstrb => s00_axi_wstrb,
      s00_axi_wvalid => s00_axi_wvalid,
      s00_axi_wready => s00_axi_wready,
      s00_axi_bresp => s00_axi_bresp,
      s00_axi_bvalid => s00_axi_bvalid,
      s00_axi_bready => s00_axi_bready,
      s00_axi_araddr => s00_axi_araddr,
      s00_axi_arprot => s00_axi_arprot,
      s00_axi_arvalid => s00_axi_arvalid,
      s00_axi_arready => s00_axi_arready,
      s00_axi_rdata => s00_axi_rdata,
      s00_axi_rresp => s00_axi_rresp,
      s00_axi_rvalid => s00_axi_rvalid,
      s00_axi_rready => s00_axi_rready,
      s00_axi_aclk => s00_axi_aclk,
      s00_axi_aresetn => s00_axi_aresetn
    );
END design_1_reg_bank_0_0_arch;
