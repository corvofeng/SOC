`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2017/09/19 19:45:43
// Design Name: 
// Module Name: pri_sim
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


module pri_sim();
	reg [7:0]in_data;
	reg in_enable;

	wire [2:0] out_data;
	wire out_gs;
	wire out_enable;
	
	PriorityEncoder8_3 uut(
		.in_data_n(in_data),
		.in_enable_n(in_enable),
		.out_data_n(out_data),
		.out_gs_n(out_gs),
		.out_enable_n(out_enable)
	);
	
	initial begin
		#10 in_enable = 1;
		#10	in_data = 8'b11111111;
		#10 in_enable = 0;
		#10	in_data = 8'b11111110;
		#10	in_data = 8'b11111100;
		#10	in_data = 8'b11111000;
		#10	in_data = 8'b11110000;
		#10	in_data = 8'b11100000;
		#10	in_data = 8'b11000000;
		#10	in_data = 8'b10000000;
		#10	in_data = 8'b00000000;
    end
endmodule
