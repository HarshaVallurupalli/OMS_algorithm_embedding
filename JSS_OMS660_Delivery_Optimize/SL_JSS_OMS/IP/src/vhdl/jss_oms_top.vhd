----------------------------------------------------------------------------------
-- File:		jss_oms_top
-- Author:		MSC
-- Created:		16.10.2019
-- Description:	Top-Level file of the JSS OMS based on a epc660
--				
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

library unisim;
use unisim.vcomponents.all;


entity jss_oms_top is
  port (
	-- DDR3 interface
    DDR_addr : inout STD_LOGIC_VECTOR ( 14 downto 0 );
    DDR_ba : inout STD_LOGIC_VECTOR ( 2 downto 0 );
    DDR_cas_n : inout STD_LOGIC;
    DDR_ck_n : inout STD_LOGIC;
    DDR_ck_p : inout STD_LOGIC;
    DDR_cke : inout STD_LOGIC;
    DDR_cs_n : inout STD_LOGIC;
    DDR_dm : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    DDR_dq : inout STD_LOGIC_VECTOR ( 31 downto 0 );
    DDR_dqs_n : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    DDR_dqs_p : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    DDR_odt : inout STD_LOGIC;
    DDR_ras_n : inout STD_LOGIC;
    DDR_reset_n : inout STD_LOGIC;
    DDR_we_n : inout STD_LOGIC;
	
	-- Fixed PS pins
    FIXED_IO_ddr_vrn : inout STD_LOGIC;
    FIXED_IO_ddr_vrp : inout STD_LOGIC;
    FIXED_IO_mio : inout STD_LOGIC_VECTOR ( 53 downto 0 );
    FIXED_IO_ps_clk : inout STD_LOGIC;
    FIXED_IO_ps_porb : inout STD_LOGIC;
    FIXED_IO_ps_srstb : inout STD_LOGIC;
	
	-- I2C
    IIC_1_0_scl_io : inout STD_LOGIC;
    IIC_1_0_sda_io : inout STD_LOGIC;
	
	-- epc660 TCMI interface cam1
    data_in : in STD_LOGIC_VECTOR ( 11 downto 0 );
    dclk_in : in STD_LOGIC;
    hsync_in : in STD_LOGIC;
    vsync_in : in STD_LOGIC;
	
	-- GPIO Control signals cam1
    cam1_reset      : out STD_LOGIC;
    cam1_vbatt_en   : out STD_LOGIC;
    cam1_deser_rst  : out STD_LOGIC;
    
    	-- epc660 TCMI interface cam2
    data_in1 : in STD_LOGIC_VECTOR ( 11 downto 0 );
    dclk_in1 : in STD_LOGIC;
    hsync_in1 : in STD_LOGIC;
    vsync_in1 : in STD_LOGIC;
    
    -- GPIO Control signals cam2
    cam2_reset      : out STD_LOGIC;
    cam2_vbatt_en   : out STD_LOGIC;
    cam2_deser_rst  : out STD_LOGIC;
    
    	-- epc660 TCMI interface cam3
    data_in2 : in STD_LOGIC_VECTOR ( 11 downto 0 );
    dclk_in2 : in STD_LOGIC;
    hsync_in2 : in STD_LOGIC;
    vsync_in2 : in STD_LOGIC;
    
    -- GPIO Control signals cam3
    cam3_reset      : out STD_LOGIC;
    cam3_vbatt_en   : out STD_LOGIC;
    cam3_deser_rst  : out STD_LOGIC;
    
        -- epc660 TCMI interface cam4
    data_in3 : in STD_LOGIC_VECTOR ( 11 downto 0 );
    dclk_in3 : in STD_LOGIC;
    hsync_in3 : in STD_LOGIC;
    vsync_in3 : in STD_LOGIC;
    
    -- GPIO Control signals cam4
    cam4_reset      : out STD_LOGIC;
    cam4_vbatt_en   : out STD_LOGIC;
    cam4_deser_rst  : out STD_LOGIC
    );
end jss_oms_top;

architecture rtl of jss_oms_top is

    -- component declaration
    component design_1 is
    port (
		data_in : in STD_LOGIC_VECTOR ( 11 downto 0 );
		dclk_in : in STD_LOGIC;
		gpio_io_o_0 : out STD_LOGIC_VECTOR ( 3 downto 0 );
		hsync_in : in STD_LOGIC;
		vsync_in : in STD_LOGIC;
		xsync_sat_in : in STD_LOGIC;
		--edit
	    data_in1 : in STD_LOGIC_VECTOR ( 11 downto 0 );
        dclk_in1 : in STD_LOGIC;
        gpio_io_o_1 : out STD_LOGIC_VECTOR ( 3 downto 0 );
        hsync_in1 : in STD_LOGIC;
        vsync_in1 : in STD_LOGIC;
        xsync_sat_in1 : in STD_LOGIC;
        
        data_in2 : in STD_LOGIC_VECTOR ( 11 downto 0 );
        dclk_in2 : in STD_LOGIC;
        gpio_io_o_2 : out STD_LOGIC_VECTOR ( 3 downto 0 );
        hsync_in2 : in STD_LOGIC;
        vsync_in2 : in STD_LOGIC;
        xsync_sat_in2 : in STD_LOGIC;
        
        data_in3 : in STD_LOGIC_VECTOR ( 11 downto 0 );
        dclk_in3 : in STD_LOGIC;
        gpio_io_o_3 : out STD_LOGIC_VECTOR ( 3 downto 0 );
        hsync_in3 : in STD_LOGIC;
        vsync_in3 : in STD_LOGIC;
        xsync_sat_in3 : in STD_LOGIC;
        --edit
		DDR_cas_n : inout STD_LOGIC;
		DDR_cke : inout STD_LOGIC;
		DDR_ck_n : inout STD_LOGIC;
		DDR_ck_p : inout STD_LOGIC;
		DDR_cs_n : inout STD_LOGIC;
		DDR_reset_n : inout STD_LOGIC;
		DDR_odt : inout STD_LOGIC;
		DDR_ras_n : inout STD_LOGIC;
		DDR_we_n : inout STD_LOGIC;
		DDR_ba : inout STD_LOGIC_VECTOR ( 2 downto 0 );
		DDR_addr : inout STD_LOGIC_VECTOR ( 14 downto 0 );
		DDR_dm : inout STD_LOGIC_VECTOR ( 3 downto 0 );
		DDR_dq : inout STD_LOGIC_VECTOR ( 31 downto 0 );
		DDR_dqs_n : inout STD_LOGIC_VECTOR ( 3 downto 0 );
		DDR_dqs_p : inout STD_LOGIC_VECTOR ( 3 downto 0 );
		FIXED_IO_mio : inout STD_LOGIC_VECTOR ( 53 downto 0 );
		FIXED_IO_ddr_vrn : inout STD_LOGIC;
		FIXED_IO_ddr_vrp : inout STD_LOGIC;
		FIXED_IO_ps_srstb : inout STD_LOGIC;
		FIXED_IO_ps_clk : inout STD_LOGIC;
		FIXED_IO_ps_porb : inout STD_LOGIC;
		IIC_1_0_sda_i : in STD_LOGIC;
		IIC_1_0_sda_o : out STD_LOGIC;
		IIC_1_0_sda_t : out STD_LOGIC;
		IIC_1_0_scl_i : in STD_LOGIC;
		IIC_1_0_scl_o : out STD_LOGIC;
		IIC_1_0_scl_t : out STD_LOGIC
    );
    end component design_1;
      
      
    component IOBUF is
    port (
        I : in STD_LOGIC;
        O : out STD_LOGIC;
        T : in STD_LOGIC;
        IO : inout STD_LOGIC
    );
    end component IOBUF; 
	
	-- signal declaration
	signal IIC_1_0_scl_i : STD_LOGIC;
	signal IIC_1_0_scl_o : STD_LOGIC;
	signal IIC_1_0_scl_t : STD_LOGIC;
	signal IIC_1_0_sda_i : STD_LOGIC;
	signal IIC_1_0_sda_o : STD_LOGIC;
	signal IIC_1_0_sda_t : STD_LOGIC;
	
	signal hsync_inv_in : std_logic;
	signal vsync_inv_in : std_logic;
    
    signal gpio_io_o_0_I  : std_logic_vector(3 downto 0);
  --edit  	
    signal hsync_inv_in1 : std_logic;
    signal vsync_inv_in1 : std_logic;
    
    signal gpio_io_o_1_I  : std_logic_vector(3 downto 0);
    
    signal hsync_inv_in2 : std_logic;
    signal vsync_inv_in2 : std_logic;
    
    signal gpio_io_o_2_I  : std_logic_vector(3 downto 0);
    
    signal hsync_inv_in3 : std_logic;
    signal vsync_inv_in3 : std_logic;
    
    signal gpio_io_o_3_I  : std_logic_vector(3 downto 0);
    --edit
begin
    
    ------------------------------------------------------------------------------
    -- I2C IO Buffers
    ------------------------------------------------------------------------------	
	
	IIC_1_0_scl_iobuf: component IOBUF
		port map (
		I => IIC_1_0_scl_o,
		IO => IIC_1_0_scl_io,
		O => IIC_1_0_scl_i,
		T => IIC_1_0_scl_t
		);
		
	IIC_1_0_sda_iobuf: component IOBUF
		port map (
		I => IIC_1_0_sda_o,
		IO => IIC_1_0_sda_io,
		O => IIC_1_0_sda_i,
		T => IIC_1_0_sda_t
		);
	
    ------------------------------------------------------------------------------
    -- block design instantiation
    ------------------------------------------------------------------------------
		
	i_bd : component design_1
		port map (
			DDR_addr(14 downto 0) => DDR_addr(14 downto 0),
			DDR_ba(2 downto 0) => DDR_ba(2 downto 0),
			DDR_cas_n => DDR_cas_n,
			DDR_ck_n => DDR_ck_n,
			DDR_ck_p => DDR_ck_p,
			DDR_cke => DDR_cke,
			DDR_cs_n => DDR_cs_n,
			DDR_dm(3 downto 0) => DDR_dm(3 downto 0),
			DDR_dq(31 downto 0) => DDR_dq(31 downto 0),
			DDR_dqs_n(3 downto 0) => DDR_dqs_n(3 downto 0),
			DDR_dqs_p(3 downto 0) => DDR_dqs_p(3 downto 0),
			DDR_odt => DDR_odt,
			DDR_ras_n => DDR_ras_n,
			DDR_reset_n => DDR_reset_n,
			DDR_we_n => DDR_we_n,
			FIXED_IO_ddr_vrn => FIXED_IO_ddr_vrn,
			FIXED_IO_ddr_vrp => FIXED_IO_ddr_vrp,
			FIXED_IO_mio(53 downto 0) => FIXED_IO_mio(53 downto 0),
			FIXED_IO_ps_clk => FIXED_IO_ps_clk,
			FIXED_IO_ps_porb => FIXED_IO_ps_porb,
			FIXED_IO_ps_srstb => FIXED_IO_ps_srstb,
			IIC_1_0_scl_i => IIC_1_0_scl_i,
			IIC_1_0_scl_o => IIC_1_0_scl_o,
			IIC_1_0_scl_t => IIC_1_0_scl_t,
			IIC_1_0_sda_i => IIC_1_0_sda_i,
			IIC_1_0_sda_o => IIC_1_0_sda_o,
			IIC_1_0_sda_t => IIC_1_0_sda_t,
			data_in(11 downto 0) => data_in(11 downto 0),
			dclk_in => dclk_in,
			gpio_io_o_0(3 downto 0) => gpio_io_o_0_I(3 downto 0),
			hsync_in => hsync_inv_in,
			vsync_in => vsync_inv_in,
			xsync_sat_in => '0',
			--edit
			data_in1(11 downto 0) => data_in1(11 downto 0),
            dclk_in1 => dclk_in1,
            gpio_io_o_1(3 downto 0) => gpio_io_o_1_I(3 downto 0),
            hsync_in1 => hsync_inv_in1,
            vsync_in1 => vsync_inv_in1,
            xsync_sat_in1 => '0',
            
			data_in2(11 downto 0) => data_in2(11 downto 0),
            dclk_in2 => dclk_in2,
            gpio_io_o_2(3 downto 0) => gpio_io_o_2_I(3 downto 0),
            hsync_in2 => hsync_inv_in2,
            vsync_in2 => vsync_inv_in2,
            xsync_sat_in2 => '0',
            
			data_in3(11 downto 0) => data_in3(11 downto 0),
            dclk_in3 => dclk_in3,
            gpio_io_o_3(3 downto 0) => gpio_io_o_3_I(3 downto 0),
            hsync_in3 => hsync_inv_in3,
            vsync_in3 => vsync_inv_in3,
            xsync_sat_in3 => '0'
            --edit
		);
		
        ------------------------------------------------------------------------------
        -- Invert hsync/vsync for serialzer transmission
        ------------------------------------------------------------------------------
		hsync_inv_in <= not hsync_in;
		vsync_inv_in <= not vsync_in;
        
        ------------------------------------------------------------------------------
        -- Assign GPIOs
        ------------------------------------------------------------------------------
        -- gpio[2] does not exist on HW
        cam1_deser_rst  <= gpio_io_o_0_I(0);
        cam1_reset      <= gpio_io_o_0_I(1);
        cam1_vbatt_en   <= gpio_io_o_0_I(3);
        
        --edit
             ------------------------------------------------------------------------------
        -- Invert hsync/vsync for serialzer transmission
        ------------------------------------------------------------------------------
        hsync_inv_in1 <= not hsync_in1;
        vsync_inv_in1 <= not vsync_in1;
        
        ------------------------------------------------------------------------------
        -- Assign GPIOs
        ------------------------------------------------------------------------------
        -- gpio[2] does not exist on HW
        cam2_deser_rst  <= gpio_io_o_1_I(0);
        cam2_reset      <= gpio_io_o_1_I(1);
        cam2_vbatt_en   <= gpio_io_o_1_I(3); 
        
         ------------------------------------------------------------------------------
       -- Invert hsync/vsync for serialzer transmission
       ------------------------------------------------------------------------------
       hsync_inv_in2 <= not hsync_in2;
       vsync_inv_in2 <= not vsync_in2;
       
       ------------------------------------------------------------------------------
       -- Assign GPIOs
       ------------------------------------------------------------------------------
       -- gpio[2] does not exist on HW
       cam3_deser_rst  <= gpio_io_o_2_I(0);
       cam3_reset      <= gpio_io_o_2_I(1);
       cam3_vbatt_en   <= gpio_io_o_2_I(3); 
                 ------------------------------------------------------------------------------
        -- Invert hsync/vsync for serialzer transmission
        ------------------------------------------------------------------------------
        hsync_inv_in3 <= not hsync_in3;
        vsync_inv_in3 <= not vsync_in3;
        
        ------------------------------------------------------------------------------
        -- Assign GPIOs
        ------------------------------------------------------------------------------
        -- gpio[2] does not exist on HW
        cam4_deser_rst  <= gpio_io_o_3_I(0);
        cam4_reset      <= gpio_io_o_3_I(1);
        cam4_vbatt_en   <= gpio_io_o_3_I(3);            
        --edit  
end rtl;