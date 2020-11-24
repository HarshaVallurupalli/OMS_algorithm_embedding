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

-- IP VLNV: xilinx.com:espros:TOF_cos_sl:1.0
-- IP Revision: 77

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY design_1_TOF_cos_sl_0_0 IS
  PORT (
    clk_CI : IN STD_LOGIC;
    reset_RBI : IN STD_LOGIC;
    reset_or_done_edge_RBO : OUT STD_LOGIC;
    dclk_in_SI : IN STD_LOGIC;
    vsync_in_SI : IN STD_LOGIC;
    hsync_in_SI : IN STD_LOGIC;
    xsync_sat_in_SI : IN STD_LOGIC;
    data_in_DI : IN STD_LOGIC_VECTOR(11 DOWNTO 0);
    rbk_cc_en_SI : IN STD_LOGIC;
    rbk_cc_rst_SI : IN STD_LOGIC;
    rbk_cc_update_reg_values_SI : IN STD_LOGIC;
    rbk_cc_mode_SI : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
    rbk_cc_data_length_SI : IN STD_LOGIC_VECTOR(16 DOWNTO 0);
    rbk_image_bin_en_SI : IN STD_LOGIC;
    rbk_img_pix_inter_en_SI : IN STD_LOGIC;
    rbk_img_adc_inter_en_SI : IN STD_LOGIC;
    rbk_im_rem_sat_SI : IN STD_LOGIC;
    rbk_init_table_SI : IN STD_LOGIC;
    rbk_adc_underflow_SI : IN STD_LOGIC;
    rbk_adc_overflow_SI : IN STD_LOGIC;
    rbk_interf_thr_DI : IN STD_LOGIC_VECTOR(12 DOWNTO 0);
    rbk_alu_dist_corr_DI : IN STD_LOGIC_VECTOR(11 DOWNTO 0);
    rbk_alu_amp_corr_DI : IN STD_LOGIC_VECTOR(11 DOWNTO 0);
    rbk_alu_minIndex_DI : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
    rbk_add_const_temp_en_SI : IN STD_LOGIC;
    rbk_add_const_temp_val_DI : IN STD_LOGIC_VECTOR(16 DOWNTO 0);
    rbk_line_length_DI : IN STD_LOGIC_VECTOR(8 DOWNTO 0);
    rbk_dist_mean_filter_en_SI : IN STD_LOGIC;
    rbk_dist_corr_en_SI : IN STD_LOGIC;
    rbk_dist_corr_dll_DI : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
    rbk_dist_dll_steps_DI : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
    rbk_mult_fact_DI : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
    rbk_add_const_en_SI : IN STD_LOGIC;
    rbk_add_const_val_DI : IN STD_LOGIC_VECTOR(16 DOWNTO 0);
    rbk_const_max_val_DI : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
    rbk_ambient_en_SI : IN STD_LOGIC;
    rbk_ambient_comp_DI : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
    rbk_gs_comp_en_SI : IN STD_LOGIC;
    rbk_gs_subtract_SI : IN STD_LOGIC;
    rbk_dbg_en_SI : IN STD_LOGIC;
    rbg_dbg_pxl_count_DI : IN STD_LOGIC_VECTOR(16 DOWNTO 0);
    rbk_dbg_pxl_index_DI : IN STD_LOGIC_VECTOR(16 DOWNTO 0);
    cc_reset_regs_RO : OUT STD_LOGIC;
    dist_offset_index_trunc_DO : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
    dist_offset_fail_pos_DO : OUT STD_LOGIC_VECTOR(16 DOWNTO 0);
    dist_offset_index_low_SO : OUT STD_LOGIC;
    dist_offset_index_high_SO : OUT STD_LOGIC;
    sg_dma_intr_SI : IN STD_LOGIC;
    cc_sort_length_DO : OUT STD_LOGIC_VECTOR(18 DOWNTO 0);
    dist_amp_sat_concat_DO : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    dist_amp_sat_pulse_SO : OUT STD_LOGIC;
    sel_gs_mode_SO : OUT STD_LOGIC;
    tcmi_pixel_cnt_DO : OUT STD_LOGIC_VECTOR(16 DOWNTO 0);
    cc_img_bin_dcs_sel_DO : OUT STD_LOGIC_VECTOR(2 DOWNTO 0);
    readRam_pulse_out_SI : IN STD_LOGIC;
    readRam_data_DI : IN STD_LOGIC_VECTOR(127 DOWNTO 0);
    readRam_en_SO : OUT STD_LOGIC;
    readRam_pulse_SO : OUT STD_LOGIC;
    readRam_index_DO : OUT STD_LOGIC_VECTOR(4 DOWNTO 0);
    gs_data_DO : OUT STD_LOGIC_VECTOR(12 DOWNTO 0);
    en_d2r_gs_SO : OUT STD_LOGIC;
    length_gs_data_DO : OUT STD_LOGIC_VECTOR(18 DOWNTO 0);
    grey_pulse_out_SO : OUT STD_LOGIC;
    grey_pulse_in_SO : OUT STD_LOGIC;
    gs_data_DI : IN STD_LOGIC_VECTOR(12 DOWNTO 0);
    cc_dcs_length_DO : OUT STD_LOGIC_VECTOR(16 DOWNTO 0);
    dcs_data_DO : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
    en_d2r_dcs_SO : OUT STD_LOGIC;
    en_d2r_wr_dcs_SO : OUT STD_LOGIC;
    reg_dcs0_or_dcs1_pulse_SO : OUT STD_LOGIC;
    dcs2_or_dcs3_pulse_SO : OUT STD_LOGIC;
    ram_dcs_data_DI : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
    DbgBram_Addr : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    DbgBram_Data : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    DbgBram_Wen : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
  );
END design_1_TOF_cos_sl_0_0;

ARCHITECTURE design_1_TOF_cos_sl_0_0_arch OF design_1_TOF_cos_sl_0_0 IS
  ATTRIBUTE DowngradeIPIdentifiedWarnings : STRING;
  ATTRIBUTE DowngradeIPIdentifiedWarnings OF design_1_TOF_cos_sl_0_0_arch: ARCHITECTURE IS "yes";
  COMPONENT TOF_cos_sl IS
    GENERIC (
      NB_OF_PIXEL : INTEGER;
      NBITS_DATA_IN : INTEGER;
      NBITS_LENGTH : INTEGER;
      NBITS_LINE_LENGTH : INTEGER;
      NBITS_ADDR_IMG_BRAM : INTEGER;
      NBITS_ADDR_BRAM_DCS : INTEGER;
      NBITS_DATA_BRAM_DCS : INTEGER;
      MEM_SIZE_BRAM_DCS : INTEGER;
      NBITS_ADDR_FIFO0 : INTEGER;
      NBITS_ADDR_FIFO1 : INTEGER;
      NBITS_DIST_OUT : INTEGER;
      NBITS_AMP_OUT : INTEGER;
      NBITS_MININDEX : INTEGER;
      NBITS_CAL_RAM : INTEGER;
      NBITS_DIST_INDEX : INTEGER;
      NBITS_DIST_MEM_CTRL : INTEGER;
      NBITS_DLL_CORR : INTEGER;
      NBITS_NB_DLL_STEPS : INTEGER;
      NBITS_OUTPUT_DATA : INTEGER;
      NBITS_AL_COMP : INTEGER;
      ENABLE_INPUT_FIFO : BOOLEAN;
      ENABLE_DELAY_NB : INTEGER;
      NBITS_GS_RAM : INTEGER;
      NBITS_MAX_GS_RAM_DATA_IN : INTEGER
    );
    PORT (
      clk_CI : IN STD_LOGIC;
      reset_RBI : IN STD_LOGIC;
      reset_or_done_edge_RBO : OUT STD_LOGIC;
      dclk_in_SI : IN STD_LOGIC;
      vsync_in_SI : IN STD_LOGIC;
      hsync_in_SI : IN STD_LOGIC;
      xsync_sat_in_SI : IN STD_LOGIC;
      data_in_DI : IN STD_LOGIC_VECTOR(11 DOWNTO 0);
      rbk_cc_en_SI : IN STD_LOGIC;
      rbk_cc_rst_SI : IN STD_LOGIC;
      rbk_cc_update_reg_values_SI : IN STD_LOGIC;
      rbk_cc_mode_SI : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
      rbk_cc_data_length_SI : IN STD_LOGIC_VECTOR(16 DOWNTO 0);
      rbk_image_bin_en_SI : IN STD_LOGIC;
      rbk_img_pix_inter_en_SI : IN STD_LOGIC;
      rbk_img_adc_inter_en_SI : IN STD_LOGIC;
      rbk_im_rem_sat_SI : IN STD_LOGIC;
      rbk_init_table_SI : IN STD_LOGIC;
      rbk_adc_underflow_SI : IN STD_LOGIC;
      rbk_adc_overflow_SI : IN STD_LOGIC;
      rbk_interf_thr_DI : IN STD_LOGIC_VECTOR(12 DOWNTO 0);
      rbk_alu_dist_corr_DI : IN STD_LOGIC_VECTOR(11 DOWNTO 0);
      rbk_alu_amp_corr_DI : IN STD_LOGIC_VECTOR(11 DOWNTO 0);
      rbk_alu_minIndex_DI : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
      rbk_add_const_temp_en_SI : IN STD_LOGIC;
      rbk_add_const_temp_val_DI : IN STD_LOGIC_VECTOR(16 DOWNTO 0);
      rbk_line_length_DI : IN STD_LOGIC_VECTOR(8 DOWNTO 0);
      rbk_dist_mean_filter_en_SI : IN STD_LOGIC;
      rbk_dist_corr_en_SI : IN STD_LOGIC;
      rbk_dist_corr_dll_DI : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
      rbk_dist_dll_steps_DI : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
      rbk_mult_fact_DI : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
      rbk_add_const_en_SI : IN STD_LOGIC;
      rbk_add_const_val_DI : IN STD_LOGIC_VECTOR(16 DOWNTO 0);
      rbk_const_max_val_DI : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
      rbk_ambient_en_SI : IN STD_LOGIC;
      rbk_ambient_comp_DI : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
      rbk_gs_comp_en_SI : IN STD_LOGIC;
      rbk_gs_subtract_SI : IN STD_LOGIC;
      rbk_dbg_en_SI : IN STD_LOGIC;
      rbg_dbg_pxl_count_DI : IN STD_LOGIC_VECTOR(16 DOWNTO 0);
      rbk_dbg_pxl_index_DI : IN STD_LOGIC_VECTOR(16 DOWNTO 0);
      cc_reset_regs_RO : OUT STD_LOGIC;
      dist_offset_index_trunc_DO : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
      dist_offset_fail_pos_DO : OUT STD_LOGIC_VECTOR(16 DOWNTO 0);
      dist_offset_index_low_SO : OUT STD_LOGIC;
      dist_offset_index_high_SO : OUT STD_LOGIC;
      sg_dma_intr_SI : IN STD_LOGIC;
      cc_sort_length_DO : OUT STD_LOGIC_VECTOR(18 DOWNTO 0);
      dist_amp_sat_concat_DO : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
      dist_amp_sat_pulse_SO : OUT STD_LOGIC;
      sel_gs_mode_SO : OUT STD_LOGIC;
      tcmi_pixel_cnt_DO : OUT STD_LOGIC_VECTOR(16 DOWNTO 0);
      cc_img_bin_dcs_sel_DO : OUT STD_LOGIC_VECTOR(2 DOWNTO 0);
      readRam_pulse_out_SI : IN STD_LOGIC;
      readRam_data_DI : IN STD_LOGIC_VECTOR(127 DOWNTO 0);
      readRam_en_SO : OUT STD_LOGIC;
      readRam_pulse_SO : OUT STD_LOGIC;
      readRam_index_DO : OUT STD_LOGIC_VECTOR(4 DOWNTO 0);
      gs_data_DO : OUT STD_LOGIC_VECTOR(12 DOWNTO 0);
      en_d2r_gs_SO : OUT STD_LOGIC;
      length_gs_data_DO : OUT STD_LOGIC_VECTOR(18 DOWNTO 0);
      grey_pulse_out_SO : OUT STD_LOGIC;
      grey_pulse_in_SO : OUT STD_LOGIC;
      gs_data_DI : IN STD_LOGIC_VECTOR(12 DOWNTO 0);
      cc_dcs_length_DO : OUT STD_LOGIC_VECTOR(16 DOWNTO 0);
      dcs_data_DO : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
      en_d2r_dcs_SO : OUT STD_LOGIC;
      en_d2r_wr_dcs_SO : OUT STD_LOGIC;
      reg_dcs0_or_dcs1_pulse_SO : OUT STD_LOGIC;
      dcs2_or_dcs3_pulse_SO : OUT STD_LOGIC;
      ram_dcs_data_DI : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
      DbgBram_Addr : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
      DbgBram_Data : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
      DbgBram_Wen : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
    );
  END COMPONENT TOF_cos_sl;
  ATTRIBUTE X_CORE_INFO : STRING;
  ATTRIBUTE X_CORE_INFO OF design_1_TOF_cos_sl_0_0_arch: ARCHITECTURE IS "TOF_cos_sl,Vivado 2018.2.2";
  ATTRIBUTE CHECK_LICENSE_TYPE : STRING;
  ATTRIBUTE CHECK_LICENSE_TYPE OF design_1_TOF_cos_sl_0_0_arch : ARCHITECTURE IS "design_1_TOF_cos_sl_0_0,TOF_cos_sl,{}";
  ATTRIBUTE CORE_GENERATION_INFO : STRING;
  ATTRIBUTE CORE_GENERATION_INFO OF design_1_TOF_cos_sl_0_0_arch: ARCHITECTURE IS "design_1_TOF_cos_sl_0_0,TOF_cos_sl,{x_ipProduct=Vivado 2018.2.2,x_ipVendor=xilinx.com,x_ipLibrary=espros,x_ipName=TOF_cos_sl,x_ipVersion=1.0,x_ipCoreRevision=77,x_ipLanguage=VHDL,x_ipSimLanguage=MIXED,NB_OF_PIXEL=76800,NBITS_DATA_IN=12,NBITS_LENGTH=17,NBITS_LINE_LENGTH=9,NBITS_ADDR_IMG_BRAM=10,NBITS_ADDR_BRAM_DCS=10,NBITS_DATA_BRAM_DCS=16,MEM_SIZE_BRAM_DCS=640,NBITS_ADDR_FIFO0=16,NBITS_ADDR_FIFO1=14,NBITS_DIST_OUT=16,NBITS_AMP_OUT=12,NBITS_MININDEX=8,NBITS_CAL_RAM=128,NBITS_DIST_INDEX=5,NBITS_DI" & 
"ST_MEM_CTRL=9,NBITS_DLL_CORR=16,NBITS_NB_DLL_STEPS=8,NBITS_OUTPUT_DATA=32,NBITS_AL_COMP=16,ENABLE_INPUT_FIFO=true,ENABLE_DELAY_NB=1200,NBITS_GS_RAM=16,NBITS_MAX_GS_RAM_DATA_IN=16}";
  ATTRIBUTE IP_DEFINITION_SOURCE : STRING;
  ATTRIBUTE IP_DEFINITION_SOURCE OF design_1_TOF_cos_sl_0_0_arch: ARCHITECTURE IS "package_project";
  ATTRIBUTE X_INTERFACE_INFO : STRING;
  ATTRIBUTE X_INTERFACE_PARAMETER : STRING;
  ATTRIBUTE X_INTERFACE_PARAMETER OF sg_dma_intr_SI: SIGNAL IS "XIL_INTERFACENAME sg_dma_intr_SI, SENSITIVITY LEVEL_HIGH, PortWidth 1";
  ATTRIBUTE X_INTERFACE_INFO OF sg_dma_intr_SI: SIGNAL IS "xilinx.com:signal:interrupt:1.0 sg_dma_intr_SI INTERRUPT";
  ATTRIBUTE X_INTERFACE_PARAMETER OF reset_or_done_edge_RBO: SIGNAL IS "XIL_INTERFACENAME reset_or_done_edge_RBO, POLARITY ACTIVE_LOW";
  ATTRIBUTE X_INTERFACE_INFO OF reset_or_done_edge_RBO: SIGNAL IS "xilinx.com:signal:reset:1.0 reset_or_done_edge_RBO RST";
  ATTRIBUTE X_INTERFACE_PARAMETER OF reset_RBI: SIGNAL IS "XIL_INTERFACENAME reset_RBI, POLARITY ACTIVE_LOW";
  ATTRIBUTE X_INTERFACE_INFO OF reset_RBI: SIGNAL IS "xilinx.com:signal:reset:1.0 reset_RBI RST";
BEGIN
  U0 : TOF_cos_sl
    GENERIC MAP (
      NB_OF_PIXEL => 76800,
      NBITS_DATA_IN => 12,
      NBITS_LENGTH => 17,
      NBITS_LINE_LENGTH => 9,
      NBITS_ADDR_IMG_BRAM => 10,
      NBITS_ADDR_BRAM_DCS => 10,
      NBITS_DATA_BRAM_DCS => 16,
      MEM_SIZE_BRAM_DCS => 640,
      NBITS_ADDR_FIFO0 => 16,
      NBITS_ADDR_FIFO1 => 14,
      NBITS_DIST_OUT => 16,
      NBITS_AMP_OUT => 12,
      NBITS_MININDEX => 8,
      NBITS_CAL_RAM => 128,
      NBITS_DIST_INDEX => 5,
      NBITS_DIST_MEM_CTRL => 9,
      NBITS_DLL_CORR => 16,
      NBITS_NB_DLL_STEPS => 8,
      NBITS_OUTPUT_DATA => 32,
      NBITS_AL_COMP => 16,
      ENABLE_INPUT_FIFO => true,
      ENABLE_DELAY_NB => 1200,
      NBITS_GS_RAM => 16,
      NBITS_MAX_GS_RAM_DATA_IN => 16
    )
    PORT MAP (
      clk_CI => clk_CI,
      reset_RBI => reset_RBI,
      reset_or_done_edge_RBO => reset_or_done_edge_RBO,
      dclk_in_SI => dclk_in_SI,
      vsync_in_SI => vsync_in_SI,
      hsync_in_SI => hsync_in_SI,
      xsync_sat_in_SI => xsync_sat_in_SI,
      data_in_DI => data_in_DI,
      rbk_cc_en_SI => rbk_cc_en_SI,
      rbk_cc_rst_SI => rbk_cc_rst_SI,
      rbk_cc_update_reg_values_SI => rbk_cc_update_reg_values_SI,
      rbk_cc_mode_SI => rbk_cc_mode_SI,
      rbk_cc_data_length_SI => rbk_cc_data_length_SI,
      rbk_image_bin_en_SI => rbk_image_bin_en_SI,
      rbk_img_pix_inter_en_SI => rbk_img_pix_inter_en_SI,
      rbk_img_adc_inter_en_SI => rbk_img_adc_inter_en_SI,
      rbk_im_rem_sat_SI => rbk_im_rem_sat_SI,
      rbk_init_table_SI => rbk_init_table_SI,
      rbk_adc_underflow_SI => rbk_adc_underflow_SI,
      rbk_adc_overflow_SI => rbk_adc_overflow_SI,
      rbk_interf_thr_DI => rbk_interf_thr_DI,
      rbk_alu_dist_corr_DI => rbk_alu_dist_corr_DI,
      rbk_alu_amp_corr_DI => rbk_alu_amp_corr_DI,
      rbk_alu_minIndex_DI => rbk_alu_minIndex_DI,
      rbk_add_const_temp_en_SI => rbk_add_const_temp_en_SI,
      rbk_add_const_temp_val_DI => rbk_add_const_temp_val_DI,
      rbk_line_length_DI => rbk_line_length_DI,
      rbk_dist_mean_filter_en_SI => rbk_dist_mean_filter_en_SI,
      rbk_dist_corr_en_SI => rbk_dist_corr_en_SI,
      rbk_dist_corr_dll_DI => rbk_dist_corr_dll_DI,
      rbk_dist_dll_steps_DI => rbk_dist_dll_steps_DI,
      rbk_mult_fact_DI => rbk_mult_fact_DI,
      rbk_add_const_en_SI => rbk_add_const_en_SI,
      rbk_add_const_val_DI => rbk_add_const_val_DI,
      rbk_const_max_val_DI => rbk_const_max_val_DI,
      rbk_ambient_en_SI => rbk_ambient_en_SI,
      rbk_ambient_comp_DI => rbk_ambient_comp_DI,
      rbk_gs_comp_en_SI => rbk_gs_comp_en_SI,
      rbk_gs_subtract_SI => rbk_gs_subtract_SI,
      rbk_dbg_en_SI => rbk_dbg_en_SI,
      rbg_dbg_pxl_count_DI => rbg_dbg_pxl_count_DI,
      rbk_dbg_pxl_index_DI => rbk_dbg_pxl_index_DI,
      cc_reset_regs_RO => cc_reset_regs_RO,
      dist_offset_index_trunc_DO => dist_offset_index_trunc_DO,
      dist_offset_fail_pos_DO => dist_offset_fail_pos_DO,
      dist_offset_index_low_SO => dist_offset_index_low_SO,
      dist_offset_index_high_SO => dist_offset_index_high_SO,
      sg_dma_intr_SI => sg_dma_intr_SI,
      cc_sort_length_DO => cc_sort_length_DO,
      dist_amp_sat_concat_DO => dist_amp_sat_concat_DO,
      dist_amp_sat_pulse_SO => dist_amp_sat_pulse_SO,
      sel_gs_mode_SO => sel_gs_mode_SO,
      tcmi_pixel_cnt_DO => tcmi_pixel_cnt_DO,
      cc_img_bin_dcs_sel_DO => cc_img_bin_dcs_sel_DO,
      readRam_pulse_out_SI => readRam_pulse_out_SI,
      readRam_data_DI => readRam_data_DI,
      readRam_en_SO => readRam_en_SO,
      readRam_pulse_SO => readRam_pulse_SO,
      readRam_index_DO => readRam_index_DO,
      gs_data_DO => gs_data_DO,
      en_d2r_gs_SO => en_d2r_gs_SO,
      length_gs_data_DO => length_gs_data_DO,
      grey_pulse_out_SO => grey_pulse_out_SO,
      grey_pulse_in_SO => grey_pulse_in_SO,
      gs_data_DI => gs_data_DI,
      cc_dcs_length_DO => cc_dcs_length_DO,
      dcs_data_DO => dcs_data_DO,
      en_d2r_dcs_SO => en_d2r_dcs_SO,
      en_d2r_wr_dcs_SO => en_d2r_wr_dcs_SO,
      reg_dcs0_or_dcs1_pulse_SO => reg_dcs0_or_dcs1_pulse_SO,
      dcs2_or_dcs3_pulse_SO => dcs2_or_dcs3_pulse_SO,
      ram_dcs_data_DI => ram_dcs_data_DI,
      DbgBram_Addr => DbgBram_Addr,
      DbgBram_Data => DbgBram_Data,
      DbgBram_Wen => DbgBram_Wen
    );
END design_1_TOF_cos_sl_0_0_arch;
