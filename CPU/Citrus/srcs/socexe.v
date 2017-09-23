`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2016/07/06 16:08:58
// Design Name:
// Module Name: socexe  exeÄ£¿é
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


module socexe (
           input reg [31:0] epc4,
           input reg [31:0] ea,
           input reg [31:0] eb,
           input reg [31:0] eimm,
           input reg [4:0] ern0,
           input reg ealuimm,
           input reg eshift,
           input reg [3:0] ealuc,
           output reg [31:0] ealu,
           output reg [4:0] ern
       );
reg epc8 = epc4 + 3'b100;//pc+4
reg [31:0] ia,ib,out;

always @ (ea or eimm or eshift) begin//shift
    case(eshift)
        0:ia <= ea;
        1:ia <= eimm;
        default:ia <= 32'h0000_0000;
    endcase
end

always @ (eb or eimm or ealuimm) begin//imme
    case(ealuimm)
        0:ib <= eb;
        1:ib <= eimm;
        default:ib <= 32'h0000_0000;
    endcase
end

always @ (epc8 or out or ejal) begin //jal
    case(ejal)
        0:ealu <= out;
        1:ealu <= epc8;
        default:ealu <= 32'h0000_0000;
    endcase
end

always @ (ern0 or ejal) begin//f
    case(ejal)
        0:ern <= ern0;
        1:ern <= 5'b11111;
        default:ern <= 32'h0000_0000;
    endcase
end


endmodule
