`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer: IceTesla
//
// Create Date: 2017/10/02 10:49:32
// Design Name:
// Module Name: HI_LO
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


module HI_LO(
    input i_clk,
    input i_reset,
    input[31:0] i_data,
    input[31:0] i_HI_data,
    input[31:0] i_LO_data,
    input i_mthi,
    input i_mtlo,
    input i_whi,
    input i_wlo,

    output[31:0] o_HI_data,
    output[31:0] o_LO_data
    );


reg[31:0] HI_reg;
reg[31:0] LO_reg;

assign o_HI_data = HI_reg;
assign o_LO_data = LO_reg;

reg[31:0] HI_reg_in;
reg[31:0] LO_reg_in;

always @ ( posedge i_clk ) begin
    if(i_reset == 1) begin
        HI_reg = 32'h0000_0000;
        LO_reg = 32'h0000_0000;
    end else begin
        if(i_whi)
            HI_reg <= HI_reg_in;
        if(i_wlo)
            LO_reg <= LO_reg_in;
    end
end

always @ ( i_mthi or i_mtlo or i_whi or i_wlo or i_data or i_HI_data or i_LO_data) begin
    if( i_mthi == 1)
        HI_reg_in = i_data;
    else
        HI_reg_in = i_HI_data;
    if( i_mtlo == 1)
        LO_reg_in = i_data;
    else
        LO_reg_in = i_LO_data;
end

endmodule
