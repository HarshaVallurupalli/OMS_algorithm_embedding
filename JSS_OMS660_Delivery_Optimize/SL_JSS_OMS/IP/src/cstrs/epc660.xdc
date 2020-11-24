#add clock constraints
create_clock –name myClk1 –period 3 [get_ports dclk_in] 
create_clock –name myClk2 –period 3 [get_ports dclk_in1]
# --------------------------------
# General
# --------------------------------
set_input_delay -clock [get_clocks *] 0.250 [all_inputs]
set_output_delay -clock [get_clocks *] -network_latency_included 0.250 [all_outputs]

# --------------------------------
# image bin
# --------------------------------
set_multicycle_path -setup -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_image_bin/data_out_DO_reg[*]/D}] 2
set_multicycle_path -hold -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_image_bin/data_out_DO_reg[*]/D}] 1

# --------------------------------
# dist_offset
# --------------------------------
set_multicycle_path -setup -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_dist_offset_correction/dist_DO_reg[*]/D}] 2
set_multicycle_path -hold -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_dist_offset_correction/dist_DO_reg[*]/D}] 1
set_multicycle_path -setup -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_dist_offset_correction/reg_status_D_reg[*]/D}] 2
set_multicycle_path -hold -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_dist_offset_correction/reg_status_D_reg[*]/D}] 1
set_multicycle_path -setup -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_dist_offset_correction/mult_D_reg/B[*]}] 2
set_multicycle_path -hold -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_dist_offset_correction/mult_D_reg/B[*]}] 1
set_multicycle_path -setup -to [get_pins i_bd/TOF_cos_sl_0/U0/i_dist_offset_correction/mult_D_reg/RSTB] 2
set_multicycle_path -hold -to [get_pins i_bd/TOF_cos_sl_0/U0/i_dist_offset_correction/mult_D_reg/RSTB] 1

# --------------------------------
# reg_bank
# --------------------------------
set_multicycle_path -setup -from [get_pins {i_bd/reg_bank_0/U0/reg_bank_v1_0_S00_AXI_inst/slv_reg*_reg[*]/C}] 5
set_multicycle_path -hold -from [get_pins {i_bd/reg_bank_0/U0/reg_bank_v1_0_S00_AXI_inst/slv_reg*_reg[*]/C}] 4
set_multicycle_path -setup -to [get_pins {i_bd/reg_bank_0/U0/reg_bank_v1_0_S00_AXI_inst/slv_reg*_reg[*]/C}] 5
set_multicycle_path -hold  -to [get_pins {i_bd/reg_bank_0/U0/reg_bank_v1_0_S00_AXI_inst/slv_reg*_reg[*]/C}] 4

# --------------------------------
# ALU
# --------------------------------
set_multicycle_path -setup -from [get_pins {i_bd/TOF_cos_sl_0/U0/i_alu/sqroot_in_reg[*]/C}] -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_alu/ARG__0/A[*]}] 5
set_multicycle_path -hold -from [get_pins {i_bd/TOF_cos_sl_0/U0/i_alu/sqroot_in_reg[*]/C}] -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_alu/ARG__0/A[*]}] 4
set_multicycle_path -setup -from [get_pins {i_bd/TOF_cos_sl_0/U0/i_alu/index_reg_rep[*]/C}] -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_alu/ARG/A[*]}] 5
set_multicycle_path -hold -from [get_pins {i_bd/TOF_cos_sl_0/U0/i_alu/index_reg_rep[*]/C}] -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_alu/ARG/A[*]}] 4
set_multicycle_path -setup -from [get_pins {i_bd/TOF_cos_sl_0/U0/i_alu/index_reg_rep[*]_rep/C}] -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_alu/ARG/A[*]}] 5
set_multicycle_path -hold -from [get_pins {i_bd/TOF_cos_sl_0/U0/i_alu/index_reg_rep[*]_rep/C}] -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_alu/ARG/A[*]}] 4
set_multicycle_path -setup -from [get_pins {i_bd/TOF_cos_sl_0/U0/i_alu/index_reg_rep[*]_rep__*/C}] -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_alu/ARG/A[*]}] 5
set_multicycle_path -hold -from [get_pins {i_bd/TOF_cos_sl_0/U0/i_alu/index_reg_rep[*]_rep__*/C}] -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_alu/ARG/A[*]}] 4
set_multicycle_path -setup -from [get_pins i_bd/TOF_cos_sl_0/U0/i_alu/diff_swap_d_reg/C] -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_alu/ARG/A[*]}] 5
set_multicycle_path -hold -from [get_pins i_bd/TOF_cos_sl_0/U0/i_alu/diff_swap_d_reg/C] -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_alu/ARG/A[*]}] 4

# --------------------------------
# GS Compensation
# --------------------------------
set_multicycle_path -setup -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_gs_compensation/gs_data_out_DO_reg[*]/D}] 3
set_multicycle_path -hold -to [get_pins {i_bd/TOF_cos_sl_0/U0/i_gs_compensation/gs_data_out_DO_reg[*]/D}] 2

# --------------------------------
# ReadRAM
# --------------------------------
set_multicycle_path -setup -to [get_pins {i_bd/readRam_burst_1/U0/read_addr_D1/A[*]}] 4
set_multicycle_path -hold -to [get_pins {i_bd/readRam_burst_1/U0/read_addr_D1/A[*]}] 3
set_multicycle_path -setup -to [get_pins {i_bd/readRam_burst_1/U0/pixel_cnt_D_reg[*]/D}] 4
set_multicycle_path -hold -to [get_pins {i_bd/readRam_burst_1/U0/pixel_cnt_D_reg[*]/D}] 3