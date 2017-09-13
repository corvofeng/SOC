`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/01/30 00:23:16
// Design Name: 
// Module Name: nxorgate_som
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


module nxorgate_som(

    );
    // input 
reg [31:0] a=32'h00000000;
reg [31:0] b=32'h00000000;

//outbut
wire [31:0] c;
 nxorgate #(32) u(a,b,c);    // 实例化异或非门的时候，设定宽度为32

initial begin
#100  a=32'hffffffff;
#100  begin a=32'h00000000;b=32'hffffffff;end
#100  b = 32'h007fa509;
#100  begin a=32'hffffffff;b=32'hffffffff;end
end    
endmodule
