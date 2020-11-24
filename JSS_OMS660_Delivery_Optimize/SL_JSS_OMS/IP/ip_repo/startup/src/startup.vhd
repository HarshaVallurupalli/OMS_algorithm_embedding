----------------------------------------------------------------------------------
-- Company: ESPROS		
-- Engineer: msc
-- 
-- Create Date: 01/04/2017 09:58:51 AM
-- Design Name: startup 
-- Module Name: startup - Behavioral
--
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

-- Startup
entity startup is
	Generic (
		WAIT_CYCLE_VDD_RAMP : Integer := 0;
		WAIT_CYCLE_VDDIO_RAMP : Integer := 0;
		WAIT_CYCLE_VDDA_RAMP : Integer := 1000000;
		WAIT_CYCLE_VBS_RAMP : Integer := 1000000;
		WAIT_CYCLE_CHIP_RDY : Integer := 1000000
	);
	Port ( 
		clk : in STD_LOGIC;
		en : in STD_LOGIC;
		rdy : out std_logic;
		vdd_en : out std_logic;
        vddio_en: out std_logic;
		vdda_en : out std_logic;
		vddhpx_en : out std_logic;
		vbs_en : out std_logic;
		chip_rstn : out std_logic);
end startup;

architecture Behavioral of startup is
	type startup_fsm is (idle, ramp_vdd, ramp_vddio, ramp_vdda, ramp_vbs, wait_chip_ready, done);
	signal counter : unsigned(31 downto 0) := (others => '0');
	signal state : startup_fsm := idle;
begin

-- FSM
process (clk)
begin
	if rising_edge(clk) then
		Case state is
			when ramp_vdd =>
				if counter<1 then
					if en='1' then
						state <= ramp_vddio;
						counter <= to_unsigned(WAIT_CYCLE_VDDIO_RAMP,32);
					else
						state <= idle;
						counter <= (others => '0');
					end if;
				else
					counter <= counter - 1;
				end if;
			when ramp_vddio =>
				If counter<1 then
					If en='1' then
						state <= ramp_vdda;
						counter <= to_unsigned(WAIT_CYCLE_VDDA_RAMP,32);
					else
						state <= ramp_vdd;
						counter <= to_unsigned(WAIT_CYCLE_VDD_RAMP,32);
					end if;
				else
					counter <= counter - 1;
				end if;
			when ramp_vdda =>
				If counter<1 then
					If en='1' then
						state <= ramp_vbs;
						counter <= to_unsigned(WAIT_CYCLE_VBS_RAMP,32);
					else
						state <= ramp_vddio;
						counter <= to_unsigned(WAIT_CYCLE_VDDIO_RAMP,32);
					end if;
				else
					counter <= counter - 1;
				end if;
			when ramp_vbs =>
				If counter<1 then
					If en='1' then
						state <= wait_chip_ready;
						counter <= to_unsigned(WAIT_CYCLE_CHIP_RDY,32);
					else
						state <= ramp_vdda;
						counter <= to_unsigned(WAIT_CYCLE_VDDA_RAMP,32);
					end if;
				else
					counter <= counter - 1;
				end if;
			when wait_chip_ready =>
				If counter<1 then
					If en='1' then
						state <= done;
						counter <= (others => '0');
					else
						state <= ramp_vbs;
						counter <= to_unsigned(WAIT_CYCLE_VBS_RAMP,32);
					end if;
				else
					counter <= counter - 1;
				end if;
			when done =>
				if en='0' then
					state <= ramp_vbs;
					counter <= to_unsigned(WAIT_CYCLE_VBS_RAMP,32);
				end if;
			when others => -- others & idle
                    if en='1' then
                        state <= ramp_vdd;
                        counter <= to_unsigned(WAIT_CYCLE_VDD_RAMP,32);
                    end if;
    end case;
  end if;
end process;

-- FSM depending signals
process (state)
begin
	case state is
		when ramp_vdd =>
			rdy <= '0';	
			vdd_en <= '1';
    	    vddio_en <= '0';	
			vdda_en <= '0';	
			vbs_en <= '0';	
			vddhpx_en <= '0';
			chip_rstn <= '0';	
		when ramp_vddio =>
			rdy <= '0';	
			vdd_en <= '1';
    	    vddio_en <= '1';	
			vdda_en <= '0';	
			vbs_en <= '0';	
			vddhpx_en <= '0';
			chip_rstn <= '0';	
		when ramp_vdda =>
			rdy <= '0';	
			vdd_en <= '1';
    	    vddio_en <= '1';	
			vdda_en <= '1';	
			vbs_en <= '0';	
			vddhpx_en <= '1';
			chip_rstn <= '0';	
		when ramp_vbs =>
			rdy <= '0';	
			vdd_en <= '1';
    	    vddio_en <= '1';	
			vdda_en <= '1';	
			vbs_en <= '1';	
			vddhpx_en <= '1';
			chip_rstn <= '0';	
		when wait_chip_ready =>
			rdy <= '0';	
			vdd_en <= '1';
    	    vddio_en <= '1';	
			vdda_en <= '1';	
			vbs_en <= '1';	
			vddhpx_en <= '1';
			chip_rstn <= '1';	
		when done =>
			rdy <= '1';	
			vdd_en <= '1';
    	    vddio_en <= '1';	
			vdda_en <= '1';	
			vbs_en <= '1';	
			vddhpx_en <= '1';
			chip_rstn <= '1';
		when others  => -- others and idle
			rdy <= '0';	
			vdd_en <= '0';
    	    vddio_en <= '0';	
			vdda_en <= '0';	
			vbs_en <= '0';	
			vddhpx_en <= '0';
			chip_rstn <= '0';
	end case;	
end process;

end Behavioral;
-- End startup
