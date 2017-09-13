`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/07/06 16:08:58
// Design Name: 
// Module Name: dff
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

// 同步置数, 异步清零
// q: OUTPUT
// d: INPUT
// ce: Write enable
// ck: clock
// clrn: set 0
module dff#(parameter WIDTH=8) (
    q, d, ce, ck, clrn
    );
    
    output [(WIDTH-1):0] q;
    input ck, ce, clrn;
    input [(WIDTH-1):0] d;
    reg [(WIDTH-1):0] q;
    wire ck, ce, clrn;
    
    always @(posedge ck or posedge clrn) begin
        if (ce) begin
            if (clrn) begin
                q <= q;
            end
            else
                q <= d;
        end
        else 
            q <= q;
    end
    
endmodule
