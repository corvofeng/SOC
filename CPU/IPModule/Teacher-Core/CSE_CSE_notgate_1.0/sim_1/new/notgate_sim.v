`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/01/29 23:04:25
// Design Name: 
// Module Name: notgate_sim
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


module notgate_sim(

    );
    // input 
reg [31:0] a=32'h00000000;

//outbut
wire [31:0] c;
 notgate #(32) u(a,c);    // 实例化非门的时候，设定宽度为32

initial begin
#100  a=32'hffffffff;
#100  a=32'hf070ff5f;
end
endmodule
