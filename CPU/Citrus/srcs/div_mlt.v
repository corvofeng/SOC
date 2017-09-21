/*
 *=============================================================================
 *    Filename: div_mlt.v
 *
 *     Version: 1.0
 *  Created on: September 21, 2017
 *
 *      Author: corvo
 *=============================================================================
 */

/**
 *  32位乘除法器, 由于计算较为耗时, 需要多个时钟周期才能完成
 *    i_en :  使能位, 高电平有效
 *    i_mul:  乘法为1, 除法为0
 *    i_sign : 是否为有符号运算 1: 有符号, 0 无符号 
 *    i_A, i_B: 待计算的数字  运算为A*B以及A/B
 *    o_hi, o_lo: 计算结果: 
 *      乘法计算时, hi保存高位, lo保存低位, 
 *      除法计算时, hi保存语数, lo保存商
 *    o_zero: 除零溢出
 */
module div_mlt(i_clk, i_en, i_mul, i_sign, i_A, i_B, o_hi, o_lo, o_zero);
  input[31:0] i_A, i_B;
  input i_clk, i_en, i_mul, i_sign;

  output reg [31:0] o_hi;
  output reg [31:0] o_lo;
  output o_zero;

  wire div_sign_clk; 
  wire div_unsign_clk;
  wire mlt_sign_clk;
  wire mlt_unsign_clk;

  assign div_sign_clk = i_clk & (i_mul == 0) & i_en & i_sign;   // 除法器在上升沿时计算
  assign div_unsign_clk = i_clk & (i_mul == 0) & i_en & (i_sign == 0);   // 除法器在上升沿时计算
  assign mlt_sign_clk = i_clk & i_mul & i_en & i_sign;
  assign mlt_unsign_clk = i_clk & i_mul & i_en & (i_sign == 0);
  assign o_zero = (i_mul == 0) && i_en && (i_B == 32'h0000);

  reg[63:0] mulOut;

  always @(i_en | mlt_sign_clk | mlt_unsign_clk)
  begin
      if(i_en && i_mul) begin
        mulOut = {32'd0, i_A} * {32'd0, i_B};
        o_hi = mulOut[63:32];
        o_lo = mulOut[31:0];
      end else if (i_en && (i_mul == 0)) begin
        o_hi = i_A % i_B;
        o_lo = i_A / i_B;
      end else begin
      ;
      end
  end


endmodule
