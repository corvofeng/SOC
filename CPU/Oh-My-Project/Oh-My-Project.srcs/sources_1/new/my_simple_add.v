`timescale 1ns / 1ps
/*
 *=============================================================================
 *    Filename:my_simple_add.v
 *
 *     Version: 1.0
 *  Created on: July 12, 2016
 *    
 *      Author: corvo
 *=============================================================================
 */
 
module my_simple_add
    #(parameter WIDTH=8)
    (
        output[(WIDTH-1):0] sum,
        input[(WIDTH-1):0] a,
        input[(WIDTH-1):0] b
    );
    wire cf2;
    assign {cf2,sum} = a + b;
endmodule
