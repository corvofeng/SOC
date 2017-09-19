//Copyright 1986-2016 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2016.2 (lin64) Build 1577090 Thu Jun  2 16:32:35 MDT 2016
//Date        : Tue Oct 18 15:22:07 2016
//Host        : ThinkPad running 64-bit Arch Linux
//Command     : generate_target top_bd_wrapper.bd
//Design      : top_bd_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module top_bd_wrapper
   (clk,
    pc_reset,
    res_reset);
  input clk;
  input pc_reset;
  input res_reset;

  wire clk;
  wire pc_reset;
  wire res_reset;

  top_bd top_bd_i
       (.clk(clk),
        .pc_reset(pc_reset),
        .res_reset(res_reset));
endmodule
