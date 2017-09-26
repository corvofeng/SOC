`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2017年9月25日 09:33:58
// Design Name: cpu综合复位信号
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

module init32(
           prst,rst,clk,reset
       );
input prst;//按钮复位
input rst;//看门狗输出的复位
input clk;
output reset;//系统复位信号

reg reset0=0;//复位信号临时寄存器
reg reset1=0;
reg cnt0=3'b100;
reg cnt1=3'b100;

always@(posedge clk && prst)
begin
    if(cnt0==3'b000)
    begin
        reset0=1;
        cnt0=3'b100;
    end
    else
    begin
        cnt0=cnt0-1;
        reset0=0;
    end
end

always@(posedge clk && rst)
begin
    if(cnt1==3'b000)
    begin
        reset1=1;
        cnt1=3'b100;
    end
    else
    begin
        cnt1=cnt1-1;
        reset1=0;
    end
end

always@(negedge clk)
begin
    if(reset0||reset1)
        reset=1;
    else
        reset=0;
end
endmodule
