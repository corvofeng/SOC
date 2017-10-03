`timescale 1ns / 1ps

module neokey16(
     reset, cs, clk, ior, address,
     i_col, o_row, o_data
    );
    input reset;
    input cs;
    input clk;      // 100Mhz
    input ior;      // 读信�?
    input[1:0] address;  // 端口�?
    input[3:0] i_col;  // 列线
    output reg [3:0] o_row;  // 行线
    output reg [15:0] o_data;
    
    reg [15:0] keyvalue;
    reg [15:0] keystat;
 
 always @ (negedge clk) begin
     if (reset==1) begin 
     o_data   =16'h0000;
     keyvalue =16'h0000;
     keystat  =16'h0000;
     o_row    = 4'h0;
     end else begin
         case(o_row)
             4'b0000:if(i_col!=4'b1111) o_row<=4'b1110;
             4'b1110:if(i_col!=4'b1111) begin
                         keyvalue[3:0]=i_col;
                         keyvalue[7:4]=o_row;
                         keystat=keystat|16'h0001;
                         o_row<=4'h0;
                     end else
                         o_row<=4'b1101;
             4'b1101:if(i_col!=4'b1111) begin
                         keyvalue[3:0]=i_col;
                         keyvalue[7:4]=o_row;
                         keystat=keystat|16'h0001;
                         o_row<=4'h0;
                      end else
                         o_row<=4'b1011;
             4'b1011:if(i_col!=4'b1111) begin
                         keyvalue[3:0]=i_col;
                         keyvalue[7:4]=o_row;
                         keystat=keystat|16'h0001;
                         o_row<=4'h0;
                      end else
                         o_row<=4'b0111;
             4'b0111:if(i_col!=4'b1111) begin
                         keyvalue[3:0]=i_col;
                         keyvalue[7:4]=o_row;
                         keystat=keystat|16'h0001;
                         o_row<=4'h0;
                      end else begin 
                         o_row<=4'b0000;
                         keystat=keystat&16'hfffe; 
                      end
             endcase
  
 if((cs==1)&&(ior==1))
     if(address==2'b00)
         o_data=keyvalue;
     else if(address==2'b10) begin
         o_data=keystat;
         keystat=keystat&16'hfffe;
       end
     end
end

endmodule
