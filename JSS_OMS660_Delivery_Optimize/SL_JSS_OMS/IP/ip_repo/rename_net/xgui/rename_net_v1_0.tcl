# Definitional proc to organize widgets for parameters.
proc init_gui { IPINST } {
  ipgui::add_param $IPINST -name "Component_Name"
  #Adding Page
  set Page_0 [ipgui::add_page $IPINST -name "Page 0"]
  ipgui::add_param $IPINST -name "INBITS" -parent ${Page_0}
  ipgui::add_param $IPINST -name "OUTBITS" -parent ${Page_0}

  ipgui::add_param $IPINST -name "OFFSET"

}

proc update_PARAM_VALUE.INBITS { PARAM_VALUE.INBITS } {
	# Procedure called to update INBITS when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.INBITS { PARAM_VALUE.INBITS } {
	# Procedure called to validate INBITS
	return true
}

proc update_PARAM_VALUE.OFFSET { PARAM_VALUE.OFFSET } {
	# Procedure called to update OFFSET when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.OFFSET { PARAM_VALUE.OFFSET } {
	# Procedure called to validate OFFSET
	return true
}

proc update_PARAM_VALUE.OUTBITS { PARAM_VALUE.OUTBITS } {
	# Procedure called to update OUTBITS when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.OUTBITS { PARAM_VALUE.OUTBITS } {
	# Procedure called to validate OUTBITS
	return true
}


proc update_MODELPARAM_VALUE.INBITS { MODELPARAM_VALUE.INBITS PARAM_VALUE.INBITS } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.INBITS}] ${MODELPARAM_VALUE.INBITS}
}

proc update_MODELPARAM_VALUE.OUTBITS { MODELPARAM_VALUE.OUTBITS PARAM_VALUE.OUTBITS } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.OUTBITS}] ${MODELPARAM_VALUE.OUTBITS}
}

proc update_MODELPARAM_VALUE.OFFSET { MODELPARAM_VALUE.OFFSET PARAM_VALUE.OFFSET } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.OFFSET}] ${MODELPARAM_VALUE.OFFSET}
}

