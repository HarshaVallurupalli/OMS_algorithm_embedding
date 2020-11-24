--------------------------------------------------------------------------------
-- Creation
--
-- Copyright : ESPROS Photonics AG (epc)
-- Project   : TOF_cos_sl
-- Date      : 09-10-2019
-- Author    : msc
--
--------------------------------------------------------------------------------
-- Description
--
-- Package of camera_control
--
--------------------------------------------------------------------------------



--------------------------------------------------------------------------------
-- Include libraries
--------------------------------------------------------------------------------

-- Include the standard packages
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

-- Include the libraries of all the packages that are included.

--------------------------------------------------------------------------------
-- Package declaration
--------------------------------------------------------------------------------
package pkg_camera_control is

  ------------------------------------------------------------------------------
  -- Constant declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Component declarations
  ------------------------------------------------------------------------------

  component ip_camera_control is
    generic (
		DONE_DELAY : integer := 1000;
        CLK_DIVISION_FACTOR : integer := 5;
        ALU_PREP_CYCLES : integer := 64;
        RAM_WAIT_CYCLES : integer := 16;
        RAM_WAIT_DONE : integer := 0;
		NBITS_LENGTH : positive := 17
	);
    port (
		clk : in std_logic;
		resetn : in std_logic;
		
		-- from/to reg_bank
		cc_en_DI : in std_logic;
		cc_rst_RI : in std_logic;
		cc_update_reg_values_SI : in std_logic;
		cc_mode_SI : in std_logic_vector(2 downto 0);
		cc_data_length_DI : in std_logic_vector(NBITS_LENGTH-1 downto 0);
		reset_cc_regs_RO : out std_logic;
		image_bin_en_SI : in std_logic;
		
		-- Control inputs
		tcmi_active : in std_logic;
		image_bin_done_SI : in std_logic;
		pixel_cnt : in unsigned(NBITS_LENGTH-1 downto 0);
		
		-- Control outputs
        tcmi_en : out std_logic;
        tcmi_dcs_sel : out std_logic_vector(2 downto 0);
        tcmi_last_dcs : out std_logic_vector(2 downto 0);
        img_dual_en : out std_logic;
  
        grey_length : out std_logic_vector(NBITS_LENGTH+1 downto 0);
        dcs_length : out std_logic_vector(NBITS_LENGTH-1 downto 0);
        sort_length : out std_logic_vector(NBITS_LENGTH-1 downto 0);
        
        alu_en : out std_logic
  );
  end component ip_camera_control;

  ------------------------------------------------------------------------------
  -- Type declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Function declarations
  ------------------------------------------------------------------------------

end pkg_camera_control;

--------------------------------------------------------------------------------
-- Package body
--------------------------------------------------------------------------------

package body pkg_camera_control is

  ------------------------------------------------------------------------------
  -- Function bodies
  ------------------------------------------------------------------------------

end pkg_camera_control;