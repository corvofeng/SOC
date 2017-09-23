`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2016/12/03 17:13:25
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


module timepiece_sim();
//input wdata,CS,CLK,Reset,pulse0,address,IOW,IOR
reg CLK=1;
reg [31:0] wdata=0;
reg CS=0;
reg Reset=0;
reg pulse0=1;
reg [31:0] address=0;
reg IOW=0;
reg IOR=0;
reg timing=0;
reg counting=0;

//output rdata,COUT0
wire [31:0] rdata;
wire COUT0;
wire [31:0] COUT2;

timepiece uut(
              //input wdata,CS,CLK,Reset,pulse0,address,IOW,IOR
              //output rdata,COUT0
              .CLK(CLK),
              .CS(CS),
              .wdata(wdata),
              .Reset(Reset),
              .pulse0(pulse0),
              .address(address),
              .IOW(IOW),
              .IOR(IOR),
              .rdata(rdata),
              .COUT0(COUT0),
              .timing(timing),
              .counting(counting),
              .COUT2(COUT2)
          );

initial
begin
    #100 CS=1;
    //非循环定时，2个clock输出一个时钟低电平
    #10 address[31:0]=8'hFFFF_FC24;//写初值寄存器
    #10 wdata[31:0]=8'h0000_0003;
    #10 IOW=1;
    #10 IOW=0;
    #10 address=8'hFFFF_FC20;//写方式寄存器
    #10 wdata=8'h0000_0000;
    #10 IOW=1;
    #10 IOW=0;
    #10 timing=1;
    //循环定时，2个clock输出一个时钟低电平,输出5个
    #30 timing=0;
    #10 address=8'hFFFF_FC24;//写初值寄存器
    #10 wdata=8'h0000_0003;
    #10 IOW=1;
    #10 IOW=0;
    #10 address=8'hFFFF_FC20;//写方式寄存器
    #10 wdata=8'h0000_0003;
    #10 IOW=1;
    #10 IOW=0;
    #10 timing=1;
    //非循环计数,5个pulse0
    #150 timing=0;
    #10 address=8'hFFFF_FC24;//写初值寄存器
    #10 wdata=8'h0000_0005;
    #10 IOW=1;
    #10 IOW=0;
    #10 address=8'hFFFF_FC20;//写方式寄存器
    #10 wdata=8'h0000_0001;
    #10 IOW=1;
    #10 IOW=0;
    #10 counting=1;
    #10 address=8'hFFFF_FC20;//读状态寄存器
    #100 counting=0;
    #10 IOR=1;
    #10 IOR=0;
    //循环计数，每次2个pulse0，跑5次
    #10 Reset=1;//Reset
    #10 Reset=0;
    #10 address=8'hFFFF_FC24;//写初值寄存器
    #10 wdata=8'h0000_0002;
    #10 IOW=1;
    #10 IOW=0;
    #10 address=8'hFFFF_FC20;//写方式寄存器
    #10 wdata=8'h0000_0003;
    #10 IOW=1;
    #10 IOW=0;
    #10 counting=1;
    #10 address=8'hFFFF_FC20;//读状态寄存器
    #190 counting=0;
    #10 IOR=1;
    #10 IOR=0;
end

always #5 CLK = ~CLK;

always #10 pulse0=~pulse0;


endmodule
