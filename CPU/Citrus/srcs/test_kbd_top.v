`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2017/09/20 18:56:25
// Design Name: 
// Module Name: test_kbd_top
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


module test_kbd_top(
	reset,cs,clk,ior,address,col,line,
	sel_n,seg_n,rst
    );
	input reset,cs,clk,ior,rst;
	input [1:0] address;
	input[3:0] col;
	output [3:0] line;
	// output[15:0] ioread_data;
	// input[32:0] input_data;
	output [7:0] sel_n,seg_n;
	wire[31:0] tmp;

	seg segtest(
		.clk(clk),.rst(rst),.input_data(tmp),
		.sel_n(sel_n),.seg_n(seg_n)
		);

	key16 keytest(
		.reset(reset),.cs(cs),.clk(clk),.ior(ior),
		.address(address),.col(col),.line(line),
		.ioread_data(tmp)
		);

endmodule
