`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: IceTesla
// 
// Create Date: 2017/09/19 16:51:41
// Design Name: 
// Module Name: PriorityEncoder8_3
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


module PriorityEncoder8_3(
	in_data,//数据输入端
	in_enable,//使能输入端,1
	out_data,//数据输出端
	out_gs,//片优先编码输出端
	out_enable//使能输出端
    );
	input [7:0] in_data ;
	input in_enable ;

	output reg [2:0] out_data ;
	output reg out_gs ;
	output reg out_enable ;

	always @ ( in_data  or in_enable ) begin
		out_data[2]=(in_data[4]||in_data[5]||in_data[6]||in_data[7])&&in_enable;
		out_data[1]=(in_data[2]&&~in_data[4]&&~in_data[5]
					||in_data[3]&&~in_data[4]&&~in_data[5]
					||in_data[6]
					||in_data[7])&&in_enable;
		out_data[0]=(in_data[1]&&~in_data[2]&&~in_data[4]&&~in_data[6]
					||in_data[3]&&~in_data[4]&&~in_data[6]
					||in_data[5]&&~in_data[6]
					||in_data[7])&&in_enable;
		out_enable=~in_data[0]&&~in_data[1]&&~in_data[2]&&~in_data[3]&&~in_data[4]
					&&~in_data[5]&&~in_data[6]&&~in_data[7]&&in_enable;
		out_gs=(in_data[0]||in_data[1]||in_data[2]||in_data[3]||in_data[4]
					||in_data[5]||in_data[6]||in_data[7])&&in_enable;
	end
endmodule
