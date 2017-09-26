`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 09/18/2017 04:06:30 PM
// Design Name:
// Module Name: Learn_sim
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


module Learn_sim();
reg [15:0] sw = 16'h0000;
wire [15:0] led;
reg gs = 0;
reg eo = 0;
reg [2:0] in = 3'b000;

wire[7:0] out;

function[7:0] getPR_out;
    input[2:0] in;
    input gs;
    input eo;
    case({gs,eo,in})
        5'b01111:getPR_out = 8'b00000001;
        5'b01110:getPR_out = 8'b00000010;
        5'b01101:getPR_out = 8'b00000100;
        5'b01100:getPR_out = 8'b00001000;
        5'b01011:getPR_out = 8'b00010000;
        5'b01010:getPR_out = 8'b00100000;
        5'b01001:getPR_out = 8'b01000000;
        5'b01000:getPR_out = 8'b10000000;
        default:getPR_out = 8'b00000000;
    endcase
endfunction

Learn learn(.sw(sw),
            .led(led)
           );
assign out = getPR_out(in,gs,eo);

initial begin
    #1 in = in + 1;
    #1 eo = 1;in = in + 1;
    #1 eo = 0;gs = 1;in = in + 1;
    #1 eo = 1;in = in + 1;
end
always #10 sw = sw + 1;
endmodule
