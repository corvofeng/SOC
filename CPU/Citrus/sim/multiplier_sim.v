`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:IceTesla
//
// Create Date: 2017/10/01 19:21:53
// Design Name:
// Module Name: multiplier_sim
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


module multiplier_sim(

    );

reg[31:0] a;
reg[31:0] b;
reg symbol = 0;

wire [63:0] o;

multiplier uut(
    .a(a),
    .b(b),
    .symbol(symbol),
    .o(o)
    );

initial begin
     a = 32'hFa4b_7d9f;
     b = 32'h4d6c_4e3a;
     #1000 symbol = 1;
end
endmodule
