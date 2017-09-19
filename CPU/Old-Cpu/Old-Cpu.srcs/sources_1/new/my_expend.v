`timescale 1ns / 1ps
/*
 *=============================================================================
 *    Filename:my_expend.v
 *
 *     Version: 1.0
 *  Created on: July 10, 2016
 *    
 *      Author: corvo
 *=============================================================================
 */
 
// Extop = 1: 符号扩展
// Extop = 0: 0扩展
module my_expend(
    im_31_0,
    im_15_0,
    Extop
    );
    output[31:0] im_31_0;
    input[15:0] im_15_0;
    input Extop;

    assign im_31_0 = (Extop & im_15_0[15])? {16'hffff, im_15_0}: {16'h0000, im_15_0};

endmodule
