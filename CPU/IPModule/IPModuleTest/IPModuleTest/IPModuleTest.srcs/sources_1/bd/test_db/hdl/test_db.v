//Copyright 1986-2016 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2016.2 (lin64) Build 1577090 Thu Jun  2 16:32:35 MDT 2016
//Date        : Tue Dec 13 19:36:11 2016
//Host        : ThinkPad running 64-bit Arch Linux
//Command     : generate_target test_db.bd
//Design      : test_db
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "test_db,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=test_db,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=1,numReposBlks=1,numNonXlnxBlks=1,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=1,bdsource=USER,synth_mode=Global}" *) (* HW_HANDOFF = "test_db.hwdef" *) 
module test_db
   (a,
    b,
    ctr,
    res);
  input [31:0]a;
  input [31:0]b;
  input [3:0]ctr;
  output [31:0]res;

  wire [31:0]a_1;
  wire [31:0]alu_bd_0_Result;
  wire [31:0]b_1;
  wire [3:0]ctr_1;

  assign a_1 = a[31:0];
  assign b_1 = b[31:0];
  assign ctr_1 = ctr[3:0];
  assign res[31:0] = alu_bd_0_Result;
  test_db_alu_bd_0_0 alu_bd_0
       (.A(a_1),
        .ALUctr(ctr_1),
        .B(b_1),
        .Result(alu_bd_0_Result));
endmodule
