library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ambient_light_sup_v1_0 is
	port (
		-- Users to add ports here
		clk_CI : in std_logic;
		en_DI : in std_logic;
		resetn_RBI : in std_logic;
        GS_DI : in std_logic_vector(12 downto 0);
        DCS_DI : in std_logic_vector(12 downto 0);
        DCScorr_DO : out std_logic_vector(12 downto 0);
		-- from reg_bank
		ambient_thr_DI : in std_logic_vector(11 downto 0);
		ambient_comp_DI : in std_logic_vector(11 downto 0)
	);
end ambient_light_sup_v1_0;

architecture arch_imp of ambient_light_sup_v1_0 is    
    -- Custom signals
    signal GSin_D : std_logic_vector(11 downto 0);
    signal GS_thr_D : std_logic_vector(11 downto 0);
    signal GSin_sat_D : std_logic;
    signal DCSin_D : std_logic_vector(11 downto 0);
    signal DCSin_sat_D : std_logic;
    signal comp_en_S : std_logic;
    signal GS_comp_D : std_logic_vector(12 downto 0);
    signal DCS_mGS_D : std_logic_vector(12 downto 0);
    signal DCSout_D : std_logic_vector(11 downto 0);
    signal DCSout_sat_D : std_logic;
    
begin

	-- Add user logic here
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
                GSin_D <= GS_DI(11 downto 0);
                GSin_sat_D <= GS_DI(12);
                DCSin_D <= DCS_DI(11 downto 0);
                DCSin_sat_D <= DCS_DI(12);
            end if;
        end if;
    end process;

    -- Compare GS with threshold
    comp_en_S <= '1' when (GSin_D > ambient_thr_DI) else '0';
   
    -- Multiply GS with comp const
    process(comp_en_S, GSin_D, ambient_comp_DI)
    begin
        if comp_en_S = '0' then
            GS_comp_D <= (others => '0');
        else
            GS_comp_D <= std_logic_vector(shift_right(unsigned(GSin_D) * unsigned(ambient_comp_DI),11)(12 downto 0)); -- Shift right by 11 to have a range of up to *2
        end if;
    end process;
    
    -- Subtract GS_comp from DCS
    process(DCSin_D, GS_comp_D)
    begin
        DCS_mGS_D <= std_logic_vector(signed('0' & DCSin_D) - signed('0' & GS_comp_D(11 downto 0)));
    end process;

    -- Output reg
    process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if (resetn_RBI='0') then
                DCScorr_DO <= (others => '0');
            elsif en_DI = '1' then
                DCScorr_DO(12) <= DCSin_sat_D or ((GS_comp_D(12) or DCS_mGS_D(12) or GSin_sat_D) and comp_en_S);
                DCScorr_DO(11 downto 0) <= DCS_mGS_D(11 downto 0);                
            else
                DCScorr_DO(12) <= DCS_DI(12);
                DCScorr_DO(11 downto 0) <= DCS_DI(11 downto 0);
            end if;
        end if;
    end process;
end arch_imp;
