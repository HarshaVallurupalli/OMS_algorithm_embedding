
################################################################
# This is a generated script based on design: design_1
#
# Though there are limitations about the generated script,
# the main purpose of this utility is to make learning
# IP Integrator Tcl commands easier.
################################################################

namespace eval _tcl {
proc get_script_folder {} {
   set script_path [file normalize [info script]]
   set script_folder [file dirname $script_path]
   return $script_folder
}
}
variable script_folder
set script_folder [_tcl::get_script_folder]

################################################################
# Check if script is running in correct Vivado version.
################################################################
set scripts_vivado_version 2018.2
set current_vivado_version [version -short]

if { [string first $scripts_vivado_version $current_vivado_version] == -1 } {
   puts ""
   catch {common::send_msg_id "BD_TCL-109" "ERROR" "This script was generated using Vivado <$scripts_vivado_version> and is being run in <$current_vivado_version> of Vivado. Please run the script in Vivado <$scripts_vivado_version> then open the design in Vivado <$current_vivado_version>. Upgrade the design by running \"Tools => Report => Report IP Status...\", then run write_bd_tcl to create an updated script."}

   return 1
}

################################################################
# START
################################################################

# To test this script, run the following commands from Vivado Tcl console:
# source design_1_script.tcl


# The design that will be created by this Tcl script contains the following 
# module references:
# clockMux1, clockMux2, clockMux3, ip_mux, op_demux

# Please add the sources of those modules before sourcing this Tcl script.

# If there is no project opened, this script will create a
# project, but make sure you do not have an existing project
# <./myproj/project_1.xpr> in the current working folder.

set list_projs [get_projects -quiet]
if { $list_projs eq "" } {
   create_project project_1 myproj -part xc7z020clg400-1
}


# CHANGE DESIGN NAME HERE
variable design_name
set design_name design_1

# If you do not already have an existing IP Integrator design open,
# you can create a design using the following command:
#    create_bd_design $design_name

# Creating design if needed
set errMsg ""
set nRet 0

set cur_design [current_bd_design -quiet]
set list_cells [get_bd_cells -quiet]

if { ${design_name} eq "" } {
   # USE CASES:
   #    1) Design_name not set

   set errMsg "Please set the variable <design_name> to a non-empty value."
   set nRet 1

} elseif { ${cur_design} ne "" && ${list_cells} eq "" } {
   # USE CASES:
   #    2): Current design opened AND is empty AND names same.
   #    3): Current design opened AND is empty AND names diff; design_name NOT in project.
   #    4): Current design opened AND is empty AND names diff; design_name exists in project.

   if { $cur_design ne $design_name } {
      common::send_msg_id "BD_TCL-001" "INFO" "Changing value of <design_name> from <$design_name> to <$cur_design> since current design is empty."
      set design_name [get_property NAME $cur_design]
   }
   common::send_msg_id "BD_TCL-002" "INFO" "Constructing design in IPI design <$cur_design>..."

} elseif { ${cur_design} ne "" && $list_cells ne "" && $cur_design eq $design_name } {
   # USE CASES:
   #    5) Current design opened AND has components AND same names.

   set errMsg "Design <$design_name> already exists in your project, please set the variable <design_name> to another value."
   set nRet 1
} elseif { [get_files -quiet ${design_name}.bd] ne "" } {
   # USE CASES: 
   #    6) Current opened design, has components, but diff names, design_name exists in project.
   #    7) No opened design, design_name exists in project.

   set errMsg "Design <$design_name> already exists in your project, please set the variable <design_name> to another value."
   set nRet 2

} else {
   # USE CASES:
   #    8) No opened design, design_name not in project.
   #    9) Current opened design, has components, but diff names, design_name not in project.

   common::send_msg_id "BD_TCL-003" "INFO" "Currently there is no design <$design_name> in project, so creating one..."

   create_bd_design $design_name

   common::send_msg_id "BD_TCL-004" "INFO" "Making design <$design_name> as current_bd_design."
   current_bd_design $design_name

}

common::send_msg_id "BD_TCL-005" "INFO" "Currently the variable <design_name> is equal to \"$design_name\"."

if { $nRet != 0 } {
   catch {common::send_msg_id "BD_TCL-114" "ERROR" $errMsg}
   return $nRet
}

##################################################################
# DESIGN PROCs
##################################################################



# Procedure to create entire design; Provide argument to make
# procedure reusable. If parentCell is "", will use root.
proc create_root_design { parentCell } {

  variable script_folder
  variable design_name

  if { $parentCell eq "" } {
     set parentCell [get_bd_cells /]
  }

  # Get object for parentCell
  set parentObj [get_bd_cells $parentCell]
  if { $parentObj == "" } {
     catch {common::send_msg_id "BD_TCL-100" "ERROR" "Unable to find parent cell <$parentCell>!"}
     return
  }

  # Make sure parentObj is hier blk
  set parentType [get_property TYPE $parentObj]
  if { $parentType ne "hier" } {
     catch {common::send_msg_id "BD_TCL-101" "ERROR" "Parent <$parentObj> has TYPE = <$parentType>. Expected to be <hier>."}
     return
  }

  # Save current instance; Restore later
  set oldCurInst [current_bd_instance .]

  # Set parent object as current
  current_bd_instance $parentObj


  # Create interface ports
  set DDR [ create_bd_intf_port -mode Master -vlnv xilinx.com:interface:ddrx_rtl:1.0 DDR ]
  set FIXED_IO [ create_bd_intf_port -mode Master -vlnv xilinx.com:display_processing_system7:fixedio_rtl:1.0 FIXED_IO ]
  set IIC_1_0 [ create_bd_intf_port -mode Master -vlnv xilinx.com:interface:iic_rtl:1.0 IIC_1_0 ]

  # Create ports
  set FCLK_CLK0 [ create_bd_port -dir O FCLK_CLK0 ]
  set FCLK_RESET0_N [ create_bd_port -dir O FCLK_RESET0_N ]
  set data_in [ create_bd_port -dir I -from 11 -to 0 data_in ]
  set data_in1 [ create_bd_port -dir I -from 11 -to 0 data_in1 ]
  set data_in2 [ create_bd_port -dir I -from 11 -to 0 data_in2 ]
  set data_in3 [ create_bd_port -dir I -from 11 -to 0 data_in3 ]
  set dclk_in [ create_bd_port -dir I dclk_in ]
  set dclk_in1 [ create_bd_port -dir I dclk_in1 ]
  set dclk_in2 [ create_bd_port -dir I dclk_in2 ]
  set dclk_in3 [ create_bd_port -dir I dclk_in3 ]
  set gpio_io_o_0 [ create_bd_port -dir O -from 3 -to 0 gpio_io_o_0 ]
  set gpio_io_o_1 [ create_bd_port -dir O -from 3 -to 0 gpio_io_o_1 ]
  set gpio_io_o_2 [ create_bd_port -dir O -from 3 -to 0 gpio_io_o_2 ]
  set gpio_io_o_3 [ create_bd_port -dir O -from 3 -to 0 gpio_io_o_3 ]
  set hsync_in [ create_bd_port -dir I hsync_in ]
  set hsync_in1 [ create_bd_port -dir I hsync_in1 ]
  set hsync_in2 [ create_bd_port -dir I hsync_in2 ]
  set hsync_in3 [ create_bd_port -dir I hsync_in3 ]
  set vsync_in [ create_bd_port -dir I vsync_in ]
  set vsync_in1 [ create_bd_port -dir I vsync_in1 ]
  set vsync_in2 [ create_bd_port -dir I vsync_in2 ]
  set vsync_in3 [ create_bd_port -dir I vsync_in3 ]
  set xsync_sat_in [ create_bd_port -dir I xsync_sat_in ]
  set xsync_sat_in1 [ create_bd_port -dir I xsync_sat_in1 ]
  set xsync_sat_in2 [ create_bd_port -dir I xsync_sat_in2 ]
  set xsync_sat_in3 [ create_bd_port -dir I xsync_sat_in3 ]

  # Create instance: TOF_cos_sl_0, and set properties
  set TOF_cos_sl_0 [ create_bd_cell -type ip -vlnv xilinx.com:espros:TOF_cos_sl:1.0 TOF_cos_sl_0 ]
  set_property -dict [ list \
   CONFIG.ENABLE_INPUT_FIFO {true} \
 ] $TOF_cos_sl_0

  # Create instance: axi_bram_ctrl_dbg_unit, and set properties
  set axi_bram_ctrl_dbg_unit [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_bram_ctrl:4.0 axi_bram_ctrl_dbg_unit ]
  set_property -dict [ list \
   CONFIG.SINGLE_PORT_BRAM {1} \
 ] $axi_bram_ctrl_dbg_unit

  # Create instance: axi_dma_SG_sort, and set properties
  set axi_dma_SG_sort [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_dma:7.1 axi_dma_SG_sort ]
  set_property -dict [ list \
   CONFIG.c_enable_multi_channel {0} \
   CONFIG.c_include_mm2s {0} \
   CONFIG.c_include_s2mm_dre {0} \
   CONFIG.c_s2mm_burst_size {16} \
   CONFIG.c_sg_include_stscntrl_strm {0} \
   CONFIG.c_sg_length_width {23} \
 ] $axi_dma_SG_sort

  # Create instance: axi_gpio_Sel1, and set properties
  set axi_gpio_Sel1 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_gpio:2.0 axi_gpio_Sel1 ]
  set_property -dict [ list \
   CONFIG.C_ALL_OUTPUTS {1} \
   CONFIG.C_GPIO_WIDTH {1} \
   CONFIG.C_INTERRUPT_PRESENT {0} \
 ] $axi_gpio_Sel1

  # Create instance: axi_gpio_Sel2, and set properties
  set axi_gpio_Sel2 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_gpio:2.0 axi_gpio_Sel2 ]
  set_property -dict [ list \
   CONFIG.C_ALL_OUTPUTS {1} \
   CONFIG.C_GPIO_WIDTH {1} \
   CONFIG.C_INTERRUPT_PRESENT {0} \
 ] $axi_gpio_Sel2

  # Create instance: axi_gpio_led, and set properties
  set axi_gpio_led [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_gpio:2.0 axi_gpio_led ]
  set_property -dict [ list \
   CONFIG.C_ALL_INPUTS_2 {0} \
   CONFIG.C_ALL_OUTPUTS {1} \
   CONFIG.C_ALL_OUTPUTS_2 {1} \
   CONFIG.C_GPIO2_WIDTH {1} \
   CONFIG.C_GPIO_WIDTH {1} \
   CONFIG.C_INTERRUPT_PRESENT {0} \
   CONFIG.C_IS_DUAL {1} \
 ] $axi_gpio_led

  # Create instance: axi_gpio_power_reset, and set properties
  set axi_gpio_power_reset [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_gpio:2.0 axi_gpio_power_reset ]
  set_property -dict [ list \
   CONFIG.C_ALL_OUTPUTS {1} \
   CONFIG.C_GPIO_WIDTH {4} \
 ] $axi_gpio_power_reset

  # Create instance: axi_mem_intercon, and set properties
  set axi_mem_intercon [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_interconnect:2.1 axi_mem_intercon ]
  set_property -dict [ list \
   CONFIG.NUM_MI {1} \
 ] $axi_mem_intercon

  # Create instance: axi_mem_intercon_1, and set properties
  set axi_mem_intercon_1 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_interconnect:2.1 axi_mem_intercon_1 ]
  set_property -dict [ list \
   CONFIG.NUM_MI {1} \
   CONFIG.S00_HAS_DATA_FIFO {0} \
 ] $axi_mem_intercon_1

  # Create instance: axi_mem_intercon_3, and set properties
  set axi_mem_intercon_3 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_interconnect:2.1 axi_mem_intercon_3 ]
  set_property -dict [ list \
   CONFIG.NUM_MI {1} \
   CONFIG.NUM_SI {2} \
 ] $axi_mem_intercon_3

  # Create instance: axi_smc, and set properties
  set axi_smc [ create_bd_cell -type ip -vlnv xilinx.com:ip:smartconnect:1.0 axi_smc ]
  set_property -dict [ list \
   CONFIG.NUM_SI {1} \
 ] $axi_smc

  # Create instance: axis_switch_2to1_0, and set properties
  set axis_switch_2to1_0 [ create_bd_cell -type ip -vlnv xilinx.com:user:axis_switch_2to1:1.0 axis_switch_2to1_0 ]

  # Create instance: blk_mem_gen_dbg_unit, and set properties
  set blk_mem_gen_dbg_unit [ create_bd_cell -type ip -vlnv xilinx.com:ip:blk_mem_gen:8.4 blk_mem_gen_dbg_unit ]
  set_property -dict [ list \
   CONFIG.Assume_Synchronous_Clk {false} \
   CONFIG.Byte_Size {8} \
   CONFIG.EN_SAFETY_CKT {true} \
   CONFIG.Enable_32bit_Address {true} \
   CONFIG.Enable_B {Use_ENB_Pin} \
   CONFIG.Memory_Type {True_Dual_Port_RAM} \
   CONFIG.Operating_Mode_A {WRITE_FIRST} \
   CONFIG.Port_B_Clock {100} \
   CONFIG.Port_B_Enable_Rate {100} \
   CONFIG.Port_B_Write_Rate {50} \
   CONFIG.Register_PortA_Output_of_Memory_Primitives {false} \
   CONFIG.Register_PortB_Output_of_Memory_Primitives {false} \
   CONFIG.Use_Byte_Write_Enable {true} \
   CONFIG.Use_RSTA_Pin {true} \
   CONFIG.Use_RSTB_Pin {true} \
   CONFIG.use_bram_block {BRAM_Controller} \
 ] $blk_mem_gen_dbg_unit

  # Create instance: blk_mem_gen_dcs, and set properties
  set blk_mem_gen_dcs [ create_bd_cell -type ip -vlnv xilinx.com:ip:blk_mem_gen:8.4 blk_mem_gen_dcs ]
  set_property -dict [ list \
   CONFIG.Assume_Synchronous_Clk {true} \
   CONFIG.Byte_Size {9} \
   CONFIG.EN_SAFETY_CKT {false} \
   CONFIG.Enable_32bit_Address {false} \
   CONFIG.Enable_B {Use_ENB_Pin} \
   CONFIG.Memory_Type {Simple_Dual_Port_RAM} \
   CONFIG.Operating_Mode_A {NO_CHANGE} \
   CONFIG.Operating_Mode_B {READ_FIRST} \
   CONFIG.Port_B_Clock {100} \
   CONFIG.Port_B_Enable_Rate {100} \
   CONFIG.Read_Width_A {16} \
   CONFIG.Read_Width_B {16} \
   CONFIG.Register_PortA_Output_of_Memory_Primitives {false} \
   CONFIG.Register_PortB_Output_of_Memory_Primitives {true} \
   CONFIG.Use_Byte_Write_Enable {false} \
   CONFIG.Use_RSTA_Pin {false} \
   CONFIG.Write_Depth_A {2048} \
   CONFIG.Write_Width_A {16} \
   CONFIG.Write_Width_B {16} \
   CONFIG.use_bram_block {Stand_Alone} \
 ] $blk_mem_gen_dcs

  # Create instance: blk_mem_gen_gs, and set properties
  set blk_mem_gen_gs [ create_bd_cell -type ip -vlnv xilinx.com:ip:blk_mem_gen:8.4 blk_mem_gen_gs ]
  set_property -dict [ list \
   CONFIG.Assume_Synchronous_Clk {true} \
   CONFIG.Byte_Size {9} \
   CONFIG.EN_SAFETY_CKT {false} \
   CONFIG.Enable_32bit_Address {false} \
   CONFIG.Enable_B {Use_ENB_Pin} \
   CONFIG.Memory_Type {Simple_Dual_Port_RAM} \
   CONFIG.Operating_Mode_A {NO_CHANGE} \
   CONFIG.Operating_Mode_B {READ_FIRST} \
   CONFIG.Port_B_Clock {100} \
   CONFIG.Port_B_Enable_Rate {100} \
   CONFIG.Read_Width_A {13} \
   CONFIG.Read_Width_B {13} \
   CONFIG.Register_PortA_Output_of_Memory_Primitives {false} \
   CONFIG.Register_PortB_Output_of_Memory_Primitives {true} \
   CONFIG.Use_Byte_Write_Enable {false} \
   CONFIG.Use_RSTA_Pin {false} \
   CONFIG.Write_Depth_A {2048} \
   CONFIG.Write_Width_A {13} \
   CONFIG.Write_Width_B {13} \
   CONFIG.use_bram_block {Stand_Alone} \
 ] $blk_mem_gen_gs

  # Create instance: clk_wiz_0, and set properties
  set clk_wiz_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:clk_wiz:6.0 clk_wiz_0 ]
  set_property -dict [ list \
   CONFIG.CLKOUT1_DRIVES {BUFG} \
   CONFIG.CLKOUT1_JITTER {130.958} \
   CONFIG.CLKOUT1_PHASE_ERROR {98.575} \
   CONFIG.CLKOUT1_REQUESTED_OUT_FREQ {100.000} \
   CONFIG.CLKOUT2_DRIVES {BUFG} \
   CONFIG.CLKOUT3_DRIVES {BUFG} \
   CONFIG.CLKOUT4_DRIVES {BUFG} \
   CONFIG.CLKOUT5_DRIVES {BUFG} \
   CONFIG.CLKOUT6_DRIVES {BUFG} \
   CONFIG.CLKOUT7_DRIVES {BUFG} \
   CONFIG.CLK_OUT1_PORT {epc_modclk} \
   CONFIG.MMCM_CLKFBOUT_MULT_F {10.000} \
   CONFIG.MMCM_CLKOUT0_DIVIDE_F {10.000} \
   CONFIG.MMCM_DIVCLK_DIVIDE {1} \
   CONFIG.OVERRIDE_MMCM {false} \
   CONFIG.SECONDARY_SOURCE {Single_ended_clock_capable_pin} \
   CONFIG.USE_DYN_RECONFIG {true} \
   CONFIG.USE_FREQ_SYNTH {false} \
   CONFIG.USE_PHASE_ALIGNMENT {false} \
   CONFIG.USE_RESET {true} \
 ] $clk_wiz_0

  # Create instance: clockMux1_0, and set properties
  set block_name clockMux1
  set block_cell_name clockMux1_0
  if { [catch {set clockMux1_0 [create_bd_cell -type module -reference $block_name $block_cell_name] } errmsg] } {
     catch {common::send_msg_id "BD_TCL-105" "ERROR" "Unable to add referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   } elseif { $clockMux1_0 eq "" } {
     catch {common::send_msg_id "BD_TCL-106" "ERROR" "Unable to referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   }
  
  # Create instance: clockMux2_0, and set properties
  set block_name clockMux2
  set block_cell_name clockMux2_0
  if { [catch {set clockMux2_0 [create_bd_cell -type module -reference $block_name $block_cell_name] } errmsg] } {
     catch {common::send_msg_id "BD_TCL-105" "ERROR" "Unable to add referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   } elseif { $clockMux2_0 eq "" } {
     catch {common::send_msg_id "BD_TCL-106" "ERROR" "Unable to referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   }
  
  # Create instance: clockMux3_0, and set properties
  set block_name clockMux3
  set block_cell_name clockMux3_0
  if { [catch {set clockMux3_0 [create_bd_cell -type module -reference $block_name $block_cell_name] } errmsg] } {
     catch {common::send_msg_id "BD_TCL-105" "ERROR" "Unable to add referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   } elseif { $clockMux3_0 eq "" } {
     catch {common::send_msg_id "BD_TCL-106" "ERROR" "Unable to referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   }
  
  # Create instance: data2axistream_v1_0_3, and set properties
  set data2axistream_v1_0_3 [ create_bd_cell -type ip -vlnv msc:msc:data2axistream_v1_0:1.0 data2axistream_v1_0_3 ]
  set_property -dict [ list \
   CONFIG.INPUT_BUS_WIDTH {32} \
   CONFIG.INPUT_FIFO_BITS {2} \
 ] $data2axistream_v1_0_3

  # Create instance: data2axistream_v1_0_4, and set properties
  set data2axistream_v1_0_4 [ create_bd_cell -type ip -vlnv msc:msc:data2axistream_v1_0:1.0 data2axistream_v1_0_4 ]
  set_property -dict [ list \
   CONFIG.INPUT_BUS_WIDTH {13} \
 ] $data2axistream_v1_0_4

  # Create instance: data2ram_dcs, and set properties
  set data2ram_dcs [ create_bd_cell -type ip -vlnv xilinx.com:user:data2ram:1.0 data2ram_dcs ]
  set_property -dict [ list \
   CONFIG.C_M00_AXI_BURST_LEN {16} \
   CONFIG.NBITS_BRAM_ADDR {11} \
   CONFIG.NBITS_INPUT {16} \
   CONFIG.NBITS_LENGTH {17} \
   CONFIG.PRELOAD_RD_PULSE {true} \
 ] $data2ram_dcs

  # Create instance: data2ram_gs, and set properties
  set data2ram_gs [ create_bd_cell -type ip -vlnv xilinx.com:user:data2ram:1.0 data2ram_gs ]
  set_property -dict [ list \
   CONFIG.C_M00_AXI_BURST_LEN {16} \
   CONFIG.NBITS_BRAM_ADDR {11} \
   CONFIG.NBITS_INPUT {13} \
   CONFIG.NBITS_LENGTH {19} \
   CONFIG.PRELOAD_RD_PULSE {true} \
 ] $data2ram_gs

  # Create instance: gpio_shutter, and set properties
  set gpio_shutter [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_gpio:2.0 gpio_shutter ]
  set_property -dict [ list \
   CONFIG.C_ALL_INPUTS_2 {0} \
   CONFIG.C_ALL_OUTPUTS {1} \
   CONFIG.C_ALL_OUTPUTS_2 {1} \
   CONFIG.C_GPIO2_WIDTH {1} \
   CONFIG.C_GPIO_WIDTH {1} \
   CONFIG.C_IS_DUAL {1} \
 ] $gpio_shutter

  # Create instance: ila_0, and set properties
  set ila_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:ila:6.2 ila_0 ]
  set_property -dict [ list \
   CONFIG.C_DATA_DEPTH {32768} \
   CONFIG.C_ENABLE_ILA_AXI_MON {false} \
   CONFIG.C_MONITOR_TYPE {Native} \
   CONFIG.C_NUM_OF_PROBES {2} \
   CONFIG.C_PROBE0_WIDTH {32} \
   CONFIG.C_PROBE10_WIDTH {1} \
   CONFIG.C_PROBE11_WIDTH {1} \
   CONFIG.C_PROBE12_WIDTH {1} \
   CONFIG.C_PROBE13_WIDTH {1} \
   CONFIG.C_PROBE14_WIDTH {1} \
   CONFIG.C_PROBE16_WIDTH {1} \
   CONFIG.C_PROBE17_WIDTH {1} \
   CONFIG.C_PROBE18_WIDTH {1} \
   CONFIG.C_PROBE19_WIDTH {1} \
   CONFIG.C_PROBE1_WIDTH {17} \
   CONFIG.C_PROBE29_WIDTH {1} \
   CONFIG.C_PROBE2_WIDTH {1} \
   CONFIG.C_PROBE30_WIDTH {1} \
   CONFIG.C_PROBE31_WIDTH {1} \
   CONFIG.C_PROBE32_WIDTH {1} \
   CONFIG.C_PROBE33_WIDTH {1} \
   CONFIG.C_PROBE34_WIDTH {1} \
   CONFIG.C_PROBE35_WIDTH {1} \
   CONFIG.C_PROBE36_WIDTH {1} \
   CONFIG.C_PROBE37_WIDTH {1} \
   CONFIG.C_PROBE38_WIDTH {1} \
   CONFIG.C_PROBE39_WIDTH {1} \
   CONFIG.C_PROBE3_WIDTH {1} \
   CONFIG.C_PROBE41_WIDTH {1} \
   CONFIG.C_PROBE42_WIDTH {1} \
   CONFIG.C_PROBE4_WIDTH {1} \
   CONFIG.C_PROBE5_WIDTH {1} \
   CONFIG.C_PROBE6_WIDTH {1} \
   CONFIG.C_PROBE7_WIDTH {1} \
   CONFIG.C_PROBE8_WIDTH {1} \
   CONFIG.C_PROBE9_WIDTH {1} \
 ] $ila_0

  # Create instance: ip_mux_1, and set properties
  set block_name ip_mux
  set block_cell_name ip_mux_1
  if { [catch {set ip_mux_1 [create_bd_cell -type module -reference $block_name $block_cell_name] } errmsg] } {
     catch {common::send_msg_id "BD_TCL-105" "ERROR" "Unable to add referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   } elseif { $ip_mux_1 eq "" } {
     catch {common::send_msg_id "BD_TCL-106" "ERROR" "Unable to referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   }
  
  # Create instance: op_demux_0, and set properties
  set block_name op_demux
  set block_cell_name op_demux_0
  if { [catch {set op_demux_0 [create_bd_cell -type module -reference $block_name $block_cell_name] } errmsg] } {
     catch {common::send_msg_id "BD_TCL-105" "ERROR" "Unable to add referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   } elseif { $op_demux_0 eq "" } {
     catch {common::send_msg_id "BD_TCL-106" "ERROR" "Unable to referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   }
  
  # Create instance: processing_system7_1, and set properties
  set processing_system7_1 [ create_bd_cell -type ip -vlnv xilinx.com:ip:processing_system7:5.5 processing_system7_1 ]
  set_property -dict [ list \
   CONFIG.PCW_ACT_APU_PERIPHERAL_FREQMHZ {666.666687} \
   CONFIG.PCW_ACT_CAN0_PERIPHERAL_FREQMHZ {23.8095} \
   CONFIG.PCW_ACT_CAN1_PERIPHERAL_FREQMHZ {23.8095} \
   CONFIG.PCW_ACT_CAN_PERIPHERAL_FREQMHZ {100.000000} \
   CONFIG.PCW_ACT_DCI_PERIPHERAL_FREQMHZ {10.158730} \
   CONFIG.PCW_ACT_ENET0_PERIPHERAL_FREQMHZ {125.000000} \
   CONFIG.PCW_ACT_ENET1_PERIPHERAL_FREQMHZ {10.000000} \
   CONFIG.PCW_ACT_FPGA0_PERIPHERAL_FREQMHZ {100.000000} \
   CONFIG.PCW_ACT_FPGA1_PERIPHERAL_FREQMHZ {10.000000} \
   CONFIG.PCW_ACT_FPGA2_PERIPHERAL_FREQMHZ {10.000000} \
   CONFIG.PCW_ACT_FPGA3_PERIPHERAL_FREQMHZ {10.000000} \
   CONFIG.PCW_ACT_I2C_PERIPHERAL_FREQMHZ {50} \
   CONFIG.PCW_ACT_PCAP_PERIPHERAL_FREQMHZ {200.000000} \
   CONFIG.PCW_ACT_QSPI_PERIPHERAL_FREQMHZ {200.000000} \
   CONFIG.PCW_ACT_SDIO_PERIPHERAL_FREQMHZ {25.000000} \
   CONFIG.PCW_ACT_SMC_PERIPHERAL_FREQMHZ {10.000000} \
   CONFIG.PCW_ACT_SPI_PERIPHERAL_FREQMHZ {10.000000} \
   CONFIG.PCW_ACT_TPIU_PERIPHERAL_FREQMHZ {200.000000} \
   CONFIG.PCW_ACT_TTC0_CLK0_PERIPHERAL_FREQMHZ {111.111115} \
   CONFIG.PCW_ACT_TTC0_CLK1_PERIPHERAL_FREQMHZ {111.111115} \
   CONFIG.PCW_ACT_TTC0_CLK2_PERIPHERAL_FREQMHZ {111.111115} \
   CONFIG.PCW_ACT_TTC1_CLK0_PERIPHERAL_FREQMHZ {111.111115} \
   CONFIG.PCW_ACT_TTC1_CLK1_PERIPHERAL_FREQMHZ {111.111115} \
   CONFIG.PCW_ACT_TTC1_CLK2_PERIPHERAL_FREQMHZ {111.111115} \
   CONFIG.PCW_ACT_TTC_PERIPHERAL_FREQMHZ {50} \
   CONFIG.PCW_ACT_UART_PERIPHERAL_FREQMHZ {50.000000} \
   CONFIG.PCW_ACT_USB0_PERIPHERAL_FREQMHZ {60} \
   CONFIG.PCW_ACT_USB1_PERIPHERAL_FREQMHZ {60} \
   CONFIG.PCW_ACT_WDT_PERIPHERAL_FREQMHZ {111.111115} \
   CONFIG.PCW_APU_CLK_RATIO_ENABLE {6:2:1} \
   CONFIG.PCW_APU_PERIPHERAL_FREQMHZ {667} \
   CONFIG.PCW_ARMPLL_CTRL_FBDIV {40} \
   CONFIG.PCW_CAN0_BASEADDR {0xE0008000} \
   CONFIG.PCW_CAN0_CAN0_IO {MIO 10 .. 11} \
   CONFIG.PCW_CAN0_GRP_CLK_ENABLE {0} \
   CONFIG.PCW_CAN0_HIGHADDR {0xE0008FFF} \
   CONFIG.PCW_CAN0_PERIPHERAL_CLKSRC {External} \
   CONFIG.PCW_CAN0_PERIPHERAL_ENABLE {1} \
   CONFIG.PCW_CAN1_GRP_CLK_ENABLE {0} \
   CONFIG.PCW_CAN1_PERIPHERAL_CLKSRC {External} \
   CONFIG.PCW_CAN1_PERIPHERAL_ENABLE {0} \
   CONFIG.PCW_CAN_PERIPHERAL_CLKSRC {IO PLL} \
   CONFIG.PCW_CAN_PERIPHERAL_DIVISOR0 {5} \
   CONFIG.PCW_CAN_PERIPHERAL_DIVISOR1 {2} \
   CONFIG.PCW_CAN_PERIPHERAL_FREQMHZ {100} \
   CONFIG.PCW_CAN_PERIPHERAL_VALID {1} \
   CONFIG.PCW_CLK0_FREQ {100000000} \
   CONFIG.PCW_CLK1_FREQ {10000000} \
   CONFIG.PCW_CLK2_FREQ {10000000} \
   CONFIG.PCW_CLK3_FREQ {10000000} \
   CONFIG.PCW_CORE0_FIQ_INTR {0} \
   CONFIG.PCW_CORE0_IRQ_INTR {0} \
   CONFIG.PCW_CORE1_FIQ_INTR {0} \
   CONFIG.PCW_CORE1_IRQ_INTR {0} \
   CONFIG.PCW_CPU_CPU_6X4X_MAX_RANGE {667} \
   CONFIG.PCW_CPU_CPU_PLL_FREQMHZ {1333.333} \
   CONFIG.PCW_CPU_PERIPHERAL_CLKSRC {ARM PLL} \
   CONFIG.PCW_CPU_PERIPHERAL_DIVISOR0 {2} \
   CONFIG.PCW_CRYSTAL_PERIPHERAL_FREQMHZ {33.333333} \
   CONFIG.PCW_DCI_PERIPHERAL_CLKSRC {DDR PLL} \
   CONFIG.PCW_DCI_PERIPHERAL_DIVISOR0 {15} \
   CONFIG.PCW_DCI_PERIPHERAL_DIVISOR1 {7} \
   CONFIG.PCW_DCI_PERIPHERAL_FREQMHZ {10.159} \
   CONFIG.PCW_DDRPLL_CTRL_FBDIV {32} \
   CONFIG.PCW_DDR_DDR_PLL_FREQMHZ {1066.667} \
   CONFIG.PCW_DDR_HPRLPR_QUEUE_PARTITION {HPR(0)/LPR(32)} \
   CONFIG.PCW_DDR_HPR_TO_CRITICAL_PRIORITY_LEVEL {15} \
   CONFIG.PCW_DDR_LPR_TO_CRITICAL_PRIORITY_LEVEL {2} \
   CONFIG.PCW_DDR_PERIPHERAL_CLKSRC {DDR PLL} \
   CONFIG.PCW_DDR_PERIPHERAL_DIVISOR0 {2} \
   CONFIG.PCW_DDR_PORT0_HPR_ENABLE {0} \
   CONFIG.PCW_DDR_PORT1_HPR_ENABLE {0} \
   CONFIG.PCW_DDR_PORT2_HPR_ENABLE {0} \
   CONFIG.PCW_DDR_PORT3_HPR_ENABLE {0} \
   CONFIG.PCW_DDR_RAM_BASEADDR {0x00100000} \
   CONFIG.PCW_DDR_RAM_HIGHADDR {0x3FFFFFFF} \
   CONFIG.PCW_DDR_WRITE_TO_CRITICAL_PRIORITY_LEVEL {2} \
   CONFIG.PCW_DM_WIDTH {4} \
   CONFIG.PCW_DQS_WIDTH {4} \
   CONFIG.PCW_DQ_WIDTH {32} \
   CONFIG.PCW_ENET0_BASEADDR {0xE000B000} \
   CONFIG.PCW_ENET0_ENET0_IO {MIO 16 .. 27} \
   CONFIG.PCW_ENET0_GRP_MDIO_ENABLE {1} \
   CONFIG.PCW_ENET0_GRP_MDIO_IO {MIO 52 .. 53} \
   CONFIG.PCW_ENET0_HIGHADDR {0xE000BFFF} \
   CONFIG.PCW_ENET0_PERIPHERAL_CLKSRC {IO PLL} \
   CONFIG.PCW_ENET0_PERIPHERAL_DIVISOR0 {8} \
   CONFIG.PCW_ENET0_PERIPHERAL_DIVISOR1 {1} \
   CONFIG.PCW_ENET0_PERIPHERAL_ENABLE {1} \
   CONFIG.PCW_ENET0_PERIPHERAL_FREQMHZ {1000 Mbps} \
   CONFIG.PCW_ENET0_RESET_ENABLE {0} \
   CONFIG.PCW_ENET1_GRP_MDIO_ENABLE {0} \
   CONFIG.PCW_ENET1_PERIPHERAL_CLKSRC {IO PLL} \
   CONFIG.PCW_ENET1_PERIPHERAL_DIVISOR0 {1} \
   CONFIG.PCW_ENET1_PERIPHERAL_DIVISOR1 {1} \
   CONFIG.PCW_ENET1_PERIPHERAL_ENABLE {0} \
   CONFIG.PCW_ENET1_PERIPHERAL_FREQMHZ {1000 Mbps} \
   CONFIG.PCW_ENET1_RESET_ENABLE {0} \
   CONFIG.PCW_ENET_RESET_ENABLE {1} \
   CONFIG.PCW_ENET_RESET_POLARITY {Active Low} \
   CONFIG.PCW_ENET_RESET_SELECT {Share reset pin} \
   CONFIG.PCW_EN_4K_TIMER {0} \
   CONFIG.PCW_EN_CAN0 {1} \
   CONFIG.PCW_EN_CAN1 {0} \
   CONFIG.PCW_EN_CLK0_PORT {1} \
   CONFIG.PCW_EN_CLK1_PORT {0} \
   CONFIG.PCW_EN_CLK2_PORT {0} \
   CONFIG.PCW_EN_CLK3_PORT {0} \
   CONFIG.PCW_EN_CLKTRIG0_PORT {0} \
   CONFIG.PCW_EN_CLKTRIG1_PORT {0} \
   CONFIG.PCW_EN_CLKTRIG2_PORT {0} \
   CONFIG.PCW_EN_CLKTRIG3_PORT {0} \
   CONFIG.PCW_EN_DDR {1} \
   CONFIG.PCW_EN_EMIO_CAN0 {0} \
   CONFIG.PCW_EN_EMIO_CAN1 {0} \
   CONFIG.PCW_EN_EMIO_CD_SDIO0 {0} \
   CONFIG.PCW_EN_EMIO_CD_SDIO1 {0} \
   CONFIG.PCW_EN_EMIO_ENET0 {0} \
   CONFIG.PCW_EN_EMIO_ENET1 {0} \
   CONFIG.PCW_EN_EMIO_GPIO {1} \
   CONFIG.PCW_EN_EMIO_I2C0 {0} \
   CONFIG.PCW_EN_EMIO_I2C1 {1} \
   CONFIG.PCW_EN_EMIO_MODEM_UART0 {0} \
   CONFIG.PCW_EN_EMIO_MODEM_UART1 {0} \
   CONFIG.PCW_EN_EMIO_PJTAG {0} \
   CONFIG.PCW_EN_EMIO_SDIO0 {0} \
   CONFIG.PCW_EN_EMIO_SDIO1 {0} \
   CONFIG.PCW_EN_EMIO_SPI0 {0} \
   CONFIG.PCW_EN_EMIO_SPI1 {0} \
   CONFIG.PCW_EN_EMIO_SRAM_INT {0} \
   CONFIG.PCW_EN_EMIO_TRACE {0} \
   CONFIG.PCW_EN_EMIO_TTC0 {1} \
   CONFIG.PCW_EN_EMIO_TTC1 {0} \
   CONFIG.PCW_EN_EMIO_UART0 {0} \
   CONFIG.PCW_EN_EMIO_UART1 {0} \
   CONFIG.PCW_EN_EMIO_WDT {0} \
   CONFIG.PCW_EN_EMIO_WP_SDIO0 {0} \
   CONFIG.PCW_EN_EMIO_WP_SDIO1 {0} \
   CONFIG.PCW_EN_ENET0 {1} \
   CONFIG.PCW_EN_ENET1 {0} \
   CONFIG.PCW_EN_GPIO {1} \
   CONFIG.PCW_EN_I2C0 {1} \
   CONFIG.PCW_EN_I2C1 {1} \
   CONFIG.PCW_EN_MODEM_UART0 {0} \
   CONFIG.PCW_EN_MODEM_UART1 {0} \
   CONFIG.PCW_EN_PJTAG {0} \
   CONFIG.PCW_EN_PTP_ENET0 {0} \
   CONFIG.PCW_EN_PTP_ENET1 {0} \
   CONFIG.PCW_EN_QSPI {1} \
   CONFIG.PCW_EN_RST0_PORT {1} \
   CONFIG.PCW_EN_RST1_PORT {0} \
   CONFIG.PCW_EN_RST2_PORT {0} \
   CONFIG.PCW_EN_RST3_PORT {0} \
   CONFIG.PCW_EN_SDIO0 {1} \
   CONFIG.PCW_EN_SDIO1 {0} \
   CONFIG.PCW_EN_SMC {0} \
   CONFIG.PCW_EN_SPI0 {0} \
   CONFIG.PCW_EN_SPI1 {0} \
   CONFIG.PCW_EN_TRACE {0} \
   CONFIG.PCW_EN_TTC0 {1} \
   CONFIG.PCW_EN_TTC1 {0} \
   CONFIG.PCW_EN_UART0 {0} \
   CONFIG.PCW_EN_UART1 {1} \
   CONFIG.PCW_EN_USB0 {1} \
   CONFIG.PCW_EN_USB1 {0} \
   CONFIG.PCW_EN_WDT {0} \
   CONFIG.PCW_FCLK0_PERIPHERAL_CLKSRC {IO PLL} \
   CONFIG.PCW_FCLK0_PERIPHERAL_DIVISOR0 {5} \
   CONFIG.PCW_FCLK0_PERIPHERAL_DIVISOR1 {2} \
   CONFIG.PCW_FCLK1_PERIPHERAL_CLKSRC {IO PLL} \
   CONFIG.PCW_FCLK1_PERIPHERAL_DIVISOR0 {1} \
   CONFIG.PCW_FCLK1_PERIPHERAL_DIVISOR1 {1} \
   CONFIG.PCW_FCLK2_PERIPHERAL_CLKSRC {IO PLL} \
   CONFIG.PCW_FCLK2_PERIPHERAL_DIVISOR0 {1} \
   CONFIG.PCW_FCLK2_PERIPHERAL_DIVISOR1 {1} \
   CONFIG.PCW_FCLK3_PERIPHERAL_CLKSRC {IO PLL} \
   CONFIG.PCW_FCLK3_PERIPHERAL_DIVISOR0 {1} \
   CONFIG.PCW_FCLK3_PERIPHERAL_DIVISOR1 {1} \
   CONFIG.PCW_FCLK_CLK0_BUF {TRUE} \
   CONFIG.PCW_FCLK_CLK1_BUF {FALSE} \
   CONFIG.PCW_FCLK_CLK2_BUF {FALSE} \
   CONFIG.PCW_FCLK_CLK3_BUF {FALSE} \
   CONFIG.PCW_FPGA0_PERIPHERAL_FREQMHZ {100} \
   CONFIG.PCW_FPGA1_PERIPHERAL_FREQMHZ {20} \
   CONFIG.PCW_FPGA2_PERIPHERAL_FREQMHZ {33.333333} \
   CONFIG.PCW_FPGA3_PERIPHERAL_FREQMHZ {50} \
   CONFIG.PCW_FPGA_FCLK0_ENABLE {1} \
   CONFIG.PCW_FPGA_FCLK1_ENABLE {0} \
   CONFIG.PCW_FPGA_FCLK2_ENABLE {0} \
   CONFIG.PCW_FPGA_FCLK3_ENABLE {0} \
   CONFIG.PCW_GP0_EN_MODIFIABLE_TXN {0} \
   CONFIG.PCW_GP0_NUM_READ_THREADS {4} \
   CONFIG.PCW_GP0_NUM_WRITE_THREADS {4} \
   CONFIG.PCW_GP1_EN_MODIFIABLE_TXN {0} \
   CONFIG.PCW_GP1_NUM_READ_THREADS {4} \
   CONFIG.PCW_GP1_NUM_WRITE_THREADS {4} \
   CONFIG.PCW_GPIO_BASEADDR {0xE000A000} \
   CONFIG.PCW_GPIO_EMIO_GPIO_ENABLE {1} \
   CONFIG.PCW_GPIO_EMIO_GPIO_IO {2} \
   CONFIG.PCW_GPIO_EMIO_GPIO_WIDTH {2} \
   CONFIG.PCW_GPIO_HIGHADDR {0xE000AFFF} \
   CONFIG.PCW_GPIO_MIO_GPIO_ENABLE {1} \
   CONFIG.PCW_GPIO_MIO_GPIO_IO {MIO} \
   CONFIG.PCW_GPIO_PERIPHERAL_ENABLE {1} \
   CONFIG.PCW_I2C0_BASEADDR {0xE0004000} \
   CONFIG.PCW_I2C0_GRP_INT_ENABLE {0} \
   CONFIG.PCW_I2C0_HIGHADDR {0xE0004FFF} \
   CONFIG.PCW_I2C0_I2C0_IO {MIO 14 .. 15} \
   CONFIG.PCW_I2C0_PERIPHERAL_ENABLE {1} \
   CONFIG.PCW_I2C0_RESET_ENABLE {0} \
   CONFIG.PCW_I2C1_GRP_INT_ENABLE {1} \
   CONFIG.PCW_I2C1_GRP_INT_IO {EMIO} \
   CONFIG.PCW_I2C1_I2C1_IO {EMIO} \
   CONFIG.PCW_I2C1_PERIPHERAL_ENABLE {1} \
   CONFIG.PCW_I2C1_RESET_ENABLE {0} \
   CONFIG.PCW_I2C_PERIPHERAL_FREQMHZ {111.111115} \
   CONFIG.PCW_I2C_RESET_ENABLE {0} \
   CONFIG.PCW_I2C_RESET_POLARITY {Active Low} \
   CONFIG.PCW_IMPORT_BOARD_PRESET {None} \
   CONFIG.PCW_INCLUDE_ACP_TRANS_CHECK {0} \
   CONFIG.PCW_IOPLL_CTRL_FBDIV {30} \
   CONFIG.PCW_IO_IO_PLL_FREQMHZ {1000.000} \
   CONFIG.PCW_IRQ_F2P_INTR {1} \
   CONFIG.PCW_IRQ_F2P_MODE {DIRECT} \
   CONFIG.PCW_MIO_0_DIRECTION {inout} \
   CONFIG.PCW_MIO_0_IOTYPE {LVCMOS 3.3V} \
   CONFIG.PCW_MIO_0_PULLUP {disabled} \
   CONFIG.PCW_MIO_0_SLEW {slow} \
   CONFIG.PCW_MIO_10_DIRECTION {in} \
   CONFIG.PCW_MIO_10_IOTYPE {LVCMOS 3.3V} \
   CONFIG.PCW_MIO_10_PULLUP {disabled} \
   CONFIG.PCW_MIO_10_SLEW {slow} \
   CONFIG.PCW_MIO_11_DIRECTION {out} \
   CONFIG.PCW_MIO_11_IOTYPE {LVCMOS 3.3V} \
   CONFIG.PCW_MIO_11_PULLUP {disabled} \
   CONFIG.PCW_MIO_11_SLEW {slow} \
   CONFIG.PCW_MIO_12_DIRECTION {inout} \
   CONFIG.PCW_MIO_12_IOTYPE {LVCMOS 3.3V} \
   CONFIG.PCW_MIO_12_PULLUP {disabled} \
   CONFIG.PCW_MIO_12_SLEW {slow} \
   CONFIG.PCW_MIO_13_DIRECTION {inout} \
   CONFIG.PCW_MIO_13_IOTYPE {LVCMOS 3.3V} \
   CONFIG.PCW_MIO_13_PULLUP {disabled} \
   CONFIG.PCW_MIO_13_SLEW {slow} \
   CONFIG.PCW_MIO_14_DIRECTION {inout} \
   CONFIG.PCW_MIO_14_IOTYPE {LVCMOS 3.3V} \
   CONFIG.PCW_MIO_14_PULLUP {disabled} \
   CONFIG.PCW_MIO_14_SLEW {slow} \
   CONFIG.PCW_MIO_15_DIRECTION {inout} \
   CONFIG.PCW_MIO_15_IOTYPE {LVCMOS 3.3V} \
   CONFIG.PCW_MIO_15_PULLUP {disabled} \
   CONFIG.PCW_MIO_15_SLEW {slow} \
   CONFIG.PCW_MIO_16_DIRECTION {out} \
   CONFIG.PCW_MIO_16_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_16_PULLUP {disabled} \
   CONFIG.PCW_MIO_16_SLEW {slow} \
   CONFIG.PCW_MIO_17_DIRECTION {out} \
   CONFIG.PCW_MIO_17_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_17_PULLUP {disabled} \
   CONFIG.PCW_MIO_17_SLEW {slow} \
   CONFIG.PCW_MIO_18_DIRECTION {out} \
   CONFIG.PCW_MIO_18_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_18_PULLUP {disabled} \
   CONFIG.PCW_MIO_18_SLEW {slow} \
   CONFIG.PCW_MIO_19_DIRECTION {out} \
   CONFIG.PCW_MIO_19_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_19_PULLUP {disabled} \
   CONFIG.PCW_MIO_19_SLEW {slow} \
   CONFIG.PCW_MIO_1_DIRECTION {out} \
   CONFIG.PCW_MIO_1_IOTYPE {LVCMOS 3.3V} \
   CONFIG.PCW_MIO_1_PULLUP {disabled} \
   CONFIG.PCW_MIO_1_SLEW {slow} \
   CONFIG.PCW_MIO_20_DIRECTION {out} \
   CONFIG.PCW_MIO_20_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_20_PULLUP {disabled} \
   CONFIG.PCW_MIO_20_SLEW {slow} \
   CONFIG.PCW_MIO_21_DIRECTION {out} \
   CONFIG.PCW_MIO_21_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_21_PULLUP {disabled} \
   CONFIG.PCW_MIO_21_SLEW {slow} \
   CONFIG.PCW_MIO_22_DIRECTION {in} \
   CONFIG.PCW_MIO_22_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_22_PULLUP {disabled} \
   CONFIG.PCW_MIO_22_SLEW {slow} \
   CONFIG.PCW_MIO_23_DIRECTION {in} \
   CONFIG.PCW_MIO_23_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_23_PULLUP {disabled} \
   CONFIG.PCW_MIO_23_SLEW {slow} \
   CONFIG.PCW_MIO_24_DIRECTION {in} \
   CONFIG.PCW_MIO_24_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_24_PULLUP {disabled} \
   CONFIG.PCW_MIO_24_SLEW {slow} \
   CONFIG.PCW_MIO_25_DIRECTION {in} \
   CONFIG.PCW_MIO_25_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_25_PULLUP {disabled} \
   CONFIG.PCW_MIO_25_SLEW {slow} \
   CONFIG.PCW_MIO_26_DIRECTION {in} \
   CONFIG.PCW_MIO_26_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_26_PULLUP {disabled} \
   CONFIG.PCW_MIO_26_SLEW {slow} \
   CONFIG.PCW_MIO_27_DIRECTION {in} \
   CONFIG.PCW_MIO_27_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_27_PULLUP {disabled} \
   CONFIG.PCW_MIO_27_SLEW {slow} \
   CONFIG.PCW_MIO_28_DIRECTION {inout} \
   CONFIG.PCW_MIO_28_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_28_PULLUP {disabled} \
   CONFIG.PCW_MIO_28_SLEW {slow} \
   CONFIG.PCW_MIO_29_DIRECTION {in} \
   CONFIG.PCW_MIO_29_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_29_PULLUP {disabled} \
   CONFIG.PCW_MIO_29_SLEW {slow} \
   CONFIG.PCW_MIO_2_DIRECTION {inout} \
   CONFIG.PCW_MIO_2_IOTYPE {LVCMOS 3.3V} \
   CONFIG.PCW_MIO_2_PULLUP {disabled} \
   CONFIG.PCW_MIO_2_SLEW {slow} \
   CONFIG.PCW_MIO_30_DIRECTION {out} \
   CONFIG.PCW_MIO_30_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_30_PULLUP {disabled} \
   CONFIG.PCW_MIO_30_SLEW {slow} \
   CONFIG.PCW_MIO_31_DIRECTION {in} \
   CONFIG.PCW_MIO_31_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_31_PULLUP {disabled} \
   CONFIG.PCW_MIO_31_SLEW {slow} \
   CONFIG.PCW_MIO_32_DIRECTION {inout} \
   CONFIG.PCW_MIO_32_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_32_PULLUP {disabled} \
   CONFIG.PCW_MIO_32_SLEW {slow} \
   CONFIG.PCW_MIO_33_DIRECTION {inout} \
   CONFIG.PCW_MIO_33_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_33_PULLUP {disabled} \
   CONFIG.PCW_MIO_33_SLEW {slow} \
   CONFIG.PCW_MIO_34_DIRECTION {inout} \
   CONFIG.PCW_MIO_34_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_34_PULLUP {disabled} \
   CONFIG.PCW_MIO_34_SLEW {slow} \
   CONFIG.PCW_MIO_35_DIRECTION {inout} \
   CONFIG.PCW_MIO_35_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_35_PULLUP {disabled} \
   CONFIG.PCW_MIO_35_SLEW {slow} \
   CONFIG.PCW_MIO_36_DIRECTION {in} \
   CONFIG.PCW_MIO_36_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_36_PULLUP {disabled} \
   CONFIG.PCW_MIO_36_SLEW {slow} \
   CONFIG.PCW_MIO_37_DIRECTION {inout} \
   CONFIG.PCW_MIO_37_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_37_PULLUP {disabled} \
   CONFIG.PCW_MIO_37_SLEW {slow} \
   CONFIG.PCW_MIO_38_DIRECTION {inout} \
   CONFIG.PCW_MIO_38_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_38_PULLUP {disabled} \
   CONFIG.PCW_MIO_38_SLEW {slow} \
   CONFIG.PCW_MIO_39_DIRECTION {inout} \
   CONFIG.PCW_MIO_39_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_39_PULLUP {disabled} \
   CONFIG.PCW_MIO_39_SLEW {slow} \
   CONFIG.PCW_MIO_3_DIRECTION {inout} \
   CONFIG.PCW_MIO_3_IOTYPE {LVCMOS 3.3V} \
   CONFIG.PCW_MIO_3_PULLUP {disabled} \
   CONFIG.PCW_MIO_3_SLEW {slow} \
   CONFIG.PCW_MIO_40_DIRECTION {inout} \
   CONFIG.PCW_MIO_40_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_40_PULLUP {disabled} \
   CONFIG.PCW_MIO_40_SLEW {slow} \
   CONFIG.PCW_MIO_41_DIRECTION {inout} \
   CONFIG.PCW_MIO_41_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_41_PULLUP {disabled} \
   CONFIG.PCW_MIO_41_SLEW {slow} \
   CONFIG.PCW_MIO_42_DIRECTION {inout} \
   CONFIG.PCW_MIO_42_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_42_PULLUP {disabled} \
   CONFIG.PCW_MIO_42_SLEW {slow} \
   CONFIG.PCW_MIO_43_DIRECTION {inout} \
   CONFIG.PCW_MIO_43_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_43_PULLUP {disabled} \
   CONFIG.PCW_MIO_43_SLEW {slow} \
   CONFIG.PCW_MIO_44_DIRECTION {inout} \
   CONFIG.PCW_MIO_44_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_44_PULLUP {disabled} \
   CONFIG.PCW_MIO_44_SLEW {slow} \
   CONFIG.PCW_MIO_45_DIRECTION {inout} \
   CONFIG.PCW_MIO_45_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_45_PULLUP {disabled} \
   CONFIG.PCW_MIO_45_SLEW {slow} \
   CONFIG.PCW_MIO_46_DIRECTION {in} \
   CONFIG.PCW_MIO_46_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_46_PULLUP {disabled} \
   CONFIG.PCW_MIO_46_SLEW {slow} \
   CONFIG.PCW_MIO_47_DIRECTION {inout} \
   CONFIG.PCW_MIO_47_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_47_PULLUP {disabled} \
   CONFIG.PCW_MIO_47_SLEW {slow} \
   CONFIG.PCW_MIO_48_DIRECTION {out} \
   CONFIG.PCW_MIO_48_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_48_PULLUP {disabled} \
   CONFIG.PCW_MIO_48_SLEW {slow} \
   CONFIG.PCW_MIO_49_DIRECTION {in} \
   CONFIG.PCW_MIO_49_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_49_PULLUP {disabled} \
   CONFIG.PCW_MIO_49_SLEW {slow} \
   CONFIG.PCW_MIO_4_DIRECTION {inout} \
   CONFIG.PCW_MIO_4_IOTYPE {LVCMOS 3.3V} \
   CONFIG.PCW_MIO_4_PULLUP {disabled} \
   CONFIG.PCW_MIO_4_SLEW {slow} \
   CONFIG.PCW_MIO_50_DIRECTION {in} \
   CONFIG.PCW_MIO_50_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_50_PULLUP {disabled} \
   CONFIG.PCW_MIO_50_SLEW {slow} \
   CONFIG.PCW_MIO_51_DIRECTION {inout} \
   CONFIG.PCW_MIO_51_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_51_PULLUP {disabled} \
   CONFIG.PCW_MIO_51_SLEW {slow} \
   CONFIG.PCW_MIO_52_DIRECTION {out} \
   CONFIG.PCW_MIO_52_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_52_PULLUP {disabled} \
   CONFIG.PCW_MIO_52_SLEW {slow} \
   CONFIG.PCW_MIO_53_DIRECTION {inout} \
   CONFIG.PCW_MIO_53_IOTYPE {LVCMOS 1.8V} \
   CONFIG.PCW_MIO_53_PULLUP {disabled} \
   CONFIG.PCW_MIO_53_SLEW {slow} \
   CONFIG.PCW_MIO_5_DIRECTION {inout} \
   CONFIG.PCW_MIO_5_IOTYPE {LVCMOS 3.3V} \
   CONFIG.PCW_MIO_5_PULLUP {disabled} \
   CONFIG.PCW_MIO_5_SLEW {slow} \
   CONFIG.PCW_MIO_6_DIRECTION {out} \
   CONFIG.PCW_MIO_6_IOTYPE {LVCMOS 3.3V} \
   CONFIG.PCW_MIO_6_PULLUP {disabled} \
   CONFIG.PCW_MIO_6_SLEW {slow} \
   CONFIG.PCW_MIO_7_DIRECTION {out} \
   CONFIG.PCW_MIO_7_IOTYPE {LVCMOS 3.3V} \
   CONFIG.PCW_MIO_7_PULLUP {disabled} \
   CONFIG.PCW_MIO_7_SLEW {slow} \
   CONFIG.PCW_MIO_8_DIRECTION {out} \
   CONFIG.PCW_MIO_8_IOTYPE {LVCMOS 3.3V} \
   CONFIG.PCW_MIO_8_PULLUP {disabled} \
   CONFIG.PCW_MIO_8_SLEW {slow} \
   CONFIG.PCW_MIO_9_DIRECTION {inout} \
   CONFIG.PCW_MIO_9_IOTYPE {LVCMOS 3.3V} \
   CONFIG.PCW_MIO_9_PULLUP {disabled} \
   CONFIG.PCW_MIO_9_SLEW {slow} \
   CONFIG.PCW_MIO_PRIMITIVE {54} \
   CONFIG.PCW_MIO_TREE_PERIPHERALS {GPIO#Quad SPI Flash#Quad SPI Flash#Quad SPI Flash#Quad SPI Flash#Quad SPI Flash#Quad SPI Flash#USB Reset#Quad SPI Flash#GPIO#CAN 0#CAN 0#GPIO#GPIO#I2C 0#I2C 0#Enet 0#Enet 0#Enet 0#Enet 0#Enet 0#Enet 0#Enet 0#Enet 0#Enet 0#Enet 0#Enet 0#Enet 0#USB 0#USB 0#USB 0#USB 0#USB 0#USB 0#USB 0#USB 0#USB 0#USB 0#USB 0#USB 0#SD 0#SD 0#SD 0#SD 0#SD 0#SD 0#SD 0#GPIO#UART 1#UART 1#SD 0#GPIO#Enet 0#Enet 0} \
   CONFIG.PCW_MIO_TREE_SIGNALS {gpio[0]#qspi0_ss_b#qspi0_io[0]#qspi0_io[1]#qspi0_io[2]#qspi0_io[3]/HOLD_B#qspi0_sclk#reset#qspi_fbclk#gpio[9]#rx#tx#gpio[12]#gpio[13]#scl#sda#tx_clk#txd[0]#txd[1]#txd[2]#txd[3]#tx_ctl#rx_clk#rxd[0]#rxd[1]#rxd[2]#rxd[3]#rx_ctl#data[4]#dir#stp#nxt#data[0]#data[1]#data[2]#data[3]#clk#data[5]#data[6]#data[7]#clk#cmd#data[0]#data[1]#data[2]#data[3]#cd#gpio[47]#tx#rx#wp#gpio[51]#mdc#mdio} \
   CONFIG.PCW_M_AXI_GP0_ENABLE_STATIC_REMAP {0} \
   CONFIG.PCW_M_AXI_GP0_ID_WIDTH {12} \
   CONFIG.PCW_M_AXI_GP0_SUPPORT_NARROW_BURST {0} \
   CONFIG.PCW_M_AXI_GP0_THREAD_ID_WIDTH {12} \
   CONFIG.PCW_NAND_CYCLES_T_AR {1} \
   CONFIG.PCW_NAND_CYCLES_T_CLR {1} \
   CONFIG.PCW_NAND_CYCLES_T_RC {11} \
   CONFIG.PCW_NAND_CYCLES_T_REA {1} \
   CONFIG.PCW_NAND_CYCLES_T_RR {1} \
   CONFIG.PCW_NAND_CYCLES_T_WC {11} \
   CONFIG.PCW_NAND_CYCLES_T_WP {1} \
   CONFIG.PCW_NAND_GRP_D8_ENABLE {0} \
   CONFIG.PCW_NAND_PERIPHERAL_ENABLE {0} \
   CONFIG.PCW_NOR_CS0_T_CEOE {1} \
   CONFIG.PCW_NOR_CS0_T_PC {1} \
   CONFIG.PCW_NOR_CS0_T_RC {11} \
   CONFIG.PCW_NOR_CS0_T_TR {1} \
   CONFIG.PCW_NOR_CS0_T_WC {11} \
   CONFIG.PCW_NOR_CS0_T_WP {1} \
   CONFIG.PCW_NOR_CS0_WE_TIME {0} \
   CONFIG.PCW_NOR_CS1_T_CEOE {1} \
   CONFIG.PCW_NOR_CS1_T_PC {1} \
   CONFIG.PCW_NOR_CS1_T_RC {11} \
   CONFIG.PCW_NOR_CS1_T_TR {1} \
   CONFIG.PCW_NOR_CS1_T_WC {11} \
   CONFIG.PCW_NOR_CS1_T_WP {1} \
   CONFIG.PCW_NOR_CS1_WE_TIME {0} \
   CONFIG.PCW_NOR_GRP_A25_ENABLE {0} \
   CONFIG.PCW_NOR_GRP_CS0_ENABLE {0} \
   CONFIG.PCW_NOR_GRP_CS1_ENABLE {0} \
   CONFIG.PCW_NOR_GRP_SRAM_CS0_ENABLE {0} \
   CONFIG.PCW_NOR_GRP_SRAM_CS1_ENABLE {0} \
   CONFIG.PCW_NOR_GRP_SRAM_INT_ENABLE {0} \
   CONFIG.PCW_NOR_PERIPHERAL_ENABLE {0} \
   CONFIG.PCW_NOR_SRAM_CS0_T_CEOE {1} \
   CONFIG.PCW_NOR_SRAM_CS0_T_PC {1} \
   CONFIG.PCW_NOR_SRAM_CS0_T_RC {11} \
   CONFIG.PCW_NOR_SRAM_CS0_T_TR {1} \
   CONFIG.PCW_NOR_SRAM_CS0_T_WC {11} \
   CONFIG.PCW_NOR_SRAM_CS0_T_WP {1} \
   CONFIG.PCW_NOR_SRAM_CS0_WE_TIME {0} \
   CONFIG.PCW_NOR_SRAM_CS1_T_CEOE {1} \
   CONFIG.PCW_NOR_SRAM_CS1_T_PC {1} \
   CONFIG.PCW_NOR_SRAM_CS1_T_RC {11} \
   CONFIG.PCW_NOR_SRAM_CS1_T_TR {1} \
   CONFIG.PCW_NOR_SRAM_CS1_T_WC {11} \
   CONFIG.PCW_NOR_SRAM_CS1_T_WP {1} \
   CONFIG.PCW_NOR_SRAM_CS1_WE_TIME {0} \
   CONFIG.PCW_OVERRIDE_BASIC_CLOCK {0} \
   CONFIG.PCW_P2F_CAN0_INTR {0} \
   CONFIG.PCW_P2F_ENET0_INTR {0} \
   CONFIG.PCW_P2F_GPIO_INTR {0} \
   CONFIG.PCW_P2F_I2C0_INTR {0} \
   CONFIG.PCW_P2F_QSPI_INTR {0} \
   CONFIG.PCW_P2F_SDIO0_INTR {0} \
   CONFIG.PCW_P2F_UART1_INTR {0} \
   CONFIG.PCW_P2F_USB0_INTR {0} \
   CONFIG.PCW_PACKAGE_DDR_BOARD_DELAY0 {0.371} \
   CONFIG.PCW_PACKAGE_DDR_BOARD_DELAY1 {0.363} \
   CONFIG.PCW_PACKAGE_DDR_BOARD_DELAY2 {0.414} \
   CONFIG.PCW_PACKAGE_DDR_BOARD_DELAY3 {0.416} \
   CONFIG.PCW_PACKAGE_DDR_DQS_TO_CLK_DELAY_0 {-0.090} \
   CONFIG.PCW_PACKAGE_DDR_DQS_TO_CLK_DELAY_1 {-0.054} \
   CONFIG.PCW_PACKAGE_DDR_DQS_TO_CLK_DELAY_2 {0.017} \
   CONFIG.PCW_PACKAGE_DDR_DQS_TO_CLK_DELAY_3 {-0.007} \
   CONFIG.PCW_PACKAGE_NAME {clg400} \
   CONFIG.PCW_PCAP_PERIPHERAL_CLKSRC {IO PLL} \
   CONFIG.PCW_PCAP_PERIPHERAL_DIVISOR0 {5} \
   CONFIG.PCW_PCAP_PERIPHERAL_FREQMHZ {200} \
   CONFIG.PCW_PERIPHERAL_BOARD_PRESET {part0} \
   CONFIG.PCW_PJTAG_PERIPHERAL_ENABLE {0} \
   CONFIG.PCW_PLL_BYPASSMODE_ENABLE {0} \
   CONFIG.PCW_PRESET_BANK0_VOLTAGE {LVCMOS 3.3V} \
   CONFIG.PCW_PRESET_BANK1_VOLTAGE {LVCMOS 1.8V} \
   CONFIG.PCW_PS7_SI_REV {PRODUCTION} \
   CONFIG.PCW_QSPI_GRP_FBCLK_ENABLE {1} \
   CONFIG.PCW_QSPI_GRP_FBCLK_IO {MIO 8} \
   CONFIG.PCW_QSPI_GRP_IO1_ENABLE {0} \
   CONFIG.PCW_QSPI_GRP_SINGLE_SS_ENABLE {1} \
   CONFIG.PCW_QSPI_GRP_SINGLE_SS_IO {MIO 1 .. 6} \
   CONFIG.PCW_QSPI_GRP_SS1_ENABLE {0} \
   CONFIG.PCW_QSPI_INTERNAL_HIGHADDRESS {0xFCFFFFFF} \
   CONFIG.PCW_QSPI_PERIPHERAL_CLKSRC {IO PLL} \
   CONFIG.PCW_QSPI_PERIPHERAL_DIVISOR0 {5} \
   CONFIG.PCW_QSPI_PERIPHERAL_ENABLE {1} \
   CONFIG.PCW_QSPI_PERIPHERAL_FREQMHZ {200} \
   CONFIG.PCW_QSPI_QSPI_IO {MIO 1 .. 6} \
   CONFIG.PCW_SD0_GRP_CD_ENABLE {1} \
   CONFIG.PCW_SD0_GRP_CD_IO {MIO 46} \
   CONFIG.PCW_SD0_GRP_POW_ENABLE {0} \
   CONFIG.PCW_SD0_GRP_WP_ENABLE {1} \
   CONFIG.PCW_SD0_GRP_WP_IO {MIO 50} \
   CONFIG.PCW_SD0_PERIPHERAL_ENABLE {1} \
   CONFIG.PCW_SD0_SD0_IO {MIO 40 .. 45} \
   CONFIG.PCW_SD1_GRP_CD_ENABLE {0} \
   CONFIG.PCW_SD1_GRP_POW_ENABLE {0} \
   CONFIG.PCW_SD1_GRP_WP_ENABLE {0} \
   CONFIG.PCW_SD1_PERIPHERAL_ENABLE {0} \
   CONFIG.PCW_SDIO0_BASEADDR {0xE0100000} \
   CONFIG.PCW_SDIO0_HIGHADDR {0xE0100FFF} \
   CONFIG.PCW_SDIO_PERIPHERAL_CLKSRC {IO PLL} \
   CONFIG.PCW_SDIO_PERIPHERAL_DIVISOR0 {40} \
   CONFIG.PCW_SDIO_PERIPHERAL_FREQMHZ {25} \
   CONFIG.PCW_SDIO_PERIPHERAL_VALID {1} \
   CONFIG.PCW_SINGLE_QSPI_DATA_MODE {x4} \
   CONFIG.PCW_SMC_CYCLE_T0 {NA} \
   CONFIG.PCW_SMC_CYCLE_T1 {NA} \
   CONFIG.PCW_SMC_CYCLE_T2 {NA} \
   CONFIG.PCW_SMC_CYCLE_T3 {NA} \
   CONFIG.PCW_SMC_CYCLE_T4 {NA} \
   CONFIG.PCW_SMC_CYCLE_T5 {NA} \
   CONFIG.PCW_SMC_CYCLE_T6 {NA} \
   CONFIG.PCW_SMC_PERIPHERAL_CLKSRC {IO PLL} \
   CONFIG.PCW_SMC_PERIPHERAL_DIVISOR0 {1} \
   CONFIG.PCW_SMC_PERIPHERAL_VALID {0} \
   CONFIG.PCW_SPI0_GRP_SS0_ENABLE {0} \
   CONFIG.PCW_SPI0_GRP_SS1_ENABLE {0} \
   CONFIG.PCW_SPI0_GRP_SS2_ENABLE {0} \
   CONFIG.PCW_SPI0_PERIPHERAL_ENABLE {0} \
   CONFIG.PCW_SPI1_GRP_SS0_ENABLE {0} \
   CONFIG.PCW_SPI1_GRP_SS1_ENABLE {0} \
   CONFIG.PCW_SPI1_GRP_SS2_ENABLE {0} \
   CONFIG.PCW_SPI1_PERIPHERAL_ENABLE {0} \
   CONFIG.PCW_SPI_PERIPHERAL_CLKSRC {IO PLL} \
   CONFIG.PCW_SPI_PERIPHERAL_DIVISOR0 {1} \
   CONFIG.PCW_SPI_PERIPHERAL_VALID {0} \
   CONFIG.PCW_S_AXI_HP0_DATA_WIDTH {64} \
   CONFIG.PCW_S_AXI_HP0_ID_WIDTH {6} \
   CONFIG.PCW_S_AXI_HP1_DATA_WIDTH {64} \
   CONFIG.PCW_S_AXI_HP1_ID_WIDTH {6} \
   CONFIG.PCW_S_AXI_HP2_DATA_WIDTH {64} \
   CONFIG.PCW_S_AXI_HP3_DATA_WIDTH {64} \
   CONFIG.PCW_TPIU_PERIPHERAL_CLKSRC {External} \
   CONFIG.PCW_TPIU_PERIPHERAL_DIVISOR0 {1} \
   CONFIG.PCW_TPIU_PERIPHERAL_FREQMHZ {200} \
   CONFIG.PCW_TRACE_GRP_16BIT_ENABLE {0} \
   CONFIG.PCW_TRACE_GRP_2BIT_ENABLE {0} \
   CONFIG.PCW_TRACE_GRP_32BIT_ENABLE {0} \
   CONFIG.PCW_TRACE_GRP_4BIT_ENABLE {0} \
   CONFIG.PCW_TRACE_GRP_8BIT_ENABLE {0} \
   CONFIG.PCW_TRACE_INTERNAL_WIDTH {2} \
   CONFIG.PCW_TRACE_PERIPHERAL_ENABLE {0} \
   CONFIG.PCW_TTC0_BASEADDR {0xE0104000} \
   CONFIG.PCW_TTC0_CLK0_PERIPHERAL_CLKSRC {CPU_1X} \
   CONFIG.PCW_TTC0_CLK0_PERIPHERAL_DIVISOR0 {1} \
   CONFIG.PCW_TTC0_CLK0_PERIPHERAL_FREQMHZ {111.111115} \
   CONFIG.PCW_TTC0_CLK1_PERIPHERAL_CLKSRC {CPU_1X} \
   CONFIG.PCW_TTC0_CLK1_PERIPHERAL_DIVISOR0 {1} \
   CONFIG.PCW_TTC0_CLK1_PERIPHERAL_FREQMHZ {111.111115} \
   CONFIG.PCW_TTC0_CLK2_PERIPHERAL_CLKSRC {CPU_1X} \
   CONFIG.PCW_TTC0_CLK2_PERIPHERAL_DIVISOR0 {1} \
   CONFIG.PCW_TTC0_CLK2_PERIPHERAL_FREQMHZ {111.111115} \
   CONFIG.PCW_TTC0_HIGHADDR {0xE0104fff} \
   CONFIG.PCW_TTC0_PERIPHERAL_ENABLE {1} \
   CONFIG.PCW_TTC0_TTC0_IO {EMIO} \
   CONFIG.PCW_TTC1_CLK0_PERIPHERAL_CLKSRC {CPU_1X} \
   CONFIG.PCW_TTC1_CLK0_PERIPHERAL_DIVISOR0 {1} \
   CONFIG.PCW_TTC1_CLK0_PERIPHERAL_FREQMHZ {133.333333} \
   CONFIG.PCW_TTC1_CLK1_PERIPHERAL_CLKSRC {CPU_1X} \
   CONFIG.PCW_TTC1_CLK1_PERIPHERAL_DIVISOR0 {1} \
   CONFIG.PCW_TTC1_CLK1_PERIPHERAL_FREQMHZ {133.333333} \
   CONFIG.PCW_TTC1_CLK2_PERIPHERAL_CLKSRC {CPU_1X} \
   CONFIG.PCW_TTC1_CLK2_PERIPHERAL_DIVISOR0 {1} \
   CONFIG.PCW_TTC1_CLK2_PERIPHERAL_FREQMHZ {133.333333} \
   CONFIG.PCW_TTC1_PERIPHERAL_ENABLE {0} \
   CONFIG.PCW_TTC_PERIPHERAL_FREQMHZ {50} \
   CONFIG.PCW_UART0_GRP_FULL_ENABLE {0} \
   CONFIG.PCW_UART0_PERIPHERAL_ENABLE {0} \
   CONFIG.PCW_UART1_BASEADDR {0xE0001000} \
   CONFIG.PCW_UART1_BAUD_RATE {115200} \
   CONFIG.PCW_UART1_GRP_FULL_ENABLE {0} \
   CONFIG.PCW_UART1_HIGHADDR {0xE0001FFF} \
   CONFIG.PCW_UART1_PERIPHERAL_ENABLE {1} \
   CONFIG.PCW_UART1_UART1_IO {MIO 48 .. 49} \
   CONFIG.PCW_UART_PERIPHERAL_CLKSRC {IO PLL} \
   CONFIG.PCW_UART_PERIPHERAL_DIVISOR0 {20} \
   CONFIG.PCW_UART_PERIPHERAL_FREQMHZ {50} \
   CONFIG.PCW_UART_PERIPHERAL_VALID {1} \
   CONFIG.PCW_UIPARAM_ACT_DDR_FREQ_MHZ {533.333374} \
   CONFIG.PCW_UIPARAM_DDR_ADV_ENABLE {0} \
   CONFIG.PCW_UIPARAM_DDR_AL {0} \
   CONFIG.PCW_UIPARAM_DDR_BANK_ADDR_COUNT {3} \
   CONFIG.PCW_UIPARAM_DDR_BL {8} \
   CONFIG.PCW_UIPARAM_DDR_BOARD_DELAY0 {0.294} \
   CONFIG.PCW_UIPARAM_DDR_BOARD_DELAY1 {0.298} \
   CONFIG.PCW_UIPARAM_DDR_BOARD_DELAY2 {0.338} \
   CONFIG.PCW_UIPARAM_DDR_BOARD_DELAY3 {0.334} \
   CONFIG.PCW_UIPARAM_DDR_BUS_WIDTH {32 Bit} \
   CONFIG.PCW_UIPARAM_DDR_CL {7} \
   CONFIG.PCW_UIPARAM_DDR_CLOCK_0_LENGTH_MM {39.7} \
   CONFIG.PCW_UIPARAM_DDR_CLOCK_0_PACKAGE_LENGTH {80.4535} \
   CONFIG.PCW_UIPARAM_DDR_CLOCK_0_PROPOGATION_DELAY {160} \
   CONFIG.PCW_UIPARAM_DDR_CLOCK_1_LENGTH_MM {39.7} \
   CONFIG.PCW_UIPARAM_DDR_CLOCK_1_PACKAGE_LENGTH {80.4535} \
   CONFIG.PCW_UIPARAM_DDR_CLOCK_1_PROPOGATION_DELAY {160} \
   CONFIG.PCW_UIPARAM_DDR_CLOCK_2_LENGTH_MM {54.14} \
   CONFIG.PCW_UIPARAM_DDR_CLOCK_2_PACKAGE_LENGTH {80.4535} \
   CONFIG.PCW_UIPARAM_DDR_CLOCK_2_PROPOGATION_DELAY {160} \
   CONFIG.PCW_UIPARAM_DDR_CLOCK_3_LENGTH_MM {54.14} \
   CONFIG.PCW_UIPARAM_DDR_CLOCK_3_PACKAGE_LENGTH {80.4535} \
   CONFIG.PCW_UIPARAM_DDR_CLOCK_3_PROPOGATION_DELAY {160} \
   CONFIG.PCW_UIPARAM_DDR_CLOCK_STOP_EN {0} \
   CONFIG.PCW_UIPARAM_DDR_COL_ADDR_COUNT {10} \
   CONFIG.PCW_UIPARAM_DDR_CWL {6} \
   CONFIG.PCW_UIPARAM_DDR_DEVICE_CAPACITY {4096 MBits} \
   CONFIG.PCW_UIPARAM_DDR_DQS_0_LENGTH_MM {50.05} \
   CONFIG.PCW_UIPARAM_DDR_DQS_0_PACKAGE_LENGTH {105.056} \
   CONFIG.PCW_UIPARAM_DDR_DQS_0_PROPOGATION_DELAY {160} \
   CONFIG.PCW_UIPARAM_DDR_DQS_1_LENGTH_MM {50.43} \
   CONFIG.PCW_UIPARAM_DDR_DQS_1_PACKAGE_LENGTH {66.904} \
   CONFIG.PCW_UIPARAM_DDR_DQS_1_PROPOGATION_DELAY {160} \
   CONFIG.PCW_UIPARAM_DDR_DQS_2_LENGTH_MM {50.10} \
   CONFIG.PCW_UIPARAM_DDR_DQS_2_PACKAGE_LENGTH {89.1715} \
   CONFIG.PCW_UIPARAM_DDR_DQS_2_PROPOGATION_DELAY {160} \
   CONFIG.PCW_UIPARAM_DDR_DQS_3_LENGTH_MM {50.01} \
   CONFIG.PCW_UIPARAM_DDR_DQS_3_PACKAGE_LENGTH {113.63} \
   CONFIG.PCW_UIPARAM_DDR_DQS_3_PROPOGATION_DELAY {160} \
   CONFIG.PCW_UIPARAM_DDR_DQS_TO_CLK_DELAY_0 {-0.073} \
   CONFIG.PCW_UIPARAM_DDR_DQS_TO_CLK_DELAY_1 {-0.072} \
   CONFIG.PCW_UIPARAM_DDR_DQS_TO_CLK_DELAY_2 {0.024} \
   CONFIG.PCW_UIPARAM_DDR_DQS_TO_CLK_DELAY_3 {0.023} \
   CONFIG.PCW_UIPARAM_DDR_DQ_0_LENGTH_MM {49.59} \
   CONFIG.PCW_UIPARAM_DDR_DQ_0_PACKAGE_LENGTH {98.503} \
   CONFIG.PCW_UIPARAM_DDR_DQ_0_PROPOGATION_DELAY {160} \
   CONFIG.PCW_UIPARAM_DDR_DQ_1_LENGTH_MM {51.74} \
   CONFIG.PCW_UIPARAM_DDR_DQ_1_PACKAGE_LENGTH {68.5855} \
   CONFIG.PCW_UIPARAM_DDR_DQ_1_PROPOGATION_DELAY {160} \
   CONFIG.PCW_UIPARAM_DDR_DQ_2_LENGTH_MM {50.32} \
   CONFIG.PCW_UIPARAM_DDR_DQ_2_PACKAGE_LENGTH {90.295} \
   CONFIG.PCW_UIPARAM_DDR_DQ_2_PROPOGATION_DELAY {160} \
   CONFIG.PCW_UIPARAM_DDR_DQ_3_LENGTH_MM {48.55} \
   CONFIG.PCW_UIPARAM_DDR_DQ_3_PACKAGE_LENGTH {103.977} \
   CONFIG.PCW_UIPARAM_DDR_DQ_3_PROPOGATION_DELAY {160} \
   CONFIG.PCW_UIPARAM_DDR_DRAM_WIDTH {16 Bits} \
   CONFIG.PCW_UIPARAM_DDR_ECC {Disabled} \
   CONFIG.PCW_UIPARAM_DDR_ENABLE {1} \
   CONFIG.PCW_UIPARAM_DDR_FREQ_MHZ {533.333333} \
   CONFIG.PCW_UIPARAM_DDR_HIGH_TEMP {Normal (0-85)} \
   CONFIG.PCW_UIPARAM_DDR_MEMORY_TYPE {DDR 3} \
   CONFIG.PCW_UIPARAM_DDR_PARTNO {MT41K256M16 RE-125} \
   CONFIG.PCW_UIPARAM_DDR_ROW_ADDR_COUNT {15} \
   CONFIG.PCW_UIPARAM_DDR_SPEED_BIN {DDR3_1066F} \
   CONFIG.PCW_UIPARAM_DDR_TRAIN_DATA_EYE {1} \
   CONFIG.PCW_UIPARAM_DDR_TRAIN_READ_GATE {1} \
   CONFIG.PCW_UIPARAM_DDR_TRAIN_WRITE_LEVEL {1} \
   CONFIG.PCW_UIPARAM_DDR_T_FAW {40.0} \
   CONFIG.PCW_UIPARAM_DDR_T_RAS_MIN {35.0} \
   CONFIG.PCW_UIPARAM_DDR_T_RC {48.75} \
   CONFIG.PCW_UIPARAM_DDR_T_RCD {7} \
   CONFIG.PCW_UIPARAM_DDR_T_RP {7} \
   CONFIG.PCW_UIPARAM_DDR_USE_INTERNAL_VREF {0} \
   CONFIG.PCW_UIPARAM_GENERATE_SUMMARY {NA} \
   CONFIG.PCW_USB0_BASEADDR {0xE0102000} \
   CONFIG.PCW_USB0_HIGHADDR {0xE0102fff} \
   CONFIG.PCW_USB0_PERIPHERAL_ENABLE {1} \
   CONFIG.PCW_USB0_PERIPHERAL_FREQMHZ {60} \
   CONFIG.PCW_USB0_RESET_ENABLE {1} \
   CONFIG.PCW_USB0_RESET_IO {MIO 7} \
   CONFIG.PCW_USB0_USB0_IO {MIO 28 .. 39} \
   CONFIG.PCW_USB1_PERIPHERAL_ENABLE {0} \
   CONFIG.PCW_USB1_PERIPHERAL_FREQMHZ {60} \
   CONFIG.PCW_USB1_RESET_ENABLE {0} \
   CONFIG.PCW_USB_RESET_ENABLE {1} \
   CONFIG.PCW_USB_RESET_POLARITY {Active Low} \
   CONFIG.PCW_USB_RESET_SELECT {Share reset pin} \
   CONFIG.PCW_USE_AXI_FABRIC_IDLE {0} \
   CONFIG.PCW_USE_AXI_NONSECURE {0} \
   CONFIG.PCW_USE_CORESIGHT {0} \
   CONFIG.PCW_USE_CROSS_TRIGGER {0} \
   CONFIG.PCW_USE_CR_FABRIC {1} \
   CONFIG.PCW_USE_DDR_BYPASS {0} \
   CONFIG.PCW_USE_DEBUG {0} \
   CONFIG.PCW_USE_DMA0 {0} \
   CONFIG.PCW_USE_DMA1 {0} \
   CONFIG.PCW_USE_DMA2 {0} \
   CONFIG.PCW_USE_DMA3 {0} \
   CONFIG.PCW_USE_EXPANDED_IOP {0} \
   CONFIG.PCW_USE_FABRIC_INTERRUPT {1} \
   CONFIG.PCW_USE_HIGH_OCM {0} \
   CONFIG.PCW_USE_M_AXI_GP0 {1} \
   CONFIG.PCW_USE_M_AXI_GP1 {0} \
   CONFIG.PCW_USE_PROC_EVENT_BUS {0} \
   CONFIG.PCW_USE_PS_SLCR_REGISTERS {0} \
   CONFIG.PCW_USE_S_AXI_ACP {0} \
   CONFIG.PCW_USE_S_AXI_GP0 {0} \
   CONFIG.PCW_USE_S_AXI_GP1 {0} \
   CONFIG.PCW_USE_S_AXI_HP0 {1} \
   CONFIG.PCW_USE_S_AXI_HP1 {1} \
   CONFIG.PCW_USE_S_AXI_HP2 {1} \
   CONFIG.PCW_USE_S_AXI_HP3 {1} \
   CONFIG.PCW_USE_TRACE {0} \
   CONFIG.PCW_VALUE_SILVERSION {3} \
   CONFIG.PCW_WDT_PERIPHERAL_CLKSRC {CPU_1X} \
   CONFIG.PCW_WDT_PERIPHERAL_DIVISOR0 {1} \
   CONFIG.PCW_WDT_PERIPHERAL_ENABLE {0} \
   CONFIG.PCW_WDT_PERIPHERAL_FREQMHZ {133.333333} \
 ] $processing_system7_1

  # Create instance: ps7_1_axi_periph, and set properties
  set ps7_1_axi_periph [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_interconnect:2.1 ps7_1_axi_periph ]
  set_property -dict [ list \
   CONFIG.NUM_MI {9} \
   CONFIG.STRATEGY {1} \
 ] $ps7_1_axi_periph

  # Create instance: readRam_burst_1, and set properties
  set readRam_burst_1 [ create_bd_cell -type ip -vlnv xilinx.com:user:readRam_burst:1.0 readRam_burst_1 ]
  set_property -dict [ list \
   CONFIG.C_M00_AXI_ID_WIDTH {0} \
   CONFIG.NBITS_RAM {5} \
 ] $readRam_burst_1

  # Create instance: reg_bank_0, and set properties
  set reg_bank_0 [ create_bd_cell -type ip -vlnv xilinx.com:user:reg_bank:1.0 reg_bank_0 ]

  # Create instance: rst_ps7_0_100M, and set properties
  set rst_ps7_0_100M [ create_bd_cell -type ip -vlnv xilinx.com:ip:proc_sys_reset:5.0 rst_ps7_0_100M ]

  # Create instance: sg_dma_intr_isolation, and set properties
  set sg_dma_intr_isolation [ create_bd_cell -type ip -vlnv msc:msc:rename_net:1.0 sg_dma_intr_isolation ]
  set_property -dict [ list \
   CONFIG.INBITS {1} \
   CONFIG.OUTBITS {1} \
 ] $sg_dma_intr_isolation

  # Create instance: xlconstant_1, and set properties
  set xlconstant_1 [ create_bd_cell -type ip -vlnv xilinx.com:ip:xlconstant:1.1 xlconstant_1 ]

  # Create instance: xlconstant_2, and set properties
  set xlconstant_2 [ create_bd_cell -type ip -vlnv xilinx.com:ip:xlconstant:1.1 xlconstant_2 ]
  set_property -dict [ list \
   CONFIG.CONST_VAL {0} \
 ] $xlconstant_2

  # Create interface connections
  connect_bd_intf_net -intf_net axi_bram_ctrl_0_BRAM_PORTA [get_bd_intf_pins axi_bram_ctrl_dbg_unit/BRAM_PORTA] [get_bd_intf_pins blk_mem_gen_dbg_unit/BRAM_PORTA]
  connect_bd_intf_net -intf_net axi_dma_SG_sort_M_AXI_S2MM [get_bd_intf_pins axi_dma_SG_sort/M_AXI_S2MM] [get_bd_intf_pins axi_mem_intercon_3/S01_AXI]
  connect_bd_intf_net -intf_net axi_dma_SG_sort_M_AXI_SG [get_bd_intf_pins axi_dma_SG_sort/M_AXI_SG] [get_bd_intf_pins axi_mem_intercon_3/S00_AXI]
  connect_bd_intf_net -intf_net axi_mem_intercon_1_M00_AXI [get_bd_intf_pins axi_mem_intercon_1/M00_AXI] [get_bd_intf_pins processing_system7_1/S_AXI_HP2]
  connect_bd_intf_net -intf_net axi_mem_intercon_3_M00_AXI [get_bd_intf_pins axi_mem_intercon_3/M00_AXI] [get_bd_intf_pins processing_system7_1/S_AXI_HP3]
  connect_bd_intf_net -intf_net axi_mem_intercon_M00_AXI [get_bd_intf_pins axi_mem_intercon/M00_AXI] [get_bd_intf_pins processing_system7_1/S_AXI_HP1]
  connect_bd_intf_net -intf_net axi_smc_M00_AXI [get_bd_intf_pins axi_smc/M00_AXI] [get_bd_intf_pins processing_system7_1/S_AXI_HP0]
  connect_bd_intf_net -intf_net data2ram_dcs_m00_axi [get_bd_intf_pins axi_mem_intercon_1/S00_AXI] [get_bd_intf_pins data2ram_dcs/m00_axi]
  connect_bd_intf_net -intf_net data2ram_gs_m00_axi [get_bd_intf_pins axi_mem_intercon/S00_AXI] [get_bd_intf_pins data2ram_gs/m00_axi]
  connect_bd_intf_net -intf_net processing_system7_1_DDR [get_bd_intf_ports DDR] [get_bd_intf_pins processing_system7_1/DDR]
  connect_bd_intf_net -intf_net processing_system7_1_FIXED_IO [get_bd_intf_ports FIXED_IO] [get_bd_intf_pins processing_system7_1/FIXED_IO]
  connect_bd_intf_net -intf_net processing_system7_1_IIC_1 [get_bd_intf_ports IIC_1_0] [get_bd_intf_pins processing_system7_1/IIC_1]
  connect_bd_intf_net -intf_net processing_system7_1_M_AXI_GP0 [get_bd_intf_pins processing_system7_1/M_AXI_GP0] [get_bd_intf_pins ps7_1_axi_periph/S00_AXI]
  connect_bd_intf_net -intf_net ps7_1_axi_periph_M00_AXI [get_bd_intf_pins axi_dma_SG_sort/S_AXI_LITE] [get_bd_intf_pins ps7_1_axi_periph/M00_AXI]
  connect_bd_intf_net -intf_net ps7_1_axi_periph_M01_AXI [get_bd_intf_pins axi_gpio_led/S_AXI] [get_bd_intf_pins ps7_1_axi_periph/M01_AXI]
  connect_bd_intf_net -intf_net ps7_1_axi_periph_M02_AXI [get_bd_intf_pins gpio_shutter/S_AXI] [get_bd_intf_pins ps7_1_axi_periph/M02_AXI]
  connect_bd_intf_net -intf_net ps7_1_axi_periph_M03_AXI [get_bd_intf_pins clk_wiz_0/s_axi_lite] [get_bd_intf_pins ps7_1_axi_periph/M03_AXI]
  connect_bd_intf_net -intf_net ps7_1_axi_periph_M04_AXI [get_bd_intf_pins ps7_1_axi_periph/M04_AXI] [get_bd_intf_pins reg_bank_0/S00_AXI]
  connect_bd_intf_net -intf_net ps7_1_axi_periph_M05_AXI [get_bd_intf_pins axi_gpio_power_reset/S_AXI] [get_bd_intf_pins ps7_1_axi_periph/M05_AXI]
  connect_bd_intf_net -intf_net ps7_1_axi_periph_M06_AXI [get_bd_intf_pins axi_bram_ctrl_dbg_unit/S_AXI] [get_bd_intf_pins ps7_1_axi_periph/M06_AXI]
  connect_bd_intf_net -intf_net ps7_1_axi_periph_M07_AXI [get_bd_intf_pins axi_gpio_Sel1/S_AXI] [get_bd_intf_pins ps7_1_axi_periph/M07_AXI]
  connect_bd_intf_net -intf_net ps7_1_axi_periph_M08_AXI [get_bd_intf_pins axi_gpio_Sel2/S_AXI] [get_bd_intf_pins ps7_1_axi_periph/M08_AXI]
  connect_bd_intf_net -intf_net readRam_burst_1_M00_AXI [get_bd_intf_pins axi_smc/S00_AXI] [get_bd_intf_pins readRam_burst_1/M00_AXI]

  # Create port connections
  connect_bd_net -net TOF_cos_sl_0_DbgBram_Addr [get_bd_pins TOF_cos_sl_0/DbgBram_Addr] [get_bd_pins blk_mem_gen_dbg_unit/addrb]
  connect_bd_net -net TOF_cos_sl_0_DbgBram_Data [get_bd_pins TOF_cos_sl_0/DbgBram_Data] [get_bd_pins blk_mem_gen_dbg_unit/dinb]
  connect_bd_net -net TOF_cos_sl_0_DbgBram_Wen [get_bd_pins TOF_cos_sl_0/DbgBram_Wen] [get_bd_pins blk_mem_gen_dbg_unit/web]
  connect_bd_net -net TOF_cos_sl_0_cc_dcs_length_DO [get_bd_pins TOF_cos_sl_0/cc_dcs_length_DO] [get_bd_pins data2ram_dcs/length_DI]
  connect_bd_net -net TOF_cos_sl_0_cc_reset_regs_RO [get_bd_pins TOF_cos_sl_0/cc_reset_regs_RO] [get_bd_pins reg_bank_0/reset_cc_regs_RI]
  connect_bd_net -net TOF_cos_sl_0_cc_sort_length_DO [get_bd_pins TOF_cos_sl_0/cc_sort_length_DO] [get_bd_pins data2axistream_v1_0_3/NUMBER_OF_OUTPUT_WORDS]
  connect_bd_net -net TOF_cos_sl_0_dcs2_or_dcs3_pulse_SO [get_bd_pins TOF_cos_sl_0/dcs2_or_dcs3_pulse_SO] [get_bd_pins data2ram_dcs/pulse_out_DI]
  connect_bd_net -net TOF_cos_sl_0_dcs_data_DO [get_bd_pins TOF_cos_sl_0/dcs_data_DO] [get_bd_pins data2ram_dcs/data_DI]
  connect_bd_net -net TOF_cos_sl_0_dist_amp_sat_concat_DO [get_bd_pins TOF_cos_sl_0/dist_amp_sat_concat_DO] [get_bd_pins data2axistream_v1_0_3/input_data] [get_bd_pins ila_0/probe0]
  connect_bd_net -net TOF_cos_sl_0_dist_amp_sat_pulse_SO [get_bd_pins TOF_cos_sl_0/dist_amp_sat_pulse_SO] [get_bd_pins data2axistream_v1_0_3/pulse]
  connect_bd_net -net TOF_cos_sl_0_dist_offset_fail_pos_DO [get_bd_pins TOF_cos_sl_0/dist_offset_fail_pos_DO] [get_bd_pins reg_bank_0/dist_fail_pos_DI]
  connect_bd_net -net TOF_cos_sl_0_dist_offset_index_high_SO [get_bd_pins TOF_cos_sl_0/dist_offset_index_high_SO] [get_bd_pins reg_bank_0/dist_index_high_SI]
  connect_bd_net -net TOF_cos_sl_0_dist_offset_index_low_SO [get_bd_pins TOF_cos_sl_0/dist_offset_index_low_SO] [get_bd_pins reg_bank_0/dist_index_low_SI]
  connect_bd_net -net TOF_cos_sl_0_dist_offset_index_trunc_DO [get_bd_pins TOF_cos_sl_0/dist_offset_index_trunc_DO] [get_bd_pins reg_bank_0/dist_index_trunc_DI]
  connect_bd_net -net TOF_cos_sl_0_en_d2r_gs_SO [get_bd_pins TOF_cos_sl_0/en_d2r_gs_SO] [get_bd_pins data2ram_gs/enable_DI]
  connect_bd_net -net TOF_cos_sl_0_en_d2r_wr_dcs_SO [get_bd_pins TOF_cos_sl_0/en_d2r_wr_dcs_SO] [get_bd_pins data2ram_dcs/wr_en_SI]
  connect_bd_net -net TOF_cos_sl_0_grey_pulse_in_SO [get_bd_pins TOF_cos_sl_0/grey_pulse_in_SO] [get_bd_pins data2ram_gs/pulse_out_DI]
  connect_bd_net -net TOF_cos_sl_0_grey_pulse_out_SO [get_bd_pins TOF_cos_sl_0/grey_pulse_out_SO] [get_bd_pins data2axistream_v1_0_4/pulse] [get_bd_pins data2ram_gs/pulse_in_DI]
  connect_bd_net -net TOF_cos_sl_0_readRam_en_SO [get_bd_pins TOF_cos_sl_0/readRam_en_SO] [get_bd_pins readRam_burst_1/enable_SI]
  connect_bd_net -net TOF_cos_sl_0_readRam_index_DO [get_bd_pins TOF_cos_sl_0/readRam_index_DO] [get_bd_pins readRam_burst_1/ram_index_DI]
  connect_bd_net -net TOF_cos_sl_0_readRam_pulse_SO [get_bd_pins TOF_cos_sl_0/readRam_pulse_SO] [get_bd_pins readRam_burst_1/ram_pulse_DI]
  connect_bd_net -net TOF_cos_sl_0_reg_dcs0_or_dcs1_pulse_SO [get_bd_pins TOF_cos_sl_0/reg_dcs0_or_dcs1_pulse_SO] [get_bd_pins data2ram_dcs/pulse_in_DI]
  connect_bd_net -net TOF_cos_sl_0_tcmi_pixel_cnt_DO [get_bd_pins TOF_cos_sl_0/tcmi_pixel_cnt_DO] [get_bd_pins ila_0/probe1]
  connect_bd_net -net axi_dma_SG_sort_s2mm_introut [get_bd_pins axi_dma_SG_sort/s2mm_introut] [get_bd_pins processing_system7_1/IRQ_F2P] [get_bd_pins sg_dma_intr_isolation/data_in]
  connect_bd_net -net axi_dma_SG_sort_s_axis_s2mm_tready [get_bd_pins axi_dma_SG_sort/s_axis_s2mm_tready] [get_bd_pins axis_switch_2to1_0/m00_axis_tready]
  connect_bd_net -net axi_gpio_Sel2_gpio_io_o [get_bd_pins axi_gpio_Sel2/gpio_io_o] [get_bd_pins clockMux3_0/sel2] [get_bd_pins ip_mux_1/sel2] [get_bd_pins op_demux_0/sel2]
  connect_bd_net -net axi_gpio_Sel_gpio_io_o [get_bd_pins axi_gpio_Sel1/gpio_io_o] [get_bd_pins clockMux1_0/sel1] [get_bd_pins clockMux2_0/sel1] [get_bd_pins ip_mux_1/sel1] [get_bd_pins op_demux_0/sel1]
  connect_bd_net -net axi_gpio_power_reset_gpio_io_o [get_bd_pins axi_gpio_power_reset/gpio_io_o] [get_bd_pins op_demux_0/gpio_io]
  connect_bd_net -net axi_peri_resetn [get_bd_pins TOF_cos_sl_0/reset_RBI] [get_bd_pins axi_bram_ctrl_dbg_unit/s_axi_aresetn] [get_bd_pins axi_gpio_Sel1/s_axi_aresetn] [get_bd_pins axi_gpio_Sel2/s_axi_aresetn] [get_bd_pins axi_gpio_led/s_axi_aresetn] [get_bd_pins axi_mem_intercon/M00_ARESETN] [get_bd_pins axi_mem_intercon/S00_ARESETN] [get_bd_pins axi_mem_intercon_1/M00_ARESETN] [get_bd_pins axi_mem_intercon_1/S00_ARESETN] [get_bd_pins axi_mem_intercon_3/M00_ARESETN] [get_bd_pins axi_mem_intercon_3/S00_ARESETN] [get_bd_pins axi_mem_intercon_3/S01_ARESETN] [get_bd_pins axi_smc/aresetn] [get_bd_pins clk_wiz_0/s_axi_aresetn] [get_bd_pins gpio_shutter/s_axi_aresetn] [get_bd_pins ps7_1_axi_periph/M00_ARESETN] [get_bd_pins ps7_1_axi_periph/M01_ARESETN] [get_bd_pins ps7_1_axi_periph/M02_ARESETN] [get_bd_pins ps7_1_axi_periph/M03_ARESETN] [get_bd_pins ps7_1_axi_periph/M04_ARESETN] [get_bd_pins ps7_1_axi_periph/M05_ARESETN] [get_bd_pins ps7_1_axi_periph/M06_ARESETN] [get_bd_pins ps7_1_axi_periph/M07_ARESETN] [get_bd_pins ps7_1_axi_periph/M08_ARESETN] [get_bd_pins readRam_burst_1/m00_axi_aresetn] [get_bd_pins reg_bank_0/s00_axi_aresetn] [get_bd_pins rst_ps7_0_100M/peripheral_aresetn]
  connect_bd_net -net axis_switch_2to1_0_m00_axis_tdata [get_bd_pins axi_dma_SG_sort/s_axis_s2mm_tdata] [get_bd_pins axis_switch_2to1_0/m00_axis_tdata]
  connect_bd_net -net axis_switch_2to1_0_m00_axis_tkeep [get_bd_pins axi_dma_SG_sort/s_axis_s2mm_tkeep] [get_bd_pins axis_switch_2to1_0/m00_axis_tkeep]
  connect_bd_net -net axis_switch_2to1_0_m00_axis_tlast [get_bd_pins axi_dma_SG_sort/s_axis_s2mm_tlast] [get_bd_pins axis_switch_2to1_0/m00_axis_tlast]
  connect_bd_net -net axis_switch_2to1_0_m00_axis_tvalid [get_bd_pins axi_dma_SG_sort/s_axis_s2mm_tvalid] [get_bd_pins axis_switch_2to1_0/m00_axis_tvalid]
  connect_bd_net -net axis_switch_2to1_0_s00_axis_tready [get_bd_pins axis_switch_2to1_0/s00_axis_tready] [get_bd_pins data2axistream_v1_0_3/m00_axis_tready]
  connect_bd_net -net axis_switch_2to1_0_s01_axis_tready [get_bd_pins axis_switch_2to1_0/s01_axis_tready] [get_bd_pins data2axistream_v1_0_4/m00_axis_tready]
  connect_bd_net -net blk_mem_gen_dcs_doutb [get_bd_pins blk_mem_gen_dcs/doutb] [get_bd_pins data2ram_dcs/rd_data_DI]
  connect_bd_net -net blk_mem_gen_gs_doutb [get_bd_pins blk_mem_gen_gs/doutb] [get_bd_pins data2ram_gs/rd_data_DI]
  connect_bd_net -net camera_ctrl_v1_0_0_tcmi_en [get_bd_pins TOF_cos_sl_0/en_d2r_dcs_SO] [get_bd_pins data2axistream_v1_0_3/en] [get_bd_pins data2axistream_v1_0_3/resetn] [get_bd_pins data2axistream_v1_0_4/en] [get_bd_pins data2axistream_v1_0_4/resetn] [get_bd_pins data2ram_dcs/enable_DI]
  connect_bd_net -net clockMux1_0_dclk_out1 [get_bd_pins clockMux1_0/dclk_out1] [get_bd_pins clockMux3_0/dclk_in1]
  connect_bd_net -net clockMux2_0_dclk_out2 [get_bd_pins clockMux2_0/dclk_out2] [get_bd_pins clockMux3_0/dclk_in2]
  connect_bd_net -net clockMux3_0_dclk_out [get_bd_pins TOF_cos_sl_0/dclk_in_SI] [get_bd_pins clockMux3_0/dclk_out]
  connect_bd_net -net data2axistream_v1_0_3_m00_axis_tdata [get_bd_pins axis_switch_2to1_0/s00_axis_tdata] [get_bd_pins data2axistream_v1_0_3/m00_axis_tdata]
  connect_bd_net -net data2axistream_v1_0_3_m00_axis_tkeep [get_bd_pins axis_switch_2to1_0/s00_axis_tkeep] [get_bd_pins data2axistream_v1_0_3/m00_axis_tkeep]
  connect_bd_net -net data2axistream_v1_0_3_m00_axis_tlast [get_bd_pins axis_switch_2to1_0/s00_axis_tlast] [get_bd_pins data2axistream_v1_0_3/m00_axis_tlast]
  connect_bd_net -net data2axistream_v1_0_3_m00_axis_tstrb [get_bd_pins axis_switch_2to1_0/s00_axis_tstrb] [get_bd_pins data2axistream_v1_0_3/m00_axis_tstrb]
  connect_bd_net -net data2axistream_v1_0_3_m00_axis_tvalid [get_bd_pins axis_switch_2to1_0/s00_axis_tvalid] [get_bd_pins data2axistream_v1_0_3/m00_axis_tvalid]
  connect_bd_net -net data2axistream_v1_0_4_m00_axis_tdata [get_bd_pins axis_switch_2to1_0/s01_axis_tdata] [get_bd_pins data2axistream_v1_0_4/m00_axis_tdata]
  connect_bd_net -net data2axistream_v1_0_4_m00_axis_tkeep [get_bd_pins axis_switch_2to1_0/s01_axis_tkeep] [get_bd_pins data2axistream_v1_0_4/m00_axis_tkeep]
  connect_bd_net -net data2axistream_v1_0_4_m00_axis_tlast [get_bd_pins axis_switch_2to1_0/s01_axis_tlast] [get_bd_pins data2axistream_v1_0_4/m00_axis_tlast]
  connect_bd_net -net data2axistream_v1_0_4_m00_axis_tstrb [get_bd_pins axis_switch_2to1_0/s01_axis_tstrb] [get_bd_pins data2axistream_v1_0_4/m00_axis_tstrb]
  connect_bd_net -net data2axistream_v1_0_4_m00_axis_tvalid [get_bd_pins axis_switch_2to1_0/s01_axis_tvalid] [get_bd_pins data2axistream_v1_0_4/m00_axis_tvalid]
  connect_bd_net -net data2ram_dcs_data_DO [get_bd_pins TOF_cos_sl_0/ram_dcs_data_DI] [get_bd_pins data2ram_dcs/data_DO]
  connect_bd_net -net data2ram_dcs_dma_busy_SO [get_bd_pins data2ram_dcs/dma_busy_SO] [get_bd_pins reg_bank_0/dcs_dma_busy_DI]
  connect_bd_net -net data2ram_dcs_dma_done_SO [get_bd_pins data2ram_dcs/dma_done_SO] [get_bd_pins reg_bank_0/dcs_dma_done_DI]
  connect_bd_net -net data2ram_dcs_dma_rdy_SO [get_bd_pins data2ram_dcs/dma_rdy_SO] [get_bd_pins reg_bank_0/dcs_dma_rdy_DI]
  connect_bd_net -net data2ram_dcs_rd_addr_DO [get_bd_pins blk_mem_gen_dcs/addrb] [get_bd_pins data2ram_dcs/rd_addr_DO]
  connect_bd_net -net data2ram_dcs_rd_en_DO [get_bd_pins blk_mem_gen_dcs/enb] [get_bd_pins data2ram_dcs/rd_en_DO]
  connect_bd_net -net data2ram_dcs_wr_addr_DO [get_bd_pins blk_mem_gen_dcs/addra] [get_bd_pins data2ram_dcs/wr_addr_DO]
  connect_bd_net -net data2ram_dcs_wr_data_DO [get_bd_pins blk_mem_gen_dcs/dina] [get_bd_pins data2ram_dcs/wr_data_DO]
  connect_bd_net -net data2ram_dcs_wr_en_DO [get_bd_pins blk_mem_gen_dcs/ena] [get_bd_pins blk_mem_gen_dcs/wea] [get_bd_pins data2ram_dcs/wr_en_DO]
  connect_bd_net -net data2ram_dcs_wr_eof_done_SO [get_bd_pins data2ram_dcs/wr_eof_done_SO] [get_bd_pins reg_bank_0/dcs_wr_eof_done_SI]
  connect_bd_net -net data2ram_gs_data_DO [get_bd_pins TOF_cos_sl_0/gs_data_DI] [get_bd_pins data2ram_gs/data_DO]
  connect_bd_net -net data2ram_gs_dma_busy_SO [get_bd_pins data2ram_gs/dma_busy_SO] [get_bd_pins reg_bank_0/gs_dma_busy_DI]
  connect_bd_net -net data2ram_gs_dma_done_SO [get_bd_pins data2ram_gs/dma_done_SO] [get_bd_pins reg_bank_0/gs_dma_done_DI]
  connect_bd_net -net data2ram_gs_dma_rdy_SO [get_bd_pins data2ram_gs/dma_rdy_SO] [get_bd_pins reg_bank_0/gs_dma_rdy_DI]
  connect_bd_net -net data2ram_gs_rd_addr_DO [get_bd_pins blk_mem_gen_gs/addrb] [get_bd_pins data2ram_gs/rd_addr_DO]
  connect_bd_net -net data2ram_gs_rd_en_DO [get_bd_pins blk_mem_gen_gs/enb] [get_bd_pins data2ram_gs/rd_en_DO]
  connect_bd_net -net data2ram_gs_wr_addr_DO [get_bd_pins blk_mem_gen_gs/addra] [get_bd_pins data2ram_gs/wr_addr_DO]
  connect_bd_net -net data2ram_gs_wr_data_DO [get_bd_pins blk_mem_gen_gs/dina] [get_bd_pins data2ram_gs/wr_data_DO]
  connect_bd_net -net data2ram_gs_wr_en_DO [get_bd_pins blk_mem_gen_gs/ena] [get_bd_pins blk_mem_gen_gs/wea] [get_bd_pins data2ram_gs/wr_en_DO]
  connect_bd_net -net data2ram_gs_wr_eof_done_SO [get_bd_pins data2ram_gs/wr_eof_done_SO] [get_bd_pins reg_bank_0/gs_wr_eof_done_SI]
  connect_bd_net -net data_in1_1 [get_bd_ports data_in1] [get_bd_pins ip_mux_1/data_in1]
  connect_bd_net -net data_in2_1 [get_bd_ports data_in2] [get_bd_pins ip_mux_1/data_in2]
  connect_bd_net -net data_in3_1 [get_bd_ports data_in3] [get_bd_pins ip_mux_1/data_in3]
  connect_bd_net -net data_in_1 [get_bd_ports data_in] [get_bd_pins ip_mux_1/data_in]
  connect_bd_net -net dclk_in1_1 [get_bd_ports dclk_in1] [get_bd_pins clockMux1_0/dclk_in1]
  connect_bd_net -net dclk_in2_1 [get_bd_ports dclk_in2] [get_bd_pins clockMux2_0/dclk_in2]
  connect_bd_net -net dclk_in3_1 [get_bd_ports dclk_in3] [get_bd_pins clockMux2_0/dclk_in3]
  connect_bd_net -net dclk_in_1 [get_bd_ports dclk_in] [get_bd_pins clockMux1_0/dclk_in]
  connect_bd_net -net gs_subtract_0_gs_DO [get_bd_pins TOF_cos_sl_0/gs_data_DO] [get_bd_pins data2axistream_v1_0_4/input_data] [get_bd_pins data2ram_gs/data_DI]
  connect_bd_net -net hsync_in1_1 [get_bd_ports hsync_in1] [get_bd_pins ip_mux_1/hsync_in1]
  connect_bd_net -net hsync_in2_1 [get_bd_ports hsync_in2] [get_bd_pins ip_mux_1/hsync_in2]
  connect_bd_net -net hsync_in3_1 [get_bd_ports hsync_in3] [get_bd_pins ip_mux_1/hsync_in3]
  connect_bd_net -net hsync_in_1 [get_bd_ports hsync_in] [get_bd_pins ip_mux_1/hsync_in]
  connect_bd_net -net ip_mux_1_data_out [get_bd_pins TOF_cos_sl_0/data_in_DI] [get_bd_pins ip_mux_1/data_out]
  connect_bd_net -net ip_mux_1_hsync_out [get_bd_pins TOF_cos_sl_0/hsync_in_SI] [get_bd_pins ip_mux_1/hsync_out]
  connect_bd_net -net ip_mux_1_vsync_out [get_bd_pins TOF_cos_sl_0/vsync_in_SI] [get_bd_pins ip_mux_1/vsync_out]
  connect_bd_net -net ip_mux_1_xsync_sat_out [get_bd_pins TOF_cos_sl_0/xsync_sat_in_SI] [get_bd_pins ip_mux_1/xsync_sat_out]
  connect_bd_net -net op_demux_0_gpio_io_o_0 [get_bd_ports gpio_io_o_0] [get_bd_pins op_demux_0/gpio_io_o_0]
  connect_bd_net -net op_demux_0_gpio_io_o_1 [get_bd_ports gpio_io_o_1] [get_bd_pins op_demux_0/gpio_io_o_1]
  connect_bd_net -net op_demux_0_gpio_io_o_2 [get_bd_ports gpio_io_o_2] [get_bd_pins op_demux_0/gpio_io_o_2]
  connect_bd_net -net op_demux_0_gpio_io_o_3 [get_bd_ports gpio_io_o_3] [get_bd_pins op_demux_0/gpio_io_o_3]
  connect_bd_net -net processing_system7_0_FCLK_CLK0 [get_bd_ports FCLK_CLK0] [get_bd_pins TOF_cos_sl_0/clk_CI] [get_bd_pins axi_bram_ctrl_dbg_unit/s_axi_aclk] [get_bd_pins axi_dma_SG_sort/m_axi_s2mm_aclk] [get_bd_pins axi_dma_SG_sort/m_axi_sg_aclk] [get_bd_pins axi_dma_SG_sort/s_axi_lite_aclk] [get_bd_pins axi_gpio_Sel1/s_axi_aclk] [get_bd_pins axi_gpio_Sel2/s_axi_aclk] [get_bd_pins axi_gpio_led/s_axi_aclk] [get_bd_pins axi_gpio_power_reset/s_axi_aclk] [get_bd_pins axi_mem_intercon/ACLK] [get_bd_pins axi_mem_intercon/M00_ACLK] [get_bd_pins axi_mem_intercon/S00_ACLK] [get_bd_pins axi_mem_intercon_1/ACLK] [get_bd_pins axi_mem_intercon_1/M00_ACLK] [get_bd_pins axi_mem_intercon_1/S00_ACLK] [get_bd_pins axi_mem_intercon_3/ACLK] [get_bd_pins axi_mem_intercon_3/M00_ACLK] [get_bd_pins axi_mem_intercon_3/S00_ACLK] [get_bd_pins axi_mem_intercon_3/S01_ACLK] [get_bd_pins axi_smc/aclk] [get_bd_pins blk_mem_gen_dbg_unit/clkb] [get_bd_pins blk_mem_gen_dcs/clka] [get_bd_pins blk_mem_gen_dcs/clkb] [get_bd_pins blk_mem_gen_gs/clka] [get_bd_pins blk_mem_gen_gs/clkb] [get_bd_pins clk_wiz_0/clk_in1] [get_bd_pins clk_wiz_0/s_axi_aclk] [get_bd_pins data2axistream_v1_0_3/clk] [get_bd_pins data2axistream_v1_0_3/m00_axis_aclk] [get_bd_pins data2axistream_v1_0_4/clk] [get_bd_pins data2axistream_v1_0_4/m00_axis_aclk] [get_bd_pins data2ram_dcs/clk_CI] [get_bd_pins data2ram_dcs/m00_axi_aclk] [get_bd_pins data2ram_gs/clk_CI] [get_bd_pins data2ram_gs/m00_axi_aclk] [get_bd_pins gpio_shutter/s_axi_aclk] [get_bd_pins ila_0/clk] [get_bd_pins processing_system7_1/FCLK_CLK0] [get_bd_pins processing_system7_1/M_AXI_GP0_ACLK] [get_bd_pins processing_system7_1/S_AXI_HP0_ACLK] [get_bd_pins processing_system7_1/S_AXI_HP1_ACLK] [get_bd_pins processing_system7_1/S_AXI_HP2_ACLK] [get_bd_pins processing_system7_1/S_AXI_HP3_ACLK] [get_bd_pins ps7_1_axi_periph/ACLK] [get_bd_pins ps7_1_axi_periph/M00_ACLK] [get_bd_pins ps7_1_axi_periph/M01_ACLK] [get_bd_pins ps7_1_axi_periph/M02_ACLK] [get_bd_pins ps7_1_axi_periph/M03_ACLK] [get_bd_pins ps7_1_axi_periph/M04_ACLK] [get_bd_pins ps7_1_axi_periph/M05_ACLK] [get_bd_pins ps7_1_axi_periph/M06_ACLK] [get_bd_pins ps7_1_axi_periph/M07_ACLK] [get_bd_pins ps7_1_axi_periph/M08_ACLK] [get_bd_pins ps7_1_axi_periph/S00_ACLK] [get_bd_pins readRam_burst_1/clk_CI] [get_bd_pins readRam_burst_1/m00_axi_aclk] [get_bd_pins reg_bank_0/s00_axi_aclk] [get_bd_pins rst_ps7_0_100M/slowest_sync_clk]
  connect_bd_net -net processing_system7_1_FCLK_RESET0_N [get_bd_ports FCLK_RESET0_N] [get_bd_pins processing_system7_1/FCLK_RESET0_N] [get_bd_pins rst_ps7_0_100M/ext_reset_in]
  connect_bd_net -net readRam_burst_1_ram_data_DO [get_bd_pins TOF_cos_sl_0/readRam_data_DI] [get_bd_pins readRam_burst_1/ram_data_DO]
  connect_bd_net -net readRam_burst_1_read_pulse_out_DO [get_bd_pins TOF_cos_sl_0/readRam_pulse_out_SI] [get_bd_pins readRam_burst_1/read_pulse_out_DO]
  connect_bd_net -net reg_bank_0_adc_inter_en_SO [get_bd_pins TOF_cos_sl_0/rbk_img_adc_inter_en_SI] [get_bd_pins reg_bank_0/adc_inter_en_SO]
  connect_bd_net -net reg_bank_0_adc_ovrflow_en_SO [get_bd_pins TOF_cos_sl_0/rbk_adc_overflow_SI] [get_bd_pins reg_bank_0/adc_ovrflow_en_SO]
  connect_bd_net -net reg_bank_0_adc_udrflow_en_SO [get_bd_pins TOF_cos_sl_0/rbk_adc_underflow_SI] [get_bd_pins reg_bank_0/adc_udrflow_en_SO]
  connect_bd_net -net reg_bank_0_alu_amp_corr_DO [get_bd_pins TOF_cos_sl_0/rbk_alu_amp_corr_DI] [get_bd_pins reg_bank_0/alu_amp_corr_DO]
  connect_bd_net -net reg_bank_0_alu_dist_corr_DO [get_bd_pins TOF_cos_sl_0/rbk_alu_dist_corr_DI] [get_bd_pins reg_bank_0/alu_dist_corr_DO]
  connect_bd_net -net reg_bank_0_alu_min_index_DO [get_bd_pins TOF_cos_sl_0/rbk_alu_minIndex_DI] [get_bd_pins reg_bank_0/alu_min_index_DO]
  connect_bd_net -net reg_bank_0_ambient_comp_DO [get_bd_pins TOF_cos_sl_0/rbk_ambient_comp_DI] [get_bd_pins reg_bank_0/ambient_comp_DO]
  connect_bd_net -net reg_bank_0_ambient_en_SO [get_bd_pins TOF_cos_sl_0/rbk_ambient_en_SI] [get_bd_pins reg_bank_0/ambient_en_SO]
  connect_bd_net -net reg_bank_0_cc_data_length_DO [get_bd_pins TOF_cos_sl_0/rbk_cc_data_length_SI] [get_bd_pins reg_bank_0/cc_data_length_DO]
  connect_bd_net -net reg_bank_0_cc_en_SO [get_bd_pins TOF_cos_sl_0/rbk_cc_en_SI] [get_bd_pins reg_bank_0/cc_en_SO]
  connect_bd_net -net reg_bank_0_cc_init_bad_pix_SO [get_bd_pins TOF_cos_sl_0/rbk_init_table_SI] [get_bd_pins reg_bank_0/cc_init_bad_pix_SO]
  connect_bd_net -net reg_bank_0_cc_line_length_DO [get_bd_pins TOF_cos_sl_0/rbk_line_length_DI] [get_bd_pins reg_bank_0/cc_line_length_DO]
  connect_bd_net -net reg_bank_0_cc_mode_SO [get_bd_pins TOF_cos_sl_0/rbk_cc_mode_SI] [get_bd_pins reg_bank_0/cc_mode_SO]
  connect_bd_net -net reg_bank_0_cc_rst_RO [get_bd_pins TOF_cos_sl_0/rbk_cc_rst_SI] [get_bd_pins reg_bank_0/cc_rst_RO]
  connect_bd_net -net reg_bank_0_cc_update_reg_values_SO [get_bd_pins TOF_cos_sl_0/rbk_cc_update_reg_values_SI] [get_bd_pins reg_bank_0/cc_update_reg_values_SO]
  connect_bd_net -net reg_bank_0_comp_en_SO [get_bd_pins TOF_cos_sl_0/rbk_add_const_en_SI] [get_bd_pins reg_bank_0/comp_en_SO]
  connect_bd_net -net reg_bank_0_const_val_DO [get_bd_pins TOF_cos_sl_0/rbk_add_const_val_DI] [get_bd_pins reg_bank_0/const_val_DO]
  connect_bd_net -net reg_bank_0_dbg_en_SI [get_bd_pins TOF_cos_sl_0/rbk_dbg_en_SI] [get_bd_pins reg_bank_0/dbg_en_SO]
  connect_bd_net -net reg_bank_0_dbg_pxl_count_DI [get_bd_pins TOF_cos_sl_0/rbg_dbg_pxl_count_DI] [get_bd_pins reg_bank_0/dbg_pxl_count_DO]
  connect_bd_net -net reg_bank_0_dbg_pxl_index_DI [get_bd_pins TOF_cos_sl_0/rbk_dbg_pxl_index_DI] [get_bd_pins reg_bank_0/dbg_pxl_index_DO]
  connect_bd_net -net reg_bank_0_dcs_dma_addr_DO [get_bd_pins data2ram_dcs/addr_DI] [get_bd_pins reg_bank_0/dcs_dma_addr_DO]
  connect_bd_net -net reg_bank_0_dist_corr_en_SO [get_bd_pins TOF_cos_sl_0/rbk_dist_corr_en_SI] [get_bd_pins reg_bank_0/dist_corr_en_SO]
  connect_bd_net -net reg_bank_0_dist_dll_DO [get_bd_pins TOF_cos_sl_0/rbk_dist_corr_dll_DI] [get_bd_pins reg_bank_0/dist_dll_DO]
  connect_bd_net -net reg_bank_0_gs_comp_en_SO [get_bd_pins TOF_cos_sl_0/rbk_gs_comp_en_SI] [get_bd_pins reg_bank_0/gs_comp_en_SO]
  connect_bd_net -net reg_bank_0_gs_dma_addr_DO [get_bd_pins data2ram_gs/addr_DI] [get_bd_pins reg_bank_0/gs_dma_addr_DO]
  connect_bd_net -net reg_bank_0_gs_subtract_en_SO [get_bd_pins TOF_cos_sl_0/rbk_gs_subtract_SI] [get_bd_pins reg_bank_0/gs_subtract_en_SO]
  connect_bd_net -net reg_bank_0_image_bin_en_SO [get_bd_pins TOF_cos_sl_0/rbk_image_bin_en_SI] [get_bd_pins reg_bank_0/image_bin_en_SO]
  connect_bd_net -net reg_bank_0_image_bin_rem_sat_SO [get_bd_pins TOF_cos_sl_0/rbk_im_rem_sat_SI] [get_bd_pins reg_bank_0/image_bin_rem_sat_SO]
  connect_bd_net -net reg_bank_0_interf_thr_DO [get_bd_pins TOF_cos_sl_0/rbk_interf_thr_DI] [get_bd_pins reg_bank_0/interf_thr_DO]
  connect_bd_net -net reg_bank_0_max_out_val_DO [get_bd_pins TOF_cos_sl_0/rbk_const_max_val_DI] [get_bd_pins reg_bank_0/max_out_val_DO]
  connect_bd_net -net reg_bank_0_mult_fact_DO [get_bd_pins TOF_cos_sl_0/rbk_mult_fact_DI] [get_bd_pins reg_bank_0/mult_fact_DO]
  connect_bd_net -net reg_bank_0_nb_dll_steps_DO [get_bd_pins TOF_cos_sl_0/rbk_dist_dll_steps_DI] [get_bd_pins readRam_burst_1/nbofdllsteps_DI] [get_bd_pins reg_bank_0/nb_dll_steps_DO]
  connect_bd_net -net reg_bank_0_pix_inter_dcs_en_SO [get_bd_pins TOF_cos_sl_0/rbk_img_pix_inter_en_SI] [get_bd_pins reg_bank_0/pix_inter_dcs_en_SO]
  connect_bd_net -net reg_bank_0_pix_inter_dist_en_SO [get_bd_pins TOF_cos_sl_0/rbk_dist_mean_filter_en_SI] [get_bd_pins reg_bank_0/pix_inter_dist_en_SO]
  connect_bd_net -net reg_bank_0_ram_read_addr_DO [get_bd_pins readRam_burst_1/ram_addr_DI] [get_bd_pins reg_bank_0/ram_read_addr_DO]
  connect_bd_net -net reg_bank_0_roi_br_x_DO [get_bd_pins readRam_burst_1/roi_br_x_DI] [get_bd_pins reg_bank_0/roi_br_x_DO]
  connect_bd_net -net reg_bank_0_roi_br_y_DO [get_bd_pins readRam_burst_1/roi_br_y_DI] [get_bd_pins reg_bank_0/roi_br_y_DO]
  connect_bd_net -net reg_bank_0_roi_full_x_DO [get_bd_pins readRam_burst_1/roi_full_x_DI] [get_bd_pins reg_bank_0/roi_full_x_DO]
  connect_bd_net -net reg_bank_0_roi_full_y_DO [get_bd_pins readRam_burst_1/roi_full_y_DI] [get_bd_pins reg_bank_0/roi_full_y_DO]
  connect_bd_net -net reg_bank_0_roi_tl_x_DO [get_bd_pins readRam_burst_1/roi_tl_x_DI] [get_bd_pins reg_bank_0/roi_tl_x_DO]
  connect_bd_net -net reg_bank_0_roi_tl_y_DO [get_bd_pins readRam_burst_1/roi_tl_y_DI] [get_bd_pins reg_bank_0/roi_tl_y_DO]
  connect_bd_net -net reg_bank_0_temp_comp_en_SO [get_bd_pins TOF_cos_sl_0/rbk_add_const_temp_en_SI] [get_bd_pins reg_bank_0/temp_comp_en_SO]
  connect_bd_net -net reg_bank_0_temp_const_val_DO [get_bd_pins TOF_cos_sl_0/rbk_add_const_temp_val_DI] [get_bd_pins reg_bank_0/temp_const_val_DO]
  connect_bd_net -net rst_ps7_0_100M_interconnect_aresetn [get_bd_pins axi_mem_intercon/ARESETN] [get_bd_pins axi_mem_intercon_1/ARESETN] [get_bd_pins axi_mem_intercon_3/ARESETN] [get_bd_pins ps7_1_axi_periph/ARESETN] [get_bd_pins ps7_1_axi_periph/S00_ARESETN] [get_bd_pins rst_ps7_0_100M/interconnect_aresetn]
  connect_bd_net -net sg_dma_intr_isolation_data_out [get_bd_pins TOF_cos_sl_0/sg_dma_intr_SI] [get_bd_pins sg_dma_intr_isolation/data_out]
  connect_bd_net -net util_vector_logic_5_Res [get_bd_pins TOF_cos_sl_0/reset_or_done_edge_RBO] [get_bd_pins axi_dma_SG_sort/axi_resetn] [get_bd_pins data2axistream_v1_0_3/m00_axis_aresetn] [get_bd_pins data2axistream_v1_0_4/m00_axis_aresetn] [get_bd_pins data2ram_dcs/m00_axi_aresetn] [get_bd_pins data2ram_gs/m00_axi_aresetn]
  connect_bd_net -net vsync_in1_1 [get_bd_ports vsync_in1] [get_bd_pins ip_mux_1/vsync_in1]
  connect_bd_net -net vsync_in2_1 [get_bd_ports vsync_in2] [get_bd_pins ip_mux_1/vsync_in2]
  connect_bd_net -net vsync_in3_1 [get_bd_ports vsync_in3] [get_bd_pins ip_mux_1/vsync_in3]
  connect_bd_net -net vsync_in_1 [get_bd_ports vsync_in] [get_bd_pins ip_mux_1/vsync_in]
  connect_bd_net -net xlconcat_0_dout [get_bd_pins TOF_cos_sl_0/length_gs_data_DO] [get_bd_pins data2axistream_v1_0_4/NUMBER_OF_OUTPUT_WORDS] [get_bd_pins data2ram_gs/length_DI]
  connect_bd_net -net xlconstant_1_dout [get_bd_pins blk_mem_gen_dbg_unit/enb] [get_bd_pins xlconstant_1/dout]
  connect_bd_net -net xlconstant_2_dout [get_bd_pins blk_mem_gen_dbg_unit/rstb] [get_bd_pins xlconstant_2/dout]
  connect_bd_net -net xlslice_2_Dout [get_bd_pins TOF_cos_sl_0/sel_gs_mode_SO] [get_bd_pins axis_switch_2to1_0/select_S01_SI] [get_bd_pins data2ram_gs/wr_en_SI]
  connect_bd_net -net xsync_sat_in1_1 [get_bd_ports xsync_sat_in1] [get_bd_pins ip_mux_1/xsync_sat_in1]
  connect_bd_net -net xsync_sat_in2_1 [get_bd_ports xsync_sat_in2] [get_bd_pins ip_mux_1/xsync_sat_in2]
  connect_bd_net -net xsync_sat_in3_1 [get_bd_ports xsync_sat_in3] [get_bd_pins ip_mux_1/xsync_sat_in3]
  connect_bd_net -net xsync_sat_in_1 [get_bd_ports xsync_sat_in] [get_bd_pins ip_mux_1/xsync_sat_in]

  # Create address segments
  create_bd_addr_seg -range 0x10000000 -offset 0x00000000 [get_bd_addr_spaces axi_dma_SG_sort/Data_SG] [get_bd_addr_segs processing_system7_1/S_AXI_HP3/HP3_DDR_LOWOCM] SEG_processing_system7_1_HP3_DDR_LOWOCM
  create_bd_addr_seg -range 0x10000000 -offset 0x00000000 [get_bd_addr_spaces axi_dma_SG_sort/Data_S2MM] [get_bd_addr_segs processing_system7_1/S_AXI_HP3/HP3_DDR_LOWOCM] SEG_processing_system7_1_HP3_DDR_LOWOCM
  create_bd_addr_seg -range 0x10000000 -offset 0x00000000 [get_bd_addr_spaces data2ram_dcs/m00_axi] [get_bd_addr_segs processing_system7_1/S_AXI_HP2/HP2_DDR_LOWOCM] SEG_processing_system7_1_HP2_DDR_LOWOCM
  create_bd_addr_seg -range 0x10000000 -offset 0x00000000 [get_bd_addr_spaces data2ram_gs/m00_axi] [get_bd_addr_segs processing_system7_1/S_AXI_HP1/HP1_DDR_LOWOCM] SEG_processing_system7_1_HP1_DDR_LOWOCM
  create_bd_addr_seg -range 0x00001000 -offset 0x44000000 [get_bd_addr_spaces processing_system7_1/Data] [get_bd_addr_segs axi_bram_ctrl_dbg_unit/S_AXI/Mem0] SEG_axi_bram_ctrl_dbg_unit_Mem0
  create_bd_addr_seg -range 0x00010000 -offset 0x40420000 [get_bd_addr_spaces processing_system7_1/Data] [get_bd_addr_segs axi_dma_SG_sort/S_AXI_LITE/Reg] SEG_axi_dma_SG_sort_Reg
  create_bd_addr_seg -range 0x00010000 -offset 0x41230000 [get_bd_addr_spaces processing_system7_1/Data] [get_bd_addr_segs axi_gpio_Sel1/S_AXI/Reg] SEG_axi_gpio_0_Reg
  create_bd_addr_seg -range 0x00010000 -offset 0x41240000 [get_bd_addr_spaces processing_system7_1/Data] [get_bd_addr_segs axi_gpio_Sel2/S_AXI/Reg] SEG_axi_gpio_Sel2_Reg
  create_bd_addr_seg -range 0x00010000 -offset 0x41200000 [get_bd_addr_spaces processing_system7_1/Data] [get_bd_addr_segs axi_gpio_led/S_AXI/Reg] SEG_axi_gpio_led_Reg
  create_bd_addr_seg -range 0x00010000 -offset 0x41210000 [get_bd_addr_spaces processing_system7_1/Data] [get_bd_addr_segs axi_gpio_power_reset/S_AXI/Reg] SEG_axi_gpio_power_reset_Reg
  create_bd_addr_seg -range 0x00010000 -offset 0x43C10000 [get_bd_addr_spaces processing_system7_1/Data] [get_bd_addr_segs clk_wiz_0/s_axi_lite/Reg] SEG_clk_wiz_0_Reg
  create_bd_addr_seg -range 0x00010000 -offset 0x41220000 [get_bd_addr_spaces processing_system7_1/Data] [get_bd_addr_segs gpio_shutter/S_AXI/Reg] SEG_gpio_shutter_Reg
  create_bd_addr_seg -range 0x00010000 -offset 0x43C00000 [get_bd_addr_spaces processing_system7_1/Data] [get_bd_addr_segs reg_bank_0/S00_AXI/S00_AXI_reg] SEG_reg_bank_0_S00_AXI_reg
  create_bd_addr_seg -range 0x10000000 -offset 0x00000000 [get_bd_addr_spaces readRam_burst_1/M00_AXI] [get_bd_addr_segs processing_system7_1/S_AXI_HP0/HP0_DDR_LOWOCM] SEG_processing_system7_1_HP0_DDR_LOWOCM


  # Restore current instance
  current_bd_instance $oldCurInst

  save_bd_design
}
# End of create_root_design()


##################################################################
# MAIN FLOW
##################################################################

create_root_design ""


