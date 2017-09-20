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
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module key16(
  reset,cs,clk,ior,address,col,line,ioread_data
    );
    input reset;
    input cs;
    input clk;
    input ior;  //读信号
    input[1:0] address;  //端口号
    input[3:0] col;  //列线
    output[3:0] line;  //行线
    output[15:0] ioread_data;  //输出到系统总线上的数据
    
    reg[15:0] ioread_data;
    reg[3:0] line;
    reg[15:0] keyvalue;  //键值寄存器
    reg[15:0] keystat;  //状态寄存器
    
    always@(negedge clk)
    begin
      if(reset==1)
      begin
        ioread_data=16'b0000000000000000;
        keyvalue=16'b0000000000000000;
        keystat=16'b0000000000000000;
        line=4'b0000;
      end else begin
        case(line)
          4'b0000:if(col!=4'b1111) line<=4'b1110;
          4'b1110:if(col!=4'b1111)begin  //扫描0行
            keyvalue[3:0]=col;
            keyvalue[7:4]=line;
            keystat=keystat|16'b0000000000000001;
            line<=4'b0000;
          end else 
            line<=4'b1101;  //如果0行无键，准备扫描1行
          4'b1101:if(col!=4'b1111)begin  //扫描1行
             keyvalue[3:0]=col;
             keyvalue[7:4]=line;
             keystat=keystat|16'b0000000000000001;
             line<=4'b0000;
           end else 
             line<=4'b1011;  
          4'b1011:if(col!=4'b1111)begin  //扫描2行
                keyvalue[3:0]=col;
                keyvalue[7:4]=line;
                keystat=keystat|16'b0000000000000001;
                line<=4'b0000;
              end else 
                line<=4'b0111;  
          4'b0111:if(col!=4'b1111)begin
                   keyvalue[3:0]=col;
                   keyvalue[7:4]=line;
                   keystat=keystat|16'b0000000000000001;
                   line<=4'b0000;
                 end else begin
                   line<=4'b0000;
                   keystat=keystat&16'b1111111111111110;
                 end
      endcase
      if((cs==1)&&(ior==1))begin
        if(address==2'b00)  //读键值
          ioread_data=keyvalue;
        else if(address==2'b10)begin 
          ioread_data=keystat;
          keystat=keystat&16'b1111111111111110;
        end
      end
    end
  end
endmodule
