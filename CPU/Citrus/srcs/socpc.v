`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2016/07/06 16:08:58
// Design Name:
// Module Name: socpc  pc
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


module socpc (
           input [31:0] pc,//pc
           //input reg [31:0]  ,//npc0
           input [31:0] bpc,//npc1
           input [31:0] dpc,//npc2
           input [31:0] jpc,//npc3
           input [1:0] pcsource,//pcæº?
           output [31:0] pc4,//pc+4
           output [31:0] ins,//ins
           output reg [31:0] npc//ins

       );
assign pc4 = pc + 31'h4;
wire[31:0] tpc;
assign tpc[29:0]=pc[31:2],
       tpc[31:30]=2'b00;

always @ ( pcsource or pc4 or bpc or dpc or jpc ) begin//db
    case(pcsource)
        2'b00:npc <= pc4;
        2'b01:npc <= bpc;
        2'b10:npc <= dpc;
        2'b11:npc <= jpc;
        default:npc <= 32'h0000_0004;
    endcase
end

rom64k instmem(
           .addr(tpc),
           .data(ins)
       );

endmodule
