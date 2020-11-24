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
-- Package of tcmi
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
package pkg_image_bin is

  ------------------------------------------------------------------------------
  -- Constant declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Component declarations
  ------------------------------------------------------------------------------

  component ip_image_bin is
    generic (
		NBITS_DATA : integer := 13;
		NBITS_ADDR : integer := 10
	);
    port (
		-- inputs
		clk_CI              : in std_logic;
		en_DI               : in std_logic;
		reset_RBI           : in std_logic;
		pulse_DI            : in std_logic;
        data_in_DI          : in std_logic_vector(NBITS_DATA-1 downto 0);
        bad_pixel_DI        : in std_logic;
		bram_data_in_DI     : in std_logic_vector(NBITS_DATA+2 downto 0);
		reg_line_length_DI  : in std_logic_vector(8 downto 0);
		reg_pix_inter_en_SI : in std_logic;
		reg_adc_en_SI       : in std_logic;
		reg_remove_sat_en_SI : in std_logic;
		hsync_DI            : in std_logic; -- to add robustness; if needed
		vsync_DI            : in std_logic; -- to generate data start / end signals
		last_pulse_DI       : in std_logic;
		dcs_SI              : in STD_LOGIC_VECTOR (2 downto 0);
        dcs_last_SI         : in STD_LOGIC_VECTOR (2 downto 0);
        dual_mgx_en_SI      : in std_logic;
		-- outputs
		mask_first_SO       : out std_logic;
		data_out_DO         : out std_logic_vector(NBITS_DATA-1 downto 0);
		bram_data_out_DO    : out std_logic_vector(NBITS_DATA+2 downto 0);
		bram_wr_en_DO       : out std_logic;
		bram_wr_addr_DO     : out std_logic_vector(NBITS_ADDR-1 downto 0);
		bram_rd_en_DO       : out std_logic;
		bram_rd_addr_DO     : out std_logic_vector(NBITS_ADDR-1 downto 0);
		grey_out_DO         : out STD_LOGIC;
        dcs0_out_DO         : out STD_LOGIC;
        dcs1_out_DO         : out STD_LOGIC;
        dcs2_out_DO         : out STD_LOGIC;
        dcs3_out_DO         : out STD_LOGIC;
        last_out_DO         : out STD_LOGIC;
        bad_pixel_DO        : out std_logic;
		image_bin_done_DO   : out STD_LOGIC;
		diff_bram_rd_en_SO  : out std_logic;
        ambient_en_SO       : out STD_LOGIC
  );
  end component ip_image_bin;

  ------------------------------------------------------------------------------
  -- Type declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Function declarations
  ------------------------------------------------------------------------------

end pkg_image_bin;

--------------------------------------------------------------------------------
-- Package body
--------------------------------------------------------------------------------

package body pkg_image_bin is

  ------------------------------------------------------------------------------
  -- Function bodies
  ------------------------------------------------------------------------------

end pkg_image_bin;