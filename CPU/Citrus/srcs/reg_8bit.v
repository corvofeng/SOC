`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer: IceTesla
//
// Create Date: 2017/09/21 09:23:24
// Design Name:
// Module Name: reg_8bit
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


module reg_8bit
        #(parameter WIDTH = 8)
        (
           i_data,
           i_clk,
           i_reset,
           i_we,
           o_data
       );
output wire [WIDTH-1:0] o_data;
input wire [WIDTH-1:0] i_data;
input wire i_clk;
input wire i_reset;
input wire i_we;

reg[WIDTH-1:0] register;

assign o_data = register;

always @(posedge i_clk) begin
    if(i_reset==1) begin
        register = 32'b00000000;
    end else if(i_we==1)begin
        register <=i_data;
    end
end

endmodule
