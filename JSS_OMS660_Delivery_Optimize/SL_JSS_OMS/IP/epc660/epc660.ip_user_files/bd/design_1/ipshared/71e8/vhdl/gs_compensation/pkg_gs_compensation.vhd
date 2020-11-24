--------------------------------------------------------------------------------
-- Creation
--
-- Copyright : ESPROS Photonics AG (epc)
-- Project   : TOF_cos_sl
-- Date      : 16-10-2019
-- Author    : msc
--
--------------------------------------------------------------------------------
-- Description
--
-- Package of gs_compensation
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
package pkg_gs_compensation is

  ------------------------------------------------------------------------------
  -- Constant declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Component declarations
  ------------------------------------------------------------------------------

  component ip_gs_compensation is
    generic (
	  NBITS_DATA_IN : positive := 12;
	  NBITS_RAM_IN : positive := 16;
	  NB_SHIFT_LEFT : positive := 4
	);
	port ( 
	  clk_CI : in STD_LOGIC;								               
	  en_SI  : in STD_LOGIC;
         
	  gs_pulse_in_SI   : in  STD_LOGIC;
	  gs_data_in_DI    : in  STD_LOGIC_VECTOR(NBITS_DATA_IN-1 downto 0);
	  ram_pulse_in_SI  : in  STD_LOGIC;
	  ram_data_in_DI   : in  STD_LOGIC_VECTOR(NBITS_RAM_IN-1 downto 0);
	  ram_pulse_req_SO : out STD_LOGIC;
	  gs_pulse_out_SO  : out STD_LOGIC;	  
	  gs_data_out_DO   : out STD_LOGIC_VECTOR(NBITS_DATA_IN-1 downto 0)
  );
  end component ip_gs_compensation;

  ------------------------------------------------------------------------------
  -- Type declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Function declarations
  ------------------------------------------------------------------------------

end pkg_gs_compensation;

--------------------------------------------------------------------------------
-- Package body
--------------------------------------------------------------------------------

package body pkg_gs_compensation is

  ------------------------------------------------------------------------------
  -- Function bodies
  ------------------------------------------------------------------------------

end pkg_gs_compensation;