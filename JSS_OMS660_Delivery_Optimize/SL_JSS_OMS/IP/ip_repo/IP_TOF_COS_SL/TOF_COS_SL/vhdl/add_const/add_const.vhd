----------------------------------------------------------------------------------
-- Company: ESPROS
-- Engineer: msc
-- 
-- Create Date: 12/15/2017 08:53:09 AM
-- Design Name: add_const
-- Module Name: add_const - Behavioral
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

entity ip_add_const is
	generic (
        BIT_WIDTH : integer
	);
	port (
		clk_CI       : in std_logic;
		en_DI        : in std_logic;
        datain_DI    : in  std_logic_vector(BIT_WIDTH-1 downto 0);
        dataout_DO   : out std_logic_vector(BIT_WIDTH-1 downto 0);
        satin_DI     : in  std_logic;
        satout_DO    : out std_logic;
		const_en_SI  : in std_logic;
		const_val_DI : in std_logic_vector(BIT_WIDTH downto 0);
		max_val_DI   : in std_logic_vector(BIT_WIDTH-1 downto 0)
	);
end ip_add_const;

architecture arch_imp of ip_add_const is

	signal sum_D : std_logic_vector(BIT_WIDTH downto 0);

begin
	
    -- Sum constant with input
    process(const_val_DI, datain_DI, max_val_DI)
    begin
        if const_val_DI(BIT_WIDTH) = '1' then -- negative constant added
            if signed('0' & datain_DI) < abs(signed(const_val_DI)) then
                sum_D <= std_logic_vector(signed('0' & max_val_DI) + signed(const_val_DI) + signed('0' & datain_DI));
            else
                sum_D <= std_logic_vector(signed(const_val_DI) + signed('0' & datain_DI));
            end if;
        else -- positive constant added
            if ('0' & unsigned(datain_DI) + unsigned(const_val_DI(BIT_WIDTH-1 downto 0))) > unsigned(max_val_DI)  then
               sum_D <= std_logic_vector(unsigned(const_val_DI) + unsigned(datain_DI) - unsigned(max_val_DI)); 
            else
                sum_D <= std_logic_vector(unsigned(const_val_DI) + unsigned('0' & datain_DI));
            end if;
        end if;         
    end process;
    
    -- output stage
    process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if en_DI = '0' then
                dataout_DO <= (others => '0');
                satout_DO <= '0';
            else
                if const_en_SI = '0' then
                    dataout_DO <= datain_DI;
                    satout_DO  <= satin_DI;
                else
                    dataout_DO <= sum_D(BIT_WIDTH-1 downto 0);
                    satout_DO  <= satin_DI;       
                end if;
            end if;
        end if;
    end process;

end arch_imp;
