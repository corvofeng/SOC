`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/02/03 18:16:05
// Design Name: 
// Module Name: mux4to1
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


module mux4to1
#(parameter WIDTH = 8)
(    input [WIDTH-1:0] a0,
     input [WIDTH-1:0] a1,
     input [WIDTH-1:0] a2,
     input [WIDTH-1:0] a3,
     input [1:0] s,
     output reg [WIDTH-1:0] q
    );
    
    always @(*)
    begin
      case(s)
        2'b00:q = a0;
        2'b01:q = a1;
        2'b10:q = a2;
        2'b11:q = a3;
        default q=3'bzzz;
      endcase
    end
endmodule
