`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2017/09/17 19:30:31
// Design Name:
// Module Name: seg
// Project Name:
// Target Devices:
// Tool Versions:
// Description: 用一�?32位的寄存器存输入的数据，对应8个数码管，寄存器初始化为0，目前是这样想的，后面可能不�?要寄存器，直接输�?
// 复位按钮还没有绑定，目前是一个临时的
// Dependencies:
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////


module seg(
           input_data,
           sel_n,
           seg_n,
           clk,  //系统时钟100mhz
           rst,
           cs  //复位,低电平有�?
       );
input clk;
input rst;
input cs;
// reg [31:0] input_data=32'b1000_0111_0110_0101_0100_0011_0010_0001;
input[31:0] input_data;
output reg[7:0] sel_n;
output reg[7:0] seg_n;
reg clk_50=0;
reg[25:0] div_counter = 0;
reg[2:0] scanner;

always@(posedge clk or negedge rst)  //分频400hz
begin
    if(!rst) begin
        div_counter = 0;
    end
    else if(div_counter>=125000)begin
        clk_50<=~clk_50;
        div_counter<=0;
    end else begin
        div_counter<=div_counter+1;
    end
end


always@(posedge clk_50 or negedge rst)begin  //循环扫描
    if(!rst) begin
        scanner<=0;
    end else if(scanner==3'd7) begin
        scanner<=0;
    end else begin
        scanner<=scanner+1;
    end
end

// reg[3:0] in;
function [7:0] dataToSeg;
    input reg[3:0] in;
    case(in)
        4'b0000:dataToSeg = 8'b1100_0000;//0
        4'b0001:dataToSeg = 8'b1111_1001;//1
        4'b0010:dataToSeg = 8'b1010_0100;//2
        4'b0011:dataToSeg = 8'b1011_0000;//3
        4'b0100:dataToSeg = 8'b1001_1001;//4
        4'b0101:dataToSeg = 8'b1001_0010;//5
        4'b0110:dataToSeg = 8'b1000_0010;//6
        4'b0111:dataToSeg = 8'b1111_1000;//7
        4'b1000:dataToSeg = 8'b1000_0000;//8
        4'b1001:dataToSeg = 8'b1001_0000;//9
        4'b1010:dataToSeg = 8'b1000_1000;//a
        4'b1011:dataToSeg = 8'b1000_0011;//b
        4'b1100:dataToSeg = 8'b1100_0110;//c
        4'b1101:dataToSeg = 8'b1010_0001;//d
        4'b1110:dataToSeg = 8'b1000_0110;//e
        4'b1111:dataToSeg = 8'b1000_1110;//f
        default:dataToSeg = 8'b1111_1111;
    endcase
endfunction

always@(scanner) begin
    if (cs) begin
    case(scanner)
        3'b000: begin sel_n<=8'b11111110;seg_n=dataToSeg(input_data[3:0]); end
        3'b001: begin sel_n<=8'b11111101;seg_n=dataToSeg(input_data[7:4]); end
        3'b010: begin sel_n<=8'b11111011;seg_n=dataToSeg(input_data[11:8]); end
        3'b011: begin sel_n<=8'b11110111;seg_n=dataToSeg(input_data[15:12]); end
        3'b100: begin sel_n<=8'b11101111;seg_n=dataToSeg(input_data[19:16]); end
        3'b101: begin sel_n<=8'b11011111;seg_n=dataToSeg(input_data[23:20]); end
        3'b110: begin sel_n<=8'b10111111;seg_n=dataToSeg(input_data[27:24]); end
        3'b111: begin sel_n<=8'b01111111;seg_n=dataToSeg(input_data[31:28]); end
        default: sel_n<=8'b11111111;
    endcase
    end
end
endmodule
