library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ip_bad_pix_mem_ctrl is
	generic (
	    BAD_PIXEL_CODE : integer;
        NBITS : integer
	);
	port (
	   -- control signals
	   clk_CI : in std_logic;
	   reset_RBI : in std_logic;
	   init_table_SI : in std_logic;
	   init_run_SI : in std_logic;
	   pix_nb_DI : in std_logic_vector(NBITS-1 downto 0);
	   reg_pix_nb_DI : in std_logic_vector(NBITS-1 downto 0);
	   pulse_in_DI : in std_logic;
	   -- ram access
	   ram_pulse_in_DI : in std_logic;
	   ram_data_in_DI : in unsigned(15 downto 0);
	   bad_pix_ram_rd_pulse_DO : out std_logic;
	   -- memory access
	   bad_pix_addr_DO : out std_logic_vector(NBITS-1 downto 0);
	   bad_pix_data_DO : out std_logic;
	   bad_pix_wr_en_DO : out std_logic;
	   bad_pix_data_DI : in std_logic;
	   -- output
	   readRam_reset_RBO : out std_logic;
	   init_not_ongoing_DO : out std_logic;
       bad_pix_sat_DO : out std_logic
	);
end ip_bad_pix_mem_ctrl;

architecture arch_imp of ip_bad_pix_mem_ctrl is

    -- Main FSM
    type main_fsm is (IDLE, INIT, RUN);
    signal main_state : main_fsm := IDLE;
    signal main_next_state : main_fsm := IDLE;

    -- Control signals
    signal clk_cnt_en : std_logic;
    signal init_wr_pulse_en : std_logic;
    signal init_reset_RB : std_logic;
    signal init_done : std_logic;
    signal run_reset_RB : std_logic;
    signal run_done : std_logic;
	signal bad_pix_wr_en_D : std_logic;
	signal rd_start_D : std_logic;
    
    -- Counters
    signal init_wr_pulse_cnt : unsigned(NBITS-1 downto 0);
    signal rd_pulse_cnt : unsigned(NBITS-1 downto 0);
    signal clk_cnt : unsigned(1 downto 0);

begin
    -- main FSM
    process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if reset_RBI='0' then
                main_state <= IDLE;
            else
                main_state <= main_next_state;
            end if;
        end if;
    end process;
    
    -- main FSM process
    process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if reset_RBI ='0' then
                main_next_state <= IDLE;
            else
                case main_state is
                    when INIT =>
                        if init_done = '1' then
                            main_next_state <= IDLE;
                        end if;
                    when RUN =>
                        if run_done = '1' then
                            main_next_state <= IDLE;
                        end if;
                    when others =>
                        if init_table_SI = '1' then
                            main_next_state <= INIT;
                        elsif init_run_SI = '1' then
                            main_next_state <= RUN;
                        end if;
                    end case;
                end if;            
        end if;
    end process;
    
    -- FSM control signals
    process(main_state, reg_pix_nb_DI, rd_pulse_cnt, init_wr_pulse_cnt)
    begin
        clk_cnt_en <= '0';
        init_done <= '0';
        init_wr_pulse_en <= '0';
        init_reset_RB <= '0';
        run_done <= '0';
        run_reset_RB <= '0';
		init_not_ongoing_DO <= '1';
        case main_state is
        when INIT =>
			init_not_ongoing_DO <= '0';
            init_reset_RB <= '1';
            clk_cnt_en <= '1';
            if init_wr_pulse_cnt < unsigned(reg_pix_nb_DI)+1 then
                init_wr_pulse_en <= '1';
            elsif rd_pulse_cnt = unsigned(reg_pix_nb_DI) then
                init_done <= '1';
            end if;
        when RUN =>
			run_reset_RB <= '1';
            if rd_pulse_cnt = unsigned(reg_pix_nb_DI) then
                run_done <= '1';
            end if;         
        when others =>
        end case;
    end process;
	
	readRam_reset_RBO <= not init_done;
    
    -- read pulse cnt
    process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if reset_RBI ='0' or (init_reset_RB = '0' and run_reset_RB = '0') then
                rd_pulse_cnt <= (others => '0');
				rd_start_D   <= '0';
            elsif ram_pulse_in_DI = '1' or pulse_in_DI = '1' then
				rd_start_D <= '1';
				if main_state = RUN or rd_start_D = '1' then
					rd_pulse_cnt <= rd_pulse_cnt + 1;
				end if;
            end if;    
        end if;
    end process;     
      
    -- INIT
    -- clk_cnt
    process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if reset_RBI ='0' or clk_cnt_en = '0' then
                clk_cnt <= (others => '1');
            else
                clk_cnt <= clk_cnt - 1;
            end if;    
        end if;
    end process;
    
    -- init wr count & init wr pulse
    process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if reset_RBI ='0' or init_reset_RB = '0' then
                init_wr_pulse_cnt <= (others => '0');
                bad_pix_ram_rd_pulse_DO <= '0';
            elsif init_wr_pulse_en = '1' and clk_cnt = 0 then
                init_wr_pulse_cnt <= init_wr_pulse_cnt + 1;
                bad_pix_ram_rd_pulse_DO <= '1';
            else
                bad_pix_ram_rd_pulse_DO <= '0';
            end if;    
        end if;
    end process;      
    
    -- INIT / RUN output
    process(clk_CI)
    begin
        if rising_edge(clk_CI) then
            if reset_RBI ='0' or (init_reset_RB = '0' and run_reset_RB = '0') then
                --bad_pix_wr_en_D <= '0';
                --bad_pix_addr_DO <= (others => '0');
                bad_pix_data_DO <= '0';
				bad_pix_sat_DO <= '0';
            elsif (ram_pulse_in_DI = '1' or pulse_in_DI = '1') then
				if main_state = INIT then
					--bad_pix_wr_en_D <= '1';
					if ram_data_in_DI = BAD_PIXEL_CODE then
						bad_pix_data_DO <= '1';
					else
						bad_pix_data_DO <= '0';
					end if;
				else
					--bad_pix_wr_en_D <= '0';
					bad_pix_sat_DO <= bad_pix_data_DI;
				end if;
                --bad_pix_addr_DO <= std_logic_vector(rd_pulse_cnt);
            end if;    
        end if;
    end process;  

	-- wr_en
	process(main_state)
	begin
		if main_state = INIT then
			bad_pix_wr_en_DO <= '1';
		else
			bad_pix_wr_en_DO <= '0';
		end if;
	end process;
	
	bad_pix_addr_DO <= std_logic_vector(rd_pulse_cnt);	

end arch_imp;
