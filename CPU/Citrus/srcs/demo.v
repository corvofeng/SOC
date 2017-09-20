`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2017/09/20 10:05:33
// Design Name: 
// Module Name: demo
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


module demo(



    );
  reg clock = 0;
  reg resetn = 0;
  wire [31:0] A = 1000000000;
  wire [31:0] B = 999999999;
  reg start = 0;
  wire busy;
  wire [31:0] q;
  wire [31:0] r;

  
  divider uut(
 .clock(clock),
 .resetn(resetn),
 .a(A),
 .b(B),
 .start(start),
 .busy(busy),
 .q(q),
 .r(r)
  );
  initial begin
  #50 resetn = 1;
  #10 start = 1;
  #50 start = 0;
  end
  
  always #10 clock = ~clock;
  
  
  
  
  
endmodule