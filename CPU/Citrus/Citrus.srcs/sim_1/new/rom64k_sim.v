`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/19/2017 08:53:07 AM
// Design Name: 
// Module Name: rom64k_sim
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


module rom64k_sim();

    reg [15:0] sw = 16'h0000;
    wire [31:0] data;

    rom64k rom(sw, data);

    always #10 sw = sw + 1;
endmodule
