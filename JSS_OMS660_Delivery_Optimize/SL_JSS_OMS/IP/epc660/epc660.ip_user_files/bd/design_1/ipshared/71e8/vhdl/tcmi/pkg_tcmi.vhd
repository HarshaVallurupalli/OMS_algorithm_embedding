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
package pkg_tcmi is

  ------------------------------------------------------------------------------
  -- Constant declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Component declarations
  ------------------------------------------------------------------------------

  component ip_tcmi is
    generic (
	  ENABLE_INPUT_FIFO : boolean := false;
	  ENABLE_DELAY_NB : positive := 1200;
	  NBITS_DATA_IN : positive := 12;
	  NBITS_LENGTH : positive := 16
	);
    port (
		-- control signals
		clk : in STD_LOGIC;							
		en : in STD_LOGIC;
		length : in std_logic_vector(NBITS_LENGTH-1 downto 0);    
        
		-- signals from chip
		dclk_in : in std_logic; 									
		vsync_in : in std_logic; 									
		hsync_in : in std_logic; 							
		xsync_sat_in : in std_logic; 						
		data_in : in std_logic_vector(NBITS_DATA_IN-1 downto 0);
		
		-- control out
		active : out std_logic;
		pixel_cnt : out unsigned(NBITS_LENGTH-1 downto 0);
		last_out : out std_logic;

		-- data to RAM
		vsync_SO : out std_logic;
		hsync_SO : out std_logic;
		pulse_out : out std_logic;
		dout : out std_logic_vector(NBITS_DATA_IN downto 0)
  );
  end component ip_tcmi;

  ------------------------------------------------------------------------------
  -- Type declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Function declarations
  ------------------------------------------------------------------------------

end pkg_tcmi;

--------------------------------------------------------------------------------
-- Package body
--------------------------------------------------------------------------------

package body pkg_tcmi is

  ------------------------------------------------------------------------------
  -- Function bodies
  ------------------------------------------------------------------------------

end pkg_tcmi;