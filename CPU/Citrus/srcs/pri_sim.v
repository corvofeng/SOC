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
		.in_data(in_data),
		.in_enable(in_enable),
		.out_data(out_data),
		.out_gs(out_gs),
		.out_enable(out_enable)
	);
	
	initial begin
		#10 in_enable = 0;
		#10	in_data = 8'b11111111;
		#10 in_enable = 1;
		#10	in_data = 8'b01111111;
		#10	in_data = 8'b00111111;
		#10	in_data = 8'b00011111;
		#10 in_enable = 0;
		#10	in_data = 8'b11111100;
		#10 in_enable = 1;
		#10	in_data = 8'b00000000;
		#10 in_enable = 0;
    end
endmodule
