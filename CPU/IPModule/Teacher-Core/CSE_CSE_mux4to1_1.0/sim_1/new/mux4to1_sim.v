`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/02/03 18:41:17
// Design Name: 
// Module Name: mux4to1_sim
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


module mux4to1_sim(

    );
// input
reg [7:0] a0 = 8'b00000000;
reg [7:0] a1 = 8'b00010001;
reg [7:0] a2 = 8'b00100010;
reg [7:0] a3 = 8'b00110011;

reg [1:0] s = 2'b00;

//output
wire [7:0] q;

mux4to1 #(8) u(a0,a1,a2,a3,s,q);

initial begin
#200 s = 2'b01;
#200 s = 2'b10;
#200 s = 2'b11;
end
endmodule
