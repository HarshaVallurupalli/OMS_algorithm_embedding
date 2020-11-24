library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity reg_bank_v1_0 is
	generic (
		-- Users to add parameters here
		NBITS_DLL_STEPS : integer := 8;
		-- User parameters ends
		-- Do not modify the parameters beyond this line


		-- Parameters of Axi Slave Bus Interface S00_AXI
		C_S00_AXI_DATA_WIDTH	: integer	:= 32;
		C_S00_AXI_ADDR_WIDTH	: integer	:= 6
	);
	port (
		-- Users to add ports here
		-- reg_camera_ctrl_mode
		reset_cc_regs_RI : in std_logic;
		cc_rst_RO : out std_logic;
		cc_update_reg_values_SO : out std_logic;
		cc_mode_SO : out std_logic_vector(2 downto 0);
		cc_init_bad_pix_SO : out std_logic;
		cc_line_length_DO : out std_logic_vector(8 downto 0);
		cc_data_length_DO : out std_logic_vector(16 downto 0);
		-- reg_alu_corr
		alu_amp_corr_DO : out std_logic_vector(11 downto 0);
		alu_dist_corr_DO : out std_logic_vector(11 downto 0);
		alu_min_index_DO : out std_logic_vector(7 downto 0);
		-- reg_ambient_comp
		ambient_comp_DO : out std_logic_vector(15 downto 0);
		-- reg_interference threshold
		interf_thr_DO : out std_logic_vector(12 downto 0);
		-- reg_temp_const_val
		temp_const_val_DO : out std_logic_vector(16 downto 0);
        -- reg_dist_dll 
		dist_dll_DO : out std_logic_vector(15 downto 0);
		nb_dll_steps_DO : out std_logic_vector(NBITS_DLL_STEPS-1 downto 0);
        -- reg_dist_status 
		dist_index_trunc_DI : in std_logic_vector(7 downto 0);
		dist_index_low_SI : in std_logic;
		dist_index_high_SI : in std_logic;
		dist_fail_pos_DI : in std_logic_vector(16 downto 0);
        -- reg_const_val
		const_val_DO : out std_logic_vector(16 downto 0);
		-- reg_block_en
		cc_en_SO : out std_logic;
		temp_comp_en_SO : out std_logic;
		dist_corr_en_SO : out std_logic;
		comp_en_SO : out std_logic;
		adc_ovrflow_en_SO : out std_logic;
		adc_udrflow_en_SO : out std_logic;
		gs_comp_en_SO : out std_logic;
		gs_subtract_en_SO : out std_logic;
		image_bin_en_SO : out std_logic;
		image_bin_rem_sat_SO : out std_logic;
		ambient_en_SO : out std_logic;
		pix_inter_dcs_en_SO : out std_logic;
		pix_inter_dist_en_SO : out std_logic;
		adc_inter_en_SO : out std_logic;
		-- ram Read Addr
		ram_read_addr_DO : out std_logic_vector(31 downto 0);
		-- out multiplication factor
		mult_fact_DO : out std_logic_vector(15 downto 0);
		max_out_val_DO : out std_logic_vector(15 downto 0);
		-- DMA control
        dcs_dma_addr_DO : out std_logic_vector(31 downto 0);
        gs_dma_addr_DO  : out std_logic_vector(31 downto 0);
        dcs_dma_rdy_DI  :  in std_logic;
        dcs_dma_busy_DI :  in std_logic; 
        dcs_dma_done_DI :  in std_logic; 
        dcs_wr_eof_done_SI : in std_logic; 
        gs_dma_rdy_DI   :  in std_logic;
        gs_dma_busy_DI  :  in std_logic; 
        gs_dma_done_DI  :  in std_logic; 
        gs_wr_eof_done_SI : in std_logic; 
        
		roi_tl_x_DO     : out std_logic_vector(8 downto 0);
		roi_br_x_DO     : out std_logic_vector(8 downto 0);		
		roi_tl_y_DO     : out std_logic_vector(6 downto 0);
		roi_br_y_DO     : out std_logic_vector(6 downto 0);		
		roi_full_x_DO   : out std_logic_vector(8 downto 0);		
		roi_full_y_DO   : out std_logic_vector(7 downto 0);
        
        -- debug unit
        dbg_en_SO               : out std_logic;
        dbg_pxl_count_DO        : out std_logic_vector(16 downto 0);
        dbg_pxl_index_DO        : out std_logic_vector(16 downto 0);
        
        
		-- User ports ends
		-- Do not modify the ports beyond this line


		-- Ports of Axi Slave Bus Interface S00_AXI
		s00_axi_aclk	: in std_logic;
		s00_axi_aresetn	: in std_logic;
		s00_axi_awaddr	: in std_logic_vector(C_S00_AXI_ADDR_WIDTH-1 downto 0);
		s00_axi_awprot	: in std_logic_vector(2 downto 0);
		s00_axi_awvalid	: in std_logic;
		s00_axi_awready	: out std_logic;
		s00_axi_wdata	: in std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
		s00_axi_wstrb	: in std_logic_vector((C_S00_AXI_DATA_WIDTH/8)-1 downto 0);
		s00_axi_wvalid	: in std_logic;
		s00_axi_wready	: out std_logic;
		s00_axi_bresp	: out std_logic_vector(1 downto 0);
		s00_axi_bvalid	: out std_logic;
		s00_axi_bready	: in std_logic;
		s00_axi_araddr	: in std_logic_vector(C_S00_AXI_ADDR_WIDTH-1 downto 0);
		s00_axi_arprot	: in std_logic_vector(2 downto 0);
		s00_axi_arvalid	: in std_logic;
		s00_axi_arready	: out std_logic;
		s00_axi_rdata	: out std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
		s00_axi_rresp	: out std_logic_vector(1 downto 0);
		s00_axi_rvalid	: out std_logic;
		s00_axi_rready	: in std_logic
	);
end reg_bank_v1_0;

architecture arch_imp of reg_bank_v1_0 is

    constant TWOPI: integer := 51471;

-- component declaration
	component reg_bank_v1_0_S00_AXI is
		generic (
		C_S_AXI_DATA_WIDTH	: integer	:= 32;
		C_S_AXI_ADDR_WIDTH	: integer	:= 5
		);
		port (
		reset_cc_regs_RI : in std_logic;
        reg_camera_ctrl_mode : out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
        reg_alu_corr : out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
        reg_ambient_comp : out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
        reg_temp_const_val : out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
        reg_dist_dll : out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
        reg_dist_status : in std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
        reg_const_val : out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
        reg_block_en : out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
		ram_read_addr : out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
		reg_mult_fact : out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
		reg_dcs_dma_addr : out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
        reg_gs_dma_addr : out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
        reg_dma_status : in std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
        reg_dma_status_o : out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
		reg_roi : out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
		reg_full_roi : out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
        reg_debug : out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
		S_AXI_ACLK	: in std_logic;
		S_AXI_ARESETN	: in std_logic;
		S_AXI_AWADDR	: in std_logic_vector(C_S_AXI_ADDR_WIDTH-1 downto 0);
		S_AXI_AWPROT	: in std_logic_vector(2 downto 0);
		S_AXI_AWVALID	: in std_logic;
		S_AXI_AWREADY	: out std_logic;
		S_AXI_WDATA	: in std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
		S_AXI_WSTRB	: in std_logic_vector((C_S_AXI_DATA_WIDTH/8)-1 downto 0);
		S_AXI_WVALID	: in std_logic;
		S_AXI_WREADY	: out std_logic;
		S_AXI_BRESP	: out std_logic_vector(1 downto 0);
		S_AXI_BVALID	: out std_logic;
		S_AXI_BREADY	: in std_logic;
		S_AXI_ARADDR	: in std_logic_vector(C_S_AXI_ADDR_WIDTH-1 downto 0);
		S_AXI_ARPROT	: in std_logic_vector(2 downto 0);
		S_AXI_ARVALID	: in std_logic;
		S_AXI_ARREADY	: out std_logic;
		S_AXI_RDATA	: out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
		S_AXI_RRESP	: out std_logic_vector(1 downto 0);
		S_AXI_RVALID	: out std_logic;
		S_AXI_RREADY	: in std_logic
		);
	end component reg_bank_v1_0_S00_AXI;

	signal reg_camera_ctrl_mode : std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
	signal reg_alu_corr         : std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
	signal reg_ambient_comp     : std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
	signal reg_temp_const_val   : std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
	signal reg_dist_dll         : std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
	signal reg_dist_status      : std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
	signal reg_const_val        : std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
	signal reg_block_en         : std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
	signal reg_mult_fact        : std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
	signal tmp_mult_fact_D      : std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
	signal reg_dcs_dma_addr     : std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
    signal reg_gs_dma_addr      : std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
    signal reg_dma_status       : std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
    signal reg_dma_status_o     : std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
    signal reg_roi              : std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
    signal reg_full_roi         : std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
    
    signal reg_debug            : std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
    	
begin

-- Instantiation of Axi Bus Interface S00_AXI
reg_bank_v1_0_S00_AXI_inst : reg_bank_v1_0_S00_AXI
	generic map (
		C_S_AXI_DATA_WIDTH	=> C_S00_AXI_DATA_WIDTH,
		C_S_AXI_ADDR_WIDTH	=> C_S00_AXI_ADDR_WIDTH
	)
	port map (
		reset_cc_regs_RI     => reset_cc_regs_RI,
		reg_camera_ctrl_mode => reg_camera_ctrl_mode,
		reg_alu_corr         => reg_alu_corr        ,
		reg_ambient_comp     => reg_ambient_comp    ,
		reg_temp_const_val   => reg_temp_const_val  ,
		reg_dist_dll         => reg_dist_dll        ,
		reg_dist_status      => reg_dist_status     ,
		reg_const_val        => reg_const_val       ,
		reg_block_en         => reg_block_en        ,
		ram_read_addr        => ram_read_addr_DO,
		reg_mult_fact        => reg_mult_fact,
		reg_dcs_dma_addr     => reg_dcs_dma_addr,
		reg_gs_dma_addr      => reg_gs_dma_addr,
		reg_dma_status       => reg_dma_status,
        reg_dma_status_o     => reg_dma_status_o,
		reg_roi              => reg_roi,
		reg_full_roi         => reg_full_roi,
        reg_debug            => reg_debug,
		S_AXI_ACLK	=> s00_axi_aclk,
		S_AXI_ARESETN	=> s00_axi_aresetn,
		S_AXI_AWADDR	=> s00_axi_awaddr,
		S_AXI_AWPROT	=> s00_axi_awprot,
		S_AXI_AWVALID	=> s00_axi_awvalid,
		S_AXI_AWREADY	=> s00_axi_awready,
		S_AXI_WDATA	=> s00_axi_wdata,
		S_AXI_WSTRB	=> s00_axi_wstrb,
		S_AXI_WVALID	=> s00_axi_wvalid,
		S_AXI_WREADY	=> s00_axi_wready,
		S_AXI_BRESP	=> s00_axi_bresp,
		S_AXI_BVALID	=> s00_axi_bvalid,
		S_AXI_BREADY	=> s00_axi_bready,
		S_AXI_ARADDR	=> s00_axi_araddr,
		S_AXI_ARPROT	=> s00_axi_arprot,
		S_AXI_ARVALID	=> s00_axi_arvalid,
		S_AXI_ARREADY	=> s00_axi_arready,
		S_AXI_RDATA	=> s00_axi_rdata,
		S_AXI_RRESP	=> s00_axi_rresp,
		S_AXI_RVALID	=> s00_axi_rvalid,
		S_AXI_RREADY	=> s00_axi_rready
	);

	-- Add user logic here
		cc_rst_RO <= reg_camera_ctrl_mode(0);
		cc_update_reg_values_SO <= reg_camera_ctrl_mode(1);
		cc_mode_SO <= reg_camera_ctrl_mode(4 downto 2);
		cc_init_bad_pix_SO <= reg_camera_ctrl_mode(5);
		cc_line_length_DO <= reg_camera_ctrl_mode(14 downto 6);
		cc_data_length_DO <= reg_camera_ctrl_mode(31 downto 15);
		-- reg_alu_corr
		alu_amp_corr_DO <= reg_alu_corr(11 downto 0);
		alu_dist_corr_DO <= reg_alu_corr(23 downto 12);
		alu_min_index_DO <= reg_alu_corr(31 downto 24);
		-- reg_ambient_comp
		ambient_comp_DO <= reg_ambient_comp(15 downto 0);
		-- reg_temp_const_val
		temp_const_val_DO <= reg_temp_const_val(16 downto 0);
        -- reg_dist_dll 
		dist_dll_DO <= reg_dist_dll(15 downto 0);
		nb_dll_steps_DO <= reg_dist_dll(16+NBITS_DLL_STEPS-1 downto 16);
        -- reg_dist_status 
		reg_dist_status(26 downto 19) <= dist_index_trunc_DI;
		reg_dist_status(18) <= dist_index_low_SI;
		reg_dist_status(17) <= dist_index_high_SI;
		reg_dist_status(16 downto 0) <= dist_fail_pos_DI;
        -- reg_const_val
		const_val_DO <= reg_const_val(16 downto 0);
		-- reg_block_en
		cc_en_SO <= reg_block_en(0);
		temp_comp_en_SO <= reg_block_en(1);
		dist_corr_en_SO <= reg_block_en(2);
		comp_en_SO <= reg_block_en(3);
		adc_udrflow_en_SO <= reg_block_en(4);
		adc_ovrflow_en_SO <= reg_block_en(5);
		gs_subtract_en_SO <= reg_block_en(6);
		image_bin_en_SO <= reg_block_en(7);
		ambient_en_SO <= reg_block_en(8);
		pix_inter_dcs_en_SO <= reg_block_en(9);
		pix_inter_dist_en_SO <= reg_block_en(10);
		image_bin_rem_sat_SO <= reg_block_en(11);
		adc_inter_en_SO <= reg_block_en(12);
		gs_comp_en_SO <= reg_block_en(13);
		-- out mult fact
		tmp_mult_fact_D <= std_logic_vector(unsigned(reg_mult_fact(15 downto 0)& (15 downto 0 => '0'))/to_unsigned(TWOPI,16));
		mult_fact_DO <= tmp_mult_fact_D(15 downto 0);
		max_out_val_DO <= reg_mult_fact(15 downto 0);
		interf_thr_DO <= reg_mult_fact(28 downto 16);
		dcs_dma_addr_DO <= reg_dcs_dma_addr;
        gs_dma_addr_DO  <= reg_gs_dma_addr;
        reg_dma_status(0) <= dcs_dma_rdy_DI;
        reg_dma_status(1) <= dcs_dma_busy_DI; 
        reg_dma_status(2) <= dcs_dma_done_DI; 
        reg_dma_status(4) <= gs_dma_rdy_DI;
        reg_dma_status(5) <= gs_dma_busy_DI; 
        reg_dma_status(6) <= gs_dma_done_DI; 
        
        -- set/reset registers
        p_rs : process (s00_axi_aclk)
        begin
            if rising_edge(s00_axi_aclk) then
                if s00_axi_aresetn = '0' then
                    reg_dma_status(12) <= '0';
                    reg_dma_status(13) <= '0';
                else
                    -- dcs_wr_eof_done_SI
                    if reg_dma_status_o(12) = '1' then
                        reg_dma_status(12) <= '0';
                    elsif dcs_wr_eof_done_SI = '1' then
                        reg_dma_status(12) <= '1';
                    end if;
                    
                    -- gs_wr_eof_done_SI
                    if reg_dma_status_o(13) = '1' then
                        reg_dma_status(13) <= '0';
                    elsif gs_wr_eof_done_SI = '1' then
                        reg_dma_status(13) <= '1';
                    end if;        
                end if;
            end if;
        end process p_rs;
        
		roi_tl_x_DO <= reg_roi(8 downto 0);
		roi_br_x_DO <= reg_roi(17 downto 9);		
		roi_tl_y_DO <= reg_roi(24 downto 18);
		roi_br_y_DO <= reg_roi(31 downto 25);	
		roi_full_x_DO <= reg_full_roi(8 downto 0);	
		roi_full_y_DO <= reg_full_roi(16 downto 9);
        
        -- debug unit
        dbg_en_SO               <= reg_debug(0);
        dbg_pxl_count_DO        <= reg_camera_ctrl_mode(31 downto 15);
        dbg_pxl_index_DO        <= reg_debug(31 downto 15);
        
        
	-- User logic ends

end arch_imp;
