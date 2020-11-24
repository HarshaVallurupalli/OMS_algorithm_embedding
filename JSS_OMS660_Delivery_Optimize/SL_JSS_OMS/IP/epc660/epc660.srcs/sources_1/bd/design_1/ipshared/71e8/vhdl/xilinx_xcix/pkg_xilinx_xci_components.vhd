--------------------------------------------------------------------------------
-- Creation
--
-- Copyright : ESPROS Photonics AG (epc)
-- Project   : TOF_cos_sl
-- Date      : 09-18-2019
-- Author    : msc
--
--------------------------------------------------------------------------------
-- Description
--
-- Package of xilinx_xcix_components
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
package pkg_xilinx_xci_components is

  ------------------------------------------------------------------------------
  -- Component declarations
  ------------------------------------------------------------------------------

  COMPONENT div_gen_alu
    PORT (
      aclk : IN STD_LOGIC;
      s_axis_divisor_tvalid : IN STD_LOGIC;
      s_axis_divisor_tdata : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
      s_axis_dividend_tvalid : IN STD_LOGIC;
      s_axis_dividend_tdata : IN STD_LOGIC_VECTOR(23 DOWNTO 0);
      m_axis_dout_tvalid : OUT STD_LOGIC;
      m_axis_dout_tdata : OUT STD_LOGIC_VECTOR(39 DOWNTO 0)
    );
  END COMPONENT;
  
  COMPONENT div_gen_dist_offset
    PORT (
      aclk : IN STD_LOGIC;
      s_axis_divisor_tvalid : IN STD_LOGIC;
      s_axis_divisor_tdata : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
      s_axis_dividend_tvalid : IN STD_LOGIC;
      s_axis_dividend_tdata : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
      m_axis_dout_tvalid : OUT STD_LOGIC;
      m_axis_dout_tdata : OUT STD_LOGIC_VECTOR(47 DOWNTO 0)
    );
  END COMPONENT;
  
  COMPONENT div_gen_gs_comp
    PORT (
      aclk : IN STD_LOGIC;
      s_axis_divisor_tvalid : IN STD_LOGIC;
      s_axis_divisor_tdata : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
      s_axis_dividend_tvalid : IN STD_LOGIC;
      s_axis_dividend_tdata : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
      m_axis_dout_tvalid : OUT STD_LOGIC;
      m_axis_dout_tdata : OUT STD_LOGIC_VECTOR(47 DOWNTO 0)
    );
  END COMPONENT;
  
  COMPONENT mult_gen_dist
    PORT (
      CLK : IN STD_LOGIC;
      A : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
      B : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
      P : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)
    );
  END COMPONENT;

  ------------------------------------------------------------------------------
  -- Type declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Function declarations
  ------------------------------------------------------------------------------

end pkg_xilinx_xci_components;

--------------------------------------------------------------------------------
-- Package body
--------------------------------------------------------------------------------

package body pkg_xilinx_xci_components is

  ------------------------------------------------------------------------------
  -- Function bodies
  ------------------------------------------------------------------------------

end pkg_xilinx_xci_components;