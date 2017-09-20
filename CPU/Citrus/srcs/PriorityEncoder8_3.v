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
	i_data_n,//数据输入端	低电平有效
	i_enable_n,//EI使能输入端	低电平有效
	o_data_n,//数据输出端
	o_gs_n,//GS片优先编码输出端	低电平代表有输入
	o_enable_n//EI使能输出端 低电平表示EI有效但没有输入
    );
	input [7:0] i_data_n ;
	input i_enable_n ;

	output reg [2:0] o_data_n ;
	output reg o_gs_n ;
	output reg o_enable_n ;

	always @ ( i_data_n  or i_enable_n ) begin
		o_data_n[2]=i_data_n[4]&&i_data_n[5]&&i_data_n[6]&&i_data_n[7]||i_enable_n;
		o_data_n[1]=~i_data_n[4]&&i_data_n[6]&&i_data_n[7]
				||~i_data_n[5]&&i_data_n[6]&&i_data_n[7]
				||i_data_n[2]&&i_data_n[3]&&i_data_n[6]&&i_data_n[7]
				||i_enable_n;
		o_data_n[0]=i_data_n[1]&&i_data_n[3]&&i_data_n[5]&&i_data_n[7]
				||~i_data_n[4]&&i_data_n[5]&&i_data_n[7]
				||~i_data_n[2]&&i_data_n[3]&&i_data_n[5]&&i_data_n[7]
				||~i_data_n[6]&&i_data_n[7]
				||i_enable_n;
		o_enable_n=~(i_data_n[0]&&i_data_n[1]&&i_data_n[2]&&i_data_n[3]&&i_data_n[4]
					&&i_data_n[5]&&i_data_n[6]&&i_data_n[7])||i_enable_n;
		o_gs_n=i_data_n[0]&&i_data_n[1]&&i_data_n[2]&&i_data_n[3]&&i_data_n[4]
					&&i_data_n[5]&&i_data_n[6]&&i_data_n[7]||i_enable_n;
	end
endmodule
