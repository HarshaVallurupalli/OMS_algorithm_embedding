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
-- Package of add_const
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
package pkg_add_const is

  ------------------------------------------------------------------------------
  -- Constant declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Component declarations
  ------------------------------------------------------------------------------

  component ip_add_const is
    generic (
	  BIT_WIDTH : integer := 16
	);
    port (
		clk_CI       : in std_logic;
		en_DI        : in std_logic;
        datain_DI    : in  std_logic_vector(BIT_WIDTH-1 downto 0);
        dataout_DO   : out std_logic_vector(BIT_WIDTH-1 downto 0);
        satin_DI     : in  std_logic;
        satout_DO    : out std_logic;
		const_en_SI  : in std_logic;
		const_val_DI : in std_logic_vector(BIT_WIDTH downto 0);
		max_val_DI   : in std_logic_vector(BIT_WIDTH-1 downto 0)
  );
  end component ip_add_const;

  ------------------------------------------------------------------------------
  -- Type declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Function declarations
  ------------------------------------------------------------------------------

end pkg_add_const;

--------------------------------------------------------------------------------
-- Package body
--------------------------------------------------------------------------------

package body pkg_add_const is

  ------------------------------------------------------------------------------
  -- Function bodies
  ------------------------------------------------------------------------------

end pkg_add_const;