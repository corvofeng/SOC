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
    input clrn,
    output reg [31:0] qa,
    output reg [31:0] qb
   );
   reg[31:0] register[31:0];
     
    always @(posedge clk) begin       // 本进程写目标寄存器
        if( clrn==1 ) begin
          qa <= 32'd0;
          qb <= 32'd0;
           register[0] <= 32'd0;
          register[1] <= 32'd0;
          register[2] <= 32'd0;
          register[3] <= 32'd0;
           register[4] <= 32'd0;
           register[5] <= 32'd0;
           register[6] <=  32'd0;
           register[7] <= 32'd0;
           register[8] <=  32'd0;
           register[9] <= 32'd0;
           register[10] <=  32'd0;
           register[11] <=  32'd0;
           register[12] <=  32'd0;
           register[13] <=  32'd0;
           register[14] <=  32'd0;
           register[15] <=  32'd0;
           register[16] <= 32'd0;
           register[17] <= 32'd0;
           register[18] <= 32'd0;
           register[19] <= 32'd0;
           register[20] <= 32'd0;
           register[21] <= 32'd0;
           register[22] <= 32'd0;
           register[23] <= 32'd0;
           register[24] <= 32'd0;
           register[25] <= 32'd0;
           register[26] <= 32'd0;
           register[27] <= 32'd0;
           register[28] <= 32'd0;
           register[29] <= 32'd0;
           register[30] <= 32'd0;
           register[31] <= 32'd0;
          end
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
                endcase
          end
      end
      
      always @( ra ) begin       // 本进程写目标寄存器
          case( ra [4:0] )
              5'd0:qa <= register[0];
              5'd1:qa <= register[1];
              5'd2:qa <= register[2];
              5'd3:qa <= register[3];
              5'd4:qa <= register[4];
              5'd5:qa <= register[5];
              5'd6:qa <= register[6];
              5'd7:qa <= register[7];
              5'd8:qa <= register[8];
              5'd9:qa <= register[9];
              5'd10:qa <= register[10];
              5'd11:qa <= register[11];
              5'd12:qa <= register[12];
              5'd13:qa <= register[13];
              5'd14:qa <= register[14];
              5'd15:qa <= register[15];
              5'd16:qa <= register[16];
              5'd17:qa <= register[17];
              5'd18:qa <= register[18];
              5'd19:qa <= register[19];
              5'd20:qa <= register[20];
              5'd21:qa <= register[21];
              5'd22:qa <= register[22];
              5'd23:qa <= register[23];
              5'd24:qa <= register[24];
              5'd25:qa <= register[25];
              5'd26:qa <= register[26];
              5'd27:qa <= register[27];
              5'd28:qa <= register[28];
              5'd29:qa <= register[29];
              5'd30:qa <= register[30];              
              5'd31:qa <= register[31];    
              endcase
     end

     always @( rb ) begin       // 本进程写目标寄存器
          case( rb [4:0] )
              5'd0:qb <= register[0];
          5'd1:qb <= register[1];
          5'd2:qb <= register[2];
          5'd3:qb <= register[3];
          5'd4:qb <= register[4];
          5'd5:qb <= register[5];
          5'd6:qb <= register[6];
          5'd7:qb <= register[7];
          5'd8:qb <= register[8];
          5'd9:qb <= register[9];
          5'd10:qb <= register[10];
          5'd11:qb <= register[11];
          5'd12:qb <= register[12];
          5'd13:qb <= register[13];
          5'd14:qb <= register[14];
          5'd15:qb <= register[15];
          5'd16:qb <= register[16];
          5'd17:qb <= register[17];
          5'd18:qb <= register[18];
          5'd19:qb <= register[19];
          5'd20:qb <= register[20];
          5'd21:qb <= register[21];
          5'd22:qb <= register[22];
          5'd23:qb <= register[23];
          5'd24:qb <= register[24];
          5'd25:qb <= register[25];
          5'd26:qb <= register[26];
          5'd27:qb <= register[27];
          5'd28:qb <= register[28];
          5'd29:qb <= register[29];
          5'd30:qb <= register[30];              
          5'd31:qb <= register[31];  
            endcase
     end   
     
endmodule
