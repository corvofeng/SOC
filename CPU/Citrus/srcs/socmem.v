`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/07/06 16:08:58
// Design Name: 
// Module Name: socmem  memÄ£¿é
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


module socmem (
    input mwmem,
    input clk,
	input [31:0] malu,
	input [31:0] mb,
	output [31:0] mmo
);
    wire clkn;
    assign clkn = ~clk;
    
    ram64k mem(
        .addr(malu),
        .data_in(mb), 
        .clk(clkn), 
        .we(mwmen), 
        .data_out(mmo)
        );
	
endmodule