`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/21/2017 10:27:55 AM
// Design Name: 
// Module Name: div_mlt_sim
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


module div_mlt_sim();

    reg[31:0] A = 32'h6fff7660;
    reg[31:0] B = 32'h0000;

    wire[31:0] hi;
    wire[31:0] lo;
    wire zero;
    reg clk;
    reg en;
    reg sign = 1;
    reg mul = 0;

    div_mlt d_m (
        .i_clk(clk),
        .i_mul(mul),
        .i_sign(1),
        .i_en(en),
        .i_A(A),
        .i_B(B),
        .o_hi(hi),
        .o_lo(lo),
        .o_zero(zero)
    );

    initial begin
        clk = 0;
        en = 0;
        #20 en = 1;

        #10 en = 0;
        #80 begin
            en = 1;
            B = 32'hccdd; 
            mul = 1;
        end
    end

    reg[1:0] cnt = 2'b00;
   
    always begin
        #10 clk = ~clk;
    /*
        if (cnt == 1) begin
            #10 cnt = 0;
            clk = ~clk;
        end else
            #10 cnt = cnt + 1;
    */
    end


endmodule
