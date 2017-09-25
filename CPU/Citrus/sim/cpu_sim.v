`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2017/09/25 10:43:31
// Design Name: 
// Module Name: cpu_sim
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


module cpu_sim(

    );
    reg clk,clrn;
    wire [31:0]pc,inst;
    cpu cpu(
      .clk(clk),
      .clrn(clrn),
      .pc(pc),
      .inst(inst)
        );
    initial begin
          #1 clrn=1;
             clk=0;
          #5 clrn = 0;
         #500 clrn = 1;           
           end
           always #5 clk=~clk;
endmodule
