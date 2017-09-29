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
    input [31:0] dpc4,
	input [31:0] da,
	input [31:0] db,
	input [31:0] dimm,
	input [4:0] drn,
	input wreg,
	input m2reg,
	input wmem,
	input jal,
	input aluimm,
	input shift,
	input [3:0] aluc,
	input clk,
	input clrn,
	input [31:0]pcd,
    input [31:0]sta,
    input [31:0]cau,
    input [31:0]epc,
    input [1:0] mfc0,
    output [1:0] emfc0,
    output [31:0] esta,
    output [31:0] ecau,
    output [31:0] eepc,
    output reg [31:0] epc4,
	output reg [31:0] ea,
	output reg [31:0] eb,
	output reg [31:0] eimm,
	output reg [4:0] ern0,
	output reg ewreg,
	output reg em2reg,
	output reg ewmem,
	output reg ejal,
	output reg ealuimm,
	output reg eshift,
	output reg [31:0]pce,
	output reg [3:0] ealuc
    );
	always @ ( posedge clk ) begin
	    if ( clrn != 0 ) begin
		    epc4    <= 32'h0000_0000;
	        ea      <= 32'h0000_0000;
	        eb      <= 32'h0000_0000;
	        eimm    <= 32'h0000_0000;
	        pce    <= 32'h0000_0000;
	        ern0    <= 5'h00;
	        ewreg   <= 1'b0;
	        em2reg  <= 1'b0;
	        ewmem   <= 1'b0;
	        ejal    <= 1'b0;
            ealuimm <= 1'b0;
	        eshift  <= 1'b0;
	        ealuc   <= 4'h0;
            esta    <= 32'h0000_0000;
            ecau    <= 32'h0000_0000;
            eepc    <= 32'h0000_0000;
            emfc0   <= 2'b00;
		end else begin
		    epc4    <= dpc4;
	        ea      <= da;
	        eb      <= db;
	        eimm    <= dimm;
	        ern0    <= drn;
	        pce     <= pcd;
	        ewreg   <= wreg;
	        em2reg  <= m2reg;
	        ewmem   <= wmem;
	        ejal    <= jal;
            ealuimm <= aluimm;
	        eshift  <= shift;
	        ealuc   <= aluc;
            esta    <= sta;
            ecau    <= cau;
            eepc    <= epc;
            emfc0   <= mfc0;
		end
	end
endmodule
