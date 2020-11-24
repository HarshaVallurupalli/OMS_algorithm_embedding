# Definitional proc to organize widgets for parameters.
proc init_gui { IPINST } {
  ipgui::add_param $IPINST -name "Component_Name"
  ipgui::add_param $IPINST -name "NBITS_DATA"
  ipgui::add_param $IPINST -name "NBITS_DEPT_FIFO0"
  ipgui::add_param $IPINST -name "NBITS_DEPT_FIFO1"

}

proc update_PARAM_VALUE.NBITS_DATA { PARAM_VALUE.NBITS_DATA } {
	# Procedure called to update NBITS_DATA when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_DATA { PARAM_VALUE.NBITS_DATA } {
	# Procedure called to validate NBITS_DATA
	return true
}

proc update_PARAM_VALUE.NBITS_DEPT_FIFO0 { PARAM_VALUE.NBITS_DEPT_FIFO0 } {
	# Procedure called to update NBITS_DEPT_FIFO0 when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_DEPT_FIFO0 { PARAM_VALUE.NBITS_DEPT_FIFO0 } {
	# Procedure called to validate NBITS_DEPT_FIFO0
	return true
}

proc update_PARAM_VALUE.NBITS_DEPT_FIFO1 { PARAM_VALUE.NBITS_DEPT_FIFO1 } {
	# Procedure called to update NBITS_DEPT_FIFO1 when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_DEPT_FIFO1 { PARAM_VALUE.NBITS_DEPT_FIFO1 } {
	# Procedure called to validate NBITS_DEPT_FIFO1
	return true
}

proc update_PARAM_VALUE.C_S00_AXI_BASEADDR { PARAM_VALUE.C_S00_AXI_BASEADDR } {
	# Procedure called to update C_S00_AXI_BASEADDR when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.C_S00_AXI_BASEADDR { PARAM_VALUE.C_S00_AXI_BASEADDR } {
	# Procedure called to validate C_S00_AXI_BASEADDR
	return true
}

proc update_PARAM_VALUE.C_S00_AXI_HIGHADDR { PARAM_VALUE.C_S00_AXI_HIGHADDR } {
	# Procedure called to update C_S00_AXI_HIGHADDR when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.C_S00_AXI_HIGHADDR { PARAM_VALUE.C_S00_AXI_HIGHADDR } {
	# Procedure called to validate C_S00_AXI_HIGHADDR
	return true
}


proc update_MODELPARAM_VALUE.NBITS_DATA { MODELPARAM_VALUE.NBITS_DATA PARAM_VALUE.NBITS_DATA } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_DATA}] ${MODELPARAM_VALUE.NBITS_DATA}
}

proc update_MODELPARAM_VALUE.NBITS_DEPT_FIFO0 { MODELPARAM_VALUE.NBITS_DEPT_FIFO0 PARAM_VALUE.NBITS_DEPT_FIFO0 } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_DEPT_FIFO0}] ${MODELPARAM_VALUE.NBITS_DEPT_FIFO0}
}

proc update_MODELPARAM_VALUE.NBITS_DEPT_FIFO1 { MODELPARAM_VALUE.NBITS_DEPT_FIFO1 PARAM_VALUE.NBITS_DEPT_FIFO1 } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_DEPT_FIFO1}] ${MODELPARAM_VALUE.NBITS_DEPT_FIFO1}
}

