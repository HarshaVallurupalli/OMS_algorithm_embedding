library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity data2ram_v1_0 is
	generic (
		-- Users to add parameters here
        NBITS_INPUT : integer := 32;
        NBITS_LENGTH : integer := 17;
        NBITS_BRAM_ADDR : integer := 11;
		NBITS_RNEXT_DEL : integer := 3;
		PRELOAD_RD_PULSE : boolean := true;
		-- User parameters ends
		-- Do not modify the parameters beyond this line

		-- Parameters of Axi Master Bus Interface M00_AXI
		C_M00_AXI_BURST_LEN	: integer	:= 16;
		C_M00_AXI_ID_WIDTH	: integer	:= 1;
		C_M00_AXI_ADDR_WIDTH	: integer	:= 32;
		C_M00_AXI_DATA_WIDTH	: integer	:= 32
	);
	port (
		-- Users to add ports here
        clk_CI : in std_logic;
        data_DI : in std_logic_vector(NBITS_INPUT-1 downto 0);
        pulse_in_DI : in std_logic;
        data_DO : out std_logic_vector(NBITS_INPUT-1 downto 0);
        pulse_out_DI : in std_logic;
        -- From/To reg bank
        enable_DI : in std_logic;
        wr_en_SI : in std_logic;
        length_DI : in std_logic_vector(NBITS_LENGTH-1 downto 0);
        addr_DI : in std_logic_vector(31 downto 0);
        dma_rdy_SO : out std_logic;
        dma_busy_SO : out std_logic;
        dma_done_SO : out std_logic;
        wr_eof_done_SO : out std_logic; -- end of frame completely written to memory
        
        -- From/To BRAM
        wr_addr_DO : out std_logic_vector(NBITS_BRAM_ADDR-1 downto 0);
        wr_data_DO : out std_logic_vector(NBITS_INPUT-1 downto 0);
        wr_en_DO   : out std_logic;
        rd_addr_DO : out std_logic_vector(NBITS_BRAM_ADDR-1 downto 0);
        rd_data_DI : in  std_logic_vector(NBITS_INPUT-1 downto 0);
        rd_en_DO   : out std_logic;     
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
		m00_axi_awvalid	: out std_logic;
		m00_axi_awready	: in std_logic;
		m00_axi_wdata	: out std_logic_vector(C_M00_AXI_DATA_WIDTH-1 downto 0);
		m00_axi_wstrb	: out std_logic_vector(C_M00_AXI_DATA_WIDTH/8-1 downto 0);
		m00_axi_wlast	: out std_logic;
		m00_axi_wvalid	: out std_logic;
		m00_axi_wready	: in std_logic;
		m00_axi_bid	: in std_logic_vector(C_M00_AXI_ID_WIDTH-1 downto 0);
		m00_axi_bresp	: in std_logic_vector(1 downto 0);
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
		m00_axi_arvalid	: out std_logic;
		m00_axi_arready	: in std_logic;
		m00_axi_rid	: in std_logic_vector(C_M00_AXI_ID_WIDTH-1 downto 0);
		m00_axi_rdata	: in std_logic_vector(C_M00_AXI_DATA_WIDTH-1 downto 0);
		m00_axi_rresp	: in std_logic_vector(1 downto 0);
		m00_axi_rlast	: in std_logic;
		m00_axi_rvalid	: in std_logic;
		m00_axi_rready	: out std_logic
	);
end data2ram_v1_0;

architecture arch_imp of data2ram_v1_0 is

	-- component declaration
	component data2ram_v1_0_M00_AXI is
		generic (
		NBITS_INPUT : integer := 32;
        NBITS_LENGTH : integer := 17;
		NBITS_WNEXT_DEL : integer := 4;
		NBITS_RNEXT_DEL : integer := 3;
		C_M_AXI_BURST_LEN	: integer	:= 16;
		C_M_AXI_ID_WIDTH	: integer	:= 1;
		C_M_AXI_ADDR_WIDTH	: integer	:= 32;
		C_M_AXI_DATA_WIDTH	: integer	:= 32
		);
		port (
		addr_DI : in std_logic_vector(31 downto 0);
		data_DI : in std_logic_vector(NBITS_INPUT-1 downto 0);
		data_DO : out std_logic_vector(NBITS_INPUT-1 downto 0);
		pulse_DO : out std_logic;
		wr_en_SI : in std_logic;
		init_txn_pulse : in std_logic;
		wr_valid : in std_logic;
		rd_valid : in std_logic;
		set_tlast : in std_logic;
		wr_busy : out std_logic;
        rd_busy : out std_logic;
		M_AXI_ACLK	: in std_logic;
		M_AXI_ARESETN	: in std_logic;
		M_AXI_AWID	: out std_logic_vector(C_M_AXI_ID_WIDTH-1 downto 0);
		M_AXI_AWADDR	: out std_logic_vector(C_M_AXI_ADDR_WIDTH-1 downto 0);
		M_AXI_AWLEN	: out std_logic_vector(7 downto 0);
		M_AXI_AWSIZE	: out std_logic_vector(2 downto 0);
		M_AXI_AWBURST	: out std_logic_vector(1 downto 0);
		M_AXI_AWLOCK	: out std_logic;
		M_AXI_AWCACHE	: out std_logic_vector(3 downto 0);
		M_AXI_AWPROT	: out std_logic_vector(2 downto 0);
		M_AXI_AWQOS	: out std_logic_vector(3 downto 0);
		M_AXI_AWVALID	: out std_logic;
		M_AXI_AWREADY	: in std_logic;
		M_AXI_WDATA	: out std_logic_vector(C_M_AXI_DATA_WIDTH-1 downto 0);
		M_AXI_WSTRB	: out std_logic_vector(C_M_AXI_DATA_WIDTH/8-1 downto 0);
		M_AXI_WLAST	: out std_logic;
		M_AXI_WVALID	: out std_logic;
		M_AXI_WREADY	: in std_logic;
		M_AXI_BID	: in std_logic_vector(C_M_AXI_ID_WIDTH-1 downto 0);
		M_AXI_BRESP	: in std_logic_vector(1 downto 0);
		M_AXI_BVALID	: in std_logic;
		M_AXI_BREADY	: out std_logic;
		M_AXI_ARID	: out std_logic_vector(C_M_AXI_ID_WIDTH-1 downto 0);
		M_AXI_ARADDR	: out std_logic_vector(C_M_AXI_ADDR_WIDTH-1 downto 0);
		M_AXI_ARLEN	: out std_logic_vector(7 downto 0);
		M_AXI_ARSIZE	: out std_logic_vector(2 downto 0);
		M_AXI_ARBURST	: out std_logic_vector(1 downto 0);
		M_AXI_ARLOCK	: out std_logic;
		M_AXI_ARCACHE	: out std_logic_vector(3 downto 0);
		M_AXI_ARPROT	: out std_logic_vector(2 downto 0);
		M_AXI_ARQOS	: out std_logic_vector(3 downto 0);
		M_AXI_ARVALID	: out std_logic;
		M_AXI_ARREADY	: in std_logic;
		M_AXI_RID	: in std_logic_vector(C_M_AXI_ID_WIDTH-1 downto 0);
		M_AXI_RDATA	: in std_logic_vector(C_M_AXI_DATA_WIDTH-1 downto 0);
		M_AXI_RRESP	: in std_logic_vector(1 downto 0);
		M_AXI_RLAST	: in std_logic;
		M_AXI_RVALID	: in std_logic;
		M_AXI_RREADY	: out std_logic
		);
	end component data2ram_v1_0_M00_AXI;
	
	signal bram_wr_cnt : unsigned(NBITS_BRAM_ADDR-1 downto 0);
	signal bram_rd_cnt : unsigned(NBITS_BRAM_ADDR-1 downto 0);
	signal max_cnt     : unsigned(NBITS_BRAM_ADDR-1 downto 0) := (others => '1');
	signal data_cnt    : unsigned(NBITS_LENGTH-1 downto 0);
	signal axi_wrdata  : std_logic_vector(NBITS_INPUT-1 downto 0);
	signal axi_pulse_D : std_logic;
	signal rd_en_D     : std_logic;
	signal wr_en_D     : std_logic;
	signal wr_en_del   : std_logic;
	signal rd_en_reg_D : std_logic;
	signal wr_en_reg_D : std_logic;
	signal init_txn_pulse : std_logic;
	signal dma_rdy_del : std_logic;
	signal dma_busy_del : std_logic;
	signal dma_rdy_S  : std_logic;
	signal dma_busy_S  : std_logic;
	signal dma_done_S  : std_logic;
	signal wr_valid : std_logic;
	signal rd_valid : std_logic;
	signal rd_first_D : std_logic;
	signal rd_second_D : std_logic;
	signal rd_first_done : std_logic;
	signal init_done_S : std_logic;
	
	signal transfer_rest : unsigned(7 downto 0);
	signal set_tlast : std_logic;
	signal set_tlast_done : std_logic;
	signal start_rd_S : std_logic;
	signal start_rd_del_S : std_logic;
	signal start_rd_d2_S  : std_logic;
	signal wr_busy : std_logic;
	signal rd_busy : std_logic;
    
    -- end of frame detection
    signal WrEof_Wait4Axi   : std_logic;
    signal WrEof_Done       : std_logic;
    
begin

-- Instantiation of Axi Bus Interface M00_AXI
data2ram_v1_0_M00_AXI_inst : data2ram_v1_0_M00_AXI
	generic map (
	    NBITS_INPUT => NBITS_INPUT,
        NBITS_LENGTH => NBITS_LENGTH,
		NBITS_WNEXT_DEL => 4, -- fixed to atleast 4
		NBITS_RNEXT_DEL => NBITS_RNEXT_DEL,
		C_M_AXI_BURST_LEN	=> C_M00_AXI_BURST_LEN,
		C_M_AXI_ID_WIDTH	=> C_M00_AXI_ID_WIDTH,
		C_M_AXI_ADDR_WIDTH	=> C_M00_AXI_ADDR_WIDTH,
		C_M_AXI_DATA_WIDTH	=> C_M00_AXI_DATA_WIDTH
	)
	port map (
        addr_DI => addr_DI,
		data_DI => rd_data_DI,
		data_DO => axi_wrdata,
		pulse_DO => axi_pulse_D,
		wr_en_SI => wr_en_SI,
		init_txn_pulse => init_txn_pulse,
		wr_valid => wr_valid,
		rd_valid => rd_valid,
		set_tlast => set_tlast,
	    wr_busy => wr_busy,
        rd_busy => rd_busy,
		M_AXI_ACLK	=> m00_axi_aclk,
		M_AXI_ARESETN	=> m00_axi_aresetn,
		M_AXI_AWID	=> m00_axi_awid,
		M_AXI_AWADDR	=> m00_axi_awaddr,
		M_AXI_AWLEN	=> m00_axi_awlen,
		M_AXI_AWSIZE	=> m00_axi_awsize,
		M_AXI_AWBURST	=> m00_axi_awburst,
		M_AXI_AWLOCK	=> m00_axi_awlock,
		M_AXI_AWCACHE	=> m00_axi_awcache,
		M_AXI_AWPROT	=> m00_axi_awprot,
		M_AXI_AWQOS	=> m00_axi_awqos,
		M_AXI_AWVALID	=> m00_axi_awvalid,
		M_AXI_AWREADY	=> m00_axi_awready,
		M_AXI_WDATA	=> m00_axi_wdata,
		M_AXI_WSTRB	=> m00_axi_wstrb,
		M_AXI_WLAST	=> m00_axi_wlast,
		M_AXI_WVALID	=> m00_axi_wvalid,
		M_AXI_WREADY	=> m00_axi_wready,
		M_AXI_BID	=> m00_axi_bid,
		M_AXI_BRESP	=> m00_axi_bresp,
		M_AXI_BVALID	=> m00_axi_bvalid,
		M_AXI_BREADY	=> m00_axi_bready,
		M_AXI_ARID	=> m00_axi_arid,
		M_AXI_ARADDR	=> m00_axi_araddr,
		M_AXI_ARLEN	=> m00_axi_arlen,
		M_AXI_ARSIZE	=> m00_axi_arsize,
		M_AXI_ARBURST	=> m00_axi_arburst,
		M_AXI_ARLOCK	=> m00_axi_arlock,
		M_AXI_ARCACHE	=> m00_axi_arcache,
		M_AXI_ARPROT	=> m00_axi_arprot,
		M_AXI_ARQOS	=> m00_axi_arqos,
		M_AXI_ARVALID	=> m00_axi_arvalid,
		M_AXI_ARREADY	=> m00_axi_arready,
		M_AXI_RID	=> m00_axi_rid,
		M_AXI_RDATA	=> m00_axi_rdata,
		M_AXI_RRESP	=> m00_axi_rresp,
		M_AXI_RLAST	=> m00_axi_rlast,
		M_AXI_RVALID	=> m00_axi_rvalid,
		M_AXI_RREADY	=> m00_axi_rready
	);
	
	-- Assign BRAM address
	wr_addr_DO <= std_logic_vector(bram_wr_cnt);
	rd_addr_DO <= std_logic_vector(bram_rd_cnt);
	
	process(wr_en_SI, axi_pulse_D, wr_en_reg_D, rd_en_reg_D, rd_first_D, rd_second_D)
	begin
		if wr_en_SI = '1' then
		    if PRELOAD_RD_PULSE = true then
			  rd_en_D <= axi_pulse_D or rd_first_D;
			else
			  rd_en_D <= axi_pulse_D;
			end if;
			wr_en_D <= wr_en_reg_D;
		else
		    if PRELOAD_RD_PULSE = true then
		      rd_en_D <= rd_en_reg_D or rd_first_D or rd_second_D;
		    else
		      rd_en_D <= rd_en_reg_D;
		    end if;
			wr_en_D <= axi_pulse_D;
		end if;
	end process;

	-- Connect signals depending on R/W
	process(clk_CI)
	begin
		if rising_edge(clk_CI) then
			if (enable_DI = '0') then
					wr_data_DO   <= (others => '0');
					data_DO      <= (others => '0');		
					bram_wr_cnt  <= (others => '0');
					bram_rd_cnt  <= (others => '0');
					data_cnt     <= (others => '0');
					rd_en_reg_D  <= '0';
					wr_en_reg_D  <= '0';
					set_tlast    <= '0';
					set_tlast_done <= '0';
					wr_en_del    <= '0';
					rd_first_D   <= '0';
					rd_second_D  <= '0';
					rd_first_done <= '0';
					start_rd_S   <= '0';
					start_rd_del_S <= '0';
					start_rd_d2_S <= '0';
			elsif (wr_en_SI /= wr_en_del) then -- reset bram counter
					wr_en_del    <= wr_en_SI;
					wr_data_DO   <= (others => '0');
					data_DO      <= (others => '0');		
					bram_wr_cnt  <= (others => '0');
					bram_rd_cnt  <= (others => '0');
					data_cnt     <= (others => '0');
					rd_en_reg_D  <= '0';
					wr_en_reg_D  <= '0';
					set_tlast    <= '0';	
					set_tlast_done <= '0';
					rd_first_D   <= '0';
					rd_second_D  <= '0';
					rd_first_done <= '0';			
					start_rd_S   <= '0';
					start_rd_del_S <= '0';		
					start_rd_d2_S <= '0';					
			else
			    rd_second_D <= rd_first_D;
				if wr_en_SI = '0' then
					start_rd_S <= '1';
				else
					start_rd_S <= '0';
				end if;
				start_rd_del_S <= start_rd_S;
				start_rd_d2_S <= start_rd_del_S;
				wr_en_del <= wr_en_SI;
				if (wr_en_SI = '1') then
					if rd_first_done = '1' then
						rd_first_D   <= '0'; -- default assignement
					end if;
					wr_data_DO <= data_DI;
					wr_en_reg_D <= pulse_in_DI;
					if wr_en_reg_D = '1' then
						bram_wr_cnt <= bram_wr_cnt + 1;
						-- Check if first read done
						if rd_first_done = '0' and bram_wr_cnt > 1 then
							rd_first_D   <= '1';
							rd_first_done <= '1';
						end if;
					end if;
					if (data_cnt < unsigned(length_DI)) and (rd_en_D = '1') then
						data_cnt <= data_cnt + 1;
						bram_rd_cnt <= bram_rd_cnt + 1;
					else
					    if (data_cnt = unsigned(length_DI) and dma_done_S = '1' and set_tlast_done = '0') then
                            set_tlast <= '1';
							set_tlast_done <= '1';
                        else
                            set_tlast <= '0';
                        end if;
					end if;
				else
					if rd_first_done = '1' then
                        rd_first_D   <= '0'; -- default assignement
                    end if;
					if wr_en_D = '1' then
						bram_wr_cnt <= bram_wr_cnt + 1;
						-- Check if first read done
                        if rd_first_done = '0' and bram_wr_cnt > 1 then
                            rd_first_D   <= '1';
                            rd_first_done <= '1';
                        end if;
					end if;
					rd_en_reg_D <= pulse_out_DI;
					if pulse_out_DI = '1' then
						data_DO  <= rd_data_DI;
					end if;
					if (data_cnt < unsigned(length_DI)) and (rd_en_D = '1') then
						data_cnt <= data_cnt + 1;
						bram_rd_cnt <= bram_rd_cnt + 1;
					end if;
					wr_data_DO <= axi_wrdata(NBITS_INPUT-1 downto 0);
				end if;
			end if;
		end if;
	end process;
	
	rd_en_DO <= rd_en_D;
	wr_en_DO <= wr_en_D;
	
	-- Calculate rest after last burst
	process(enable_DI, length_DI)
	begin
		if enable_DI = '1' then
			transfer_rest <= to_unsigned(C_M00_AXI_BURST_LEN,8);
		else
			transfer_rest <= (others => '0');
		end if;
	end process;
	
	-- AXI control: ready/valid
	process(clk_CI)
	begin
		if rising_edge(clk_CI) then
			if enable_DI = '0' then
				wr_valid <= '0';
				rd_valid <= '0';
			else	
				if wr_en_SI = '1' then -- Write
					rd_valid <= '0';
					if (wr_busy = '0' and wr_valid = '0' and dma_busy_S = '1' and (((bram_wr_cnt > bram_rd_cnt) and (((bram_wr_cnt - bram_rd_cnt+1) > to_unsigned(C_M00_AXI_BURST_LEN,NBITS_BRAM_ADDR)) or ((data_cnt >= (unsigned(length_DI) - to_unsigned(2*C_M00_AXI_BURST_LEN,NBITS_BRAM_ADDR))) and ((bram_wr_cnt - bram_rd_cnt+1) >= to_unsigned(C_M00_AXI_BURST_LEN,NBITS_BRAM_ADDR))))) or ((bram_rd_cnt > bram_wr_cnt) and (bram_rd_cnt > (max_cnt - to_unsigned(C_M00_AXI_BURST_LEN,NBITS_BRAM_ADDR))) and ((max_cnt-bram_rd_cnt+bram_wr_cnt) >= to_unsigned(C_M00_AXI_BURST_LEN-2,NBITS_BRAM_ADDR))))) then
						wr_valid <= '1';
					elsif wr_busy = '1' then
						wr_valid <= '0';
					end if;
				else -- Read
					wr_valid <= '0';
					if (init_txn_pulse = '1') or (rd_busy = '0' and rd_valid = '0' and init_done_S = '1' and (((bram_wr_cnt > bram_rd_cnt) and ((bram_wr_cnt - bram_rd_cnt) < (max_cnt - to_unsigned(C_M00_AXI_BURST_LEN,NBITS_BRAM_ADDR)))) or ((bram_rd_cnt > bram_wr_cnt) and (((max_cnt-bram_rd_cnt+bram_wr_cnt) < (max_cnt - to_unsigned(2*C_M00_AXI_BURST_LEN,NBITS_BRAM_ADDR))) or ((data_cnt >= (unsigned(length_DI) - to_unsigned(2*C_M00_AXI_BURST_LEN,NBITS_BRAM_ADDR)))))))) then
						rd_valid <= '1';
					elsif rd_busy = '1' then
						rd_valid <= '0';
					end if;
				end if;
			end if;
		end if;
	end process;
	
	-- init_txn_pulse
	process(clk_CI)
	begin
		if rising_edge(clk_CI) then
			if enable_DI = '0' then
				dma_busy_del <= '0';
				dma_rdy_del <= '0';
				init_txn_pulse <= '0';
				init_done_S <= '0';
			else
				dma_rdy_del <= dma_rdy_S;
				dma_busy_del <= dma_busy_S;
				if wr_en_SI = '1' then
				    init_done_S <= '0';
					if dma_busy_S = '1' and dma_busy_del = '0' then
						init_txn_pulse <= '1';
					else 
						init_txn_pulse <= '0';
					end if;
				else
				    if init_txn_pulse = '1' then
				        init_done_S <= '1';
				    elsif dma_busy_S = '0' and dma_busy_del = '1' then
				        init_done_S <= '0';
				    end if;
					if dma_rdy_S = '1' and dma_rdy_del = '0' then
						init_txn_pulse <= '1';
					else 
						init_txn_pulse <= '0';
					end if;				
				end if;
			end if;
		end if;
	end process;
	
	-- Process status reg
	process(clk_CI)
	begin
		if rising_edge(clk_CI) then
			if enable_DI = '0' then
				dma_busy_S <= '0';
				dma_done_S <= '0';
				dma_rdy_S  <= '0';
			else			
				dma_busy_S <= '0';
				dma_done_S <= '0';
				dma_rdy_S  <= '0';
				if data_cnt = unsigned(length_DI) then
					dma_done_S <= '1';
				elsif (bram_rd_cnt = bram_wr_cnt) and (data_cnt = 0) then
					dma_rdy_S <= '1';
				else
					dma_busy_S <= '1';
				end if;
			end if;
		end if;
	end process;
	
	dma_rdy_SO <= dma_rdy_S;
	dma_busy_SO <= dma_busy_S;
	dma_done_SO <= dma_done_S;
    
    
    -- end of frame transfer detection
    -- Glue-logic to detect response of very last write
    -- Because there is only one open write-transfer, this approach works.
    p_eof : process (clk_CI)
    begin
        if rising_edge(clk_CI) then
            if enable_DI = '0' then
                WrEof_Wait4Axi  <= '0';
                WrEof_Done      <= '0';
                wr_eof_done_SO  <= '0';
            else
                -- detect last write command
                if set_tlast = '1' then
                    WrEof_Wait4Axi  <= '1';
                elsif m00_axi_bvalid = '1' then
                    -- m00_axi_bready can be ignored (always set with bvalid)
                    WrEof_Wait4Axi  <= '0';
                end if;

                -- last write response
                WrEof_Done  <= '0';
                if WrEof_Wait4Axi = '1' and m00_axi_bvalid = '1' then
                    -- m00_axi_bready can be ignored (always set with bvalid)
                    WrEof_Done      <= '1';
                end if;
                
                -- pipeline reg
                wr_eof_done_SO      <= WrEof_Done;
                
            end if;
        end if;
    end process;

end arch_imp;
