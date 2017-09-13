`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/01/29 18:32:43
// Design Name: 
// Module Name: andgate_sim
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


module andgate_sim(

    );
    // input 
    reg [31:0] a=32'h00000000;
    reg [31:0] b=32'h00000000;
    
    //outbut
    wire [31:0] c;
    andgate #(32) u(a,b,c);    // 实例化与门的时候，设定宽度为32
    
    initial begin
    #100  a=32'hffffffff;
    #100  begin a=32'h00000000;b=32'hffffffff;end
    #100  a = 32'h007fa509;
    #100  a=32'hffffffff;
   end
endmodule
