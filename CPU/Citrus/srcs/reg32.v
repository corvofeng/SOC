`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2017/09/24 09:38:52
// Design Name: 
// Module Name: reg32
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


module reg32(
    input [4:0] ra,
    input [4:0] rb,
    input [4:0] wn,
    input [31:0] i,
    input we,
    input clk,
    output reg [31:0] qa,
    output reg [31:0] qb
   );
   reg[31:0] register[31:0];
   
    always @(posedge clk) begin       // 本进程写目标寄存器
        if( we == 1 ) begin  // 注意寄存器0恒等于0
            case( wn[4:0] )
                5'd0:register[0] <= 32'd0;
                5'd1:register[1] <= i;
                5'd2:register[2] <= i;
                5'd3:register[3] <= i;
                5'd4:register[4] <= i;
                5'd5:register[5] <= i;
                5'd6:register[6] <= i;
                5'd7:register[7] <= i;
                5'd8:register[8] <= i;
                5'd9:register[9] <= i;
                5'd10:register[10] <= i;
                5'd11:register[11] <= i;
                5'd12:register[12] <= i;
                5'd13:register[13] <= i;
                5'd14:register[14] <= i;
                5'd15:register[15] <= i;
                5'd16:register[16] <= i;
                5'd17:register[17] <= i;
                5'd18:register[18] <= i;
                5'd19:register[19] <= i;
                5'd20:register[20] <= i;
                5'd21:register[21] <= i;
                5'd22:register[22] <= i;
                5'd23:register[23] <= i;
                5'd24:register[24] <= i;
                5'd25:register[25] <= i;
                5'd26:register[26] <= i;
                5'd27:register[27] <= i;
                5'd28:register[28] <= i;
                5'd29:register[29] <= i;
                5'd30:register[30] <= i;
                5'd31:register[31] <= i;
                default:register[0] <= 32'd0;
              endcase
          end
      end
      
      always @(posedge ra ) begin       // 本进程写目标寄存器
          case( ra [4:0] )
              5'd0:qa[0] <= register[0];
              5'd1:qa[1] <= register[1];
              5'd2:qa[2] <= register[2];
              5'd3:qa[3] <= register[3];
              5'd4:qa[4] <= register[4];
              5'd5:qa[5] <= register[5];
              5'd6:qa[6] <= register[6];
              5'd7:qa[7] <= register[7];
              5'd8:qa[8] <= register[8];
              5'd9:qa[9] <= register[9];
              5'd10:qa[10] <= register[10];
              5'd11:qa[11] <= register[11];
              5'd12:qa[12] <= register[12];
              5'd13:qa[13] <= register[13];
              5'd14:qa[14] <= register[14];
              5'd15:qa[15] <= register[15];
              5'd16:qa[16] <= register[16];
              5'd17:qa[17] <= register[17];
              5'd18:qa[18] <= register[18];
              5'd19:qa[19] <= register[19];
              5'd20:qa[20] <= register[20];
              5'd21:qa[21] <= register[21];
              5'd22:qa[22] <= register[22];
              5'd23:qa[23] <= register[23];
              5'd24:qa[24] <= register[24];
              5'd25:qa[25] <= register[25];
              5'd26:qa[26] <= register[26];
              5'd27:qa[27] <= register[27];
              5'd28:qa[28] <= register[28];
              5'd29:qa[29] <= register[29];
              5'd30:qa[30] <= register[30];
              5'd31:qa[31] <= register[31];
              default:qa[0] <= 32'd0;
          endcase
     end

     always @(posedge rb ) begin       // 本进程写目标寄存器
          case( rb [4:0] )
              5'd0:qb[0] <= register[0];
              5'd1:qb[1] <= register[1];
              5'd2:qb[2] <= register[2];
              5'd3:qb[3] <= register[3];
              5'd4:qb[4] <= register[4];
              5'd5:qb[5] <= register[5];
              5'd6:qb[6] <= register[6];
              5'd7:qb[7] <= register[7];
              5'd8:qb[8] <= register[8];
              5'd9:qb[9] <= register[9];
              5'd10:qb[10] <= register[10];
              5'd11:qb[11] <= register[11];
              5'd12:qb[12] <= register[12];
              5'd13:qb[13] <= register[13];
              5'd14:qb[14] <= register[14];
              5'd15:qb[15] <= register[15];
              5'd16:qb[16] <= register[16];
              5'd17:qb[17] <= register[17];
              5'd18:qb[18] <= register[18];
              5'd19:qb[19] <= register[19];
              5'd20:qb[20] <= register[20];
              5'd21:qb[21] <= register[21];
              5'd22:qb[22] <= register[22];
              5'd23:qb[23] <= register[23];
              5'd24:qb[24] <= register[24];
              5'd25:qb[25] <= register[25];
              5'd26:qb[26] <= register[26];
              5'd27:qb[27] <= register[27];
              5'd28:qb[28] <= register[28];
              5'd29:qb[29] <= register[29];
              5'd30:qb[30] <= register[30];
              5'd31:qb[31] <= register[31];
              default:qb[0] <= 32'd0;
          endcase
     end   
     
endmodule
