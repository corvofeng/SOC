`timescale 1ns / 1ps



module my_xor(
    out,
a,
b
);
output[31:0]out;
input [31:0]a;
input [31:0]b;
assign out = a ^ b;
endmodule
