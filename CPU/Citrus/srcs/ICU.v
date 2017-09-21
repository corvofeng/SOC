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
	i_cs,
	i_data,
	i_inta,
	i_clk,
	o_intr,
	o_vector
    );
	input[7:0] i_interrupt;
	input[1:0] i_addr;
	input i_we;
	input i_cs;
	input[7:0] i_data;
	input i_inta;
	input i_clk;
	output o_intr;
	output[7:0] o_vector;
	
	//各寄存器输入输出
	wire[7:0] ISR_data_in,ISR_data_out;
	wire[7:0] IRR_data_in,IRR_data_out;
	wire[7:0] IMR_data_in,IMR_data_out;
	wire[7:0] status_data_in,status_data_out;
	wire[7:0] PR_data_in,PR_data_out;
	
	assign IRR_data_in = i_interrupt,
		PR_data_in = ~IMR_data_out & IRR_data_out,
		ISR_data_in = PR_data_out,
		IMR_data_in = i_data,
		status_data_in = i_data,
		
	
	//ICU_ctrl控制逻辑
	wire status_we;
	wire status_reset;
	wire IMR_we;
	wire IMR_reset;
	wire ISR_we;
	wire ISR_reset;
	wire IRR_we;
	wire IRR_reset;
	wire intr;
	
	assign status_we = i_we && i_addr[1] && ~i_addr[0] && cs,
		status_reset = ~i_addr[1] && ~i_addr[0] && cs,
		IMR_we = i_we && i_addr[1] && i_addr[0] && cs,
		IMR_reset = ~i_addr[1] && ~i_addr[0] && cs,
		ISR_we = ~cs && (ISR_data_out[7]||ISR_data_out[6]||ISR_data_out[5]||ISR_data_out[4]||ISR_data_out[3]||ISR_data_out[2]||ISR_data_out[1]||ISR_data_out[0]),
		ISR_reset = ~i_addr[1] && ~i_addr[0] && cs || ~i_addr[1] && i_addr[0] && i_inta && cs,
		IRR_we = ~cs && (ISR_data_out[7]||ISR_data_out[6]||ISR_data_out[5]||ISR_data_out[4]||ISR_data_out[3]||ISR_data_out[2]||ISR_data_out[1]||ISR_data_out[0]),
		IRR_reset = ~i_addr[1] && ~i_addr[0] && cs || ~i_addr[1] && i_addr[0] && i_inta && cs;
 	
	PriorityEncoder8_3 PR(
		.in_data_n(PR_data_in),
		.in_enable_n(),
		.o_data_n(),
		.o_gs_n(),
		.o_enable_n()
	);
	
	reg_8bit IRR(
		.i_data(IRR_data_in),
		.i_clk(i_clk),
		.i_reset(IRR_reset),
		.i_we(IRR_we),
		.o_data(IRR_data_out)
	);
	
	reg_8bit IMR(
		.i_data(IMR_data_in),
		.i_clk(i_clk),
		.i_reset(IMR_reset),
		.i_we(IMR_we),
		.o_data(IMR_data_out)
	);
	
	reg_8bit ISR(
		.i_data(ISR_data_in),
		.i_clk(i_clk),
		.i_reset(ISR_reset),
		.i_we(ISR_we),
		.o_data(ISR_data_out)
	);
	
	reg_8bit Status(
		.i_data(status_data_in),
		.i_clk(i_clk),
		.i_reset(status_reset),
		.i_we(status_we),
		.o_data(status_data_out)
	);
	
	
endmodule
