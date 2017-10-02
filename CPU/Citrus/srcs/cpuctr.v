`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2017/09/21 08:46:25
// Design Name:
// Module Name: cpuctr
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


module cpuctr(
           input [5:0] op,
           input [4:0] rs,
           input [4:0] rt,
           input [4:0] rd,
           input [5:0] func,
           input [7:0] immehi,
           input rerteqe,
           input ewreg,
           input em2reg,
           input [4:0] ern,
           input mwreg,
           input mm2reg,
           input [4:0] mrn,
           input clrn,
           output wreg,
           output m2reg,
           output wmem,
           output rmem,
           output wio,
           output rio,

           output [1:0] pcsource,
           output nostall,
           output reg [1:0] fwda,
           output reg [1:0] fwdb,
           output regrt,
           output sext,
           output shift,
           output jal,
           output aluimm,
           output ilui,
           output [3:0] aluc,

           input intr,
           input ecancel,
           input earith,
           input eisbr,
           input misbr,
           input ov,
           input [31:0]sta,
           output exc,
           output wsta,
           output wcau,
           output wepc,
           output unimpl_inst,
           output mtc0,
           output isbr,
           output arith,
           output cancel,
           output inta,
           input [7:0] vector,
           output [1:0] mfc0,
           output [1:0] selpc,
           output [1:0] sepc,
           output [31:0] cause,

           output mul_div,
           output symbol,
           output mul_start,
           output div_start,
           output mthi,
           output mtlo,
           output whi,
           output wlo,
           output[1:0] mfhilo
       );
wire clr=~clrn;
wire r_type, iadd, iaddu, isub, isubu, imult, imultu, idiv, idivu, imfhi,
     imthi, imflo, imtlo, iand, ior, ixor, inor, islt, isltu,
     isll, isrl, isra, isllv, isrlv, israv, ijr, ijalr,
     iaddi, iaddiu, iandi, iori, ixori, ilb, ilh, ilw, ilbu,
     ilhu, isb, ish, isw, ibeq, ibne, ibltz, ibgez, iblez, ibgtz, ibltzal,
     ibgezal, islti, isltiu, ij, ijal,
     c0_type, imfc0, imtc0, unimpl_inst,cancel;

assign isbr = ibeq | ibne | ij | ijal | ijalr | ibltz | ibgez | iblez | ibgtz | ibltzal | ibgezal;
assign arith = iadd | isub | iaddi;
wire overflow = ov & earith;
assign inta = ieret;
wire exc_int = ~sta[0] & intr;
//wire exc_sys = sta[1] & isyscall;
wire exc_uni = ~sta[2] & unimpl_inst;
wire exc_ovr = ~sta[3] & overflow;
assign exc = exc_int | exc_uni | exc_ovr; //| exc_sys
assign cancel = exc;
assign sepc[1] = exc_uni & eisbr | exc_ovr;
assign sepc[0] = exc_int &  isbr //| exc_sys
        |exc_uni &~eisbr | exc_ovr & misbr;

wire ExcCode0 = overflow | intr;//|syscall;
wire ExcCode1 = unimpl_inst | overflow;
assign cause = { vector,20'h0, ExcCode1, ExcCode0, 2'b00};
assign mtc0 = imtc0;
assign wsta = exc | mtc0 & rd_is_status | ieret;
assign wcau = exc | mtc0 & rd_is_cause;
assign wepc = exc | mtc0 & rd_is_epc;
wire rd_is_status = (rd == 5'd12);
wire rd_is_cause  = (rd == 5'd13);
wire rd_is_epc    = (rd == 5'd14);

assign mfc0[0] = imfc0 & rd_is_status | imfc0 & rd_is_epc;
assign mfc0[1] = imfc0 & rd_is_cause  | imfc0 & rd_is_epc;

assign selpc[0] = ieret;
assign selpc[1] = exc;

and(unimpl_inst,~iadd,~iaddu,~isub,~isubu,~imult,~imultu,~idiv, ~idivu, ~imfhi,
           ~imthi, ~imflo, ~imtlo, ~iand, ~ior, ~ixor, ~inor, ~islt, ~isltu,
           ~isll, ~isrl, ~isra, ~isllv, ~isrlv, ~israv, ~ijr, ~ijalr,
           ~iaddi, ~iaddiu, ~iandi, ~iori, ~ixori, ~ilb, ~ilh, ~ilw, ~ilbu,
           ~ilhu, ~isb, ~ish, ~isw, ~ibeq, ~ibne, ~ibltz, ~ibgez, ~iblez, ~ibgtz, ~ibltzal,
           ~ibgezal, ~islti, ~isltiu, ~ij, ~ijal,~clrn,~ilui,~imfc0,~imtc0);
and(c0_type,  ~op[5], op[4],~op[3],~op[2],~op[1],~op[0]);
and(imfc0, c0_type,~rs[2]); //mfc0 op=010000 rs=00000
and(imtc0, c0_type, rs[2]); //mtc0 op=010000 rs=00100
and(ieret, c0_type,~func[5], func[4], func[3],~func[2],~func[1],~func[0] );//eretfunc=011000
//syscall
//break



and(r_type, ~op[5],~op[4],~op[3],~op[2],~op[1],~op[0]); //op==000000?
and(bgeltz, ~op[5],~op[4],~op[3],~op[2],~op[1], op[0]); //bge or lt z=000001

and(iadd,   r_type, func[5],~func[4],~func[3],~func[2],~func[1],~func[0]);//func=100000
and(iaddu,  r_type, func[5],~func[4],~func[3],~func[2],~func[1], func[0]);//func=100001
and(isub,   r_type, func[5],~func[4],~func[3],~func[2], func[1],~func[0]);//func=100010
and(isubu,  r_type, func[5],~func[4],~func[3],~func[2], func[1], func[0]);//func=100011

and(imult,  r_type,~func[5], func[4], func[3],~func[2],~func[1],~func[0]);//func=011000
and(imultu, r_type,~func[5], func[4], func[3],~func[2],~func[1], func[0]);//func=011001
and(idiv,   r_type,~func[5], func[4], func[3],~func[2], func[1],~func[0]);//func=011010
and(idivu,  r_type,~func[5], func[4], func[3],~func[2], func[1], func[0]);//func=011011

and(imfhi,  r_type,~func[5], func[4],~func[3],~func[2],~func[1],~func[0]);//func=010000
and(imthi,  r_type,~func[5], func[4],~func[3],~func[2],~func[1], func[0]);//func=010001
and(imflo,  r_type,~func[5], func[4],~func[3],~func[2], func[1],~func[0]);//func=010010
and(imtlo,  r_type,~func[5], func[4],~func[3],~func[2], func[1], func[0]);//func=010011



and(iand,   r_type, func[5],~func[4],~func[3], func[2],~func[1],~func[0]);//func=100100
and(ior,    r_type, func[5],~func[4],~func[3], func[2],~func[1], func[0]);//func=100101
and(ixor,   r_type, func[5],~func[4],~func[3], func[2], func[1],~func[0]);//func=100110
and(inor,   r_type, func[5],~func[4],~func[3], func[2], func[1], func[0]);//func=100111

and(islt,   r_type, func[5],~func[4], func[3],~func[2], func[1],~func[0]);//func=101010
and(isltu,  r_type, func[5],~func[4], func[3],~func[2], func[1], func[0]);//func=101011

and(isll,   r_type,~func[5],~func[4],~func[3],~func[2],~func[1],~func[0]);//func=000000
and(isrl,   r_type,~func[5],~func[4],~func[3],~func[2], func[1],~func[0]);//func=000010
and(isra,   r_type,~func[5],~func[4],~func[3],~func[2], func[1], func[0]);//func=000011
and(isllv,  r_type,~func[5],~func[4],~func[3], func[2],~func[1],~func[0]);//func=000100
and(isrlv,  r_type,~func[5],~func[4],~func[3], func[2], func[1],~func[0]);//func=000110
and(israv,  r_type,~func[5],~func[4],~func[3], func[2], func[1], func[0]);//func=000111

and(ijr,    r_type,~func[5],~func[4], func[3],~func[2],~func[1],~func[0]);//func=001000
and(ijalr,  r_type,~func[5],~func[4], func[3],~func[2],~func[1], func[0]);//func=001001

and(iaddi,  ~op[5],~op[4], op[3],~op[2],~op[1],~op[0]);//op=001000
and(iaddiu, ~op[5],~op[4], op[3],~op[2],~op[1], op[0]);//op=001001

and(iandi,  ~op[5],~op[4], op[3], op[2],~op[1],~op[0]);//op=001100
and(iori,   ~op[5],~op[4], op[3], op[2],~op[1], op[0]);//op=001101
and(ixori,  ~op[5],~op[4], op[3], op[2], op[1],~op[0]);//op=001110

and(ilui,   ~op[5],~op[4], op[3], op[2], op[1], op[0]);//op=001111

and(ilb,     op[5],~op[4],~op[3],~op[2],~op[1],~op[0]);//op=100000
and(ilh,     op[5],~op[4],~op[3],~op[2],~op[1], op[0]);//op=100001
and(ilw,     op[5],~op[4],~op[3],~op[2], op[1], op[0]);//op=100011
and(ilbu,    op[5],~op[4],~op[3], op[2],~op[1],~op[0]);//op=100100
and(ilhu,    op[5],~op[4],~op[3], op[2],~op[1], op[0]);//op=100101
and(isb,     op[5],~op[4], op[3],~op[2],~op[1],~op[0]);//op=101000
and(ish,     op[5],~op[4], op[3],~op[2],~op[1], op[0]);//op=101001
and(isw,     op[5],~op[4], op[3],~op[2], op[1], op[0]);//op=101011

and(ibeq,   ~op[5],~op[4],~op[3], op[2],~op[1],~op[0]);//op=000100
and(ibne,   ~op[5],~op[4],~op[3], op[2],~op[1], op[0]);//op=000101
and(ibgez,  bgeltz,~rt[4],~rt[3],~rt[2],~rt[1], rt[0]);//rt=00001
and(ibgtz,  ~op[5],~op[4],~op[3], op[2], op[1], op[0]);//op=000111
and(iblez,  ~op[5],~op[4],~op[3], op[2], op[1],~op[0]);//op=000110
and(ibltz,  bgeltz,~rt[4],~rt[3],~rt[2],~rt[1],~rt[0]);//rt=00000
and(ibgezal,bgeltz, rt[4],~rt[3],~rt[2],~rt[1], rt[0]);//rt=10001
and(ibltzal,bgeltz, rt[4],~rt[3],~rt[2],~rt[1],~rt[0]);//rt=10000

and(islti,  ~op[5],~op[4], op[3],~op[2], op[1],~op[0]);//op=001010
and(isltiu, ~op[5],~op[4], op[3],~op[2], op[1], op[0]);//op=001011

and(ij,     ~op[5],~op[4],~op[3],~op[2], op[1],~op[0]);//op=000010
and(ijal,   ~op[5],~op[4],~op[3],~op[2], op[1], op[0]);//op=000011

//=============================================================================
wire irs   = iadd  | iaddu  | isub  | isubu | imfhi | imflo | iand   | ior   | ixor  |
     inor  | islt   | isltu | isll  | isrl  | isra  | isllv  | isrlv | israv |
     ijalr  | ijr ;
wire irt   = iaddi | iaddiu | iandi | iori  | ixori | ilui  | ilb    | ilh   | ilw   |
     ilbu  | ilhu   | isw   | isb   | ish   | islti | isltiu | ij | ijal | ibeq |
     ibne  | ibgez  | ibgtz | iblez | ibltz | ibgezal | ibltzal;
assign nostall = ~((ewreg & em2reg & ( ern != 0 ) & (irs & ( ern == rs )| irt & ( ern == rt )))&clr);
always @ (ewreg or mwreg or ern or mrn or em2reg or mm2reg or rs or rt or clr) begin

    fwda = 2'b00; //default
    if (ewreg & (ern != 0) & (ern == rs) & ~em2reg ) begin
        fwda = 2'b01;//exe_alu
    end else begin
        if (mwreg & (mrn != 0) & (mrn == rs) & ~mm2reg) begin
            fwda = 2'b10;//mem_alu
        end else begin
            if (mwreg & (mrn != 0) & (mrn == rs) &  mm2reg) begin
                fwda = 2'b11;//mem_lw
            end
        end
    end
    fwdb = 2'b00;
    if (ewreg & (ern != 0) & (ern == rt) & ~em2reg ) begin
        fwdb = 2'b01;//exe_alu
    end else begin
        if (mwreg & (mrn != 0) & (mrn == rt) & ~mm2reg) begin
            fwdb = 2'b10;//mem_alu
        end else begin
            if (mwreg & (mrn != 0) & (mrn == rt) &  mm2reg) begin
                fwdb = 2'b11;//mem_lw
            end
        end
    end
end
always @ (clr) begin
    if(clr==0) begin
        fwda = 2'b00;
        fwda = 2'b00;
    end
end
assign wreg    = (iadd  | isub   | iaddu  | isubu | iand  | ior    | ixor  | inor  |
                  islt  | isltu  | isll   | isrl  | isra  | isllv  | isrlv | israv |
                  ijalr | iaddi  | iaddiu | iandi | iori  | ixori  | ilui  | ilb   |
                  ilh   | ilw    | ilbu   | ilhu  | islti | isltiu | imfhi | imflo |
                  ijal  | imfc0  | imfhi  | imflo )&clr & nostall & ~ecancel & ~exc_ovr ;
assign regrt   = (iaddi | iaddiu | iandi  | iori  | ixor  | ilw    | ilb   | ilbu  |
                  ilh   | ilhu   | ilui   | islti | isltiu | imfc0 | imtc0 )&clr;
assign jal     = (ijal  | ijalr)&clr;
assign m2reg   = (ilb | ilw  | ilbu   | ilh | ilhu)&clr;
assign shift   = (isll  | isrl   | isra)&clr;
assign aluimm  = (iaddi | iaddiu | iandi | iori | ixori | ilw | ilb | ilbu | ilh |
                  ilhu  | ilui   | isw   | ish  | isb)&clr;
assign sext    = (iaddi | iaddiu | ilw   | ilb  | ilh |isw | ish | isb  | ibeq   |
                  ibne  | ibgez | ibgtz | iblez | ibltz | ibgezal | ibltzal | islti)&clr ;

assign aluc[3] = (ibeq  | ibne  | isub  | isubu | islt | islti | isltu | isltiu | isll | isrl | isra |
                  isllv | isrlv | israv | ibgez | ibgtz | iblez | ibltz | ibgezal | ibltzal)&clr;
assign aluc[2] = (inor  | ixor  | ixori | isll | isrl | isra | isllv | isrlv | israv)&clr;
assign aluc[1] = (ixor  | ixori | iand | iandi | ior | iori | islt | islti | isltu | isltiu |
                  isra  | israv)&clr;
assign aluc[0] = (iaddu | iaddiu | isub | ior | iori | inor | islt | islti | isrl | isrlv |
                  ibgez | ibgtz | iblez | ibltz | ibgezal | ibltzal)&clr;

assign pcsource[1] =( ij | ijr | ijal | ijalr)&clr;
assign pcsource[0] = ((ibeq & rerteqe )| (ibne & rerteqe) | ij | ijal | ijalr)&clr;

assign rmem    = ((ilw | ilb | ilbu  | ilh | ilhu ) & (immehi != 8'hff) & nostall)&clr & ~ecancel;
assign wmem    = ((isw | isb | ish ) & (immehi != 8'hff) & nostall)&clr & ~ecancel & ~exc_ovr;
assign rio     = ((ilw | ilb | ilh | ilhu |ilbu  ) & (immehi == 8'hff) & nostall)&clr & ~ecancel & ~exc_ovr;
assign wio     = ((isw | isb | ish ) & (immehi == 8'hff) & nostall)&clr & ~ecancel & ~exc_ovr;


assign mul_div = idiv | idivu;
assign symbol =  imult | idiv;
assign mul_start = imult | imultu;
assign div_start = idiv | idivu;
assign mthi = imthi;
assign mtlo = imtlo;
assign whi = ;
assign wlo = ;
assign mfhilo[1] = imfhi | imflo; // 00选择原数据，10选择LO,11选择HI
assign mfhilo[0] = imfhi;
assign inop = !inst;
endmodule
