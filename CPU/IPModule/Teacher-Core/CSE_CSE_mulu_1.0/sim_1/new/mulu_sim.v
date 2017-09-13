`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/02/26 15:31:28
// Design Name: 
// Module Name: mulu_sim
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


module mulu_sim(

    );
// input
reg [31:0] a = 32'd9;
reg [31:0] b = 32'd12;

// output 
wire [63:0] c;

mulu #(32) u(a,b,c);

initial begin
#400 a = 32'd6;
#400 b = 32'd5;
end

endmodule
