`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/02/02 19:39:04
// Design Name: 
// Module Name: mux2to1
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


module mux2to1
#(parameter WIDTH=8)           //指定数据宽度参数，缺省值是
(
    input [(WIDTH-1):0] a0,
    input [(WIDTH-1):0] a1,
    input s,
    output [(WIDTH-1):0] q
    );
    
    assign q = (s) ? a1 : a0;
endmodule
