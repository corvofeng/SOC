`timescale 1ns / 1ps
/*
 *=============================================================================
 *    Filename:input16.v
 *
 *     Version: 1.0
 *  Created on: July 17, 2016
 *    
 *      Author: corvo
 *=============================================================================
 */
 
module input16(
        out
    );
    output[31:0] out;
    assign out = 32'd16;
endmodule
