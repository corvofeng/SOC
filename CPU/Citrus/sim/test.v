`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2017/09/22 13:45:28
// Design Name:
// Module Name: test
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


module test();
reg [15:0] sw = 16'h0000;

wire [15:0] led;



reg a = 0;

wire b;

Learn learn(.sw(sw),

            .led(led)
           );

assign
    a = ~a;


always b = a;
endmodule
