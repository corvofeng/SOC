`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2017/09/22 13:38:43
// Design Name:
// Module Name: pipeir
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


module pipeir(
           input reg [31:0] pc4,
           input reg [31:0] ins,
           input wir,
           input clk,
           input clrn,
           output reg [31:0] dpc4,
           output reg [31:0] inst
       );
always @ ( posedge clk ) begin
    if ( clrn != 0 ) begin
        dpc4 <= 32'h0000_0000;
        inst <= 32'h0000_0000;
    end else begin
        if ( wir !=0 ) begin
            dpc4 <= pc4;
            inst <= ins;
        end
    end
end

endmodule
