`timescale 1ns / 1ps
/*
 *=============================================================================
 *    Filename:my_shift2.v
 *
 *     Version: 1.0
 *  Created on: July 11, 2016
 *    
 *      Author: corvo
 *=============================================================================
 */
 
module my_shift2
    #(parameter WIDTH=8)
    (
        output[(WIDTH-1):0] out,
        input[(WIDTH-1):0] in
    );

    assign out = {in[(WIDTH-3):0], 2'b00};
endmodule
