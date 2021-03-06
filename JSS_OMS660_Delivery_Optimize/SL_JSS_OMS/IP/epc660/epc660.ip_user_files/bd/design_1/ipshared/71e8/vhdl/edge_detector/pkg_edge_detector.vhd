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
-- Package of edge_detector
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
package pkg_edge_detector is

  ------------------------------------------------------------------------------
  -- Constant declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Component declarations
  ------------------------------------------------------------------------------

  component ip_edge_detector is
    generic (
		RISING	: boolean	:= false;
		FALLING	: boolean	:= true;
		PULSE_LENGTH: integer := 5;
		NEG_OUTPUT : boolean := true
	);
    port (
	    clk_CI : in  std_logic;
	    en_DI  : in  std_logic;
        in_DI  : in  std_logic;
        out_DO : out std_logic
  );
  end component ip_edge_detector;

  ------------------------------------------------------------------------------
  -- Type declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Function declarations
  ------------------------------------------------------------------------------

end pkg_edge_detector;

--------------------------------------------------------------------------------
-- Package body
--------------------------------------------------------------------------------

package body pkg_edge_detector is

  ------------------------------------------------------------------------------
  -- Function bodies
  ------------------------------------------------------------------------------

end pkg_edge_detector;