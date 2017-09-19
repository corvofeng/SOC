`timescale 1ns / 1ps
/*
 *=============================================================================
 *    Filename:my_control.v
 *
 *     Version: 1.0
 *  Created on: July 09, 2016
 *    
 *      Author: corvo
 *=============================================================================
 */
 
module my_control(
    RegDst,
    MemRead,
    MemToReg,
    MemWrite,
    ALUsrc,
    RegWrite,
    ALUctr,
    jmp,
    jrn,
    nBranch,
    Branch,
    Extop,
    jal,
    ShiftShamt,
    lui,
    op,
    func
    );
    
    output RegDst;
    output MemRead;
    output MemToReg;
    output MemWrite;
    output ALUsrc;
    output RegWrite;
    output[3:0] ALUctr;
    output jmp; 
    output jrn;
    output nBranch;
    output Branch;
    output Extop;
    output jal;
    output ShiftShamt;
    output lui;
    input[5:0] op;
    input[5:0] func;
    
    reg RegDst, MemRead, MemToReg, MemWrite, ALUsrc, RegWrite, jmp, jrn, nBranch, Branch, Extop, jal, ShiftShamt, lui;
    reg[3:0] ALUctr;
    wire[5:0] op;
    wire[5:0] func;

    always @* begin
        ShiftShamt = 0;
        lui = 0;
        
        case(op[5:0])
            //R type
            6'b000000: begin                            
                RegWrite<=1; RegDst<=1; MemToReg<=0; ALUsrc=0;
                MemToReg<=0; MemWrite<=0; Branch<=0; nBranch<=0;
                jmp <= 0;

                case(func[5:0])
                    6'b100000: begin ALUctr[3:0] <= 4'b0001; jmp <= 0; end  // add 
                    6'b100001: begin ALUctr[3:0] <= 4'b0000; jmp <= 0; end  // addu
                    6'b100010: begin ALUctr[3:0] <= 4'b1001; jmp <= 0; end // sub
                    6'b100011: begin ALUctr[3:0] <= 4'b1000; jmp <= 0; end // subu
                    6'b100100: begin ALUctr[3:0] <= 4'b0010;  end// and
                    6'b100101: begin ALUctr[3:0] <= 4'b0011;  end// or
                    6'b100110: begin ALUctr[3:0] <= 4'b0110;  end// xor
                    6'b100111: begin ALUctr[3:0] <= 4'b0101;  end// nor
                    6'b101010: begin ALUctr[3:0] <= 4'b1011;  end// slt
                    6'b101011: begin ALUctr[3:0] <= 4'b1010;  end// sltu
                    6'b001000: begin                    // jr
                        RegWrite <= 0; MemWrite <=0; jmp <= 0;
                        jrn <= 1; jal <=0;
                    end
                    6'b000000: begin                    // sll
                        ALUctr[3:0] <= 4'b1100; 
                        ShiftShamt <= 1;
                    end

                    6'b000010: begin                    // srl
                        ShiftShamt <= 1;
                        ALUctr[3:0] <= 4'b1101;
                    end

                    6'b000011: begin                    // sra
                        ShiftShamt <= 1;
                        ALUctr[3:0] <= 4'b1110;
                    end

                    6'b000100: ALUctr[3:0] <= 4'b1100;  // sslv 
                    6'b000100: ALUctr[3:0] <= 4'b1101;  // srlv
                    6'b000110: ALUctr[3:0] <= 4'b1110;  // srav

                endcase
            end

            // I type
            6'b001000: begin            // addi
                RegWrite<=1; RegDst<=0; ALUsrc=1; Extop=1;
                MemToReg<=0; MemWrite<=0; Branch<=0; nBranch<=0; jal<=0; jmp<=0; jrn<=0;
                ALUctr[3:0] <= 4'b0001;  
            end

            6'b001001: begin            // addiu
                RegWrite<=1; RegDst<=0; ALUsrc=1; Extop=1;
                MemToReg<=0; MemWrite<=0; Branch<=0; nBranch<=0; jal<=0; jmp<=0; jrn<=0;
                ALUctr[3:0] <= 4'b0000;  
            end

            6'b001100: begin             // andi
                RegWrite<=1; RegDst<=0; ALUsrc=1; Extop=0;
                MemToReg<=0; MemWrite<=0; Branch<=0; nBranch<=0; jal<=0; jmp<=0; jrn<=0;
                ALUctr[3:0] <= 4'b0010;  
            end

            6'b001101: begin             // ori
                RegWrite<=1; RegDst<=0; ALUsrc<=1; Extop<=0;
                MemToReg<=0; MemWrite<=0; Branch<=0; nBranch<=0; jal<=0; jmp<=0; jrn<=0;
                ALUctr[3:0] <= 4'b0110;  
            end

            6'b001111: begin             // lui
                ALUctr[3:0] <= 4'b1100;
                RegWrite<=1; RegDst<=0; jal<=0; Extop<=0; ALUsrc<=1; 
                MemRead<=0; MemWrite<=0; Branch<=0; nBranch<=0; jmp<=0; jrn<=0;
                MemToReg<=0;
                lui<=1;
            end

            6'b001101: begin             // xori
                RegWrite<=1; RegDst<=0; ALUsrc<=1; Extop<=0;
                MemToReg<=0; MemWrite<=0; Branch<=0; nBranch<=0; jal<=0; jmp<=0; jrn<=0;
                ALUctr[3:0] <= 4'b0011;  
            end

            6'b100011: begin             // lw
                RegWrite<=1; RegDst<=0; ALUsrc<=1; Extop<=1;
                Branch<=0; nBranch<=0; jmp<=0; jrn<=0; jal<=0;
                MemToReg<=1;
                ALUctr[3:0] <= 4'b0001;  
            end

            6'b101011: begin             // sw
                RegWrite<=0; ALUsrc<=1; Extop<=1; MemWrite<=1; 
                Branch<=0; nBranch<=0; jmp<=0; jrn<=0; jal<=0;
                ALUctr[3:0] <= 4'b0000;  
            end

            6'b000100: begin             // beq
                RegWrite<=0; ALUsrc<=0; MemWrite<=0; Extop<=1;
                Branch<=1; nBranch<=0; jmp<=0; jrn<=0; jal<=0;
                ALUctr[3:0] <= 4'b1000;  
            end

            6'b000101: begin             // bne
                RegWrite<=0; ALUsrc<=0; MemWrite<=0; 
                Branch<=0; nBranch<=1; jmp<=0; jrn<=0; jal<=0;
                ALUctr[3:0] <= 4'b1000;  
            end

            6'b001010: begin             // slti
                ALUctr[3:0] <= 4'b1011;  // slt
                RegWrite<=1; RegDst<=0; ALUsrc<=1; Extop<=1; MemToReg<=0;
                Branch<=0; nBranch<=0; jmp<=0; jrn<=0; jal<=0;
            end

            6'b001011: begin             // sltiu
                RegWrite<=1; RegDst<=0; ALUsrc<=1; Extop<=0; MemToReg<=0;
                Branch<=0; nBranch<=0; jmp<=0; jrn<=0; jal<=0;
                ALUctr[3:0] <= 4'b1010;  // sltu
            end


            // I型指令
            6'b000010: begin            // j
                RegWrite<=0; MemWrite<=0; jmp<=1; jrn<=0; jal<=0;
            end

            6'b000011: begin            // jal
                RegWrite<=1; jmp<=1; jal<=1; 
            end

            default: begin
                jmp <= 0; jrn<=0; nBranch<=0; Branch<=0;
            end

        endcase

    end

endmodule
