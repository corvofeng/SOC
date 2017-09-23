`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2017/09/22 13:38:43
// Design Name: 
// Module Name: pipeemreg
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


module pipeemreg(
	input reg [31:0] ealu,
	input reg [31:0] eb,
	input reg [4:0] ern,
	input reg ewerg,
	input reg em2reg,
	input reg ewmem,
	input clk,
	input clrn,
	output reg [31:0] malu,
	output reg [31:0] mb,
	output reg [4:0] mrn,
	output reg mwerg,
	output reg mm2reg,
	output reg mwmem,

    );
	always @ ( posedge clk ) begin
	    if ( clrn != 0 ) begin
		    malu   <= 32h'00;
	        mb     <= 32h'00;
	        mrn    <= 5b'00000;
	        mwerg  <= 0;
	        mm2reg <= 0;
	        mwmem  <= 0;
		end else begin
		    malu   <= ealu;
	        mb     <= eb;
	        mrn    <= ern;
	        mwerg  <= ewerg;
	        mm2reg <= em2reg;
	        mwmem  <= ewmem;
		end
	end
		
endmodule