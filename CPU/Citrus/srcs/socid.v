`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2016/07/06 16:08:58
// Design Name:
// Module Name: socid  idģ��
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


module socid (

           input [31:0] dpc4,//pc
           input [31:0] inst,//ָ��
           input [31:0] wdi,//reginput
           input [4:0] wrn,//Ŀ�ļĴ���
           input [31:0] ealu,
           input [31:0] malu,
           input [31:0] mmo,
           input [4:0] mrn,
           input mm2reg,
           input [4:0] ern,
           input em2reg,
           input ewreg,
           input wwreg,
           input clk,
           input clrn,
           input mwreg,

           output [1:0] fwda,
           output [1:0] fwdb,
           output reg [31:0] da,//dpc/da
           output reg [31:0] db,
           output reg [31:0] dimm,
           output reg [4:0] drn,
           output wreg,
           output m2reg,
           output wmem,
           output jal,
           output aluimm,
           output shift,
           output [3:0] aluc,
           output [31:0] jpc,
           output [31:0] bpc,
           output nostall,
           output [4:0] rs,
           output [4:0] rt,
           output [4:0] rd,
           output [4:0] shamt,
           output [5:0] func,
           output [5:0]  op,
           output [1:0] pcsource,

           input ov,
           input [31:0] pc,
           input [31:0] pcd,
           input [31:0] pce,
           input [31:0] pcm,
           output [31:0] sta,
           output [31:0] epc,
           output [31:0] cau,
           output [1:0] selpc,
           output [1:0] mfc0,

           input intr,
           output inta,
           input [7:0] vector,
           input ecancel,
           output cancel,

           output rmem,
           output rio,
           output wio,

           output[1:0] mfhilo,
           output[31:0] o_HI_data,
           output[31:0] o_LO_data
       );
//    output [4:0] rs,rt,rd,shamt;
//	output [5:0] func,op;
wire [15:0] imme;
wire [25:0] addr;
wire  [31:0] qa,qb;
wire [31:0] bpc,bpc0;
wire [7:0] immehi;
wire sext,regrt,ilui;
reg  rsrtequ;
wire clkn=~clk;

assign op[5:0]    = inst[31:26],
       rs[4:0]    = inst[25:21],
       rt[4:0]    = inst[20:16],
       rd[4:0]    = inst[15:11],
       shamt[4:0] = inst[10:6],
       func[5:0]  = inst[5:0],
       imme[15:0] = inst[15:0],
       immehi[7:0]= inst[15:8],
       addr[25:0] = inst[25:0];

assign jpc[31:28] = dpc4[31:28],//jpc
       jpc[27:2] = addr[25:0],
       jpc[1:0] = 2'b00;


always @ ( sext or shift or shamt or imme) begin//shift
    if (shift != 0)begin
        dimm[15:5] <= 11'h000;
        dimm[4:0]  <= shamt[4:0];
    end else begin
        dimm[15:0] <= imme[15:0];
    end

    if (sext != 0 & imme[15]==1 )begin//dimm
        dimm[31:16] <= 16'hffff;
    end else begin
        dimm[31:16] <= 16'h0000;
    end

    if(ilui==1)begin
        dimm[31:16] <= dimm[15:0];
        dimm[15:0] <= 16'h0000;
    end

end

assign bpc0[31:2] = dimm[29:0],
       bpc0[1:0]  = 2'b00;
assign bpc = dimm + dpc4;

always @ ( fwda or qa or mmo or malu or ealu ) begin//da
    case(fwda)
        2'b00:da <= qa;
        2'b01:da <= ealu;
        2'b10:da <= malu;
        2'b11:da <= mmo;
        default:da <= 32'h0000_0000;
    endcase
end

always @ ( fwdb or qb or mmo or malu or ealu ) begin//db
    case(fwdb)
        2'b00:db <= qb;
        2'b01:db <= ealu;
        2'b10:db <= malu;
        2'b11:db <= mmo;
        default:db <= 32'h0000_0000;
    endcase
end





always @ ( rd or rt or regrt ) begin//da
    case(regrt)
        0:drn <= rd;
        1:drn <= rt;
        default:drn <= 5'b00000;
    endcase
end

always @ ( da or db ) begin//rsrtequ
    if ( da != db ) begin
        rsrtequ <= 0;
    end else begin
        rsrtequ <= 1;
    end
end

wire wsta,wcau,wepc;
wire mtc0;
wire[31:0] sta,epc,cau;
wire[31:0] cause;
wire[1:0] sepc;
wire[1:0] selpc;
wire [1:0] mfc0;

cpuctr cpuctr0(
           .op(op),
           .rs(rs),
           .rt(rt),
           .rd(rd),
           .func(func),
           .rerteqe(rsrtequ),
           .ewreg(ewreg),
           .em2reg(em2reg),
           .ern(ern),
           .mwreg(mwreg),
           .mm2reg(mm2reg),
           .mrn(mrn),
           .wreg(wreg),
           .m2reg(m2reg),
           .wmem(wmem),
           .pcsource(pcsource),
           .fwda(fwda),
           .fwdb(fwdb),
           .regrt(regrt),
           .sext(sext),
           .shift(shift),
           .jal(jal),
           .aluimm(aluimm),
           .aluc(aluc),
           .nostall(nostall),
           .clrn(clrn),
           .ilui(ilui),

           .intr(intr),
           .ecancel(ecancel),
           .earith(),
           .eisbr(),
           .misbr(),
           .ov(ov),
           .sta(sta),
           .vector(vector),

           .exc(exc),
           .wsta(wsta),
           .wcau(wcau),
           .wepc(wepc),
           .unimpl_inst(),
           .mtc0(mtc0),
           .isbr(),
           .arith(),
           .cancel(cancel),
           .inta(inta),
           .mfc0(mfc0),
           .selpc(selpc),
           .sepc(sepc),
           .cause(cause),

           .immehi(immehi),
           .rmem(rmem),
           .wio(wio),
           .rio(rio),

           .mul_div(mul_div),
           .symbol(symbol),
           .mul_start(mul_start),
           .div_start(div_start),
           .mthi(mthi),
           .mtlo(mtlo),
           .whi(whi),
           .wlo(wlo),
           .mfhilo(mfhilo),
           .mul_busy(mul_busy),
           .div_busy(div_busy)
       );

reg32 regfil(
          .ra(rs),
          .rb(rt),
          .wn(wrn),
          .i(wdi),
          .we(wwreg),
          .clk(clkn),
          .qa(qa),
          .qb(qb),
          .clrn(clrn)
      );

CP0 reg_CP0(
    .i_clk(clk),
    .i_reset(clrn),

    .i_exc(exc),
    .i_cause(cause),
    .i_selpc_epc(sepc),
    .i_pc(pc),
    .i_pcd(pcd),
    .i_pce(pce),
    .i_pcm(pcm),

    .i_wsta(wsta),
    .i_wcau(wcau),
    .i_wepc(wepc),

    .i_mtc0(mtc0),
    .i_data(db),

    .o_status_data(sta),
    .o_epc_data(epc),
    .o_cause_data(cau)
    );

reg[31:0] i_HI_data;
reg[31:0] i_LO_data;
wire [63:0] mul_out;
wire [31:0] div_q;
wire [31:0] div_r;

wire mul_div;
wire mthi;
wire mtlo;
wire whi;
wire wlo;
wire symbol;
wire mul_start;
wire div_start;
wire mul_busy;
wire div_busy;

always @ ( mul_div or mul_out or div_r or div_q ) begin
    if(mul_div == 0) begin
        i_HI_data <= mul_out[63:32];
        i_LO_data <= mul_out[31:0];
    end else begin
        i_HI_data <= div_r;
        i_LO_data <= div_q;
    end
end

HI_LO reg_HILO(
    .i_clk(i_clk),
    .i_reset(clrn),
    .i_data(da),
    .i_HI_data(i_HI_data),
    .i_LO_data(i_LO_data),
    .i_mthi(mthi),
    .i_mtlo(mtlo),
    .i_whi(whi),
    .i_wlo(wlo),

    .o_HI_data(o_HI_data),
    .o_LO_data(o_LO_data)
    );

multiplier mul(
    .a(da),
    .b(db),
    .symbol(symbol),
    .start(mul_start),
    .clk(i_clk),
    .reset(clrn),
    .o(mul_out),
    .busy(mul_busy)
    );

divider div(
    .a(da),
    .b(db),
    .symbol(symbol),
    .start(div_start),
    .clk(i_clk),
    .reset(clrn),
    .q(div_q),
    .r(div_r),
    .busy(div_busy)
    );
endmodule
