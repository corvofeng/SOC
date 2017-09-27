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
           output [1:0] pcsource
       );
//    output [4:0] rs,rt,rd,shamt;
//	output [5:0] func,op;
wire [15:0] imme;
wire [25:0] addr;
wire  [31:0] qa,qb;
wire [31:0] bpc,bpc0;
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


cpuctr cpuctr0(
           .op(op),
           .rs(rs),
           .rt(rt),
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
           .ilui(ilui)
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
    i_clk(i_clk),
    i_reset(i_reset),

    i_exc(i_exc),
    i_cause(i_cause),
    i_selpc_epc(i_selpc_epc),
    i_pc(i_pc),
    i_dpc(i_dpc),
    i_epc(i_epc),
    i_mpc(i_mpc),

    i_wsta(i_wsta),
    i_wcau(i_wcau),
    i_wepc(i_wepc),

    i_mtc0(i_mtc0),
    i_data(i_data),

    o_status_data(o_status_data),
    o_epc_data(o_epc_data),
    o_cause_data(o_cause_data)
    );
endmodule
