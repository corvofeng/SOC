// Copyright 1986-2016 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2016.2 (lin64) Build 1577090 Thu Jun  2 16:32:35 MDT 2016
// Date        : Tue Dec 13 19:20:59 2016
// Host        : ThinkPad running 64-bit Arch Linux
// Command     : write_verilog -force -mode synth_stub
//               /home/corvo/Learning/verilog/CourseSubmit/Oh-My-Project/Oh-My-Project.srcs/sources_1/ip/orgate_0/orgate_0_stub.v
// Design      : orgate_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a100tcsg324-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "orgate,Vivado 2016.2" *)
module orgate_0(a, b, c)
/* synthesis syn_black_box black_box_pad_pin="a[7:0],b[7:0],c[7:0]" */;
  input [7:0]a;
  input [7:0]b;
  output [7:0]c;
endmodule
