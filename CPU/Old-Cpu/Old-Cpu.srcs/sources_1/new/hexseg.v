`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/07/04 13:46:10
// Design Name: 
// Module Name: hexseg
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
//   数码管设置
//////////////////////////////////////////////////////////////////////////////////


module hexseg(segs, pos_out, hex, pos_in);
    output [6:0] segs;
    output [7:0] pos_out;
    input [3:0] hex;
    input [7:0] pos_in;
    reg [6:0] segs;
    reg [7:0] pos_out;
    
    always @(hex) begin 
        pos_out = pos_in;
        case (hex)
            4'h0: segs = 7'b0000_001;
            4'h1: segs = 7'b1001_111;
            4'h2: segs = 7'b0010_010;
            4'h3: segs = 7'b0000_110;
            4'h4: segs = 7'b1001_100;
            4'h5: segs = 7'b0100_100;
            4'h6: segs = 7'b0100_000;
            4'h7: segs = 7'b0001_111;
            4'h8: segs = 7'b0000_000;
            4'h9: segs = 7'b0000_100;
            4'ha: segs = 7'b0001_000;
            4'hb: segs = 7'b1100_000;
            4'hc: segs = 7'b0110_001;
            4'hd: segs = 7'b1000_010;
            4'he: segs = 7'b0110_000;
            4'hf: segs = 7'b0111_000;
            default: segs = 7'bx;
        endcase
    end
    
endmodule
