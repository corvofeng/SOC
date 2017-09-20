`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/18/2017 04:06:30 PM
// Design Name: 
// Module Name: Learn_sim
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


module Learn_sim();
	reg [15:0] sw = 16'h0000;

	wire [15:0] led;

	Learn learn(.sw(sw), 
		.led(led)
		);

	always #10 sw = sw + 1;
endmodule
