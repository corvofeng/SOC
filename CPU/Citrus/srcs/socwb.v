`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/07/06 16:08:58
// Design Name: 
// Module Name: socwb 写回模块
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
	input wm2reg,//pc来源
	input [1:0]mfc0,
	input [31:0] sta,
	input [31:0] cau,
	input [31:0] epc,
	
	output reg [31:0] wdi,//wdi
    output reg [31:0] wi
);
    always @ (wm2reg  or  walu  or  wmo) begin
        case(wm2reg)
            0:wdi <= walu;
            1:wdi <= wmo;
            default:wdi <= 32'h0000_0000;
        endcase
	end		
	
    always @ (mfc0  or  wdi  or  sta or cau or epc) begin
        case(mfc0)
            2'b00:wi <= wdi;
            2'b01:wi <= sta;
            2'b10:wi <= cau;
            2'b11:wi <= epc;
            default:wi <= 32'h0000_0000;
        endcase
    end        	

endmodule
