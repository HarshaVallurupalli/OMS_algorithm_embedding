# README to build & modify a vivado project
> ESPROS Photonics AG
> 04.10.2018, msc@espros.com


## TCL commands to re-generate the Vivado & Block-Design
1) Start Vivado

2) In the TCL console change the directory to the path of the file "create_project.tcl"

3) Type the following command:
    source ./create_project.tcl

4) After the blockdesing has been built, close it and run the synthesis, implementation & bitstream generation

5) Export -> Export Bitstream File 


## TCL command to create the blockdesign generation script
1) Open the block design and validate it

2) Type the following command into the TCL console (Note that the path must match the directory of the file "create_project.tcl"
    write_bd_tcl -no_mig_contents -no_ip_version -force ./src/bd/create_tofcam660_bd_jss_oms660.tcl

    
## TCL command to create the Vivado Project generation script
1) In the TCL console change the directory to the path of the file "create_project.tcl"

2) Type the following command into the TCL console:
    write_project_tcl -no_copy_sources -use_bd_files -force ./create_project.tcl

3) Manually add the generation of the block design into generated TCL scipt. 
   The command must be located before "design_1.bd" is used in the script.
   Note that file comparision shall be used to add this command.
    source $origin_dir/src/bd/create_tofcam660_bd_jss_oms660.tcl
    
4) Manually modify the block design build strategy ("Global" instead of "Out of context per IP")
   This command can be located at the end of the script.
    set_property synth_checkpoint_mode None [get_files  ./epc660/epc660.srcs/sources_1/bd/design_1/design_1.bd]
    
