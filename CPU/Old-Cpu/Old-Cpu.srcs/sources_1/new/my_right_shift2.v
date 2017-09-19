`timescale 1ns / 1ps
/*
 *=============================================================================
 *    Filename:my_right_shift2.v
 *
 *     Version: 1.0
 *  Created on: July 27, 2016
 *    
 *      Author: corvo
 *=============================================================================
 */
 
  

// i >> 2
module my_right_shift2(
    Result,
    i
    );

    output[15:0] Result;
    input[31:0] i;

    assign Result[15:0] = i >>  2;

endmodule
