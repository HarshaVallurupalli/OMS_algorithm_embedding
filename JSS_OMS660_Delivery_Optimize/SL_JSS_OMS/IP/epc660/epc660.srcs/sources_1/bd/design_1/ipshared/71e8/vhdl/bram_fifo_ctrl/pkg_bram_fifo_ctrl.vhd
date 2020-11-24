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
-- Package of bram_fifo_ctrl
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
package pkg_bram_fifo_ctrl is

  ------------------------------------------------------------------------------
  -- Constant declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Component declarations
  ------------------------------------------------------------------------------

  component ip_bram_fifo_ctrl is
    generic (
        NBITS_DATA : integer := 16;
        NBITS_DEPT_FIFO0 : integer := 16; -- We assume FIFO0 > FIFO1
        NBITS_DEPT_FIFO1 : integer := 14
	);
    port (
	    clk_CI : in std_logic;
	    resetn_RBI : in std_logic;
	    rden_SI : in std_logic;
	    
		-- Write FIFO
		wr_pulse_in_DI : in  std_logic;
		wr_data_in_DI  : in  std_logic_vector(NBITS_DATA-1 downto 0);
		
		wr_en_f0_DO    : out std_logic;
		wr_data_f0_DO  : out std_logic_vector(NBITS_DATA-1 downto 0);
		wr_en_f1_DO    : out std_logic;
		wr_data_f1_DO  : out std_logic_vector(NBITS_DATA-1 downto 0);
        
		-- Read FIFO
		rd_pulse_in_DI : in  std_logic;
		rd_data_out_DO : out std_logic_vector(NBITS_DATA-1 downto 0);
		
		rd_data_f0_DI  : in  std_logic_vector(NBITS_DATA-1 downto 0);
		rd_data_f1_DI  : in  std_logic_vector(NBITS_DATA-1 downto 0);
		
		-- common FIFO
		f0_pulse_DO    : out std_logic; 
	    f1_pulse_DO    : out std_logic; 
	    f0_addr_DO     : out std_logic_vector(NBITS_DEPT_FIFO0-1 downto 0);	
        f1_addr_DO     : out std_logic_vector(NBITS_DEPT_FIFO1-1 downto 0)	
  );
  end component ip_bram_fifo_ctrl;

  ------------------------------------------------------------------------------
  -- Type declarations
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Function declarations
  ------------------------------------------------------------------------------

end pkg_bram_fifo_ctrl;

--------------------------------------------------------------------------------
-- Package body
--------------------------------------------------------------------------------

package body pkg_bram_fifo_ctrl is

  ------------------------------------------------------------------------------
  -- Function bodies
  ------------------------------------------------------------------------------

end pkg_bram_fifo_ctrl;