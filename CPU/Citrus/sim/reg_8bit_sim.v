`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2017/09/21 14:10:24
// Design Name:
// Module Name: reg_8bit_sim
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


module reg_8bit_sim();
reg [7:0] i_data;
reg i_clk = 0;
reg i_reset;
reg i_we;

wire[7:0] o_data;

reg_8bit uut(
             .i_data(i_data),
             .i_clk(i_clk),
             .i_reset(i_reset),
             .i_we(i_we),
             .o_data(o_data)
         );

initial begin
    i_we = 1;
    #10 i_reset =1;
    #10 i_we = 0;i_reset=0;
    #10 i_data = 8'b11110000; i_we = 1;
    #10 i_we = 0;
    #10 i_data = 8'b00000011;
    #10 i_reset = 1;
    #10 i_reset = 0;

end

always #1 i_clk = ~i_clk;
endmodule
