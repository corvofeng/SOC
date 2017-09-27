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
	input [31:0] ealu,
	input [31:0] eb,
	input [31:0] pce,
	input [4:0] ern,
	input [31:0] ealu,
	input ewreg,
	input em2reg,
	input ewmem,
	input clk,
	input clrn,
	output reg [31:0] malu,
	output reg [31:0] pcm,
	output reg [31:0] mb,
	output reg [4:0] mrn,
	output reg mwreg,
	output reg mm2reg,
	output reg mwmem
    );
    
	always @ ( posedge clk ) begin
	    if ( clrn != 0 ) begin
		    malu   <= 32'h0000_0000;
	        mb     <= 32'h0000_0000;
	        pcm    <= 32'h0000_0000;
	        mrn    <= 5'h00;
	        mwreg  <= 1'b0;
	        mm2reg <= 1'b0;
	        mwmem  <= 1'b0;
		end else begin
		    malu   <= ealu;
	        mb     <= eb;
	        mrn    <= ern;
	        pcm    <= pce;
	        mwreg  <= ewreg;
	        mm2reg <= em2reg;
	        mwmem  <= ewmem;
		end
	end
		
endmodule
