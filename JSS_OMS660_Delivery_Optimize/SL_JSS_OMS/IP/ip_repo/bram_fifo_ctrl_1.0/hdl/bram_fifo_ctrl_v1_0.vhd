library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity bram_fifo_ctrl_v1_0 is
	generic (
		-- Users to add parameters here
        NBITS_DATA : integer := 12;
        NBITS_DEPT_FIFO0 : integer := 16; -- We assume FIFO0 > FIFO1
        NBITS_DEPT_FIFO1 : integer := 14
		-- User parameters ends
	);
	port (
	    clk_CI : in std_logic;
	    resetn_RBI : in std_logic;
	    rden_SI : in std_logic;
	    
		-- Write FIFO
		wr_pulse_in_DI : in  std_logic;
		wr_data_in_DI  : in  std_logic_vector(NBITS_DATA-1 downto 0);
		
		wr_en_f0_DO    : out std_logic;
		wr_data_f0_DO  : out std_logic_vector(NBITS_DATA-1 downto 0);
		wr_en_f1_DO    : out std_logic;
		wr_data_f1_DO  : out std_logic_vector(NBITS_DATA-1 downto 0);
        
		-- Read FIFO
		rd_pulse_in_DI : in  std_logic;
		rd_data_out_DO : out std_logic_vector(NBITS_DATA-1 downto 0);
		
		rd_data_f0_DI  : in  std_logic_vector(NBITS_DATA-1 downto 0);
		rd_data_f1_DI  : in  std_logic_vector(NBITS_DATA-1 downto 0);
		
		-- common FIFO
		f0_pulse_DO    : out std_logic; 
	    f1_pulse_DO    : out std_logic; 
	    f0_addr_DO     : out std_logic_vector(NBITS_DEPT_FIFO0-1 downto 0);	
        f1_addr_DO     : out std_logic_vector(NBITS_DEPT_FIFO1-1 downto 0)		
	);
end bram_fifo_ctrl_v1_0;

architecture arch_imp of bram_fifo_ctrl_v1_0 is

    signal wr_cnt_D : unsigned(NBITS_DEPT_FIFO0 downto 0); -- We assume FIFO0 > FIFO1
    signal rd_cnt_D : unsigned(NBITS_DEPT_FIFO0 downto 0); -- We assume FIFO0 > FIFO1
    signal wr_pulse_D : std_logic;
    signal wr_pulse_f0_D : std_logic;
    signal wr_pulse_f1_D : std_logic;
    signal rd_pulse_D : std_logic;
    signal rd_pulse_f0_D : std_logic;
    signal rd_pulse_f1_D : std_logic;
    signal wr_addr_f0_D : std_logic_vector(NBITS_DEPT_FIFO0-1 downto 0);
    signal wr_addr_f1_D : std_logic_vector(NBITS_DEPT_FIFO1-1 downto 0);
    signal rd_addr_f0_D : std_logic_vector(NBITS_DEPT_FIFO0-1 downto 0);
    signal rd_addr_f1_D : std_logic_vector(NBITS_DEPT_FIFO1-1 downto 0);
    signal wr_sel_fifo1_S : std_logic;
    signal rd_sel_fifo1_S : std_logic;
	signal rd_en_S : std_logic;
    
begin

    -- select FIFO to write
    process(wr_cnt_D)
    begin
        if wr_cnt_D(NBITS_DEPT_FIFO0) = '1' then
            wr_sel_fifo1_S <= '1';
        else
            wr_sel_fifo1_S <= '0';
        end if;
    end process;   
    
    process(rd_cnt_D)
    begin
        if rd_cnt_D(NBITS_DEPT_FIFO0) = '1' then
            rd_sel_fifo1_S <= '1';
        else
            rd_sel_fifo1_S <= '0';
        end if;
    end process; 
    
    -- Counters
    process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if resetn_RBI = '0' then
                wr_cnt_D <= (others => '0');
                rd_cnt_D <= (others => '0');
            else
                if wr_pulse_D = '1' then
                    wr_cnt_D <= wr_cnt_D + 1;
                end if;
                if rd_pulse_D = '1' then
                    rd_cnt_D <= rd_cnt_D + 1;
                end if;
            end if;
        end if;
    end process;
    
    -- Data / Control signals
    process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if resetn_RBI = '0' then
                wr_pulse_D <= '0';
                wr_pulse_f0_D <= '0';
                wr_pulse_f1_D <= '0';
                wr_data_f0_DO <= (others => '0');
                wr_addr_f0_D  <= (others => '0');                
                wr_data_f1_DO <= (others => '0');
                wr_addr_f1_D  <= (others => '0');    
                rd_pulse_D <= '0';     
				rd_en_S <= '0';
            else
				rd_en_S <= rden_SI;
                -- Write
                -- handle pulse
                if wr_pulse_in_DI = '1' then
                    wr_pulse_D <= '1';
                    if wr_sel_fifo1_S = '1' then 
                        wr_pulse_f0_D <= '0';
                        wr_pulse_f1_D <= '1';
                    else
                        wr_pulse_f0_D <= '1';
                        wr_pulse_f1_D <= '0';
                    end if;
                else
                    wr_pulse_D <= '0';
                    wr_pulse_f0_D <= '0';
                    wr_pulse_f1_D <= '0';
                end if;
                -- handle data / addr
                if wr_sel_fifo1_S = '1' then -- write to FIFO1
                    wr_data_f1_DO <= wr_data_in_DI;
                    wr_addr_f1_D  <= std_logic_vector(wr_cnt_D(NBITS_DEPT_FIFO1-1 downto 0));        
                else -- write to FIFO0
                    wr_data_f0_DO <= wr_data_in_DI;
                    wr_addr_f0_D  <= std_logic_vector(wr_cnt_D(NBITS_DEPT_FIFO0-1 downto 0));                   
                end if;
                -- Read
                -- handle pulse
                if rd_pulse_in_DI = '1' then
                    rd_pulse_D <= '1';
                else
                    rd_pulse_D <= '0';
                end if;            
                -- handle data / addr
                if rd_sel_fifo1_S = '1' then -- write to FIFO1
                    rd_data_out_DO <= rd_data_f1_DI;
                    rd_addr_f1_D  <= std_logic_vector(rd_cnt_D(NBITS_DEPT_FIFO1-1 downto 0));        
                else -- write to FIFO0
                    rd_data_out_DO <= rd_data_f0_DI;
                    rd_addr_f0_D  <= std_logic_vector(rd_cnt_D(NBITS_DEPT_FIFO0-1 downto 0));                   
                end if;                
            end if;
        end if;
    end process;
    
    process(rd_sel_fifo1_S, rd_pulse_in_DI)
    begin
        if rd_sel_fifo1_S = '1' then
            rd_pulse_f0_D <= '0';
            rd_pulse_f1_D <= rd_pulse_in_DI;
        else
            rd_pulse_f0_D <= rd_pulse_in_DI;
            rd_pulse_f1_D <= '0';
        end if;
    end process;    
    
    -- Handle read/write
    process(rd_en_S, wr_pulse_f0_D, wr_pulse_f1_D, wr_addr_f0_D, wr_addr_f1_D, rd_pulse_f0_D, rd_pulse_f1_D, rd_addr_f0_D, rd_addr_f1_D)
    begin
        if rd_en_S = '0' then
            f0_pulse_DO <= wr_pulse_f0_D;
            f1_pulse_DO <= wr_pulse_f1_D;
            f0_addr_DO  <= wr_addr_f0_D;
            f1_addr_DO  <= wr_addr_f1_D;
            wr_en_f0_DO <= '1';
            wr_en_f1_DO <= '1';
        else
            f0_pulse_DO <= rd_pulse_f0_D;
            f1_pulse_DO <= rd_pulse_f1_D;
            f0_addr_DO  <= rd_addr_f0_D;
            f1_addr_DO  <= rd_addr_f1_D;
            wr_en_f0_DO <= '0';
            wr_en_f1_DO <= '0';            
        end if;
    end process;

end arch_imp;
