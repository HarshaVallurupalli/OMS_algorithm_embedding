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
-- Package of interf_detect
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
package pkg_interf_detect is

  ------------------------------------------------------------------------------
  -- Constant declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Component declarations
  ------------------------------------------------------------------------------

  component ip_interf_detect is
    generic (
		NBITS_DATA : integer := 12
	);
    port (
		clk_CI            : in STD_LOGIC;
        resetn_RB         : in STD_LOGIC;
        reg_interf_thr_DI : in STD_LOGIC_VECTOR (NBITS_DATA downto 0);
        data_in0_DI       : in STD_LOGIC_VECTOR (NBITS_DATA downto 0);
        data_in1_DI       : in STD_LOGIC_VECTOR (NBITS_DATA downto 0);
        interf_flag_DO    : out STD_LOGIC	
  );
  end component ip_interf_detect;

  ------------------------------------------------------------------------------
  -- Type declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Function declarations
  ------------------------------------------------------------------------------

end pkg_interf_detect;

--------------------------------------------------------------------------------
-- Package body
--------------------------------------------------------------------------------

package body pkg_interf_detect is

  ------------------------------------------------------------------------------
  -- Function bodies
  ------------------------------------------------------------------------------

end pkg_interf_detect;