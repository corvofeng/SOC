`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2017/09/19 19:14:38
// Design Name:
// Module Name: divider
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


module divider(a,b,start,clock,resetn,q,r,busy
              );

integer i=0;
input [31:0] a;
input [31:0] b;
input start;
input clock,resetn;
output [31:0] q;
output [31:0] r;
output busy;
reg [31:0] reg_q;
reg [31:0] reg_r;
reg [31:0] reg_b;
reg busy, busy2;
always @ (posedge clock or negedge resetn) begin
    if (resetn == 0) begin
        busy <= 0;
        busy2 <= 0;
    end else begin
        busy2 <= busy;
        if(start) begin
            reg_r <= 16'h0;
            reg_q <= a;
            reg_b <= b;
            busy <= 1'b1;
        end else if (busy) begin
            reg_r <= mux_out;
            reg_q <= {reg_q[30:0],~sub_out[32]};
            i = i+1;
            if (i == 32)
                busy <= 0;
        end
    end
end
wire [32:00] sub_out = {r,q[31]} - {1'b0,reg_b};
wire [31:00] mux_out = sub_out[32]?
     {r[30:0],q[31]} : sub_out[31:0];
assign q = reg_q;
assign r = reg_r;

endmodule
