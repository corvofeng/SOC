`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/19/2017 09:08:12 AM
// Design Name: 
// Module Name: ram64k
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


/*
 *
 */
module ram64k(addr, data_in, clk, we, data_out);
  input[15:0] addr;       // 输入地址
  input[31:0] data_in;    // 输入数据
  input clk;              // 时钟
  input we;               // 使能
  output[31:0] data_out;  // 数据输出

  dist_mem_gen_ram ram(
    .a(addr),
    .d(data_in),
    .clk(clk),
    .we(we),
    .spo(data_out)
  );
endmodule
