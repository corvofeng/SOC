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
    input start,
    input clk,
    input reset,
    output[63:0] o

    );

    reg [31:0] a_latch;
    reg [31:0] b_latch;

    always @(posedge clk) begin
        if(reset==1) begin
            a_latch = 32'h00000000;
            b_latch = 32'h00000000;
        end else begin
            if(start==1) begin
                a_latch <= a;
                b_latch <= b;
            end
        end
    end

    reg [31:0] unsigned_a;
    reg [31:0] unsigned_b;
    wire ab_symbol;

    wire [63:0] out;

    xor(ab_symbol,a[31],b[31]);

    always @ ( * ) begin
        if(symbol == 0) begin
            unsigned_a <= a_latch;
            unsigned_b <= b_latch;
        end else begin
            unsigned_a <= a_latch[31]?(~a_latch+1):a_latch;
            unsigned_b <= b_latch[31]?(~b_latch+1):b_latch;
        end
    end

    wallace_tree32_unsigned mul(
        .a(unsigned_a),
        .b(unsigned_b),
        .s(out)
        );

    assign o = (symbol == 0 || symbol&&~ab_symbol)?out:(~out + 1);
endmodule
