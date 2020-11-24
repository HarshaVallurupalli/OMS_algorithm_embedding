----------------------------------------------------------------------------------
-- Company: ESPROS		
-- Engineer: asc
-- 
-- Create Date: 01/07/2020
-- Design Name: ip_tof_debug_unit_pxl_sel
-- Module Name: ip_tof_debug_unit_pxl_sel
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

-- tof_debug_unit
entity ip_tof_debug_unit_pxl_sel is
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
end ip_tof_debug_unit_pxl_sel;

architecture rtl of ip_tof_debug_unit_pxl_sel is

    signal PxlCntr              : unsigned (NBITS_FRAME_LENGTH downto 0);
     
begin



    p_ctrl : process(Clk)
    begin
        if rising_edge(Clk) then
            if Rst = '1' then
                PxlCntr         <= (others => '0');
                DbgPxl_Sel      <= '0';
            else
                -- pixel counter
                if Data_Vld = '1' then
                    if PxlCntr = unsigned(Rb_PxlCount)-1 then
                        PxlCntr <= (others => '0');
                    else
                        PxlCntr <= PxlCntr+1;
                    end if;
                end if;
                
                -- debug pixel selection, updated 2 cycles after Vld -> ready for next input vld
                if unsigned(Rb_DbgPxlIdx) = PxlCntr then
                    DbgPxl_Sel <= '1';
                else
                    DbgPxl_Sel <= '0';
                end if;
            end if;
        end if;
    end process;
    
    
end rtl;
-- end ip_tof_debug_unit_pxl_sel
