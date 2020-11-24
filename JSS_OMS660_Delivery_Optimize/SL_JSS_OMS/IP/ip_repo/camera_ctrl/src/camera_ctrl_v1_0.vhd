library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity camera_ctrl_v1_0 is
	generic (
		-- Users to add parameters here
		DONE_DELAY : integer := 20;
        CLK_DIVISION_FACTOR : integer := 10;
        ALU_PREP_CYCLES : integer := 64;
        RAM_WAIT_CYCLES : integer := 1024;
        RAM_WAIT_DONE : integer := 0
		-- User parameters ends
	);
	port (
		-- Users to add ports here
		clk : in std_logic;
		resetn : in std_logic;
		
		-- from/to reg_bank
		cc_en_DI : in std_logic;
		cc_rst_RI : in std_logic;
		cc_update_reg_values_SI : in std_logic;
		cc_mode_SI : in std_logic_vector(2 downto 0);
		cc_data_length_DI : in std_logic_vector(16 downto 0);
		reset_cc_regs_RO : out std_logic;
		image_bin_en_SI : in std_logic;
		
		-- Control inputs
		tcmi_active : in std_logic;
		image_bin_done_SI : in std_logic;
		pixel_cnt : in unsigned(16 downto 0);
		
		-- Control outputs
        tcmi_en : out std_logic;
        tcmi_dcs_sel : out std_logic_vector(2 downto 0);
        tcmi_last_dcs : out std_logic_vector(2 downto 0);
        img_dual_en : out std_logic;
  
        grey_length : out std_logic_vector(18 downto 0);
        dcs_length : out std_logic_vector(16 downto 0);
        sort_length : out std_logic_vector(16 downto 0);
        
        alu_en : out std_logic
		-- User ports ends
	);
end camera_ctrl_v1_0;

architecture arch_imp of camera_ctrl_v1_0 is
	
	-- Signals
	signal reg0_mode     : std_logic_vector(31 downto 0); -- 31:15> Data_length ; 13:5 Line length ; 4:2> Mode ToF=0 / Greyscale = 1 / 4 dcs = 2 / dualMGX = 3 ; 1>Update Register values ; 0> Reset
    signal data_length_reg : std_logic_vector(16 downto 0) := (others => '0');
    signal mode_reg : std_logic_vector(2 downto 0) := (others => '0');
    signal update_reg : std_logic := '0';
    signal reset_reg : std_logic := '0';
    signal enable_reg : std_logic := '0';
    signal int_resetn : std_logic := '1';
    signal update : std_logic := '0';
    signal fsm_done : std_logic := '0';
    signal fsm_done_dcs : std_logic := '0';
    signal reset_regs : std_logic := '0';
    signal dcs_length_reg : std_logic_vector(16 downto 0) := (others => '0');
    signal sort_length_reg : std_logic_vector(16 downto 0) := (others => '0');
    signal alu_done_sig : std_logic := '0';
    signal sample_cnt : unsigned(16 downto 0) := (others =>'0');
    signal next_sample : std_logic := '0';

    -- Main FSM
    type main_fsm is (DISABLED, INIT, IDLE, BUSY);
    signal main_state : main_fsm := DISABLED;
    signal main_next_state : main_fsm := DISABLED;
    
    -- TCMI FSM
    signal tcmi_active_reg : std_logic := '0';
    signal tcmi_active_reg_d : std_logic := '0';
    signal dcs_state : unsigned(1 downto 0) := (others => '0');
    signal next_dcs_state : unsigned(1 downto 0) := (others => '0');
    
    signal alu_en_int : std_logic;
    signal tcmi_dcs_sel_int : std_logic_vector(2 downto 0);
    signal tcmi_last_dcs_int : std_logic_vector(2 downto 0);
	signal done_rdy : std_logic;
	signal done_del : std_logic_vector(DONE_DELAY-1 downto 0);
begin

	-- connect registers
	reg0_mode(0) <= cc_en_DI;
	reg0_mode(1) <= cc_rst_RI;
	reg0_mode(2) <= cc_update_reg_values_SI;
	reg0_mode(5 downto 3) <= cc_mode_SI;
	reg0_mode(31 downto 15) <= cc_data_length_DI;
	
	-- Add user logic here
    int_resetn <= resetn and not reset_reg and enable_reg;
    
    -- main FSM
    process(clk)
    begin
        if rising_edge(clk) then
            if int_resetn='0' then
                main_state <= DISABLED;
            else
                main_state <= main_next_state;
            end if;
        end if;
    end process;
    
    -- main FSM process
    process(clk)
    begin
        if rising_edge(clk) then
            if int_resetn ='0' then
                main_next_state <= INIT;
            else
                case main_state is
                    when DISABLED =>
                        if int_resetn ='1' then
                            main_next_state <= INIT;
                        end if;
                    when INIT =>
                        if int_resetn = '0' then
                            main_next_state <= DISABLED;
                        elsif (update = '1') and (reset_reg ='0') and (update_reg='0') then
                            main_next_state <= IDLE;
                        end if;
                    when IDLE =>
                    if int_resetn = '0' then
                            main_next_state <= DISABLED;
                        elsif tcmi_active = '1' then
                            main_next_state <= BUSY;
				        elsif update_reg = '1' then
					       main_next_state <= INIT;
                        --else
                            --main_next_state <= IDLE;
                        end if;
                    when BUSY =>
                        if int_resetn = '0' then
                            main_next_state <= DISABLED;
                        elsif fsm_done = '1' then
                            main_next_state <= IDLE;
                        --else
                            --main_next_state <= BUSY;
                        end if;
                end case;
                end if;            
        end if;
    end process;
    
    -- register update
    update_reg <= reg0_mode(2);
    reset_reg  <= reg0_mode(1);
    enable_reg <= reg0_mode(0);
    
    process(clk)
    begin
        if rising_edge(clk) then
            if int_resetn = '0' then
                data_length_reg <= (others => '0');
                mode_reg <= (others => '0');
                grey_length <= (others => '0');
                dcs_length_reg <= (others => '0');
                sort_length_reg <= (others => '0');
            elsif update = '1' then
                grey_length <= (others => '0'); -- default assignement
                data_length_reg <= reg0_mode(31 downto 15);
                mode_reg <= reg0_mode(5 downto 3);
                if (mode_reg = "010") then
				    grey_length <= reg0_mode(31 downto 15) & "00";
				else
					grey_length <= "00" & reg0_mode(31 downto 15);
                end if;                
                dcs_length_reg <= reg0_mode(31 downto 15);
                if mode_reg = "011" then -- dual mgx mode
                    sort_length_reg <= '0' & reg0_mode(31 downto 16); -- length divided by 2
                else
                    sort_length_reg <= reg0_mode(31 downto 15);
                end if;
            end if;
        end if;
    end process;
    dcs_length <= dcs_length_reg;
    sort_length <= sort_length_reg;
    
    --main FSM outputs
    process(clk)
    begin
    if rising_edge(clk) then
        if (int_resetn = '0') then
            update <= '0';
            tcmi_en <= '0';
            alu_en_int <= '0';
            reset_regs <= '0';
        else
            update <= '0';
            tcmi_en <= '1';
            alu_en_int <= '0';
            reset_regs <= '0';
            case main_state is
                when BUSY => 
                    if mode_reg = "000" or mode_reg = "011" then
                        alu_en_int <= '1';
                    end if;
                when INIT =>
                    reset_regs <= '1';
					update <= '1';
                when others =>
            end case;
            case main_next_state is
                when INIT =>
                    update <= '1';
                    reset_regs <= '1';
                when others =>
            end case; 
        end if;
    end if;
    end process;
    alu_en <= alu_en_int;
	reset_cc_regs_RO <= reset_regs;
	
	-- done ready
	process(image_bin_done_SI, image_bin_en_SI, tcmi_active_reg, tcmi_active_reg_d)
	begin
		if image_bin_en_SI = '1' then
			done_rdy <= image_bin_done_SI;
		elsif tcmi_active_reg='0' and tcmi_active_reg_d='1' then
			done_rdy <= '1';
		else
			done_rdy <= '0';		
		end if;
	end process;
	
	-- done_delay
	process(clk)
	begin
		if rising_edge(clk) then
			if int_resetn = '0' then
				done_del <= (others => '0');
			else
				done_del <= done_del(DONE_DELAY-2 downto 0) & done_rdy;
			end if;
		end if;
	end process;
    
    -- tcmi active delayed
    process(clk)
    begin
    if rising_edge(clk) then
        if (int_resetn ='0') then
            tcmi_active_reg <= '0';
            tcmi_active_reg_d <= '0';
            tcmi_dcs_sel_int <= (others => '0');
            tcmi_last_dcs_int <= (others => '1');
            fsm_done_dcs <= '0'; 
        else
            tcmi_active_reg <= tcmi_active;
            tcmi_active_reg_d <= tcmi_active_reg;
            if mode_reg = "000" then
                tcmi_last_dcs_int <= "011";  -- Last pulse used for DCS 3
                tcmi_dcs_sel_int <= '0' & std_logic_vector(dcs_state);   
            elsif mode_reg = "010" then
                tcmi_last_dcs_int <= "100";  -- Generate last pulse for debug / Last pulse not used in GS (4 DCS mode)
                tcmi_dcs_sel_int <= "100"; -- use GS mode to store 4 DCS
                if dcs_state > 2 and done_del(DONE_DELAY-1) = '1' then
                    fsm_done_dcs <= '1'; 
                else
                    fsm_done_dcs <= '0'; 
                end if;             
            elsif mode_reg = "001" then
                tcmi_last_dcs_int <= (others => '1'); -- Last pulse not used in GS
                tcmi_dcs_sel_int <= "100"; 
            elsif mode_reg = "011" then
                tcmi_last_dcs_int <= "010";  -- Last pulse used for DCS 2
                tcmi_dcs_sel_int <= '0' & std_logic_vector(dcs_state);   
            end if;
        end if;
    end if;
    end process;   
    
    -- Assign outputs
    tcmi_last_dcs <= tcmi_last_dcs_int;
    tcmi_dcs_sel <= tcmi_dcs_sel_int;
    
    -- calculate next_dcs_state -> dcs0, dcs2, dcs1, dcs3
    process(dcs_state, mode_reg)
    begin
        if mode_reg = "011" then
            case dcs_state is
            when "00" => 
                next_dcs_state <= "10";
            when others =>              
                next_dcs_state <= "00";     
        end case;  
        else
            case dcs_state is
                when "00" => 
                    next_dcs_state <= "10";
                when "01" => 
                    next_dcs_state <= "11";
                when "10" =>
                    next_dcs_state <= "01";
                when others =>              
                    next_dcs_state <= "00";     
            end case;   
        end if;    
    end process;
     
    -- tcmi fsm
    process(clk)
    begin    
    if rising_edge(clk) then
        if (int_resetn ='0') then
            dcs_state <= (others => '0');
        elsif main_state = BUSY then
			if done_del(DONE_DELAY-1) = '1' then
				dcs_state <= next_dcs_state;
			end if;
        else
            dcs_state <= (others => '0');
        end if;
    end if;
    end process;
    
    --fsm done signals
    process(clk)
    begin
    if rising_edge(clk) then
        if (int_resetn = '0') then
            fsm_done <= '0';
        else
            if mode_reg = "010" then
                fsm_done <= fsm_done_dcs;
            end if;
        end if;
    end if;
    end process;
    
    -- dual enable signal for image bin block
    process(mode_reg)
    begin
        if (mode_reg = "011") then
            img_dual_en <= '1';
        else
            img_dual_en <= '0';
        end if;
    end process;
	-- User logic ends

end arch_imp;
