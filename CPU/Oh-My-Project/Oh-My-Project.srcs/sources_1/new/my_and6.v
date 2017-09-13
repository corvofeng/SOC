`timescale 1ns / 1ps
/*
 *=============================================================================
 *    Filename:my_and6.v
 *
 *     Version: 1.0
 *  Created on: July 28, 2016
 *    
 *      Author: corvo
 *=============================================================================
 */
 
module my_and6(
    result,
    in0,
    in1,
    in2,
    in3,
    in4,
    in5
    );
    output result;
    input in0, in1, in2, in3, in4, in5;

    assign result = ~ in0 & ~ in1 & ~ in2 & ~ in3 & ~ in4 & ~ in5;
endmodule
