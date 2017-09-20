`timescale 1ns / 1ps
/*
 *=============================================================================
 *    Filename:my_mem.v
 *
 *     Version: 1.0
 *  Created on: July 07, 2016
 *    
 *      Author: corvo
 *=============================================================================
 */
 
// i_data0, i_data1 for register output
// i_addr_0, i_addr_1 for input the addrress i_data0, i_data1
//
// 同步置数

module my_reg(
    i_data0,
	i_data1,
    i_addr_w, 
	i_addr_0, 
	i_addr_1,
    i_wr,
    i_data,
    i_clk,
    i_reset
    );
    
    output[31:0] i_data0;
    output[31:0] i_data1;
    input [4:0] i_addr_0, i_addr_1, i_addr_w;
    input i_reset;
    input i_wr;
    input i_clk;
    input[31:0] i_data;
    
    wire[31:0] i_data0;
    wire[31:0] i_data1;
    wire i_reset;
    wire i_clk;

    reg[31:0] register[0:31];               //寄存器组共32个32位寄存器
    wire[31:0] i_data;

    wire[4:0] i_addr_0; 
    wire[4:0] i_addr_1;
    wire[4:0] i_addr_w;

    assign i_data0 = register[i_addr_0];
    assign i_data1 = register[i_addr_1];

    integer i;
    always @(posedge i_clk) begin
        if(i_reset==1) begin              // 每个寄存器初始值为寄存器号
            for(i=0;i<32;i=i+1) register[i] = i;
        end 
    end

    always @(negedge i_clk) begin         // 本进程写目标寄存器
        if(i_wr==1) begin  // 注意寄存器0恒等于0
            case(i_addr_w[4:0])
                5'd0:register[0] <= 32'd0;
                5'd1:register[1] <= i_data;
                5'd2:register[2] <= i_data;
                5'd3:register[3] <= i_data;
                5'd4:register[4] <= i_data;
                5'd5:register[5] <= i_data;
                5'd6:register[6] <= i_data;
                5'd7:register[7] <= i_data;
                5'd8:register[8] <= i_data;
                5'd9:register[9] <= i_data;
                5'd10:register[10] <= i_data;
                5'd11:register[11] <= i_data;
                5'd12:register[12] <= i_data;
                5'd13:register[13] <= i_data;
                5'd14:register[14] <= i_data;
                5'd15:register[15] <= i_data;
                5'd16:register[16] <= i_data;
                5'd17:register[17] <= i_data;
                5'd18:register[18] <= i_data;
                5'd19:register[19] <= i_data;
                5'd20:register[20] <= i_data;
                5'd21:register[21] <= i_data;
                5'd22:register[22] <= i_data;
                5'd23:register[23] <= i_data;
                5'd24:register[24] <= i_data;
                5'd25:register[25] <= i_data;
                5'd26:register[26] <= i_data;
                5'd27:register[27] <= i_data;
                5'd28:register[28] <= i_data;
                5'd29:register[29] <= i_data;
                5'd30:register[30] <= i_data;
                5'd31:register[31] <= i_data;
                default:register[0] <= 32'd0;
            endcase
        end else 
            register[0] <= 32'd0;
    end
endmodule
