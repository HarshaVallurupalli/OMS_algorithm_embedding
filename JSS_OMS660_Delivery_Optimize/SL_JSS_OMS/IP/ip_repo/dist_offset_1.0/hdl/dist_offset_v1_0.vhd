library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity dist_offset_v1_0 is
	generic (
		-- Users to add parameters here
		NBITS_DIST      : integer := 16;
		NBITS_DATA      : integer := 128;
		NBITS_INDEX     : integer := 4;
		RAM_READ_CYCLES : integer := 6;
		NBITS_DLL_STEPS : integer := 8
		-- User parameters ends
	);
	port (
		-- Users to add ports here
		clk_CI      : in  std_logic;
		en_DI       : in  std_logic;
		-- distance in/out
		pulse_in_DI : in  std_logic;
        dist_DI     : in  std_logic_vector(NBITS_DIST-1 downto 0);
		dist_sat_DI : in  std_logic;
        dist_pix_sat_DI : in  std_logic;
        dist_DO     : out std_logic_vector(NBITS_DIST-1 downto 0);
		dist_sat_DO : out std_logic;
		dist_pix_sat_DO : out std_logic;
		pulse_out_DO: out std_logic;
		-- FIFO in
		dist_fifo_DI : in std_logic_vector(NBITS_DIST+1 downto 0); -- includes normal and pixel saturation bit
        -- RAM control/data
		ram_read_pulse_DI : in std_logic;
        ram_data_DI       : in  std_logic_vector(NBITS_DATA-1 downto 0);
        ram_read_pulse_DO : out std_logic;
        ram_index_DO      : out std_logic_vector(NBITS_INDEX-1 downto 0);
		-- division / delay data
        dividend_DO       : out std_logic_vector(2*NBITS_DIST-1 downto 0);
        divisor_DO        : out std_logic_vector(NBITS_DIST-1 downto 0);
        div_pulse_DO      : out std_logic;
		div_res_DI        : in  std_logic_vector(NBITS_DIST-1 downto 0);
		div_pulse_DI      : in  std_logic;
		dist_delay_DI     : in  std_logic_vector(NBITS_DIST+NBITS_INDEX+3 downto 0);
		dist_delay_DO     : out std_logic_vector(NBITS_DIST+NBITS_INDEX+3 downto 0);		
		-- from/to reg_bank
		dist_pix_nb_DI : in std_logic_vector(16 downto 0);
		dist_line_nb_DI : in std_logic_vector(9 downto 0);
		dist_mean_filter_en_SI : in std_logic;
		dist_corr_en_SI  : in std_logic;
		dist_corr_dll_DI : in std_logic_vector(15 downto 0);
		dist_nb_dll_steps_DI : in std_logic_vector(NBITS_DLL_STEPS-1 downto 0);
		dist_index_trunc_DO : out std_logic_vector(7 downto 0);
		dist_fail_pos_DO    : out std_logic_vector(16 downto 0);
		dist_index_low_SO   : out std_logic;
		dist_index_high_SO  : out std_logic
	);
end dist_offset_v1_0;

architecture arch_imp of dist_offset_v1_0 is	
	constant C_S_AXI_DATA_WIDTH	: integer	:= 32;
	constant TWOPI: integer := 51471;
	
	signal reg_status_D : std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0); -- --Reg b24-b8> pixel_cnt b7-b2> index_trunc b1> Index too low b0> Index too high 
	signal dDLL_D : std_logic_vector(15 downto 0);
	signal oneoverdDLL_D : unsigned(17 downto 0);
	signal ram_addr_D : std_logic_vector(31 downto 0);
	signal index_D : unsigned(33 downto 0) := (others => '0');
	signal dist_index_D : unsigned(33 downto 0) := (others => '0');
	signal max_index_D : unsigned(NBITS_DLL_STEPS-1 downto 0);
	signal index_trunc_D  : unsigned(NBITS_INDEX+1 downto 0) := (others => '0'); -- index_trunc [0 to 49]
	signal index_trunc_ram_D  : unsigned(NBITS_INDEX+1 downto 0) := (others => '0'); -- index_trunc_ram [0 to 49] (after comparing dist to ram output)
	signal index_trunc_tmp_D  : unsigned(NBITS_INDEX+2 downto 0) := (others => '0'); -- index_trunc_ram [0 to 49] (after comparing dist to ram output)
	signal dist_table_index_D  : unsigned(NBITS_INDEX-1 downto 0) := (others => '0'); -- table_index [0 to 12] (Ram address offset)
	signal table_index_D  : unsigned(NBITS_INDEX-1 downto 0) := (others => '0'); -- table_index [0 to 12] (Ram address offset)
	signal table_index_m1_D : unsigned(NBITS_INDEX-1 downto 0) := (others => '0'); -- table_index -1 if odd 
	signal pixel_cnt_D : unsigned(16 downto 0) := (others => '0'); -- Number of pixel (to determine position in pixel field)
	signal pulse_ram_reg_D : std_logic_vector(RAM_READ_CYCLES-1 downto 0);
	signal ram0_D : std_logic_vector(15 downto 0);
	signal ram1_D : std_logic_vector(15 downto 0);
	signal ram2_D : std_logic_vector(15 downto 0);
	signal ram3_D : std_logic_vector(15 downto 0);
	signal ram4_D : std_logic_vector(15 downto 0);
	signal ram5_D : std_logic_vector(15 downto 0);
	signal ram6_D : std_logic_vector(15 downto 0);
	signal ram7_D : std_logic_vector(15 downto 0);
	signal ram_is_bigger : std_logic_vector(7 downto 0);
	signal ram_is_equal : unsigned(1 downto 0);
	signal Ti_D : std_logic_vector(NBITS_DIST-1 downto 0);
	signal Tip1_D : std_logic_vector(NBITS_DIST-1 downto 0);
	signal dist_cor_D : std_logic_vector(NBITS_DIST-1 downto 0);
	signal dist_cor_tmp_D : std_logic_vector(22 downto 0);
	signal dist_sat_in_D : std_logic;
	signal pulse_in_D : std_logic;
	signal dist_sat_input_D : std_logic;
	signal dist_pix_sat_in_D : std_logic;
	signal dist_pix_sat_d_D : std_logic;
	signal dist_pix_sat_d1_D : std_logic;
	signal dist_pix_sat_d2_D : std_logic;
	signal dist_sat_d_D : std_logic;
	signal dist_sat_d1_D : std_logic;
	signal dist_sat_d2_D : std_logic;
	signal dist_D : std_logic_vector(NBITS_DIST-1 downto 0);
	signal dist_d_D : std_logic_vector(NBITS_DIST-1 downto 0);
	signal dist_in_D : std_logic_vector(NBITS_DIST-1 downto 0);
	signal ram_data_D : std_logic_vector(NBITS_DATA-1 downto 0);
	signal ram_index_D : unsigned(1 downto 0); -- Selects index position in RAM
	signal ram_pos_D   : unsigned(2 downto 0); -- Selects ram0-7 output
	signal ram_add_D   : unsigned(3 downto 0); -- Signed, range +/-5
	signal div_top_D : unsigned(2*NBITS_DIST-1 downto 0); 
	signal div_bot_D : unsigned(NBITS_DIST-1 downto 0); 
	signal mult_D    : unsigned(NBITS_DIST+NBITS_INDEX+1 downto 0);
	signal mult_in_div_D: unsigned(NBITS_DIST-1 downto 0); 
	signal mult_in_D    : unsigned(NBITS_DIST+NBITS_INDEX+1 downto 0);
	signal pulse_in_cnt_D : unsigned(16 downto 0);
	signal pulse_out_cnt_D : unsigned(16 downto 0);
	signal line_cnt_D : unsigned(9 downto 0);
	signal pulse_out_D : std_logic;
	signal shift_pulse_D : std_logic;
	signal cycle_cnt_D : unsigned(1 downto 0);
	signal dist_0_D : std_logic_vector(NBITS_DIST+1 downto 0);
	signal dist_1_D : std_logic_vector(NBITS_DIST+1 downto 0);
	signal dist_2_D : std_logic_vector(NBITS_DIST+1 downto 0);
	signal dist_3_D : std_logic_vector(NBITS_DIST+1 downto 0);
	signal dist_13_D : std_logic_vector(NBITS_DIST downto 0);
	signal dist_03_D : std_logic_vector(NBITS_DIST downto 0);
begin
	-- registers
	dist_index_high_SO  <= reg_status_D(0);
	dist_index_low_SO   <= reg_status_D(1); 
	dist_index_trunc_DO <= "00" & reg_status_D(7 downto 2);
	dist_fail_pos_DO    <= reg_status_D(24 downto 8);

	-- constants
	dDLL_D <= dist_corr_dll_DI;
	oneoverdDLL_D <= to_unsigned(65535,18)/unsigned(dDLL_D);
    max_index_D <= unsigned('0' & dist_nb_dll_steps_DI(NBITS_DLL_STEPS-1 downto 1))-4;
    
	-- First calculate requests for readRAM
	dist_index_D <= unsigned(dist_in_D)*oneoverdDLL_D; -- Multiply by 1/dDLL (precomputed)
	
	process(dist_index_D, dist_nb_dll_steps_DI)
	begin
	    if dist_index_D(33 downto 16) > (unsigned(dist_nb_dll_steps_DI)-4) then -- if > dllsteps-4 -> take the last 8 
            dist_table_index_D <= max_index_D(NBITS_INDEX-1 downto 0);
		elsif dist_index_D(33 downto 16)<5 then -- if already in table 0-7 -> start with 0
            dist_table_index_D <= (others => '0');		
        elsif dist_index_D(16)='1' then         -- check if lsb is '1'; if yes we take -1, 0, 1, 2 otherwise -2, -1, 0, 1
            dist_table_index_D <= dist_index_D(17+NBITS_INDEX-1 downto 17);		
		else                                    -- Start with table_index - 2
            dist_table_index_D <= dist_index_D(17+NBITS_INDEX-1 downto 17)-1;
        end if;
    end process;
	
	process(clk_CI)
    begin
		if rising_edge(clk_CI) then
			if en_DI = '0' then
				ram_index_DO <= (others => '0');
				dist_in_D <= (others => '0');
				dist_sat_input_D <= '0';
				ram_read_pulse_DO <= '0';
				pulse_in_D        <= '0';
			else
			    pulse_in_D <= pulse_in_DI;
				dist_in_D <= dist_DI;
				dist_sat_input_D <= dist_sat_DI;
				if pulse_in_DI = '1' and dist_corr_en_SI = '1' then -- gate outputs, if not enabled
					ram_index_DO <= std_logic_vector(dist_table_index_D);
					ram_read_pulse_DO <= '1';
				else
					ram_read_pulse_DO <= '0';
				end if;
			end if;
		end if;
    end process;
	
	-- calculate index of fifo value
	process(clk_CI)
	begin
		if rising_edge(clk_CI) then
			if en_DI = '0' then
				dist_D <= (others => '0');
				dist_pix_sat_in_D <= '0';
				dist_sat_in_D <= '0';
				pulse_ram_reg_D <= (others => '0');
				ram_data_D <= (others => '0');
			else
				dist_D <= dist_fifo_DI(NBITS_DIST-1 downto 0);
				dist_sat_in_D <= dist_fifo_DI(NBITS_DIST);
				dist_pix_sat_in_D <= dist_fifo_DI(NBITS_DIST+1);
				pulse_ram_reg_D <= pulse_ram_reg_D(RAM_READ_CYCLES-2 downto 0) & ram_read_pulse_DI;
				ram_data_D <= ram_data_DI;
			end if;
		end if;
	end process;
	
	index_D <= unsigned(dist_fifo_DI(NBITS_DIST-1 downto 0))*oneoverdDLL_D; -- Multiply by 1/dDLL (precomputed)
	
	-- index_D
	process(index_D, dist_nb_dll_steps_DI)
	begin
	    if index_D(33 downto 16) > unsigned(dist_nb_dll_steps_DI) then -- only 50 tables
			index_trunc_D <= unsigned(dist_nb_dll_steps_DI(NBITS_INDEX+1 downto 0));
		else
			index_trunc_D <= index_D(17+NBITS_INDEX downto 16);
        end if;
    end process;
	
	-- table_index
	process(index_D, dist_nb_dll_steps_DI)
	begin
	    if index_D(33 downto 16) > (unsigned(dist_nb_dll_steps_DI)-4) then -- if > dllsteps-4 -> take the last 8 
            table_index_D <= max_index_D(NBITS_INDEX-1 downto 0);
		elsif index_D(33 downto 16)<5 then -- if already in table 0-7 -> start with 0
            table_index_D <= (others => '0');		
        elsif index_D(16)='1' then              -- if odd, dont modify index
            table_index_D <= index_D(17+NBITS_INDEX-1 downto 17);		
		else                                    -- if even, reduce index by 1
            table_index_D <= index_D(17+NBITS_INDEX-1 downto 17)-1;
        end if;
    end process;
	
	-- calculate Table values
	process(clk_CI)
	begin
		if rising_edge(clk_CI) then
			if en_DI = '0' then
				ram0_D <= (others => '0');
				ram1_D <= (others => '0');
				ram2_D <= (others => '0');
				ram3_D <= (others => '0');
				ram4_D <= (others => '0');
				ram5_D <= (others => '0');
				ram6_D <= (others => '0');
				ram7_D <= (others => '0');
			elsif pulse_ram_reg_D(0) = '1' then
				ram0_D <= ram_data_D(15 downto 0);
				ram1_D <= ram_data_D(31 downto 16);
				ram2_D <= ram_data_D(47 downto 32);
				ram3_D <= ram_data_D(63 downto 48);
				ram4_D <= ram_data_D(79 downto 64);
				ram5_D <= ram_data_D(95 downto 80);
				ram6_D <= ram_data_D(111 downto 96);
				ram7_D <= ram_data_D(127 downto 112);
			end if;
		end if;
	end process;
	
	process(ram0_D, ram1_D, ram2_D, ram3_D, ram4_D, ram5_D, ram6_D, ram7_D, dist_fifo_DI)
	begin
		if ram0_D > dist_fifo_DI(NBITS_DIST-1 downto 0) and ram0_D < ram1_D then -- handle wrapping
			ram_is_bigger(0) <= '1';
		else
			ram_is_bigger(0) <= '0';
		end if;
		if ram1_D > dist_fifo_DI(NBITS_DIST-1 downto 0) then
			ram_is_bigger(1) <= '1';
		else
			ram_is_bigger(1) <= '0';
		end if;
		if ram2_D > dist_fifo_DI(NBITS_DIST-1 downto 0) then
			ram_is_bigger(2) <= '1';
		else
			ram_is_bigger(2) <= '0';
		end if;
		if ram3_D > dist_fifo_DI(NBITS_DIST-1 downto 0) then
			ram_is_bigger(3) <= '1';
		else
			ram_is_bigger(3) <= '0';
		end if;
		if ram4_D > dist_fifo_DI(NBITS_DIST-1 downto 0) then
			ram_is_bigger(4) <= '1';
		else
			ram_is_bigger(4) <= '0';
		end if;
		if ram5_D > dist_fifo_DI(NBITS_DIST-1 downto 0) then
			ram_is_bigger(5) <= '1';
		else
			ram_is_bigger(5) <= '0';
		end if;
		if ram6_D > dist_fifo_DI(NBITS_DIST-1 downto 0) then
			ram_is_bigger(6) <= '1';
		else
			ram_is_bigger(6) <= '0';
		end if;
		if ram7_D > dist_fifo_DI(NBITS_DIST-1 downto 0) then
			ram_is_bigger(7) <= '1';
		else
			ram_is_bigger(7) <= '0';
		end if;		
	end process;
	
	process(ram4_D, ram5_D, ram6_D, ram7_D)
	begin
		if (ram4_D = ram5_D) then
			ram_is_equal <= to_unsigned(3,2);
		elsif (ram5_D = ram6_D) then
			ram_is_equal <= to_unsigned(2,2);
		elsif (ram6_D = ram7_D) then
			ram_is_equal <= to_unsigned(1,2);
		else
			ram_is_equal <= to_unsigned(0,2);
		end if;
	end process;
	
	-- Calculate RAM index
	process(index_trunc_D(1 downto 0))
	begin
		case index_trunc_D(1 downto 0) is
			when "00" =>
				ram_index_D <= to_unsigned(0,2);
			when "01" => 
				ram_index_D <= to_unsigned(0,2);
			when "10" =>
				ram_index_D <= to_unsigned(0,2);
			when others => 
				ram_index_D <= to_unsigned(0,2);
		end case;
	end process;
	
	-- Calculate RAM position
	process(ram_is_bigger)
	begin
		case ram_is_bigger is
			when "11111111" =>
				ram_pos_D <= to_unsigned(0,3);
			when "11111110" =>
				ram_pos_D <= to_unsigned(1,3);
			when "11111100" =>
				ram_pos_D <= to_unsigned(2,3);
			when "11111000" =>
				ram_pos_D <= to_unsigned(3,3);
			when "11110000" =>
				ram_pos_D <= to_unsigned(4,3);
			when "11100000" =>
				ram_pos_D <= to_unsigned(5,3);
			when "11000000" =>
				ram_pos_D <= to_unsigned(6,3);
			when others =>
				ram_pos_D <= to_unsigned(7,3)-ram_is_equal; -- if we are over the end of the tables and they are filled with a copy of the last one, this will be corrected			
		end case;
	end process;
	
	-- Calculate index correction factor
	process(ram_index_D, ram_pos_D)
	begin
		ram_add_D <= unsigned('0' & std_logic_vector(ram_pos_D)) + unsigned('0' & std_logic_vector(ram_index_D));
	end process;
	
	-- Calculate table_index_m1_D
	process(table_index_D)
	begin
		if table_index_D(0) = '1' then
			table_index_m1_D <= table_index_D - 1;
		else
			table_index_m1_D <= table_index_D;
		end if;
	end process;
	
	process(table_index_m1_D, ram_add_D)
	begin
	  if unsigned(std_logic_vector(unsigned("00" & table_index_m1_D & '0') + ram_add_D))> 0 then -- avoid wrap around
	    index_trunc_tmp_D <= unsigned(std_logic_vector(unsigned("00" & table_index_m1_D & '0') + ram_add_D))-to_unsigned(1,3);
	  else 
	    index_trunc_tmp_D <= (others => '0'); 
	  end if;
	end process;
	
	process(clk_CI)
	begin
		if rising_edge(clk_CI) then
			if en_DI = '0' then
				Ti_D <= (others => '0'); 
				Tip1_D   <= (others => '0'); 
				reg_status_D <= (others => '0');
				dist_d_D <= (others => '0');
				dist_sat_d_D <= '0';
				dist_sat_d1_D <= '0';
				dist_pix_sat_d_D <= '0';
				dist_pix_sat_d1_D <= '0';
				div_top_D <= (others => '0');
				div_bot_D <= (others => '0');
				mult_D    <= (others => '0');
			else
			if pulse_ram_reg_D(1) = '1' then
				dist_sat_d_D <= dist_sat_in_D;
				dist_pix_sat_d_D <= dist_pix_sat_in_D;
				dist_d_D <= dist_fifo_DI(NBITS_DIST-1 downto 0);	
				index_trunc_ram_D <= index_trunc_tmp_D(NBITS_INDEX+1 downto 0);
				-- Check if correct index is in the ram_data_DI
				if (ram_is_bigger(0) = '1') then -- Index is set too high
					Ti_D <= ram0_D; 
					Tip1_D <= ram1_D; 
					reg_status_D <= (31 downto 26 => '0') & std_logic_vector(pixel_cnt_D) & std_logic_vector(index_trunc_D) & "01"; --Reg b24-b8> pixel_cnt b7-b2> index_trunc b1> Index too low b0> Index too high
				elsif (ram_is_bigger(7) = '0') then -- Index is set too low
					Ti_D <= ram6_D; 
					Tip1_D <= ram7_D; 
					reg_status_D <= (31 downto 26 => '0') & std_logic_vector(pixel_cnt_D) & std_logic_vector(index_trunc_D) & "10"; --Reg b24-b8> pixel_cnt b7-b2> index_trunc b1> Index too low b0> Index too high 
				else 
					if ram_is_bigger(1) = '1' then
						Ti_D <= ram0_D; 
						Tip1_D <= ram1_D; 
					elsif ram_is_bigger(2) = '1' then
						Ti_D <= ram1_D; 
						Tip1_D <= ram2_D; 
					elsif ram_is_bigger(3) = '1' then
						Ti_D <= ram2_D;
						Tip1_D <= ram3_D;
					elsif ram_is_bigger(4) = '1' then
						Ti_D <= ram3_D; 
						Tip1_D <= ram4_D; 
					elsif ram_is_bigger(5) = '1' then
						Ti_D <= ram4_D; 
						Tip1_D <= ram5_D; 
					elsif ram_is_bigger(6) = '1' then
						Ti_D <= ram5_D; 
						Tip1_D <= ram6_D; 
					elsif ram_is_bigger(7) = '1' then
						Ti_D <= ram6_D; 
						Tip1_D <= ram7_D; 
					end if;
				end if;
			end if;
			if pulse_ram_reg_D(2) = '1' then
				dist_sat_d1_D <= dist_sat_d_D;
				dist_pix_sat_d1_D <= dist_pix_sat_d_D;
				-- Handle negative ram0 or dist < ram0
				if unsigned(Tip1_D) < unsigned(Ti_D) then
					div_bot_D <= (unsigned(Tip1_D)-unsigned(Ti_D)+TWOPI);
				else
					div_bot_D <= (unsigned(Tip1_D)-unsigned(Ti_D));
				end if;
				if unsigned(dist_d_D) < unsigned(Ti_D) then
					div_top_D <= unsigned(dDLL_D)*(unsigned(dist_d_D)-unsigned(Ti_D)+TWOPI);
				else
					div_top_D <= unsigned(dDLL_D)*(unsigned(dist_d_D)-unsigned(Ti_D));
				end if;
				mult_D    <= unsigned(dDLL_D)*index_trunc_ram_D;
			end if;
		  end if;
		end if;
	end process;
	
	process(dist_corr_en_SI, pulse_ram_reg_D, div_top_D, div_bot_D) -- gate outputs if not enabled
	begin
		if dist_corr_en_SI = '1' then
			div_pulse_DO <= pulse_ram_reg_D(3);
			dividend_DO <= std_logic_vector(div_top_D);
			divisor_DO <= std_logic_vector(div_bot_D);
		else
			div_pulse_DO <= '0';
			dividend_DO <= (others => '0');
			divisor_DO <= (others => '0');
		end if;
	end process;
	
	dist_delay_DO <= dist_pix_sat_d1_D & dist_sat_d1_D &  std_logic_vector(mult_D);
	dist_sat_d2_D <= dist_delay_DI(NBITS_DIST+NBITS_INDEX+2);
	dist_pix_sat_d2_D <= dist_delay_DI(NBITS_DIST+NBITS_INDEX+3);
	mult_in_D     <= unsigned(dist_delay_DI(NBITS_DIST+NBITS_INDEX+1 downto 0));
	
	-- Calculate output distance
	process(div_res_DI, mult_in_D, mult_in_div_D)
	begin
		dist_cor_tmp_D <= std_logic_vector(unsigned(div_res_DI) + mult_in_D);
	end process;
	
	process(dist_cor_tmp_D)
	begin
		if (unsigned('0' & dist_cor_tmp_D(15 downto 0)) > TWOPI) then
			dist_cor_D <= std_logic_vector(unsigned(dist_cor_tmp_D(15 downto 0))-TWOPI);
		else
			dist_cor_D <= dist_cor_tmp_D(15 downto 0);
		end if;
	end process;
	
	-- generate shift_pulses
	process(clk_CI)
	begin
        if rising_edge(clk_CI) then
            if en_DI = '0' then
                cycle_cnt_D <= (others => '0');
            elsif (pulse_in_cnt_D = unsigned(dist_pix_nb_DI)) and (pulse_out_cnt_D < pulse_in_cnt_D) then
                cycle_cnt_D <= cycle_cnt_D + 1;
            end if;
        end if;
	end process;
	
	process(cycle_cnt_D, pulse_out_cnt_D, pulse_in_cnt_D, pulse_in_D, dist_corr_en_SI)
	begin
	   if dist_corr_en_SI = '0' then -- if bloc is disabled
	       if pulse_in_D = '1' or (cycle_cnt_D = 3 and pulse_in_cnt_D > pulse_out_cnt_D) then
	           shift_pulse_D <= '1';
	       else
	           shift_pulse_D <= '0';
	       end if;
	   else
	        if (cycle_cnt_D = 3 and pulse_in_cnt_D > pulse_out_cnt_D) then
                shift_pulse_D <= '1';
            else
                shift_pulse_D <= '0';
            end if;
	   end if;
	end process;	
	
	-- Distance sum
	dist_13_D <= (dist_1_D(NBITS_DIST-1) or dist_3_D(NBITS_DIST-1)) & std_logic_vector(unsigned('0' & dist_1_D(NBITS_DIST-2 downto 0)) + unsigned('0' & dist_3_D(NBITS_DIST-2 downto 0)));
	dist_03_D <= (dist_0_D(NBITS_DIST-1) or dist_3_D(NBITS_DIST-1)) & std_logic_vector(unsigned('0' & dist_0_D(NBITS_DIST-2 downto 0)) + unsigned('0' & dist_3_D(NBITS_DIST-2 downto 0)));
	
	-- shift register & output mean filter
	process(clk_CI)
	begin
		if rising_edge(clk_CI) then
			if en_DI = '0' then
                dist_0_D <= (others => '0');
                dist_1_D <= (others => '0');
                dist_2_D <= (others => '0');
                dist_3_D <= (others => '0');
                pulse_out_D <= '0';
                pulse_in_cnt_D <= (others => '0');
				dist_DO     <= (others => '0');
				dist_sat_DO <= '0';
				pulse_out_DO <= '0';
				pulse_out_cnt_D <= (others => '0');
				line_cnt_D <= unsigned(dist_line_nb_DI) - 1;
            elsif dist_corr_en_SI = '0' and shift_pulse_D = '1' then -- if bloc is disabled
                dist_0_D <= dist_pix_sat_DI & dist_sat_input_D & dist_in_D;
                dist_1_D <= dist_0_D;
                dist_2_D <= dist_1_D;
                dist_3_D <= dist_2_D;
                pulse_in_cnt_D <= pulse_in_cnt_D + 1;
                if pulse_in_cnt_D > 1 then
                    pulse_out_D <= '1';
				else
					pulse_out_D <= '0';
                end if;
				pulse_out_DO <= '0';
            elsif dist_corr_en_SI = '1' and (div_pulse_DI = '1') then 
                dist_0_D <= dist_pix_sat_d2_D & dist_sat_d2_D & dist_cor_D;
                dist_1_D <= dist_0_D;
                dist_2_D <= dist_1_D;
                dist_3_D <= dist_2_D;
                pulse_in_cnt_D <= pulse_in_cnt_D + 1;
                if pulse_in_cnt_D > 1 then -- skip first cycle
                    pulse_out_D <= '1';
				else
					pulse_out_D <= '0';
                end if;
				pulse_out_DO <= '0';
			elsif pulse_out_D = '1' then
				pulse_out_D <= '0';
			    if line_cnt_D > 0 then
			         line_cnt_D <= line_cnt_D - 1;
			    else
			         line_cnt_D <= unsigned(dist_line_nb_DI) - 1;
			    end if;
			    if dist_2_D(NBITS_DIST+1) = '0' or dist_mean_filter_en_SI = '0' then -- No pixel error detected
				    dist_DO     <= dist_2_D(NBITS_DIST-1 downto 0);
				    if dist_2_D(NBITS_DIST+1) = '0' then
				        dist_pix_sat_DO <= '0';
				    else
				        dist_pix_sat_DO <= '1';
				    end if;
				else -- Pixel error detected - horizontal mean value (max 4 pixels)
				    if line_cnt_D = unsigned(dist_line_nb_DI) - 1 then -- if first element 
				        if dist_1_D(NBITS_DIST+1) = '0' then
				            dist_DO <= dist_1_D(NBITS_DIST-1 downto 0);
				            dist_2_D(NBITS_DIST-1 downto 0) <= dist_1_D(NBITS_DIST-1 downto 0); -- update value -> for mean algorithm
				        else -- more than 2 bad pixels are not allowed
				            dist_DO <= dist_0_D(NBITS_DIST-1 downto 0);
				            dist_2_D(NBITS_DIST-1 downto 0) <= dist_0_D(NBITS_DIST-1 downto 0); -- update value -> for mean algorithm
				        end if;
				    elsif line_cnt_D = 1 then -- second last element
				   	    if dist_1_D(NBITS_DIST+1) = '0' then
                            dist_DO <= dist_13_D(NBITS_DIST downto 1);
                            dist_2_D(NBITS_DIST-1 downto 0) <= dist_13_D(NBITS_DIST downto 1); -- update value -> for mean algorithm
                        else -- dont take the pixel from the next line
                            dist_DO <= dist_3_D(NBITS_DIST-1 downto 0);
                            dist_2_D(NBITS_DIST-1 downto 0) <= dist_3_D(NBITS_DIST-1 downto 0); -- update value -> for mean algorithm
                        end if;				        
				    elsif line_cnt_D = 0 then -- last element
	                    -- dont take the pixel from the next line
                        dist_DO <= dist_3_D(NBITS_DIST-1 downto 0);		        
				    else -- for normal pixels (not border ones)
				   	    if dist_1_D(NBITS_DIST+1) = '0' then
                            dist_DO <= dist_13_D(NBITS_DIST downto 1);
                            dist_2_D(NBITS_DIST-1 downto 0) <= dist_13_D(NBITS_DIST downto 1); -- update value -> for mean algorithm
                        else -- more than 2 bad pixels are not allowed
                            dist_DO <= dist_03_D(NBITS_DIST downto 1);
                            dist_2_D(NBITS_DIST-1 downto 0) <= dist_03_D(NBITS_DIST downto 1); -- update value -> for mean algorithm
                        end if;
				    end if;
				    dist_pix_sat_DO <= '1';
				end if;
				pulse_out_cnt_D <= pulse_out_cnt_D + 1;
				dist_sat_DO <= dist_2_D(NBITS_DIST);
                pulse_out_DO <= '1';
		    else
				pulse_out_D <= '0';
		        pulse_out_DO <= '0';
			end if;
		end if;
	end process;

end arch_imp;
