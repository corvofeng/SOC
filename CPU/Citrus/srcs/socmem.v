`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2016/07/06 16:08:58
// Design Name:
// Module Name: socmem  memÄ£¿é
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


module socmem (
           input mwmem,
           input clk,
           input [31:0] malu,
           input [31:0] mb,
           output reg [31:0] mmo,
           input clrn,
           input mrmem,
           input mrio,
           input mwio,
           
           output LEDCtrl,
           output KEYCtrl,
           output CTCCtrl,
           output PWMCtrl,
           output UARTCtrl,
           output WDTCtrl,
           output[11:0] address,
           output[31:0] write_data,
           input [31:0] mread_data,
           input [15:0] ioread_data_key,
           input [15:0] ioread_data_ctc,
           input [15:0] ioread_data_uart
       );
wire clkn;
assign clkn = ~clk;
wire [15:0]caddr= malu[15:0];
wire [7:0]mem_in= malu[7:0];
wire [31:0] ioout, memout;


MiniSysBus bus(
    .caddress(caddr),
    .clk(clkn),
    .clrn(clrn),
    .memread(mrmem),
    .memwrite(mwmem),
    .ioread(mrio),
    .iowrite(mwio),
    .wdata(mb),
    .rdata(ioout),
    .LEDCtrl(LEDCtrl),
    .KEYCtrl(KEYCtrl),
    .CTCCtrl(CTCCtrl),
    .PWMCtrl(PWMCtrl),
    .UARTCtrl(UARTCtrl),
    .WDTCtrl(WDTCtrl),
    .address(address),
    .write_data(write_data),
    .mread_data(mread_data),
    .ioread_data_key(ioread_data_key),
    .ioread_data_ctc(ioread_data_ctc),
    .ioread_data_uart(ioread_data_uart)
    );

dist_mem_gen_0 mem(
    .a(mem_in),
    .d(mb),
    .clk(clkn),
    .we(mwmem),
    .dpo(memout)
       );
always @(posedge clk or negedge clk) begin 
   if( mrio| mwio ) begin
       mmo<=ioout;
   end else begin
       mmo<=memout;
    end
end

endmodule
