`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:IceTesla
//
// Create Date: 2017/10/01 17:16:54
// Design Name:
// Module Name: multiplier
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


module multiplier(
    input[31:0] a,
    input[31:0] b,
    input symbol,
    output[63:0] o

    );

    reg [31:0] unsigned_a;
    reg [31:0] unsigned_b;
    wire ab_symbol;

    wire [63:0] out;

    xor(ab_symbol,a[31],b[31]);

    always @ ( * ) begin
        if(symbol == 0) begin
            unsigned_a <= a;
            unsigned_b <= b;
        end else begin
            unsigned_a <= a[31]?(~a+1):a;
            unsigned_b <= b[31]?(~b+1):b;
        end
    end

    wallace_tree32_unsigned mul(
        .a(unsigned_a),
        .b(unsigned_b),
        .s(out)
        );

    assign o = (symbol == 0 || symbol&&~ab_symbol)?out:(~out + 1);
endmodule
