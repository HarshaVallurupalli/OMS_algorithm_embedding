# Definitional proc to organize widgets for parameters.
proc init_gui { IPINST } {
  ipgui::add_param $IPINST -name "Component_Name"
  #Adding Page
  ipgui::add_page $IPINST -name "Page 0"

  ipgui::add_param $IPINST -name "RISING"
  ipgui::add_param $IPINST -name "FALLING"
  ipgui::add_param $IPINST -name "PULSE_LENGTH"
  ipgui::add_param $IPINST -name "NEG_OUTPUT"

}

proc update_PARAM_VALUE.FALLING { PARAM_VALUE.FALLING } {
	# Procedure called to update FALLING when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.FALLING { PARAM_VALUE.FALLING } {
	# Procedure called to validate FALLING
	return true
}

proc update_PARAM_VALUE.NEG_OUTPUT { PARAM_VALUE.NEG_OUTPUT } {
	# Procedure called to update NEG_OUTPUT when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NEG_OUTPUT { PARAM_VALUE.NEG_OUTPUT } {
	# Procedure called to validate NEG_OUTPUT
	return true
}

proc update_PARAM_VALUE.PULSE_LENGTH { PARAM_VALUE.PULSE_LENGTH } {
	# Procedure called to update PULSE_LENGTH when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.PULSE_LENGTH { PARAM_VALUE.PULSE_LENGTH } {
	# Procedure called to validate PULSE_LENGTH
	return true
}

proc update_PARAM_VALUE.RISING { PARAM_VALUE.RISING } {
	# Procedure called to update RISING when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.RISING { PARAM_VALUE.RISING } {
	# Procedure called to validate RISING
	return true
}


proc update_MODELPARAM_VALUE.RISING { MODELPARAM_VALUE.RISING PARAM_VALUE.RISING } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.RISING}] ${MODELPARAM_VALUE.RISING}
}

proc update_MODELPARAM_VALUE.FALLING { MODELPARAM_VALUE.FALLING PARAM_VALUE.FALLING } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.FALLING}] ${MODELPARAM_VALUE.FALLING}
}

proc update_MODELPARAM_VALUE.NEG_OUTPUT { MODELPARAM_VALUE.NEG_OUTPUT PARAM_VALUE.NEG_OUTPUT } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NEG_OUTPUT}] ${MODELPARAM_VALUE.NEG_OUTPUT}
}

proc update_MODELPARAM_VALUE.PULSE_LENGTH { MODELPARAM_VALUE.PULSE_LENGTH PARAM_VALUE.PULSE_LENGTH } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.PULSE_LENGTH}] ${MODELPARAM_VALUE.PULSE_LENGTH}
}

