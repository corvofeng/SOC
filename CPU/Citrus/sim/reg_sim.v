`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2017/09/25 20:46:19
// Design Name: 
// Module Name: reg_sim
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


module reg_sim(

    );
   reg clrn,clk;
    reg [4:0] ra,rb,wn;
    reg [31:0]i;
    reg32 reg32(
       .clrn(clrn),
       .ra(ra),
       .rb(rb),
       .clk(clk),
       .wn(wn)
        );
    initial begin
           wn= 5;
           clrn=0;
           clk=0;
           #1 clrn=1;
          #50 clrn=0;
              ra=0;
              rb=0;
           #70 ra=5'b01101;
          end
          always #5 clk=~clk;

endmodule
