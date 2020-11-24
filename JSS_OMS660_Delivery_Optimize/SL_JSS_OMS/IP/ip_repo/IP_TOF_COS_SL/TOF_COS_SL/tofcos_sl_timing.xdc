# --------------------------------
# General
# --------------------------------
set_input_delay -clock [get_clocks *] 0.250 [all_inputs]
set_output_delay -clock [get_clocks *] -network_latency_included 0.250 [all_outputs]

# --------------------------------
# image bin
# --------------------------------
set_multicycle_path -setup -to [get_pins {i_bd/image_bin_0/U0/data_out_DO_reg[*]/D}] 2
set_multicycle_path -hold -to [get_pins {i_bd/image_bin_0/U0/data_out_DO_reg[*]/D}] 1

# --------------------------------
# dist_offset
# --------------------------------
set_multicycle_path -setup -to [get_pins {i_bd/dist_offset_0/U0/dist_DO_reg[*]/D}] 2
set_multicycle_path -hold -to [get_pins {i_bd/dist_offset_0/U0/dist_DO_reg[*]/D}] 1
set_multicycle_path -setup -to [get_pins {i_bd/dist_offset_0/U0/reg_status_D_reg[*]/D}] 2
set_multicycle_path -hold -to [get_pins {i_bd/dist_offset_0/U0/reg_status_D_reg[*]/D}] 1
set_multicycle_path -setup -to [get_pins {i_bd/dist_offset_0/U0/mult_D_reg/B[*]}] 2
set_multicycle_path -hold -to [get_pins {i_bd/dist_offset_0/U0/mult_D_reg/B[*]}] 1
set_multicycle_path -setup -to [get_pins {i_bd/dist_offset_0/U0/mult_D_reg/RSTB}] 2
set_multicycle_path -hold -to [get_pins {i_bd/dist_offset_0/U0/mult_D_reg/RSTB}] 1

# --------------------------------
# ALU
# --------------------------------
set_multicycle_path -setup -from [get_pins {i_bd/alu_0/U0/sqroot_in_reg[*]/C}] -to [get_pins {i_bd/alu_0/U0/ARG__0/A[*]}] 5
set_multicycle_path -hold -from [get_pins {i_bd/alu_0/U0/sqroot_in_reg[*]/C}] -to [get_pins {i_bd/alu_0/U0/ARG__0/A[*]}] 4
set_multicycle_path -setup -from [get_pins {i_bd/alu_0/U0/index_reg_rep[*]/C}] -to [get_pins {i_bd/alu_0/U0/ARG/A[*]}] 5
set_multicycle_path -hold -from [get_pins {i_bd/alu_0/U0/index_reg_rep[*]/C}] -to [get_pins {i_bd/alu_0/U0/ARG/A[*]}] 4
set_multicycle_path -setup -from [get_pins {i_bd/alu_0/U0/index_reg_rep[*]_rep/C}] -to [get_pins {i_bd/alu_0/U0/ARG/A[*]}] 5
set_multicycle_path -hold -from [get_pins {i_bd/alu_0/U0/index_reg_rep[*]_rep/C}] -to [get_pins {i_bd/alu_0/U0/ARG/A[*]}] 4
set_multicycle_path -setup -from [get_pins {i_bd/alu_0/U0/index_reg_rep[*]_rep__*/C}] -to [get_pins {i_bd/alu_0/U0/ARG/A[*]}] 5
set_multicycle_path -hold -from [get_pins {i_bd/alu_0/U0/index_reg_rep[*]_rep__*/C}] -to [get_pins {i_bd/alu_0/U0/ARG/A[*]}] 4
set_multicycle_path -setup -from [get_pins i_bd/alu_0/U0/diff_swap_d_reg/C] -to [get_pins {i_bd/alu_0/U0/ARG/A[*]}] 5
set_multicycle_path -hold -from [get_pins i_bd/alu_0/U0/diff_swap_d_reg/C] -to [get_pins {i_bd/alu_0/U0/ARG/A[*]}] 4
