----------------------------------------------------------------------------------
-- Company: ESPROS		
-- Engineer: msc
-- 
-- Create Date: 10/09/2019 09:58:51 AM
-- Design Name: TOF_cos_sl 
-- Module Name: TOF_cos_sl - Behavioral
--
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

-- Include Subblocks in default lib, because IP update is removing the library information
library xil_defaultlib;
use xil_defaultlib.pkg_edge_detector.all;
use xil_defaultlib.pkg_tcmi.all;
use xil_defaultlib.pkg_camera_control.all;
use xil_defaultlib.pkg_bad_pix_mem_ctrl.all;
use xil_defaultlib.pkg_image_bin.all;
use xil_defaultlib.pkg_DCSsat_detect.all;
use xil_defaultlib.pkg_interf_detect.all;
use xil_defaultlib.pkg_DCS_subtract.all;
use xil_defaultlib.pkg_bram_fifo_ctrl.all;
use xil_defaultlib.pkg_reg_stage.all;
use xil_defaultlib.pkg_alu.all;
use xil_defaultlib.pkg_add_const.all;
use xil_defaultlib.pkg_dist_offset.all;
use xil_defaultlib.pkg_dist_mem_ctrl.all;
use xil_defaultlib.pkg_gs_compensation.all;
use xil_defaultlib.pkg_gs_subtract.all;
use xil_defaultlib.pkg_ambient_light_sup.all;
use xil_defaultlib.pkg_tof_debug_unit.all;

-- Include Xilinx blocks
Library xpm;
use xpm.vcomponents.all;

library UNISIM;
use UNISIM.VComponents.all;

use xil_defaultlib.pkg_xilinx_xci_components.all;

-- Entity
entity TOF_cos_sl is
	Generic (
	    ENABLE_INPUT_FIFO        : boolean  := false;
		ENABLE_DELAY_NB          : positive := 1200;
		NB_OF_PIXEL              : positive := 76800;
		NBITS_DATA_IN            : positive := 12;
		NBITS_LENGTH             : positive := 17;
		NBITS_LINE_LENGTH        : positive := 9;		
		NBITS_ADDR_IMG_BRAM      : positive := 10;	
        NBITS_ADDR_BRAM_DCS      : positive := 10;
        NBITS_DATA_BRAM_DCS      : positive := 16;    
        MEM_SIZE_BRAM_DCS        : positive := 640;
		NBITS_ADDR_FIFO0         : positive := 16;
		NBITS_ADDR_FIFO1         : positive := 14;
		NBITS_DIST_OUT           : positive := 16;
		NBITS_AMP_OUT            : positive := 12;
		NBITS_AL_COMP            : positive := 16;
		NBITS_MININDEX           : positive := 8;
		NBITS_GS_RAM             : positive := 16;
		NBITS_MAX_GS_RAM_DATA_IN : positive := 16;
		NBITS_CAL_RAM            : positive := 128;
		NBITS_DIST_INDEX         : positive := 5;
		NBITS_DIST_MEM_CTRL      : positive := 9;
		NBITS_DLL_CORR           : positive := 16;
		NBITS_NB_DLL_STEPS       : positive := 8;	
		NBITS_OUTPUT_DATA        : positive := 32
	);
	Port (
		-- General inputs / outputs
		clk_CI                 : in  std_logic;
		reset_RBI              : in  std_logic;
		reset_or_done_edge_RBO : out std_logic;
		
		-- TCMI inputs
		dclk_in_SI      : in  std_logic;
		vsync_in_SI     : in  std_logic;
		hsync_in_SI     : in  std_logic;
		xsync_sat_in_SI : in  std_logic;
		data_in_DI      : in  std_logic_vector(NBITS_DATA_IN-1 downto 0);
		
		-- Reg_bank inputs/outputs
		rbk_cc_en_SI                : in  std_logic;
		rbk_cc_rst_SI               : in  std_logic;
		rbk_cc_update_reg_values_SI : in  std_logic;
		rbk_cc_mode_SI              : in  std_logic_vector(2 downto 0);
		rbk_cc_data_length_SI       : in  std_logic_vector(NBITS_LENGTH-1 downto 0);
		rbk_image_bin_en_SI         : in  std_logic;
		rbk_img_pix_inter_en_SI     : in  std_logic;
        rbk_img_adc_inter_en_SI     : in  std_logic;
        rbk_im_rem_sat_SI           : in  std_logic;
	    rbk_init_table_SI           : in  std_logic;
		rbk_adc_underflow_SI        : in  std_logic;
		rbk_adc_overflow_SI         : in  std_logic;
		rbk_interf_thr_DI           : in  std_logic_vector(NBITS_DATA_IN downto 0);
        rbk_alu_dist_corr_DI        : in  std_logic_vector(NBITS_DATA_IN-1 downto 0);
        rbk_alu_amp_corr_DI         : in  std_logic_vector(NBITS_DATA_IN-1 downto 0);
        rbk_alu_minIndex_DI         : in  std_logic_vector(NBITS_MININDEX-1 downto 0);
		rbk_add_const_temp_en_SI    : in  std_logic;
		rbk_add_const_temp_val_DI   : in  std_logic_vector(NBITS_DIST_OUT downto 0);
	    rbk_line_length_DI          : in  std_logic_vector(NBITS_LINE_LENGTH-1 downto 0);
	    rbk_dist_mean_filter_en_SI  : in  std_logic;
	    rbk_dist_corr_en_SI         : in  std_logic;
	    rbk_dist_corr_dll_DI        : in  std_logic_vector(NBITS_DLL_CORR-1 downto 0);
	    rbk_dist_dll_steps_DI       : in  std_logic_vector(NBITS_NB_DLL_STEPS-1 downto 0);
		rbk_mult_fact_DI            : in  std_logic_vector(NBITS_DIST_OUT-1 downto 0);
		rbk_add_const_en_SI         : in  std_logic;
		rbk_add_const_val_DI        : in  std_logic_vector(NBITS_DIST_OUT downto 0);
		rbk_const_max_val_DI        : in  std_logic_vector(NBITS_DIST_OUT-1 downto 0);
		rbk_ambient_en_SI           : in  std_logic;
		rbk_ambient_comp_DI		    : in  std_logic_vector(NBITS_AL_COMP-1 downto 0);
		rbk_gs_comp_en_SI           : in  std_logic;
		rbk_gs_subtract_SI          : in  std_logic;
        
        -- debug unit
        rbk_dbg_en_SI               : in  std_logic;
        rbg_dbg_pxl_count_DI        : in  std_logic_vector(NBITS_LENGTH-1 downto 0);
        rbk_dbg_pxl_index_DI        : in  std_logic_vector(NBITS_LENGTH-1 downto 0);
        
		cc_reset_regs_RO            : out std_logic;
	    dist_offset_index_trunc_DO  : out std_logic_vector(NBITS_NB_DLL_STEPS-1 downto 0);
	    dist_offset_fail_pos_DO     : out std_logic_vector(NBITS_LENGTH-1 downto 0);
	    dist_offset_index_low_SO    : out std_logic;
	    dist_offset_index_high_SO	: out std_logic;
		
		-- SG DMA inputs/outputs
		sg_dma_intr_SI         : in std_logic;
		cc_sort_length_DO      : out std_logic_vector(NBITS_LENGTH+1 downto 0);
		dist_amp_sat_concat_DO : out std_logic_vector(NBITS_OUTPUT_DATA-1 downto 0);
		dist_amp_sat_pulse_SO  : out std_logic;
		
		-- General outputs
		sel_gs_mode_SO : out std_logic;
		tcmi_pixel_cnt_DO : out std_logic_vector(NBITS_LENGTH-1 downto 0);
		cc_img_bin_dcs_sel_DO : out std_logic_vector(2 downto 0);
		
		-- readRam
	    readRam_pulse_out_SI : in  std_logic;
	    readRam_data_DI      : in  std_logic_vector(NBITS_CAL_RAM-1 downto 0);
		readRam_en_SO        : out std_logic;
		readRam_pulse_SO     : out std_logic;		
		readRam_index_DO     : out std_logic_vector(NBITS_DIST_INDEX-1 downto 0);	
		
		-- data2ram_gs
		gs_data_DO          : out std_logic_vector(NBITS_DATA_IN downto 0);
		en_d2r_gs_SO        : out std_logic;
		length_gs_data_DO   : out std_logic_vector(NBITS_LENGTH+1 downto 0);
		grey_pulse_out_SO   : out std_logic;
		grey_pulse_in_SO    : out std_logic;
		gs_data_DI          : in  std_logic_vector(NBITS_DATA_IN downto 0);
		
		-- data2ram_dcs
		cc_dcs_length_DO          : out std_logic_vector(NBITS_LENGTH-1 downto 0);
		dcs_data_DO               : out std_logic_vector(NBITS_MAX_GS_RAM_DATA_IN-1 downto 0);
		en_d2r_dcs_SO             : out std_logic;
		en_d2r_wr_dcs_SO          : out std_logic;
		reg_dcs0_or_dcs1_pulse_SO : out std_logic;
		dcs2_or_dcs3_pulse_SO     : out std_logic;
		ram_dcs_data_DI           : in  std_logic_vector(NBITS_MAX_GS_RAM_DATA_IN-1 downto 0);

        -- debug bram
        DbgBram_Addr        : out std_logic_vector(31 downto 0);
        DbgBram_Data        : out std_logic_vector(31 downto 0);
        DbgBram_Wen         : out std_logic_vector(3 downto 0)
	);
end TOF_cos_sl;

-- Architecture
architecture Behavioral of TOF_cos_sl is

	-- Reset control & edge detection
	signal edge_out_S : std_logic;
	signal reset_or_done_edge_RB : std_logic;

	-- Camera control
	signal cc_tcmi_en_S          : std_logic;
    signal cc_img_bin_dcs_sel_D  : std_logic_vector(2 downto 0);
    signal cc_img_bin_last_dcs_D : std_logic_vector(2 downto 0);
    signal cc_img_bin_dual_en_S  : std_logic;
    signal cc_dcs_length_D       : std_logic_vector(NBITS_LENGTH-1 downto 0);
    signal cc_sort_length_D      : std_logic_vector(NBITS_LENGTH-1 downto 0);
    signal cc_alu_en_S           : std_logic;
	
	-- TCMI
	signal tcmi_active_S    : std_logic;
	signal tcmi_pixel_cnt_D : unsigned(NBITS_LENGTH-1 downto 0);
	signal tcmi_last_out_S  : std_logic;
	signal tcmi_vsync_S     : std_logic;
	signal tcmi_hsync_S     : std_logic;
	signal tcmi_pulse_out_S : std_logic;
	signal tcmi_dout_D      : std_logic_vector(NBITS_DATA_IN downto 0);
	
	-- bad pixel_cnt
	signal bad_pixel_S                : std_logic;
	signal bad_pix_ram_rd_pulse_S     : std_logic;
	signal bad_pix_ram_addr_D         : std_logic_vector(NBITS_LENGTH-1 downto 0);
	signal bad_pix_ram_data_D         : std_logic;
	signal bad_pix_ram_wr_en_S        : std_logic;
	signal bad_pix_readRam_reset_RB   : std_logic;
	signal bad_pix_init_not_ongoing_S : std_logic;
	
	-- bram_bad_pix_mem_ctrl
	signal bram_bad_pix_data_D : std_logic_vector(0 downto 0);
	
	-- Image bin
	signal img_bin_done_S        : std_logic;
	signal img_mask_first_S      : std_logic;
	signal img_bram_data_in_D    : std_logic_vector(NBITS_DATA_IN+3 downto 0);
	signal img_data_out_D        : std_logic_vector(NBITS_DATA_IN downto 0);
	signal img_bram_data_out_D   : std_logic_vector(NBITS_DATA_IN+4-1 downto 0);
	signal img_bram_wr_en_S      : std_logic;
	signal img_bram_addr_D       : std_logic_vector(NBITS_ADDR_IMG_BRAM-1 downto 0);
	signal img_bram_rd_en_S      : std_logic;
	signal img_diff_bram_rd_en_S : std_logic;
	signal img_bram_rd_addr_D    : std_logic_vector(NBITS_ADDR_IMG_BRAM-1 downto 0);
	signal img_grey_pulse_S      : std_logic;
    signal img_dcs0_pulse_S      : std_logic;
    signal img_dcs1_pulse_S      : std_logic;
    signal img_dcs2_pulse_S      : std_logic;
    signal img_dcs3_pulse_S      : std_logic;
    signal img_last_out_S        : std_logic;
    signal img_bad_pixel_S       : std_logic;
    signal img_ambient_en_S      : std_logic;
    
    signal reg_cc_img_bin_dcs_sel_D : std_logic;
    
    
    signal img_dcs0_pulse_reg2  : std_logic;
    signal img_dcs1_pulse_reg2  : std_logic;
    
	
	-- DCSsat
	signal DCSsat_S : std_logic;

	-- Interference detection
	signal interf_flag_S : std_logic;
	
	-- GS compensation
    signal ram_gs_pulse_S : std_logic;
	signal gs_comp_out_D  : std_logic_vector(NBITS_DATA_IN downto 0);
    signal gs_comp_pulse_S  : std_logic;
	signal gs_comp_ram_pulse_req_S : std_logic;
	
	-- DCS subtract
    signal DCSsub_sign_D : std_logic;
    signal DCSsub_data_D : std_logic_vector(NBITS_DATA_IN-1 downto 0);
    signal DCSsub_sat_S  : std_logic;
	
	signal reg_DCSsat_S         : std_logic;
	signal reg_dcssat_corr_S    : std_logic;
	signal dcs_or_ambient_sat_S : std_logic;	
	signal reg_img_dcs2_pulse_S : std_logic;
	
	-- bram fifo
	signal bram_diff_data_in_D    : std_logic_vector(NBITS_DATA_IN+4-1 downto 0);
	signal bram_fifo_wr_en_f0_S   : std_logic;
	signal bram_fifo_wr_data_f0_D : std_logic_vector(NBITS_DATA_IN+4-1 downto 0);
	signal bram_fifo_wr_en_f1_S   : std_logic;
	signal bram_fifo_wr_data_f1_D : std_logic_vector(NBITS_DATA_IN+4-1 downto 0);
	signal bram_fifo_rd_data_D    : std_logic_vector(NBITS_DATA_IN+4-1 downto 0);
	signal bram_fifo_f0_pulse_S   : std_logic;
	signal bram_fifo_f1_pulse_S   : std_logic;
	signal bram_fifo_f0_addr_D	  : std_logic_vector(NBITS_ADDR_FIFO0-1 downto 0);
    signal bram_fifo_f1_addr_D    : std_logic_vector(NBITS_ADDR_FIFO1-1 downto 0);
		
	-- fifo
	signal fifo0_data_D : std_logic_vector(NBITS_DATA_IN+4-1 downto 0);
	signal fifo1_data_D : std_logic_vector(NBITS_DATA_IN+4-1 downto 0);
	
    signal dcs3_pulse_or_last_S      : std_logic;	
	signal reg_dcs3_pulse_or_last_S  : std_logic;
	signal alu_div_pulse_S           : std_logic;
	signal reg_alu_div_pulse_S       : std_logic;
	signal reg_alu_out_pulse_S       : std_logic;
	signal interf_flag_or_S          : std_logic;
	signal dcs_ambient_or_diff_sat_S : std_logic;
	
	-- alu
	signal alu_div_out_D     : std_logic_vector(39 downto 0);
	signal alu_dist_D        : std_logic_vector(NBITS_DIST_OUT-1 downto 0);
	signal alu_sat_S         : std_logic;
	signal alu_amp_D         : std_logic_vector(NBITS_AMP_OUT-1 downto 0);
	signal alu_minIndex_S    : std_logic;
	signal alu_interf_flag_S : std_logic;
	signal alu_dcssat_S      : std_logic;
	signal alu_chipsat_S     : std_logic;
	signal alu_delayed_D     : std_logic_vector(38 downto 0);
	signal reg_alu_delayed_D : std_logic_vector(38 downto 0);
	signal alu_pulse_div_S   : std_logic;
	signal alu_div_top_D     : std_logic_vector(2*NBITS_DATA_IN-1 downto 0);
	signal alu_div_bot_D     : std_logic_vector(NBITS_DATA_IN-1 downto 0);
	signal alu_div_bot_ext_D : std_logic_vector(NBITS_DATA_IN+4-1 downto 0);
	
	signal amp_sat_concat_D : std_logic_vector(NBITS_AMP_OUT+4-1 downto 0);
	signal reg_nodist_amp_sat_concat_D : std_logic_vector(NBITS_AMP_OUT+4-1 downto 0);
	signal reg_dist_amp_sat_concat_D : std_logic_vector(NBITS_AMP_OUT+4-1 downto 0);
	signal reg_dist_amp_sat_fifo_D : std_logic_vector(NBITS_AMP_OUT+4-1 downto 0);
	signal dist_mem_in_D : std_logic_vector(NBITS_AMP_OUT+4+NBITS_DIST_OUT+2-1 downto 0);
	
	signal reg_img_bad_pixel_S : std_logic;
    
	-- Add const temp
	signal add_const_temp_sat_S  : std_logic;
	signal add_const_temp_data_D : std_logic_vector(NBITS_DIST_OUT-1 downto 0);
	
	signal reg_alu_dist_corr_pulse_S : std_logic;
	
	-- dist mem ctrl
	signal dist_ram_in_pulse_S   : std_logic;
    signal dist_mem_read_addr_D  : std_logic_vector(NBITS_DIST_MEM_CTRL-1 downto 0);
    signal dist_mem_read_en_S    : std_logic;
    signal dist_mem_write_addr_D : std_logic_vector(NBITS_DIST_MEM_CTRL-1 downto 0);
    signal dist_mem_write_en_S	 : std_logic;
	signal dist_mem_data_D       : std_logic_vector(34-1 downto 0);
	
	-- dist offset correction
    signal dist_offset_data_D           : std_logic_vector(NBITS_DIST_OUT-1 downto 0);
	signal dist_offset_sat_S            : std_logic;
	signal dist_offset_pix_sat_S        : std_logic;
	signal dist_offset_pulse_S          : std_logic;
	signal reg_dist_offset_pulse_S      : std_logic;
    signal dist_offset_ram_read_pulse_S : std_logic;
    signal dist_offset_dividend_D       : std_logic_vector(32-1 downto 0);
    signal dist_offset_divisor_D        : std_logic_vector(16-1 downto 0);
    signal dist_offset_div_pulse_S      : std_logic;
	signal dist_div_out_D               : std_logic_vector(48-1 downto 0);
	signal dist_div_out_valid_S         : std_logic;
	signal reg_dist_div_delay_D         : std_logic_vector(25-1 downto 0);
	signal dist_div_delay_D             : std_logic_vector(25-1 downto 0);
	
	-- Multiplier
    signal mult_dist_data_D : std_logic_vector(NBITS_DIST_OUT-1 downto 0);
	
	-- Add constant
    signal add_const_data_D    : std_logic_vector(NBITS_DIST_OUT-1 downto 0); 
    signal add_const_sat_S     : std_logic;
	signal reg_add_const_sat_S : std_logic;
	
     -- Ambient light compensation
    signal ambient_corr_data_D : std_logic_vector(NBITS_DATA_IN downto 0);
	
	-- output control
	signal mux_amp_sat_D             : std_logic_vector(NBITS_AMP_OUT+4-1 downto 0);
	signal reg_mux_amp_sat_D         : std_logic_vector(NBITS_AMP_OUT+4-1 downto 0);
	signal dcs0_or_dcs1_pulse_S      : std_logic;
	signal reg_dist_offset_pix_sat_S : std_logic;
	signal reg_dcs0_or_dcs1_pulse_S  : std_logic;     
    
begin

	-- reset control & edge detection
	i_edge_detector : ip_edge_detector
    port map (
		clk_CI => clk_CI,
	    en_DI  => reset_RBI,
        in_DI  => sg_dma_intr_SI,
        out_DO => edge_out_S		
	);		
	reset_or_done_edge_RB  <= reset_RBI and edge_out_S;
	reset_or_done_edge_RBO <= reset_or_done_edge_RB;

	-- Camera control
	i_camera_control : ip_camera_control
	generic map (
	    NBITS_LENGTH => NBITS_LENGTH
	)
	port map(
		clk => clk_CI,
		resetn => reset_or_done_edge_RB,
		cc_en_DI => rbk_cc_en_SI,
		cc_rst_RI => rbk_cc_rst_SI,
		cc_update_reg_values_SI => rbk_cc_update_reg_values_SI,
		cc_mode_SI => rbk_cc_mode_SI,
		cc_data_length_DI => rbk_cc_data_length_SI,
		reset_cc_regs_RO => cc_reset_regs_RO,
		image_bin_en_SI => rbk_image_bin_en_SI,
		tcmi_active => tcmi_active_S,
		image_bin_done_SI => img_bin_done_S,
		pixel_cnt => tcmi_pixel_cnt_D,
        tcmi_en => cc_tcmi_en_S,
        tcmi_dcs_sel => cc_img_bin_dcs_sel_D,
        tcmi_last_dcs => cc_img_bin_last_dcs_D,
        img_dual_en => cc_img_bin_dual_en_S,
        grey_length => length_gs_data_DO,
        dcs_length => cc_dcs_length_D,
        sort_length => cc_sort_length_D,
        alu_en => cc_alu_en_S
	);

    sel_gs_mode_SO <= cc_img_bin_dcs_sel_D(2);
	cc_sort_length_DO <= "00" & cc_sort_length_D;
	cc_dcs_length_DO  <= cc_dcs_length_D;
	cc_img_bin_dcs_sel_DO <= cc_img_bin_dcs_sel_D;

	-- TCMI
	i_tcmi : ip_tcmi
	generic map (
	    ENABLE_INPUT_FIFO => ENABLE_INPUT_FIFO,
		ENABLE_DELAY_NB => ENABLE_DELAY_NB,
		NBITS_DATA_IN => NBITS_DATA_IN,
	    NBITS_LENGTH => NBITS_LENGTH
	)
    port map (
		clk          => clk_CI,
		en           => cc_tcmi_en_S,
		length       => cc_dcs_length_D,
		dclk_in      => dclk_in_SI,
		vsync_in     => vsync_in_SI,
		hsync_in     => hsync_in_SI,
		xsync_sat_in => xsync_sat_in_SI,
		data_in      => data_in_DI,
		active       => tcmi_active_S,
		pixel_cnt    => tcmi_pixel_cnt_D,
		last_out     => tcmi_last_out_S,
		vsync_SO     => tcmi_vsync_S,
		hsync_SO     => tcmi_hsync_S,
		pulse_out    => tcmi_pulse_out_S,
		dout         => tcmi_dout_D
	);	
	
	tcmi_pixel_cnt_DO <= std_logic_vector(tcmi_pixel_cnt_D);
	
	-- bad_pix_mem_ctrl
	i_bad_pix_mem_ctrl : ip_bad_pix_mem_ctrl
	generic map (
		NBITS => NBITS_LENGTH
	)
    port map (
	   clk_CI                  => clk_CI,
	   reset_RBI               => reset_or_done_edge_RB,
	   init_table_SI           => rbk_init_table_SI,
	   init_run_SI             => tcmi_active_S,
	   pix_nb_DI               => std_logic_vector(tcmi_pixel_cnt_D),
	   reg_pix_nb_DI           => rbk_cc_data_length_SI,
	   pulse_in_DI             => tcmi_pulse_out_S,
	   ram_pulse_in_DI         => readRam_pulse_out_SI,
	   ram_data_in_DI          => unsigned(readRam_data_DI(NBITS_CAL_RAM/8-1 downto 0)),
	   bad_pix_ram_rd_pulse_DO => bad_pix_ram_rd_pulse_S,
	   bad_pix_addr_DO         => bad_pix_ram_addr_D,
	   bad_pix_data_DO         => bad_pix_ram_data_D,
	   bad_pix_wr_en_DO        => bad_pix_ram_wr_en_S,
	   bad_pix_data_DI         => bram_bad_pix_data_D(0),
	   readRam_reset_RBO       => bad_pix_readRam_reset_RB,
	   init_not_ongoing_DO     => bad_pix_init_not_ongoing_S,
       bad_pix_sat_DO          => bad_pixel_S
	);		
	
	-- bram_bad_pix (Xilinx primitive)
    i_bram_bad_pix : xpm_memory_spram
    generic map (
       ADDR_WIDTH_A => NBITS_LENGTH,
       BYTE_WRITE_WIDTH_A => 1,
       MEMORY_OPTIMIZATION => "true",
       MEMORY_SIZE => NB_OF_PIXEL,
       READ_DATA_WIDTH_A => 1,
       READ_LATENCY_A => 1,
       USE_MEM_INIT => 0,
       WRITE_DATA_WIDTH_A => 1,
	   MEMORY_PRIMITIVE => "block",	  
       WRITE_MODE_A => "write_first"
    )
    port map (
       douta  => bram_bad_pix_data_D,
       addra  => bad_pix_ram_addr_D, 
       clka   => clk_CI, 
       dina(0)=> bad_pix_ram_data_D,
       ena    => reset_or_done_edge_RB,
       wea(0) => bad_pix_ram_wr_en_S,
       -- unused ports
       injectdbiterra => '0',
       injectsbiterra => '0',
       regcea         => '1',
       rsta           => '0',
       sleep          => '0'
    );	
	
	-- Image_bin
	i_image_bin : ip_image_bin
	generic map (
		NBITS_DATA => NBITS_DATA_IN+1,
        NBITS_ADDR => NBITS_ADDR_IMG_BRAM		
	)
    port map (
		clk_CI               => clk_CI,
		en_DI                => rbk_image_bin_en_SI,
		reset_RBI            => cc_tcmi_en_S,
		pulse_DI             => tcmi_pulse_out_S,
        data_in_DI           => tcmi_dout_D,
        bad_pixel_DI         => bad_pixel_S,
		bram_data_in_DI      => img_bram_data_in_D,
		reg_line_length_DI   => rbk_line_length_DI,
		reg_pix_inter_en_SI  => rbk_img_pix_inter_en_SI,
		reg_adc_en_SI        => rbk_img_adc_inter_en_SI,
		reg_remove_sat_en_SI => rbk_im_rem_sat_SI,
		hsync_DI             => tcmi_hsync_S,
		vsync_DI             => tcmi_vsync_S,
		last_pulse_DI        => tcmi_last_out_S,
		dcs_SI               => cc_img_bin_dcs_sel_D,
        dcs_last_SI          => cc_img_bin_last_dcs_D,
        dual_mgx_en_SI       => cc_img_bin_dual_en_S,
		mask_first_SO        => img_mask_first_S,
		data_out_DO          => img_data_out_D,
		bram_data_out_DO     => img_bram_data_out_D,
		bram_wr_en_DO        => img_bram_wr_en_S,
		bram_wr_addr_DO      => img_bram_addr_D,
		bram_rd_en_DO        => img_bram_rd_en_S,
		bram_rd_addr_DO      => img_bram_rd_addr_D,
		grey_out_DO          => img_grey_pulse_S,
        dcs0_out_DO          => img_dcs0_pulse_S,
        dcs1_out_DO          => img_dcs1_pulse_S,
        dcs2_out_DO          => img_dcs2_pulse_S,
        dcs3_out_DO          => img_dcs3_pulse_S,
        last_out_DO          => img_last_out_S,
        bad_pixel_DO         => img_bad_pixel_S,
		image_bin_done_DO    => img_bin_done_S,
		diff_bram_rd_en_SO   => img_diff_bram_rd_en_S,
        ambient_en_SO        => img_ambient_en_S
	);		
	
	-- bram_image_bin (Xilinx primitive)
    i_bram_image_bin : xpm_memory_sdpram
    generic map (
       ADDR_WIDTH_A => NBITS_ADDR_BRAM_DCS,
       ADDR_WIDTH_B => NBITS_ADDR_BRAM_DCS, 
       BYTE_WRITE_WIDTH_A => NBITS_DATA_BRAM_DCS,     
       MEMORY_SIZE => MEM_SIZE_BRAM_DCS*NBITS_DATA_BRAM_DCS,        
       READ_DATA_WIDTH_B => NBITS_DATA_BRAM_DCS,     
       WRITE_DATA_WIDTH_A => NBITS_DATA_BRAM_DCS,   
	   READ_LATENCY_B => 1,	   
	   MEMORY_PRIMITIVE => "block",	   
       WRITE_MODE_B => "read_first"
    )
    port map (
       addra => img_bram_addr_D,
       clka  => clk_CI,
       dina  => img_bram_data_out_D,
       ena   => img_bram_wr_en_S,
       wea(0)=> img_bram_wr_en_S,
	   addrb => img_bram_rd_addr_D,
	   clkb  => clk_CI,
	   doutb => img_bram_data_in_D,
	   enb   => img_bram_rd_en_S,
	   -- unused ports
	   sleep          => '0',
	   rstb           => '0',
	   injectsbiterra => '0',
	   injectdbiterra => '0',
	   regceb         => '1'
    );	
	
	-- DCSSat detection (ADC saturation)
	i_DCSsat_detect : ip_DCSsat_detect
	generic map (
		NBITS_DATA => NBITS_DATA_IN
	)
    port map (
        DCSin_DI           => img_data_out_D,
        DCSsat_DO          => DCSsat_S,
        ADCunderflow_en_SI => rbk_adc_underflow_SI,
        ADCoverflow_en_SI  => rbk_adc_overflow_SI	
	);		
	
	-- Interference detection
	i_interf_detect : ip_interf_detect
	generic map (
		NBITS_DATA => NBITS_DATA_IN
	)
    port map (
		clk_CI            => clk_CI,
        resetn_RB         => cc_tcmi_en_S,
        reg_interf_thr_DI => rbk_interf_thr_DI,
        data_in0_DI       => img_data_out_D,
        data_in1_DI       => ram_dcs_data_DI(NBITS_DATA_IN downto 0),
        interf_flag_DO    => interf_flag_S
	);		

	-- DCS Subtract
	i_DCS_subtract : ip_DCS_subtract
	generic map (
		NBITS_DATA_IN => NBITS_DATA_IN
	)
    port map (
		DCSin_DI     => img_data_out_D,
        DCSin_sub_DI => ram_dcs_data_DI(NBITS_DATA_IN downto 0),
        clk_CI       => clk_CI,
        en_DI        => cc_tcmi_en_S,
        sign_DO      => DCSsub_sign_D,
        udiff_DO     => DCSsub_data_D,
        sat_DO       => DCSsub_sat_S
	);		
	
	-- Reg stage for img_dcs2_pulse_S
	i_reg_stage_dcs2_pulse : ip_reg_stage
	generic map (
        NB_STAGES => 3
	)
    port map (
        en_DI      => cc_tcmi_en_S,
        clk_CI     => clk_CI,
        data_DI(0) => img_dcs2_pulse_S,
        data_DO(0) => reg_img_dcs2_pulse_S
	);		

	-- Reg stage for DCSsat_S
	i_reg_stage_dcssat : ip_reg_stage
    port map (
        en_DI      => cc_tcmi_en_S,
        clk_CI     => clk_CI,
        data_DI(0) => DCSsat_S,
        data_DO(0) => reg_DCSsat_S
	);		
	
	dcs_or_ambient_sat_S <= ram_dcs_data_DI(NBITS_DATA_IN+1) or reg_DCSsat_S; 
	bram_diff_data_in_D  <= interf_flag_S & dcs_or_ambient_sat_S & DCSsub_sign_D & DCSsub_sat_S & DCSsub_data_D;
	
	-- BRAM fifo ctrl
	i_bram_fifo_ctrl : ip_bram_fifo_ctrl
	generic map (
		NBITS_DATA => NBITS_DATA_IN+4 -- +4 : for saturation bits
	)
    port map (
	    clk_CI         => clk_CI,
	    resetn_RBI     => cc_tcmi_en_S,
	    rden_SI        => img_diff_bram_rd_en_S,
		wr_pulse_in_DI => reg_img_dcs2_pulse_S,
		wr_data_in_DI  => bram_diff_data_in_D,
		wr_en_f0_DO    => bram_fifo_wr_en_f0_S,
		wr_data_f0_DO  => bram_fifo_wr_data_f0_D,
		wr_en_f1_DO    => bram_fifo_wr_en_f1_S,
		wr_data_f1_DO  => bram_fifo_wr_data_f1_D,
		rd_pulse_in_DI => img_dcs3_pulse_S,
		rd_data_out_DO => bram_fifo_rd_data_D,
		rd_data_f0_DI  => fifo0_data_D,
		rd_data_f1_DI  => fifo1_data_D,
		f0_pulse_DO    => bram_fifo_f0_pulse_S,
	    f1_pulse_DO    => bram_fifo_f1_pulse_S,
	    f0_addr_DO     => bram_fifo_f0_addr_D,	
        f1_addr_DO     => bram_fifo_f1_addr_D	
	);		
		
	-- Fifo0 & Fifo1
    i_fifo0 : xpm_memory_spram
    generic map (
       ADDR_WIDTH_A => NBITS_ADDR_FIFO0,
       BYTE_WRITE_WIDTH_A => NBITS_DATA_IN+4,
       MEMORY_OPTIMIZATION => "true",
       MEMORY_SIZE => (2**NBITS_ADDR_FIFO0)*(NBITS_DATA_IN+4),
       READ_DATA_WIDTH_A => NBITS_DATA_IN+4,
       READ_LATENCY_A => 1,
       USE_MEM_INIT => 0,
       WRITE_DATA_WIDTH_A => NBITS_DATA_IN+4,
	   MEMORY_PRIMITIVE => "block",	  
       WRITE_MODE_A => "no_change"
    )
    port map (
       douta => fifo0_data_D,
       addra => bram_fifo_f0_addr_D, 
       clka  => clk_CI, 
       dina  => bram_fifo_wr_data_f0_D,
       ena   => bram_fifo_f0_pulse_S,
       wea(0)=> bram_fifo_wr_en_f0_S,
       -- unused signals
       injectdbiterra => '0',
       injectsbiterra => '0',
       regcea         => '1',
       rsta           => '0',
       sleep          => '0'      
    );	
	
    i_fifo1 : xpm_memory_spram
    generic map (
       ADDR_WIDTH_A => NBITS_ADDR_FIFO1,
       BYTE_WRITE_WIDTH_A => NBITS_DATA_IN+4,
       MEMORY_OPTIMIZATION => "true",
       MEMORY_SIZE => (2**NBITS_ADDR_FIFO1)*(NBITS_DATA_IN+4),
       READ_DATA_WIDTH_A => NBITS_DATA_IN+4,
       READ_LATENCY_A => 1,
       USE_MEM_INIT => 0,
       WRITE_DATA_WIDTH_A => NBITS_DATA_IN+4,
	   MEMORY_PRIMITIVE => "block",	  
       WRITE_MODE_A => "no_change"
    )
    port map (
       douta => fifo1_data_D,
       addra => bram_fifo_f1_addr_D, 
       clka  => clk_CI, 
       dina  => bram_fifo_wr_data_f1_D,
       ena   => bram_fifo_f1_pulse_S,
       wea(0)=> bram_fifo_wr_en_f1_S,
       -- unused signals
       injectdbiterra => '0',
       injectsbiterra => '0',
       regcea         => '1',
       rsta           => '0',
       sleep          => '0'   
    );	
	
	-- ALU input preparation
	dcs3_pulse_or_last_S <= img_dcs3_pulse_S or img_last_out_S;
	
	i_reg_stage_dcs3_pulse : ip_reg_stage
	generic map (
        NB_STAGES => 2
	)
    port map (
        en_DI      => cc_tcmi_en_S,
        clk_CI     => clk_CI,
        data_DI(0) => dcs3_pulse_or_last_S,
        data_DO(0) => reg_dcs3_pulse_or_last_S
	);		
	
	alu_div_pulse_S <= reg_dcs3_pulse_or_last_S and not img_mask_first_S;
	
	i_reg_stage_div_pulse : ip_reg_stage
	generic map (
        NB_STAGES => 32
	)
    port map (
        en_DI      => cc_tcmi_en_S,
        clk_CI     => clk_CI,
        data_DI(0) => alu_div_pulse_S,
        data_DO(0) => reg_alu_div_pulse_S
	);		

	i_reg_stage_out_pulse : ip_reg_stage
	generic map (
        NB_STAGES => 4
	)
    port map (
        en_DI      => cc_tcmi_en_S,
        clk_CI     => clk_CI,
        data_DI(0) => reg_alu_div_pulse_S,
        data_DO(0) => reg_alu_out_pulse_S
	);		
	
	interf_flag_or_S <= interf_flag_S or bram_fifo_rd_data_D(NBITS_DATA_IN+3);
	
	dcs_ambient_or_diff_sat_S <= dcs_or_ambient_sat_S or bram_fifo_rd_data_D(NBITS_DATA_IN+2);
	
	i_reg_stage_alu_delayed : ip_reg_stage
	generic map (
		BIT_WIDTH  => 39,
        NB_STAGES  => 26
	)
    port map (
        en_DI   => cc_tcmi_en_S,
        clk_CI  => clk_CI,
        data_DI => alu_delayed_D,
        data_DO => reg_alu_delayed_D
	);		
	
	alu_div_bot_ext_D <= "0000" & alu_div_bot_D;
	
	-- ALU divider (Xilinx primitive)
    i_alu_div : div_gen_alu
    port map (
        aclk                   => clk_CI,
        s_axis_divisor_tvalid  => alu_pulse_div_S,
        s_axis_divisor_tdata   => alu_div_bot_ext_D,
        s_axis_dividend_tvalid => alu_pulse_div_S,
        s_axis_dividend_tdata  => alu_div_top_D,
        m_axis_dout_tdata      => alu_div_out_D
      );
	
	-- ALU
	i_alu : ip_alu
	generic map (
		NBITS_DATA_IN  => NBITS_DATA_IN,
		NBITS_DIST_OUT => NBITS_DIST_OUT,
		NBITS_AMP_OUT  => NBITS_AMP_OUT,
		NBITS_MININDEX => NBITS_MININDEX
	)
    port map (
		clk_CI         => clk_CI,
		en_DI          => cc_alu_en_S,
		pulse_DI       => reg_dcs3_pulse_or_last_S,
		pulse_div_DI   => reg_alu_div_pulse_S,
		pulse_out_DI   => reg_alu_out_pulse_S,
        udiff0_DI      => bram_fifo_rd_data_D(NBITS_DATA_IN-1 downto 0),
        sat0_DI        => bram_fifo_rd_data_D(NBITS_DATA_IN),
        sign0_DI       => bram_fifo_rd_data_D(NBITS_DATA_IN+1),
        udiff1_DI      => DCSsub_data_D,
        sat1_DI        => DCSsub_sat_S,
        sign1_DI       => DCSsub_sign_D,
        interf_flag_DI => interf_flag_or_S,
        dcs_sat_DI     => dcs_ambient_or_diff_sat_S,
        pulse_div_DO   => alu_pulse_div_S,
        alu_delayed_DO => alu_delayed_D,
        alu_div_top_DO => alu_div_top_D,
        alu_div_bot_DO => alu_div_bot_D,
        alu_delayed_DI => reg_alu_delayed_D,
        alu_div_res_DI => alu_div_out_D(39 downto 16),
        corr_d_DI      => unsigned(rbk_alu_dist_corr_DI),
        corr_a_DI      => unsigned(rbk_alu_amp_corr_DI),
        minIndex_DI    => rbk_alu_minIndex_DI,
		dist_DO        => alu_dist_D,
		alu_sat_DO     => alu_sat_S,
		amp_DO         => alu_amp_D,
		minIndex_DO    => alu_minIndex_S,
		interf_flag_DO => alu_interf_flag_S,
		dcssat_DO      => alu_dcssat_S,
		chipsat_DO     => alu_chipsat_S
	);		
	
	amp_sat_concat_D <= alu_interf_flag_S & alu_chipsat_S & alu_dcssat_S & alu_minIndex_S & alu_amp_D;

	i_reg_stage_alu_amp_nodist_corr : ip_reg_stage
	generic map (
		BIT_WIDTH => NBITS_AMP_OUT+4,
        NB_STAGES => 13
	)
    port map (
        en_DI   => cc_tcmi_en_S,
        clk_CI  => clk_CI,
        data_DI => amp_sat_concat_D,
        data_DO => reg_nodist_amp_sat_concat_D
	);		
	
	i_reg_stage_alu_amp_dist_corr : ip_reg_stage
	generic map (
		BIT_WIDTH => NBITS_AMP_OUT+4,
        NB_STAGES => 9
	)
    port map (
        en_DI   => cc_tcmi_en_S,
        clk_CI  => clk_CI,
        data_DI => amp_sat_concat_D,
        data_DO => reg_dist_amp_sat_concat_D
	);	
		
	i_reg_stage_fifo_amp_dist_corr : ip_reg_stage
	generic map (
		BIT_WIDTH => NBITS_AMP_OUT+4,
        NB_STAGES => 39
	)
    port map (
        en_DI   => cc_tcmi_en_S,
        clk_CI  => clk_CI,
        data_DI => dist_mem_data_D(33 downto 18),
        data_DO => reg_dist_amp_sat_fifo_D
	);		
	
	mux_amp_sat_D <= reg_dist_amp_sat_fifo_D when (rbk_dist_corr_en_SI = '1') else reg_nodist_amp_sat_concat_D;
		
	i_reg_stage_bad_pix : ip_reg_stage
	generic map (
        NB_STAGES => 39
	)
    port map (
        en_DI      => cc_tcmi_en_S,
        clk_CI     => clk_CI,
        data_DI(0) => img_bad_pixel_S,
        data_DO(0) => reg_img_bad_pixel_S
	);	
	
	-- Add constant temperature
	i_add_const_temp : ip_add_const
    port map (
		clk_CI       => clk_CI,
		en_DI        => cc_tcmi_en_S,
        datain_DI    => alu_dist_D,
        dataout_DO   => add_const_temp_data_D,
        satin_DI     => alu_sat_S,
        satout_DO    => add_const_temp_sat_S,
		const_en_SI  => rbk_add_const_temp_en_SI,
		const_val_DI => rbk_add_const_temp_val_DI,
		max_val_DI   => std_logic_vector(to_unsigned(51471,16)) -- 2*PI 
	);	
	
	-- Dist FIFO
	dist_mem_in_D <= reg_dist_amp_sat_concat_D & reg_img_bad_pixel_S & add_const_temp_sat_S & add_const_temp_data_D;
	
	i_dist_mem_ctrl : ip_dist_mem_ctrl
	generic map (
		NBITS_ADDR => NBITS_DIST_MEM_CTRL
	)
    port map (
        clk_CI             => clk_CI,
        enable_SI          => cc_tcmi_en_S,
        data_pulse_DI      => reg_alu_dist_corr_pulse_S,
		read_pulse_DI      => dist_ram_in_pulse_S,
        read_bram_addr_DO  => dist_mem_read_addr_D,
        read_bram_en_DO    => dist_mem_read_en_S,
        write_bram_addr_DO => dist_mem_write_addr_D,
        write_bram_en_DO   => dist_mem_write_en_S
	);	

	-- dist mem bram (Xilinx primitive)
    i_bram_dist_mem : xpm_memory_sdpram
    generic map (
       ADDR_WIDTH_A => NBITS_DIST_MEM_CTRL,
       ADDR_WIDTH_B => NBITS_DIST_MEM_CTRL, 
       BYTE_WRITE_WIDTH_A => 34,     
       MEMORY_SIZE => 512*34,        
       READ_DATA_WIDTH_B => 34,     
       WRITE_DATA_WIDTH_A => 34,
       READ_LATENCY_B => 1,	   
	   MEMORY_PRIMITIVE => "block",	  	   
       WRITE_MODE_B => "read_first"
    )
    port map (
       addra => dist_mem_write_addr_D,
       clka  => clk_CI,
       dina  => dist_mem_in_D,
       ena   => dist_mem_write_en_S,
       wea(0)=> dist_mem_write_en_S,
	   addrb => dist_mem_read_addr_D,
	   clkb  => clk_CI,
	   doutb => dist_mem_data_D,
	   enb   => dist_mem_read_en_S,
       -- unused signals
	   sleep          => '0',
       rstb           => '0',
       injectsbiterra => '0',
       injectdbiterra => '0',
       regceb         => '1'
    );		
	
	i_reg_stage_alu_dist_corr : ip_reg_stage
	generic map (
        NB_STAGES => 3
	)
    port map (
        en_DI      => cc_tcmi_en_S,
        clk_CI     => clk_CI,
        data_DI(0) => reg_alu_out_pulse_S,
        data_DO(0) => reg_alu_dist_corr_pulse_S
	);			
	
	i_reg_stage_dist_div_delay : ip_reg_stage
	generic map (
		BIT_WIDTH => 25,
        NB_STAGES => 34
	)
    port map (
        en_DI   => cc_tcmi_en_S,
        clk_CI  => clk_CI,
        data_DI => dist_div_delay_D,
        data_DO => reg_dist_div_delay_D
	);			
		
	dist_ram_in_pulse_S <= bad_pix_init_not_ongoing_S and readRam_pulse_out_SI;
	
	-- Dist offset correction
	i_dist_offset_correction : ip_dist_offset
	generic map (
		NBITS_DIST      => NBITS_DIST_OUT,
		NBITS_DATA      => NBITS_CAL_RAM,
		NBITS_INDEX     => NBITS_DIST_INDEX
	)
    port map (
		clk_CI                 => clk_CI,
		en_DI                  => cc_tcmi_en_S,
		pulse_in_DI            => reg_alu_dist_corr_pulse_S,
        dist_DI                => add_const_temp_data_D,
		dist_sat_DI            => add_const_temp_sat_S,
        dist_pix_sat_DI        => reg_img_bad_pixel_S,
        dist_DO                => dist_offset_data_D,
		dist_sat_DO            => dist_offset_sat_S,
		dist_pix_sat_DO        => dist_offset_pix_sat_S,
		pulse_out_DO           => dist_offset_pulse_S,
		dist_fifo_DI           => dist_mem_data_D(NBITS_DIST_OUT+1 downto 0),
		ram_read_pulse_DI      => dist_ram_in_pulse_S,
        ram_data_DI            => readRam_data_DI,
        ram_read_pulse_DO      => dist_offset_ram_read_pulse_S,
        ram_index_DO           => readRam_index_DO,
        dividend_DO            => dist_offset_dividend_D,
        divisor_DO             => dist_offset_divisor_D,
        div_pulse_DO           => dist_offset_div_pulse_S,
		div_res_DI             => dist_div_out_D(31 downto 16),
		div_pulse_DI           => dist_div_out_valid_S,
		dist_delay_DI          => reg_dist_div_delay_D,
		dist_delay_DO          => dist_div_delay_D,
		dist_pix_nb_DI         => rbk_cc_data_length_SI,
		dist_line_nb_DI        => rbk_line_length_DI,
		dist_mean_filter_en_SI => rbk_dist_mean_filter_en_SI,
		dist_corr_en_SI        => rbk_dist_corr_en_SI,
		dist_corr_dll_DI       => rbk_dist_corr_dll_DI,
		dist_nb_dll_steps_DI   => rbk_dist_dll_steps_DI,
		dist_index_trunc_DO    => dist_offset_index_trunc_DO,
		dist_fail_pos_DO       => dist_offset_fail_pos_DO,
		dist_index_low_SO      => dist_offset_index_low_SO,
		dist_index_high_SO     => dist_offset_index_high_SO
	);		
	
	-- Dist divider (Xilinx primitive)
	i_dist_div : div_gen_dist_offset
    port map (
      aclk => clk_CI,
      s_axis_divisor_tvalid => dist_offset_div_pulse_S,
      s_axis_divisor_tdata => dist_offset_divisor_D,
      s_axis_dividend_tvalid => dist_offset_div_pulse_S,
      s_axis_dividend_tdata => dist_offset_dividend_D,
	  m_axis_dout_tvalid => dist_div_out_valid_S,
      m_axis_dout_tdata => dist_div_out_D
    );		
	
	readRam_en_SO    <= cc_tcmi_en_S and bad_pix_readRam_reset_RB;
	readRam_pulse_SO <= dist_offset_ram_read_pulse_S or bad_pix_ram_rd_pulse_S;	
	
	-- Dist multiplier (Xilinx primitive)
    i_mult_dist : mult_gen_dist
    port map (
      CLK => clk_CI,
      A => dist_offset_data_D,
      B => rbk_mult_fact_DI,
      P => mult_dist_data_D
    );	
	
	-- Add constant offset
	i_add_const_offset : ip_add_const
    port map (
		clk_CI       => clk_CI,
		en_DI        => cc_tcmi_en_S,
        datain_DI    => mult_dist_data_D,
        dataout_DO   => add_const_data_D,
        satin_DI     => dist_offset_sat_S,
        satout_DO    => add_const_sat_S,
		const_en_SI  => rbk_add_const_en_SI,
		const_val_DI => rbk_add_const_val_DI,
		max_val_DI   => rbk_const_max_val_DI
	);		
	
	i_reg_stage_add_const_sat_out : ip_reg_stage
	generic map (
        NB_STAGES => 3
	)
    port map (
        en_DI      => cc_tcmi_en_S,
        clk_CI     => clk_CI,
        data_DI(0) => add_const_sat_S,
        data_DO(0) => reg_add_const_sat_S
	);	
	
	i_reg_stage_bad_pix_out : ip_reg_stage
	generic map (
        NB_STAGES => 4
	)
    port map (
        en_DI      => cc_tcmi_en_S,
        clk_CI     => clk_CI,
        data_DI(0) => dist_offset_pix_sat_S,
        data_DO(0) => reg_dist_offset_pix_sat_S
	);		
	
	i_reg_stage_sat_amp_mux : ip_reg_stage
	generic map (
		BIT_WIDTH => NBITS_AMP_OUT+4,
        NB_STAGES => 4
	)
    port map (
        en_DI   => cc_tcmi_en_S,
        clk_CI  => clk_CI,
        data_DI => mux_amp_sat_D,
        data_DO => reg_mux_amp_sat_D
	);	
	
	dist_amp_sat_concat_DO <= (reg_dist_offset_pix_sat_S or reg_mux_amp_sat_D(NBITS_AMP_OUT) or reg_add_const_sat_S) & reg_mux_amp_sat_D(NBITS_AMP_OUT+3) & reg_mux_amp_sat_D(NBITS_AMP_OUT+1) & reg_mux_amp_sat_D(NBITS_AMP_OUT+2) & reg_mux_amp_sat_D(NBITS_AMP_OUT-1 downto 0) & add_const_data_D;
	
	i_reg_stage_dist_offset_pulse : ip_reg_stage
	generic map (
        NB_STAGES => 4
	)
    port map (
        en_DI      => cc_tcmi_en_S,
        clk_CI     => clk_CI,
        data_DI(0) => dist_offset_pulse_S,
        data_DO(0) => reg_dist_offset_pulse_S
	);		
	
	dist_amp_sat_pulse_SO  <= reg_dist_offset_pulse_S;
	
	-- Reg stage for ram_gs_pulse
	i_reg_stage_ram_gs_pulse : ip_reg_stage
	generic map (
        NB_STAGES => 1
	)
    port map (
        en_DI      => cc_tcmi_en_S,
        clk_CI     => clk_CI,
        data_DI(0) => img_grey_pulse_S,
        data_DO(0) => ram_gs_pulse_S
	);		
	
	i_gs_compensation : ip_gs_compensation
    generic map (
	  NBITS_DATA_IN => NBITS_DATA_IN+1,
	  NBITS_RAM_IN  => NBITS_GS_RAM,
	  NB_SHIFT_LEFT => 4
	)
	port map ( 
	  clk_CI => clk_CI,								               
	  en_SI  => rbk_gs_comp_en_SI,
	  gs_pulse_in_SI => img_grey_pulse_S,
	  gs_data_in_DI   => img_data_out_D,
	  ram_pulse_in_SI => ram_gs_pulse_S,
	  ram_data_in_DI  => ram_dcs_data_DI(NBITS_GS_RAM-1 downto 0),
	  ram_pulse_req_SO => gs_comp_ram_pulse_req_S,
	  gs_pulse_out_SO => gs_comp_pulse_S,   --grey_pulse_out_SO,
	  gs_data_out_DO  => gs_comp_out_D
	);
	
	i_gs_subtract : ip_gs_subtract
	generic map (
		NBITS_DATA => NBITS_DATA_IN+1
	)
    port map (
		clk_CI          => clk_CI,
        gs_en_DI        => rbk_gs_subtract_SI,
        gs_DI           => gs_comp_out_D,
        gs_pulse_in_SI  => gs_comp_pulse_S,
        gs_DO           => gs_data_DO,
        gs_pulse_out_SO => grey_pulse_out_SO
	);		
	
	dcs0_or_dcs1_pulse_S <= img_dcs0_pulse_S or img_dcs1_pulse_S;
	grey_pulse_in_SO     <= dcs0_or_dcs1_pulse_S;
	
	i_reg_stage_dcssel : ip_reg_stage
	generic map (
        NB_STAGES => 10
	)
    port map (
        en_DI      => cc_tcmi_en_S,
        clk_CI     => clk_CI,
        data_DI(0) => cc_img_bin_dcs_sel_D(1),
        data_DO(0) => reg_cc_img_bin_dcs_sel_D
	);		
	
	en_d2r_gs_SO <= cc_tcmi_en_S and not reg_cc_img_bin_dcs_sel_D;
 	
	i_reg_stage_dcs0_or_dcs1 : ip_reg_stage
	generic map (
        NB_STAGES => 3
	)
    port map (
        en_DI      => cc_tcmi_en_S,
        clk_CI     => clk_CI,
        data_DI(0) => dcs0_or_dcs1_pulse_S,
        data_DO(0) => reg_dcs0_or_dcs1_pulse_SO
	);		
	
	i_reg_stage_dcssat_corr : ip_reg_stage
	generic map (
        NB_STAGES => 2
	)
    port map (
        en_DI      => cc_tcmi_en_S,
        clk_CI     => clk_CI,
        data_DI(0) => DCSsat_S,
        data_DO(0) => reg_dcssat_corr_S
	);			
	
	i_ambient_light_sup : ip_ambient_light_sup
	generic map (
        NBITS_DATA    => NBITS_DATA_IN,
		NBITS_COMP    => NBITS_AL_COMP,
		NBITS_COMP_FP => NBITS_AL_COMP/2
	)
    port map (
		clk_CI          => clk_CI,
		en_DI           => rbk_ambient_en_SI,
		resetn_RBI      => img_ambient_en_S,
        GS_DI           => gs_data_DI,
        DCS_DI          => img_data_out_D,
        DCScorr_DO      => ambient_corr_data_D,
		ambient_comp_DI => rbk_ambient_comp_DI
	);		
	
	en_d2r_dcs_SO    <= cc_tcmi_en_S;
	
	-- Reuse data2ram_dcs for gs_compensation data2ram_dcs
	process(rbk_gs_comp_en_SI, cc_img_bin_dcs_sel_D(2), reg_cc_img_bin_dcs_sel_D, reg_dcssat_corr_S, ambient_corr_data_D)
	begin
		-- Init dcs_data_DO with 0's, due to different sizes of data for GS and DCS
		dcs_data_DO <= (others => '0'); 
		if (rbk_gs_comp_en_SI = '1' and cc_img_bin_dcs_sel_D(2) = '1') then -- GS Mode and compensation enabled
			en_d2r_wr_dcs_SO       <= '0';
			dcs2_or_dcs3_pulse_SO  <= gs_comp_ram_pulse_req_S;
		else
			en_d2r_wr_dcs_SO                      <= not reg_cc_img_bin_dcs_sel_D;
			dcs_data_DO(NBITS_DATA_IN+1 downto 0) <= reg_dcssat_corr_S & ambient_corr_data_D;
			dcs2_or_dcs3_pulse_SO                 <= img_dcs2_pulse_S or img_dcs3_pulse_S;
		end if;
	end process;
    
    
    -- debugging unit
    i_dbg : ip_tof_debug_unit
	generic map (
		NBITS_DATA                  => 16,
        NBITS_FRAME_LENGTH          => NBITS_LENGTH,
        NBITS_BRAM_DATA             => 32,
        NBITS_BRAM_ADDR             => 10	)
	port map ( 
		-- clock and reset
		Clk                         => clk_CI,
        Rst                         => not (reset_RBI),
        
        -- control inputs
        Ena                         => rbk_dbg_en_SI,
        Rb_PxlCount                 => rbg_dbg_pxl_count_DI,
        Rb_DbgPxlIdx                => rbk_dbg_pxl_index_DI,
        
        -- data intput interfaces
        DcsRawX_Data(15 downto 13)  => "000",
        DcsRawX_Data(12 downto 0)   => img_data_out_D,
        DcsRawX_Vld(0)              => img_dcs0_pulse_S,
        DcsRawX_Vld(1)              => img_dcs1_pulse_S,
        DcsRawX_Vld(2)              => img_dcs2_pulse_S,
        DcsRawX_Vld(3)              => img_dcs3_pulse_S,
        
        DcsAmbX_Data(15 downto 13)  => "000",
        DcsAmbX_Data(12 downto 0)   => ambient_corr_data_D,
        DcsAmbX_Vld(0)              => img_dcs0_pulse_reg2,   -- tbd 2clocks after ambient input
        DcsAmbX_Vld(1)              => img_dcs1_pulse_reg2,   
        
        --DistRaw_Data(15 downto NBITS_DIST_OUT)  => (others => '0'),
        DistRaw_Data(NBITS_DIST_OUT-1 downto 0) => alu_dist_D,
        DistRaw_Vld                 => reg_alu_out_pulse_S,
        
        --DistComp_Data(15 downto NBITS_DIST_OUT)  => (others => '0'),
        DistComp_Data(NBITS_DIST_OUT-1 downto 0) => add_const_data_D,
        DistComp_Vld                => reg_dist_offset_pulse_S,
        
        GsRaw_Data(15 downto 13)    => "000",
        GsRaw_Data(12 downto 0)     => img_data_out_D,
        GsRaw_Vld                   => img_grey_pulse_S,
        
        GsComp_Data(15 downto 13)   => "000",
        GsComp_Data(12 downto 0)    => gs_comp_out_D,
        GsComp_Vld                  => gs_comp_pulse_S,
        
        -- BRAM interface
        DbgBram_Addr                => DbgBram_Addr,
        DbgBram_Data                => DbgBram_Data,
        DbgBram_Wen                 => DbgBram_Wen);

    -- helper signals
 	i_dbg_hlp_amb : ip_reg_stage
	generic map (
        BIT_WIDTH	=> 2,
        NB_STAGES   => 2)
    port map (
        en_DI      => '1',
        clk_CI     => clk_CI,
        data_DI(0) => img_dcs0_pulse_S,
        data_DI(1) => img_dcs1_pulse_S,
        data_DO(0) => img_dcs0_pulse_reg2,
        data_DO(1) => img_dcs1_pulse_reg2
	);		   
        
	
end Behavioral;