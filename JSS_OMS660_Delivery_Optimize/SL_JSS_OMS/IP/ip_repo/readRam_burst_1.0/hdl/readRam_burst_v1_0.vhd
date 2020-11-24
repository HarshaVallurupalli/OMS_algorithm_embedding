library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity readRam_burst_v1_0 is
	generic (
		-- Users to add parameters here
		NBITS_RAM         : integer := 4;
		NBITS_ADDR        : integer := 6;
		NBITS_DATA        : integer := 128;
		NBITS_DLL_STEPS   : integer := 8;
		NBITS_ROI_X       : integer := 9;
		NBITS_ROI_Y       : integer := 7;
		NBITS_DATA_LENGTH : integer := 17;
		-- User parameters ends
		-- Do not modify the parameters beyond this line

		-- Parameters of Axi Master Bus Interface M00_AXI
		C_M00_AXI_TARGET_SLAVE_BASE_ADDR : std_logic_vector	:= x"40000000";
		C_M00_AXI_BURST_LEN	             : integer	:= 2;
		C_M00_AXI_ID_WIDTH	             : integer	:= 1;
		C_M00_AXI_ADDR_WIDTH	         : integer	:= 32;
		C_M00_AXI_DATA_WIDTH	         : integer	:= 64;
		C_M00_AXI_AWUSER_WIDTH	         : integer	:= 0;
		C_M00_AXI_ARUSER_WIDTH	         : integer	:= 0;
		C_M00_AXI_WUSER_WIDTH	         : integer	:= 0;
		C_M00_AXI_RUSER_WIDTH	         : integer	:= 0;
		C_M00_AXI_BUSER_WIDTH	         : integer	:= 0
	);
	port (
		-- Users to add ports here
		clk_CI            : in  std_logic;
        enable_SI         : in  std_logic;
		ram_pulse_DI      : in  std_logic;
		ram_data_DO       : out std_logic_vector(NBITS_DATA-1 downto 0);
        ram_addr_DI       : in  std_logic_vector(C_M00_AXI_ADDR_WIDTH-1 downto 0);
		ram_index_DI      : in  std_logic_vector(NBITS_RAM-1 downto 0);
		nbofdllsteps_DI   : in  std_logic_vector(NBITS_DLL_STEPS-1 downto 0);
		roi_tl_x_DI       : in  std_logic_vector(NBITS_ROI_X-1 downto 0);
		roi_br_x_DI       : in  std_logic_vector(NBITS_ROI_X-1 downto 0);		
		roi_tl_y_DI       : in  std_logic_vector(NBITS_ROI_Y-1 downto 0);
		roi_br_y_DI       : in  std_logic_vector(NBITS_ROI_Y-1 downto 0);
		roi_full_x_DI     : in  std_logic_vector(NBITS_ROI_X-1 downto 0);
		roi_full_y_DI     : in  std_logic_vector(NBITS_ROI_Y   downto 0); 
		read_pulse_out_DO : out std_logic;
		-- User ports ends
		-- Do not modify the ports beyond this line

		-- Ports of Axi Master Bus Interface M00_AXI
		m00_axi_aclk	: in std_logic;
		m00_axi_aresetn	: in std_logic;
		m00_axi_awid	: out std_logic_vector(C_M00_AXI_ID_WIDTH-1 downto 0);
		m00_axi_awaddr	: out std_logic_vector(C_M00_AXI_ADDR_WIDTH-1 downto 0);
		m00_axi_awlen	: out std_logic_vector(7 downto 0);
		m00_axi_awsize	: out std_logic_vector(2 downto 0);
		m00_axi_awburst	: out std_logic_vector(1 downto 0);
		m00_axi_awlock	: out std_logic;
		m00_axi_awcache	: out std_logic_vector(3 downto 0);
		m00_axi_awprot	: out std_logic_vector(2 downto 0);
		m00_axi_awqos	: out std_logic_vector(3 downto 0);
		m00_axi_awuser	: out std_logic_vector(C_M00_AXI_AWUSER_WIDTH-1 downto 0);
		m00_axi_awvalid	: out std_logic;
		m00_axi_awready	: in std_logic;
		m00_axi_wdata	: out std_logic_vector(C_M00_AXI_DATA_WIDTH-1 downto 0);
		m00_axi_wstrb	: out std_logic_vector(C_M00_AXI_DATA_WIDTH/8-1 downto 0);
		m00_axi_wlast	: out std_logic;
		m00_axi_wuser	: out std_logic_vector(C_M00_AXI_WUSER_WIDTH-1 downto 0);
		m00_axi_wvalid	: out std_logic;
		m00_axi_wready	: in std_logic;
		m00_axi_bid	: in std_logic_vector(C_M00_AXI_ID_WIDTH-1 downto 0);
		m00_axi_bresp	: in std_logic_vector(1 downto 0);
		m00_axi_buser	: in std_logic_vector(C_M00_AXI_BUSER_WIDTH-1 downto 0);
		m00_axi_bvalid	: in std_logic;
		m00_axi_bready	: out std_logic;
		m00_axi_arid	: out std_logic_vector(C_M00_AXI_ID_WIDTH-1 downto 0);
		m00_axi_araddr	: out std_logic_vector(C_M00_AXI_ADDR_WIDTH-1 downto 0);
		m00_axi_arlen	: out std_logic_vector(7 downto 0);
		m00_axi_arsize	: out std_logic_vector(2 downto 0);
		m00_axi_arburst	: out std_logic_vector(1 downto 0);
		m00_axi_arlock	: out std_logic;
		m00_axi_arcache	: out std_logic_vector(3 downto 0);
		m00_axi_arprot	: out std_logic_vector(2 downto 0);
		m00_axi_arqos	: out std_logic_vector(3 downto 0);
		m00_axi_aruser	: out std_logic_vector(C_M00_AXI_ARUSER_WIDTH-1 downto 0);
		m00_axi_arvalid	: out std_logic;
		m00_axi_arready	: in std_logic;
		m00_axi_rid	: in std_logic_vector(C_M00_AXI_ID_WIDTH-1 downto 0);
		m00_axi_rdata	: in std_logic_vector(C_M00_AXI_DATA_WIDTH-1 downto 0);
		m00_axi_rresp	: in std_logic_vector(1 downto 0);
		m00_axi_rlast	: in std_logic;
		m00_axi_ruser	: in std_logic_vector(C_M00_AXI_RUSER_WIDTH-1 downto 0);
		m00_axi_rvalid	: in std_logic;
		m00_axi_rready	: out std_logic
	);
end readRam_burst_v1_0;

architecture arch_imp of readRam_burst_v1_0 is

	-- component declaration
	component readRam_burst_v1_0_M00_AXI is
		generic (
		NBITS_INDEX  : integer := 2;
		C_M_TARGET_SLAVE_BASE_ADDR	: std_logic_vector	:= x"40000000";
		C_M_AXI_BURST_LEN	: integer	:= 2;
		C_M_AXI_ID_WIDTH	: integer	:= 1;
		C_M_AXI_ADDR_WIDTH	: integer	:= 32;
		C_M_AXI_DATA_WIDTH	: integer	:= 64;
		C_M_AXI_AWUSER_WIDTH	: integer	:= 0;
		C_M_AXI_ARUSER_WIDTH	: integer	:= 0;
		C_M_AXI_WUSER_WIDTH	: integer	:= 0;
		C_M_AXI_RUSER_WIDTH	: integer	:= 0;
		C_M_AXI_BUSER_WIDTH	: integer	:= 0
		);
		port (
		read_addr_DI  : in std_logic_vector(C_M_AXI_ADDR_WIDTH-1 downto 0);
        read_pulse_DI : in std_logic;
        read_data_DO  : out std_logic_vector(C_M_AXI_DATA_WIDTH-1 downto 0);
		read_tlast_DO : out std_logic;
		read_rvalid_DO : out std_logic;
		M_AXI_ACLK	: in std_logic;
		M_AXI_ARESETN	: in std_logic;
		M_AXI_ARID	: out std_logic_vector(C_M_AXI_ID_WIDTH-1 downto 0);
		M_AXI_ARADDR	: out std_logic_vector(C_M_AXI_ADDR_WIDTH-1 downto 0);
		M_AXI_ARLEN	: out std_logic_vector(7 downto 0);
		M_AXI_ARSIZE	: out std_logic_vector(2 downto 0);
		M_AXI_ARBURST	: out std_logic_vector(1 downto 0);
		M_AXI_ARLOCK	: out std_logic;
		M_AXI_ARCACHE	: out std_logic_vector(3 downto 0);
		M_AXI_ARPROT	: out std_logic_vector(2 downto 0);
		M_AXI_ARQOS	: out std_logic_vector(3 downto 0);
		M_AXI_ARUSER	: out std_logic_vector(C_M_AXI_ARUSER_WIDTH-1 downto 0);
		M_AXI_ARVALID	: out std_logic;
		M_AXI_ARREADY	: in std_logic;
		M_AXI_RID	: in std_logic_vector(C_M_AXI_ID_WIDTH-1 downto 0);
		M_AXI_RDATA	: in std_logic_vector(C_M_AXI_DATA_WIDTH-1 downto 0);
		M_AXI_RRESP	: in std_logic_vector(1 downto 0);
		M_AXI_RLAST	: in std_logic;
		M_AXI_RUSER	: in std_logic_vector(C_M_AXI_RUSER_WIDTH-1 downto 0);
		M_AXI_RVALID	: in std_logic;
		M_AXI_RREADY	: out std_logic
		);
	end component readRam_burst_v1_0_M00_AXI;
	
	signal read_addr_D           : std_logic_vector(C_M00_AXI_ADDR_WIDTH-1 downto 0);
    signal read_data_D           : std_logic_vector(C_M00_AXI_DATA_WIDTH-1 downto 0);
	signal read_pulse_D          : std_logic;
	signal read_pulse_d1_D       : std_logic;
	--signal read_pulse_d2_D       : std_logic;
	--signal read_pulse_d3_D       : std_logic;
	--signal read_pulse_d4_D       : std_logic;
	signal read_tlast_D          : std_logic;
	signal read_rvalid_D         : std_logic;
 	signal pixel_cnt_D           : unsigned(NBITS_DATA_LENGTH-1 downto 0);
    signal pixel_cnt_start_D     : unsigned(NBITS_DATA_LENGTH-1 downto 0);
	signal pixel_cnt_start_del_D : unsigned(NBITS_DATA_LENGTH-1 downto 0);
	signal pixel_cnt_line_wrap_D : unsigned(NBITS_ROI_X-1 downto 0);

begin

-- Instantiation of Axi Bus Interface M00_AXI
readRam_burst_v1_0_M00_AXI_inst : readRam_burst_v1_0_M00_AXI
	generic map (
		C_M_TARGET_SLAVE_BASE_ADDR	=> C_M00_AXI_TARGET_SLAVE_BASE_ADDR,
		C_M_AXI_BURST_LEN	=> C_M00_AXI_BURST_LEN,
		C_M_AXI_ID_WIDTH	=> C_M00_AXI_ID_WIDTH,
		C_M_AXI_ADDR_WIDTH	=> C_M00_AXI_ADDR_WIDTH,
		C_M_AXI_DATA_WIDTH	=> C_M00_AXI_DATA_WIDTH,
		C_M_AXI_AWUSER_WIDTH	=> C_M00_AXI_AWUSER_WIDTH,
		C_M_AXI_ARUSER_WIDTH	=> C_M00_AXI_ARUSER_WIDTH,
		C_M_AXI_WUSER_WIDTH	=> C_M00_AXI_WUSER_WIDTH,
		C_M_AXI_RUSER_WIDTH	=> C_M00_AXI_RUSER_WIDTH,
		C_M_AXI_BUSER_WIDTH	=> C_M00_AXI_BUSER_WIDTH
	)
	port map (
	    read_pulse_DI => read_pulse_D,
	    read_addr_DI  => read_addr_D,
	    read_data_DO  => read_data_D,
		read_tlast_DO => read_tlast_D,
		read_rvalid_DO => read_rvalid_D,
		M_AXI_ACLK	=> m00_axi_aclk,
		M_AXI_ARESETN	=> m00_axi_aresetn,
		M_AXI_ARID	=> m00_axi_arid,
		M_AXI_ARADDR	=> m00_axi_araddr,
		M_AXI_ARLEN	=> m00_axi_arlen,
		M_AXI_ARSIZE	=> m00_axi_arsize,
		M_AXI_ARBURST	=> m00_axi_arburst,
		M_AXI_ARLOCK	=> m00_axi_arlock,
		M_AXI_ARCACHE	=> m00_axi_arcache,
		M_AXI_ARPROT	=> m00_axi_arprot,
		M_AXI_ARQOS	=> m00_axi_arqos,
		M_AXI_ARUSER	=> m00_axi_aruser,
		M_AXI_ARVALID	=> m00_axi_arvalid,
		M_AXI_ARREADY	=> m00_axi_arready,
		M_AXI_RID	=> m00_axi_rid,
		M_AXI_RDATA	=> m00_axi_rdata,
		M_AXI_RRESP	=> m00_axi_rresp,
		M_AXI_RLAST	=> m00_axi_rlast,
		M_AXI_RUSER	=> m00_axi_ruser,
		M_AXI_RVALID	=> m00_axi_rvalid,
		M_AXI_RREADY	=> m00_axi_rready
	);

	-- Handle read_addr; Gated with read_pulse_d3_D to have a multicycle path of 2
    process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if enable_SI = '0' then
				read_addr_D <= (others => '0');
			elsif ram_pulse_DI = '1' then
				read_addr_D <= std_logic_vector(unsigned(ram_addr_DI)+(unsigned(ram_index_DI & "00"))+unsigned(std_logic_vector((pixel_cnt_D*unsigned(nbofdllsteps_DI))) & '0'));
            end if;
        end if;
    end process;
	
	-- Handle ROI
    process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if enable_SI = '0' then
                pixel_cnt_start_D     <= (others => '0');
				pixel_cnt_line_wrap_D <= (others => '0');
				pixel_cnt_start_del_D <= (others => '0');
            else
				if unsigned(roi_full_y_DI) > 0 and unsigned(roi_full_x_DI) > 0 then -- if full roi is set to 0, no roi is selected
					pixel_cnt_start_del_D <= pixel_cnt_start_D;
					pixel_cnt_start_D     <= unsigned('0' & roi_full_x_DI)*(unsigned(roi_full_y_DI(NBITS_ROI_Y downto 1))-unsigned(roi_br_y_DI))+unsigned(roi_tl_x_DI);
					pixel_cnt_line_wrap_D <= unsigned(roi_full_x_DI)-unsigned(roi_br_x_DI)+unsigned(roi_tl_x_DI);
				else
					pixel_cnt_start_D     <= (others => '0');
					pixel_cnt_line_wrap_D <= (others => '0');
					pixel_cnt_line_wrap_D(0) <= '1';
					pixel_cnt_start_del_D <= (others => '0');				
				end if;
            end if;
        end if;
    end process;	
	
	-- Update pixel count
    process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if enable_SI = '0' then
                pixel_cnt_D  <= (others => '0');
				read_pulse_d1_D <= '0';
				--read_pulse_d2_D <= '0';
				--read_pulse_d3_D <= '0';
				--read_pulse_d4_D <= '0';
            else
				read_pulse_d1_D <= ram_pulse_DI;
				--read_pulse_d2_D <= read_pulse_d1_D;
				--read_pulse_d3_D <= read_pulse_d2_D;
				--read_pulse_d4_D <= read_pulse_d3_D;
				if pixel_cnt_start_D /= pixel_cnt_start_del_D then
					-- Init pixel_cnt_D to start value if ROI is changed
					pixel_cnt_D <= pixel_cnt_start_D;
				elsif ram_pulse_DI = '1' then
					if unsigned(roi_full_y_DI) > 0 and unsigned(roi_full_x_DI) > 0 then
						-- Update pixel cnt depending on ROI => if last element of line, add offset
						if to_integer(pixel_cnt_D) mod to_integer(unsigned(roi_full_x_DI)) = to_integer(unsigned(roi_br_x_DI)) then
							pixel_cnt_D <= pixel_cnt_D + pixel_cnt_line_wrap_D;
						else
							pixel_cnt_D <= pixel_cnt_D + 1;
						end if;
					else -- if ROI not selected, always count up one
						pixel_cnt_D <= pixel_cnt_D + 1;
					end if;
				end if;
            end if;
        end if;
    end process;
	
	read_pulse_D <= read_pulse_d1_D;
	
	-- Handle Outputs
	process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if enable_SI = '0' then
                ram_data_DO <= (others => '0');
				read_pulse_out_DO <= '0';
            else
				if read_tlast_D = '1' then
					ram_data_DO(NBITS_DATA-1 downto NBITS_DATA/2) <= read_data_D;
					read_pulse_out_DO <= '1';
				elsif read_rvalid_D = '1' then
					ram_data_DO(NBITS_DATA/2-1 downto 0) <= read_data_D;
					read_pulse_out_DO <= '0';
				else
				    read_pulse_out_DO <= '0'; 
				end if;
            end if;
        end if;
    end process;	
	

end arch_imp;