`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/02/26 14:17:23
// Design Name: 
// Module Name: mulu
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


/* module mulu
(
    input [31:0] a,
    input [31:0] b,
    output reg [63:0] c
    );
    
    integer i;
    reg [31:0] y,t;
    reg [63:0] x,z;
    
    always @(*)
    begin
      //t = {32{0}};
      x = {32'h00000000,a};
      z = {64'h0000000000000000};
      y = b;
      for(i = 0; i<32; i=i+1)
      begin
        if(y[0] == 1)                // 循环的
          z = z + x;
        x = x << 1;         // 被乘数左移
        y = y >> 1;         //  同时乘数右移
      end
      c = z;
    end
endmodule  */

module mulu
#(parameter WIDTH = 8)
(
    input [WIDTH-1:0] a,
    input [WIDTH-1:0] b,
    output reg [WIDTH*2-1:0] c
    );
    
    integer i;
    reg [WIDTH-1:0] y,t;
    reg [WIDTH*2-1:0] x,z;
    
    always @(*)
    begin
      t = {WIDTH{1'b0}};
      x = {t,a};
      z = {WIDTH*2{1'b0}};
      y = b;
      for(i = 0; i<WIDTH; i=i+1)
      begin
        if(y[0] == 1)                // 循环
          z = z + x;
        x = x << 1;         // 被乘数左移
        y = y >> 1;         //  同时乘数右移
      end
      c = z;
    end
endmodule
