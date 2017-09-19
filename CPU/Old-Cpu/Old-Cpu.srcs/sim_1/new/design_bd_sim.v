`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/07/05 20:42:19
// Design Name: 
// Module Name: design_bd_sim
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


module design_bd_sim();
    // input
    reg [31:0] a = 32'd16;
    reg [31:0] b = 32'd12;
    reg SUBctr = 1;
    reg [2:0] OPctr = 3'b000;
    reg OVctr = 1;
    reg SIGctr = 0;
    
     
    //output
  
    wire [31:0] Result;
    wire Zero;
    wire Overflow;
        
       
    // initial
    design_bd U (
        .A(a),
        .B(b),
        .OPctr(OPctr),
        .OVctr(OVctr),
        .Overflow(Overflow),
        .Result(Result),
        .SIGctr(SIGctr),
        .SUBctr(SUBctr),
        .Zero(Zero)
       
        );
    initial begin
        begin a=32'hfffffff4; b=32'hfffffff5; SUBctr=0; OVctr=0; OPctr=3'b000; end     // addu
        #50 begin a = 32'h7f; b=32'h72; SUBctr=0; OVctr=1; end                         // add
        #50 begin a=32'h7ffffff7; b=32'h7ffffffa; SUBctr=0; OVctr=1; end      // add
        #50 begin a=32'hfffffff4; b=32'hfffffff3; SUBctr=0; OVctr=0; OPctr=3'b010; end // and
        #50 begin a=32'hfff0fff4; b=32'hfff1fff5; SUBctr=0; OVctr=0; OPctr=3'b011; end // or
        #50 begin a=32'hff0ffff4; b=32'hff1ffff5; SUBctr=0; OVctr=0; OPctr=3'b101; end // nor
        #50 begin a=32'h00000008; b=32'h00000003; SUBctr=1; OVctr=0; OPctr=3'b000; end // subu
        #50 begin a=32'h00000005; b=32'h00000008; SUBctr=1; OVctr=1; OPctr=3'b000; end // sub
        #50 begin a=32'h00000005; b=32'h00000008; SUBctr=1; OVctr=1; OPctr=3'b001; end // sltu
        #50 begin a=32'hfffffff5; b=32'hfffffff4; SUBctr=1; OVctr=1; OPctr=3'b001; end // sub
    end
endmodule
