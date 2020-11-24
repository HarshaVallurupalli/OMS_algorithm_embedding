# Definitional proc to organize widgets for parameters.
proc init_gui { IPINST } {
  ipgui::add_param $IPINST -name "Component_Name"
  #Adding Page
  set Page_0 [ipgui::add_page $IPINST -name "Page 0"]
  ipgui::add_param $IPINST -name "MEM_SIZE_BRAM_DCS" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_ADDR_BRAM_DCS" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_ADDR_FIFO0" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_ADDR_FIFO1" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_ADDR_IMG_BRAM" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_AL_COMP" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_AMP_OUT" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_CAL_RAM" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_DATA_BRAM_DCS" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_DATA_IN" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_DIST_INDEX" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_DIST_MEM_CTRL" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_DIST_OUT" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_DLL_CORR" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_LENGTH" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_LINE_LENGTH" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_MININDEX" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_NB_DLL_STEPS" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_OUTPUT_DATA" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NB_OF_PIXEL" -parent ${Page_0}

  ipgui::add_param $IPINST -name "ENABLE_INPUT_FIFO"
  ipgui::add_param $IPINST -name "ENABLE_DELAY_NB"
  ipgui::add_param $IPINST -name "NBITS_GS_RAM"

}

proc update_PARAM_VALUE.ENABLE_DELAY_NB { PARAM_VALUE.ENABLE_DELAY_NB } {
	# Procedure called to update ENABLE_DELAY_NB when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.ENABLE_DELAY_NB { PARAM_VALUE.ENABLE_DELAY_NB } {
	# Procedure called to validate ENABLE_DELAY_NB
	return true
}

proc update_PARAM_VALUE.ENABLE_INPUT_FIFO { PARAM_VALUE.ENABLE_INPUT_FIFO } {
	# Procedure called to update ENABLE_INPUT_FIFO when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.ENABLE_INPUT_FIFO { PARAM_VALUE.ENABLE_INPUT_FIFO } {
	# Procedure called to validate ENABLE_INPUT_FIFO
	return true
}

proc update_PARAM_VALUE.MEM_SIZE_BRAM_DCS { PARAM_VALUE.MEM_SIZE_BRAM_DCS } {
	# Procedure called to update MEM_SIZE_BRAM_DCS when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.MEM_SIZE_BRAM_DCS { PARAM_VALUE.MEM_SIZE_BRAM_DCS } {
	# Procedure called to validate MEM_SIZE_BRAM_DCS
	return true
}

proc update_PARAM_VALUE.NBITS_ADDR_BRAM_DCS { PARAM_VALUE.NBITS_ADDR_BRAM_DCS } {
	# Procedure called to update NBITS_ADDR_BRAM_DCS when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_ADDR_BRAM_DCS { PARAM_VALUE.NBITS_ADDR_BRAM_DCS } {
	# Procedure called to validate NBITS_ADDR_BRAM_DCS
	return true
}

proc update_PARAM_VALUE.NBITS_ADDR_FIFO0 { PARAM_VALUE.NBITS_ADDR_FIFO0 } {
	# Procedure called to update NBITS_ADDR_FIFO0 when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_ADDR_FIFO0 { PARAM_VALUE.NBITS_ADDR_FIFO0 } {
	# Procedure called to validate NBITS_ADDR_FIFO0
	return true
}

proc update_PARAM_VALUE.NBITS_ADDR_FIFO1 { PARAM_VALUE.NBITS_ADDR_FIFO1 } {
	# Procedure called to update NBITS_ADDR_FIFO1 when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_ADDR_FIFO1 { PARAM_VALUE.NBITS_ADDR_FIFO1 } {
	# Procedure called to validate NBITS_ADDR_FIFO1
	return true
}

proc update_PARAM_VALUE.NBITS_ADDR_IMG_BRAM { PARAM_VALUE.NBITS_ADDR_IMG_BRAM } {
	# Procedure called to update NBITS_ADDR_IMG_BRAM when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_ADDR_IMG_BRAM { PARAM_VALUE.NBITS_ADDR_IMG_BRAM } {
	# Procedure called to validate NBITS_ADDR_IMG_BRAM
	return true
}

proc update_PARAM_VALUE.NBITS_AL_COMP { PARAM_VALUE.NBITS_AL_COMP } {
	# Procedure called to update NBITS_AL_COMP when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_AL_COMP { PARAM_VALUE.NBITS_AL_COMP } {
	# Procedure called to validate NBITS_AL_COMP
	return true
}

proc update_PARAM_VALUE.NBITS_AMP_OUT { PARAM_VALUE.NBITS_AMP_OUT } {
	# Procedure called to update NBITS_AMP_OUT when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_AMP_OUT { PARAM_VALUE.NBITS_AMP_OUT } {
	# Procedure called to validate NBITS_AMP_OUT
	return true
}

proc update_PARAM_VALUE.NBITS_CAL_RAM { PARAM_VALUE.NBITS_CAL_RAM } {
	# Procedure called to update NBITS_CAL_RAM when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_CAL_RAM { PARAM_VALUE.NBITS_CAL_RAM } {
	# Procedure called to validate NBITS_CAL_RAM
	return true
}

proc update_PARAM_VALUE.NBITS_DATA_BRAM_DCS { PARAM_VALUE.NBITS_DATA_BRAM_DCS } {
	# Procedure called to update NBITS_DATA_BRAM_DCS when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_DATA_BRAM_DCS { PARAM_VALUE.NBITS_DATA_BRAM_DCS } {
	# Procedure called to validate NBITS_DATA_BRAM_DCS
	return true
}

proc update_PARAM_VALUE.NBITS_DATA_IN { PARAM_VALUE.NBITS_DATA_IN } {
	# Procedure called to update NBITS_DATA_IN when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_DATA_IN { PARAM_VALUE.NBITS_DATA_IN } {
	# Procedure called to validate NBITS_DATA_IN
	return true
}

proc update_PARAM_VALUE.NBITS_DIST_INDEX { PARAM_VALUE.NBITS_DIST_INDEX } {
	# Procedure called to update NBITS_DIST_INDEX when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_DIST_INDEX { PARAM_VALUE.NBITS_DIST_INDEX } {
	# Procedure called to validate NBITS_DIST_INDEX
	return true
}

proc update_PARAM_VALUE.NBITS_DIST_MEM_CTRL { PARAM_VALUE.NBITS_DIST_MEM_CTRL } {
	# Procedure called to update NBITS_DIST_MEM_CTRL when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_DIST_MEM_CTRL { PARAM_VALUE.NBITS_DIST_MEM_CTRL } {
	# Procedure called to validate NBITS_DIST_MEM_CTRL
	return true
}

proc update_PARAM_VALUE.NBITS_DIST_OUT { PARAM_VALUE.NBITS_DIST_OUT } {
	# Procedure called to update NBITS_DIST_OUT when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_DIST_OUT { PARAM_VALUE.NBITS_DIST_OUT } {
	# Procedure called to validate NBITS_DIST_OUT
	return true
}

proc update_PARAM_VALUE.NBITS_DLL_CORR { PARAM_VALUE.NBITS_DLL_CORR } {
	# Procedure called to update NBITS_DLL_CORR when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_DLL_CORR { PARAM_VALUE.NBITS_DLL_CORR } {
	# Procedure called to validate NBITS_DLL_CORR
	return true
}

proc update_PARAM_VALUE.NBITS_GS_RAM { PARAM_VALUE.NBITS_GS_RAM } {
	# Procedure called to update NBITS_GS_RAM when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_GS_RAM { PARAM_VALUE.NBITS_GS_RAM } {
	# Procedure called to validate NBITS_GS_RAM
	return true
}

proc update_PARAM_VALUE.NBITS_LENGTH { PARAM_VALUE.NBITS_LENGTH } {
	# Procedure called to update NBITS_LENGTH when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_LENGTH { PARAM_VALUE.NBITS_LENGTH } {
	# Procedure called to validate NBITS_LENGTH
	return true
}

proc update_PARAM_VALUE.NBITS_LINE_LENGTH { PARAM_VALUE.NBITS_LINE_LENGTH } {
	# Procedure called to update NBITS_LINE_LENGTH when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_LINE_LENGTH { PARAM_VALUE.NBITS_LINE_LENGTH } {
	# Procedure called to validate NBITS_LINE_LENGTH
	return true
}

proc update_PARAM_VALUE.NBITS_MAX_GS_RAM_DATA_IN { PARAM_VALUE.NBITS_MAX_GS_RAM_DATA_IN } {
	# Procedure called to update NBITS_MAX_GS_RAM_DATA_IN when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_MAX_GS_RAM_DATA_IN { PARAM_VALUE.NBITS_MAX_GS_RAM_DATA_IN } {
	# Procedure called to validate NBITS_MAX_GS_RAM_DATA_IN
	return true
}

proc update_PARAM_VALUE.NBITS_MININDEX { PARAM_VALUE.NBITS_MININDEX } {
	# Procedure called to update NBITS_MININDEX when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_MININDEX { PARAM_VALUE.NBITS_MININDEX } {
	# Procedure called to validate NBITS_MININDEX
	return true
}

proc update_PARAM_VALUE.NBITS_NB_DLL_STEPS { PARAM_VALUE.NBITS_NB_DLL_STEPS } {
	# Procedure called to update NBITS_NB_DLL_STEPS when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_NB_DLL_STEPS { PARAM_VALUE.NBITS_NB_DLL_STEPS } {
	# Procedure called to validate NBITS_NB_DLL_STEPS
	return true
}

proc update_PARAM_VALUE.NBITS_OUTPUT_DATA { PARAM_VALUE.NBITS_OUTPUT_DATA } {
	# Procedure called to update NBITS_OUTPUT_DATA when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_OUTPUT_DATA { PARAM_VALUE.NBITS_OUTPUT_DATA } {
	# Procedure called to validate NBITS_OUTPUT_DATA
	return true
}

proc update_PARAM_VALUE.NB_OF_PIXEL { PARAM_VALUE.NB_OF_PIXEL } {
	# Procedure called to update NB_OF_PIXEL when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NB_OF_PIXEL { PARAM_VALUE.NB_OF_PIXEL } {
	# Procedure called to validate NB_OF_PIXEL
	return true
}


proc update_MODELPARAM_VALUE.NB_OF_PIXEL { MODELPARAM_VALUE.NB_OF_PIXEL PARAM_VALUE.NB_OF_PIXEL } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NB_OF_PIXEL}] ${MODELPARAM_VALUE.NB_OF_PIXEL}
}

proc update_MODELPARAM_VALUE.NBITS_DATA_IN { MODELPARAM_VALUE.NBITS_DATA_IN PARAM_VALUE.NBITS_DATA_IN } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_DATA_IN}] ${MODELPARAM_VALUE.NBITS_DATA_IN}
}

proc update_MODELPARAM_VALUE.NBITS_LENGTH { MODELPARAM_VALUE.NBITS_LENGTH PARAM_VALUE.NBITS_LENGTH } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_LENGTH}] ${MODELPARAM_VALUE.NBITS_LENGTH}
}

proc update_MODELPARAM_VALUE.NBITS_LINE_LENGTH { MODELPARAM_VALUE.NBITS_LINE_LENGTH PARAM_VALUE.NBITS_LINE_LENGTH } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_LINE_LENGTH}] ${MODELPARAM_VALUE.NBITS_LINE_LENGTH}
}

proc update_MODELPARAM_VALUE.NBITS_ADDR_IMG_BRAM { MODELPARAM_VALUE.NBITS_ADDR_IMG_BRAM PARAM_VALUE.NBITS_ADDR_IMG_BRAM } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_ADDR_IMG_BRAM}] ${MODELPARAM_VALUE.NBITS_ADDR_IMG_BRAM}
}

proc update_MODELPARAM_VALUE.NBITS_ADDR_BRAM_DCS { MODELPARAM_VALUE.NBITS_ADDR_BRAM_DCS PARAM_VALUE.NBITS_ADDR_BRAM_DCS } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_ADDR_BRAM_DCS}] ${MODELPARAM_VALUE.NBITS_ADDR_BRAM_DCS}
}

proc update_MODELPARAM_VALUE.NBITS_DATA_BRAM_DCS { MODELPARAM_VALUE.NBITS_DATA_BRAM_DCS PARAM_VALUE.NBITS_DATA_BRAM_DCS } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_DATA_BRAM_DCS}] ${MODELPARAM_VALUE.NBITS_DATA_BRAM_DCS}
}

proc update_MODELPARAM_VALUE.MEM_SIZE_BRAM_DCS { MODELPARAM_VALUE.MEM_SIZE_BRAM_DCS PARAM_VALUE.MEM_SIZE_BRAM_DCS } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.MEM_SIZE_BRAM_DCS}] ${MODELPARAM_VALUE.MEM_SIZE_BRAM_DCS}
}

proc update_MODELPARAM_VALUE.NBITS_ADDR_FIFO0 { MODELPARAM_VALUE.NBITS_ADDR_FIFO0 PARAM_VALUE.NBITS_ADDR_FIFO0 } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_ADDR_FIFO0}] ${MODELPARAM_VALUE.NBITS_ADDR_FIFO0}
}

proc update_MODELPARAM_VALUE.NBITS_ADDR_FIFO1 { MODELPARAM_VALUE.NBITS_ADDR_FIFO1 PARAM_VALUE.NBITS_ADDR_FIFO1 } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_ADDR_FIFO1}] ${MODELPARAM_VALUE.NBITS_ADDR_FIFO1}
}

proc update_MODELPARAM_VALUE.NBITS_DIST_OUT { MODELPARAM_VALUE.NBITS_DIST_OUT PARAM_VALUE.NBITS_DIST_OUT } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_DIST_OUT}] ${MODELPARAM_VALUE.NBITS_DIST_OUT}
}

proc update_MODELPARAM_VALUE.NBITS_AMP_OUT { MODELPARAM_VALUE.NBITS_AMP_OUT PARAM_VALUE.NBITS_AMP_OUT } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_AMP_OUT}] ${MODELPARAM_VALUE.NBITS_AMP_OUT}
}

proc update_MODELPARAM_VALUE.NBITS_MININDEX { MODELPARAM_VALUE.NBITS_MININDEX PARAM_VALUE.NBITS_MININDEX } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_MININDEX}] ${MODELPARAM_VALUE.NBITS_MININDEX}
}

proc update_MODELPARAM_VALUE.NBITS_CAL_RAM { MODELPARAM_VALUE.NBITS_CAL_RAM PARAM_VALUE.NBITS_CAL_RAM } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_CAL_RAM}] ${MODELPARAM_VALUE.NBITS_CAL_RAM}
}

proc update_MODELPARAM_VALUE.NBITS_DIST_INDEX { MODELPARAM_VALUE.NBITS_DIST_INDEX PARAM_VALUE.NBITS_DIST_INDEX } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_DIST_INDEX}] ${MODELPARAM_VALUE.NBITS_DIST_INDEX}
}

proc update_MODELPARAM_VALUE.NBITS_DIST_MEM_CTRL { MODELPARAM_VALUE.NBITS_DIST_MEM_CTRL PARAM_VALUE.NBITS_DIST_MEM_CTRL } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_DIST_MEM_CTRL}] ${MODELPARAM_VALUE.NBITS_DIST_MEM_CTRL}
}

proc update_MODELPARAM_VALUE.NBITS_DLL_CORR { MODELPARAM_VALUE.NBITS_DLL_CORR PARAM_VALUE.NBITS_DLL_CORR } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_DLL_CORR}] ${MODELPARAM_VALUE.NBITS_DLL_CORR}
}

proc update_MODELPARAM_VALUE.NBITS_NB_DLL_STEPS { MODELPARAM_VALUE.NBITS_NB_DLL_STEPS PARAM_VALUE.NBITS_NB_DLL_STEPS } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_NB_DLL_STEPS}] ${MODELPARAM_VALUE.NBITS_NB_DLL_STEPS}
}

proc update_MODELPARAM_VALUE.NBITS_OUTPUT_DATA { MODELPARAM_VALUE.NBITS_OUTPUT_DATA PARAM_VALUE.NBITS_OUTPUT_DATA } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_OUTPUT_DATA}] ${MODELPARAM_VALUE.NBITS_OUTPUT_DATA}
}

proc update_MODELPARAM_VALUE.NBITS_AL_COMP { MODELPARAM_VALUE.NBITS_AL_COMP PARAM_VALUE.NBITS_AL_COMP } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_AL_COMP}] ${MODELPARAM_VALUE.NBITS_AL_COMP}
}

proc update_MODELPARAM_VALUE.ENABLE_INPUT_FIFO { MODELPARAM_VALUE.ENABLE_INPUT_FIFO PARAM_VALUE.ENABLE_INPUT_FIFO } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.ENABLE_INPUT_FIFO}] ${MODELPARAM_VALUE.ENABLE_INPUT_FIFO}
}

proc update_MODELPARAM_VALUE.ENABLE_DELAY_NB { MODELPARAM_VALUE.ENABLE_DELAY_NB PARAM_VALUE.ENABLE_DELAY_NB } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.ENABLE_DELAY_NB}] ${MODELPARAM_VALUE.ENABLE_DELAY_NB}
}

proc update_MODELPARAM_VALUE.NBITS_GS_RAM { MODELPARAM_VALUE.NBITS_GS_RAM PARAM_VALUE.NBITS_GS_RAM } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_GS_RAM}] ${MODELPARAM_VALUE.NBITS_GS_RAM}
}

proc update_MODELPARAM_VALUE.NBITS_MAX_GS_RAM_DATA_IN { MODELPARAM_VALUE.NBITS_MAX_GS_RAM_DATA_IN PARAM_VALUE.NBITS_MAX_GS_RAM_DATA_IN } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_MAX_GS_RAM_DATA_IN}] ${MODELPARAM_VALUE.NBITS_MAX_GS_RAM_DATA_IN}
}

