library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity add_const_v1_0 is
	generic (
		-- Users to add parameters here
        BIT_WIDTH : integer := 16
		-- User parameters ends
	);
	port (
		-- Users to add ports here
		clk_CI : in std_logic;
		en_DI  : in std_logic;
        datain_DI  : in  std_logic_vector(BIT_WIDTH-1 downto 0);
        dataout_DO : out std_logic_vector(BIT_WIDTH-1 downto 0);
        satin_DI   : in  std_logic;
        satout_DO  : out std_logic;
		-- from reg_bank
		const_en_SI : in std_logic;
		const_val_DI : in std_logic_vector(BIT_WIDTH downto 0);
		max_val_Di : in std_logic_vector(BIT_WIDTH-1 downto 0)
		-- User ports ends
	);
end add_const_v1_0;

architecture arch_imp of add_const_v1_0 is

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
	-- User logic ends

end arch_imp;
