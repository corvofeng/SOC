`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/07/06 16:08:58
// Design Name: 
// Module Name: socid  idÄ£¿é
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


module socid (
    input reg [31:0] dpc4,//pc
	input reg [31:0] inst,//Ö¸Áî
	
  	output reg [31:0] da,//dpc/da
	output reg [31:0] db,
	output reg [31:0] dimm,
	output reg [4:0] drn,
	output reg werg,
	output reg m2reg,
	output reg wmem,
	output reg jal,
	output reg aluimm,
	output reg shift,
	output reg [3:0] aluc,
	output reg [31:0] jpc,
	output reg [31:0] bpc,

);
		

endmodule
