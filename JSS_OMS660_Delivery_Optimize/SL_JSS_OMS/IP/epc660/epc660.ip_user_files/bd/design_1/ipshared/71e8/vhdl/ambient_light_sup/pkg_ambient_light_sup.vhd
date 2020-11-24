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
-- Package of ambient_light_sup
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
package pkg_ambient_light_sup is

  ------------------------------------------------------------------------------
  -- Constant declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Component declarations
  ------------------------------------------------------------------------------

  component ip_ambient_light_sup is
    generic (
		NBITS_DATA    : integer := 12;
		NBITS_COMP    : integer := 16;
		NBITS_COMP_FP : integer := 8
	);
    port (
		clk_CI          : in std_logic;
		en_DI           : in std_logic;
		resetn_RBI      : in std_logic;
        GS_DI           : in std_logic_vector(NBITS_DATA downto 0);
        DCS_DI          : in std_logic_vector(NBITS_DATA downto 0);
        DCScorr_DO      : out std_logic_vector(NBITS_DATA downto 0);
		-- from reg_bank
		ambient_comp_DI : in std_logic_vector(NBITS_COMP-1 downto 0)
  );
  end component ip_ambient_light_sup;

  ------------------------------------------------------------------------------
  -- Type declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Function declarations
  ------------------------------------------------------------------------------

end pkg_ambient_light_sup;

--------------------------------------------------------------------------------
-- Package body
--------------------------------------------------------------------------------

package body pkg_ambient_light_sup is

  ------------------------------------------------------------------------------
  -- Function bodies
  ------------------------------------------------------------------------------

end pkg_ambient_light_sup;