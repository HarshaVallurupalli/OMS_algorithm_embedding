----------------------------------------------------------------------------------
-- Company: ESPROS
-- Engineer: msc
-- 
-- Create Date: 12/15/2017 08:53:09 AM
-- Design Name: dist_mem_ctrl
-- Module Name: dist_mem_ctrl - Behavioral
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

entity ip_dist_mem_ctrl is
	generic (
		NBITS_ADDR : integer
	);
	port (
        clk_CI             : in  std_logic;
        enable_SI          : in  std_logic;
        data_pulse_DI      : in  std_logic;
        -- readRAM               
		read_pulse_DI      : in  std_logic;
        -- BRAM
        read_bram_addr_DO  : out std_logic_vector(NBITS_ADDR-1 downto 0);
        read_bram_en_DO    : out std_logic;
        write_bram_addr_DO : out std_logic_vector(NBITS_ADDR-1 downto 0);
        write_bram_en_DO   : out std_logic
	);
end ip_dist_mem_ctrl;

architecture arch_imp of ip_dist_mem_ctrl is
	-- write ctrl
	signal write_cnt_D    : unsigned(NBITS_ADDR-1 downto 0);
	-- read ctrl
	signal read_cnt_D     : unsigned(NBITS_ADDR-1 downto 0);
begin

	-- pulse outputs
	read_bram_en_DO  <= read_pulse_DI;
	write_bram_en_DO <= data_pulse_DI;
	
	-- internal counts and register outputs
	process(clk_CI)
	begin
		if rising_edge(clk_CI) then
			if enable_SI = '0' then
				write_cnt_D        <= (others => '0');
				read_cnt_D         <= (others => '0');
				write_bram_addr_DO <= (others => '0');
				read_bram_addr_DO  <= (others => '0');		
			else
				write_bram_addr_DO <= std_logic_vector(write_cnt_D);
				read_bram_addr_DO  <= std_logic_vector(read_cnt_D);		
				
				if data_pulse_DI = '1' then
					write_cnt_D <= write_cnt_D + 1;
				end if;
				if read_pulse_DI = '1' then
					read_cnt_D <= read_cnt_D + 1;
				end if;					
			end if;
		end if;
	end process;
	-- User logic ends

end arch_imp;
