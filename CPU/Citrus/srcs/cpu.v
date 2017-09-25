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


//module cpu(
//    clk,
//    clrn
//    );
  module cpu(
      clk,clrn,
      npc,pc,bpc,dpc,jpc,pc4,ins,dpc4,inst,wdi,ealu,malu,mmo,da,db,dimm,epc4,ea,eb,eimm,mb,walu,wmo,
      aluc,ealuc,
      wrn,mrn,ern,drn,ern0,
      pcsource,
      wpcir,fwda,fwdb,mm2reg,ewreg,wwreg,wreg,m2reg,wmem,jal,aluimm,shift,em2reg,ewmem,ejal,ealuimm,eshift,mwreg,mwmem,wm2reg
    );
  
    input clk,clrn;
    input [31:0] npc,pc,bpc,dpc,jpc,pc4,ins,dpc4,inst,wdi,ealu,malu,mmo,da,db,dimm,epc4,ea,eb,eimm,mb,walu,wmo;
    input [5:0] aluc,ealuc;
    input [4:0] wrn,mrn,ern,drn,ern0;
    input [1:0] pcsource;
    input wpcir,fwda,fwdb,mm2reg,ewreg,wwreg,wreg,m2reg,wmem,jal,aluimm,shift,em2reg,ewmem,ejal,ealuimm,eshift,mwreg,mwmem,wm2reg;
 
     pipepc p1(
        .npc(npc),
        .wpc(wpeir),
        .clk(clk),
        .clrn(clrn),
        .pc(pc)
        );
    socpc p2(
        .pc(pc),//pc
        .bpc(bpc),//npc1
        .dpc(dpc),//npc2
        .jpc(jpc),//npc3
        .pcsource(pcsource),//pc婧?
        .pc4(pc4),//pc+4
        .ins(ins),//is
        .npc(npc)//nextpc
        );
     pipeir p3(
         .pc4(pc4),
         .ins(ins),
         .wir(wpcir),
         .clk(clk),
         .clrn(clrn),
         .dpc4(dpc4),
         .inst(inst)
         );
     socid p4(
         .dpc4(dpc4),//pc
         .inst(inst),//指令
         .wdi(wdi),//reginput
         .wrn(wrn),//目的寄存器
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
         .werg(wreg),
         .m2reg(m2reg),
         .wmem(wmem),
         .jal(jal),
         .aluimm(aluimm),
         .shift(shift),
         .aluc(aluc),
         .jpc(jpc),
         .bpc(bpc)
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
          .ealuc(ealuc)
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
          .ern(ern)
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
          .mwmem(mwmem)
          );
      socmem p8(
          .mwmem(mwmem),
          .malu(malu),
          .mb(mb),
          .mmo(mmo),
          .clk(clk)
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
          .wdi(wdi)//wdi
       );

endmodule
