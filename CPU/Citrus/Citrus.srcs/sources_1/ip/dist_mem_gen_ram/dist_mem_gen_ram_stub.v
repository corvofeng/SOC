// Copyright 1986-2015 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2015.4 (lin64) Build 1412921 Wed Nov 18 09:44:32 MST 2015
// Date        : Tue Sep 19 09:12:53 2017
// Host        : ThinkPad running 64-bit unknown
// Command     : write_verilog -force -mode synth_stub
//               /home/corvo/Learning/verilog/SOC/CPU/Citrus/Citrus.srcs/sources_1/ip/dist_mem_gen_ram/dist_mem_gen_ram_stub.v
// Design      : dist_mem_gen_ram
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a100tfgg484-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* x_core_info = "dist_mem_gen_v8_0_9,Vivado 2015.4" *)
module dist_mem_gen_ram(a, d, clk, we, spo)
/* synthesis syn_black_box black_box_pad_pin="a[15:0],d[31:0],clk,we,spo[31:0]" */;
  input [15:0]a;
  input [31:0]d;
  input clk;
  input we;
  output [31:0]spo;
endmodule
