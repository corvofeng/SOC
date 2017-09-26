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
           i_data,
           i_clk,
           i_reset,
           i_we,
           i_sel,
           o_status_data,
           o_epc_data,
           o_cause_data
       );
input wire [31:0] i_data;
input wire i_clk;
input wire i_reset;
input wire i_we;
input wire [5:0] i_sel;
output wire [31:0] o_status_data;
output wire [31:0] o_cause_data;
output wire [31:0] o_epc_data;

reg[31:0] status_reg;
reg[31:0] cause_reg;
reg[31:0] epc_reg;

assign o_status_data = status_reg;
assign o_cause_data = cause_reg;
assign o_epc_data = epc_reg;

always @(posedge i_clk) begin
    if(i_reset==1) begin
        status_reg = 8'b00000000;
        cause_reg = 8'b00000000;
        epc_reg = 8'b00000000;
    end else if(i_we==1)begin
        case(i_sel)
          5'b01100:status_reg <= i_data;
          5'b01101:cause_reg <= i_data;
          5'b01110:epc_reg <= i_data;
          default ;
        endcase
    end
end

endmodule
