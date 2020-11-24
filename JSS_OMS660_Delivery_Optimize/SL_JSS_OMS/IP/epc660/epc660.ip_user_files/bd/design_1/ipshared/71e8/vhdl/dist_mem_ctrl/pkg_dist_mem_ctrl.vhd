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
-- Package of dist_mem_ctrl
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
package pkg_dist_mem_ctrl is

  ------------------------------------------------------------------------------
  -- Constant declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Component declarations
  ------------------------------------------------------------------------------

  component ip_dist_mem_ctrl is
    generic (
	  NBITS_ADDR : integer   := 9
	);
    port (
        clk_CI             : in  std_logic;
        enable_SI          : in  std_logic;
        data_pulse_DI      : in  std_logic;
        -- readRAM               
		read_pulse_DI      : in  std_logic;
        -- BRAM
        read_bram_addr_DO  : out std_logic_vector(NBITS_ADDR-1 downto 0);
        read_bram_en_DO    : out std_logic;
        write_bram_addr_DO : out std_logic_vector(NBITS_ADDR-1 downto 0);
        write_bram_en_DO   : out std_logic
  );
  end component ip_dist_mem_ctrl;

  ------------------------------------------------------------------------------
  -- Type declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Function declarations
  ------------------------------------------------------------------------------

end pkg_dist_mem_ctrl;

--------------------------------------------------------------------------------
-- Package body
--------------------------------------------------------------------------------

package body pkg_dist_mem_ctrl is

  ------------------------------------------------------------------------------
  -- Function bodies
  ------------------------------------------------------------------------------

end pkg_dist_mem_ctrl;