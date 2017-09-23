`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2017/09/22 13:38:43
// Design Name: 
// Module Name: pipepc
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


module pipepc(
    input reg [31:0] npc,
	input wpc,
	input clk,
	input clrn,
	output reg [31:0] pc
    );
	always @ ( posedge clk ) begin
	    if ( clrn != 0 ) begin
		    pc <= 32h'00;
		end else begin
		    if ( wpc !=0 ) begin
			    pc <= npc;
			end
		end
	end
		
endmodule
