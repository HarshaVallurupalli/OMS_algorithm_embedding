library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity reg_stage_v1_0 is
	generic (
        BIT_WIDTH	: integer	:= 1;
        NB_STAGES	: integer	:= 1
	);
	port (
        en_DI   : in  std_logic;
        clk_CI  : in  std_logic;
        data_DI : in  std_logic_vector(BIT_WIDTH-1 downto 0);
        data_DO : out std_logic_vector(BIT_WIDTH-1 downto 0)
	);
end reg_stage_v1_0;

architecture arch_imp of reg_stage_v1_0 is

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
