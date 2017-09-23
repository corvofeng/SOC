`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2017年9月22日 19:20:39
// Design Name: 定时/计数器仿真测试
// Module Name:
// Project Name:
// Target Devices:
// Tool Versions:
// Description:
//
// Dependencies:
//
// Revision:
//
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////

module ctc16_sim();
reg clk = 1;
reg[15:0] wdata=0;
reg cs=0;
reg reset=0;
reg pulse1=1;
reg[15:0] address=0;
reg iow=0;
reg ior=0;

wire [15:0] rdata;
wire cout1;

ctc16 ctc(
          .CLK(clk),
          .CS(cs),
          .Reset(reset),
          .wdata(wdata),
          .pulse1(pulse1),
          .address(address),
          .IOW(iow),
          .IOR(ior),
          .rdata(rdata),
          .COUT1(cout1)
      );

initial
begin
    //循环定时，2个clock输出一个时钟低电平
    #100 cs=1;
    // #10 address=16'hff26;//写初值寄存器
    // #10 wdata=16'h0003;
    // #10 iow=1;
    // #10 iow=0;
    // #10 address=16'hff22;//写方式寄存器
    // #10 wdata=16'h0002;
    // #10 iow=1;
    // #10 iow=0;
    // //非循环定时3个clk输出一个低电平
    // #90 address=16'hff26;
    // #10 wdata=16'h0004;
    // #10 iow=1;
    // #10 iow=0;
    // #10 address=16'hff22;
    // #10 wdata=16'h0000;
    // #10 iow=1;
    // #10 iow=0;
    //循环计数
    // #60 reset=1;
    // #10 reset=0;
    #10 address=16'hff26;//写初值寄存器
    #10 wdata=16'h0004;
    #10 iow=1;
    #10 iow=0;
    #10 address=16'hff22;//写方式寄存器
    #10 wdata=16'h0003;
    #10 iow=1;
    #10 iow=0;
    #10 address=16'hff26;
    #20 ior=1;
    // #10 ior=0;


end



always #5 clk=~clk;
always #10 pulse1=~pulse1;

endmodule
