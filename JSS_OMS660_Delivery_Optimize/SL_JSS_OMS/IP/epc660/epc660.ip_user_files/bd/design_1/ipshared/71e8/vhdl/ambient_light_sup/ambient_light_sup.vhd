----------------------------------------------------------------------------------
-- Company: ESPROS
-- Engineer: msc
-- 
-- Create Date: 12/15/2017 08:53:09 AM
-- Design Name: ambient_light_sup
-- Module Name: ambient_light_sup - Behavioral
-- Project Name: TOFcos_sl
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ip_ambient_light_sup is
	generic (
		NBITS_DATA    : integer;
		NBITS_COMP    : integer;
		NBITS_COMP_FP : integer
	);
	port (
		clk_CI          : in std_logic;
		en_DI           : in std_logic;
		resetn_RBI      : in std_logic;
        GS_DI           : in std_logic_vector(NBITS_DATA downto 0);
        DCS_DI          : in std_logic_vector(NBITS_DATA downto 0);
        DCScorr_DO      : out std_logic_vector(NBITS_DATA downto 0);
		-- from reg_bank
		ambient_comp_DI : in std_logic_vector(NBITS_COMP-1 downto 0) -- NBITS_COMP_FP floating point
	);
end ip_ambient_light_sup;

architecture arch_imp of ip_ambient_light_sup is    
    -- Custom signals
    signal GSin_D : std_logic_vector(NBITS_DATA-1 downto 0);
    signal GS_thr_D : std_logic_vector(NBITS_DATA-1 downto 0);
    signal GSin_sat_D : std_logic;
    signal DCSin_D : std_logic_vector(NBITS_DATA-1 downto 0);
    signal DCSin_sat_D : std_logic;
    signal GS_comp_D : std_logic_vector(NBITS_COMP downto 0);
    signal DCS_mGS_D : std_logic_vector(NBITS_DATA downto 0);
    signal DCSout_D : std_logic_vector(NBITS_DATA-1 downto 0);
    signal DCSout_sat_D : std_logic;
    
begin

	-- Input FF
	process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if resetn_RBI='0' then
                GSin_D <= (others => '0');
                GSin_sat_D <= '0';
                DCSin_D <= (others => '0');
                DCSin_sat_D <= '0';      
            else
                GSin_D <= GS_DI(NBITS_DATA-1 downto 0);
                GSin_sat_D <= GS_DI(NBITS_DATA);
                DCSin_D <= DCS_DI(NBITS_DATA-1 downto 0);
                DCSin_sat_D <= DCS_DI(NBITS_DATA);
            end if;
        end if;
    end process;
   
    -- Multiply GS with comp const
    process(GSin_D, ambient_comp_DI)
    begin
        GS_comp_D <= std_logic_vector(shift_right(unsigned(GSin_D) * unsigned(ambient_comp_DI),NBITS_COMP_FP)(NBITS_COMP downto 0)); -- Shift right by NBITS_COMP_FP; fixed floating point
    end process;
    
    -- Subtract GS_comp from DCS
    process(DCSin_D, GS_comp_D)
    begin
        DCS_mGS_D <= std_logic_vector(signed('0' & DCSin_D) - signed('0' & GS_comp_D(NBITS_DATA-1 downto 0)));
    end process;

    -- Output reg
    process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if (resetn_RBI='0') then
                DCScorr_DO <= (others => '0');
            elsif en_DI = '1' then
                DCScorr_DO(NBITS_DATA) <= DCSin_sat_D or ((GS_comp_D(NBITS_DATA) or DCS_mGS_D(NBITS_DATA) or GSin_sat_D));
                DCScorr_DO(NBITS_DATA-1 downto 0) <= DCS_mGS_D(NBITS_DATA-1 downto 0);                
            else
                DCScorr_DO(NBITS_DATA) <= DCS_DI(NBITS_DATA);
                DCScorr_DO(NBITS_DATA-1 downto 0) <= DCS_DI(NBITS_DATA-1 downto 0);
            end if;
        end if;
    end process;
end arch_imp;
