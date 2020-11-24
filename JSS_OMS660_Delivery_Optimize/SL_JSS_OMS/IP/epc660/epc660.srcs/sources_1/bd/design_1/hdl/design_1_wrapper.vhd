--Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2018.2.2 (win64) Build 2258646 Thu Jun 14 20:03:12 MDT 2018
--Date        : Thu Aug 20 05:48:56 2020
--Host        : DESKTOP-C4AINOR running 64-bit major release  (build 9200)
--Command     : generate_target design_1_wrapper.bd
--Design      : design_1_wrapper
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity design_1_wrapper is
  port (
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
    FCLK_CLK0 : out STD_LOGIC;
    FCLK_RESET0_N : out STD_LOGIC;
    FIXED_IO_ddr_vrn : inout STD_LOGIC;
    FIXED_IO_ddr_vrp : inout STD_LOGIC;
    FIXED_IO_mio : inout STD_LOGIC_VECTOR ( 53 downto 0 );
    FIXED_IO_ps_clk : inout STD_LOGIC;
    FIXED_IO_ps_porb : inout STD_LOGIC;
    FIXED_IO_ps_srstb : inout STD_LOGIC;
    IIC_1_0_scl_io : inout STD_LOGIC;
    IIC_1_0_sda_io : inout STD_LOGIC;
    data_in : in STD_LOGIC_VECTOR ( 11 downto 0 );
    data_in1 : in STD_LOGIC_VECTOR ( 11 downto 0 );
    data_in2 : in STD_LOGIC_VECTOR ( 11 downto 0 );
    data_in3 : in STD_LOGIC_VECTOR ( 11 downto 0 );
    dclk_in : in STD_LOGIC;
    dclk_in1 : in STD_LOGIC;
    dclk_in2 : in STD_LOGIC;
    dclk_in3 : in STD_LOGIC;
    gpio_io_o_0 : out STD_LOGIC_VECTOR ( 3 downto 0 );
    gpio_io_o_1 : out STD_LOGIC_VECTOR ( 3 downto 0 );
    gpio_io_o_2 : out STD_LOGIC_VECTOR ( 3 downto 0 );
    gpio_io_o_3 : out STD_LOGIC_VECTOR ( 3 downto 0 );
    hsync_in : in STD_LOGIC;
    hsync_in1 : in STD_LOGIC;
    hsync_in2 : in STD_LOGIC;
    hsync_in3 : in STD_LOGIC;
    vsync_in : in STD_LOGIC;
    vsync_in1 : in STD_LOGIC;
    vsync_in2 : in STD_LOGIC;
    vsync_in3 : in STD_LOGIC;
    xsync_sat_in : in STD_LOGIC;
    xsync_sat_in1 : in STD_LOGIC;
    xsync_sat_in2 : in STD_LOGIC;
    xsync_sat_in3 : in STD_LOGIC
  );
end design_1_wrapper;

architecture STRUCTURE of design_1_wrapper is
  component design_1 is
  port (
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
    IIC_1_0_scl_t : out STD_LOGIC;
    FCLK_CLK0 : out STD_LOGIC;
    FCLK_RESET0_N : out STD_LOGIC;
    hsync_in : in STD_LOGIC;
    vsync_in : in STD_LOGIC;
    xsync_sat_in : in STD_LOGIC;
    hsync_in1 : in STD_LOGIC;
    vsync_in1 : in STD_LOGIC;
    gpio_io_o_0 : out STD_LOGIC_VECTOR ( 3 downto 0 );
    gpio_io_o_1 : out STD_LOGIC_VECTOR ( 3 downto 0 );
    data_in : in STD_LOGIC_VECTOR ( 11 downto 0 );
    data_in1 : in STD_LOGIC_VECTOR ( 11 downto 0 );
    xsync_sat_in1 : in STD_LOGIC;
    dclk_in : in STD_LOGIC;
    dclk_in1 : in STD_LOGIC;
    data_in2 : in STD_LOGIC_VECTOR ( 11 downto 0 );
    hsync_in2 : in STD_LOGIC;
    vsync_in2 : in STD_LOGIC;
    xsync_sat_in2 : in STD_LOGIC;
    data_in3 : in STD_LOGIC_VECTOR ( 11 downto 0 );
    hsync_in3 : in STD_LOGIC;
    vsync_in3 : in STD_LOGIC;
    xsync_sat_in3 : in STD_LOGIC;
    dclk_in2 : in STD_LOGIC;
    dclk_in3 : in STD_LOGIC;
    gpio_io_o_2 : out STD_LOGIC_VECTOR ( 3 downto 0 );
    gpio_io_o_3 : out STD_LOGIC_VECTOR ( 3 downto 0 )
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
  signal IIC_1_0_scl_i : STD_LOGIC;
  signal IIC_1_0_scl_o : STD_LOGIC;
  signal IIC_1_0_scl_t : STD_LOGIC;
  signal IIC_1_0_sda_i : STD_LOGIC;
  signal IIC_1_0_sda_o : STD_LOGIC;
  signal IIC_1_0_sda_t : STD_LOGIC;
begin
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
design_1_i: component design_1
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
      FCLK_CLK0 => FCLK_CLK0,
      FCLK_RESET0_N => FCLK_RESET0_N,
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
      data_in1(11 downto 0) => data_in1(11 downto 0),
      data_in2(11 downto 0) => data_in2(11 downto 0),
      data_in3(11 downto 0) => data_in3(11 downto 0),
      dclk_in => dclk_in,
      dclk_in1 => dclk_in1,
      dclk_in2 => dclk_in2,
      dclk_in3 => dclk_in3,
      gpio_io_o_0(3 downto 0) => gpio_io_o_0(3 downto 0),
      gpio_io_o_1(3 downto 0) => gpio_io_o_1(3 downto 0),
      gpio_io_o_2(3 downto 0) => gpio_io_o_2(3 downto 0),
      gpio_io_o_3(3 downto 0) => gpio_io_o_3(3 downto 0),
      hsync_in => hsync_in,
      hsync_in1 => hsync_in1,
      hsync_in2 => hsync_in2,
      hsync_in3 => hsync_in3,
      vsync_in => vsync_in,
      vsync_in1 => vsync_in1,
      vsync_in2 => vsync_in2,
      vsync_in3 => vsync_in3,
      xsync_sat_in => xsync_sat_in,
      xsync_sat_in1 => xsync_sat_in1,
      xsync_sat_in2 => xsync_sat_in2,
      xsync_sat_in3 => xsync_sat_in3
    );
end STRUCTURE;
