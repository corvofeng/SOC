`timescale 1ns / 1ps
/*
 *=============================================================================
 *    Filename:my_pc.v
 *
 *     Version: 1.0
 *  Created on: July 10, 2016
 *    
 *      Author: corvo
 *=============================================================================
 */
 
module my_pc(
    pc_out,
    pc_add4,
    pc_in,
    clk,
    reset
    );
    
    output[31:0] pc_out, pc_add4;
    input[31:0] pc_in;
    input clk,reset;
    
    reg[31:0] pc_out, pc_add4;

    always @(posedge clk) begin

        if(reset == 1) begin      // 同步置数
            pc_out = 32'h0000;
            pc_add4[31:0] = 32'h0004;
        end else 
            pc_out = pc_in;

        //if (reset == 0) begin
        //    pc_out <= 32'b0;
        //end else begin
        //end

        pc_add4[1:0] = 2'b00;
        pc_add4[31:2] = pc_out[31:2] + 1;

       // pc_add4[1:0] = 2'b00;
       // pc_add4[31:2] = pc_out[31:2] + 1;
    end

endmodule
