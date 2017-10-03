`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2017/10/02 23:57:36
// Design Name: 
// Module Name: Minisys
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


module Minisys(
    sel_n,seg_n,
    i_col,o_row,
    clk,clrn
    );

wire [7:0] vector;
input clk,clrn;
wire intr,inta;
wire LEDCtrl,KEYCtrl,CTCCtrl,ICUCtrl;
wire [15:0] address;
wire [1:0] addr2 = address[1:0];
wire [31:0] wdata;
wire [15:0] rdata;
wire [15:0] key_data,ctc_data;
wire we,re;
wire [7:0] wdata8 = wdata[7:0];
wire [15:0] wdata16 = wdata[15:0];
//wire pulse0,pulse1;
//wire COUT0,COUT1;
output [7:0] sel_n,seg_n;
input[3:0] i_col;
output[3:0] o_row;
wire [3:0] key_value=key_data[3:0];
wire [7:0] icwn;

cpu cpu(
    .clk(clk),
    .clrn(clrn),
    .intr(intr),
    .inta(inta),
    .vector(vector),
    .LEDCtrl(LEDCtrl),
    .KEYCtrl(KEYCtrl),
    .CTCCtrl(CTCCtrl),
    .ICUCtrl(ICUCtrl),
   // .WDTCtrl(),
    .address(address),
    .write_data(wdata),
    .mread_data(rdata),
    .ioread_data_key(key_data),
    .ioread_data_ctc(ctc_data),
    .mrio(we),
    .mwio(re)
    );

ICU interrupt(
    .i_interrupt(icwn),
    .i_addr(addr2),
    .i_we(we),
    .i_cs(ICUCtrl),
    .i_data(wdata8),
    .i_inta(inta),
    .i_clk(clk),
    .o_intr(intr),
    .o_vector(vector)
    );   
    
ctc16 ctc(
    .rdata(ctc_data),
    .wdata(wdata16),
    .CS(CTCCtrl),
    .CLK(clk),
    .Reset(clrn),
    .address(address),
    .IOW(we),
    .IOR(re),
    .COUT0(icwn[5])
    );
   
seg seg(
    .input_data(wdata),
    .sel_n(sel_n),
    .seg_n(seg_n),
    .clk(clk),  //系统时钟100mhz
    .rst(clrn)  //复位,低电平有�?
    );
    
key16 key(
    .reset(clrn),
    .cs(KEYCtrl),
    .clk(clk),
    .ior(we),
    .address(addr2),
    .i_col(i_col),
    .o_row(o_row),
    .o_data(key_value),
    .key_flag(icwn[4])
    );
    
endmodule
