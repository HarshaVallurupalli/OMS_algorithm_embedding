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
-- Package of dist_offset
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
package pkg_dist_offset is

  ------------------------------------------------------------------------------
  -- Constant declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Component declarations
  ------------------------------------------------------------------------------

  component ip_dist_offset is
    generic (
		NBITS_DIST      : integer := 16;
		NBITS_DATA      : integer := 128;
		NBITS_INDEX     : integer := 5;
		RAM_READ_CYCLES : integer := 4;
		NBITS_DLL_STEPS : integer := 8
	);
    port (
		clk_CI                 : in  std_logic;
		en_DI                  : in  std_logic;
		-- distance in/out
		pulse_in_DI            : in  std_logic;
        dist_DI                : in  std_logic_vector(NBITS_DIST-1 downto 0);
		dist_sat_DI            : in  std_logic;
        dist_pix_sat_DI        : in  std_logic;
        dist_DO                : out std_logic_vector(NBITS_DIST-1 downto 0);
		dist_sat_DO            : out std_logic;
		dist_pix_sat_DO        : out std_logic;
		pulse_out_DO           : out std_logic;
		-- FIFO in
		dist_fifo_DI           : in  std_logic_vector(NBITS_DIST+1 downto 0); -- includes normal and pixel saturation bit
        -- RAM control/data
		ram_read_pulse_DI      : in  std_logic;
        ram_data_DI            : in  std_logic_vector(NBITS_DATA-1 downto 0);
        ram_read_pulse_DO      : out std_logic;
        ram_index_DO           : out std_logic_vector(NBITS_INDEX-1 downto 0);
		-- division / delay data
        dividend_DO            : out std_logic_vector(2*NBITS_DIST-1 downto 0);
        divisor_DO             : out std_logic_vector(NBITS_DIST-1 downto 0);
        div_pulse_DO           : out std_logic;
		div_res_DI             : in  std_logic_vector(NBITS_DIST-1 downto 0);
		div_pulse_DI           : in  std_logic;
		dist_delay_DI          : in  std_logic_vector(NBITS_DIST+NBITS_INDEX+3 downto 0);
		dist_delay_DO          : out std_logic_vector(NBITS_DIST+NBITS_INDEX+3 downto 0);		
		-- from/to reg_bank
		dist_pix_nb_DI         : in  std_logic_vector(16 downto 0);
		dist_line_nb_DI        : in  std_logic_vector(8 downto 0);
		dist_mean_filter_en_SI : in  std_logic;
		dist_corr_en_SI        : in  std_logic;
		dist_corr_dll_DI       : in  std_logic_vector(15 downto 0);
		dist_nb_dll_steps_DI   : in  std_logic_vector(NBITS_DLL_STEPS-1 downto 0);
		dist_index_trunc_DO    : out std_logic_vector(7 downto 0);
		dist_fail_pos_DO       : out std_logic_vector(16 downto 0);
		dist_index_low_SO      : out std_logic;
		dist_index_high_SO     : out std_logic
  );
  end component ip_dist_offset;

  ------------------------------------------------------------------------------
  -- Type declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Function declarations
  ------------------------------------------------------------------------------

end pkg_dist_offset;

--------------------------------------------------------------------------------
-- Package body
--------------------------------------------------------------------------------

package body pkg_dist_offset is

  ------------------------------------------------------------------------------
  -- Function bodies
  ------------------------------------------------------------------------------

end pkg_dist_offset;