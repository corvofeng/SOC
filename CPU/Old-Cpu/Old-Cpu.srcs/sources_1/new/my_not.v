`timescale 1ns / 1ps
/*
 *=============================================================================
 *    Filename:my_not.v
 *
 *     Version: 1.0
 *  Created on: July 28, 2016
 *    
 *      Author: corvo
 *=============================================================================
 */
 
module my_not(
    out,
    in
    );
    output out;
    input in;
    assign out = ~ in;
endmodule
