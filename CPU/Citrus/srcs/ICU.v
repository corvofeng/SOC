`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer: IceTesla
//
// Create Date: 2017/09/20 19:30:06
// Design Name:
// Module Name: ICU
// Project Name:
// Target Devices:
// Tool Versions:
// Description:
//
// Dependencies:
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments: 目前没有实现PR的两种工作模式：优先级模式和平等模式
//
//////////////////////////////////////////////////////////////////////////////////


module ICU(
           i_interrupt,
           i_addr,
           i_we,
           i_cs,
           i_data,
           i_inta,
           i_clk,
           o_intr,
           o_vector
       );
input[7:0] i_interrupt;
input[1:0] i_addr;
input i_we;
input i_cs;
input[7:0] i_data;
input i_inta;
input i_clk;
output o_intr;
output[7:0] o_vector;

function[7:0] getVector;
    input [7:0] in;
    input [7:0] vector;
    case(in)
        8'b00000001:getVector = vector;
        8'b00000010:getVector = vector + 1;
        8'b00000100:getVector = vector + 2;
        8'b00001000:getVector = vector + 3;
        8'b00010000:getVector = vector + 4;
        8'b00100000:getVector = vector + 5;
        8'b01000000:getVector = vector + 6;
        8'b10000000:getVector = vector + 7;
        default:getVector = vector;
    endcase
endfunction

//各寄存器输入输出
wire[7:0] ISR_data_in,ISR_data_out;
wire[7:0] IRR_data_in,IRR_data_out;
wire[7:0] IMR_data_in,IMR_data_out;
wire[7:0] status_data_in,status_data_out;
wire[7:0] PR_data_in,PR_data_out;

assign IRR_data_in = i_interrupt,
       PR_data_in = IMR_data_out | ~IRR_data_out,
       ISR_data_in = PR_data_out,
       IMR_data_in = i_data,
       status_data_in = i_data;

//ICU_ctrl控制逻辑
wire status_we;
wire status_reset;
wire IMR_we;
wire IMR_reset;
wire ISR_we;
wire ISR_reset;
wire IRR_we;
wire IRR_reset;

assign status_we = i_we && i_addr[1] && ~i_addr[0] && i_cs,
       status_reset = ~i_addr[1] && ~i_addr[0] && i_cs,
       IMR_we = i_we && i_addr[1] && i_addr[0] && i_cs,
       IMR_reset = ~i_addr[1] && ~i_addr[0] && i_cs,
       ISR_we = ~i_cs && ~ISR_data_out[7]&&~ISR_data_out[6]&&~ISR_data_out[5]&&~ISR_data_out[4]&&~ISR_data_out[3]&&~ISR_data_out[2]&&~ISR_data_out[1]&&~ISR_data_out[0],
       ISR_reset = ~i_addr[1] && ~i_addr[0] && i_cs || ~i_addr[1] && i_addr[0] && i_inta && i_cs,
       IRR_we = ~i_cs && ~ISR_data_out[7]&&~ISR_data_out[6]&&~ISR_data_out[5]&&~ISR_data_out[4]&&~ISR_data_out[3]&&~ISR_data_out[2]&&~ISR_data_out[1]&&~ISR_data_out[0],
       IRR_reset = ~i_addr[1] && ~i_addr[0] && i_cs || ~i_addr[1] && i_addr[0] && i_inta && i_cs,
       o_intr = ~i_addr[1] && i_addr[0] && (ISR_data_out[7]||ISR_data_out[6]||ISR_data_out[5]||ISR_data_out[4]||ISR_data_out[3]||ISR_data_out[2]||ISR_data_out[1]||ISR_data_out[0]),
       o_vector = getVector(ISR_data_out,status_data_out);

function[7:0] getPR_out;
    input gs;
    input eo;
    input[2:0] in;
    case({gs,eo,in})
        5'b01111:getPR_out = 8'b00000001;
        5'b01110:getPR_out = 8'b00000010;
        5'b01101:getPR_out = 8'b00000100;
        5'b01100:getPR_out = 8'b00001000;
        5'b01011:getPR_out = 8'b00010000;
        5'b01010:getPR_out = 8'b00100000;
        5'b01001:getPR_out = 8'b01000000;
        5'b01000:getPR_out = 8'b10000000;
        default:getPR_out = 8'b00000000;
    endcase
endfunction

wire PR_enable_o;
wire PR_gs;
wire PR_enable_i;
wire[2:0]PR_temp;

assign PR_enable_i = i_cs || ISR_data_out[7] || ISR_data_out[6] || ISR_data_out[5] || ISR_data_out[4] || ISR_data_out[3] || ISR_data_out[2] || ISR_data_out[1] || ISR_data_out[0],
       PR_data_out = getPR_out(PR_gs,PR_enable_o,PR_temp);

PriorityEncoder8_3 PR(
                       .i_data_n(PR_data_in),
                       .i_enable_n(PR_enable_i),
                       .o_data_n(PR_temp),
                       .o_gs_n(PR_gs),
                       .o_enable_n(PR_enable_o)
                   );

reg_8bit IRR(
             .i_data(IRR_data_in),
             .i_clk(i_clk),
             .i_reset(IRR_reset),
             .i_we(IRR_we),
             .o_data(IRR_data_out)
         );

reg_8bit IMR(
             .i_data(IMR_data_in),
             .i_clk(i_clk),
             .i_reset(IMR_reset),
             .i_we(IMR_we),
             .o_data(IMR_data_out)
         );

reg_8bit ISR(
             .i_data(ISR_data_in),
             .i_clk(i_clk),
             .i_reset(ISR_reset),
             .i_we(ISR_we),
             .o_data(ISR_data_out)
         );

reg_8bit Status(
             .i_data(status_data_in),
             .i_clk(i_clk),
             .i_reset(status_reset),
             .i_we(status_we),
             .o_data(status_data_out)
         );


endmodule
