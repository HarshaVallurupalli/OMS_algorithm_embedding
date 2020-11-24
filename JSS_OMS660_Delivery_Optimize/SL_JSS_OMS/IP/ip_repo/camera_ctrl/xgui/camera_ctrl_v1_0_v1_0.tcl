# Definitional proc to organize widgets for parameters.
proc init_gui { IPINST } {
  ipgui::add_param $IPINST -name "Component_Name"
  #Adding Page
  ipgui::add_page $IPINST -name "Page 0"

  ipgui::add_param $IPINST -name "CLK_DIVISION_FACTOR"
  ipgui::add_param $IPINST -name "ALU_PREP_CYCLES"
  ipgui::add_param $IPINST -name "RAM_WAIT_CYCLES"
  ipgui::add_param $IPINST -name "RAM_WAIT_DONE"
  ipgui::add_param $IPINST -name "DONE_DELAY"

}

proc update_PARAM_VALUE.ALU_PREP_CYCLES { PARAM_VALUE.ALU_PREP_CYCLES } {
	# Procedure called to update ALU_PREP_CYCLES when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.ALU_PREP_CYCLES { PARAM_VALUE.ALU_PREP_CYCLES } {
	# Procedure called to validate ALU_PREP_CYCLES
	return true
}

proc update_PARAM_VALUE.CLK_DIVISION_FACTOR { PARAM_VALUE.CLK_DIVISION_FACTOR } {
	# Procedure called to update CLK_DIVISION_FACTOR when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.CLK_DIVISION_FACTOR { PARAM_VALUE.CLK_DIVISION_FACTOR } {
	# Procedure called to validate CLK_DIVISION_FACTOR
	return true
}

proc update_PARAM_VALUE.DONE_DELAY { PARAM_VALUE.DONE_DELAY } {
	# Procedure called to update DONE_DELAY when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.DONE_DELAY { PARAM_VALUE.DONE_DELAY } {
	# Procedure called to validate DONE_DELAY
	return true
}

proc update_PARAM_VALUE.RAM_WAIT_CYCLES { PARAM_VALUE.RAM_WAIT_CYCLES } {
	# Procedure called to update RAM_WAIT_CYCLES when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.RAM_WAIT_CYCLES { PARAM_VALUE.RAM_WAIT_CYCLES } {
	# Procedure called to validate RAM_WAIT_CYCLES
	return true
}

proc update_PARAM_VALUE.RAM_WAIT_DONE { PARAM_VALUE.RAM_WAIT_DONE } {
	# Procedure called to update RAM_WAIT_DONE when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.RAM_WAIT_DONE { PARAM_VALUE.RAM_WAIT_DONE } {
	# Procedure called to validate RAM_WAIT_DONE
	return true
}


proc update_MODELPARAM_VALUE.CLK_DIVISION_FACTOR { MODELPARAM_VALUE.CLK_DIVISION_FACTOR PARAM_VALUE.CLK_DIVISION_FACTOR } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.CLK_DIVISION_FACTOR}] ${MODELPARAM_VALUE.CLK_DIVISION_FACTOR}
}

proc update_MODELPARAM_VALUE.ALU_PREP_CYCLES { MODELPARAM_VALUE.ALU_PREP_CYCLES PARAM_VALUE.ALU_PREP_CYCLES } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.ALU_PREP_CYCLES}] ${MODELPARAM_VALUE.ALU_PREP_CYCLES}
}

proc update_MODELPARAM_VALUE.RAM_WAIT_CYCLES { MODELPARAM_VALUE.RAM_WAIT_CYCLES PARAM_VALUE.RAM_WAIT_CYCLES } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.RAM_WAIT_CYCLES}] ${MODELPARAM_VALUE.RAM_WAIT_CYCLES}
}

proc update_MODELPARAM_VALUE.RAM_WAIT_DONE { MODELPARAM_VALUE.RAM_WAIT_DONE PARAM_VALUE.RAM_WAIT_DONE } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.RAM_WAIT_DONE}] ${MODELPARAM_VALUE.RAM_WAIT_DONE}
}

proc update_MODELPARAM_VALUE.DONE_DELAY { MODELPARAM_VALUE.DONE_DELAY PARAM_VALUE.DONE_DELAY } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.DONE_DELAY}] ${MODELPARAM_VALUE.DONE_DELAY}
}

