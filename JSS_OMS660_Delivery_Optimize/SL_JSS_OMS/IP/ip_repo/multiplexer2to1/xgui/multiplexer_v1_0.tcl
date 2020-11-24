# Definitional proc to organize widgets for parameters.
proc init_gui { IPINST } {
  ipgui::add_param $IPINST -name "Component_Name"
  #Adding Page
  set Page_0 [ipgui::add_page $IPINST -name "Page 0"]
  ipgui::add_param $IPINST -name "NBITS_DATA" -parent ${Page_0}


}

proc update_PARAM_VALUE.NBITS_DATA { PARAM_VALUE.NBITS_DATA } {
	# Procedure called to update NBITS_DATA when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_DATA { PARAM_VALUE.NBITS_DATA } {
	# Procedure called to validate NBITS_DATA
	return true
}


proc update_MODELPARAM_VALUE.NBITS_DATA { MODELPARAM_VALUE.NBITS_DATA PARAM_VALUE.NBITS_DATA } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_DATA}] ${MODELPARAM_VALUE.NBITS_DATA}
}

