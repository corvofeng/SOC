// Copyright 1986-2016 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2016.2 (lin64) Build 1577090 Thu Jun  2 16:32:35 MDT 2016
// Date        : Tue Dec 13 19:20:59 2016
// Host        : ThinkPad running 64-bit Arch Linux
// Command     : write_verilog -force -mode funcsim
//               /home/corvo/Learning/verilog/CourseSubmit/Oh-My-Project/Oh-My-Project.srcs/sources_1/ip/orgate_0/orgate_0_sim_netlist.v
// Design      : orgate_0
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7a100tcsg324-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "orgate_0,orgate,{}" *) (* DowngradeIPIdentifiedWarnings = "yes" *) (* X_CORE_INFO = "orgate,Vivado 2016.2" *) 
(* NotValidForBitStream *)
module orgate_0
   (a,
    b,
    c);
  input [7:0]a;
  input [7:0]b;
  output [7:0]c;

  wire [7:0]a;
  wire [7:0]b;
  wire [7:0]c;

  orgate_0_orgate inst
       (.a(a),
        .b(b),
        .c(c));
endmodule

(* ORIG_REF_NAME = "orgate" *) 
module orgate_0_orgate
   (c,
    a,
    b);
  output [7:0]c;
  input [7:0]a;
  input [7:0]b;

  wire [7:0]a;
  wire [7:0]b;
  wire [7:0]c;

  LUT2 #(
    .INIT(4'hE)) 
    \c[0]_INST_0 
       (.I0(a[0]),
        .I1(b[0]),
        .O(c[0]));
  LUT2 #(
    .INIT(4'hE)) 
    \c[1]_INST_0 
       (.I0(a[1]),
        .I1(b[1]),
        .O(c[1]));
  LUT2 #(
    .INIT(4'hE)) 
    \c[2]_INST_0 
       (.I0(a[2]),
        .I1(b[2]),
        .O(c[2]));
  LUT2 #(
    .INIT(4'hE)) 
    \c[3]_INST_0 
       (.I0(a[3]),
        .I1(b[3]),
        .O(c[3]));
  LUT2 #(
    .INIT(4'hE)) 
    \c[4]_INST_0 
       (.I0(a[4]),
        .I1(b[4]),
        .O(c[4]));
  LUT2 #(
    .INIT(4'hE)) 
    \c[5]_INST_0 
       (.I0(a[5]),
        .I1(b[5]),
        .O(c[5]));
  LUT2 #(
    .INIT(4'hE)) 
    \c[6]_INST_0 
       (.I0(a[6]),
        .I1(b[6]),
        .O(c[6]));
  LUT2 #(
    .INIT(4'hE)) 
    \c[7]_INST_0 
       (.I0(a[7]),
        .I1(b[7]),
        .O(c[7]));
endmodule
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (weak1, weak0) GSR = GSR_int;
    assign (weak1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule
`endif
