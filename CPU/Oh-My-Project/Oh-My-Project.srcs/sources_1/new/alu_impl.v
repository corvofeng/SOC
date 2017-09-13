`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/07/05 11:38:58
// Design Name: 
// Module Name: alu_impl
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module alu_impl(
    Zero, 
    Overflow,
    Result,
    in1,
    in2,
    SUBctr,     // 判断加法减法         0:add 1:sub
    OPctr,      // 控制哪种运算结果输出 
    OVctr,      // 是否进行溢出判断     0:No   1:Yes
    SIGctr      // 选择ALU,slt,sltu     0:sltu 1:slt
    );
    output Zero, Overflow;
    output [31:0] Result;
    input [31:0] in1, in2;
    input SUBctr, OVctr, SIGctr;
    input [2:0] OPctr;



endmodule
