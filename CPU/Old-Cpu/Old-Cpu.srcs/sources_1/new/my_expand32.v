`timescale 1ns / 1ps
/*
 *=============================================================================
 *    Filename:my_expand32.v
 *
 *     Version: 1.0
 *  Created on: July 12, 2016
 *    
 *      Author: corvo
 *=============================================================================
 */
 
module my_expand32
    #(parameter WIDTH=8)
    (
        out_31_0, in_WIDTH_0
    );

    output [31:0] out_31_0;
    input[(WIDTH-1):0] in_WIDTH_0;

    wire [31:0] out_31_0;
    wire [(WIDTH-1):0] in_WIDTH_0;

    assign out_31_0 = 32'b0 + in_WIDTH_0;
endmodule
