
################################################################
# This is a generated script based on design: design_bd
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
# source design_bd_script.tcl

# If there is no project opened, this script will create a
# project, but make sure you do not have an existing project
# <./myproj/project_1.xpr> in the current working folder.

set list_projs [get_projects -quiet]
if { $list_projs eq "" } {
   create_project project_1 myproj -part xc7a100tcsg324-1
}


# CHANGE DESIGN NAME HERE
set design_name design_bd

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
  set A [ create_bd_port -dir I -from 31 -to 0 A ]
  set ALUctr [ create_bd_port -dir I -from 3 -to 0 ALUctr ]
  set B [ create_bd_port -dir I -from 31 -to 0 B ]
  set Overflow [ create_bd_port -dir O -from 0 -to 0 Overflow ]
  set Result [ create_bd_port -dir O -from 31 -to 0 Result ]
  set Zero [ create_bd_port -dir O Zero ]

  # Create instance: addsub_0, and set properties
  set addsub_0 [ create_bd_cell -type ip -vlnv CSE:CSE:addsub:1.0 addsub_0 ]
  set_property -dict [ list \
CONFIG.WIDTH {32} \
 ] $addsub_0

  # Create instance: andgate_0, and set properties
  set andgate_0 [ create_bd_cell -type ip -vlnv CSE:CSE:andgate:1.0 andgate_0 ]
  set_property -dict [ list \
CONFIG.WIDTH {1} \
 ] $andgate_0

  # Create instance: andgate_1, and set properties
  set andgate_1 [ create_bd_cell -type ip -vlnv CSE:CSE:andgate:1.0 andgate_1 ]
  set_property -dict [ list \
CONFIG.WIDTH {32} \
 ] $andgate_1

  # Create instance: input0_1, and set properties
  set input0_1 [ create_bd_cell -type ip -vlnv CSE:CSE:input0:1.0 input0_1 ]

  # Create instance: input1_1, and set properties
  set input1_1 [ create_bd_cell -type ip -vlnv CSE:CSE:input1:1.0 input1_1 ]

  # Create instance: mux2to1_0, and set properties
  set mux2to1_0 [ create_bd_cell -type ip -vlnv CSE:CSE:mux2to1:1.0 mux2to1_0 ]
  set_property -dict [ list \
CONFIG.WIDTH {1} \
 ] $mux2to1_0

  # Create instance: mux2to1_1, and set properties
  set mux2to1_1 [ create_bd_cell -type ip -vlnv CSE:CSE:mux2to1:1.0 mux2to1_1 ]
  set_property -dict [ list \
CONFIG.WIDTH {32} \
 ] $mux2to1_1

  # Create instance: my_8mux1_1, and set properties
  set my_8mux1_1 [ create_bd_cell -type ip -vlnv CSE:CSE:my_8mux1:1.0 my_8mux1_1 ]
  set_property -dict [ list \
CONFIG.WIDTH {32} \
 ] $my_8mux1_1

  # Create instance: my_alu_ctr_input_0, and set properties
  set my_alu_ctr_input_0 [ create_bd_cell -type ip -vlnv CSE:CSE:my_alu_ctr_input:1.0 my_alu_ctr_input_0 ]

  # Create instance: my_shift_0, and set properties
  set my_shift_0 [ create_bd_cell -type ip -vlnv CSE:CSE:my_shift:1.0 my_shift_0 ]

  # Create instance: norgate_0, and set properties
  set norgate_0 [ create_bd_cell -type ip -vlnv CSE:CSE:norgate:1.0 norgate_0 ]
  set_property -dict [ list \
CONFIG.WIDTH {32} \
 ] $norgate_0

  # Create instance: orgate_0, and set properties
  set orgate_0 [ create_bd_cell -type ip -vlnv CSE:CSE:orgate:1.0 orgate_0 ]
  set_property -dict [ list \
CONFIG.WIDTH {32} \
 ] $orgate_0

  # Create instance: xorgate_0, and set properties
  set xorgate_0 [ create_bd_cell -type ip -vlnv CSE:CSE:xorgate:1.0 xorgate_0 ]
  set_property -dict [ list \
CONFIG.WIDTH {1} \
 ] $xorgate_0

  # Create instance: xorgate_1, and set properties
  set xorgate_1 [ create_bd_cell -type ip -vlnv CSE:CSE:xorgate:1.0 xorgate_1 ]
  set_property -dict [ list \
CONFIG.WIDTH {1} \
 ] $xorgate_1

  # Create port connections
  connect_bd_net -net ALUctr_1 [get_bd_ports ALUctr] [get_bd_pins my_alu_ctr_input_0/ALUctr]
  connect_bd_net -net A_1 [get_bd_ports A] [get_bd_pins addsub_0/a] [get_bd_pins andgate_1/a] [get_bd_pins my_shift_0/A] [get_bd_pins norgate_0/a] [get_bd_pins orgate_0/a]
  connect_bd_net -net B_1 [get_bd_ports B] [get_bd_pins addsub_0/b] [get_bd_pins andgate_1/b] [get_bd_pins my_shift_0/B] [get_bd_pins norgate_0/b] [get_bd_pins orgate_0/b]
  connect_bd_net -net SUBctr_1 [get_bd_pins addsub_0/sub] [get_bd_pins my_alu_ctr_input_0/SUBctr] [get_bd_pins xorgate_0/a]
  connect_bd_net -net addsub_0_cf [get_bd_pins addsub_0/cf] [get_bd_pins xorgate_0/b]
  connect_bd_net -net addsub_0_of [get_bd_pins addsub_0/of] [get_bd_pins andgate_0/a] [get_bd_pins xorgate_1/a]
  connect_bd_net -net addsub_0_sf [get_bd_pins addsub_0/sf] [get_bd_pins xorgate_1/b]
  connect_bd_net -net addsub_0_sum [get_bd_pins addsub_0/sum] [get_bd_pins my_8mux1_1/a0]
  connect_bd_net -net addsub_0_zf [get_bd_ports Zero] [get_bd_pins addsub_0/zf]
  connect_bd_net -net andgate_0_c [get_bd_ports Overflow] [get_bd_pins andgate_0/c]
  connect_bd_net -net andgate_1_c [get_bd_pins andgate_1/c] [get_bd_pins my_8mux1_1/a2]
  connect_bd_net -net input0_0_zero [get_bd_pins input0_1/zero] [get_bd_pins mux2to1_1/a0] [get_bd_pins my_8mux1_1/a4] [get_bd_pins my_8mux1_1/a6]
  connect_bd_net -net input1_1_zero [get_bd_pins input1_1/zero] [get_bd_pins mux2to1_1/a1]
  connect_bd_net -net mux2to1_0_q [get_bd_pins mux2to1_0/q] [get_bd_pins mux2to1_1/s]
  connect_bd_net -net mux2to1_1_q [get_bd_pins mux2to1_1/q] [get_bd_pins my_8mux1_1/a1]
  connect_bd_net -net my_8mux1_1_q [get_bd_ports Result] [get_bd_pins my_8mux1_1/q]
  connect_bd_net -net my_alu_ctr_input_0_ALGctr [get_bd_pins my_alu_ctr_input_0/ALGctr] [get_bd_pins my_shift_0/ALGctr]
  connect_bd_net -net my_alu_ctr_input_0_OPctr [get_bd_pins my_8mux1_1/s] [get_bd_pins my_alu_ctr_input_0/OPctr]
  connect_bd_net -net my_alu_ctr_input_0_OVctr [get_bd_pins andgate_0/b] [get_bd_pins my_alu_ctr_input_0/OVctr]
  connect_bd_net -net my_alu_ctr_input_0_SIGctr [get_bd_pins mux2to1_0/s] [get_bd_pins my_alu_ctr_input_0/SIGctr]
  connect_bd_net -net my_alu_ctr_input_0_SLctr [get_bd_pins my_alu_ctr_input_0/SLctr] [get_bd_pins my_shift_0/SLctr]
  connect_bd_net -net my_shift_0_Result [get_bd_pins my_8mux1_1/a7] [get_bd_pins my_shift_0/Result]
  connect_bd_net -net norgate_0_c [get_bd_pins my_8mux1_1/a5] [get_bd_pins norgate_0/c]
  connect_bd_net -net orgate_0_c [get_bd_pins my_8mux1_1/a3] [get_bd_pins orgate_0/c]
  connect_bd_net -net xorgate_0_c [get_bd_pins mux2to1_0/a0] [get_bd_pins xorgate_0/c]
  connect_bd_net -net xorgate_1_c [get_bd_pins mux2to1_0/a1] [get_bd_pins xorgate_1/c]

  # Create address segments

  # Perform GUI Layout
  regenerate_bd_layout -layout_string {
   guistr: "# # String gsaved with Nlview 6.5.12  2016-01-29 bk=1.3547 VDI=39 GEI=35 GUI=JA:1.6
#  -string -flagsOSRD
preplace port Zero -pg 1 -y 460 -defaultsOSRD
preplace portBus A -pg 1 -y 410 -defaultsOSRD
preplace portBus ALUctr -pg 1 -y 210 -defaultsOSRD
preplace portBus Overflow -pg 1 -y 510 -defaultsOSRD
preplace portBus B -pg 1 -y 480 -defaultsOSRD
preplace portBus Result -pg 1 -y 160 -defaultsOSRD
preplace inst my_shift_0 -pg 1 -lvl 2 -y 10 -defaultsOSRD
preplace inst mux2to1_0 -pg 1 -lvl 4 -y 720 -defaultsOSRD
preplace inst my_8mux1_1 -pg 1 -lvl 6 -y 160 -defaultsOSRD
preplace inst mux2to1_1 -pg 1 -lvl 5 -y 430 -defaultsOSRD
preplace inst xorgate_0 -pg 1 -lvl 3 -y 700 -defaultsOSRD
preplace inst orgate_0 -pg 1 -lvl 5 -y 160 -defaultsOSRD
preplace inst addsub_0 -pg 1 -lvl 2 -y 480 -defaultsOSRD
preplace inst xorgate_1 -pg 1 -lvl 3 -y 590 -defaultsOSRD
preplace inst norgate_0 -pg 1 -lvl 5 -y 290 -defaultsOSRD
preplace inst my_alu_ctr_input_0 -pg 1 -lvl 1 -y 90 -defaultsOSRD
preplace inst input1_1 -pg 1 -lvl 4 -y 450 -defaultsOSRD
preplace inst input0_1 -pg 1 -lvl 4 -y 360 -defaultsOSRD
preplace inst andgate_0 -pg 1 -lvl 6 -y 510 -defaultsOSRD
preplace inst andgate_1 -pg 1 -lvl 5 -y 40 -defaultsOSRD
preplace netloc my_shift_0_Result 1 2 4 370 -20 NJ -20 NJ -20 NJ
preplace netloc A_1 1 0 5 N 410 NJ 90 NJ 80 NJ 80 750
preplace netloc addsub_0_sf 1 2 1 370
preplace netloc addsub_0_sum 1 2 4 NJ 100 NJ 100 NJ 100 960
preplace netloc my_alu_ctr_input_0_SIGctr 1 1 3 NJ 120 NJ 120 560
preplace netloc addsub_0_zf 1 2 5 NJ 520 NJ 520 NJ 520 NJ 450 NJ
preplace netloc addsub_0_cf 1 2 1 380
preplace netloc my_alu_ctr_input_0_ALGctr 1 1 1 -430
preplace netloc my_alu_ctr_input_0_OPctr 1 1 5 NJ 110 NJ 110 NJ 110 NJ 230 NJ
preplace netloc my_alu_ctr_input_0_OVctr 1 1 5 NJ -70 NJ -70 NJ -70 NJ -70 970
preplace netloc mux2to1_1_q 1 5 1 980
preplace netloc SUBctr_1 1 1 2 NJ 390 NJ
preplace netloc input1_1_zero 1 4 1 NJ
preplace netloc andgate_1_c 1 5 1 990
preplace netloc mux2to1_0_q 1 4 1 770
preplace netloc andgate_0_c 1 6 1 N
preplace netloc input0_0_zero 1 4 2 770 220 990
preplace netloc xorgate_1_c 1 3 1 550
preplace netloc B_1 1 0 5 N 480 NJ 100 NJ 90 NJ 90 760
preplace netloc my_8mux1_1_q 1 6 1 N
preplace netloc ALUctr_1 1 0 1 -1320
preplace netloc my_alu_ctr_input_0_SLctr 1 1 1 -480
preplace netloc norgate_0_c 1 5 1 1010
preplace netloc addsub_0_of 1 2 4 390 500 NJ 500 NJ 500 N
preplace netloc xorgate_0_c 1 3 1 N
preplace netloc orgate_0_c 1 5 1 960
levelinfo -pg 1 -1340 -600 280 480 670 880 1260 1360 -top -160 -bot 790
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

create_root_design ""


