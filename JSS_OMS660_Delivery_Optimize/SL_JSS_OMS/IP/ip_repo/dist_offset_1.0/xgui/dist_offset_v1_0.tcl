# Definitional proc to organize widgets for parameters.
proc init_gui { IPINST } {
  ipgui::add_param $IPINST -name "Component_Name"
  #Adding Page
  ipgui::add_page $IPINST -name "Page 0"

  ipgui::add_param $IPINST -name "RAM_READ_CYCLES"
  ipgui::add_param $IPINST -name "NBITS_DIST"
  ipgui::add_param $IPINST -name "NBITS_DATA"
  ipgui::add_param $IPINST -name "NBITS_INDEX"
  ipgui::add_param $IPINST -name "NBITS_DLL_STEPS"

}

proc update_PARAM_VALUE.NBITS_DATA { PARAM_VALUE.NBITS_DATA } {
	# Procedure called to update NBITS_DATA when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_DATA { PARAM_VALUE.NBITS_DATA } {
	# Procedure called to validate NBITS_DATA
	return true
}

proc update_PARAM_VALUE.NBITS_DIST { PARAM_VALUE.NBITS_DIST } {
	# Procedure called to update NBITS_DIST when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_DIST { PARAM_VALUE.NBITS_DIST } {
	# Procedure called to validate NBITS_DIST
	return true
}

proc update_PARAM_VALUE.NBITS_DLL_STEPS { PARAM_VALUE.NBITS_DLL_STEPS } {
	# Procedure called to update NBITS_DLL_STEPS when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_DLL_STEPS { PARAM_VALUE.NBITS_DLL_STEPS } {
	# Procedure called to validate NBITS_DLL_STEPS
	return true
}

proc update_PARAM_VALUE.NBITS_INDEX { PARAM_VALUE.NBITS_INDEX } {
	# Procedure called to update NBITS_INDEX when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_INDEX { PARAM_VALUE.NBITS_INDEX } {
	# Procedure called to validate NBITS_INDEX
	return true
}

proc update_PARAM_VALUE.RAM_READ_CYCLES { PARAM_VALUE.RAM_READ_CYCLES } {
	# Procedure called to update RAM_READ_CYCLES when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.RAM_READ_CYCLES { PARAM_VALUE.RAM_READ_CYCLES } {
	# Procedure called to validate RAM_READ_CYCLES
	return true
}


proc update_MODELPARAM_VALUE.RAM_READ_CYCLES { MODELPARAM_VALUE.RAM_READ_CYCLES PARAM_VALUE.RAM_READ_CYCLES } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.RAM_READ_CYCLES}] ${MODELPARAM_VALUE.RAM_READ_CYCLES}
}

proc update_MODELPARAM_VALUE.NBITS_DIST { MODELPARAM_VALUE.NBITS_DIST PARAM_VALUE.NBITS_DIST } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_DIST}] ${MODELPARAM_VALUE.NBITS_DIST}
}

proc update_MODELPARAM_VALUE.NBITS_DATA { MODELPARAM_VALUE.NBITS_DATA PARAM_VALUE.NBITS_DATA } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_DATA}] ${MODELPARAM_VALUE.NBITS_DATA}
}

proc update_MODELPARAM_VALUE.NBITS_INDEX { MODELPARAM_VALUE.NBITS_INDEX PARAM_VALUE.NBITS_INDEX } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_INDEX}] ${MODELPARAM_VALUE.NBITS_INDEX}
}

proc update_MODELPARAM_VALUE.NBITS_DLL_STEPS { MODELPARAM_VALUE.NBITS_DLL_STEPS PARAM_VALUE.NBITS_DLL_STEPS } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_DLL_STEPS}] ${MODELPARAM_VALUE.NBITS_DLL_STEPS}
}

