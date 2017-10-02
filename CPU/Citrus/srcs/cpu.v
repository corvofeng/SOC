`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2017/09/24 10:27:23
// Design Name:
// Module Name: cpu
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

module cpu(
      clk,clrn,


      intr,inta,vector,

      LEDCtrl,KEYCtrl,CTCCtrl,PWMCtrl,UARTCtrl,WDTCtrl,
      address,write_data,mread_data,
      ioread_data_key,ioread_data_ctc,ioread_data_uart
    );

    input clk,clrn;
    wire [31:0] npc,pc,bpc,dpc,jpc,pc4,ins,dpc4,inst,wdi,ealu,malu,mmo,da,db,dimm,epc4,ea,eb,eimm,mb,walu,wmo;
    wire [3:0] aluc,ealuc;
    wire [4:0] wrn,mrn,ern,drn,ern0;
    wire [1:0] fwda,fwdb,pcsource;
    wire wpcir,mm2reg,ewreg,wwreg,wreg,m2reg,wmem,jal,aluimm,shift,em2reg,ewmem,ejal,ealuimm,eshift,mwreg,mwmem,wm2reg;
    wire [4:0]rs,rt,rd,shamt;
    wire [5:0]op,func;
    assign dpc = da;

    wire [31:0] pcd,pce,pcm;
    wire [1:0] mfc0,emfc0;
    wire [31:0] sta,cau,epc,esta,ecau,eepc,msta,mcau,mepc,wsta,wcau,wepc;
    wire [1:0] selpc;

    wire ov;
    input intr;
    output inta;
    input[7:0] vector;

    wire cancel,ecancel;
    wire mrmem,mrio,mwio,ermem,erio,ewio,rmem,rio,wio;
    output LEDCtrl,KEYCtrl,CTCCtrl,PWMCtrl,UARTCtrl,WDTCtrl;
    output[11:0] address;
    output[31:0] write_data;
    input [31:0] mread_data;
    input [15:0] ioread_data_key,ioread_data_ctc,ioread_data_uart;

    wire[1:0] mfhilom,emfhilo;
    wire[31:0] HI_data;
    wire[31:0] LO_data;

     pipepc p1(
        .npc(npc),
        .wpc(wpcir),
        .clk(clk),
        .clrn(clrn),
        .pc(pc)
        );
    socpc p2(
        .pc(pc),//pc
        .bpc(bpc),//npc1
        .dpc(dpc),//npc2
        .jpc(jpc),//npc3
        .pcsource(pcsource),//pc��??
        .pc4(pc4),//pc+4
        .ins(ins),//is
        .selpc(selpc),
        .next_pc(npc),//nextpc
        .epc(epc)
        );
     pipeir p3(
         .pc4(pc4),
         .ins(ins),
         .wir(wpcir),
         .clk(clk),
         .clrn(clrn),
         .dpc4(dpc4),
         .inst(inst),
         .pcd(pcd),
         .pc(pc)
         );

     socid p4(
         .dpc4(dpc4),//pc
         .inst(inst),//指令
         .wdi(wdi),//reginput
         .wrn(wrn),//目的寄存��?
         .fwda(fwda),
         .fwdb(fwdb),
         .ealu(ealu),
         .malu(malu),
         .mmo(mmo),
         .mrn(mrn),
         .mm2reg(mm2reg),
         .ern(ern),
         .em2reg(em2reg),
         .ewreg(ewreg),
         .wwreg(wwreg),
         .clk(clk),
         .da(da),//dpc/da
         .db(db),
         .dimm(dimm),
         .drn(drn),
         .wreg(wreg),
         .m2reg(m2reg),
         .wmem(wmem),
         .jal(jal),
         .aluimm(aluimm),
         .shift(shift),
         .aluc(aluc),
         .jpc(jpc),
         .bpc(bpc),
         .nostall(wpcir),
         .clrn(clrn),
         .rs(rs),
         .rt(rt),
         .rd(rd),
         .shamt(shamt),
         .func(func),
         .op(op),
         .pcsource(pcsource),
         .mwreg(mwreg),

         .pc(pc),
         .pcd(pcd),
         .pce(pce),
         .pcm(pcm),
         .sta(sta),
         .epc(epc),
         .cau(cau),
         .selpc(selpc),
         .mfc0(mfc0),
         .ov(ov),
         .intr(intr),
         .inta(inta),
         .vector(vector),

         .cancel(cancel),
         .ecancel(ecancel),

         .rmem(rmem),
         .rio(rio),
         .wio(wio),

         .mfhilo(mfhilo),
         .o_HI_data(o_HI_data),
         .o_LO_data(o_LO_data)

         );

      pipedereg p5(
          .dpc4(dpc4),
          .da(da),
          .db(db),
          .dimm(dimm),
          .drn(drn),
          .wreg(wreg),
          .m2reg(m2reg),
          .wmem(wmem),
          .jal(jal),
          .aluimm(aluimm),
          .shift(shift),
          .aluc(aluc),
          .clk(clk),
          .clrn(clrn),
          .epc4(epc4),
          .ea(ea),
          .eb(eb),
          .eimm(eimm),
          .ern0(ern0),
          .ewreg(ewreg),
          .em2reg(em2reg),
          .ewmem(ewmem),
          .ejal(ejal),
          .ealuimm(ealuimm),
          .eshift(eshift),
          .ealuc(ealuc),
          .pce(pce),
          .pcd(pcd),
          .sta(sta),
          .cau(cau),
          .epc(epc),
          .esta(esta),
          .ecau(ecau),
          .eepc(eepc),
          .mfc0(mfc0),
          .emfc0(emfc0),

          .cancel(cancel),
          .ecancel(ecancel),
          .rmem(rmem),
          .rio(rio),
          .wio(wio),
          .ermem(ermem),
          .erio(erio),
          .ewio(ewio),

          .mfhilo(mfhilo),
          .emfhilo(emfhilo)
         );
     socexe p6(
          .epc4(epc4),
          .ea(ea),
          .eb(eb),
          .eimm(eimm),
          .ern0(ern0),
          .ealuimm(ealuimm),
          .eshift(eshift),
          .ealuc(ealuc),
          .ealu(ealu),
          .ern(ern),
          .ejal(jal),
          .ov(ov),
          .esta(esta),
          .ecau(ecau),
          .eepc(eepc),
          .emfc0(emfc0),

          .emfhilo(emfhilo),
          .HI_data(HI_data),
          .LO_data(LO_data)
          );
    pipeemreg p7(
          .ealu(ealu),
          .eb(eb),
          .ern(ern),
          .ewreg(ewreg),
          .em2reg(em2reg),
          .ewmem(ewmem),
          .clk(clk),
          .clrn(clrn),
          .malu(malu),
          .mb(mb),
          .mrn(mrn),
          .mwreg(mwreg),
          .mm2reg(mm2reg),
          .mwmem(mwmem),
          .pcm(pcm),
          .pce(pce),

          .ermem(ermem),
          .erio(erio),
          .ewio(ewio),
          .mrmem(mrmem),
          .mrio(mrio),
          .mwio(mwio)
          );
      socmem p8(
          .mwmem(mwmem),
          .malu(malu),
          .mb(mb),
          .mmo(mmo),
          .clk(clk),
          .clrn(clrn),
          .mrmem(mrmem),
          .mrio(mrio),
          .mwio(mwio),
          .LEDCtrl(LEDCtrl),
          .KEYCtrl(KEYCtrl),
          .CTCCtrl(CTCCtrl),
          .PWMCtrl(PWMCtrl),
          .UARTCtrl(UARTCtrl),
          .WDTCtrl(WDTCtrl),
          .address(address),
          .write_data(write_data),
          .mread_data(mread_data),
          .ioread_data_key(ioread_data_key),
          .ioread_data_ctc(ioread_data_ctc),
          .ioread_data_uart(ioread_data_uart)
         );
      pipemwreg p9(
          .malu(malu),
          .mmo(mmo),
          .mrn(mrn),
          .mwreg(mwreg),
          .mm2reg(mm2reg),
          .clk(clk),
          .clrn(clrn),
          .walu(walu),
          .wmo(wmo),
          .wrn(wrn),
          .wwreg(wwreg),
          .wm2reg(wm2reg)
           );
       socwb p10(
          .wmo(wmo),//wmo
          .walu(walu),//walu
          .wm2reg(wm2reg),//pc来源
          .wdi(wdi)
       );

endmodule
