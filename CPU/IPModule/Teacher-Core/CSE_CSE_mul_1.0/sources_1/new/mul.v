`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/02/28 16:50:38
// Design Name: 
// Module Name: mul
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


module mul
#(parameter WIDTH = 8)
(
    input [WIDTH-1:0] a,
    input [WIDTH-1:0] b,
    output reg [WIDTH*2-1:0] c
    );
    
    integer i;
    reg [WIDTH-1:0] y,t;
    reg [WIDTH*2-1:0] x,z;
    reg sign;
    
    always @(*)
    begin
      t = {WIDTH{a[WIDTH-1]}};
      x = {t,a};                    // 符号扩展
      y = b;
      z = {WIDTH*2{1'b0}};
      if(a[WIDTH-1] == 1)           // 被乘数是负数的处理
      begin
        x = ~x;
        x = x + 1'b1;
      end
      if(b[WIDTH-1] == 1)           // 乘数是负数的处理
      begin
        y = ~y;
        y = y + 1'b1;
      end
      for(i = 0; i<WIDTH-1; i=i+1)
      begin
        if(y[0] == 1)                // 循环
          z = z + x;
        x = x << 1;         // 被乘数左移
        y = y >> 1;         //  同时乘数右移
      end
      sign = a[WIDTH-1] ^ b[WIDTH-1];
      if(sign == 1)           // 积是负数的处理
      begin
        z = ~z;
        z = z + 1'b1;
      end
      c = z;
    end
 endmodule
