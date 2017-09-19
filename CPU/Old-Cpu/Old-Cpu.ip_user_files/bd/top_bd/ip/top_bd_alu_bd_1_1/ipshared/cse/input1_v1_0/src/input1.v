`timescale 1ns / 1ps
/*
 *=============================================================================
 *    Filename:input1.v
 *
 *     Version: 1.0
 *  Created on: July 11, 2016
 *    
 *      Author: corvo
 *=============================================================================
 */
 
module input1(
    one
    );
    output[31:0] one;
    assign one = 32'h1;
endmodule
