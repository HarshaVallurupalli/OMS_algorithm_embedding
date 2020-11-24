----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 09/25/2019
-- Design Name: 
-- Module Name: tb_TOF_cos_sl - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

Library xpm;
use xpm.vcomponents.all;

entity tb_TOF_cos_sl is
--  Port ( );
end tb_TOF_cos_sl ;

architecture Behavioral of tb_TOF_cos_sl  is
    component TOF_cos_sl
		generic (
	        ENABLE_INPUT_FIFO   : boolean  := false;	
	        ENABLE_DELAY_NB     : positive := 1200;	    
			NB_OF_PIXEL         : positive := 76800;
			NBITS_DATA_IN       : positive := 12;
			NBITS_LENGTH        : positive := 17;
			NBITS_LINE_LENGTH   : positive := 9;		
			NBITS_ADDR_IMG_BRAM : positive := 10;	
			NBITS_ADDR_BRAM_DCS : positive := 10;
			NBITS_DATA_BRAM_DCS : positive := 16;    
			MEM_SIZE_BRAM_DCS   : positive := 640;
			NBITS_ADDR_FIFO0    : positive := 16;
			NBITS_ADDR_FIFO1    : positive := 14;
			NBITS_DIST_OUT      : positive := 16;
			NBITS_AMP_OUT       : positive := 12;
			NBITS_AL_COMP       : positive := 16;
			NBITS_MININDEX      : positive := 8;
			NBITS_GS_RAM        : positive := 16;
		    NBITS_MAX_GS_RAM_DATA_IN : positive := 16;			
			NBITS_CAL_RAM       : positive := 128;
			NBITS_DIST_INDEX    : positive := 5;
			NBITS_DIST_MEM_CTRL : positive := 9;
			NBITS_DLL_CORR      : positive := 16;
			NBITS_NB_DLL_STEPS  : positive := 8;
			NBITS_OUTPUT_DATA   : positive := 32
		);	
        port (
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
    end component;
    
    constant T_DCLK_HALF : time := 22.6 ns;
    --constant T_DCLK_HALF : time := 15 ns;
    
    constant NROWS : positive := 20;
    constant NCOLS : positive := 320;
	
	constant TB_ENABLE_INPUT_FIFO   : boolean  := true;
	constant TB_ENABLE_DELAY_NB     : positive := 1200;	  
	constant TB_NB_OF_PIXEL         : positive := NROWS*NCOLS;
	constant TB_NBITS_DATA_IN       : positive := 12;
	constant TB_NBITS_LENGTH        : positive := 17;
	constant TB_NBITS_LINE_LENGTH   : positive := 9;		
	constant TB_NBITS_ADDR_IMG_BRAM : positive := 10;	
	constant TB_NBITS_ADDR_BRAM_DCS : positive := 10;
	constant TB_NBITS_DATA_BRAM_DCS : positive := 16;    
	constant TB_MEM_SIZE_BRAM_DCS   : positive := 2*NCOLS;
	constant TB_NBITS_ADDR_FIFO0    : positive := 16;
	constant TB_NBITS_ADDR_FIFO1    : positive := 14;
	constant TB_NBITS_DIST_OUT      : positive := 16;
	constant TB_NBITS_AMP_OUT       : positive := 12;
	constant TB_NBITS_AL_COMP       : positive := 16;
	constant TB_NBITS_MININDEX      : positive := 8;
	constant TB_NBITS_DATA_MAX_IN   : positive := 16;
	constant TB_NBITS_GS_RAM        : positive := 16;
	constant TB_NBITS_CAL_RAM       : positive := 128;
	constant TB_NBITS_DIST_INDEX    : positive := 5;
	constant TB_NBITS_DIST_MEM_CTRL : positive := 9;
	constant TB_NBITS_DLL_CORR      : positive := 16;
	constant TB_NBITS_NB_DLL_STEPS  : positive := 8;
	constant TB_NBITS_OUTPUT_DATA   : positive := 32;

    signal clk_C                      : std_logic := '0';
	signal reset_RB                   : std_logic := '0';
	signal reset_R                    : std_logic := '1';
	signal reset_or_done_edge_RB      : std_logic;
	signal dclk_in_S                  : std_logic := '0';
	signal vsync_in_S                 : std_logic := '1';
	signal hsync_in_S                 : std_logic := '1';
	signal xsync_sat_in_S             : std_logic := '0';
	signal data_in_D                  : std_logic_vector(TB_NBITS_DATA_IN-1 downto 0) := (others => '0');
	signal rbk_cc_en_S                : std_logic := '1';
	signal rbk_cc_rst_S               : std_logic := '0';
	signal rbk_cc_update_reg_values_S : std_logic := '0';
	signal rbk_cc_mode_S              : std_logic_vector(2 downto 0) := "001"; -- GS
	signal rbk_cc_data_length_S       : std_logic_vector(TB_NBITS_LENGTH-1 downto 0) := std_logic_vector(to_unsigned(NROWS*NCOLS, TB_NBITS_LENGTH));
	signal rbk_image_bin_en_S         : std_logic := '0';
	signal rbk_img_pix_inter_en_S     : std_logic := '0';
	signal rbk_img_adc_inter_en_S     : std_logic := '0';
	signal rbk_im_rem_sat_S           : std_logic := '0';
	signal rbk_init_table_S           : std_logic := '0';
	signal rbk_adc_underflow_S        : std_logic := '1';
	signal rbk_adc_overflow_S         : std_logic := '1';
	signal rbk_interf_thr_D           : std_logic_vector(TB_NBITS_DATA_IN downto 0) := (others => '0');
	signal rbk_alu_Dist_corr_D        : std_logic_vector(TB_NBITS_DATA_IN-1 downto 0) := std_logic_vector(to_unsigned(2048, TB_NBITS_DATA_IN));
	signal rbk_alu_amp_corr_D         : std_logic_vector(TB_NBITS_DATA_IN-1 downto 0) := std_logic_vector(to_unsigned(2048, TB_NBITS_DATA_IN));
	signal rbk_alu_minIndex_D         : std_logic_vector(TB_NBITS_MININDEX-1 downto 0) := (others => '0');
	signal rbk_add_const_temp_en_S    : std_logic := '1';
	signal rbk_add_const_temp_val_D   : std_logic_vector(TB_NBITS_DIST_OUT downto 0) := (others => '0');
	signal rbk_line_length_D          : std_logic_vector(TB_NBITS_LINE_LENGTH-1 downto 0):= std_logic_vector(to_unsigned(NCOLS, TB_NBITS_LINE_LENGTH));
	signal rbk_dist_mean_filter_en_S  : std_logic := '1';
	signal rbk_dist_corr_en_S         : std_logic := '1';
	signal rbk_dist_corr_dll_D        : std_logic_vector(TB_NBITS_DLL_CORR-1 downto 0) := std_logic_vector(to_unsigned(1029, TB_NBITS_DLL_CORR));
	signal rbk_dist_dll_steps_D       : std_logic_vector(TB_NBITS_NB_DLL_STEPS-1 downto 0) := std_logic_vector(to_unsigned(50, TB_NBITS_NB_DLL_STEPS));
	signal rbk_mult_fact_D            : std_logic_vector(TB_NBITS_DIST_OUT-1 downto 0) := std_logic_vector(to_unsigned(0, TB_NBITS_DIST_OUT));
	signal rbk_add_const_en_S         : std_logic := '1';
	signal rbk_add_const_val_D        : std_logic_vector(TB_NBITS_DIST_OUT downto 0) := (others => '0');
	signal rbk_const_max_val_D        : std_logic_vector(TB_NBITS_DIST_OUT-1 downto 0) := (others => '1');
	signal rbk_ambient_en_S           : std_logic := '1';
	signal rbk_ambient_comp_D		  : std_logic_vector(TB_NBITS_AL_COMP-1 downto 0) := (others => '0');
	signal rbk_gs_subtract_S          : std_logic := '1';
	signal cc_reset_regs_R            : std_logic;
	signal dist_offset_index_trunc_D  : std_logic_vector(TB_NBITS_NB_DLL_STEPS-1 downto 0);
	signal dist_offset_fail_pos_D     : std_logic_vector(TB_NBITS_LENGTH-1 downto 0);
	signal dist_offset_index_low_S    : std_logic;
	signal dist_offset_index_high_S	  : std_logic;
	signal sg_dma_intr_S              : std_logic := '0';
	signal cc_sort_length_D           : std_logic_vector(TB_NBITS_LENGTH+1 downto 0);
	signal dist_amp_sat_concat_D      : std_logic_vector(TB_NBITS_OUTPUT_DATA-1 downto 0);
	signal dist_amp_sat_pulse_S       : std_logic;
	signal sel_gs_mode_S              : std_logic;
	signal readRam_pulse_out_S        : std_logic := '0';
	signal readRam_data_D             : std_logic_vector(TB_NBITS_CAL_RAM-1 downto 0) := (others => '0');
	signal readRam_en_S               : std_logic;
	signal readRam_pulse_S            : std_logic;		
	signal readRam_index_D            : std_logic_vector(TB_NBITS_DIST_INDEX-1 downto 0) := (others => '0');	
	signal gs_data_D                  : std_logic_vector(TB_NBITS_DATA_IN downto 0);
	signal en_d2r_gs_S                : std_logic;
	signal length_gs_data_D           : std_logic_vector(TB_NBITS_LENGTH+1 downto 0);
	signal grey_pulse_out_S           : std_logic;
	signal grey_pulse_in_S            : std_logic;
	signal gs_data_in_D               : std_logic_vector(TB_NBITS_DATA_IN downto 0) := (others => '0');
	signal cc_dcs_length_D            : std_logic_vector(TB_NBITS_LENGTH-1 downto 0);
	signal dcs_data_D                 : std_logic_vector(TB_NBITS_DATA_MAX_IN-1 downto 0);
	signal en_d2r_dcs_S               : std_logic;
	signal en_d2r_wr_dcs_S            : std_logic;
	signal reg_dcs0_or_dcs1_pulse_S   : std_logic;
	signal dcs2_or_dcs3_pulse_S       : std_logic;
	signal ram_dcs_data_D             : std_logic_vector(TB_NBITS_DATA_MAX_IN-1 downto 0) := (others => '0');
    
begin
    clk_C     <= not clk_C after 5 ns;
	dclk_in_S <= not dclk_in_S after T_DCLK_HALF;
    
    UUT: TOF_cos_sl 
		generic map(
		    ENABLE_INPUT_FIFO   => TB_ENABLE_INPUT_FIFO  ,
		    ENABLE_DELAY_NB     => TB_ENABLE_DELAY_NB    ,
			NB_OF_PIXEL         => TB_NB_OF_PIXEL        ,
			NBITS_DATA_IN       => TB_NBITS_DATA_IN      ,
			NBITS_LENGTH        => TB_NBITS_LENGTH       ,
			NBITS_LINE_LENGTH   => TB_NBITS_LINE_LENGTH  ,
			NBITS_ADDR_IMG_BRAM => TB_NBITS_ADDR_IMG_BRAM,
			NBITS_ADDR_BRAM_DCS => TB_NBITS_ADDR_BRAM_DCS,
			NBITS_DATA_BRAM_DCS => TB_NBITS_DATA_BRAM_DCS, 
			MEM_SIZE_BRAM_DCS   => TB_MEM_SIZE_BRAM_DCS  ,
			NBITS_ADDR_FIFO0    => TB_NBITS_ADDR_FIFO0   ,
			NBITS_ADDR_FIFO1    => TB_NBITS_ADDR_FIFO1   ,
			NBITS_DIST_OUT      => TB_NBITS_DIST_OUT     ,
			NBITS_AMP_OUT       => TB_NBITS_AMP_OUT      ,
			NBITS_AL_COMP       => TB_NBITS_AL_COMP      ,
			NBITS_MININDEX      => TB_NBITS_MININDEX     ,
			NBITS_GS_RAM        => TB_NBITS_GS_RAM       ,
			NBITS_CAL_RAM       => TB_NBITS_CAL_RAM      ,
			NBITS_DIST_INDEX    => TB_NBITS_DIST_INDEX   ,
			NBITS_DIST_MEM_CTRL => TB_NBITS_DIST_MEM_CTRL,
			NBITS_DLL_CORR      => TB_NBITS_DLL_CORR     ,
			NBITS_NB_DLL_STEPS  => TB_NBITS_NB_DLL_STEPS ,
			NBITS_OUTPUT_DATA   => TB_NBITS_OUTPUT_DATA  
		)
		port map(
			clk_CI                      => clk_C,                     
			reset_RBI                   => reset_RB,                 
			reset_or_done_edge_RBO      => reset_or_done_edge_RB,     
			dclk_in_SI                  => dclk_in_S,                 
			vsync_in_SI                 => vsync_in_S,                
			hsync_in_SI                 => hsync_in_S,                
			xsync_sat_in_SI             => xsync_sat_in_S,            
			data_in_DI                  => data_in_D,                 
			rbk_cc_en_SI                => rbk_cc_en_S,               
			rbk_cc_rst_SI               => rbk_cc_rst_S,              
			rbk_cc_update_reg_values_SI => rbk_cc_update_reg_values_S,
			rbk_cc_mode_SI              => rbk_cc_mode_S,             
			rbk_cc_data_length_SI       => rbk_cc_data_length_S,      
			rbk_image_bin_en_SI         => rbk_image_bin_en_S,        
			rbk_img_pix_inter_en_SI     => rbk_img_pix_inter_en_S,   
			rbk_img_adc_inter_en_SI     => rbk_img_adc_inter_en_S,    
			rbk_im_rem_sat_SI           => rbk_im_rem_sat_S,          
			rbk_init_table_SI           => rbk_init_table_S,          
			rbk_adc_underflow_SI        => rbk_adc_underflow_S,       
			rbk_adc_overflow_SI         => rbk_adc_overflow_S,        
			rbk_interf_thr_DI           => rbk_interf_thr_D,          
			rbk_alu_dist_corr_DI        => rbk_alu_dist_corr_D,       
			rbk_alu_amp_corr_DI         => rbk_alu_amp_corr_D,        
			rbk_alu_minIndex_DI         => rbk_alu_minIndex_D,        
			rbk_add_const_temp_en_SI    => rbk_add_const_temp_en_S,   
			rbk_add_const_temp_val_DI   => rbk_add_const_temp_val_D,  
			rbk_line_length_DI          => rbk_line_length_D,         
			rbk_dist_mean_filter_en_SI  => rbk_dist_mean_filter_en_S, 
			rbk_dist_corr_en_SI         => rbk_dist_corr_en_S,        
			rbk_dist_corr_dll_DI        => rbk_dist_corr_dll_D,       
			rbk_dist_dll_steps_DI       => rbk_dist_dll_steps_D,      
			rbk_mult_fact_DI            => rbk_mult_fact_D,           
			rbk_add_const_en_SI         => rbk_add_const_en_S,        
			rbk_add_const_val_DI        => rbk_add_const_val_D,       
			rbk_const_max_val_DI        => rbk_const_max_val_D,       
			rbk_ambient_en_SI           => rbk_ambient_en_S,          
			rbk_ambient_comp_DI		    => rbk_ambient_comp_D,		
			rbk_gs_comp_en_SI           => '1',   
			rbk_gs_subtract_SI          => rbk_gs_subtract_S,   

            -- debug unit
            rbk_dbg_en_SI               => '1',  
            rbg_dbg_pxl_count_DI        => rbk_cc_data_length_S,     
            rbk_dbg_pxl_index_DI        => std_logic_vector(to_unsigned(3, TB_NBITS_LENGTH)),

            
			cc_reset_regs_RO            => cc_reset_regs_R,           
			dist_offset_index_trunc_DO  => dist_offset_index_trunc_D, 
			dist_offset_fail_pos_DO     => dist_offset_fail_pos_D,    
			dist_offset_index_low_SO    => dist_offset_index_low_S,   
			dist_offset_index_high_SO	=> dist_offset_index_high_S,	
			sg_dma_intr_SI              => sg_dma_intr_S,             
			cc_sort_length_DO           => cc_sort_length_D,          
			dist_amp_sat_concat_DO      => dist_amp_sat_concat_D,     
			dist_amp_sat_pulse_SO       => dist_amp_sat_pulse_S,      
			sel_gs_mode_SO              => sel_gs_mode_S,             
			readRam_pulse_out_SI        => readRam_pulse_out_S,       
			readRam_data_DI             => readRam_data_D,            
			readRam_en_SO               => readRam_en_S,              
			readRam_pulse_SO            => readRam_pulse_S,           
			readRam_index_DO            => readRam_index_D,           
			gs_data_DO                  => gs_data_D,                 
			en_d2r_gs_SO                => en_d2r_gs_S,               
			length_gs_data_DO           => length_gs_data_D,          
			grey_pulse_out_SO           => grey_pulse_out_S,          
			grey_pulse_in_SO            => grey_pulse_in_S,           
			gs_data_DI                  => gs_data_in_D,        
			cc_dcs_length_DO            => cc_dcs_length_D,        
			dcs_data_DO                 => dcs_data_D,                
			en_d2r_dcs_SO               => en_d2r_dcs_S,              
			en_d2r_wr_dcs_SO            => en_d2r_wr_dcs_S,           
			reg_dcs0_or_dcs1_pulse_SO   => reg_dcs0_or_dcs1_pulse_S,  
			dcs2_or_dcs3_pulse_SO       => dcs2_or_dcs3_pulse_S,      
			ram_dcs_data_DI             => "0001010100010101",--ram_dcs_data_D
            
            -- debug bram
            DbgBram_Addr                => open,    
            DbgBram_Data                => open,    
            DbgBram_Wen                 => open
		);
		
UUT_ref: TOF_cos_sl 
                generic map(
                    ENABLE_INPUT_FIFO   => false  ,
                    ENABLE_DELAY_NB     => TB_ENABLE_DELAY_NB    ,
                    NB_OF_PIXEL         => TB_NB_OF_PIXEL        ,
                    NBITS_DATA_IN       => TB_NBITS_DATA_IN      ,
                    NBITS_LENGTH        => TB_NBITS_LENGTH       ,
                    NBITS_LINE_LENGTH   => TB_NBITS_LINE_LENGTH  ,
                    NBITS_ADDR_IMG_BRAM => TB_NBITS_ADDR_IMG_BRAM,
                    NBITS_ADDR_BRAM_DCS => TB_NBITS_ADDR_BRAM_DCS,
                    NBITS_DATA_BRAM_DCS => TB_NBITS_DATA_BRAM_DCS, 
                    MEM_SIZE_BRAM_DCS   => TB_MEM_SIZE_BRAM_DCS  ,
                    NBITS_ADDR_FIFO0    => TB_NBITS_ADDR_FIFO0   ,
                    NBITS_ADDR_FIFO1    => TB_NBITS_ADDR_FIFO1   ,
                    NBITS_DIST_OUT      => TB_NBITS_DIST_OUT     ,
                    NBITS_AMP_OUT       => TB_NBITS_AMP_OUT      ,
                    NBITS_AL_COMP       => TB_NBITS_AL_COMP      ,
                    NBITS_MININDEX      => TB_NBITS_MININDEX     ,
                    NBITS_GS_RAM        => TB_NBITS_GS_RAM       ,
                    NBITS_CAL_RAM       => TB_NBITS_CAL_RAM      ,
                    NBITS_DIST_INDEX    => TB_NBITS_DIST_INDEX   ,
                    NBITS_DIST_MEM_CTRL => TB_NBITS_DIST_MEM_CTRL,
                    NBITS_DLL_CORR      => TB_NBITS_DLL_CORR     ,
                    NBITS_NB_DLL_STEPS  => TB_NBITS_NB_DLL_STEPS ,
                    NBITS_OUTPUT_DATA   => TB_NBITS_OUTPUT_DATA  
                )
                port map(
                    clk_CI                      => clk_C,                     
                    reset_RBI                   => reset_RB,                 
                    reset_or_done_edge_RBO      => open,     
                    dclk_in_SI                  => dclk_in_S,                 
                    vsync_in_SI                 => vsync_in_S,                
                    hsync_in_SI                 => hsync_in_S,                
                    xsync_sat_in_SI             => xsync_sat_in_S,            
                    data_in_DI                  => data_in_D,                 
                    rbk_cc_en_SI                => rbk_cc_en_S,               
                    rbk_cc_rst_SI               => rbk_cc_rst_S,              
                    rbk_cc_update_reg_values_SI => rbk_cc_update_reg_values_S,
                    rbk_cc_mode_SI              => rbk_cc_mode_S,             
                    rbk_cc_data_length_SI       => rbk_cc_data_length_S,      
                    rbk_image_bin_en_SI         => rbk_image_bin_en_S,        
                    rbk_img_pix_inter_en_SI     => rbk_img_pix_inter_en_S,   
                    rbk_img_adc_inter_en_SI     => rbk_img_adc_inter_en_S,    
                    rbk_im_rem_sat_SI           => rbk_im_rem_sat_S,          
                    rbk_init_table_SI           => rbk_init_table_S,          
                    rbk_adc_underflow_SI        => rbk_adc_underflow_S,       
                    rbk_adc_overflow_SI         => rbk_adc_overflow_S,        
                    rbk_interf_thr_DI           => rbk_interf_thr_D,          
                    rbk_alu_dist_corr_DI        => rbk_alu_dist_corr_D,       
                    rbk_alu_amp_corr_DI         => rbk_alu_amp_corr_D,        
                    rbk_alu_minIndex_DI         => rbk_alu_minIndex_D,        
                    rbk_add_const_temp_en_SI    => rbk_add_const_temp_en_S,   
                    rbk_add_const_temp_val_DI   => rbk_add_const_temp_val_D,  
                    rbk_line_length_DI          => rbk_line_length_D,         
                    rbk_dist_mean_filter_en_SI  => rbk_dist_mean_filter_en_S, 
                    rbk_dist_corr_en_SI         => rbk_dist_corr_en_S,        
                    rbk_dist_corr_dll_DI        => rbk_dist_corr_dll_D,       
                    rbk_dist_dll_steps_DI       => rbk_dist_dll_steps_D,      
                    rbk_mult_fact_DI            => rbk_mult_fact_D,           
                    rbk_add_const_en_SI         => rbk_add_const_en_S,        
                    rbk_add_const_val_DI        => rbk_add_const_val_D,       
                    rbk_const_max_val_DI        => rbk_const_max_val_D,       
                    rbk_ambient_en_SI           => rbk_ambient_en_S,          
                    rbk_ambient_comp_DI         => rbk_ambient_comp_D,   
                    rbk_gs_comp_en_SI           => '0',           
                    rbk_gs_subtract_SI          => rbk_gs_subtract_S,        
                    
                    -- debug unit
                    rbk_dbg_en_SI               => '1',
                    rbg_dbg_pxl_count_DI        => rbk_cc_data_length_S,      
                    rbk_dbg_pxl_index_DI        => std_logic_vector(to_unsigned(3, TB_NBITS_LENGTH)),
                    
                    cc_reset_regs_RO            => cc_reset_regs_R,           
                    dist_offset_index_trunc_DO  => open, 
                    dist_offset_fail_pos_DO     => open,    
                    dist_offset_index_low_SO    => open,   
                    dist_offset_index_high_SO    => open,    
                    sg_dma_intr_SI              => sg_dma_intr_S,             
                    cc_sort_length_DO           => open,          
                    dist_amp_sat_concat_DO      => open,     
                    dist_amp_sat_pulse_SO       => open,      
                    sel_gs_mode_SO              => open,             
                    readRam_pulse_out_SI        => readRam_pulse_out_S,       
                    readRam_data_DI             => readRam_data_D,            
                    readRam_en_SO               => open,              
                    readRam_pulse_SO            => open,           
                    readRam_index_DO            => open,           
                    gs_data_DO                  => open,                 
                    en_d2r_gs_SO                => open,               
                    length_gs_data_DO           => open,          
                    grey_pulse_out_SO           => open,          
                    grey_pulse_in_SO            => open,           
                    gs_data_DI                  => gs_data_in_D,        
                    cc_dcs_length_DO            => open,        
                    dcs_data_DO                 => open,                
                    en_d2r_dcs_SO               => open,              
                    en_d2r_wr_dcs_SO            => open,           
                    reg_dcs0_or_dcs1_pulse_SO   => open,  
                    dcs2_or_dcs3_pulse_SO       => open,      
                    ram_dcs_data_DI             => ram_dcs_data_D,
                    
                    -- debug bram
                    DbgBram_Addr                => open,    
                    DbgBram_Data                => open,    
                    DbgBram_Wen                 => open
                    
                );
		
	    reset_R <= not reset_RB;
		
		xpm_fifo_sync_gs : xpm_fifo_sync
           generic map (
              DOUT_RESET_VALUE => "0",    -- String
              ECC_MODE => "no_ecc",       -- String
              FIFO_MEMORY_TYPE => "auto", -- String
              FIFO_READ_LATENCY => 1,     -- DECIMAL
              FIFO_WRITE_DEPTH => 262144,   -- DECIMAL
              FULL_RESET_VALUE => 0,      -- DECIMAL
              PROG_EMPTY_THRESH => 10,    -- DECIMAL
              PROG_FULL_THRESH => 10,     -- DECIMAL
              RD_DATA_COUNT_WIDTH => 1,   -- DECIMAL
              READ_DATA_WIDTH => 13,      -- DECIMAL
              READ_MODE => "std",         -- String
              USE_ADV_FEATURES => "0707", -- String
              WAKEUP_TIME => 0,           -- DECIMAL
              WRITE_DATA_WIDTH => 13,     -- DECIMAL
              WR_DATA_COUNT_WIDTH => 1    -- DECIMAL
           )
           port map (
              almost_empty => open,
              almost_full => open,
              data_valid => open,
              dbiterr => open,
              dout => gs_data_in_D,
              empty => open,
              full => open,
              overflow => open,
              prog_empty => open,
              prog_full => open,
              rd_data_count => open,
              rd_rst_busy => open,
              sbiterr => open,
              underflow => open,
              wr_ack => open,
              wr_data_count => open,
              wr_rst_busy => open,
              din => gs_data_D,
              injectdbiterr => '0',
              injectsbiterr => '0',
              rd_en => grey_pulse_in_S,
              rst => reset_R,
              sleep => '0',
              wr_clk => clk_C,
              wr_en =>  grey_pulse_out_S
           );
		
		xpm_fifo_sync_dcs : xpm_fifo_sync
           generic map (
              DOUT_RESET_VALUE => "0",    -- String
              ECC_MODE => "no_ecc",       -- String
              FIFO_MEMORY_TYPE => "auto", -- String
              FIFO_READ_LATENCY => 1,     -- DECIMAL
              FIFO_WRITE_DEPTH => 131072, -- DECIMAL
              FULL_RESET_VALUE => 0,      -- DECIMAL
              PROG_EMPTY_THRESH => 10,    -- DECIMAL
              PROG_FULL_THRESH => 10,     -- DECIMAL
              RD_DATA_COUNT_WIDTH => 1,   -- DECIMAL
              READ_DATA_WIDTH => 16,      -- DECIMAL
              READ_MODE => "std",         -- String
              USE_ADV_FEATURES => "0707", -- String
              WAKEUP_TIME => 0,           -- DECIMAL
              WRITE_DATA_WIDTH => 16,     -- DECIMAL
              WR_DATA_COUNT_WIDTH => 1    -- DECIMAL
           )
           port map (
              almost_empty => open,
              almost_full => open,
              data_valid => open,
              dbiterr => open,
              dout => ram_dcs_data_D,
              empty => open,
              full => open,
              overflow => open,
              prog_empty => open,
              prog_full => open,
              rd_data_count => open,
              rd_rst_busy => open,
              sbiterr => open,
              underflow => open,
              wr_ack => open,
              wr_data_count => open,
              wr_rst_busy => open,
              din => dcs_data_D,
              injectdbiterr => '0',
              injectsbiterr => '0',
              rd_en => dcs2_or_dcs3_pulse_S,
              rst => reset_R,
              sleep => '0',
              wr_clk => clk_C,
              wr_en =>  reg_dcs0_or_dcs1_pulse_S
           );
        
    process
    begin
		-- Release reset
		wait for 100 ns;
		reset_RB <= '1';
		
		---- Send GS image
		wait for 100 ns;
		wait until rising_edge(dclk_in_S);
		vsync_in_S <= '0';
		for J in 0 to NROWS/2-1 loop
			hsync_in_S <= '0';
			for I in 0 to 2*NCOLS-1 loop
			    if unsigned(data_in_D) = 2322 then
			      data_in_D <= std_logic_vector(to_unsigned(2219,12));
			    else
				  data_in_D <= std_logic_vector(to_unsigned(2322,12));
				end if;
				wait for 2*T_DCLK_HALF;
			end loop;
			hsync_in_S <= '1';
			wait for 12000 ns;
			wait until rising_edge(dclk_in_S);
		end loop;
		vsync_in_S <= '1';
		wait for 180000 ns;
		
		-- DMA intr
		sg_dma_intr_S <= '1';
		wait for 100 ns;
		sg_dma_intr_S <= '0';
		wait for 10 ns;
		
        --wait for 100 ns;
        --wait until rising_edge(dclk_in_S);
        --vsync_in_S <= '0';
        --for J in 0 to NROWS/2-1 loop
        --    hsync_in_S <= '0';
        --    for I in 0 to 2*NCOLS-1 loop
        --        data_in_D <= std_logic_vector(unsigned(data_in_D) + 1);
        --        wait for 2*T_DCLK_HALF;
        --    end loop;
        --    hsync_in_S <= '1';
        --    wait for 12000 ns;
        --    wait until rising_edge(dclk_in_S);
        --end loop;
        --vsync_in_S <= '1';
        --wait for 180000 ns;
        --
        ---- DMA intr
        --sg_dma_intr_S <= '1';
        --wait for 100 ns;
        --sg_dma_intr_S <= '0';
        --wait for 10 ns;
		
		-- Try TOF Image
		rbk_cc_mode_S <= "000"; -- 3D TOF
		wait for 100 ns;
		
		-- DCS0
		data_in_D <= (others => '0');
		wait for 100 ns;
		wait until rising_edge(dclk_in_S);
        vsync_in_S <= '0';
        for J in 0 to NROWS/2-1 loop
            hsync_in_S <= '0';
            for I in 0 to 2*NCOLS-1 loop
                data_in_D <= std_logic_vector(unsigned(data_in_D) + 1);
                wait for 2*T_DCLK_HALF;
            end loop;
            hsync_in_S <= '1';
            wait for 12000 ns;
            wait until rising_edge(dclk_in_S);
        end loop;
        vsync_in_S <= '1';
        wait for 180000 ns;		
        
		-- DCS2
        data_in_D <= (others => '0');
        wait for 100 ns;
        wait until rising_edge(dclk_in_S);
        vsync_in_S <= '0';
        for J in 0 to NROWS/2-1 loop
            hsync_in_S <= '0';
            for I in 0 to 2*NCOLS-1 loop
                data_in_D <= std_logic_vector(unsigned(data_in_D) + 1);
                wait for 2*T_DCLK_HALF;
            end loop;
            hsync_in_S <= '1';
            wait for 12000 ns;
            wait until rising_edge(dclk_in_S);
        end loop;
        vsync_in_S <= '1';
        wait for 180000 ns;    
		
		-- DCS1
        data_in_D <= (others => '0');
        wait for 100 ns;
        wait until rising_edge(dclk_in_S);
        vsync_in_S <= '0';
        for J in 0 to NROWS/2-1 loop
            hsync_in_S <= '0';
            for I in 0 to 2*NCOLS-1 loop
                data_in_D <= std_logic_vector(unsigned(data_in_D) + 1);
                wait for 2*T_DCLK_HALF;
            end loop;
            hsync_in_S <= '1';
            wait for 12000 ns;
            wait until rising_edge(dclk_in_S);
        end loop;
        vsync_in_S <= '1';
        wait for 180000 ns;        
        
        -- DCS3
        data_in_D <= (others => '0');
        wait for 100 ns;
        wait until rising_edge(dclk_in_S);
        vsync_in_S <= '0';
        for J in 0 to NROWS/2-1 loop
            hsync_in_S <= '0';
            for I in 0 to 2*NCOLS-1 loop
                data_in_D <= std_logic_vector(unsigned(data_in_D) + 1);
                wait for 2*T_DCLK_HALF;
            end loop;
            hsync_in_S <= '1';
            wait for 12000 ns;
            wait until rising_edge(dclk_in_S);
        end loop;
        vsync_in_S <= '1';
        wait for 180000 ns;  
        
		-- DMA intr
        sg_dma_intr_S <= '1';
        wait for 100 ns;
        sg_dma_intr_S <= '0';
        wait for 10 ns;          
	
	    wait;
    end process;
end Behavioral;
