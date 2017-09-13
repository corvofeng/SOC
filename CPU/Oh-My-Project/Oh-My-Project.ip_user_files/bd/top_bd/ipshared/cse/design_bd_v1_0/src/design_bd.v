//Copyright 1986-2016 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2016.2 (lin64) Build 1577090 Thu Jun  2 16:32:35 MDT 2016
//Date        : Fri Jul 15 17:26:33 2016
//Host        : ThinkPad running 64-bit Arch Linux
//Command     : generate_target design_bd.bd
//Design      : design_bd
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "design_bd,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=design_bd,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=14,numReposBlks=14,numNonXlnxBlks=14,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=USER,synth_mode=Global}" *) (* HW_HANDOFF = "design_bd.hwdef" *) 
module design_bd
   (A,
    ALUctr,
    B,
    Overflow,
    Result,
    Zero);
  input [31:0]A;
  input [3:0]ALUctr;
  input [31:0]B;
  output [0:0]Overflow;
  output [31:0]Result;
  output Zero;

  wire [3:0]ALUctr_1;
  wire [31:0]A_1;
  wire [31:0]B_1;
  wire SUBctr_1;
  wire addsub_0_cf;
  wire addsub_0_of;
  wire addsub_0_sf;
  wire [31:0]addsub_0_sum;
  wire addsub_0_zf;
  wire [0:0]andgate_0_c;
  wire [31:0]andgate_1_c;
  wire [31:0]input0_0_zero;
  wire [31:0]input1_1_zero;
  wire [0:0]mux2to1_0_q;
  wire [31:0]mux2to1_1_q;
  wire [31:0]my_8mux1_1_q;
  wire my_alu_ctr_input_0_ALGctr;
  wire [2:0]my_alu_ctr_input_0_OPctr;
  wire my_alu_ctr_input_0_OVctr;
  wire my_alu_ctr_input_0_SIGctr;
  wire my_alu_ctr_input_0_SLctr;
  wire [31:0]my_shift_0_Result;
  wire [31:0]norgate_0_c;
  wire [31:0]orgate_0_c;
  wire [0:0]xorgate_0_c;
  wire [0:0]xorgate_1_c;

  assign ALUctr_1 = ALUctr[3:0];
  assign A_1 = A[31:0];
  assign B_1 = B[31:0];
  assign Overflow[0] = andgate_0_c;
  assign Result[31:0] = my_8mux1_1_q;
  assign Zero = addsub_0_zf;
  design_bd_addsub_0_2 addsub_0
       (.a(A_1),
        .b(B_1),
        .cf(addsub_0_cf),
        .of(addsub_0_of),
        .sf(addsub_0_sf),
        .sub(SUBctr_1),
        .sum(addsub_0_sum),
        .zf(addsub_0_zf));
  design_bd_andgate_0_0 andgate_0
       (.a(addsub_0_of),
        .b(my_alu_ctr_input_0_OVctr),
        .c(andgate_0_c));
  design_bd_andgate_1_0 andgate_1
       (.a(A_1),
        .b(B_1),
        .c(andgate_1_c));
  design_bd_input0_1_0 input0_1
       (.zero(input0_0_zero));
  design_bd_input1_1_0 input1_1
       (.zero(input1_1_zero));
  design_bd_mux2to1_0_0 mux2to1_0
       (.a0(xorgate_0_c),
        .a1(xorgate_1_c),
        .q(mux2to1_0_q),
        .s(my_alu_ctr_input_0_SIGctr));
  design_bd_mux2to1_1_0 mux2to1_1
       (.a0(input0_0_zero),
        .a1(input1_1_zero),
        .q(mux2to1_1_q),
        .s(mux2to1_0_q));
  design_bd_my_8mux1_1_0 my_8mux1_1
       (.a0(addsub_0_sum),
        .a1(mux2to1_1_q),
        .a2(andgate_1_c),
        .a3(orgate_0_c),
        .a4(input0_0_zero),
        .a5(norgate_0_c),
        .a6(input0_0_zero),
        .a7(my_shift_0_Result),
        .q(my_8mux1_1_q),
        .s(my_alu_ctr_input_0_OPctr));
  design_bd_my_alu_ctr_input_0_0 my_alu_ctr_input_0
       (.ALGctr(my_alu_ctr_input_0_ALGctr),
        .ALUctr(ALUctr_1),
        .OPctr(my_alu_ctr_input_0_OPctr),
        .OVctr(my_alu_ctr_input_0_OVctr),
        .SIGctr(my_alu_ctr_input_0_SIGctr),
        .SLctr(my_alu_ctr_input_0_SLctr),
        .SUBctr(SUBctr_1));
  design_bd_my_shift_0_0 my_shift_0
       (.A(A_1),
        .ALGctr(my_alu_ctr_input_0_ALGctr),
        .B(B_1),
        .Result(my_shift_0_Result),
        .SLctr(my_alu_ctr_input_0_SLctr));
  design_bd_norgate_0_0 norgate_0
       (.a(A_1),
        .b(B_1),
        .c(norgate_0_c));
  design_bd_orgate_0_0 orgate_0
       (.a(A_1),
        .b(B_1),
        .c(orgate_0_c));
  design_bd_xorgate_0_0 xorgate_0
       (.a(SUBctr_1),
        .b(addsub_0_cf),
        .c(xorgate_0_c));
  design_bd_xorgate_0_1 xorgate_1
       (.a(addsub_0_of),
        .b(addsub_0_sf),
        .c(xorgate_1_c));
endmodule
