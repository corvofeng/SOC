`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2017/09/19 19:01:18
// Design Name:
// Module Name: key16
// Project Name: Citrus
// Target Devices:
// Tool Versions:
// Description:
//  管脚分配方案:
//    i_col[3:0]  -> {K8, k7, K6, K5}
//    o_row[3:0]  -> {K4, K3, K2, K1}
//    clk         -> k9
//
// Dependencies:
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////


module key16(
           reset, cs, clk, ior, address,
           i_col, o_row, o_data,
           key_flag
       );
input reset;
input cs;
input clk;      // 100Mhz
input ior;      // 读信号
input[1:0] address;  // 端口号
input[3:0] i_col;  // 列线
output[3:0] o_row;  // 行线
output[3:0] o_data;  //输出到系统总线上的数据
output key_flag;  // 键盘是否被按下, 将作为中断控制器的输入

reg[3:0] o_data;
reg[3:0] o_row;

reg[15:0] keyvalue =16'h0000;  //键值寄存器,初始化为0
reg[15:0] keystat;  //状态寄存器
reg key_flag;   //按键标志位
reg [2:0] state;  //状态标志


reg[3:0] col_reg;
reg[3:0] row_reg;

always@(posedge clk or negedge reset)
begin
    if(!reset)
    begin
        o_row <= 4'b000;
    end else

    begin

        case(state)
            0:
            begin
                o_row[3:0] <= 4'b0000;
                key_flag <= 1'b0;
                if(i_col[3:0] != 4'b1111) begin // 发现键盘被按下
                    state <= 1;
                    o_row[3:0] <= 4'b1110;  // 扫面第一列
                end else
                begin
                    state <= 0;
                end
            end
            1:
            begin
                if(i_col != 4'b1111) begin  // 判断是否是第一行
                    state <= 5;
                end else begin  // 扫描第二行
                    state <= 2;
                    o_row <= 4'b1101;
                end
            end
            2:
            begin
                if(i_col != 4'b1111) begin state <= 5; end  /// 判断是否是第二行
                else begin  // 扫描第三行
                    state <= 3;
                    o_row <= 4'b1011;
                end
            end
            3:
            begin
                if(i_col != 4'b1111) begin state <= 5; end
                else begin
                    state <= 4;
                    o_row <= 4'b0111;
                end
            end

            4:
            begin
                if(i_col != 4'b1111) begin
                    state <= 5;
                end else begin
                    state <= 0;
                end
            end
            5:
            begin
                if(i_col != 4'b1111) begin
                    col_reg <= i_col;
                    row_reg <= o_row;
                    state <= 5;
                    key_flag <= 1'b1;
                end else
                    state <= 0;
            end
        endcase

    end
end

always @(clk or row_reg or col_reg)
begin
    if(key_flag == 1'b1) begin
        case ({col_reg, row_reg})
            8'b1110_1110:o_data <= 4'hd;
            8'b1110_1101:o_data <= 4'hc;
            8'b1110_1011:o_data <= 4'hb;
            8'b1110_0111:o_data <= 4'ha;

            8'b1101_1110:o_data <= 4'hf;
            8'b1101_1101:o_data <= 4'h9;
            8'b1101_1011:o_data <= 4'h6;
            8'b1101_0111:o_data <= 4'h3;

            8'b1011_1110:o_data <= 4'h0;
            8'b1011_1101:o_data <= 4'h8;
            8'b1011_1011:o_data <= 4'h5;
            8'b1011_0111:o_data <= 4'h2;

            8'b0111_1110:o_data <= 4'he;
            8'b0111_1101:o_data <= 4'h7;
            8'b0111_1011:o_data <= 4'h4;
            8'b0111_0111:o_data <= 4'h1;
        endcase
    end
end

endmodule
