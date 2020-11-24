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
-- Package of alu
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
package pkg_alu is

  ------------------------------------------------------------------------------
  -- Constant declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Component declarations
  ------------------------------------------------------------------------------

  component ip_alu is
    generic (
		NBITS_DATA_IN  : positive := 12;
		NBITS_DIST_OUT : positive := 16;
		NBITS_AMP_OUT  : positive := 12;
		NBITS_MININDEX : positive := 8
	);
    port (
		clk_CI         : in STD_LOGIC;
		en_DI          : in STD_LOGIC;
		pulse_DI       : in std_logic;
		pulse_div_DI   : in std_logic;
		pulse_out_DI   : in std_logic;
        udiff0_DI      : in std_logic_vector(NBITS_DATA_IN-1 downto 0);
        sat0_DI        : in std_logic;
        sign0_DI       : in std_logic;
        udiff1_DI      : in std_logic_vector(NBITS_DATA_IN-1 downto 0);
        sat1_DI        : in std_logic;
        sign1_DI       : in std_logic;
        interf_flag_DI : in std_logic;
        dcs_sat_DI     : in std_logic;        
        pulse_div_DO   : out std_logic;
        alu_delayed_DO : out std_logic_vector(38 downto 0);
        alu_div_top_DO : out std_logic_vector(2*NBITS_DATA_IN-1 downto 0);
        alu_div_bot_DO : out std_logic_vector(NBITS_DATA_IN-1 downto 0);
        alu_delayed_DI : in std_logic_vector(38 downto 0);
        alu_div_res_DI : in std_logic_vector(2*NBITS_DATA_IN-1 downto 0);
        corr_d_DI      : in unsigned (NBITS_DATA_IN-1 downto 0);
        corr_a_DI      : in unsigned (NBITS_DATA_IN-1 downto 0);
        minIndex_DI    : in std_logic_vector(NBITS_MININDEX-1 downto 0);
		dist_DO        : out std_logic_vector(NBITS_DIST_OUT-1 downto 0);
		alu_sat_DO     : out std_logic;
		amp_DO         : out std_logic_vector(NBITS_AMP_OUT-1 downto 0);
		minIndex_DO    : out std_logic;
		interf_flag_DO : out std_logic;
		dcssat_DO      : out std_logic;
		chipsat_DO     : out std_logic
  );
  end component ip_alu;

  ------------------------------------------------------------------------------
  -- Type declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Function declarations
  ------------------------------------------------------------------------------

end pkg_alu;

--------------------------------------------------------------------------------
-- Package body
--------------------------------------------------------------------------------

package body pkg_alu is

  ------------------------------------------------------------------------------
  -- Function bodies
  ------------------------------------------------------------------------------

end pkg_alu;