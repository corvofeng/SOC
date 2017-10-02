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
           input [1:0] pcsource,//pc��?
           output [31:0] pc4,//pc+4
           output [31:0] ins,//ins
           //output reg [31:0] npc,//ins

           input [1:0] selpc, //select pc source
           input [31:0] epc,
           output[31:0] next_pc
       );
assign pc4 = pc + 31'h4;
wire[31:0] tpc;
assign tpc[29:0]=pc[31:2],
       tpc[31:30]=2'b00;

reg [31:0] npc;
reg [31:0] next_pc;

always @ ( pcsource or pc4 or bpc or dpc or jpc ) begin//db
    case(pcsource)
        2'b00:npc <= pc4;
        2'b01:npc <= bpc;
        2'b10:npc <= dpc;
        2'b11:npc <= jpc;
        default:npc <= 32'h0000_0004;
    endcase
end

always @ ( selpc or npc or epc ) begin
    case(selpc)
        2'b00:next_pc <= npc;
        2'b01:next_pc <= epc;
        2'b10:next_pc <= 32'H1000;
        default:next_pc <= 32'h0000_0004;
    endcase
end

inst_rom instmem(
           .a(tpc),
           .spo(ins)
       );

endmodule
