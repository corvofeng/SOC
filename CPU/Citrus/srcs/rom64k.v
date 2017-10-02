/*
 *=============================================================================
 *    Filename: rom64k.v
 *
 *     Version: 1.0
 *  Created on: September 19, 2017
 *
 *      Author: corvo
 *=============================================================================
 */
`timescale 1ns / 1ps

module rom64k(addr, data);
input [15:0] addr;
output [31:0] data;
wire [7:0] ai= addr[7:0];

inst_rom insrom(
                     .a(ai),
                     .spo(data)
                 );
endmodule
