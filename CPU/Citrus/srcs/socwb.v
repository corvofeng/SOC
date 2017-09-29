`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2016/07/06 16:08:58
// Design Name:
// Module Name: socwb д��ģ��
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


module socwb (
    input [31:0] wmo,//wmo
	input [31:0] walu,//walu
	input wm2reg,//pc��Դ
	output reg [31:0] wdi//wdi
);
    always @ (wm2reg  or  walu  or  wmo) begin
        case(wm2reg)
            0:wdi <= walu;
            1:wdi <= wmo;
            default:wdi <= 32'h0000_0000;
        endcase
	end		
endmodule
