----------------------------------------------------------------------------------
-- Company: ESPROS		
-- Engineer: msc
-- 
-- Create Date: 01/05/2017 09:58:51 AM
-- Design Name: tcmi 
-- Module Name: tcmi - Behavioral
--
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;
use ieee.math_real.all;

Library xpm;
use xpm.vcomponents.all;

-- TCMI
entity ip_tcmi is
    Generic (
      ENABLE_INPUT_FIFO : boolean := false;
	  ENABLE_DELAY_NB : positive := 1200;
	  NBITS_DATA_IN : positive := 12;
	  NBITS_LENGTH : positive := 16
	);
	Port ( 
		-- control signals
		clk : in STD_LOGIC;								                -- clk has to be at least 4x faster than dclk!!!
		en : in STD_LOGIC;
		length : in std_logic_vector(NBITS_LENGTH-1 downto 0);          -- dcs length (to generate a last pulse for alu and readout)
        
		-- signals from chip
		dclk_in : in std_logic; 										-- clk input
		vsync_in : in std_logic; 										-- dcs sync 
		hsync_in : in std_logic; 										-- row sync
		xsync_sat_in : in std_logic; 								    -- sat bit
		data_in : in std_logic_vector(NBITS_DATA_IN-1 downto 0);        -- data
		
		-- control out
		active : out std_logic;
		pixel_cnt : out unsigned(NBITS_LENGTH-1 downto 0);
		last_out : out std_logic;

		-- data to RAM
		vsync_SO : out std_logic;
		hsync_SO : out std_logic;
		pulse_out : out std_logic := '0';
		dout : out std_logic_vector(NBITS_DATA_IN downto 0) := (others => '0'));
end ip_tcmi;

architecture Behavioral of ip_tcmi is
	signal vsync_in_0 : std_logic := '1';
	signal vsync_in_1 : std_logic := '1';
	signal vsync_in_2 : std_logic := '1';
	signal dclk_in_0 : std_logic := '1';
	signal dclk_in_1 : std_logic := '1';
	signal dclk_in_2 : std_logic := '1';
	signal pulse : std_logic := '0';
	signal hsync_0 : std_logic := '1';
	signal hsync_1 : std_logic := '1';
	signal hsync_2 : std_logic := '1';	
	signal pixel_cnt_int : unsigned(NBITS_LENGTH-1 downto 0) := (others => '0');
	signal last_pulse : std_logic := '0';
	signal enable_tcmi : std_logic := '0';
	signal data_in_0 : std_logic_vector(NBITS_DATA_IN downto 0) := (others => '0');
	signal data_in_1 : std_logic_vector(NBITS_DATA_IN downto 0) := (others => '0');
	-- if FIFO enabled
    signal fifo_empty : std_logic;	
	signal pixel_cnt_in : unsigned(NBITS_LENGTH-1 downto 0) := (others => '0');
	signal pulse_ram : std_logic;
	signal pulse_cnt : unsigned(positive(ceil(log2(real(ENABLE_DELAY_NB)))) downto 0);
	signal fifo_out : std_logic_vector(NBITS_DATA_IN downto 0) := (others => '0');
	signal rst : std_logic;
	signal en_last_pulse : std_logic;
	signal fifo_full : std_logic;  -- For debug
	signal data_valid : std_logic; -- For debug
	signal delay_cnt_ongoing : std_logic := '0';
	signal delay_cnt_done : std_logic := '0';
	signal last : std_logic := '0';
begin

-- ENABLE_INPUT_FIFO = false
g_no_fifo : if ENABLE_INPUT_FIFO = false generate
	-- synchronisation of vsync, dclk and hsync
	process(clk)
	begin
		if (rising_edge(clk)) then
			vsync_in_0 <= vsync_in;
			vsync_in_1 <= vsync_in_0;
			vsync_in_2 <= vsync_in_1;	
			if en = '1' then
				if vsync_in_0 = '0' and vsync_in_1 = '1' then -- detect falling edge
					enable_tcmi <= '1';
				elsif vsync_in_1 = '1' and vsync_in_2 = '0' then -- detect rising edge
					enable_tcmi <= '0';
				end if;
			else
				enable_tcmi <= '0';
			end if;	
			-- dclk/hsync
			dclk_in_0 <= dclk_in;
			dclk_in_1 <= dclk_in_0;
			dclk_in_2 <= dclk_in_1;
			hsync_0   <= hsync_in;
			hsync_1   <= hsync_0;
			hsync_2   <= hsync_1;
			data_in_0 <= xsync_sat_in & data_in;
			data_in_1 <= data_in_0;	
		end if;
	end process;
	
	active <= not vsync_in_1 and enable_tcmi;
	
	process (clk)
	begin
		if rising_edge(clk) then
			if en = '0' then 
				pixel_cnt_int <= (others => '0'); 
				last_pulse <= '0';
				pulse <= '0';
				pulse_out <= '0';
				last_out <= '0';			
			else
				if pulse = '1' then
					pulse <= '0';
					if last_pulse = '1' then
						last_out <= '1';
						last_pulse <= '0';
					else
						pulse_out <= '1';
					end if;
				-- data sampling on falling edge; sample delayed data, which is stable on dclk falling edge
				elsif ((enable_tcmi = '1' or (vsync_in_0 = '0' and vsync_in_1 = '1' and en = '1')) and (dclk_in_1 = '1' and dclk_in_0 = '0') and (hsync_in = '0' or hsync_1 = '0' or (unsigned(length) = pixel_cnt_int and last_pulse = '0'))) then
					pulse <= '1';
					if (unsigned(length) = pixel_cnt_int and last_pulse = '0' and pixel_cnt_int > 0) then
						last_pulse <= '1';
					end if;
					dout <= data_in_1;
					pulse_out <= '0';
					if unsigned(length) = pixel_cnt_int then
						pixel_cnt_int <= (others => '0'); 
					else
						pixel_cnt_int <= pixel_cnt_int + 1;
					end if;
				else
					pulse <= '0';
					pulse_out <= '0';
					last_out <= '0';
				end if;
			end if;
		end if;
	end process;
	
	-- assign outputs
	pixel_cnt <= pixel_cnt_int;
	vsync_SO <= vsync_in_1;
	hsync_SO <= hsync_1;	
	
end generate g_no_fifo;

-- ENABLE_INPUT_FIFO = true
g_fifo : if ENABLE_INPUT_FIFO = true generate
	-- synchronisation of vsync, dclk and hsync
	process(clk)
	begin
		if (rising_edge(clk)) then
			vsync_in_0 <= vsync_in;
			vsync_in_1 <= vsync_in_0;
			vsync_in_2 <= vsync_in_1;	
			if en = '1' then
				if vsync_in_0 = '0' and vsync_in_1 = '1' then -- detect falling edge
					enable_tcmi <= '1';
				elsif vsync_in_1 = '1' and fifo_empty = '1' and delay_cnt_done = '1' then -- detect FIFO empty instead of rising edge
					enable_tcmi <= '0';
				end if;
			else
				enable_tcmi <= '0';
			end if;	
			-- dclk/hsync
			dclk_in_0 <= dclk_in;
			dclk_in_1 <= dclk_in_0;
			dclk_in_2 <= dclk_in_1;
			hsync_0   <= hsync_in;
			hsync_1   <= hsync_0;
			hsync_2   <= hsync_1;
			data_in_0 <= xsync_sat_in & data_in;
			data_in_1 <= data_in_0;	
		end if;
	end process;
	
	active <= not vsync_in_1 or enable_tcmi;
	
	process (clk)
	begin
		if rising_edge(clk) then
			if en = '0' then 
				pixel_cnt_in <= (others => '0'); 
				last_pulse <= '0';
				pulse <= '0';	
			else
				if pulse = '1' then
					pulse <= '0';
				-- data sampling on falling edge; sample delayed data, which is stable on dclk falling edge
				elsif ((enable_tcmi = '1' or (vsync_in_0 = '0' and vsync_in_1 = '1' and en = '1')) and (dclk_in_1 = '1' and dclk_in_0 = '0') and (hsync_0 = '0' or hsync_1 = '0')) then
					pulse <= '1';
					if (unsigned(length) = pixel_cnt_in and last_pulse = '0' and pixel_cnt_in > 0) then
						last_pulse <= '1';
					end if;
					if unsigned(length) = pixel_cnt_in then
						pixel_cnt_in <= (others => '0'); 
					else
						pixel_cnt_in <= pixel_cnt_in + 1;
					end if;
				elsif enable_tcmi = '0' then
					-- reset counter
					pixel_cnt_in <= (others => '0'); 
				else
					pulse <= '0';
				end if;
			end if;
		end if;
	end process;
	
	-- Generate signals for FIFO
	rst <= not en;
	
	process (clk)
	begin
		if rising_edge(clk) then
			if en = '0' then
				pulse_ram <= '0';	
				pulse_cnt <= (others => '0');
			else
				if vsync_in_1 = '0' or enable_tcmi = '1' then
					pulse_ram <= '0';
					if pulse_cnt > 3 and delay_cnt_ongoing = '0' then -- Reset count only if fifo is not empty
						if fifo_empty = '0' then
							pulse_cnt <= (others => '0');
							pulse_ram <= '1';
						end if;
					else
						pulse_cnt <= pulse_cnt + 1;
					end if;
				else
					pulse_ram <= '0';	
					pulse_cnt <= (others => '0');					
				end if;
			end if;
		end if;
	end process;	
	
    -- xpm_fifo_sync: Synchronous FIFO
    -- Xilinx Parameterized Macro, version 2018.2
    
    xpm_fifo_sync_inst : xpm_fifo_sync
    generic map (
       DOUT_RESET_VALUE => "0",    -- String
       ECC_MODE => "no_ecc",       -- String
       FIFO_MEMORY_TYPE => "auto", -- String
       FIFO_READ_LATENCY => 1,     -- DECIMAL
       FIFO_WRITE_DEPTH => 4096,   -- DECIMAL
       FULL_RESET_VALUE => 0,      -- DECIMAL
       PROG_EMPTY_THRESH => 10,    -- DECIMAL
       PROG_FULL_THRESH => 10,     -- DECIMAL
       RD_DATA_COUNT_WIDTH => 13,  -- DECIMAL
       READ_DATA_WIDTH => 13,      -- DECIMAL
       READ_MODE => "std",         -- String
       USE_ADV_FEATURES => "0707", -- String
       WAKEUP_TIME => 0,           -- DECIMAL
       WRITE_DATA_WIDTH => 13,     -- DECIMAL
       WR_DATA_COUNT_WIDTH => 13   -- DECIMAL
    )
    port map (
       almost_empty => open,
       almost_full => open,
       data_valid => data_valid,
       dbiterr => open,
       dout => fifo_out,
       empty => fifo_empty,
       full => fifo_full,
       overflow => open,
       prog_empty => open,
       prog_full => open,
       rd_data_count => open,
       rd_rst_busy => open,
       sbiterr => open,
       underflow => open,
       wr_ack => open,
       wr_data_count => open,
       wr_rst_busy => open,
       din => data_in_1,
       injectdbiterr => '0',
       injectsbiterr => '0',
       rd_en => pulse_ram,
       rst => rst,
       sleep => '0',
       wr_clk => clk,
       wr_en => pulse
    );
    -- End of xpm_fifo_sync_inst instantiation	
	
	-- Output assignments
	dout <= fifo_out;
	
	process (clk)
	begin
		if rising_edge(clk) then
			if en = '0' then
				pulse_out <= '0';
				last <= '0';		
				pixel_cnt_int <= (others => '0');
				en_last_pulse <= '1';
				delay_cnt_ongoing <= '0';
				delay_cnt_done <= '1';
			else
				if unsigned(length) = pixel_cnt_int then
					if pulse_cnt = 4 then
						en_last_pulse <= '0';
						if last = '0' then
							last <= '1';
						else
							last <= '0';
						end if;
						delay_cnt_ongoing <= '1';
						delay_cnt_done <= '0';
					else
						last <= '0';
					end if;
					pulse_out <= '0';
					if pulse_ram = '1' or enable_tcmi = '0' then
						pixel_cnt_int <= (others => '0');
					end if;
				    -- Check the delay count
					if delay_cnt_ongoing = '1' and pulse_cnt > ENABLE_DELAY_NB then
						delay_cnt_done <= '1';
						delay_cnt_ongoing <= '0';
					end if;
				else
					en_last_pulse <= '1';
					pulse_out <= pulse_ram;
					if pulse_ram = '1' then
						pixel_cnt_int <= pixel_cnt_int + 1;
					end if;
					-- Reset delay count
					delay_cnt_done <= '0';
					delay_cnt_ongoing <= '0';					
				end if;
			end if;
		end if;
	end process;	

	last_out <= last;

	-- assign outputs
	pixel_cnt <= pixel_cnt_int;
	vsync_SO <= not enable_tcmi or delay_cnt_ongoing or delay_cnt_done;
	hsync_SO <= fifo_empty and hsync_1;	
	
end generate g_fifo;

end Behavioral;
-- End tcmi