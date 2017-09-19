`timescale 1ns / 1ps
/*
 *=============================================================================
 *    Filename:my_mem_sim.v
 *
 *     Version: 1.0
 *  Created on: July 07, 2016
 *    
 *      Author: corvo
 *=============================================================================
 */
 
module my_mem_sim(

    );

    // input
    reg[4:0] Ra = 5'h11;
    reg[4:0] Rb = 5'h12;
    reg[4:0] Rw = 5'h11;

    reg clk;
    reg WriteEnable = 0;
    reg[31:0] busW;
    
     
    //output
    wire [31:0] Qa;
    wire [31:0] Qb;
        
       
    // initial
    my_mem U (
        .Qa(Qa), .Qb(Qb),
        .Rw(Rw), .Ra(Ra), .Rb(Rb),
        .WriteEnable(WriteEnable),
        .busW(busW),
        .clk(clk)
        );
    initial begin
        begin clk = 0; end     
        #49 begin WriteEnable=1; busW=32'h72; Rw = 5'h11; #1 clk=1; end     
        #49 begin WriteEnable=1; busW=32'h72; Rw = 5'h12; #1 clk=0; end      
        #49 begin WriteEnable=1; busW=32'h72; Rw = 5'h12; #1 clk=1; end      
        #49 begin Ra=5'h11; Rb=5'h12; clk=0; end 
    end

endmodule
