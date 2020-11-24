# Definitional proc to organize widgets for parameters.
proc init_gui { IPINST } {
  ipgui::add_param $IPINST -name "Component_Name"
  ipgui::add_param $IPINST -name "BAD_PIXEL_CODE"
  ipgui::add_param $IPINST -name "NBITS"

}

proc update_PARAM_VALUE.BAD_PIXEL_CODE { PARAM_VALUE.BAD_PIXEL_CODE } {
	# Procedure called to update BAD_PIXEL_CODE when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.BAD_PIXEL_CODE { PARAM_VALUE.BAD_PIXEL_CODE } {
	# Procedure called to validate BAD_PIXEL_CODE
	return true
}

proc update_PARAM_VALUE.NBITS { PARAM_VALUE.NBITS } {
	# Procedure called to update NBITS when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS { PARAM_VALUE.NBITS } {
	# Procedure called to validate NBITS
	return true
}


proc update_MODELPARAM_VALUE.BAD_PIXEL_CODE { MODELPARAM_VALUE.BAD_PIXEL_CODE PARAM_VALUE.BAD_PIXEL_CODE } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.BAD_PIXEL_CODE}] ${MODELPARAM_VALUE.BAD_PIXEL_CODE}
}

proc update_MODELPARAM_VALUE.NBITS { MODELPARAM_VALUE.NBITS PARAM_VALUE.NBITS } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS}] ${MODELPARAM_VALUE.NBITS}
}

