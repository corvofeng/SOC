`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/12/13 19:35:20
// Design Name: 
// Module Name: test_sim
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


odule test_sim(

    );
    reg[31:0] a = 32;
        reg[31:0] b = 44;
        reg[3:0] ctr = 4;
        //top_bd u(clk, pc_reset, reg_reset);
        test_db u(a, b, ctr);
endmodule
