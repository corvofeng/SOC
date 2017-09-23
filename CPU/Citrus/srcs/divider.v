`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2017/09/19 16:59:22
// Design Name:
// Module Name: divider
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


module divider(


           reg [7:0]a,b;
           reg clk,reset,load;

           wire [7:0]c,d;
           wire done,error;

           initial
           begin
               clk=0;
               reset=0;
               load=0;
               #5 reset=1;
               #5 reset=0;
               #5
                a=50;
               b=23;
               #3 load=1;
               #15 load=0;

               #50
                a=150;
               b=13;
               #5 load=1;
               #15 load=0;

               #150
                a=150;
               b=0;
               #15 load=1;
               #15 load=0;

               #50
                a=150;
               b=110;
               #5 load=1;
               #15 load=0;


           end

           always #3 clk=!clk;

               sque_divider m1(.a(a),.b(b),.c(c),.d(d),.done(done),.clk(clk),.reset(reset),.load(load),.error(error));
               endmodule
