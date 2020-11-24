# Definitional proc to organize widgets for parameters.
proc init_gui { IPINST } {
  ipgui::add_param $IPINST -name "Component_Name"
  ipgui::add_param $IPINST -name "INPUT_FIFO_BITS" -widget comboBox
  ipgui::add_param $IPINST -name "INPUT_BUS_WIDTH"
  ipgui::add_param $IPINST -name "C_M00_AXIS_TDATA_WIDTH"
  ipgui::add_param $IPINST -name "C_M00_AXIS_START_COUNT"

}

proc update_PARAM_VALUE.C_M00_AXIS_START_COUNT { PARAM_VALUE.C_M00_AXIS_START_COUNT } {
	# Procedure called to update C_M00_AXIS_START_COUNT when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.C_M00_AXIS_START_COUNT { PARAM_VALUE.C_M00_AXIS_START_COUNT } {
	# Procedure called to validate C_M00_AXIS_START_COUNT
	return true
}

proc update_PARAM_VALUE.C_M00_AXIS_TDATA_WIDTH { PARAM_VALUE.C_M00_AXIS_TDATA_WIDTH } {
	# Procedure called to update C_M00_AXIS_TDATA_WIDTH when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.C_M00_AXIS_TDATA_WIDTH { PARAM_VALUE.C_M00_AXIS_TDATA_WIDTH } {
	# Procedure called to validate C_M00_AXIS_TDATA_WIDTH
	return true
}

proc update_PARAM_VALUE.INPUT_BUS_WIDTH { PARAM_VALUE.INPUT_BUS_WIDTH } {
	# Procedure called to update INPUT_BUS_WIDTH when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.INPUT_BUS_WIDTH { PARAM_VALUE.INPUT_BUS_WIDTH } {
	# Procedure called to validate INPUT_BUS_WIDTH
	return true
}

proc update_PARAM_VALUE.INPUT_FIFO_BITS { PARAM_VALUE.INPUT_FIFO_BITS } {
	# Procedure called to update INPUT_FIFO_BITS when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.INPUT_FIFO_BITS { PARAM_VALUE.INPUT_FIFO_BITS } {
	# Procedure called to validate INPUT_FIFO_BITS
	return true
}


proc update_MODELPARAM_VALUE.INPUT_BUS_WIDTH { MODELPARAM_VALUE.INPUT_BUS_WIDTH PARAM_VALUE.INPUT_BUS_WIDTH } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.INPUT_BUS_WIDTH}] ${MODELPARAM_VALUE.INPUT_BUS_WIDTH}
}

proc update_MODELPARAM_VALUE.C_M00_AXIS_TDATA_WIDTH { MODELPARAM_VALUE.C_M00_AXIS_TDATA_WIDTH PARAM_VALUE.C_M00_AXIS_TDATA_WIDTH } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.C_M00_AXIS_TDATA_WIDTH}] ${MODELPARAM_VALUE.C_M00_AXIS_TDATA_WIDTH}
}

proc update_MODELPARAM_VALUE.C_M00_AXIS_START_COUNT { MODELPARAM_VALUE.C_M00_AXIS_START_COUNT PARAM_VALUE.C_M00_AXIS_START_COUNT } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.C_M00_AXIS_START_COUNT}] ${MODELPARAM_VALUE.C_M00_AXIS_START_COUNT}
}

proc update_MODELPARAM_VALUE.INPUT_FIFO_BITS { MODELPARAM_VALUE.INPUT_FIFO_BITS PARAM_VALUE.INPUT_FIFO_BITS } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.INPUT_FIFO_BITS}] ${MODELPARAM_VALUE.INPUT_FIFO_BITS}
}

