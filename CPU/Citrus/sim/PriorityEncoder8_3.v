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
	in_data_n,//数据输入端	低电平有效
	in_enable_n,//EI使能输入端	低电平有效
	out_data_n,//数据输出端
	out_gs_n,//GS片优先编码输出端	低电平代表有输入
	out_enable_n//EI使能输出端 低电平表示EI有效但没有输入
    );
	input [7:0] in_data_n ;
	input in_enable_n ;

	output reg [2:0] out_data_n ;
	output reg out_gs_n ;
	output reg out_enable_n ;

	always @ ( in_data_n  or in_enable_n ) begin
		out_data_n[2]=in_data_n[4]&&in_data_n[5]&&in_data_n[6]&&in_data_n[7]||in_enable_n;
		out_data_n[1]=~in_data_n[4]&&in_data_n[6]&&in_data_n[7]
				||~in_data_n[5]&&in_data_n[6]&&in_data_n[7]
				||in_data_n[2]&&in_data_n[3]&&in_data_n[6]&&in_data_n[7]
				||in_enable_n;
		out_data_n[0]=in_data_n[1]&&in_data_n[3]&&in_data_n[5]&&in_data_n[7]
				||~in_data_n[4]&&in_data_n[5]&&in_data_n[7]
				||~in_data_n[2]&&in_data_n[3]&&in_data_n[5]&&in_data_n[7]
				||~in_data_n[6]&&in_data_n[7]
				||in_enable_n;
		out_enable_n=~(in_data_n[0]&&in_data_n[1]&&in_data_n[2]&&in_data_n[3]&&in_data_n[4]
					&&in_data_n[5]&&in_data_n[6]&&in_data_n[7])||in_enable_n;
		out_gs_n=in_data_n[0]&&in_data_n[1]&&in_data_n[2]&&in_data_n[3]&&in_data_n[4]
					&&in_data_n[5]&&in_data_n[6]&&in_data_n[7]||in_enable_n;
	end
endmodule
