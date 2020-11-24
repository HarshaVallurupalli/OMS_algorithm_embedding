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
package pkg_tof_debug_unit is

  ------------------------------------------------------------------------------
  -- Constant declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Component declarations
  ------------------------------------------------------------------------------

    component ip_tof_debug_unit is
        generic (
            NBITS_DATA          : integer := 12;
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
            DcsRawX_Data     : in std_logic_vector(NBITS_DATA-1 downto 0);
            DcsRawX_Vld      : in std_logic_vector(3 downto 0);
            
            DcsAmbX_Data     : in std_logic_vector(NBITS_DATA-1 downto 0);
            DcsAmbX_Vld      : in std_logic_vector(1 downto 0);
            
            DistRaw_Data    : in std_logic_vector(NBITS_DATA-1 downto 0);
            DistRaw_Vld     : in std_logic;
            
            DistComp_Data   : in std_logic_vector(NBITS_DATA-1 downto 0);
            DistComp_Vld    : in std_logic;
            
            GsRaw_Data      : in std_logic_vector(NBITS_DATA-1 downto 0);
            GsRaw_Vld       : in std_logic;
            
            GsComp_Data     : in std_logic_vector(NBITS_DATA-1 downto 0);
            GsComp_Vld      : in std_logic;
            
            -- BRAM interface
            DbgBram_Addr    : out std_logic_vector(31 downto 0);
            DbgBram_Data    : out std_logic_vector(NBITS_BRAM_DATA-1 downto 0);
            DbgBram_Wen     : out std_logic_vector(3 downto 0)
        );
    end component ip_tof_debug_unit;

  ------------------------------------------------------------------------------
  -- Type declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Function declarations
  ------------------------------------------------------------------------------

end pkg_tof_debug_unit;

--------------------------------------------------------------------------------
-- Package body
--------------------------------------------------------------------------------

package body pkg_tof_debug_unit is

  ------------------------------------------------------------------------------
  -- Function bodies
  ------------------------------------------------------------------------------

end pkg_tof_debug_unit;