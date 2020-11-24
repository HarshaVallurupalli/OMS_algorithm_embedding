----------------------------------------------------------------------------------
-- Company: ESPROS		
-- Engineer: msc
-- 
-- Create Date: 19/12/2017 09:58:51 AM
-- Design Name: edge_detector
-- Module Name: edge_detector - Behavioral
--
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ip_edge_detector is
	generic (
		RISING	: boolean;
		FALLING	: boolean;
		PULSE_LENGTH: integer;
		NEG_OUTPUT : boolean
	);
	port (
	    clk_CI : in  std_logic;
	    en_DI  : in  std_logic;
        in_DI  : in  std_logic;
        out_DO : out std_logic
	);
end ip_edge_detector;

architecture arch_imp of ip_edge_detector is
    signal out_D : std_logic_vector(PULSE_LENGTH downto 0);
    signal in_reg_D : std_logic;
begin
	
	process(clk_CI)
	begin
	   if rising_edge(clk_CI) then
	       if en_DI = '0' then
	           in_reg_D <= '0';
	           out_DO <= '0';
	       else
	           in_reg_D <= in_DI;
	           -- Negate output if requested
	           if NEG_OUTPUT = true then
	               if unsigned(out_D(PULSE_LENGTH-1 downto 0))>0 then
	                   out_DO <= '0';
	               else
	                   out_DO <= '1';
	               end if;
	           else
	               if unsigned(out_D(PULSE_LENGTH-1 downto 0))>0 then
	                   out_DO <= '1';
	               else
                       out_DO <= '0';
                   end if;
	           end if;
	       end if;
	   end if;
	end process;
	
	-- logic
	process(clk_CI)
	begin
	   if rising_edge(clk_CI) then
		-- both edges
		if RISING = true and FALLING = true then
			out_D <= out_D(PULSE_LENGTH-1 downto 0) & (in_DI xor in_reg_D);
		-- rising
		elsif RISING = true then
			out_D <= out_D(PULSE_LENGTH-1 downto 0) & ((in_DI xor in_reg_D) and in_DI);
		-- falling
		elsif FALLING = true then
			out_D <= out_D(PULSE_LENGTH-1 downto 0) & ((in_DI xor in_reg_D) and in_reg_D);
		-- none
		else
			out_D <= (others => '0');
		end if;
	   end if;
	end process;

end arch_imp;
