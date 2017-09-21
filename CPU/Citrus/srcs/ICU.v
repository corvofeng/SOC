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
	i_we,
	// i_rd_n,
	i_cs_n,
	i_data,
	i_inta,
	i_clk,
	o_intr,
	o_vector
    );
	input[7:0] i_interrupt;
	input i_addr;
	input i_we;
	// input i_rd_n;
	input i_cs_n;
	input[7:0] i_data;
	input i_inta;
	input i_clk;
	output o_intr;
	output[7:0] o_vector;
	
	PriorityEncoder8_3 PR(
		.in_data_n(),
		.in_enable_n(),
		.o_data_n(),
		.o_gs_n(),
		.o_enable_n()
	);
	
	reg_8bit IRR(
		.i_data(),
		.i_clk(),
		.i_reset(),
		.i_we(),
		.o_data()
	);
	
	reg_8bit IMR(
		.i_data(),
		.i_clk(),
		.i_reset(),
		.i_we(),
		.o_data()
	);
	
	reg_8bit ISR(
		.i_data(),
		.i_clk(),
		.i_reset(),
		.i_we(),
		.o_data()
	);
	
	reg_8bit Status(
		.i_data(),
		.i_clk(),
		.i_reset(),
		.i_we(),
		.o_data()
	);
	
	
endmodule
