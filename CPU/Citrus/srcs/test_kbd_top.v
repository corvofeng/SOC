`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2017/09/20 18:56:25
// Design Name:
// Module Name: test_kbd_top
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


module test_kbd_top(
           reset,
           cs,
           clk,
           ior,
           address,
           col,
           line,
           sel_n,
           seg_n,
           rst,
           clk_50k,
           hope_row,
           hope_col,
           hope_out,
           key_flag,
       );
input reset,cs,clk,ior,rst;
input [1:0] address;
input[3:0] col;
output [3:0] line;
output [7:0] sel_n,seg_n;
output clk_50k;
output [3:0] hope_col, hope_row, hope_out;
output key_flag;    // 键盘值是否有效

reg clk_50k=0;

// output[15:0] ioread_data;
// input[32:0] input_data;

wire[3:0] tmp;

reg[25:0] div_counter = 0;

assign hope_row = line;
assign hope_col = col;
assign hope_out = tmp;

always @ (posedge clk or negedge reset)  //分频50hz
begin
    if(!reset) begin
        div_counter = 0;
    end

    else if(div_counter>=25)
    begin
        clk_50k<=~clk_50k;
        div_counter<=0;
    end

    else
    begin
        div_counter<=div_counter+1;
    end
end

seg segtest(
        .clk(clk),
        .rst(rst),
        .input_data({28'h0, tmp}),
        .sel_n(sel_n),
        .seg_n(seg_n)
    );

key16 keytest(
          .reset(reset),
          .cs(cs),
          .clk(clk_50k),
          .ior(ior),
          .address(address),
          .i_col(col),
          .o_row(line),
          .o_data(tmp),
          .key_flag(key_flag)
      );

endmodule
