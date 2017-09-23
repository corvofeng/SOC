`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/07/06 16:08:58
// Design Name: 
// Module Name: socexe  exeÄ£¿é
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


module socexe (
    input reg [31:0] epc4,
	input reg [31:0] ea,
	input reg [31:0] eb,
	input reg [31:0] eimm,
	input reg [4:0] ern0,
	input reg ealuimm,
	input reg eshift,
	input reg [3:0] ealuc,
	output reg [31:0] ealu,
	output reg [31:0] eb,
	output reg [4:0] ern,
);
		

endmodule
