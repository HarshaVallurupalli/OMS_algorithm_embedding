library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity data2axistream_v1_0_M00_AXIS is
	generic (
		-- Users to add parameters here
		INPUT_FIFO_BITS : integer :=  1; -- Input FIFO bits to handle dma not ready (1 or 2 bit possible)
		-- User parameters ends
		-- Do not modify the parameters beyond this line

		-- Width of S_AXIS address bus. The slave accepts the read and write addresses of width C_M_AXIS_TDATA_WIDTH.
		C_M_AXIS_TDATA_WIDTH	: integer	:= 32;
		-- Start count is the numeber of clock cycles the master will wait before initiating/issuing any transaction.
		C_M_START_COUNT	: integer	:= 32
	);
	port (
		-- Users to add ports here
		en : in std_logic;
		clk : in std_logic;
		pulse : in std_logic;
        input_data : in std_logic_vector(31 downto 0);
        NUMBER_OF_OUTPUT_WORDS : in unsigned(18 downto 0);
        --debug_1 : out std_logic_vector(4 downto 0);
		-- User ports ends
		-- Do not modify the ports beyond this line

		-- Global ports
		M_AXIS_ACLK	: in std_logic;
		-- 
		M_AXIS_ARESETN	: in std_logic;
		-- Master Stream Ports. TVALID indicates that the master is driving a valid transfer, A transfer takes place when both TVALID and TREADY are asserted. 
		M_AXIS_TVALID	: out std_logic;
		-- TDATA is the primary payload that is used to provide the data that is passing across the interface from the master.
		M_AXIS_TDATA	: out std_logic_vector(C_M_AXIS_TDATA_WIDTH-1 downto 0);
		-- TSTRB is the byte qualifier that indicates whether the content of the associated byte of TDATA is processed as a data byte or a position byte.
		M_AXIS_TSTRB	: out std_logic_vector((C_M_AXIS_TDATA_WIDTH/8)-1 downto 0);
		-- TKEEP is the byte qualifier ..?
        M_AXIS_TKEEP    : out std_logic_vector((C_M_AXIS_TDATA_WIDTH/8)-1 downto 0);
		-- TLAST indicates the boundary of a packet.
		M_AXIS_TLAST	: out std_logic;
		-- TREADY indicates that the slave can accept a transfer in the current cycle.
		M_AXIS_TREADY	: in std_logic
	);
end data2axistream_v1_0_M00_AXIS;

architecture implementation of data2axistream_v1_0_M00_AXIS is
                                                                      
	 -- function called clogb2 that returns an integer which has the   
	 -- value of the ceiling of the log base 2.                              
	function clogb2 (bit_depth : integer) return integer is                  
	 	variable depth  : integer := bit_depth;                               
	 	variable count  : integer := 1;                                       
	 begin                                                                   
	 	 for clogb2 in 1 to bit_depth loop  -- Works for up to 32 bit integers
	      if (bit_depth <= 2) then                                           
	        count := 1;                                                      
	      else                                                               
	        if(depth <= 1) then                                              
	 	       count := count;                                                
	 	     else                                                             
	 	       depth := depth / 2;                                            
	          count := count + 1;                                            
	 	     end if;                                                          
	 	   end if;                                                            
	   end loop;                                                             
	   return(count);        	                                              
	 end;                                                                    

	 -- WAIT_COUNT_BITS is the width of the wait counter.                       
	 constant  WAIT_COUNT_BITS  : integer := clogb2(C_M_START_COUNT-1);                                                                                                                                    
	                                                                                  
	-- Define the states of state machine                                             
	-- The control state machine oversees the writing of input streaming data to the FIFO,
	-- and outputs the streaming data from the FIFO                                   
	type state is ( IDLE,        -- This is the initial/idle state                    
	                INIT_COUNTER,  -- This state initializes the counter, ones        
	                                -- the counter reaches C_M_START_COUNT count,     
	                                -- the state machine changes state to INIT_WRITE  
	                SEND_STREAM);  -- In this state the                               
	                             -- stream data is output through M_AXIS_TDATA        
	-- State variable                                                                 
	signal  mst_exec_state : state := IDLE;                                                   
	-- Example design FIFO read pointer                                               
	--signal read_pointer : integer range 0 to bit_num-1 := 0;
	signal read_pointer : integer range 0 to 8388607 := 0; 
	signal write_pointer : integer range 0 to 8388607 := 0;   	

	-- AXI Stream internal signals
	--wait counter. The master waits for the user defined number of clock cycles before initiating a transfer.
	signal count	: std_logic_vector(WAIT_COUNT_BITS-1 downto 0) := (others => '0');
	--streaming data valid
	signal axis_tvalid	: std_logic;
	--streaming data valid delayed by one clock cycle
	signal axis_tvalid_delay	: std_logic;
	--Last of the streaming data 
	signal axis_tlast	: std_logic;
	--Last of the streaming data delayed by one clock cycle
	signal axis_tlast_delay	: std_logic;
	--FIFO implementation signals
	signal stream_data_out	: std_logic_vector(C_M_AXIS_TDATA_WIDTH-1 downto 0);
	signal tx_done	: std_logic;
	-- FIFO control
	signal fifo_push : std_logic := '0';
	signal fifo_load : std_logic := '0';
	signal fifo_full : std_logic := '0';
	signal fifo_empty : std_logic := '1';
	signal fifo_cnt : unsigned(1 downto 0) := "00";
	signal fifo_data0 : std_logic_vector(C_M_AXIS_TDATA_WIDTH-1 downto 0);
	signal fifo_data1 : std_logic_vector(C_M_AXIS_TDATA_WIDTH-1 downto 0);
	signal fifo_data2 : std_logic_vector(C_M_AXIS_TDATA_WIDTH-1 downto 0);
	signal fifo_data3 : std_logic_vector(C_M_AXIS_TDATA_WIDTH-1 downto 0);
	signal pulse_int  : std_logic := '0';

begin
	-- I/O Connections assignments

	M_AXIS_TVALID	<= axis_tvalid_delay;
	M_AXIS_TDATA	<= stream_data_out;
	M_AXIS_TLAST	<= axis_tlast_delay;
	M_AXIS_TSTRB	<= (others => '1');
	M_AXIS_TKEEP	<= (others => '1');


	-- Control state machine implementation                                               
	process(M_AXIS_ACLK)                                                                        
	begin                                                                                       
	  if (rising_edge (M_AXIS_ACLK)) then                                                       
	    if(M_AXIS_ARESETN = '0') then                                                           
	      -- Synchronous reset (active low)                                                     
	      mst_exec_state      <= IDLE;                                                          
	      count <= (others => '0');                                                             
	    else                                                                                    
	      case (mst_exec_state) is                                                              
	        when IDLE     =>                                                                    
	          -- The slave starts accepting tdata when                                          
	          -- there tvalid is asserted to mark the                                           
	          -- presence of valid streaming data                                               
	          --if (count = "0")then                                                            
	            mst_exec_state <= INIT_COUNTER;                                                 
	          --else                                                                              
	          --  mst_exec_state <= IDLE;                                                         
	          --end if;                                                                           
	                                                                                            
	          when INIT_COUNTER =>                                                              
	            -- This state is responsible to wait for user defined C_M_START_COUNT           
	            -- number of clock cycles.                                                      
	            if ( count = std_logic_vector(to_unsigned((C_M_START_COUNT - 1), WAIT_COUNT_BITS))) then
	              mst_exec_state  <= SEND_STREAM;                                               
	            else                                                                            
	              count <= std_logic_vector (unsigned(count) + 1);                              
	              mst_exec_state  <= INIT_COUNTER;                                              
	            end if;                                                                         
	                                                                                            
	        when SEND_STREAM  =>                                                                
	          -- The example design streaming master functionality starts                       
	          -- when the master drives output tdata from the FIFO and the slave                
	          -- has finished storing the S_AXIS_TDATA                                          
	          if (tx_done = '1') then                                                           
	            mst_exec_state <= IDLE;                                                         
	          else                                                                              
	            mst_exec_state <= SEND_STREAM;                                                  
	          end if;                                                                           
	                                                                                            
	        when others    =>                                                                   
	          mst_exec_state <= IDLE;                                                           
	                                                                                            
	      end case;                                                                             
	    end if;                                                                                 
	  end if;                                                                                   
	end process;                                                                                


	--tvalid generation
	--axis_tvalid is asserted when the control state machine's state is SEND_STREAM and
	--number of output streaming data is less than the NUMBER_OF_OUTPUT_WORDS.
	axis_tvalid <= '1' when ((read_pointer < NUMBER_OF_OUTPUT_WORDS) and pulse_int='1' and fifo_empty = '0' and M_AXIS_TREADY = '1') else '0';
	                                                                                               
	-- AXI tlast generation                                                                        
	-- axis_tlast is asserted number of output streaming data is NUMBER_OF_OUTPUT_WORDS-1          
	-- (0 to NUMBER_OF_OUTPUT_WORDS-1)                                                             
	axis_tlast <= '1' when (read_pointer = NUMBER_OF_OUTPUT_WORDS-1) else '0';                     
	                                                                                               
	-- Delay the axis_tvalid and axis_tlast signal by one clock cycle                              
	-- to match the latency of M_AXIS_TDATA                                                        
	process(M_AXIS_ACLK)                                                                           
	begin                                                                                          
	  if (rising_edge (M_AXIS_ACLK)) then                                                          
	    if(M_AXIS_ARESETN = '0') then                                                              
	      axis_tvalid_delay <= '0';                                                                
	      axis_tlast_delay <= '0';                                                                 
	    else                                                                                       
	      axis_tvalid_delay <= axis_tvalid;                                                        
	      axis_tlast_delay <= axis_tlast;                                                          
	    end if;                                                                                    
	  end if;                                                                                      
	end process;                                                                                   


	--read_pointer pointer
	process(M_AXIS_ACLK)                                                       
	begin                                                                            
	  if (rising_edge (M_AXIS_ACLK)) then                                            
	    if(M_AXIS_ARESETN = '0') then                                                
	      read_pointer <= 0;                                                         
	      tx_done  <= '0';         
		  pulse_int <= '0';
	    else
		  pulse_int <= not pulse_int;
	      if (tx_done = '1') then
	        read_pointer <= 0;
	      end if;                                                                         
	      if (read_pointer <= NUMBER_OF_OUTPUT_WORDS-1) then                         
	        if (fifo_load = '1') then                                                    
	          -- write pointer is incremented after every read from the FIFO          
	          -- when FIFO read signal is enabled.                                   
	          read_pointer <= read_pointer + 1;                                      
	          tx_done <= '0';                                                        
	        end if;                                                                  
	      elsif (read_pointer = NUMBER_OF_OUTPUT_WORDS) then                         
	        -- tx_done is asserted when NUMBER_OF_OUTPUT_WORDS numbers of streaming data
	        -- has been out.                                                         
	        tx_done <= '1';                                                          
	      end  if;                                                                   
	    end  if;                                                                     
	  end  if;                                                                       
	end process;                                                                     

	--write_pointer pointer
	process(M_AXIS_ACLK)                                                       
	begin                                                                            
	  if (rising_edge (M_AXIS_ACLK)) then                                            
	    if(M_AXIS_ARESETN = '0') then                                                
	      write_pointer <= 0;                                                         
	      tx_done  <= '0';       
	    else
	      if (tx_done = '1') then
	        write_pointer <= 0;
	      end if;                                                                         
	      if (write_pointer <= NUMBER_OF_OUTPUT_WORDS-1) then                         
	        if (fifo_push = '1') then                                                    
	          -- write pointer is incremented after every write to the FIFO          
	          -- when FIFO read signal is enabled.                                   
	          write_pointer <= write_pointer + 1;                                      
	          tx_done <= '0';                                                        
	        end if;                                                                                                                         
	      end  if;                                                                   
	    end  if;                                                                     
	  end  if;                                                                       
	end process;  

	--FIFO Control
	fifo_push <= pulse and not fifo_full;
	fifo_load <= M_AXIS_TREADY and axis_tvalid and not fifo_empty;
	
	fifo_nbits_2: if INPUT_FIFO_BITS = 2 generate
	process(fifo_cnt)
	begin
		if fifo_cnt = 3 then
			fifo_full <= '1';
		else
			fifo_full <= '0';
		end if;
	end process;
	
	-- FIFO Implementation  
	  process(M_AXIS_ACLK)
	  variable  sig_one : integer := 1;     
	  begin                                                                         
	    if (rising_edge (M_AXIS_ACLK)) then                                         
	      if(M_AXIS_ARESETN = '0') then                                             
	        fifo_data0 <= (others => '0');
			fifo_data1 <= (others => '0');
			fifo_data2 <= (others => '0');
			fifo_data3 <= (others => '0');
			fifo_cnt   <= (others => '0');
			fifo_empty <= '1';
			stream_data_out <= std_logic_vector(to_unsigned(sig_one,C_M_AXIS_TDATA_WIDTH)); 
	      elsif (fifo_push = '1' and fifo_load = '0') then -- Only push 
			fifo_empty <= '0';
			if fifo_empty = '0' then
				fifo_cnt   <= fifo_cnt + 1;
			end if;
			fifo_data0 <= input_data;
			fifo_data1 <= fifo_data0;
			fifo_data2 <= fifo_data1;
			fifo_data3 <= fifo_data2;
		  elsif (fifo_push = '0' and fifo_load = '1') then -- Only load
			if fifo_cnt = 0 then
				fifo_empty <= '1';
			else
				fifo_cnt <= fifo_cnt - 1;
			end if;
			case fifo_cnt is
				when "00" =>
					stream_data_out <= fifo_data0;
				when "01" =>
					stream_data_out <= fifo_data1;
				when "10" =>
					stream_data_out <= fifo_data2;
				when others =>
					stream_data_out <= fifo_data3;	
			end case;
		  elsif (fifo_push = '1' and fifo_load = '1') then -- push & load
			fifo_data0 <= input_data;
			fifo_data1 <= fifo_data0;
			fifo_data2 <= fifo_data1;
			fifo_data3 <= fifo_data2;
			case fifo_cnt is
				when "00" =>
					stream_data_out <= fifo_data0;
				when "01" =>
					stream_data_out <= fifo_data1;
				when "10" =>
					stream_data_out <= fifo_data2;
				when others =>
					stream_data_out <= fifo_data3;	
			end case;			
	      end if;                                                                   
	     end if;                                                                    
	   end process; 	
	end generate;
	
	fifo_nbits_1: if INPUT_FIFO_BITS = 1 generate
	process(fifo_cnt)
	begin
		if fifo_cnt = 1 then
			fifo_full <= '1';
		else
			fifo_full <= '0';
		end if;
	end process;
	
	-- FIFO Implementation  
	  process(M_AXIS_ACLK)
	  variable  sig_one : integer := 1;     
	  begin                                                                         
	    if (rising_edge (M_AXIS_ACLK)) then                                         
	      if(M_AXIS_ARESETN = '0') then                                             
	        fifo_data0 <= (others => '0');
			fifo_data1 <= (others => '0');
			fifo_cnt   <= (others => '0');
			fifo_empty <= '1';
			stream_data_out <= std_logic_vector(to_unsigned(sig_one,C_M_AXIS_TDATA_WIDTH)); 
	      elsif (fifo_push = '1' and fifo_load = '0') then -- Only push 
			fifo_empty <= '0';
			if fifo_empty = '0' then
				fifo_cnt   <= "01";
			end if;
			fifo_data0 <= input_data;
			fifo_data1 <= fifo_data0;
		  elsif (fifo_push = '0' and fifo_load = '1') then -- Only load
			if fifo_cnt = 0 then
				fifo_empty <= '1';
			else
				fifo_cnt <= "00";
			end if;
			case fifo_cnt is
				when "00" =>
					stream_data_out <= fifo_data0;
				when others =>
					stream_data_out <= fifo_data1;
			end case;
		  elsif (fifo_push = '1' and fifo_load = '1') then -- push & load
			fifo_data0 <= input_data;
			fifo_data1 <= fifo_data0;
			case fifo_cnt is
				when "00" =>
					stream_data_out <= fifo_data0;
				when others =>
					stream_data_out <= fifo_data1;
			end case;			
	      end if;                                                                   
	     end if;                                                                    
	   end process; 	
	end generate;

end implementation;
