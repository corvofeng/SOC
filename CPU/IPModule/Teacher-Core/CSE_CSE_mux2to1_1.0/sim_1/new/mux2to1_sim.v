`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/02/02 19:53:04
// Design Name: 
// Module Name: mux2to1_sim
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

module mux2to1_sim(   );
    // input 
reg [7:0] a0=8'b00001001;
reg [7:0] a1=8'b10110110;
reg  s = 0;
//outbut
wire [7:0] q;
mux2to1 #(8) u(a0,a1,s,q);    // 实例化与门的时候，设定宽度为1

initial begin
#300  s=1;
end
endmodule
