# Definitional proc to organize widgets for parameters.
proc init_gui { IPINST } {
  ipgui::add_param $IPINST -name "Component_Name"
  #Adding Page
  set Page_0 [ipgui::add_page $IPINST -name "Page 0"]
  ipgui::add_param $IPINST -name "C_M00_AXI_ADDR_WIDTH" -parent ${Page_0}
  ipgui::add_param $IPINST -name "C_M00_AXI_BURST_LEN" -parent ${Page_0}
  ipgui::add_param $IPINST -name "C_M00_AXI_DATA_WIDTH" -parent ${Page_0}
  ipgui::add_param $IPINST -name "C_M00_AXI_ID_WIDTH" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_INPUT" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_BRAM_ADDR" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_LENGTH" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_RNEXT_DEL" -parent ${Page_0}
  ipgui::add_param $IPINST -name "NBITS_WNEXT_DEL" -parent ${Page_0}
  ipgui::add_param $IPINST -name "PRELOAD_RD_PULSE" -parent ${Page_0}
  ipgui::add_param $IPINST -name "ENABLE_DBG_CNTER" -parent ${Page_0}
  ipgui::add_param $IPINST -name "ENABLE_DBG_CNTER_AXI" -parent ${Page_0}


}

proc update_PARAM_VALUE.C_M00_AXI_ADDR_WIDTH { PARAM_VALUE.C_M00_AXI_ADDR_WIDTH } {
	# Procedure called to update C_M00_AXI_ADDR_WIDTH when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.C_M00_AXI_ADDR_WIDTH { PARAM_VALUE.C_M00_AXI_ADDR_WIDTH } {
	# Procedure called to validate C_M00_AXI_ADDR_WIDTH
	return true
}

proc update_PARAM_VALUE.C_M00_AXI_BURST_LEN { PARAM_VALUE.C_M00_AXI_BURST_LEN } {
	# Procedure called to update C_M00_AXI_BURST_LEN when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.C_M00_AXI_BURST_LEN { PARAM_VALUE.C_M00_AXI_BURST_LEN } {
	# Procedure called to validate C_M00_AXI_BURST_LEN
	return true
}

proc update_PARAM_VALUE.C_M00_AXI_DATA_WIDTH { PARAM_VALUE.C_M00_AXI_DATA_WIDTH } {
	# Procedure called to update C_M00_AXI_DATA_WIDTH when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.C_M00_AXI_DATA_WIDTH { PARAM_VALUE.C_M00_AXI_DATA_WIDTH } {
	# Procedure called to validate C_M00_AXI_DATA_WIDTH
	return true
}

proc update_PARAM_VALUE.C_M00_AXI_ID_WIDTH { PARAM_VALUE.C_M00_AXI_ID_WIDTH } {
	# Procedure called to update C_M00_AXI_ID_WIDTH when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.C_M00_AXI_ID_WIDTH { PARAM_VALUE.C_M00_AXI_ID_WIDTH } {
	# Procedure called to validate C_M00_AXI_ID_WIDTH
	return true
}

proc update_PARAM_VALUE.ENABLE_DBG_CNTER { PARAM_VALUE.ENABLE_DBG_CNTER } {
	# Procedure called to update ENABLE_DBG_CNTER when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.ENABLE_DBG_CNTER { PARAM_VALUE.ENABLE_DBG_CNTER } {
	# Procedure called to validate ENABLE_DBG_CNTER
	return true
}

proc update_PARAM_VALUE.ENABLE_DBG_CNTER_AXI { PARAM_VALUE.ENABLE_DBG_CNTER_AXI } {
	# Procedure called to update ENABLE_DBG_CNTER_AXI when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.ENABLE_DBG_CNTER_AXI { PARAM_VALUE.ENABLE_DBG_CNTER_AXI } {
	# Procedure called to validate ENABLE_DBG_CNTER_AXI
	return true
}

proc update_PARAM_VALUE.NBITS_BRAM_ADDR { PARAM_VALUE.NBITS_BRAM_ADDR } {
	# Procedure called to update NBITS_BRAM_ADDR when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_BRAM_ADDR { PARAM_VALUE.NBITS_BRAM_ADDR } {
	# Procedure called to validate NBITS_BRAM_ADDR
	return true
}

proc update_PARAM_VALUE.NBITS_INPUT { PARAM_VALUE.NBITS_INPUT } {
	# Procedure called to update NBITS_INPUT when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_INPUT { PARAM_VALUE.NBITS_INPUT } {
	# Procedure called to validate NBITS_INPUT
	return true
}

proc update_PARAM_VALUE.NBITS_LENGTH { PARAM_VALUE.NBITS_LENGTH } {
	# Procedure called to update NBITS_LENGTH when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_LENGTH { PARAM_VALUE.NBITS_LENGTH } {
	# Procedure called to validate NBITS_LENGTH
	return true
}

proc update_PARAM_VALUE.NBITS_RNEXT_DEL { PARAM_VALUE.NBITS_RNEXT_DEL } {
	# Procedure called to update NBITS_RNEXT_DEL when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_RNEXT_DEL { PARAM_VALUE.NBITS_RNEXT_DEL } {
	# Procedure called to validate NBITS_RNEXT_DEL
	return true
}

proc update_PARAM_VALUE.NBITS_WNEXT_DEL { PARAM_VALUE.NBITS_WNEXT_DEL } {
	# Procedure called to update NBITS_WNEXT_DEL when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.NBITS_WNEXT_DEL { PARAM_VALUE.NBITS_WNEXT_DEL } {
	# Procedure called to validate NBITS_WNEXT_DEL
	return true
}

proc update_PARAM_VALUE.PRELOAD_RD_PULSE { PARAM_VALUE.PRELOAD_RD_PULSE } {
	# Procedure called to update PRELOAD_RD_PULSE when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.PRELOAD_RD_PULSE { PARAM_VALUE.PRELOAD_RD_PULSE } {
	# Procedure called to validate PRELOAD_RD_PULSE
	return true
}


proc update_MODELPARAM_VALUE.NBITS_INPUT { MODELPARAM_VALUE.NBITS_INPUT PARAM_VALUE.NBITS_INPUT } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_INPUT}] ${MODELPARAM_VALUE.NBITS_INPUT}
}

proc update_MODELPARAM_VALUE.NBITS_LENGTH { MODELPARAM_VALUE.NBITS_LENGTH PARAM_VALUE.NBITS_LENGTH } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_LENGTH}] ${MODELPARAM_VALUE.NBITS_LENGTH}
}

proc update_MODELPARAM_VALUE.NBITS_BRAM_ADDR { MODELPARAM_VALUE.NBITS_BRAM_ADDR PARAM_VALUE.NBITS_BRAM_ADDR } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_BRAM_ADDR}] ${MODELPARAM_VALUE.NBITS_BRAM_ADDR}
}

proc update_MODELPARAM_VALUE.C_M00_AXI_BURST_LEN { MODELPARAM_VALUE.C_M00_AXI_BURST_LEN PARAM_VALUE.C_M00_AXI_BURST_LEN } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.C_M00_AXI_BURST_LEN}] ${MODELPARAM_VALUE.C_M00_AXI_BURST_LEN}
}

proc update_MODELPARAM_VALUE.C_M00_AXI_ID_WIDTH { MODELPARAM_VALUE.C_M00_AXI_ID_WIDTH PARAM_VALUE.C_M00_AXI_ID_WIDTH } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.C_M00_AXI_ID_WIDTH}] ${MODELPARAM_VALUE.C_M00_AXI_ID_WIDTH}
}

proc update_MODELPARAM_VALUE.C_M00_AXI_ADDR_WIDTH { MODELPARAM_VALUE.C_M00_AXI_ADDR_WIDTH PARAM_VALUE.C_M00_AXI_ADDR_WIDTH } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.C_M00_AXI_ADDR_WIDTH}] ${MODELPARAM_VALUE.C_M00_AXI_ADDR_WIDTH}
}

proc update_MODELPARAM_VALUE.C_M00_AXI_DATA_WIDTH { MODELPARAM_VALUE.C_M00_AXI_DATA_WIDTH PARAM_VALUE.C_M00_AXI_DATA_WIDTH } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.C_M00_AXI_DATA_WIDTH}] ${MODELPARAM_VALUE.C_M00_AXI_DATA_WIDTH}
}

proc update_MODELPARAM_VALUE.NBITS_WNEXT_DEL { MODELPARAM_VALUE.NBITS_WNEXT_DEL PARAM_VALUE.NBITS_WNEXT_DEL } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_WNEXT_DEL}] ${MODELPARAM_VALUE.NBITS_WNEXT_DEL}
}

proc update_MODELPARAM_VALUE.ENABLE_DBG_CNTER { MODELPARAM_VALUE.ENABLE_DBG_CNTER PARAM_VALUE.ENABLE_DBG_CNTER } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.ENABLE_DBG_CNTER}] ${MODELPARAM_VALUE.ENABLE_DBG_CNTER}
}

proc update_MODELPARAM_VALUE.NBITS_RNEXT_DEL { MODELPARAM_VALUE.NBITS_RNEXT_DEL PARAM_VALUE.NBITS_RNEXT_DEL } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.NBITS_RNEXT_DEL}] ${MODELPARAM_VALUE.NBITS_RNEXT_DEL}
}

proc update_MODELPARAM_VALUE.ENABLE_DBG_CNTER_AXI { MODELPARAM_VALUE.ENABLE_DBG_CNTER_AXI PARAM_VALUE.ENABLE_DBG_CNTER_AXI } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.ENABLE_DBG_CNTER_AXI}] ${MODELPARAM_VALUE.ENABLE_DBG_CNTER_AXI}
}

proc update_MODELPARAM_VALUE.PRELOAD_RD_PULSE { MODELPARAM_VALUE.PRELOAD_RD_PULSE PARAM_VALUE.PRELOAD_RD_PULSE } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.PRELOAD_RD_PULSE}] ${MODELPARAM_VALUE.PRELOAD_RD_PULSE}
}

