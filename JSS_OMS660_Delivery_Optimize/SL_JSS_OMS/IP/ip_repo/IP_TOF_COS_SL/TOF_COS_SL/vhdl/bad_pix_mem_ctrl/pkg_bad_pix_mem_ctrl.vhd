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
-- Package of bad_pix_mem_ctrl
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
package pkg_bad_pix_mem_ctrl is

  ------------------------------------------------------------------------------
  -- Constant declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Component declarations
  ------------------------------------------------------------------------------

  component ip_bad_pix_mem_ctrl is
    generic (
	    BAD_PIXEL_CODE : integer := 60000;
        NBITS : integer := 17
	);
    port (
	   clk_CI : in std_logic;
	   reset_RBI : in std_logic;
	   init_table_SI : in std_logic;
	   init_run_SI : in std_logic;
	   pix_nb_DI : in std_logic_vector(NBITS-1 downto 0);
	   reg_pix_nb_DI : in std_logic_vector(NBITS-1 downto 0);
	   pulse_in_DI : in std_logic;
	   -- ram access
	   ram_pulse_in_DI : in std_logic;
	   ram_data_in_DI : in unsigned(15 downto 0);
	   bad_pix_ram_rd_pulse_DO : out std_logic;
	   -- memory access
	   bad_pix_addr_DO : out std_logic_vector(NBITS-1 downto 0);
	   bad_pix_data_DO : out std_logic;
	   bad_pix_wr_en_DO : out std_logic;
	   bad_pix_data_DI : in std_logic;
	   -- output
	   readRam_reset_RBO : out std_logic;
	   init_not_ongoing_DO : out std_logic;
       bad_pix_sat_DO : out std_logic
  );
  end component ip_bad_pix_mem_ctrl;

  ------------------------------------------------------------------------------
  -- Type declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Function declarations
  ------------------------------------------------------------------------------

end pkg_bad_pix_mem_ctrl;

--------------------------------------------------------------------------------
-- Package body
--------------------------------------------------------------------------------

package body pkg_bad_pix_mem_ctrl is

  ------------------------------------------------------------------------------
  -- Function bodies
  ------------------------------------------------------------------------------

end pkg_bad_pix_mem_ctrl;