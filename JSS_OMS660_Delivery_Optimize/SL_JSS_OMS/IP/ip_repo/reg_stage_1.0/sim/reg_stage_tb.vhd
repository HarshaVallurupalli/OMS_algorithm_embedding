----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 01/03/2018 11:31:22 AM
-- Design Name: 
-- Module Name: reg_stage_tb - Behavioral
-- Project Name: 
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


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity reg_stage_tb is
--  Port ( );
end reg_stage_tb;

architecture Behavioral of reg_stage_tb is

    constant BIT_WIDTH : integer := 3;
    constant NB_STAGES : integer := 5;

    component reg_stage_v1_0 is
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
end component;

    signal din   : std_logic_vector(BIT_WIDTH-1 downto 0) := (others => '0');
    signal dout  : std_logic_vector(BIT_WIDTH-1 downto 0);
    signal en_S  : std_logic := '0';
    signal clk_C : std_logic := '0';
    constant TCLK_PER : time := 10 ns;
begin

    -- Connect instance
    UUT: reg_stage_v1_0 
    generic map (
        BIT_WIDTH => BIT_WIDTH,
        NB_STAGES => NB_STAGES
    )
    port map (
        en_DI => en_S,
        clk_CI => clk_C,
        data_DI => din,
        data_DO => dout
    );
    
    p_clk_gen : process
    begin
        clk_C <= '0';
        wait for TCLK_PER/2;
        clk_C <= '1';
        wait for TCLK_PER/2;
    end process;
    
    p_tb : process
    begin
        wait for 100 ns;
        en_S <= '1';
        wait for 100 ns;
        din <= (others => '1');
        wait for 200 ns;
         din <= (others => '0');
        wait for 200 ns;     
        din <= (others => '1');
        wait for 200 ns;
        din <= (others => '0');
        wait for 200 ns;
        din <= (others => '1');
        wait for 200 ns;  
        en_S <= '0';
        wait;
    end process;

end Behavioral;
