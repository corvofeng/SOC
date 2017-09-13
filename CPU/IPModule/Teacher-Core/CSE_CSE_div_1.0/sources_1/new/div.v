`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/03/014 21:25:31
// Design Name: 
// Module Name: div
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


module div
 #(parameter WIDTH = 8)   
    (
    input [WIDTH-1:0] a,
    input [WIDTH/2-1:0] b,
    input clk,
    input start,
    input resetn,
    output [WIDTH-1:0] q,    // 商
    output [WIDTH/2-1:0] r,    // 余数
    output reg busy     // 正在做除法
    );
    
    reg [WIDTH-1:0] regq;
    reg [WIDTH/2-1:0] regb;
    reg [WIDTH/2-1:0] regr;
    reg [WIDTH-2:0] count;
    reg r_sign;
    reg result_sign;
    
    wire [WIDTH-1:0] qq;
    wire [WIDTH/2-1:0] rr;
    wire [WIDTH/2:0] suboradd;
    assign suboradd = r_sign ? {regr,qq[WIDTH-1]}+{1'b0,regb} : {regr,qq[WIDTH-1]}-{1'b0,regb};
    assign rr = r_sign ? regr + regb : regr;
    assign r = a[WIDTH-1] ? ~rr+1 : rr;
    assign qq = regq;
    assign q = result_sign ? ~qq+1 : qq;
   
    always @(posedge clk or negedge resetn)
    begin
      if(resetn == 0)
      begin
        count  <= {WIDTH-1{1'b1}};
        busy   <= 1'b0;
      end else
      begin
        if(start)
        begin
          regr <= {WIDTH{1'B0}};
          r_sign <= 1'b0;
          if(a[WIDTH-1] == 0)
            regq <= a;
          else
            regq <= ~a+1;          //被除数为负数
          if(b[WIDTH/2-1] == 0)
            regb <= b;
          else
            regb <= ~b+1;         // 除数为负数
          result_sign <= a[WIDTH-1] ^ b[WIDTH/2-1];
          count <= {WIDTH-1{1'b1}};
          busy <=1'b1;
        end else
        if(busy)
        begin
          regr <= suboradd[WIDTH/2-1:0];
          r_sign <= suboradd[WIDTH/2];
          regq <={regq[WIDTH-2:0],~suboradd[WIDTH/2]};
          count <= count >> 1;
          if(count == {WIDTH-1{1'b0}}) busy <= 1'b0;
        end
      end
    end
endmodule
