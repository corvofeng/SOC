`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/01/30 00:10:16
// Design Name: 
// Module Name: xorgate
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


module xorgate
#(parameter WIDTH=8)           //指定数据宽度参数，缺省值是8
   (
    input [(WIDTH-1):0] a,     // 出具位数由参数WIDTH决定
    input [(WIDTH-1):0] b,
    output [(WIDTH-1):0] c
    );

    assign c = a ^ b;       //  2输入异或门

endmodule
