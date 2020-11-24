# Definitional proc to organize widgets for parameters.
proc init_gui { IPINST } {
  ipgui::add_param $IPINST -name "Component_Name"
  #Adding Page
  set Page_0 [ipgui::add_page $IPINST -name "Page 0"]
  ipgui::add_param $IPINST -name "BIT_WIDTH" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NB_STAGES" -parent ${Page_0}


}

proc update_PARAM_VALUE.BIT_WIDTH { PARAM_VALUE.BIT_WIDTH } {
	# Procedure called to update BIT_WIDTH when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.BIT_WIDTH { PARAM_VALUE.BIT_WIDTH } {
	# Procedure called to validate BIT_WIDTH
	return true
}

proc update_PARAM_VALUE.NB_STAGES { PARAM_VALUE.NB_STAGES } {
	# Procedure called to update NB_STAGES when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NB_STAGES { PARAM_VALUE.NB_STAGES } {
	# Procedure called to validate NB_STAGES
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


proc update_MODELPARAM_VALUE.BIT_WIDTH { MODELPARAM_VALUE.BIT_WIDTH PARAM_VALUE.BIT_WIDTH } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.BIT_WIDTH}] ${MODELPARAM_VALUE.BIT_WIDTH}
}

proc update_MODELPARAM_VALUE.NB_STAGES { MODELPARAM_VALUE.NB_STAGES PARAM_VALUE.NB_STAGES } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NB_STAGES}] ${MODELPARAM_VALUE.NB_STAGES}
}

