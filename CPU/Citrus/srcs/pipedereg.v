`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2017/09/22 13:38:43
// Design Name: 
// Module Name: pipedereg
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


module pipedereg(
    input reg [31:0] dpc4,
	input reg [31:0] da,
	input reg [31:0] db,
	input reg [31:0] dimm,
	input reg [4:0] drn,
	input reg werg,
	input reg m2reg,
	input reg wmem,
	input reg jal,
	input reg aluimm,
	input reg shift,
	input reg [3:0] aluc,
	input clk,
	input clrn,
    output reg [31:0] epc4,
	output reg [31:0] ea,
	output reg [31:0] eb,
	output reg [31:0] eimm,
	output reg [4:0] ern0,
	output reg ewerg,
	output reg em2reg,
	output reg ewmem,
	output reg ejal,
	output reg ealuimm,
	output reg eshift,
	output reg [3:0] ealuc
    );
	always @ ( posedge clk ) begin
	    if ( clrn != 0 ) begin
		    epc4    <= 32h'00;
	        ea      <= 32h'00;
	        eb      <= 32h'00;
	        eimm    <= 32h'00;
	        ern0    <= 5b'00000;
	        ewerg   <= 0;
	        em2reg  <= 0;
	        ewmem   <= 0;
	        ejal    <= 0;
            ealuimm <= 0;
	        eshift  <= 0;
	        ealuc   <= 4b'0000;
		end else begin
		    epc4    <= dpc4;
	        ea      <= da;
	        eb      <= db;
	        eimm    <= dimm;
	        ern0    <= drn;
	        ewerg   <= werg;
	        em2reg  <= m2reg;
	        ewmem   <= wmem;
	        ejal    <= jal;
            ealuimm <= aluimm;
	        eshift  <= shift;
	        ealuc   <= aluc;
		end
	end
		
endmodule
