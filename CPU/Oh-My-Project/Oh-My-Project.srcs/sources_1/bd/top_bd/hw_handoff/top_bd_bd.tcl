
################################################################
# This is a generated script based on design: top_bd
#
# Though there are limitations about the generated script,
# the main purpose of this utility is to make learning
# IP Integrator Tcl commands easier.
################################################################

namespace eval _tcl {
proc get_script_folder {} {
   set script_path [file normalize [info script]]
   set script_folder [file dirname $script_path]
   return $script_folder
}
}
variable script_folder
set script_folder [_tcl::get_script_folder]

################################################################
# Check if script is running in correct Vivado version.
################################################################
set scripts_vivado_version 2016.2
set current_vivado_version [version -short]

if { [string first $scripts_vivado_version $current_vivado_version] == -1 } {
   puts ""
   catch {common::send_msg_id "BD_TCL-109" "ERROR" "This script was generated using Vivado <$scripts_vivado_version> and is being run in <$current_vivado_version> of Vivado. Please run the script in Vivado <$scripts_vivado_version> then open the design in Vivado <$current_vivado_version>. Upgrade the design by running \"Tools => Report => Report IP Status...\", then run write_bd_tcl to create an updated script."}

   return 1
}

################################################################
# START
################################################################

# To test this script, run the following commands from Vivado Tcl console:
# source top_bd_script.tcl


# The design that will be created by this Tcl script contains the following 
# module references:
# input16, input31, instruct_split, my_control, my_expand32, my_expand32, my_expend, my_pc, my_right_shift2, my_shift2, my_shift2, my_simple_add

# Please add the sources of those modules before sourcing this Tcl script.

# If there is no project opened, this script will create a
# project, but make sure you do not have an existing project
# <./myproj/project_1.xpr> in the current working folder.

set list_projs [get_projects -quiet]
if { $list_projs eq "" } {
   create_project project_1 myproj -part xc7a100tcsg324-1
}


# CHANGE DESIGN NAME HERE
set design_name top_bd

# If you do not already have an existing IP Integrator design open,
# you can create a design using the following command:
#    create_bd_design $design_name

# Creating design if needed
set errMsg ""
set nRet 0

set cur_design [current_bd_design -quiet]
set list_cells [get_bd_cells -quiet]

if { ${design_name} eq "" } {
   # USE CASES:
   #    1) Design_name not set

   set errMsg "Please set the variable <design_name> to a non-empty value."
   set nRet 1

} elseif { ${cur_design} ne "" && ${list_cells} eq "" } {
   # USE CASES:
   #    2): Current design opened AND is empty AND names same.
   #    3): Current design opened AND is empty AND names diff; design_name NOT in project.
   #    4): Current design opened AND is empty AND names diff; design_name exists in project.

   if { $cur_design ne $design_name } {
      common::send_msg_id "BD_TCL-001" "INFO" "Changing value of <design_name> from <$design_name> to <$cur_design> since current design is empty."
      set design_name [get_property NAME $cur_design]
   }
   common::send_msg_id "BD_TCL-002" "INFO" "Constructing design in IPI design <$cur_design>..."

} elseif { ${cur_design} ne "" && $list_cells ne "" && $cur_design eq $design_name } {
   # USE CASES:
   #    5) Current design opened AND has components AND same names.

   set errMsg "Design <$design_name> already exists in your project, please set the variable <design_name> to another value."
   set nRet 1
} elseif { [get_files -quiet ${design_name}.bd] ne "" } {
   # USE CASES: 
   #    6) Current opened design, has components, but diff names, design_name exists in project.
   #    7) No opened design, design_name exists in project.

   set errMsg "Design <$design_name> already exists in your project, please set the variable <design_name> to another value."
   set nRet 2

} else {
   # USE CASES:
   #    8) No opened design, design_name not in project.
   #    9) Current opened design, has components, but diff names, design_name not in project.

   common::send_msg_id "BD_TCL-003" "INFO" "Currently there is no design <$design_name> in project, so creating one..."

   create_bd_design $design_name

   common::send_msg_id "BD_TCL-004" "INFO" "Making design <$design_name> as current_bd_design."
   current_bd_design $design_name

}

common::send_msg_id "BD_TCL-005" "INFO" "Currently the variable <design_name> is equal to \"$design_name\"."

if { $nRet != 0 } {
   catch {common::send_msg_id "BD_TCL-114" "ERROR" $errMsg}
   return $nRet
}

##################################################################
# DESIGN PROCs
##################################################################



# Procedure to create entire design; Provide argument to make
# procedure reusable. If parentCell is "", will use root.
proc create_root_design { parentCell } {

  variable script_folder

  if { $parentCell eq "" } {
     set parentCell [get_bd_cells /]
  }

  # Get object for parentCell
  set parentObj [get_bd_cells $parentCell]
  if { $parentObj == "" } {
     catch {common::send_msg_id "BD_TCL-100" "ERROR" "Unable to find parent cell <$parentCell>!"}
     return
  }

  # Make sure parentObj is hier blk
  set parentType [get_property TYPE $parentObj]
  if { $parentType ne "hier" } {
     catch {common::send_msg_id "BD_TCL-101" "ERROR" "Parent <$parentObj> has TYPE = <$parentType>. Expected to be <hier>."}
     return
  }

  # Save current instance; Restore later
  set oldCurInst [current_bd_instance .]

  # Set parent object as current
  current_bd_instance $parentObj


  # Create interface ports

  # Create ports
  set clk [ create_bd_port -dir I -type clk clk ]
  set_property -dict [ list \
CONFIG.FREQ_HZ {1000000} \
 ] $clk
  set pc_reset [ create_bd_port -dir I pc_reset ]
  set res_reset [ create_bd_port -dir I res_reset ]

  # Create instance: alu_bd_1, and set properties
  set alu_bd_1 [ create_bd_cell -type ip -vlnv CSE:CSE:alu_bd:1.0 alu_bd_1 ]

  # Create instance: andgate_0, and set properties
  set andgate_0 [ create_bd_cell -type ip -vlnv CSE:CSE:andgate:1.0 andgate_0 ]
  set_property -dict [ list \
CONFIG.WIDTH {1} \
 ] $andgate_0

  # Create instance: andgate_1, and set properties
  set andgate_1 [ create_bd_cell -type ip -vlnv CSE:CSE:andgate:1.0 andgate_1 ]
  set_property -dict [ list \
CONFIG.WIDTH {1} \
 ] $andgate_1

  # Create instance: dist_mem_gen_0, and set properties
  set dist_mem_gen_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:dist_mem_gen:8.0 dist_mem_gen_0 ]
  set_property -dict [ list \
CONFIG.coefficient_file {../../../../../../../../../MyCoe/test_prgmip32.coe} \
CONFIG.data_width {32} \
CONFIG.depth {32768} \
CONFIG.input_options {non_registered} \
CONFIG.memory_type {rom} \
 ] $dist_mem_gen_0

  # Create instance: dist_mem_gen_1, and set properties
  set dist_mem_gen_1 [ create_bd_cell -type ip -vlnv xilinx.com:ip:dist_mem_gen:8.0 dist_mem_gen_1 ]
  set_property -dict [ list \
CONFIG.coefficient_file {../../../../../../../../../MyCoe/test_dmem32.coe} \
CONFIG.data_width {32} \
CONFIG.depth {65536} \
 ] $dist_mem_gen_1

  # Create instance: input16_0, and set properties
  set block_name input16
  set block_cell_name input16_0
  if { [catch {set input16_0 [create_bd_cell -type module -reference $block_name $block_cell_name] } errmsg] } {
     catch {common::send_msg_id "BD_TCL-105" "ERROR" "Unable to add referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   } elseif { $input16_0 eq "" } {
     catch {common::send_msg_id "BD_TCL-106" "ERROR" "Unable to referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   }
  
  # Create instance: input31_0, and set properties
  set block_name input31
  set block_cell_name input31_0
  if { [catch {set input31_0 [create_bd_cell -type module -reference $block_name $block_cell_name] } errmsg] } {
     catch {common::send_msg_id "BD_TCL-105" "ERROR" "Unable to add referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   } elseif { $input31_0 eq "" } {
     catch {common::send_msg_id "BD_TCL-106" "ERROR" "Unable to referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   }
  
  # Create instance: instruct_split_0, and set properties
  set block_name instruct_split
  set block_cell_name instruct_split_0
  if { [catch {set instruct_split_0 [create_bd_cell -type module -reference $block_name $block_cell_name] } errmsg] } {
     catch {common::send_msg_id "BD_TCL-105" "ERROR" "Unable to add referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   } elseif { $instruct_split_0 eq "" } {
     catch {common::send_msg_id "BD_TCL-106" "ERROR" "Unable to referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   }
  
  # Create instance: mux2to1_0, and set properties
  set mux2to1_0 [ create_bd_cell -type ip -vlnv CSE:CSE:mux2to1:1.0 mux2to1_0 ]
  set_property -dict [ list \
CONFIG.WIDTH {5} \
 ] $mux2to1_0

  # Create instance: mux2to1_1, and set properties
  set mux2to1_1 [ create_bd_cell -type ip -vlnv CSE:CSE:mux2to1:1.0 mux2to1_1 ]
  set_property -dict [ list \
CONFIG.WIDTH {5} \
 ] $mux2to1_1

  # Create instance: mux2to1_2, and set properties
  set mux2to1_2 [ create_bd_cell -type ip -vlnv CSE:CSE:mux2to1:1.0 mux2to1_2 ]
  set_property -dict [ list \
CONFIG.WIDTH {32} \
 ] $mux2to1_2

  # Create instance: mux2to1_3, and set properties
  set mux2to1_3 [ create_bd_cell -type ip -vlnv CSE:CSE:mux2to1:1.0 mux2to1_3 ]
  set_property -dict [ list \
CONFIG.WIDTH {32} \
 ] $mux2to1_3

  # Create instance: mux2to1_4, and set properties
  set mux2to1_4 [ create_bd_cell -type ip -vlnv CSE:CSE:mux2to1:1.0 mux2to1_4 ]
  set_property -dict [ list \
CONFIG.WIDTH {32} \
 ] $mux2to1_4

  # Create instance: mux2to1_5, and set properties
  set mux2to1_5 [ create_bd_cell -type ip -vlnv CSE:CSE:mux2to1:1.0 mux2to1_5 ]
  set_property -dict [ list \
CONFIG.WIDTH {32} \
 ] $mux2to1_5

  # Create instance: mux2to1_6, and set properties
  set mux2to1_6 [ create_bd_cell -type ip -vlnv CSE:CSE:mux2to1:1.0 mux2to1_6 ]
  set_property -dict [ list \
CONFIG.WIDTH {32} \
 ] $mux2to1_6

  # Create instance: mux2to1_7, and set properties
  set mux2to1_7 [ create_bd_cell -type ip -vlnv CSE:CSE:mux2to1:1.0 mux2to1_7 ]
  set_property -dict [ list \
CONFIG.WIDTH {32} \
 ] $mux2to1_7

  # Create instance: mux2to1_8, and set properties
  set mux2to1_8 [ create_bd_cell -type ip -vlnv CSE:CSE:mux2to1:1.0 mux2to1_8 ]
  set_property -dict [ list \
CONFIG.WIDTH {32} \
 ] $mux2to1_8

  # Create instance: mux2to1_9, and set properties
  set mux2to1_9 [ create_bd_cell -type ip -vlnv CSE:CSE:mux2to1:1.0 mux2to1_9 ]
  set_property -dict [ list \
CONFIG.WIDTH {32} \
 ] $mux2to1_9

  # Create instance: my_control_0, and set properties
  set block_name my_control
  set block_cell_name my_control_0
  if { [catch {set my_control_0 [create_bd_cell -type module -reference $block_name $block_cell_name] } errmsg] } {
     catch {common::send_msg_id "BD_TCL-105" "ERROR" "Unable to add referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   } elseif { $my_control_0 eq "" } {
     catch {common::send_msg_id "BD_TCL-106" "ERROR" "Unable to referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   }
  
  # Create instance: my_expand32_0, and set properties
  set block_name my_expand32
  set block_cell_name my_expand32_0
  if { [catch {set my_expand32_0 [create_bd_cell -type module -reference $block_name $block_cell_name] } errmsg] } {
     catch {common::send_msg_id "BD_TCL-105" "ERROR" "Unable to add referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   } elseif { $my_expand32_0 eq "" } {
     catch {common::send_msg_id "BD_TCL-106" "ERROR" "Unable to referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   }
    set_property -dict [ list \
CONFIG.WIDTH {26} \
 ] $my_expand32_0

  # Create instance: my_expand32_1, and set properties
  set block_name my_expand32
  set block_cell_name my_expand32_1
  if { [catch {set my_expand32_1 [create_bd_cell -type module -reference $block_name $block_cell_name] } errmsg] } {
     catch {common::send_msg_id "BD_TCL-105" "ERROR" "Unable to add referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   } elseif { $my_expand32_1 eq "" } {
     catch {common::send_msg_id "BD_TCL-106" "ERROR" "Unable to referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   }
    set_property -dict [ list \
CONFIG.WIDTH {5} \
 ] $my_expand32_1

  # Create instance: my_expend_0, and set properties
  set block_name my_expend
  set block_cell_name my_expend_0
  if { [catch {set my_expend_0 [create_bd_cell -type module -reference $block_name $block_cell_name] } errmsg] } {
     catch {common::send_msg_id "BD_TCL-105" "ERROR" "Unable to add referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   } elseif { $my_expend_0 eq "" } {
     catch {common::send_msg_id "BD_TCL-106" "ERROR" "Unable to referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   }
  
  # Create instance: my_pc_0, and set properties
  set block_name my_pc
  set block_cell_name my_pc_0
  if { [catch {set my_pc_0 [create_bd_cell -type module -reference $block_name $block_cell_name] } errmsg] } {
     catch {common::send_msg_id "BD_TCL-105" "ERROR" "Unable to add referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   } elseif { $my_pc_0 eq "" } {
     catch {common::send_msg_id "BD_TCL-106" "ERROR" "Unable to referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   }
  
  # Create instance: my_reg_0, and set properties
  set my_reg_0 [ create_bd_cell -type ip -vlnv CSE:CSE:my_reg:1.0 my_reg_0 ]

  # Create instance: my_right_shift2_0, and set properties
  set block_name my_right_shift2
  set block_cell_name my_right_shift2_0
  if { [catch {set my_right_shift2_0 [create_bd_cell -type module -reference $block_name $block_cell_name] } errmsg] } {
     catch {common::send_msg_id "BD_TCL-105" "ERROR" "Unable to add referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   } elseif { $my_right_shift2_0 eq "" } {
     catch {common::send_msg_id "BD_TCL-106" "ERROR" "Unable to referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   }
  
  # Create instance: my_shift2_0, and set properties
  set block_name my_shift2
  set block_cell_name my_shift2_0
  if { [catch {set my_shift2_0 [create_bd_cell -type module -reference $block_name $block_cell_name] } errmsg] } {
     catch {common::send_msg_id "BD_TCL-105" "ERROR" "Unable to add referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   } elseif { $my_shift2_0 eq "" } {
     catch {common::send_msg_id "BD_TCL-106" "ERROR" "Unable to referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   }
    set_property -dict [ list \
CONFIG.WIDTH {26} \
 ] $my_shift2_0

  # Create instance: my_shift2_1, and set properties
  set block_name my_shift2
  set block_cell_name my_shift2_1
  if { [catch {set my_shift2_1 [create_bd_cell -type module -reference $block_name $block_cell_name] } errmsg] } {
     catch {common::send_msg_id "BD_TCL-105" "ERROR" "Unable to add referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   } elseif { $my_shift2_1 eq "" } {
     catch {common::send_msg_id "BD_TCL-106" "ERROR" "Unable to referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   }
    set_property -dict [ list \
CONFIG.WIDTH {32} \
 ] $my_shift2_1

  # Create instance: my_simple_add_0, and set properties
  set block_name my_simple_add
  set block_cell_name my_simple_add_0
  if { [catch {set my_simple_add_0 [create_bd_cell -type module -reference $block_name $block_cell_name] } errmsg] } {
     catch {common::send_msg_id "BD_TCL-105" "ERROR" "Unable to add referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   } elseif { $my_simple_add_0 eq "" } {
     catch {common::send_msg_id "BD_TCL-106" "ERROR" "Unable to referenced block <$block_name>. Please add the files for ${block_name}'s definition into the project."}
     return 1
   }
    set_property -dict [ list \
CONFIG.WIDTH {32} \
 ] $my_simple_add_0

  # Create instance: notgate_0, and set properties
  set notgate_0 [ create_bd_cell -type ip -vlnv CSE:CSE:notgate:1.0 notgate_0 ]
  set_property -dict [ list \
CONFIG.WIDTH {1} \
 ] $notgate_0

  # Create instance: orgate_0, and set properties
  set orgate_0 [ create_bd_cell -type ip -vlnv CSE:CSE:orgate:1.0 orgate_0 ]
  set_property -dict [ list \
CONFIG.WIDTH {1} \
 ] $orgate_0

  # Create instance: xorgate_0, and set properties
  set xorgate_0 [ create_bd_cell -type ip -vlnv CSE:CSE:xorgate:1.0 xorgate_0 ]
  set_property -dict [ list \
CONFIG.WIDTH {1} \
 ] $xorgate_0

  # Create port connections
  connect_bd_net -net alu_bd_1_Result [get_bd_pins alu_bd_1/Result] [get_bd_pins dist_mem_gen_1/a]
  connect_bd_net -net alu_bd_1_Zero [get_bd_pins alu_bd_1/Zero] [get_bd_pins andgate_0/a] [get_bd_pins mux2to1_3/a0] [get_bd_pins notgate_0/a]
  connect_bd_net -net andgate_0_c [get_bd_pins andgate_0/c] [get_bd_pins orgate_0/a]
  connect_bd_net -net andgate_1_c [get_bd_pins andgate_1/c] [get_bd_pins orgate_0/b]
  connect_bd_net -net clk_1 [get_bd_ports clk] [get_bd_pins dist_mem_gen_1/clk] [get_bd_pins my_pc_0/clk] [get_bd_pins my_reg_0/clk]
  connect_bd_net -net dist_mem_gen_0_spo [get_bd_pins dist_mem_gen_0/spo] [get_bd_pins instruct_split_0/inst_31_0]
  connect_bd_net -net dist_mem_gen_1_spo [get_bd_pins dist_mem_gen_1/spo] [get_bd_pins mux2to1_3/a1]
  connect_bd_net -net input16_0_out [get_bd_pins input16_0/out] [get_bd_pins mux2to1_9/a1]
  connect_bd_net -net input31_0_out [get_bd_pins input31_0/out] [get_bd_pins mux2to1_1/a1]
  connect_bd_net -net instruct_split_0_inst_10_6 [get_bd_pins instruct_split_0/inst_10_6] [get_bd_pins my_expand32_1/in_WIDTH_0]
  connect_bd_net -net instruct_split_0_inst_15_0 [get_bd_pins instruct_split_0/inst_15_0] [get_bd_pins my_expend_0/im_15_0]
  connect_bd_net -net instruct_split_0_inst_15_11 [get_bd_pins instruct_split_0/inst_15_11] [get_bd_pins mux2to1_0/a1]
  connect_bd_net -net instruct_split_0_inst_20_16 [get_bd_pins instruct_split_0/inst_20_16] [get_bd_pins mux2to1_0/a0] [get_bd_pins my_reg_0/Rb]
  connect_bd_net -net instruct_split_0_inst_25_0 [get_bd_pins instruct_split_0/inst_25_0] [get_bd_pins my_shift2_0/in]
  connect_bd_net -net instruct_split_0_inst_25_21 [get_bd_pins instruct_split_0/inst_25_21] [get_bd_pins my_reg_0/Ra]
  connect_bd_net -net instruct_split_0_inst_31_26 [get_bd_pins instruct_split_0/inst_31_26] [get_bd_pins my_control_0/op]
  connect_bd_net -net instruct_split_0_inst_5_0 [get_bd_pins instruct_split_0/inst_5_0] [get_bd_pins my_control_0/func]
  connect_bd_net -net mux2to1_0_q [get_bd_pins mux2to1_0/q] [get_bd_pins mux2to1_1/a0]
  connect_bd_net -net mux2to1_1_q [get_bd_pins mux2to1_1/q] [get_bd_pins my_reg_0/Rw]
  connect_bd_net -net mux2to1_2_q [get_bd_pins alu_bd_1/B] [get_bd_pins mux2to1_2/q]
  connect_bd_net -net mux2to1_3_q [get_bd_pins mux2to1_3/q] [get_bd_pins mux2to1_4/a0]
  connect_bd_net -net mux2to1_4_q [get_bd_pins mux2to1_4/q] [get_bd_pins my_reg_0/busW]
  connect_bd_net -net mux2to1_5_q [get_bd_pins mux2to1_5/q] [get_bd_pins mux2to1_6/a0]
  connect_bd_net -net mux2to1_6_q [get_bd_pins mux2to1_6/q] [get_bd_pins mux2to1_7/a0]
  connect_bd_net -net mux2to1_7_q [get_bd_pins mux2to1_7/q] [get_bd_pins my_pc_0/pc_in]
  connect_bd_net -net mux2to1_8_q [get_bd_pins alu_bd_1/A] [get_bd_pins mux2to1_8/q]
  connect_bd_net -net mux2to1_9_q [get_bd_pins mux2to1_8/a1] [get_bd_pins mux2to1_9/q]
  connect_bd_net -net my_control_0_ALUctr [get_bd_pins alu_bd_1/ALUctr] [get_bd_pins my_control_0/ALUctr]
  connect_bd_net -net my_control_0_ALUsrc [get_bd_pins mux2to1_2/s] [get_bd_pins my_control_0/ALUsrc]
  connect_bd_net -net my_control_0_Branch [get_bd_pins andgate_0/b] [get_bd_pins my_control_0/Branch]
  connect_bd_net -net my_control_0_Extop [get_bd_pins my_control_0/Extop] [get_bd_pins my_expend_0/Extop]
  connect_bd_net -net my_control_0_MemToReg [get_bd_pins mux2to1_3/s] [get_bd_pins my_control_0/MemToReg]
  connect_bd_net -net my_control_0_MemWrite [get_bd_pins dist_mem_gen_1/we] [get_bd_pins my_control_0/MemWrite]
  connect_bd_net -net my_control_0_RegDst [get_bd_pins mux2to1_0/s] [get_bd_pins my_control_0/RegDst]
  connect_bd_net -net my_control_0_RegWrite [get_bd_pins my_control_0/RegWrite] [get_bd_pins my_reg_0/WriteEnable]
  connect_bd_net -net my_control_0_ShiftShamt [get_bd_pins my_control_0/ShiftShamt] [get_bd_pins xorgate_0/b]
  connect_bd_net -net my_control_0_jal [get_bd_pins mux2to1_1/s] [get_bd_pins mux2to1_4/s] [get_bd_pins my_control_0/jal]
  connect_bd_net -net my_control_0_jmp [get_bd_pins mux2to1_7/s] [get_bd_pins my_control_0/jmp]
  connect_bd_net -net my_control_0_jrn [get_bd_pins mux2to1_6/s] [get_bd_pins my_control_0/jrn]
  connect_bd_net -net my_control_0_lui [get_bd_pins mux2to1_9/s] [get_bd_pins my_control_0/lui] [get_bd_pins xorgate_0/a]
  connect_bd_net -net my_control_0_nBranch [get_bd_pins andgate_1/b] [get_bd_pins my_control_0/nBranch]
  connect_bd_net -net my_expand32_0_out_31_0 [get_bd_pins mux2to1_7/a1] [get_bd_pins my_expand32_0/out_31_0]
  connect_bd_net -net my_expand32_1_out_31_0 [get_bd_pins mux2to1_9/a0] [get_bd_pins my_expand32_1/out_31_0]
  connect_bd_net -net my_expend_0_im_31_0 [get_bd_pins mux2to1_2/a1] [get_bd_pins my_expend_0/im_31_0] [get_bd_pins my_shift2_1/in]
  connect_bd_net -net my_pc_0_pc_add4 [get_bd_pins mux2to1_4/a1] [get_bd_pins mux2to1_5/a0] [get_bd_pins my_pc_0/pc_add4] [get_bd_pins my_simple_add_0/a]
  connect_bd_net -net my_pc_0_pc_out [get_bd_pins my_pc_0/pc_out] [get_bd_pins my_right_shift2_0/i]
  connect_bd_net -net my_reg_0_Qa [get_bd_pins mux2to1_6/a1] [get_bd_pins mux2to1_8/a0] [get_bd_pins my_reg_0/Qa]
  connect_bd_net -net my_reg_0_Qb [get_bd_pins dist_mem_gen_1/d] [get_bd_pins mux2to1_2/a0] [get_bd_pins my_reg_0/Qb]
  connect_bd_net -net my_right_shift2_0_Result [get_bd_pins dist_mem_gen_0/a] [get_bd_pins my_right_shift2_0/Result]
  connect_bd_net -net my_shift2_0_out [get_bd_pins my_expand32_0/in_WIDTH_0] [get_bd_pins my_shift2_0/out]
  connect_bd_net -net my_shift2_1_out [get_bd_pins my_shift2_1/out] [get_bd_pins my_simple_add_0/b]
  connect_bd_net -net my_simple_add_0_sum [get_bd_pins mux2to1_5/a1] [get_bd_pins my_simple_add_0/sum]
  connect_bd_net -net notgate_0_c [get_bd_pins andgate_1/a] [get_bd_pins notgate_0/c]
  connect_bd_net -net orgate_0_c [get_bd_pins mux2to1_5/s] [get_bd_pins orgate_0/c]
  connect_bd_net -net pc_reset_1 [get_bd_ports pc_reset] [get_bd_pins my_pc_0/reset]
  connect_bd_net -net res_reset_1 [get_bd_ports res_reset] [get_bd_pins my_reg_0/reset]
  connect_bd_net -net xorgate_0_c [get_bd_pins mux2to1_8/s] [get_bd_pins xorgate_0/c]

  # Create address segments

  # Perform GUI Layout
  regenerate_bd_layout -layout_string {
   comment_0: "The ALU",
   comment_1: "ROM",
   commentid: "comment_0|comment_1|",
   font_comment_0: "15",
   font_comment_1: "10",
   guistr: "# # String gsaved with Nlview 6.5.12  2016-01-29 bk=1.3547 VDI=39 GEI=35 GUI=JA:1.6
#  -string -flagsOSRD
preplace port res_reset -pg 1 -y -10 -defaultsOSRD
preplace port pc_reset -pg 1 -y -80 -defaultsOSRD
preplace port clk -pg 1 -y -150 -defaultsOSRD
preplace inst my_expand32_0 -pg 1 -lvl 13 -y -990 -defaultsOSRD
preplace inst my_expend_0 -pg 1 -lvl 7 -y -140 -defaultsOSRD
preplace inst my_expand32_1 -pg 1 -lvl 7 -y -650 -defaultsOSRD
preplace inst input16_0 -pg 1 -lvl 7 -y -740 -defaultsOSRD
preplace inst mux2to1_0 -pg 1 -lvl 6 -y -400 -defaultsOSRD
preplace inst xorgate_0 -pg 1 -lvl 11 -y -690 -defaultsOSRD
preplace inst orgate_0 -pg 1 -lvl 14 -y -750 -defaultsOSRD
preplace inst mux2to1_1 -pg 1 -lvl 7 -y -400 -defaultsOSRD -resize 100 100
preplace inst dist_mem_gen_0 -pg 1 -lvl 3 -y -320 -defaultsOSRD
preplace inst dist_mem_gen_1 -pg 1 -lvl 18 -y -450 -defaultsOSRD
preplace inst mux2to1_2 -pg 1 -lvl 12 -y -390 -defaultsOSRD
preplace inst input31_0 -pg 1 -lvl 6 -y -190 -defaultsOSRD
preplace inst mux2to1_3 -pg 1 -lvl 19 -y -280 -defaultsOSRD
preplace inst alu_bd_1 -pg 1 -lvl 13 -y -270 -defaultsOSRD
preplace inst mux2to1_4 -pg 1 -lvl 5 -y -50 -defaultsOSRD -orient R90
preplace inst my_shift2_0 -pg 1 -lvl 9 -y -1100 -defaultsOSRD
preplace inst mux2to1_5 -pg 1 -lvl 16 -y -740 -defaultsOSRD
preplace inst my_reg_0 -pg 1 -lvl 10 -y -530 -defaultsOSRD
preplace inst my_shift2_1 -pg 1 -lvl 14 -y -580 -defaultsOSRD
preplace inst my_pc_0 -pg 1 -lvl 1 -y -310 -defaultsOSRD
preplace inst mux2to1_6 -pg 1 -lvl 17 -y -680 -defaultsOSRD -resize 120 100
preplace inst notgate_0 -pg 1 -lvl 13 -y -590 -defaultsOSRD
preplace inst mux2to1_7 -pg 1 -lvl 18 -y -970 -defaultsOSRD -resize 120 100
preplace inst my_simple_add_0 -pg 1 -lvl 15 -y -540 -defaultsOSRD
preplace inst my_right_shift2_0 -pg 1 -lvl 2 -y -340 -defaultsOSRD
preplace inst mux2to1_8 -pg 1 -lvl 12 -y -660 -defaultsOSRD
preplace inst my_control_0 -pg 1 -lvl 6 -y -800 -defaultsOSRD
preplace inst mux2to1_9 -pg 1 -lvl 8 -y -760 -defaultsOSRD
preplace inst instruct_split_0 -pg 1 -lvl 4 -y -380 -defaultsOSRD
preplace inst andgate_0 -pg 1 -lvl 13 -y -800 -defaultsOSRD
preplace inst andgate_1 -pg 1 -lvl 13 -y -690 -defaultsOSRD -resize 100 80
preplace netloc my_reg_0_Qb 1 10 8 NJ -520 NJ -460 NJ -460 NJ -460 NJ -460 NJ -460 NJ -460 NJ
preplace netloc my_control_0_MemWrite 1 6 12 NJ -890 NJ -890 NJ -890 NJ -890 NJ -890 NJ -890 NJ -890 NJ -890 NJ -890 NJ -890 NJ -890 2620
preplace netloc my_control_0_ALUsrc 1 6 6 NJ -870 NJ -870 NJ -870 NJ -870 NJ -870 1210
preplace netloc alu_bd_1_Zero 1 12 7 1460 -500 1790 -300 NJ -300 NJ -300 NJ -300 NJ -300 N
preplace netloc input16_0_out 1 7 1 260
preplace netloc my_expand32_0_out_31_0 1 13 5 NJ -990 NJ -990 NJ -990 NJ -990 NJ
preplace netloc my_control_0_ALUctr 1 6 7 NJ -920 NJ -920 NJ -920 NJ -920 NJ -920 NJ -920 NJ
preplace netloc notgate_0_c 1 12 2 1450 -860 1790
preplace netloc my_simple_add_0_sum 1 15 1 2270
preplace netloc my_control_0_jal 1 5 2 -350 -470 -70
preplace netloc instruct_split_0_inst_15_0 1 4 3 NJ -310 NJ -310 NJ
preplace netloc instruct_split_0_inst_10_6 1 4 3 -570 -610 NJ -610 NJ
preplace netloc my_control_0_RegDst 1 5 2 -340 -990 -110
preplace netloc my_control_0_RegWrite 1 6 4 NJ -850 NJ -850 NJ -850 NJ
preplace netloc my_right_shift2_0_Result 1 2 1 -1120
preplace netloc pc_reset_1 1 0 1 -1600
preplace netloc instruct_split_0_inst_5_0 1 4 2 -580 -790 NJ
preplace netloc instruct_split_0_inst_25_21 1 4 6 NJ -570 NJ -570 NJ -570 NJ -570 NJ -570 NJ
preplace netloc mux2to1_1_q 1 7 3 NJ -590 NJ -590 NJ
preplace netloc my_expend_0_im_31_0 1 7 7 NJ -390 NJ -390 NJ -390 NJ -390 NJ -520 NJ -520 NJ
preplace netloc my_control_0_ShiftShamt 1 6 5 NJ -590 NJ -680 NJ -680 NJ -680 NJ
preplace netloc my_expand32_1_out_31_0 1 7 1 250
preplace netloc my_pc_0_pc_add4 1 1 15 NJ -280 NJ -250 NJ -250 NJ N NJ -540 NJ -540 NJ -660 NJ -660 NJ -660 NJ -510 NJ -510 NJ -510 NJ -510 2060 -760 NJ
preplace netloc alu_bd_1_Result 1 13 5 1810 -630 NJ -630 NJ -630 NJ -610 NJ
preplace netloc instruct_split_0_inst_20_16 1 4 6 NJ -420 NJ -550 NJ -550 NJ -550 NJ -550 NJ
preplace netloc clk_1 1 0 18 -1620 -500 NJ -500 NJ -500 NJ -500 NJ -500 NJ -500 NJ -500 NJ -500 NJ -500 NJ -640 NJ -630 NJ -590 NJ -480 NJ -480 NJ -480 NJ -480 NJ -480 NJ
preplace netloc andgate_1_c 1 13 1 1800
preplace netloc dist_mem_gen_0_spo 1 3 1 -900
preplace netloc mux2to1_2_q 1 12 1 1400
preplace netloc mux2to1_8_q 1 12 1 1410
preplace netloc my_shift2_0_out 1 9 4 NJ -1100 NJ -1100 NJ -1100 NJ
preplace netloc my_control_0_lui 1 6 5 NJ -790 NJ -840 NJ -840 NJ -840 NJ
preplace netloc my_shift2_1_out 1 14 1 2050
preplace netloc andgate_0_c 1 13 1 1800
preplace netloc mux2to1_0_q 1 6 1 -50
preplace netloc my_pc_0_pc_out 1 1 1 -1350
preplace netloc mux2to1_4_q 1 5 5 -380 -510 NJ -510 NJ -510 NJ -510 NJ
preplace netloc instruct_split_0_inst_25_0 1 4 5 -610 -1100 NJ -1100 NJ -1100 NJ -1100 NJ
preplace netloc mux2to1_7_q 1 0 19 -1600 -1030 NJ -1030 NJ -1030 NJ -1030 NJ -1030 NJ -1030 NJ -1030 NJ -1030 NJ -1030 NJ -1050 NJ -1050 NJ -1050 NJ -1050 NJ -1050 NJ -1050 NJ -1050 NJ -1050 NJ -1050 2860
preplace netloc my_control_0_jmp 1 6 12 -100 -1040 NJ -1040 NJ -1040 NJ -1040 NJ -1040 NJ -1040 NJ -1040 NJ -1040 NJ -1040 NJ -1040 NJ -1040 NJ
preplace netloc mux2to1_6_q 1 17 1 2630
preplace netloc my_control_0_jrn 1 6 11 NJ -910 NJ -910 NJ -910 NJ -910 NJ -910 NJ -910 NJ -910 NJ -910 NJ -910 NJ -910 2450
preplace netloc mux2to1_5_q 1 16 1 2440
preplace netloc my_control_0_Extop 1 6 1 -100
preplace netloc instruct_split_0_inst_31_26 1 4 2 -600 -810 NJ
preplace netloc res_reset_1 1 0 10 NJ -390 NJ -390 NJ -390 NJ -260 NJ -260 NJ -260 NJ -470 NJ -470 NJ -470 NJ
preplace netloc my_control_0_Branch 1 6 7 NJ -800 NJ -860 NJ -860 NJ -860 NJ -860 NJ -860 NJ
preplace netloc mux2to1_3_q 1 5 15 NJ 30 NJ 30 NJ 30 NJ 30 NJ 30 NJ 30 NJ 30 NJ 30 NJ 30 NJ 30 NJ 30 NJ 30 NJ 30 NJ 30 3030
preplace netloc my_control_0_MemToReg 1 6 13 NJ -900 NJ -900 NJ -900 NJ -900 NJ -900 NJ -900 NJ -900 NJ -900 NJ -900 NJ -900 NJ -900 NJ -900 2860
preplace netloc input31_0_out 1 6 1 -40
preplace netloc xorgate_0_c 1 11 1 1220
preplace netloc my_control_0_nBranch 1 6 7 NJ -830 NJ -830 NJ -830 NJ -830 NJ -830 NJ -830 1430
preplace netloc my_reg_0_Qa 1 10 7 NJ -540 NJ -540 NJ -540 NJ -670 NJ -670 NJ -670 NJ
preplace netloc instruct_split_0_inst_15_11 1 4 2 NJ -400 NJ
preplace netloc mux2to1_9_q 1 8 4 NJ -760 NJ -760 NJ -760 1230
preplace netloc orgate_0_c 1 14 2 NJ -750 NJ
preplace netloc dist_mem_gen_1_spo 1 18 1 NJ
preplace cgraphic comment_1 place abs -1031 -385 textcolor 4 linecolor 3 linewidth 2
preplace cgraphic comment_0 place abs 1520 -363 textcolor 4 linecolor 3 linewidth 2
levelinfo -pg 1 -1640 -1470 -1230 -1010 -750 -460 -220 110 370 570 920 1120 1320 1640 1950 2160 2360 2530 2750 2950 3050 -top -1150 -bot 670
",
}

  # Restore current instance
  current_bd_instance $oldCurInst

  save_bd_design
}
# End of create_root_design()


##################################################################
# MAIN FLOW
##################################################################


common::send_msg_id "BD_TCL-2000" "CRITICAL WARNING" "This Tcl script was generated from a block design that is out-of-date/locked. It is possible that design <$design_name> may result in errors during construction."

create_root_design ""


