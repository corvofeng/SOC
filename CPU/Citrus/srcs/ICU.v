`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: IceTesla
// 
// Create Date: 2017/09/20 19:30:06
// Design Name:
// Module Name: ICU
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


module ICU(
	i_interrupt,
	i_addr,
	i_wr_n,
	i_rd_n,
	i_cs_n,
	i_data,
	i_inta,
	o_intr,
	o_vector
    );
	input[7:0] i_interrupt;
	input i_addr;
	input i_wr_n;
	input i_rd_n;
	input i_cs_n;
	input[7:0] i_data;
	input i_inta;
	output o_intr;
	output[7:0] o_vector;
	
	PriorityEncoder8_3 PE8_3(
		.in_data_n(),
		.in_enable_n(),
		.o_data_n(),
		.o_gs_n(),
		.o_enable_n()
	);
	
	// my_reg IRR(
		
	// );
	
endmodule
