`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2017/09/30 19:59:07
// Design Name: 
// Module Name: busctr
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


module MiniSysBus(
    caddress,clk,clrn,memread,memwrite,ioread,iowrite,wdata,rdata,
    LEDCtrl,KEYCtrl,CTCCtrl,ICUCtrl,WDTCtrl,//PWMCtrl,
    address,write_data,mread_data,
    ioread_data_key,ioread_data_ctc//,ioread_data_uart
    );
    input [15:0] caddress;
    input clk,clrn,memread,memwrite,ioread,iowrite;
    input [31:0] mread_data;
    input [15:0] ioread_data_key,ioread_data_ctc;//,ioread_data_uart;
    input [31:0] wdata;
    output [31:0] rdata,write_data;
    output LEDCtrl,KEYCtrl,CTCCtrl,ICUCtrl,WDTCtrl;//PWMCtrl,
    output [15:0] address;
    
    reg [31:0] write_data;
    wire iorw;
    reg [15:0] ioread_data;
    
    assign address = caddress[15:0];
    assign rdata = ( memread == 1 )? mread_data : {16'h0000,ioread_data[15:0]};
    assign iorw = ( ioread || iowrite);
    
    assign LEDCtrl = ((iorw==1) && (caddress[15:4]==12'hff0))?1'b1:1'b0;
    assign KEYCtrl = ((iorw==1) && (caddress[15:4]==12'hff1))?1'b1:1'b0;
    assign CTCCtrl = ((iorw==1) && (caddress[15:4]==12'hff2))?1'b1:1'b0;
   // assign PWMCtrl = ((iorw==1) && (caddress[15:4]==12'hff3))?1'b1:1'b0;
    assign ICUCtrl = ((iorw==1) && (caddress[15:4]==12'hff4))?1'b1:1'b0;
    assign WDTCtrl = ((iorw==1) && (caddress[15:4]==12'hff5))?1'b1:1'b0;
    
    always @( wdata or memwrite or iowrite) begin 
        if((memwrite==1)||(iowrite==1)) begin
            write_data=wdata;
        end else begin
            write_data=32'hZZZZ_ZZZZ;
        end
    end
    
    always @(clrn or ioread or KEYCtrl or CTCCtrl or  ioread_data_key or ioread_data_ctc /*or ioread_data_uart*/) begin 
        if(clrn==1) begin
            ioread_data=16'h0000;
        end 
        else if(ioread==1) begin
            if(KEYCtrl==1)
                ioread_data=ioread_data_key;
            else if(CTCCtrl==1)
                ioread_data=ioread_data_ctc;
//            else if(UARTCtrl==1)
//                ioread_data=ioread_data_uart;     
        end
    end
    
    
 endmodule
