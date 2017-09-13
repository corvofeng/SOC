`timescale 1ns / 1ps
/*
 *=============================================================================
 *    Filename:instruct_split.v
 *
 *     Version: 1.0
 *  Created on: July 10, 2016
 *    
 *      Author: corvo
 *=============================================================================
 */
 
// 将指令分解 
module instruct_split(inst_31_26, inst_25_0, inst_25_21,
    inst_20_16, inst_15_11, inst_10_6, inst_5_0, inst_15_0, inst_31_0);
    input[31:0] inst_31_0;
    output[5:0] inst_31_26, inst_5_0;
    output[4:0] inst_25_21, inst_20_16, inst_15_11, inst_10_6;
    output[15:0] inst_15_0;
    output[25:0] inst_25_0;

    reg[5:0] inst_31_26, inst_5_0;
    reg[4:0] inst_25_21, inst_20_16, inst_15_11, inst_10_6;
    reg[15:0] inst_15_0;
    reg[25:0] inst_25_0;

    always @* begin
        inst_5_0 = inst_31_0[5:0];
        inst_10_6 = inst_31_0[10:6];
        inst_15_0 = inst_31_0[15:0];
        inst_25_0 = inst_31_0[25:0];
        inst_15_11 = inst_31_0[15:11];
        inst_20_16 = inst_31_0[20:16];
        inst_25_21 = inst_31_0[25:21];
        inst_31_26 = inst_31_0[31:26];
    end

endmodule
