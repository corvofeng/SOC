`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/02/28 18:15:00
// Design Name: 
// Module Name: mul_sim
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


module mul_sim(

    );
    // input
    reg [31:0] a = 32'd9;
    reg [31:0] b = 32'd12;
    
    // output 
    wire [63:0] c;
    
    mul #(32) u(a,b,c);
    
    initial begin
    #400 a = 32'hfffffffe;
    #400 b = 32'hfffffffe;
    end

endmodule
