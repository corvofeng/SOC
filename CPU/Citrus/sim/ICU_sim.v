`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2017/09/22 09:05:25
// Design Name: 
// Module Name: ICU_sim
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


module ICU_sim();
	reg[7:0] i_interrupt;
	reg[1:0] i_addr;
	reg i_we;
	reg i_cs;
	reg[7:0] i_data;
	reg i_inta;
	reg i_clk = 0;
	wire o_intr;
	wire[7:0] o_vector;
	
	wire[7:0]IRR_data_in;
	wire[7:0]IRR_data_out;
	wire IRR_we;
	wire IRR_reset;
	
	wire[7:0]PR_data_in;
	wire[7:0]PR_data_out;
	wire PR_enable_o;
	wire PR_gs;
	wire PR_enable_i;
	wire[2:0] PR_temp;
	
	wire[7:0]ISR_data_in;
	wire[7:0]ISR_data_out;
	wire ISR_we;
	wire ISR_reset;
	
	wire[7:0]IMR_data_in;
	wire[7:0]IMR_data_out;
	wire IMR_we;
	wire IMR_reset;
	
	wire[7:0]status_data_in;
	wire[7:0]status_data_out;
	wire status_we;
	wire status_reset;
	
	
	
	
	
	ICU uut(
		.i_interrupt(i_interrupt),
		.i_addr(i_addr),
		.i_we(i_we),
		.i_cs(i_cs),
		.i_data(i_data),
		.i_inta(i_inta),
		.i_clk(i_clk),
		.o_intr(o_intr),
		.o_vector(o_vector),
		.ISR_data_in(ISR_data_in),
		.ISR_data_out(ISR_data_out),
		.IRR_data_in(IRR_data_in),
		.IRR_data_out(IRR_data_out),
		.IMR_data_in(IMR_data_in),
		.IMR_data_out(IMR_data_out),
		.status_data_in(status_data_in),
		.status_data_out(status_data_out),
		.PR_data_in(PR_data_in),
		.PR_data_out(PR_data_out),
		.status_we(status_we),
		.status_reset(status_reset),
		.IMR_we(IMR_we),
		.IMR_reset(IMR_reset),
		.ISR_we(ISR_we),
		.ISR_reset(ISR_reset),
		.IRR_we(IRR_we),
		.IRR_reset(IRR_reset),
		.PR_enable_o(PR_enable_o),
		.PR_gs(PR_gs),
		.PR_enable_i(PR_enable_i),
		.PR_temp(PR_temp)
	);
	
	initial begin
		i_interrupt = 8'b00000000;
		i_data = 8'b01010101;
		i_cs = 0;
		i_addr = 2'b00;
		i_we = 0;
		i_inta = 0;
		#5 i_cs = 1;
		#5 i_addr = 2'b10;i_interrupt = 8'b00000001;
		#5 i_we = 1;
		#5 i_cs = 0 ;i_we = 0;
		#5 i_cs = 1; i_we = 1;i_addr = 2'b11;i_data = 8'b00000001;
		#5 i_cs = 0;i_we = 0;
		#5 i_cs =1;i_addr = 2'b01; i_inta = 1;
    end
	
	always #0.5 i_clk = ~i_clk;
endmodule
