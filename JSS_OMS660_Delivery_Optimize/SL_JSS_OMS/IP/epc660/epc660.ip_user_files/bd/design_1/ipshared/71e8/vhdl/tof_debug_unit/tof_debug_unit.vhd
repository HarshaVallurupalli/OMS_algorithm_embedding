----------------------------------------------------------------------------------
-- Company: ESPROS		
-- Engineer: asc
-- 
-- Create Date: 01/07/2020
-- Design Name: ip_tof_debug_unit
-- Module Name: ip_tof_debug_unit
--
-- Revision:
-- Revision 0.1 - File Created
-- Additional Comments: Debug register unit
--                      Saves particular pixel values (raw & processed to a BRAM 
--                      for debug purposes
-- 
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

library xil_defaultlib;
use xil_defaultlib.pkg_tof_debug_unit_pxl_sel.all;

-- tof_debug_unit
entity ip_tof_debug_unit is
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
end ip_tof_debug_unit;

architecture rtl of ip_tof_debug_unit is

    -- local functions
    function toOr (a : std_logic_vector) return std_logic is
        constant a_c : std_logic_vector (a'range) := a;
        variable r_v : std_logic;
    begin
        r_v := '0';
        if unsigned (a_c) /= 0 then 
            r_v := '1';
        end if;
        return r_v;
    end function toOr;
    
    function toZeros (len : positive) return std_logic_vector is
        constant r_c : std_logic_vector(len-1 downto 0) := (others => '0');
    begin
        return r_c;
    end function toZeros;

    -- debug pixel selection
    signal DcsRawX_Sel          : std_logic_vector(3 downto 0);
    signal DcsAmbX_Sel          : std_logic_vector(1 downto 0);
    signal DistRaw_Sel          : std_logic;
    signal DistComp_Sel         : std_logic;
    signal GsRaw_Sel            : std_logic;
    signal GsComp_Sel           : std_logic;
    
	-- bram control signals
    signal DbgBram_Addr_Next    : std_logic_vector(NBITS_BRAM_ADDR-1 downto 0);
    signal DbgBram_Data_Next    : std_logic_vector(NBITS_BRAM_DATA-1 downto 0);
    signal DbgBram_Wen_Next     : std_logic;
    
begin


    -- bram content:
    --      each pixel value saved as 32bit
    --
    --      Addr [byte] Value
    --      -----------------------
    --      0x00        DCS raw 0
    --      0x04        DCS raw 1
    --      0x08        DCS raw 2
    --      0x0C        DCS raw 3
    --      0x10        DCS ambient comp 0
    --      0x14        DCS ambient comp 1
    --      0x20        Distance raw
    --      0x24        Distance comp 
    --      0x30        Grayscale raw
    --      0x34        Grayscale comp

    ----------------------------------------
    -- raw dcs
    ----------------------------------------
    -- raw dcs 0, .., 3
    gen_pxl_sel_dcs_raw_i : for i in 0 to 3 generate
    begin
        i_pxlsel_dcs_raw : ip_tof_debug_unit_pxl_sel
            generic map (
                NBITS_DATA          => NBITS_DATA,
                NBITS_FRAME_LENGTH  => NBITS_FRAME_LENGTH)
            port map ( 
                -- clock and reset
                Clk             => Clk,
                Rst             => Rst,
                
                -- control inputs
                Ena             => Ena,
                Rb_PxlCount     => Rb_PxlCount,
                Rb_DbgPxlIdx    => Rb_DbgPxlIdx,
                
                -- data intput interfaces
                Data_Vld        => DcsRawX_Vld(i), 
                DbgPxl_Sel      => DcsRawX_Sel(i)
            );
    end generate gen_pxl_sel_dcs_raw_i;
    
    -- ambient comp 0, 1
    gen_pxl_sel_dcs_amb_i : for i in 0 to 1 generate
    begin
        i_pxlsel_dcs_amb : ip_tof_debug_unit_pxl_sel
            generic map (
                NBITS_DATA          => NBITS_DATA,
                NBITS_FRAME_LENGTH  => NBITS_FRAME_LENGTH)
            port map ( 
                -- clock and reset
                Clk             => Clk,
                Rst             => Rst,
                
                -- control inputs
                Ena             => Ena,
                Rb_PxlCount     => Rb_PxlCount,
                Rb_DbgPxlIdx    => Rb_DbgPxlIdx,
                
                -- data intput interfaces
                Data_Vld        => DcsAmbX_Vld(i), 
                DbgPxl_Sel      => DcsAmbX_Sel(i)
            );
    end generate gen_pxl_sel_dcs_amb_i;   
    
    -- distance raw
    i_pxlsel_dist_raw : ip_tof_debug_unit_pxl_sel
        generic map (
            NBITS_DATA          => NBITS_DATA,
            NBITS_FRAME_LENGTH  => NBITS_FRAME_LENGTH)
        port map ( 
            -- clock and reset
            Clk             => Clk,
            Rst             => Rst,
            
            -- control inputs
            Ena             => Ena,
            Rb_PxlCount     => Rb_PxlCount,
            Rb_DbgPxlIdx    => Rb_DbgPxlIdx,
            
            -- data intput interfaces
            Data_Vld        => DistRaw_Vld,
            DbgPxl_Sel      => DistRaw_Sel
        );
    
    -- distance compensated
    i_pxlsel_dist_comp : ip_tof_debug_unit_pxl_sel
        generic map (
            NBITS_DATA          => NBITS_DATA,
            NBITS_FRAME_LENGTH  => NBITS_FRAME_LENGTH)
        port map ( 
            -- clock and reset
            Clk             => Clk,
            Rst             => Rst,
            
            -- control inputs
            Ena             => Ena,
            Rb_PxlCount     => Rb_PxlCount,
            Rb_DbgPxlIdx    => Rb_DbgPxlIdx,
            
            -- data intput interfaces
            Data_Vld        => DistComp_Vld,
            DbgPxl_Sel      => DistComp_Sel
        );
    
    
    -- grayscale raw
    i_pxlsel_gs_raw : ip_tof_debug_unit_pxl_sel
        generic map (
            NBITS_DATA          => NBITS_DATA,
            NBITS_FRAME_LENGTH  => NBITS_FRAME_LENGTH)
        port map ( 
            -- clock and reset
            Clk             => Clk,
            Rst             => Rst,
            
            -- control inputs
            Ena             => Ena,
            Rb_PxlCount     => Rb_PxlCount,
            Rb_DbgPxlIdx    => Rb_DbgPxlIdx,
            
            -- data intput interfaces
            Data_Vld        => GsRaw_Vld, 
            DbgPxl_Sel      => GsRaw_Sel
        );
    
    -- grayscale compensated
    i_pxlsel_gs_comp : ip_tof_debug_unit_pxl_sel
        generic map (
            NBITS_DATA          => NBITS_DATA,
            NBITS_FRAME_LENGTH  => NBITS_FRAME_LENGTH)
        port map ( 
            -- clock and reset
            Clk             => Clk,
            Rst             => Rst,
            
            -- control inputs
            Ena             => Ena,
            Rb_PxlCount     => Rb_PxlCount,
            Rb_DbgPxlIdx    => Rb_DbgPxlIdx,
            
            -- data intput interfaces
            Data_Vld        => GsComp_Vld,
            DbgPxl_Sel      => GsComp_Sel
        );
    

    -- control unit
 
    
    p_ctrl : process (Clk)
    begin
        if rising_edge (Clk) then
            -- write strobe
            DbgBram_Wen_Next <= toOr (DcsRawX_Sel and DcsRawX_Vld)
                            or  toOr (DcsAmbX_Sel and DcsAmbX_Vld)
                            or       (DistRaw_Sel and DistRaw_Vld) 
                            or       (DistComp_Sel and DistComp_Vld)
                            or       (GsRaw_Sel and   GsRaw_Vld)
                            or       (GsComp_Sel and  GsComp_Vld);
                            
            -- address & data mux
            if      (DcsRawX_Sel(0) and DcsRawX_Vld(0)) = '1' then
                -- DCS0 raw
                DbgBram_Addr_Next   <= std_logic_vector(to_unsigned(16#00#/4, NBITS_BRAM_ADDR));
                DbgBram_Data_Next   <= toZeros(NBITS_BRAM_DATA-NBITS_DATA) & DcsRawX_Data;
            elsif   (DcsRawX_Sel(1) and DcsRawX_Vld(1)) = '1' then
                -- DCS1 raw
                DbgBram_Addr_Next   <= std_logic_vector(to_unsigned(16#04#/4, NBITS_BRAM_ADDR));
                DbgBram_Data_Next   <= toZeros(NBITS_BRAM_DATA-NBITS_DATA) & DcsRawX_Data;
            elsif   (DcsRawX_Sel(2) and DcsRawX_Vld(2)) = '1' then
                -- DCS2 raw
                DbgBram_Addr_Next   <= std_logic_vector(to_unsigned(16#08#/4, NBITS_BRAM_ADDR));
                DbgBram_Data_Next   <= toZeros(NBITS_BRAM_DATA-NBITS_DATA) & DcsRawX_Data;
            elsif   (DcsRawX_Sel(3) and DcsRawX_Vld(3)) = '1' then
                -- DCS3 raw
                DbgBram_Addr_Next   <= std_logic_vector(to_unsigned(16#0C#/4, NBITS_BRAM_ADDR));
                DbgBram_Data_Next   <= toZeros(NBITS_BRAM_DATA-NBITS_DATA) & DcsRawX_Data;
            
            elsif   (DcsAmbX_Sel(0) and DcsAmbX_Vld(0)) = '1' then
                -- DCS0 ambient compensated
                DbgBram_Addr_Next   <= std_logic_vector(to_unsigned(16#10#/4, NBITS_BRAM_ADDR));
                DbgBram_Data_Next   <= toZeros(NBITS_BRAM_DATA-NBITS_DATA) & DcsAmbX_Data;
            elsif   (DcsAmbX_Sel(1) and DcsAmbX_Vld(1)) = '1' then
                -- DCS1 ambient compensated
                DbgBram_Addr_Next   <= std_logic_vector(to_unsigned(16#14#/4, NBITS_BRAM_ADDR));
                DbgBram_Data_Next   <= toZeros(NBITS_BRAM_DATA-NBITS_DATA) & DcsAmbX_Data;
            
            elsif   (DistRaw_Sel and DistRaw_Vld) = '1' then
                -- distance raw
                DbgBram_Addr_Next   <= std_logic_vector(to_unsigned(16#20#/4, NBITS_BRAM_ADDR));
                DbgBram_Data_Next   <= toZeros(NBITS_BRAM_DATA-NBITS_DATA) & DistRaw_Data;
            elsif   (DistComp_Sel and DistComp_Vld) = '1' then
                -- distance compensated
                DbgBram_Addr_Next   <= std_logic_vector(to_unsigned(16#24#/4, NBITS_BRAM_ADDR));
                DbgBram_Data_Next   <= toZeros(NBITS_BRAM_DATA-NBITS_DATA) & DistComp_Data;
            
            elsif   (GsRaw_Sel and   GsRaw_Vld) = '1' then
                -- grayscale raw
                DbgBram_Addr_Next   <= std_logic_vector(to_unsigned(16#30#/4, NBITS_BRAM_ADDR));
                DbgBram_Data_Next   <= toZeros(NBITS_BRAM_DATA-NBITS_DATA) & GsRaw_Data;
            elsif   (GsComp_Sel and  GsComp_Vld) = '1' then
                -- grayscale compensated
                DbgBram_Addr_Next   <= std_logic_vector(to_unsigned(16#34#/4, NBITS_BRAM_ADDR));
                DbgBram_Data_Next   <= toZeros(NBITS_BRAM_DATA-NBITS_DATA) & GsComp_Data;
            end if;
 
            -- reset handling
            if Rst = '1' then
                DbgBram_Wen_Next    <= '0';
            end if;
        end if;
    end process;
    
    
    -- output registers
    p_reg : process(Clk)
    begin
        if rising_edge(Clk) then
            DbgBram_Addr                                <= (others => '0');
            DbgBram_Addr(NBITS_BRAM_ADDR+1 downto 0)    <= DbgBram_Addr_Next & "00";
            DbgBram_Data    <= DbgBram_Data_Next;
            DbgBram_Wen     <= (others => DbgBram_Wen_Next);
        end if;
    end process;
    
    
end rtl;
-- end ip_tof_debug_unit
