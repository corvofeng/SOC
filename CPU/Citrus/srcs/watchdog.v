`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2017年9月24日 11:04:42
// Design Name: 看门狗
// Module Name:
// Project Name:
// Target Devices:
// Tool Versions:
// Description:
//
// Dependencies:
//
// Revision:
//
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////

module watchdog(
	cs,clk,o_rst_cpu,iow,reset
	);
input cs,clk,iow,reset;
output o_rst_cpu;
reg[2:0] cnt;//复位信号定时器
reg[15:0] count;//16位定时器

always @(posedge clk) begin
	if (reset) begin
		// reset
		count=16'hffff;
		cnt=3'b000;
		o_rst_cpu=0;
		
	end
	else 
	begin 
		//定时器
		if (count==16'h0000) 
		begin
		cnt=3'b100;
		count=16'hffff;
		o_rst_cpu=1;	
		end
		else
			count=count-1;
		//定时到0，输出4个周期的复位cpu信号
		if (cnt==3'b000)
			o_rst_cpu=0;
		else
			cnt=cnt-1;
		//程序定期发出的复位信号
		if(cs&&iow)
		begin
			count=16'hffff;
			cnt=3'b000;
			o_rst_cpu=0;
		end
	end
end
endmodule