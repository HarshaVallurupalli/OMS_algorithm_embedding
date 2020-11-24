library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity DCSsat_detect_v1_0 is
	port (
		-- Users to add ports here
        DCSin_DI : in std_logic_vector(12 downto 0);
        DCSsat_DO : out std_logic;
        ADCunderflow_en_SI : in std_logic;
        ADCoverflow_en_SI : in std_logic
	);
end DCSsat_detect_v1_0;

architecture arch_imp of DCSsat_detect_v1_0 is
    
begin
	-- Add user logic here
	-- reg_en_D bit[0] : Check for ADC overflow ; bit[1] : Check for ADC underflow
    process(ADCunderflow_en_SI, ADCoverflow_en_SI, DCSin_DI)
    begin
        if (ADCoverflow_en_SI = '1' and unsigned(DCSin_DI(11 downto 0)) > 4094) or (ADCunderflow_en_SI = '1' and unsigned(DCSin_DI(11 downto 0)) < 1) then
            DCSsat_DO <= '1';
        else
            DCSsat_DO <= '0';
        end if;
    end process;
	-- User logic ends

end arch_imp;
