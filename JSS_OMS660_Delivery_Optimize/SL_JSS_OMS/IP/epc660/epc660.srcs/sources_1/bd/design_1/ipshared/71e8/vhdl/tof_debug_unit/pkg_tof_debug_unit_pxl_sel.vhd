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
package pkg_tof_debug_unit_pxl_sel is

  ------------------------------------------------------------------------------
  -- Constant declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Component declarations
  ------------------------------------------------------------------------------

    component ip_tof_debug_unit_pxl_sel is
        generic (
            NBITS_DATA          : integer;
            NBITS_FRAME_LENGTH  : integer := 17;
            NBITS_BRAM_DATA     : integer := 32;
            NBITS_BRAM_ADDR     : integer := 10
        );
        port ( 
            -- clock and reset
            Clk             : in std_logic;
            Rst             : in std_logic;
            
            -- control inputs
            Ena             : in std_logic;
            Rb_PxlCount     : in std_logic_vector (NBITS_FRAME_LENGTH-1 downto 0);
            Rb_DbgPxlIdx    : in std_logic_vector (NBITS_FRAME_LENGTH-1 downto 0);
            
            -- data intput interfaces
            Data_Vld        : in std_logic;
            DbgPxl_Sel      : out std_logic
        );  
    end component ip_tof_debug_unit_pxl_sel;

  ------------------------------------------------------------------------------
  -- Type declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Function declarations
  ------------------------------------------------------------------------------

end pkg_tof_debug_unit_pxl_sel;

--------------------------------------------------------------------------------
-- Package body
--------------------------------------------------------------------------------

package body pkg_tof_debug_unit_pxl_sel is

  ------------------------------------------------------------------------------
  -- Function bodies
  ------------------------------------------------------------------------------

end pkg_tof_debug_unit_pxl_sel;