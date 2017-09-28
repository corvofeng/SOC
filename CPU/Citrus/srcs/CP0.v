`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer: IceTesla
//
// Create Date: 2017/09/25 20:36:24
// Design Name:
// Module Name: CP0
// Project Name:
// Target Devices:
// Tool Versions:
// Description:
//
// Dependencies:
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////

module CP0(
        i_clk,
        i_reset,

        i_exc,
        i_cause,
        i_selpc_epc,
        i_pc,
        i_pcd,
        i_pce,
        i_pcm,

        i_wsta,
        i_wcau,
        i_wepc,

        i_mtc0,
        i_data,

        o_status_data,
        o_epc_data,
        o_cause_data
       );
input wire i_clk;
input wire i_reset;

input wire i_exc;
input wire [31:0] i_cause;
input wire [1:0] i_selpc_epc;
input wire [31:0] i_pc;
input wire [31:0] i_pcd;
input wire [31:0] i_pce;
input wire [31:0] i_pcm;

input wire i_wsta;
input wire i_wcau;
input wire i_wepc;

input wire [5:0] i_mtc0;
input wire [31:0] i_data;

output wire [31:0] o_status_data;
output wire [31:0] o_cause_data;
output wire [31:0] o_epc_data;

reg[31:0] status_reg;
reg[31:0] cause_reg;
reg[31:0] epc_reg;

assign o_status_data = status_reg;
assign o_cause_data = cause_reg;
assign o_epc_data = epc_reg;

reg[31:0] sta_reg_in;
reg[31:0] cau_reg_in;
reg[31:0] epc_reg_in;

reg[31:0] sta_sel_data;
reg[31:0] epc_sel_data;


always @(posedge i_clk) begin
    if(i_reset==1) begin
        status_reg = 8'b00000000;
        cause_reg = 8'b00000000;
        epc_reg = 8'b00000000;
    end else begin
        case({i_wsta,i_wcau,i_wepc})
            3'b100:status_reg <= sta_reg_in;
            3'b010:cause_reg <= cau_reg_in;
            3'b001:epc_reg <= epc_reg_in;
            default;
        endcase
    end
end

always @ ( i_mtc0 or i_data or sta_sel_data or i_cause or epc_sel_data ) begin
    if( i_mtc0 == 1) begin
        sta_reg_in = i_data;
        cau_reg_in = i_data;
        epc_reg_in = i_data;
    end else begin
        sta_reg_in = sta_sel_data;
        cau_reg_in = i_cause;
        epc_reg_in = epc_sel_data;
    end
end

always @ ( i_selpc_epc or i_pc or i_pcd or i_pce or i_pcm ) begin
    case(i_selpc_epc)
        2'b00:epc_sel_data = i_pc;
        2'b01:epc_sel_data = i_pcd;
        2'b10:epc_sel_data = i_pce;
        2'b11:epc_sel_data = i_pcm;
        default;
    endcase
end

always @ ( i_exc or o_status_data ) begin
    case(i_exc)
        0:sta_sel_data = {4'h0,o_status_data[31:4]};
        1:sta_sel_data = {o_status_data[27:0],4'h0};
    endcase
end

endmodule
