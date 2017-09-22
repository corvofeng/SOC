`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2017年9月22日 19:20:39
// Design Name: 
// Module Name: timepiece_sim
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

module ctc16_sim();
reg clk = 1;
reg[15:0] wdata=0;
reg cs=0;
reg reset=0;
reg pulse0=1;
reg[15:0] address=0;
reg iow=0;
reg ior=0;

wire [15:0] rdata;
wire cout0;

ctc16 ctc(
		.CLK(clk),
		.CS(cs),
		.Reset(reset),
		.wdata(wdata),
		.pulse0(pulse0),
		.address(address),
		.IOW(iow),
		.IOR(ior),
		.rdata(rdata),
		.COUT0(cout0)
	);

initial
	begin

    //循环定时，2个clock输出一个时钟低电平,输出5个
    #100 cs=1;
    #10 address=16'hff24;//写初值寄存器
    #10 wdata=16'h0003;
    #15 iow=1;
    #10 iow=0;
    #10 address=16'hff20;//写方式寄存器
    #10 wdata=16'h0002;
    #15 iow=1;
    #10 iow=0;
	end

always #5 clk=~clk;
always #10 pulse0=~pulse0;

endmodule