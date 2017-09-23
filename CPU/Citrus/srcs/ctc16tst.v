 `timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2017/9/21 16:11:21
// Design Name: 
// Module Name: ctc16
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

module ctc16(
	reset,clk,cs,iow,ior,i_pulse0,i_pulse1,address,i_write_data,
	o_read_data,cout0,cout1
	);

input reset,clk,iow,ior;
input i_pulse0,i_pulse1;  //两个cnt的外部脉冲信号
input[3:0] address;  //端口号
input[15:0] i_write_data;  //写入的数据
output[15:0] o_read_data;  //读出的数据
output cout1,cout0;  //两个cnt的输出引脚


reg cout0,cout1;
reg[15:0] o_read_data;
reg[15:0] status1,status2;  //cnt0和cnt1的状态寄存器
reg[15:0] stat11,stat12,stat21,stat22;  //临时状态寄存器
reg[15:0] mode1,mode2;  //方式寄存器
reg[15:0] count1,count2;  //减1计数器
reg[15:0] cnt11,cnt12,cnt21,cnt22;  //临时减1计数器
reg[15:0] initcnt1,initcnt2;  //两个cnt的初始值寄存器
reg[15:0] rubbish;

always @(negedge clk) begin
	if (reset==1) begin
		// reset
		cout0=1;
		cout1=1;
		initcnt1=16'h0000;
		initcnt2=16'h0000;
		cnt11
		
	end
	else if () begin
		
	end
end

endmodule