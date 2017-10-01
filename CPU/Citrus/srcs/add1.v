`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:IceTesla
//
// Create Date: 2017/10/01 19:37:29
// Design Name:
// Module Name: add1
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

module add1 (a, b, ci, s, co);
input a;
input b;
input ci;
output s;
output co;
wire S1, T1, T2, T3;
// -- statements -- //
xor x1 (S1, a, b);
xor x2 (s, S1, ci);
and A1 (T3, a, b );
and A2 (T2, b, ci);
and A3 (T1, a, ci);
or O1 (co, T1, T2, T3 );
endmodule
