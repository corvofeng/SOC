`timescale 1ns / 1ps
/*
 *=============================================================================
 *    Filename:my_6split1.v
 *
 *     Version: 1.0
 *  Created on: July 28, 2016
 *    
 *      Author: corvo
 *=============================================================================
 */
 
module my_6split1(
    out0,
    out1,
    out2,
    out3,
    out4,
    out5,
    in5_0
    );
    output out0, out1, out2, out3, out4, out5;
    input[5:0] in5_0;

    assign out0 = in5_0[0];   
    assign out1 = in5_0[1];   
    assign out2 = in5_0[2];   
    assign out3 = in5_0[3];   
    assign out4 = in5_0[4];   
    assign out5 = in5_0[5];   
   

endmodule
