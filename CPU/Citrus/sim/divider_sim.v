`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:IceTesla
//
// Create Date: 2017/09/20 10:05:33
// Design Name:
// Module Name: divider_sim
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


module divider_sim(



       );
reg clock = 0;
reg reset = 1;
wire [31:0] A = 32'h8000_0000;
wire [31:0] B = 32'h7d5f_8a74;
reg start = 0;
wire busy;
wire [31:0] q;
wire [31:0] r;
reg symbol;


divider uut(
            .clock(clock),
            .reset(reset),
            .a(A),
            .b(B),
            .start(start),
            .busy(busy),
            .symbol(symbol),
            .q(q),
            .r(r)
        );
initial begin
    #50 reset = 0;
    #10 start = 1;symbol = 0;
    #50 start = 0;
    #1000 start = 1; symbol =1;
    #50 start = 0;
end

always #10 clock = ~clock;





endmodule
