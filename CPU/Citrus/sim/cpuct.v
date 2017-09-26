`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2017/09/25 17:24:33
// Design Name:
// Module Name: cpuct
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


module cpuct(

       );
reg clrn;
reg [6:0] op,func;
cpuctr ctr(
           .clrn(clrn),
           .func(func),
           .op(op)

       );
initial begin
    clrn=0;
    op=6'b00_0000;
    func=6'b00_0000;
    #1 clrn=1;
    #50 clrn=0;
end
endmodule
