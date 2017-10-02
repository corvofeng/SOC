`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2016/07/06 16:08:58
// Design Name:
// Module Name: socexe  exeģ��
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
           input [31:0] epc4,
           input [31:0] ea,
           input [31:0] eb,
           input [31:0] eimm,
           input [4:0] ern0,
           input ealuimm,
           input eshift,
           input ejal,
           input [3:0] ealuc,
           output reg [31:0] ealu,
           output reg [4:0] ern,
           output ov,

           input[31:0] esta,
           input[31:0] ecau,
           input[31:0] eepc,
           input [1:0] emfc0,

           input[1:0] emfhilo,
           input[31:0] HI_data,
           input [31:0] LO_data
       );
wire epc8 = epc4 + 3'b100;//pc+4
reg [31:0] ia,ib;
wire [31:0]out;
wire ov,zero;

reg[31:0] mfc0_out;
reg[31:0] mfhilo_out;

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

always @ ( emfc0 or epc8 or esta or ecau or eepc ) begin
    case(emfc0)
        2'b00:mfc0_out <= epc8;
        2'b01:mfc0_out <= esta;
        2'b10:mfc0_out <= ecau;
        2'b11:mfc0_out <= eepc;
        default:mfc0_out <=32'h0000_0000;
    endcase
end

always @ ( emfhilo or LO_data or HI_data) begin
    case(emfhilo)
        2'b00:mfhilo_out <= mfc0_out;
        2'b10:mfhilo_out <= LO_data;
        2'b11:mfhilo_out <= HI_data;
        default:mfhilo_out <= mfc0_out;
    endcase
end

always @ (mfc0_out or out or ejal) begin //jal
    if(ejal|emfc0[1]|emfc0[0]|emfhilo[1])begin
        ealu <= mfhilo_out;
    end else begin
        ealu <= out;
    end
end

always @ (ern0 or ejal) begin//f
    case(ejal)
        0:ern <= ern0;
        1:ern <= 5'b11111;
        default:ern <= 32'h0000_0000;
    endcase
end
alu_impl alu(
             .A(ia),
             .ALUctr(ealuc),
             .B(ib),
             .Overflow(ov),
             .Result(out),
             .Zero(zero)
         );
endmodule
