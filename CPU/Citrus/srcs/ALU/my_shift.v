`timescale 1ns / 1ps
/*
 *=============================================================================
 *    Filename:my_shift.v
 *
 *     Version: 1.0
 *  Created on: July 15, 2016
 *    
 *      Author: corvo
 *=============================================================================
 */

module my_shift(
           Result,
           Overflow,
           A,
           B,
           SLctr,
           ALGctr
       );
output[31:0] Result;
output Overflow;

reg[31:0] Result;

input[31:0] A, B;
input SLctr, ALGctr;

always @* begin
    if (!SLctr) begin
        if (ALGctr) begin
            Result <= B >>> A;
        end else
            Result <= B >> A;
    end else
        Result <= B << A;
end


endmodule
