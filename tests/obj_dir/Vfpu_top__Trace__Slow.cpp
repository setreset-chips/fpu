// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfpu_top__Syms.h"


//======================

void Vfpu_top::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vfpu_top::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vfpu_top__Syms* __restrict vlSymsp = static_cast<Vfpu_top__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vfpu_top::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vfpu_top::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vfpu_top__Syms* __restrict vlSymsp = static_cast<Vfpu_top__Syms*>(userp);
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vfpu_top::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vfpu_top__Syms* __restrict vlSymsp = static_cast<Vfpu_top__Syms*>(userp);
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+175,"instruction", false,-1, 31,0);
        tracep->declBit(c+176,"clk", false,-1);
        tracep->declBus(c+177,"fpu_out", false,-1, 31,0);
        tracep->declBus(c+175,"fpu_top instruction", false,-1, 31,0);
        tracep->declBit(c+176,"fpu_top clk", false,-1);
        tracep->declBus(c+177,"fpu_top fpu_out", false,-1, 31,0);
        tracep->declBus(c+1,"fpu_top operand_1", false,-1, 31,0);
        tracep->declBus(c+2,"fpu_top operand_2", false,-1, 31,0);
        tracep->declBus(c+3,"fpu_top operand_3", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+4+i*1,"fpu_top regFile", true,(i+0), 31,0);}}
        tracep->declBus(c+182,"fpu_top fcsr", false,-1, 31,0);
        tracep->declBus(c+178,"fpu_top op1_addr", false,-1, 4,0);
        tracep->declBus(c+179,"fpu_top op2_addr", false,-1, 4,0);
        tracep->declBus(c+180,"fpu_top op3_addr", false,-1, 4,0);
        tracep->declBus(c+36,"fpu_top ins_p1", false,-1, 31,0);
        tracep->declBus(c+37,"fpu_top opcode1", false,-1, 4,0);
        tracep->declBus(c+38,"fpu_top opcode2", false,-1, 4,0);
        tracep->declBus(c+39,"fpu_top opcode3", false,-1, 1,0);
        tracep->declBit(c+40,"fpu_top opcode4", false,-1);
        tracep->declBus(c+41,"fpu_top curr_op", false,-1, 4,0);
        tracep->declBus(c+42,"fpu_top oper1", false,-1, 31,0);
        tracep->declBus(c+43,"fpu_top oper2", false,-1, 31,0);
        tracep->declBus(c+44,"fpu_top oper3", false,-1, 31,0);
        tracep->declBus(c+45,"fpu_top exec_op", false,-1, 4,0);
        tracep->declBus(c+46,"fpu_top ins_p2", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top operand_one", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top operand_two", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top operand_three", false,-1, 31,0);
        tracep->declBus(c+50,"fpu_top result", false,-1, 31,0);
        tracep->declBus(c+51,"fpu_top fma", false,-1, 31,0);
        tracep->declBus(c+52,"fpu_top fms", false,-1, 31,0);
        tracep->declBus(c+53,"fpu_top fnms", false,-1, 31,0);
        tracep->declBus(c+54,"fpu_top fnma", false,-1, 31,0);
        tracep->declBus(c+55,"fpu_top fad", false,-1, 31,0);
        tracep->declBus(c+56,"fpu_top fsu", false,-1, 31,0);
        tracep->declBus(c+57,"fpu_top fmu", false,-1, 31,0);
        tracep->declBus(c+58,"fpu_top fdi", false,-1, 31,0);
        tracep->declBus(c+181,"fpu_top fsq", false,-1, 31,0);
        tracep->declBus(c+59,"fpu_top fsj", false,-1, 31,0);
        tracep->declBus(c+60,"fpu_top fsn", false,-1, 31,0);
        tracep->declBus(c+61,"fpu_top fsx", false,-1, 31,0);
        tracep->declBus(c+62,"fpu_top fmi", false,-1, 31,0);
        tracep->declBus(c+63,"fpu_top fmx", false,-1, 31,0);
        tracep->declBus(c+64,"fpu_top fq", false,-1, 31,0);
        tracep->declBus(c+65,"fpu_top ft", false,-1, 31,0);
        tracep->declBus(c+66,"fpu_top fe", false,-1, 31,0);
        tracep->declBus(c+183,"fpu_top fcls", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top writeback_data", false,-1, 31,0);
        tracep->declBus(c+68,"fpu_top ins_p3", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fmadd1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fmadd1 var2", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fmadd1 var3", false,-1, 31,0);
        tracep->declBus(c+51,"fpu_top fmadd1 res", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fmadd1 in1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fmadd1 in2", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fmadd1 in3", false,-1, 31,0);
        tracep->declBus(c+69,"fpu_top fmadd1 out", false,-1, 31,0);
        tracep->declBus(c+51,"fpu_top fmadd1 out2", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fmadd1 fmul1 num1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fmadd1 fmul1 num2", false,-1, 31,0);
        tracep->declBus(c+69,"fpu_top fmadd1 fmul1 out_mul", false,-1, 31,0);
        tracep->declBit(c+70,"fpu_top fmadd1 fmul1 sign", false,-1);
        tracep->declBus(c+71,"fpu_top fmadd1 fmul1 expF", false,-1, 7,0);
        tracep->declBus(c+72,"fpu_top fmadd1 fmul1 mantissa", false,-1, 23,0);
        tracep->declBus(c+73,"fpu_top fmadd1 fmul1 mantissa1", false,-1, 23,0);
        tracep->declBus(c+74,"fpu_top fmadd1 fmul1 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+75,"fpu_top fmadd1 fmul1 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+184,"fpu_top fmadd1 fmul1 i", false,-1, 31,0);
        tracep->declBus(c+69,"fpu_top fmadd1 fadd1 num1", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fmadd1 fadd1 num2", false,-1, 31,0);
        tracep->declBus(c+51,"fpu_top fmadd1 fadd1 out_num", false,-1, 31,0);
        tracep->declBit(c+77,"fpu_top fmadd1 fadd1 largerMag", false,-1);
        tracep->declBit(c+78,"fpu_top fmadd1 fadd1 finalSign", false,-1);
        tracep->declBus(c+79,"fpu_top fmadd1 fadd1 num1Exp", false,-1, 7,0);
        tracep->declBus(c+80,"fpu_top fmadd1 fadd1 num2Exp", false,-1, 7,0);
        tracep->declBus(c+81,"fpu_top fmadd1 fadd1 finalExp", false,-1, 7,0);
        tracep->declBus(c+82,"fpu_top fmadd1 fadd1 num1Mant", false,-1, 23,0);
        tracep->declBus(c+83,"fpu_top fmadd1 fadd1 num2Mant", false,-1, 23,0);
        tracep->declBus(c+84,"fpu_top fmadd1 fadd1 finalMant", false,-1, 23,0);
        tracep->declBus(c+85,"fpu_top fmadd1 fadd1 sumMants", false,-1, 24,0);
        tracep->declBus(c+185,"fpu_top fmadd1 fadd1 i", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fmsub1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fmsub1 var2", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fmsub1 var3", false,-1, 31,0);
        tracep->declBus(c+52,"fpu_top fmsub1 res", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fmsub1 in1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fmsub1 in2", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fmsub1 in3", false,-1, 31,0);
        tracep->declBus(c+86,"fpu_top fmsub1 out", false,-1, 31,0);
        tracep->declBus(c+52,"fpu_top fmsub1 out2", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fmsub1 f1 num1", false,-1, 31,0);
        tracep->declBus(c+87,"fpu_top fmsub1 f1 num2", false,-1, 31,0);
        tracep->declBus(c+86,"fpu_top fmsub1 f1 out_num", false,-1, 31,0);
        tracep->declBit(c+88,"fpu_top fmsub1 f1 largerMag", false,-1);
        tracep->declBit(c+89,"fpu_top fmsub1 f1 finalSign", false,-1);
        tracep->declBus(c+90,"fpu_top fmsub1 f1 num1Exp", false,-1, 7,0);
        tracep->declBus(c+91,"fpu_top fmsub1 f1 num2Exp", false,-1, 7,0);
        tracep->declBus(c+92,"fpu_top fmsub1 f1 finalExp", false,-1, 7,0);
        tracep->declBus(c+93,"fpu_top fmsub1 f1 num1Mant", false,-1, 23,0);
        tracep->declBus(c+94,"fpu_top fmsub1 f1 num2Mant", false,-1, 23,0);
        tracep->declBus(c+95,"fpu_top fmsub1 f1 finalMant", false,-1, 23,0);
        tracep->declBus(c+96,"fpu_top fmsub1 f1 sumMants", false,-1, 24,0);
        tracep->declBus(c+186,"fpu_top fmsub1 f1 i", false,-1, 31,0);
        tracep->declBus(c+86,"fpu_top fmsub1 fmul1 num1", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fmsub1 fmul1 num2", false,-1, 31,0);
        tracep->declBus(c+52,"fpu_top fmsub1 fmul1 out_mul", false,-1, 31,0);
        tracep->declBit(c+97,"fpu_top fmsub1 fmul1 sign", false,-1);
        tracep->declBus(c+98,"fpu_top fmsub1 fmul1 expF", false,-1, 7,0);
        tracep->declBus(c+99,"fpu_top fmsub1 fmul1 mantissa", false,-1, 23,0);
        tracep->declBus(c+100,"fpu_top fmsub1 fmul1 mantissa1", false,-1, 23,0);
        tracep->declBus(c+101,"fpu_top fmsub1 fmul1 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+102,"fpu_top fmsub1 fmul1 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+184,"fpu_top fmsub1 fmul1 i", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fnmsub1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fnmsub1 var2", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fnmsub1 var3", false,-1, 31,0);
        tracep->declBus(c+53,"fpu_top fnmsub1 res", false,-1, 31,0);
        tracep->declBus(c+104,"fpu_top fnmsub1 in1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fnmsub1 in2", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fnmsub1 in3", false,-1, 31,0);
        tracep->declBus(c+105,"fpu_top fnmsub1 out", false,-1, 31,0);
        tracep->declBus(c+53,"fpu_top fnmsub1 out2", false,-1, 31,0);
        tracep->declBus(c+104,"fpu_top fnmsub1 fmul1 num1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fnmsub1 fmul1 num2", false,-1, 31,0);
        tracep->declBus(c+105,"fpu_top fnmsub1 fmul1 out_mul", false,-1, 31,0);
        tracep->declBit(c+106,"fpu_top fnmsub1 fmul1 sign", false,-1);
        tracep->declBus(c+107,"fpu_top fnmsub1 fmul1 expF", false,-1, 7,0);
        tracep->declBus(c+108,"fpu_top fnmsub1 fmul1 mantissa", false,-1, 23,0);
        tracep->declBus(c+109,"fpu_top fnmsub1 fmul1 mantissa1", false,-1, 23,0);
        tracep->declBus(c+74,"fpu_top fnmsub1 fmul1 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+110,"fpu_top fnmsub1 fmul1 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+184,"fpu_top fnmsub1 fmul1 i", false,-1, 31,0);
        tracep->declBus(c+104,"fpu_top fnmsub1 fsub1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fnmsub1 fsub1 var2", false,-1, 31,0);
        tracep->declBus(c+53,"fpu_top fnmsub1 fsub1 res", false,-1, 31,0);
        tracep->declBus(c+104,"fpu_top fnmsub1 fsub1 f1 num1", false,-1, 31,0);
        tracep->declBus(c+87,"fpu_top fnmsub1 fsub1 f1 num2", false,-1, 31,0);
        tracep->declBus(c+53,"fpu_top fnmsub1 fsub1 f1 out_num", false,-1, 31,0);
        tracep->declBit(c+112,"fpu_top fnmsub1 fsub1 f1 largerMag", false,-1);
        tracep->declBit(c+113,"fpu_top fnmsub1 fsub1 f1 finalSign", false,-1);
        tracep->declBus(c+114,"fpu_top fnmsub1 fsub1 f1 num1Exp", false,-1, 7,0);
        tracep->declBus(c+115,"fpu_top fnmsub1 fsub1 f1 num2Exp", false,-1, 7,0);
        tracep->declBus(c+116,"fpu_top fnmsub1 fsub1 f1 finalExp", false,-1, 7,0);
        tracep->declBus(c+117,"fpu_top fnmsub1 fsub1 f1 num1Mant", false,-1, 23,0);
        tracep->declBus(c+118,"fpu_top fnmsub1 fsub1 f1 num2Mant", false,-1, 23,0);
        tracep->declBus(c+119,"fpu_top fnmsub1 fsub1 f1 finalMant", false,-1, 23,0);
        tracep->declBus(c+120,"fpu_top fnmsub1 fsub1 f1 sumMants", false,-1, 24,0);
        tracep->declBus(c+187,"fpu_top fnmsub1 fsub1 f1 i", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fnmadd1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fnmadd1 var2", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fnmadd1 var3", false,-1, 31,0);
        tracep->declBus(c+54,"fpu_top fnmadd1 res", false,-1, 31,0);
        tracep->declBus(c+104,"fpu_top fnmadd1 in1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fnmadd1 in2", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fnmadd1 in3", false,-1, 31,0);
        tracep->declBus(c+121,"fpu_top fnmadd1 out", false,-1, 31,0);
        tracep->declBus(c+54,"fpu_top fnmadd1 out2", false,-1, 31,0);
        tracep->declBus(c+104,"fpu_top fnmadd1 fmul1 num1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fnmadd1 fmul1 num2", false,-1, 31,0);
        tracep->declBus(c+121,"fpu_top fnmadd1 fmul1 out_mul", false,-1, 31,0);
        tracep->declBit(c+106,"fpu_top fnmadd1 fmul1 sign", false,-1);
        tracep->declBus(c+122,"fpu_top fnmadd1 fmul1 expF", false,-1, 7,0);
        tracep->declBus(c+123,"fpu_top fnmadd1 fmul1 mantissa", false,-1, 23,0);
        tracep->declBus(c+109,"fpu_top fnmadd1 fmul1 mantissa1", false,-1, 23,0);
        tracep->declBus(c+74,"fpu_top fnmadd1 fmul1 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+124,"fpu_top fnmadd1 fmul1 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+184,"fpu_top fnmadd1 fmul1 i", false,-1, 31,0);
        tracep->declBus(c+121,"fpu_top fnmadd1 fadd1 num1", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fnmadd1 fadd1 num2", false,-1, 31,0);
        tracep->declBus(c+54,"fpu_top fnmadd1 fadd1 out_num", false,-1, 31,0);
        tracep->declBit(c+126,"fpu_top fnmadd1 fadd1 largerMag", false,-1);
        tracep->declBit(c+127,"fpu_top fnmadd1 fadd1 finalSign", false,-1);
        tracep->declBus(c+128,"fpu_top fnmadd1 fadd1 num1Exp", false,-1, 7,0);
        tracep->declBus(c+129,"fpu_top fnmadd1 fadd1 num2Exp", false,-1, 7,0);
        tracep->declBus(c+130,"fpu_top fnmadd1 fadd1 finalExp", false,-1, 7,0);
        tracep->declBus(c+131,"fpu_top fnmadd1 fadd1 num1Mant", false,-1, 23,0);
        tracep->declBus(c+132,"fpu_top fnmadd1 fadd1 num2Mant", false,-1, 23,0);
        tracep->declBus(c+133,"fpu_top fnmadd1 fadd1 finalMant", false,-1, 23,0);
        tracep->declBus(c+134,"fpu_top fnmadd1 fadd1 sumMants", false,-1, 24,0);
        tracep->declBus(c+188,"fpu_top fnmadd1 fadd1 i", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fadd1 num1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fadd1 num2", false,-1, 31,0);
        tracep->declBus(c+55,"fpu_top fadd1 out_num", false,-1, 31,0);
        tracep->declBit(c+135,"fpu_top fadd1 largerMag", false,-1);
        tracep->declBit(c+136,"fpu_top fadd1 finalSign", false,-1);
        tracep->declBus(c+137,"fpu_top fadd1 num1Exp", false,-1, 7,0);
        tracep->declBus(c+138,"fpu_top fadd1 num2Exp", false,-1, 7,0);
        tracep->declBus(c+139,"fpu_top fadd1 finalExp", false,-1, 7,0);
        tracep->declBus(c+140,"fpu_top fadd1 num1Mant", false,-1, 23,0);
        tracep->declBus(c+141,"fpu_top fadd1 num2Mant", false,-1, 23,0);
        tracep->declBus(c+142,"fpu_top fadd1 finalMant", false,-1, 23,0);
        tracep->declBus(c+143,"fpu_top fadd1 sumMants", false,-1, 24,0);
        tracep->declBus(c+189,"fpu_top fadd1 i", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fsub1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fsub1 var2", false,-1, 31,0);
        tracep->declBus(c+56,"fpu_top fsub1 res", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fsub1 f1 num1", false,-1, 31,0);
        tracep->declBus(c+87,"fpu_top fsub1 f1 num2", false,-1, 31,0);
        tracep->declBus(c+56,"fpu_top fsub1 f1 out_num", false,-1, 31,0);
        tracep->declBit(c+144,"fpu_top fsub1 f1 largerMag", false,-1);
        tracep->declBit(c+145,"fpu_top fsub1 f1 finalSign", false,-1);
        tracep->declBus(c+146,"fpu_top fsub1 f1 num1Exp", false,-1, 7,0);
        tracep->declBus(c+147,"fpu_top fsub1 f1 num2Exp", false,-1, 7,0);
        tracep->declBus(c+148,"fpu_top fsub1 f1 finalExp", false,-1, 7,0);
        tracep->declBus(c+149,"fpu_top fsub1 f1 num1Mant", false,-1, 23,0);
        tracep->declBus(c+150,"fpu_top fsub1 f1 num2Mant", false,-1, 23,0);
        tracep->declBus(c+151,"fpu_top fsub1 f1 finalMant", false,-1, 23,0);
        tracep->declBus(c+152,"fpu_top fsub1 f1 sumMants", false,-1, 24,0);
        tracep->declBus(c+190,"fpu_top fsub1 f1 i", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fmul1 num1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fmul1 num2", false,-1, 31,0);
        tracep->declBus(c+57,"fpu_top fmul1 out_mul", false,-1, 31,0);
        tracep->declBit(c+70,"fpu_top fmul1 sign", false,-1);
        tracep->declBus(c+153,"fpu_top fmul1 expF", false,-1, 7,0);
        tracep->declBus(c+154,"fpu_top fmul1 mantissa", false,-1, 23,0);
        tracep->declBus(c+73,"fpu_top fmul1 mantissa1", false,-1, 23,0);
        tracep->declBus(c+74,"fpu_top fmul1 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+155,"fpu_top fmul1 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+184,"fpu_top fmul1 i", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fdiv1 divisor", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fdiv1 dividend", false,-1, 31,0);
        tracep->declBus(c+58,"fpu_top fdiv1 div_out", false,-1, 31,0);
        tracep->declBus(c+157,"fpu_top fdiv1 temp_out", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fdiv1 fi0 num1", false,-1, 31,0);
        tracep->declBus(c+157,"fpu_top fdiv1 fi0 num_out", false,-1, 31,0);
        tracep->declBus(c+191,"fpu_top fdiv1 fi0 magic_number", false,-1, 31,0);
        tracep->declBus(c+158,"fpu_top fdiv1 fi0 temp_out", false,-1, 31,0);
        tracep->declBus(c+158,"fpu_top fdiv1 fi0 f1 num1", false,-1, 31,0);
        tracep->declBus(c+158,"fpu_top fdiv1 fi0 f1 num2", false,-1, 31,0);
        tracep->declBus(c+157,"fpu_top fdiv1 fi0 f1 out_mul", false,-1, 31,0);
        tracep->declBit(c+159,"fpu_top fdiv1 fi0 f1 sign", false,-1);
        tracep->declBus(c+160,"fpu_top fdiv1 fi0 f1 expF", false,-1, 7,0);
        tracep->declBus(c+161,"fpu_top fdiv1 fi0 f1 mantissa", false,-1, 23,0);
        tracep->declBus(c+162,"fpu_top fdiv1 fi0 f1 mantissa1", false,-1, 23,0);
        tracep->declBus(c+162,"fpu_top fdiv1 fi0 f1 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+163,"fpu_top fdiv1 fi0 f1 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+184,"fpu_top fdiv1 fi0 f1 i", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fdiv1 fm0 num1", false,-1, 31,0);
        tracep->declBus(c+157,"fpu_top fdiv1 fm0 num2", false,-1, 31,0);
        tracep->declBus(c+58,"fpu_top fdiv1 fm0 out_mul", false,-1, 31,0);
        tracep->declBit(c+165,"fpu_top fdiv1 fm0 sign", false,-1);
        tracep->declBus(c+166,"fpu_top fdiv1 fm0 expF", false,-1, 7,0);
        tracep->declBus(c+167,"fpu_top fdiv1 fm0 mantissa", false,-1, 23,0);
        tracep->declBus(c+73,"fpu_top fdiv1 fm0 mantissa1", false,-1, 23,0);
        tracep->declBus(c+168,"fpu_top fdiv1 fm0 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+169,"fpu_top fdiv1 fm0 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+184,"fpu_top fdiv1 fm0 i", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fsqrt1 var1", false,-1, 31,0);
        tracep->declBus(c+181,"fpu_top fsqrt1 res", false,-1, 31,0);
        tracep->declBus(c+181,"fpu_top fsqrt1 shifted_num", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fsgnj1 val1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fsgnj1 val2", false,-1, 31,0);
        tracep->declBus(c+59,"fpu_top fsgnj1 out_val", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fsgnjn1 val1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fsgnjn1 val2", false,-1, 31,0);
        tracep->declBus(c+60,"fpu_top fsgnjn1 out_val", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fsgnjx1 val1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fsgnjx1 val2", false,-1, 31,0);
        tracep->declBus(c+61,"fpu_top fsgnjx1 out_val", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fmin1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fmin1 var2", false,-1, 31,0);
        tracep->declBus(c+62,"fpu_top fmin1 res", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fmin1 in1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fmin1 in2", false,-1, 31,0);
        tracep->declBus(c+62,"fpu_top fmin1 out", false,-1, 31,0);
        tracep->declBus(c+171,"fpu_top fmin1 exp1", false,-1, 7,0);
        tracep->declBus(c+172,"fpu_top fmin1 exp2", false,-1, 7,0);
        tracep->declBus(c+173,"fpu_top fmin1 mantissa1", false,-1, 22,0);
        tracep->declBus(c+174,"fpu_top fmin1 mantissa2", false,-1, 22,0);
        tracep->declBus(c+47,"fpu_top fmax1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fmax1 var2", false,-1, 31,0);
        tracep->declBus(c+63,"fpu_top fmax1 res", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fmax1 in1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fmax1 in2", false,-1, 31,0);
        tracep->declBus(c+63,"fpu_top fmax1 out", false,-1, 31,0);
        tracep->declBus(c+171,"fpu_top fmax1 exp1", false,-1, 7,0);
        tracep->declBus(c+172,"fpu_top fmax1 exp2", false,-1, 7,0);
        tracep->declBus(c+173,"fpu_top fmax1 mantissa1", false,-1, 22,0);
        tracep->declBus(c+174,"fpu_top fmax1 mantissa2", false,-1, 22,0);
        tracep->declBus(c+47,"fpu_top feq1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top feq1 var2", false,-1, 31,0);
        tracep->declBus(c+64,"fpu_top feq1 res", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top flt1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top flt1 var2", false,-1, 31,0);
        tracep->declBus(c+65,"fpu_top flt1 res", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top flt1 in1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top flt1 in2", false,-1, 31,0);
        tracep->declBus(c+65,"fpu_top flt1 out", false,-1, 31,0);
        tracep->declBus(c+171,"fpu_top flt1 exp1", false,-1, 7,0);
        tracep->declBus(c+172,"fpu_top flt1 exp2", false,-1, 7,0);
        tracep->declBus(c+173,"fpu_top flt1 mantissa1", false,-1, 22,0);
        tracep->declBus(c+174,"fpu_top flt1 mantissa2", false,-1, 22,0);
        tracep->declBus(c+47,"fpu_top fle1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fle1 var2", false,-1, 31,0);
        tracep->declBus(c+66,"fpu_top fle1 res", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fle1 in1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fle1 in2", false,-1, 31,0);
        tracep->declBus(c+66,"fpu_top fle1 out", false,-1, 31,0);
        tracep->declBus(c+171,"fpu_top fle1 exp1", false,-1, 7,0);
        tracep->declBus(c+172,"fpu_top fle1 exp2", false,-1, 7,0);
        tracep->declBus(c+173,"fpu_top fle1 mantissa1", false,-1, 22,0);
        tracep->declBus(c+174,"fpu_top fle1 mantissa2", false,-1, 22,0);
        tracep->declBus(c+47,"fpu_top fclass1 val1", false,-1, 31,0);
        tracep->declBus(c+183,"fpu_top fclass1 out_val", false,-1, 31,0);
        tracep->declBus(c+183,"fpu_top fclass1 result", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fclass1 in1", false,-1, 31,0);
    }
}

void Vfpu_top::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vfpu_top::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vfpu_top__Syms* __restrict vlSymsp = static_cast<Vfpu_top__Syms*>(userp);
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vfpu_top::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vfpu_top__Syms* __restrict vlSymsp = static_cast<Vfpu_top__Syms*>(userp);
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->fpu_top__DOT__operand_1),32);
        tracep->fullIData(oldp+2,(vlTOPp->fpu_top__DOT__operand_2),32);
        tracep->fullIData(oldp+3,(vlTOPp->fpu_top__DOT__operand_3),32);
        tracep->fullIData(oldp+4,(vlTOPp->fpu_top__DOT__regFile[0]),32);
        tracep->fullIData(oldp+5,(vlTOPp->fpu_top__DOT__regFile[1]),32);
        tracep->fullIData(oldp+6,(vlTOPp->fpu_top__DOT__regFile[2]),32);
        tracep->fullIData(oldp+7,(vlTOPp->fpu_top__DOT__regFile[3]),32);
        tracep->fullIData(oldp+8,(vlTOPp->fpu_top__DOT__regFile[4]),32);
        tracep->fullIData(oldp+9,(vlTOPp->fpu_top__DOT__regFile[5]),32);
        tracep->fullIData(oldp+10,(vlTOPp->fpu_top__DOT__regFile[6]),32);
        tracep->fullIData(oldp+11,(vlTOPp->fpu_top__DOT__regFile[7]),32);
        tracep->fullIData(oldp+12,(vlTOPp->fpu_top__DOT__regFile[8]),32);
        tracep->fullIData(oldp+13,(vlTOPp->fpu_top__DOT__regFile[9]),32);
        tracep->fullIData(oldp+14,(vlTOPp->fpu_top__DOT__regFile[10]),32);
        tracep->fullIData(oldp+15,(vlTOPp->fpu_top__DOT__regFile[11]),32);
        tracep->fullIData(oldp+16,(vlTOPp->fpu_top__DOT__regFile[12]),32);
        tracep->fullIData(oldp+17,(vlTOPp->fpu_top__DOT__regFile[13]),32);
        tracep->fullIData(oldp+18,(vlTOPp->fpu_top__DOT__regFile[14]),32);
        tracep->fullIData(oldp+19,(vlTOPp->fpu_top__DOT__regFile[15]),32);
        tracep->fullIData(oldp+20,(vlTOPp->fpu_top__DOT__regFile[16]),32);
        tracep->fullIData(oldp+21,(vlTOPp->fpu_top__DOT__regFile[17]),32);
        tracep->fullIData(oldp+22,(vlTOPp->fpu_top__DOT__regFile[18]),32);
        tracep->fullIData(oldp+23,(vlTOPp->fpu_top__DOT__regFile[19]),32);
        tracep->fullIData(oldp+24,(vlTOPp->fpu_top__DOT__regFile[20]),32);
        tracep->fullIData(oldp+25,(vlTOPp->fpu_top__DOT__regFile[21]),32);
        tracep->fullIData(oldp+26,(vlTOPp->fpu_top__DOT__regFile[22]),32);
        tracep->fullIData(oldp+27,(vlTOPp->fpu_top__DOT__regFile[23]),32);
        tracep->fullIData(oldp+28,(vlTOPp->fpu_top__DOT__regFile[24]),32);
        tracep->fullIData(oldp+29,(vlTOPp->fpu_top__DOT__regFile[25]),32);
        tracep->fullIData(oldp+30,(vlTOPp->fpu_top__DOT__regFile[26]),32);
        tracep->fullIData(oldp+31,(vlTOPp->fpu_top__DOT__regFile[27]),32);
        tracep->fullIData(oldp+32,(vlTOPp->fpu_top__DOT__regFile[28]),32);
        tracep->fullIData(oldp+33,(vlTOPp->fpu_top__DOT__regFile[29]),32);
        tracep->fullIData(oldp+34,(vlTOPp->fpu_top__DOT__regFile[30]),32);
        tracep->fullIData(oldp+35,(vlTOPp->fpu_top__DOT__regFile[31]),32);
        tracep->fullIData(oldp+36,(vlTOPp->fpu_top__DOT__ins_p1),32);
        tracep->fullCData(oldp+37,((0x1fU & (vlTOPp->fpu_top__DOT__ins_p1 
                                             >> 2U))),5);
        tracep->fullCData(oldp+38,((0x1fU & (vlTOPp->fpu_top__DOT__ins_p1 
                                             >> 0x1bU))),5);
        tracep->fullCData(oldp+39,((3U & (vlTOPp->fpu_top__DOT__ins_p1 
                                          >> 0xcU))),2);
        tracep->fullBit(oldp+40,((1U & (vlTOPp->fpu_top__DOT__ins_p1 
                                        >> 0x14U))));
        tracep->fullCData(oldp+41,(vlTOPp->fpu_top__DOT__curr_op),5);
        tracep->fullIData(oldp+42,(vlTOPp->fpu_top__DOT__oper1),32);
        tracep->fullIData(oldp+43,(vlTOPp->fpu_top__DOT__oper2),32);
        tracep->fullIData(oldp+44,(vlTOPp->fpu_top__DOT__oper3),32);
        tracep->fullCData(oldp+45,(vlTOPp->fpu_top__DOT__exec_op),5);
        tracep->fullIData(oldp+46,(vlTOPp->fpu_top__DOT__ins_p2),32);
        tracep->fullIData(oldp+47,(vlTOPp->fpu_top__DOT__operand_one),32);
        tracep->fullIData(oldp+48,(vlTOPp->fpu_top__DOT__operand_two),32);
        tracep->fullIData(oldp+49,(vlTOPp->fpu_top__DOT__operand_three),32);
        tracep->fullIData(oldp+50,(vlTOPp->fpu_top__DOT__result),32);
        tracep->fullIData(oldp+51,(((0x80000000U & 
                                     ((~ (IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalSign)) 
                                      << 0x1fU)) | 
                                    (((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                      << 0x17U) | (0x7fffffU 
                                                   & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                      >> 1U))))),32);
        tracep->fullIData(oldp+52,(vlTOPp->fpu_top__DOT__fmsub1__DOT__out2),32);
        tracep->fullIData(oldp+53,(((0x80000000U & 
                                     ((~ (IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalSign)) 
                                      << 0x1fU)) | 
                                    (((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                      << 0x17U) | (0x7fffffU 
                                                   & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                      >> 1U))))),32);
        tracep->fullIData(oldp+54,(((0x80000000U & 
                                     ((~ (IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalSign)) 
                                      << 0x1fU)) | 
                                    (((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                      << 0x17U) | (0x7fffffU 
                                                   & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                      >> 1U))))),32);
        tracep->fullIData(oldp+55,(((0x80000000U & 
                                     ((~ (IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalSign)) 
                                      << 0x1fU)) | 
                                    (((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                      << 0x17U) | (0x7fffffU 
                                                   & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                      >> 1U))))),32);
        tracep->fullIData(oldp+56,(((0x80000000U & 
                                     ((~ (IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalSign)) 
                                      << 0x1fU)) | 
                                    (((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                      << 0x17U) | (0x7fffffU 
                                                   & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                      >> 1U))))),32);
        tracep->fullIData(oldp+57,(vlTOPp->fpu_top__DOT__fmu),32);
        tracep->fullIData(oldp+58,(vlTOPp->fpu_top__DOT__fdi),32);
        tracep->fullIData(oldp+59,(((0x80000000U & vlTOPp->fpu_top__DOT__operand_two) 
                                    | (0x7fffffffU 
                                       & vlTOPp->fpu_top__DOT__operand_one))),32);
        tracep->fullIData(oldp+60,(((0x80000000U & 
                                     ((~ (vlTOPp->fpu_top__DOT__operand_two 
                                          >> 0x1fU)) 
                                      << 0x1fU)) | 
                                    (0x7fffffffU & vlTOPp->fpu_top__DOT__operand_one))),32);
        tracep->fullIData(oldp+61,(((0x80000000U & 
                                     (vlTOPp->fpu_top__DOT__operand_two 
                                      ^ vlTOPp->fpu_top__DOT__operand_one)) 
                                    | (0x7fffffffU 
                                       & vlTOPp->fpu_top__DOT__operand_one))),32);
        tracep->fullIData(oldp+62,(vlTOPp->fpu_top__DOT__fmin1__DOT__out),32);
        tracep->fullIData(oldp+63,(vlTOPp->fpu_top__DOT__fmax1__DOT__out),32);
        tracep->fullIData(oldp+64,(((vlTOPp->fpu_top__DOT__operand_one 
                                     == vlTOPp->fpu_top__DOT__operand_two)
                                     ? 1U : 0U)),32);
        tracep->fullIData(oldp+65,(vlTOPp->fpu_top__DOT__flt1__DOT__out),32);
        tracep->fullIData(oldp+66,(vlTOPp->fpu_top__DOT__fle1__DOT__out),32);
        tracep->fullIData(oldp+67,(vlTOPp->fpu_top__DOT__writeback_data),32);
        tracep->fullIData(oldp+68,(vlTOPp->fpu_top__DOT__ins_p3),32);
        tracep->fullIData(oldp+69,(vlTOPp->fpu_top__DOT__fmadd1__DOT__out),32);
        tracep->fullBit(oldp+70,((1U & ((vlTOPp->fpu_top__DOT__operand_one 
                                         ^ vlTOPp->fpu_top__DOT__operand_two) 
                                        >> 0x1fU))));
        tracep->fullCData(oldp+71,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fmul1__DOT__expF),8);
        tracep->fullIData(oldp+72,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fmul1__DOT__mantissa),24);
        tracep->fullIData(oldp+73,(((0U == vlTOPp->fpu_top__DOT__operand_one)
                                     ? 0U : (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->fpu_top__DOT__operand_one)))),24);
        tracep->fullIData(oldp+74,(((0U == vlTOPp->fpu_top__DOT__operand_two)
                                     ? 0U : (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->fpu_top__DOT__operand_two)))),24);
        tracep->fullQData(oldp+75,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fmul1__DOT__mantissaProd),48);
        tracep->fullBit(oldp+77,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__largerMag));
        tracep->fullBit(oldp+78,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalSign));
        tracep->fullCData(oldp+79,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Exp),8);
        tracep->fullCData(oldp+80,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Exp),8);
        tracep->fullCData(oldp+81,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp),8);
        tracep->fullIData(oldp+82,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Mant),24);
        tracep->fullIData(oldp+83,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Mant),24);
        tracep->fullIData(oldp+84,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant),24);
        tracep->fullIData(oldp+85,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__sumMants),25);
        tracep->fullIData(oldp+86,(vlTOPp->fpu_top__DOT__fmsub1__DOT__out),32);
        tracep->fullIData(oldp+87,(vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2),32);
        tracep->fullBit(oldp+88,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__largerMag));
        tracep->fullBit(oldp+89,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalSign));
        tracep->fullCData(oldp+90,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Exp),8);
        tracep->fullCData(oldp+91,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Exp),8);
        tracep->fullCData(oldp+92,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp),8);
        tracep->fullIData(oldp+93,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Mant),24);
        tracep->fullIData(oldp+94,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Mant),24);
        tracep->fullIData(oldp+95,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant),24);
        tracep->fullIData(oldp+96,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__sumMants),25);
        tracep->fullBit(oldp+97,((1U & ((vlTOPp->fpu_top__DOT__fmsub1__DOT__out 
                                         ^ vlTOPp->fpu_top__DOT__operand_three) 
                                        >> 0x1fU))));
        tracep->fullCData(oldp+98,(vlTOPp->fpu_top__DOT__fmsub1__DOT__fmul1__DOT__expF),8);
        tracep->fullIData(oldp+99,(vlTOPp->fpu_top__DOT__fmsub1__DOT__fmul1__DOT__mantissa),24);
        tracep->fullIData(oldp+100,(((0U == vlTOPp->fpu_top__DOT__fmsub1__DOT__out)
                                      ? 0U : (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->fpu_top__DOT__fmsub1__DOT__out)))),24);
        tracep->fullIData(oldp+101,(((0U == vlTOPp->fpu_top__DOT__operand_three)
                                      ? 0U : (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->fpu_top__DOT__operand_three)))),24);
        tracep->fullQData(oldp+102,(vlTOPp->fpu_top__DOT__fmsub1__DOT__fmul1__DOT__mantissaProd),48);
        tracep->fullIData(oldp+104,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1),32);
        tracep->fullIData(oldp+105,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__out),32);
        tracep->fullBit(oldp+106,((1U & ((vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1 
                                          ^ vlTOPp->fpu_top__DOT__operand_two) 
                                         >> 0x1fU))));
        tracep->fullCData(oldp+107,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fmul1__DOT__expF),8);
        tracep->fullIData(oldp+108,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fmul1__DOT__mantissa),24);
        tracep->fullIData(oldp+109,(((0U == vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1)
                                      ? 0U : (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1)))),24);
        tracep->fullQData(oldp+110,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fmul1__DOT__mantissaProd),48);
        tracep->fullBit(oldp+112,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__largerMag));
        tracep->fullBit(oldp+113,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalSign));
        tracep->fullCData(oldp+114,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Exp),8);
        tracep->fullCData(oldp+115,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Exp),8);
        tracep->fullCData(oldp+116,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp),8);
        tracep->fullIData(oldp+117,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Mant),24);
        tracep->fullIData(oldp+118,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Mant),24);
        tracep->fullIData(oldp+119,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant),24);
        tracep->fullIData(oldp+120,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__sumMants),25);
        tracep->fullIData(oldp+121,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__out),32);
        tracep->fullCData(oldp+122,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fmul1__DOT__expF),8);
        tracep->fullIData(oldp+123,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fmul1__DOT__mantissa),24);
        tracep->fullQData(oldp+124,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fmul1__DOT__mantissaProd),48);
        tracep->fullBit(oldp+126,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__largerMag));
        tracep->fullBit(oldp+127,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalSign));
        tracep->fullCData(oldp+128,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Exp),8);
        tracep->fullCData(oldp+129,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Exp),8);
        tracep->fullCData(oldp+130,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp),8);
        tracep->fullIData(oldp+131,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Mant),24);
        tracep->fullIData(oldp+132,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Mant),24);
        tracep->fullIData(oldp+133,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant),24);
        tracep->fullIData(oldp+134,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__sumMants),25);
        tracep->fullBit(oldp+135,(vlTOPp->fpu_top__DOT__fadd1__DOT__largerMag));
        tracep->fullBit(oldp+136,(vlTOPp->fpu_top__DOT__fadd1__DOT__finalSign));
        tracep->fullCData(oldp+137,(vlTOPp->fpu_top__DOT__fadd1__DOT__num1Exp),8);
        tracep->fullCData(oldp+138,(vlTOPp->fpu_top__DOT__fadd1__DOT__num2Exp),8);
        tracep->fullCData(oldp+139,(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp),8);
        tracep->fullIData(oldp+140,(vlTOPp->fpu_top__DOT__fadd1__DOT__num1Mant),24);
        tracep->fullIData(oldp+141,(vlTOPp->fpu_top__DOT__fadd1__DOT__num2Mant),24);
        tracep->fullIData(oldp+142,(vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant),24);
        tracep->fullIData(oldp+143,(vlTOPp->fpu_top__DOT__fadd1__DOT__sumMants),25);
        tracep->fullBit(oldp+144,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__largerMag));
        tracep->fullBit(oldp+145,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalSign));
        tracep->fullCData(oldp+146,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Exp),8);
        tracep->fullCData(oldp+147,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Exp),8);
        tracep->fullCData(oldp+148,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp),8);
        tracep->fullIData(oldp+149,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Mant),24);
        tracep->fullIData(oldp+150,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Mant),24);
        tracep->fullIData(oldp+151,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant),24);
        tracep->fullIData(oldp+152,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__sumMants),25);
        tracep->fullCData(oldp+153,(vlTOPp->fpu_top__DOT__fmul1__DOT__expF),8);
        tracep->fullIData(oldp+154,(vlTOPp->fpu_top__DOT__fmul1__DOT__mantissa),24);
        tracep->fullQData(oldp+155,(vlTOPp->fpu_top__DOT__fmul1__DOT__mantissaProd),48);
        tracep->fullIData(oldp+157,(vlTOPp->fpu_top__DOT__fdiv1__DOT__temp_out),32);
        tracep->fullIData(oldp+158,((((IData)(0xbe6eb3beU) 
                                      - vlTOPp->fpu_top__DOT__operand_two) 
                                     >> 1U)),32);
        tracep->fullBit(oldp+159,(0U));
        tracep->fullCData(oldp+160,(vlTOPp->fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1__DOT__expF),8);
        tracep->fullIData(oldp+161,(vlTOPp->fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1__DOT__mantissa),24);
        tracep->fullIData(oldp+162,(((0U == (((IData)(0xbe6eb3beU) 
                                              - vlTOPp->fpu_top__DOT__operand_two) 
                                             >> 1U))
                                      ? 0U : (0x800000U 
                                              | (0x7fffffU 
                                                 & (((IData)(0xbe6eb3beU) 
                                                     - vlTOPp->fpu_top__DOT__operand_two) 
                                                    >> 1U))))),24);
        tracep->fullQData(oldp+163,(vlTOPp->fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1__DOT__mantissaProd),48);
        tracep->fullBit(oldp+165,((1U & ((vlTOPp->fpu_top__DOT__operand_one 
                                          ^ vlTOPp->fpu_top__DOT__fdiv1__DOT__temp_out) 
                                         >> 0x1fU))));
        tracep->fullCData(oldp+166,(vlTOPp->fpu_top__DOT__fdiv1__DOT__fm0__DOT__expF),8);
        tracep->fullIData(oldp+167,(vlTOPp->fpu_top__DOT__fdiv1__DOT__fm0__DOT__mantissa),24);
        tracep->fullIData(oldp+168,(((0U == vlTOPp->fpu_top__DOT__fdiv1__DOT__temp_out)
                                      ? 0U : (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->fpu_top__DOT__fdiv1__DOT__temp_out)))),24);
        tracep->fullQData(oldp+169,(vlTOPp->fpu_top__DOT__fdiv1__DOT__fm0__DOT__mantissaProd),48);
        tracep->fullCData(oldp+171,((0xffU & (vlTOPp->fpu_top__DOT__operand_one 
                                              >> 0x17U))),8);
        tracep->fullCData(oldp+172,((0xffU & (vlTOPp->fpu_top__DOT__operand_two 
                                              >> 0x17U))),8);
        tracep->fullIData(oldp+173,((0x7fffffU & vlTOPp->fpu_top__DOT__operand_one)),23);
        tracep->fullIData(oldp+174,((0x7fffffU & vlTOPp->fpu_top__DOT__operand_two)),23);
        tracep->fullIData(oldp+175,(vlTOPp->instruction),32);
        tracep->fullBit(oldp+176,(vlTOPp->clk));
        tracep->fullIData(oldp+177,(vlTOPp->fpu_out),32);
        tracep->fullCData(oldp+178,((0x1fU & (vlTOPp->instruction 
                                              >> 0xfU))),5);
        tracep->fullCData(oldp+179,((0x1fU & (vlTOPp->instruction 
                                              >> 0x14U))),5);
        tracep->fullCData(oldp+180,((0x1fU & (vlTOPp->instruction 
                                              >> 0x1bU))),5);
        tracep->fullIData(oldp+181,(vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num),32);
        tracep->fullIData(oldp+182,(vlTOPp->fpu_top__DOT__fcsr),32);
        tracep->fullIData(oldp+183,(0U),32);
        tracep->fullIData(oldp+184,(0U),32);
        tracep->fullIData(oldp+185,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__i),32);
        tracep->fullIData(oldp+186,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__i),32);
        tracep->fullIData(oldp+187,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__i),32);
        tracep->fullIData(oldp+188,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__i),32);
        tracep->fullIData(oldp+189,(vlTOPp->fpu_top__DOT__fadd1__DOT__i),32);
        tracep->fullIData(oldp+190,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__i),32);
        tracep->fullIData(oldp+191,(0xbe6eb3beU),32);
    }
}
