//Copyright 1986-2016 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2016.2 (lin64) Build 1577090 Thu Jun  2 16:32:35 MDT 2016
//Date        : Tue Dec 13 19:05:47 2016
//Host        : ThinkPad running 64-bit Arch Linux
//Command     : generate_target test_db_wrapper.bd
//Design      : test_db_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module test_db_wrapper
   (a,
    b,
    ctr,
    res);
  input [31:0]a;
  input [31:0]b;
  input [3:0]ctr;
  output [31:0]res;

  wire [31:0]a;
  wire [31:0]b;
  wire [3:0]ctr;
  wire [31:0]res;

  test_db test_db_i
       (.a(a),
        .b(b),
        .ctr(ctr),
        .res(res));
endmodule
