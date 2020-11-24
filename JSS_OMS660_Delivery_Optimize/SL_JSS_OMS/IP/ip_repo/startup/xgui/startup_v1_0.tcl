# Definitional proc to organize widgets for parameters.
proc init_gui { IPINST } {
  ipgui::add_param $IPINST -name "Component_Name"
  #Adding Page
  set Page_0 [ipgui::add_page $IPINST -name "Page 0"]
  ipgui::add_param $IPINST -name "WAIT_CYCLE_CHIP_RDY" -parent ${Page_0}
  ipgui::add_param $IPINST -name "WAIT_CYCLE_VBS_RAMP" -parent ${Page_0}
  ipgui::add_param $IPINST -name "WAIT_CYCLE_VDDA_RAMP" -parent ${Page_0}
  ipgui::add_param $IPINST -name "WAIT_CYCLE_VDDIO_RAMP" -parent ${Page_0}
  ipgui::add_param $IPINST -name "WAIT_CYCLE_VDD_RAMP" -parent ${Page_0}


}

proc update_PARAM_VALUE.WAIT_CYCLE_CHIP_RDY { PARAM_VALUE.WAIT_CYCLE_CHIP_RDY } {
	# Procedure called to update WAIT_CYCLE_CHIP_RDY when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.WAIT_CYCLE_CHIP_RDY { PARAM_VALUE.WAIT_CYCLE_CHIP_RDY } {
	# Procedure called to validate WAIT_CYCLE_CHIP_RDY
	return true
}

proc update_PARAM_VALUE.WAIT_CYCLE_VBS_RAMP { PARAM_VALUE.WAIT_CYCLE_VBS_RAMP } {
	# Procedure called to update WAIT_CYCLE_VBS_RAMP when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.WAIT_CYCLE_VBS_RAMP { PARAM_VALUE.WAIT_CYCLE_VBS_RAMP } {
	# Procedure called to validate WAIT_CYCLE_VBS_RAMP
	return true
}

proc update_PARAM_VALUE.WAIT_CYCLE_VDDA_RAMP { PARAM_VALUE.WAIT_CYCLE_VDDA_RAMP } {
	# Procedure called to update WAIT_CYCLE_VDDA_RAMP when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.WAIT_CYCLE_VDDA_RAMP { PARAM_VALUE.WAIT_CYCLE_VDDA_RAMP } {
	# Procedure called to validate WAIT_CYCLE_VDDA_RAMP
	return true
}

proc update_PARAM_VALUE.WAIT_CYCLE_VDDIO_RAMP { PARAM_VALUE.WAIT_CYCLE_VDDIO_RAMP } {
	# Procedure called to update WAIT_CYCLE_VDDIO_RAMP when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.WAIT_CYCLE_VDDIO_RAMP { PARAM_VALUE.WAIT_CYCLE_VDDIO_RAMP } {
	# Procedure called to validate WAIT_CYCLE_VDDIO_RAMP
	return true
}

proc update_PARAM_VALUE.WAIT_CYCLE_VDD_RAMP { PARAM_VALUE.WAIT_CYCLE_VDD_RAMP } {
	# Procedure called to update WAIT_CYCLE_VDD_RAMP when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.WAIT_CYCLE_VDD_RAMP { PARAM_VALUE.WAIT_CYCLE_VDD_RAMP } {
	# Procedure called to validate WAIT_CYCLE_VDD_RAMP
	return true
}


proc update_MODELPARAM_VALUE.WAIT_CYCLE_VDD_RAMP { MODELPARAM_VALUE.WAIT_CYCLE_VDD_RAMP PARAM_VALUE.WAIT_CYCLE_VDD_RAMP } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.WAIT_CYCLE_VDD_RAMP}] ${MODELPARAM_VALUE.WAIT_CYCLE_VDD_RAMP}
}

proc update_MODELPARAM_VALUE.WAIT_CYCLE_VDDIO_RAMP { MODELPARAM_VALUE.WAIT_CYCLE_VDDIO_RAMP PARAM_VALUE.WAIT_CYCLE_VDDIO_RAMP } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.WAIT_CYCLE_VDDIO_RAMP}] ${MODELPARAM_VALUE.WAIT_CYCLE_VDDIO_RAMP}
}

proc update_MODELPARAM_VALUE.WAIT_CYCLE_VDDA_RAMP { MODELPARAM_VALUE.WAIT_CYCLE_VDDA_RAMP PARAM_VALUE.WAIT_CYCLE_VDDA_RAMP } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.WAIT_CYCLE_VDDA_RAMP}] ${MODELPARAM_VALUE.WAIT_CYCLE_VDDA_RAMP}
}

proc update_MODELPARAM_VALUE.WAIT_CYCLE_VBS_RAMP { MODELPARAM_VALUE.WAIT_CYCLE_VBS_RAMP PARAM_VALUE.WAIT_CYCLE_VBS_RAMP } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.WAIT_CYCLE_VBS_RAMP}] ${MODELPARAM_VALUE.WAIT_CYCLE_VBS_RAMP}
}

proc update_MODELPARAM_VALUE.WAIT_CYCLE_CHIP_RDY { MODELPARAM_VALUE.WAIT_CYCLE_CHIP_RDY PARAM_VALUE.WAIT_CYCLE_CHIP_RDY } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.WAIT_CYCLE_CHIP_RDY}] ${MODELPARAM_VALUE.WAIT_CYCLE_CHIP_RDY}
}

