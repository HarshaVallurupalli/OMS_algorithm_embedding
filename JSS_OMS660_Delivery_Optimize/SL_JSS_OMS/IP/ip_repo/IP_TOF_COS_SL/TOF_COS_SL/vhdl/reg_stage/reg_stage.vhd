----------------------------------------------------------------------------------
-- Company: ESPROS
-- Engineer: msc
-- 
-- Create Date: 12/15/2017 08:53:09 AM
-- Design Name: reg_stage
-- Module Name: reg_stage - Behavioral
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

entity ip_reg_stage is
	generic (
        BIT_WIDTH	: integer;
        NB_STAGES	: integer
	);
	port (
        en_DI   : in  std_logic;
        clk_CI  : in  std_logic;
        data_DI : in  std_logic_vector(BIT_WIDTH-1 downto 0);
        data_DO : out std_logic_vector(BIT_WIDTH-1 downto 0)
	);
end ip_reg_stage;

architecture arch_imp of ip_reg_stage is

    type REGARRAY is array (NB_STAGES downto 0) of std_logic_vector(BIT_WIDTH-1 downto 0);
    signal reg_D : REGARRAY;

begin

    -- Connect input
    reg_D(0) <= data_DI;

    gen_code_label:  
      for index in 1 to NB_STAGES generate  
      begin  
        process(clk_CI)
        begin
            if rising_edge(clk_CI) then
                if en_DI = '0' then
                    reg_D(index) <= (others => '0');    
                else
                    reg_D(index) <= reg_D(index-1);
                end if;
            end if;
        end process;    
      end generate;  
      
      -- Connect output
      data_DO <= reg_D(NB_STAGES);

end arch_imp;
