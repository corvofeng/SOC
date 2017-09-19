//Copyright 1986-2016 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2016.2 (lin64) Build 1577090 Thu Jun  2 16:32:35 MDT 2016
//Date        : Tue Oct 18 15:22:07 2016
//Host        : ThinkPad running 64-bit Arch Linux
//Command     : generate_target top_bd.bd
//Design      : top_bd
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "top_bd,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=top_bd,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=31,numReposBlks=31,numNonXlnxBlks=29,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=12,numPkgbdBlks=1,bdsource=USER,synth_mode=Global}" *) (* HW_HANDOFF = "top_bd.hwdef" *) 
module top_bd
   (clk,
    pc_reset,
    res_reset);
  input clk;
  input pc_reset;
  input res_reset;

  wire [31:0]alu_bd_1_Result;
  wire alu_bd_1_Zero;
  wire [0:0]andgate_0_c;
  wire [0:0]andgate_1_c;
  wire clk_1;
  wire [31:0]dist_mem_gen_0_spo;
  wire [31:0]dist_mem_gen_1_spo;
  wire [31:0]input16_0_out;
  wire [4:0]input31_0_out;
  wire [4:0]instruct_split_0_inst_10_6;
  wire [15:0]instruct_split_0_inst_15_0;
  wire [4:0]instruct_split_0_inst_15_11;
  wire [4:0]instruct_split_0_inst_20_16;
  wire [25:0]instruct_split_0_inst_25_0;
  wire [4:0]instruct_split_0_inst_25_21;
  wire [5:0]instruct_split_0_inst_31_26;
  wire [5:0]instruct_split_0_inst_5_0;
  wire [4:0]mux2to1_0_q;
  wire [4:0]mux2to1_1_q;
  wire [31:0]mux2to1_2_q;
  wire [31:0]mux2to1_3_q;
  wire [31:0]mux2to1_4_q;
  wire [31:0]mux2to1_5_q;
  wire [31:0]mux2to1_6_q;
  wire [31:0]mux2to1_7_q;
  wire [31:0]mux2to1_8_q;
  wire [31:0]mux2to1_9_q;
  wire [3:0]my_control_0_ALUctr;
  wire my_control_0_ALUsrc;
  wire my_control_0_Branch;
  wire my_control_0_Extop;
  wire my_control_0_MemToReg;
  wire my_control_0_MemWrite;
  wire my_control_0_RegDst;
  wire my_control_0_RegWrite;
  wire my_control_0_ShiftShamt;
  wire my_control_0_jal;
  wire my_control_0_jmp;
  wire my_control_0_jrn;
  wire my_control_0_lui;
  wire my_control_0_nBranch;
  wire [31:0]my_expand32_0_out_31_0;
  wire [31:0]my_expand32_1_out_31_0;
  wire [31:0]my_expend_0_im_31_0;
  wire [31:0]my_pc_0_pc_add4;
  wire [31:0]my_pc_0_pc_out;
  wire [31:0]my_reg_0_Qa;
  wire [31:0]my_reg_0_Qb;
  wire [15:0]my_right_shift2_0_Result;
  wire [25:0]my_shift2_0_out;
  wire [31:0]my_shift2_1_out;
  wire [31:0]my_simple_add_0_sum;
  wire [0:0]notgate_0_c;
  wire [0:0]orgate_0_c;
  wire pc_reset_1;
  wire res_reset_1;
  wire [0:0]xorgate_0_c;

  assign clk_1 = clk;
  assign pc_reset_1 = pc_reset;
  assign res_reset_1 = res_reset;
  alu_impl alu_bd_1
       (.A(mux2to1_8_q),
        .ALUctr(my_control_0_ALUctr),
        .B(mux2to1_2_q),
        .Result(alu_bd_1_Result),
        .Zero(alu_bd_1_Zero));
  top_bd_andgate_0_0 andgate_0
       (.a(alu_bd_1_Zero),
        .b(my_control_0_Branch),
        .c(andgate_0_c));
  top_bd_andgate_0_1 andgate_1
       (.a(notgate_0_c),
        .b(my_control_0_nBranch),
        .c(andgate_1_c));
  top_bd_dist_mem_gen_0_0 dist_mem_gen_0
       (.a(my_right_shift2_0_Result[14:0]),
        .spo(dist_mem_gen_0_spo));
  top_bd_dist_mem_gen_1_0 dist_mem_gen_1
       (.a(alu_bd_1_Result[15:0]),
        .clk(clk_1),
        .d(my_reg_0_Qb),
        .spo(dist_mem_gen_1_spo),
        .we(my_control_0_MemWrite));
  top_bd_input16_0_0 input16_0
       (.out(input16_0_out));
  top_bd_input31_0_0 input31_0
       (.out(input31_0_out));
  top_bd_instruct_split_0_0 instruct_split_0
       (.inst_10_6(instruct_split_0_inst_10_6),
        .inst_15_0(instruct_split_0_inst_15_0),
        .inst_15_11(instruct_split_0_inst_15_11),
        .inst_20_16(instruct_split_0_inst_20_16),
        .inst_25_0(instruct_split_0_inst_25_0),
        .inst_25_21(instruct_split_0_inst_25_21),
        .inst_31_0(dist_mem_gen_0_spo),
        .inst_31_26(instruct_split_0_inst_31_26),
        .inst_5_0(instruct_split_0_inst_5_0));
  top_bd_mux2to1_0_0 mux2to1_0
       (.a0(instruct_split_0_inst_20_16),
        .a1(instruct_split_0_inst_15_11),
        .q(mux2to1_0_q),
        .s(my_control_0_RegDst));
  top_bd_mux2to1_0_1 mux2to1_1
       (.a0(mux2to1_0_q),
        .a1(input31_0_out),
        .q(mux2to1_1_q),
        .s(my_control_0_jal));
  top_bd_mux2to1_2_0 mux2to1_2
       (.a0(my_reg_0_Qb),
        .a1(my_expend_0_im_31_0),
        .q(mux2to1_2_q),
        .s(my_control_0_ALUsrc));
  top_bd_mux2to1_3_0 mux2to1_3
       (.a0({alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero,alu_bd_1_Zero}),
        .a1(dist_mem_gen_1_spo),
        .q(mux2to1_3_q),
        .s(my_control_0_MemToReg));
  top_bd_mux2to1_4_0 mux2to1_4
       (.a0(mux2to1_3_q),
        .a1(my_pc_0_pc_add4),
        .q(mux2to1_4_q),
        .s(my_control_0_jal));
  top_bd_mux2to1_5_0 mux2to1_5
       (.a0(my_pc_0_pc_add4),
        .a1(my_simple_add_0_sum),
        .q(mux2to1_5_q),
        .s(orgate_0_c));
  top_bd_mux2to1_5_1 mux2to1_6
       (.a0(mux2to1_5_q),
        .a1(my_reg_0_Qa),
        .q(mux2to1_6_q),
        .s(my_control_0_jrn));
  top_bd_mux2to1_6_0 mux2to1_7
       (.a0(mux2to1_6_q),
        .a1(my_expand32_0_out_31_0),
        .q(mux2to1_7_q),
        .s(my_control_0_jmp));
  top_bd_mux2to1_8_0 mux2to1_8
       (.a0(my_reg_0_Qa),
        .a1(mux2to1_9_q),
        .q(mux2to1_8_q),
        .s(xorgate_0_c));
  top_bd_mux2to1_9_0 mux2to1_9
       (.a0(my_expand32_1_out_31_0),
        .a1(input16_0_out),
        .q(mux2to1_9_q),
        .s(my_control_0_lui));
  top_bd_my_control_0_0 my_control_0
       (.ALUctr(my_control_0_ALUctr),
        .ALUsrc(my_control_0_ALUsrc),
        .Branch(my_control_0_Branch),
        .Extop(my_control_0_Extop),
        .MemToReg(my_control_0_MemToReg),
        .MemWrite(my_control_0_MemWrite),
        .RegDst(my_control_0_RegDst),
        .RegWrite(my_control_0_RegWrite),
        .ShiftShamt(my_control_0_ShiftShamt),
        .func(instruct_split_0_inst_5_0),
        .jal(my_control_0_jal),
        .jmp(my_control_0_jmp),
        .jrn(my_control_0_jrn),
        .lui(my_control_0_lui),
        .nBranch(my_control_0_nBranch),
        .op(instruct_split_0_inst_31_26));
  top_bd_my_expand32_0_0 my_expand32_0
       (.in_WIDTH_0(my_shift2_0_out),
        .out_31_0(my_expand32_0_out_31_0));
  top_bd_my_expand32_0_1 my_expand32_1
       (.in_WIDTH_0(instruct_split_0_inst_10_6),
        .out_31_0(my_expand32_1_out_31_0));
  top_bd_my_expend_0_0 my_expend_0
       (.Extop(my_control_0_Extop),
        .im_15_0(instruct_split_0_inst_15_0),
        .im_31_0(my_expend_0_im_31_0));
  top_bd_my_pc_0_0 my_pc_0
       (.clk(clk_1),
        .pc_add4(my_pc_0_pc_add4),
        .pc_in(mux2to1_7_q),
        .pc_out(my_pc_0_pc_out),
        .reset(pc_reset_1));
  top_bd_my_reg_0_0 my_reg_0
       (.Qa(my_reg_0_Qa),
        .Qb(my_reg_0_Qb),
        .Ra(instruct_split_0_inst_25_21),
        .Rb(instruct_split_0_inst_20_16),
        .Rw(mux2to1_1_q),
        .WriteEnable(my_control_0_RegWrite),
        .busW(mux2to1_4_q),
        .clk(clk_1),
        .reset(res_reset_1));
  top_bd_my_right_shift2_0_0 my_right_shift2_0
       (.Result(my_right_shift2_0_Result),
        .i(my_pc_0_pc_out));
  top_bd_my_shift2_0_0 my_shift2_0
       (.in(instruct_split_0_inst_25_0),
        .out(my_shift2_0_out));
  top_bd_my_shift2_0_1 my_shift2_1
       (.in(my_expend_0_im_31_0),
        .out(my_shift2_1_out));
  top_bd_my_simple_add_0_0 my_simple_add_0
       (.a(my_pc_0_pc_add4),
        .b(my_shift2_1_out),
        .sum(my_simple_add_0_sum));
  top_bd_notgate_0_0 notgate_0
       (.a(alu_bd_1_Zero),
        .c(notgate_0_c));
  top_bd_orgate_0_0 orgate_0
       (.a(andgate_0_c),
        .b(andgate_1_c),
        .c(orgate_0_c));
  top_bd_xorgate_0_0 xorgate_0
       (.a(my_control_0_lui),
        .b(my_control_0_ShiftShamt),
        .c(xorgate_0_c));
endmodule
