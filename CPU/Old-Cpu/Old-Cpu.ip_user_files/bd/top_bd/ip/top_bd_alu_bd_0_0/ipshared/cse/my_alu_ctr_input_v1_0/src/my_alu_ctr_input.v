`timescale 1ns / 1ps
/*
 *=============================================================================
 *    Filename:my_alu_ctr_input.v
 *
 *     Version: 1.0
 *  Created on: July 15, 2016
 *    
 *      Author: corvo
 *=============================================================================
 */
 
module my_alu_ctr_input(
    SUBctr,         // 加减
    OVctr,          // 溢出使能
    SIGctr,         // 标志位
    OPctr,          // 通路选择
    SLctr,          // 左移(shift left)
    ALGctr,         // 算术移位
    ALUctr
    );

    output[2:0] OPctr;
    output SUBctr, OVctr, SIGctr, SLctr, ALGctr;
    

    reg[2:0] OPctr;
    reg SUBctr, OVctr, SIGctr, SLctr, ALGctr;

    input[3:0] ALUctr;
    wire[3:0] ALUctr;
    
    always @* begin
        case(ALUctr)
            4'b0000: begin      // add
                SUBctr<=0; OVctr<=0; OPctr<=3'b000;
            end
            4'b0001: begin      // addu
                SUBctr<=0; OVctr<=1; OPctr<=3'b000;
            end
            4'b0010: begin      // and
                SUBctr<=0; OVctr<=0; OPctr<=3'b010;
            end
            4'b0011: begin      // or
                SUBctr<=0; OVctr<=0; OPctr<=3'b011;
            end
            4'b0101: begin      // nor
                SUBctr<=0; OVctr<=0; OPctr<=3'b101;
            end
            4'b0110: begin      
                SUBctr<=0; OVctr<=0; OPctr<=3'b011;
            end
            4'b0111: begin      // or
                SUBctr<=0; OVctr<=0; OPctr<=3'b011;
            end
            4'b1000: begin      // subu
                SUBctr<=1; OVctr<=0; OPctr<=3'b000;
            end
            4'b1001: begin      // sub
                SUBctr<=1; OVctr<=1; OPctr<=3'b000;
            end
            4'b1010: begin      // sltu
                SUBctr<=1; OVctr<=0; SIGctr<=0; OPctr<=3'b001;
            end
            4'b1011: begin      // slt
                SUBctr<=1; OVctr<=0; SIGctr<=1; OPctr<=3'b001;
            end
            4'b1100: begin      // sll
                SLctr<=1; ALGctr<=0; OPctr<=3'b111;
            end
            4'b1101: begin      // srl
                SLctr<=0; ALGctr<=0; OPctr<=3'b111;
            end
            4'b1110: begin      // sra
                SLctr<=0; ALGctr<=1; OPctr<=3'b111;
            end
        endcase
    end

endmodule
