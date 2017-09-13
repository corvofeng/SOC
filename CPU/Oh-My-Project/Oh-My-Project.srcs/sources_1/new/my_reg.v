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
 
// Qa, Qb for register output
// Ra, Rb for input the addrress Qa, Qb
//
// 同步置数

module my_reg(
    Qa,Qb,
    Rw, Ra, Rb,
    WriteEnable,
    busW,
    clk,
    reset
    );
    
    output[31:0] Qa;
    output[31:0] Qb;
    input [4:0] Ra, Rb, Rw;
    input reset;
    input WriteEnable;
    input clk;
    input[31:0] busW;
    
    wire[31:0] Qa;
    wire[31:0] Qb;
    wire reset;
    //wire clk;

    reg[31:0] register[0:31];               //寄存器组共32个32位寄存器
    wire[31:0] busW;

    wire[4:0] Ra; 
    wire[4:0] Rb;
    wire[4:0] Rw;

    assign Qa = register[Ra];
    assign Qb = register[Rb];

    integer i;
    always @(posedge clk) begin
        if(reset==1) begin              // 每个寄存器初始值为寄存器号
            for(i=0;i<32;i=i+1) register[i] = i;
        end 
    end

    always @(negedge clk) begin         // 本进程写目标寄存器
        if(WriteEnable==1) begin  // 注意寄存器0恒等于0
            case(Rw[4:0])
                5'd0:register[0] <= 32'd0;
                5'd1:register[1] <= busW;
                5'd2:register[2] <= busW;
                5'd3:register[3] <= busW;
                5'd4:register[4] <= busW;
                5'd5:register[5] <= busW;
                5'd6:register[6] <= busW;
                5'd7:register[7] <= busW;
                5'd8:register[8] <= busW;
                5'd9:register[9] <= busW;
                5'd10:register[10] <= busW;
                5'd11:register[11] <= busW;
                5'd12:register[12] <= busW;
                5'd13:register[13] <= busW;
                5'd14:register[14] <= busW;
                5'd15:register[15] <= busW;
                5'd16:register[16] <= busW;
                5'd17:register[17] <= busW;
                5'd18:register[18] <= busW;
                5'd19:register[19] <= busW;
                5'd20:register[20] <= busW;
                5'd21:register[21] <= busW;
                5'd22:register[22] <= busW;
                5'd23:register[23] <= busW;
                5'd24:register[24] <= busW;
                5'd25:register[25] <= busW;
                5'd26:register[26] <= busW;
                5'd27:register[27] <= busW;
                5'd28:register[28] <= busW;
                5'd29:register[29] <= busW;
                5'd30:register[30] <= busW;
                5'd31:register[31] <= busW;
                default:register[0] <= 32'd0;
            endcase
        end else 
            register[0] <= 32'd0;
    end
endmodule
