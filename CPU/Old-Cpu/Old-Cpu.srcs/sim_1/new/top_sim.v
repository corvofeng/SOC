`timescale 1ns / 1ps
/*
 *=============================================================================
 *    Filename:top_sim.v
 *
 *     Version: 1.0
 *  Created on: July 12, 2016
 *    
 *      Author: corvo
 *=============================================================================
 */
 
  
module top_sim();

    reg clk = 0;
    reg pc_reset = 0;
    reg reg_reset = 0;

    initial begin

        #10 pc_reset = 0;
        #60 pc_reset = 1;
        #40 reg_reset = 0;
        #20 begin pc_reset = 0;end
      //  #50 begin pc_reset = 1;reg_reset = 0; end
        //#990 pc_reset = 1;
       // #1120 pc_reset = 0;

    end
    reg[31:0] a = 32;
    reg[31:0] b = 44;
    reg[3:0] ctr = 4;
    cpu_single u(clk, pc_reset, reg_reset);
    reg[1:0] cnt = 2'b00;
   
    always begin
        if (cnt == 2) begin
            #30 cnt = 0;
            clk = ~clk;
        end else
            #30 cnt = cnt + 1;
        end
    

endmodule
