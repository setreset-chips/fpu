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
        tracep->declBus(c+243,"instruction", false,-1, 31,0);
        tracep->declBit(c+244,"clk", false,-1);
        tracep->declBus(c+245,"fpu_out", false,-1, 31,0);
        tracep->declBus(c+243,"fpu_top instruction", false,-1, 31,0);
        tracep->declBit(c+244,"fpu_top clk", false,-1);
        tracep->declBus(c+245,"fpu_top fpu_out", false,-1, 31,0);
        tracep->declBus(c+1,"fpu_top operand_1", false,-1, 31,0);
        tracep->declBus(c+2,"fpu_top operand_2", false,-1, 31,0);
        tracep->declBus(c+3,"fpu_top operand_3", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+4+i*1,"fpu_top regFile", true,(i+0), 31,0);}}
        tracep->declBus(c+250,"fpu_top fcsr", false,-1, 31,0);
        tracep->declBus(c+246,"fpu_top op1_addr", false,-1, 4,0);
        tracep->declBus(c+247,"fpu_top op2_addr", false,-1, 4,0);
        tracep->declBus(c+248,"fpu_top op3_addr", false,-1, 4,0);
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
        tracep->declBus(c+238,"fpu_top fsq", false,-1, 31,0);
        tracep->declBus(c+59,"fpu_top fsj", false,-1, 31,0);
        tracep->declBus(c+60,"fpu_top fsn", false,-1, 31,0);
        tracep->declBus(c+61,"fpu_top fsx", false,-1, 31,0);
        tracep->declBus(c+62,"fpu_top fmi", false,-1, 31,0);
        tracep->declBus(c+63,"fpu_top fmx", false,-1, 31,0);
        tracep->declBus(c+64,"fpu_top fq", false,-1, 31,0);
        tracep->declBus(c+65,"fpu_top ft", false,-1, 31,0);
        tracep->declBus(c+66,"fpu_top fe", false,-1, 31,0);
        tracep->declBus(c+251,"fpu_top fcls", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top rm", false,-1, 2,0);
        tracep->declBus(c+68,"fpu_top writeback_data", false,-1, 31,0);
        tracep->declBus(c+69,"fpu_top ins_p3", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fmadd1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fmadd1 var2", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fmadd1 var3", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fmadd1 rm", false,-1, 2,0);
        tracep->declBus(c+51,"fpu_top fmadd1 res", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fmadd1 in1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fmadd1 in2", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fmadd1 in3", false,-1, 31,0);
        tracep->declBus(c+70,"fpu_top fmadd1 out", false,-1, 31,0);
        tracep->declBus(c+51,"fpu_top fmadd1 out2", false,-1, 31,0);
        tracep->declBus(c+70,"fpu_top fmadd1 fadd1 num1", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fmadd1 fadd1 num2", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fmadd1 fadd1 rm", false,-1, 2,0);
        tracep->declBus(c+51,"fpu_top fmadd1 fadd1 out_num", false,-1, 31,0);
        tracep->declBit(c+71,"fpu_top fmadd1 fadd1 largerMag", false,-1);
        tracep->declBit(c+72,"fpu_top fmadd1 fadd1 finalSign", false,-1);
        tracep->declBus(c+73,"fpu_top fmadd1 fadd1 num1Exp", false,-1, 7,0);
        tracep->declBus(c+74,"fpu_top fmadd1 fadd1 num2Exp", false,-1, 7,0);
        tracep->declBus(c+75,"fpu_top fmadd1 fadd1 finalExp", false,-1, 7,0);
        tracep->declBus(c+76,"fpu_top fmadd1 fadd1 num1Mant", false,-1, 23,0);
        tracep->declBus(c+77,"fpu_top fmadd1 fadd1 num2Mant", false,-1, 23,0);
        tracep->declBus(c+78,"fpu_top fmadd1 fadd1 finalMant", false,-1, 23,0);
        tracep->declBus(c+79,"fpu_top fmadd1 fadd1 sumMants", false,-1, 24,0);
        tracep->declBus(c+252,"fpu_top fmadd1 fadd1 i", false,-1, 31,0);
        tracep->declBus(c+80,"fpu_top fmadd1 fadd1 unrounded", false,-1, 31,0);
        tracep->declBus(c+80,"fpu_top fmadd1 fadd1 r0 num1", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fmadd1 fadd1 r0 rm", false,-1, 2,0);
        tracep->declBus(c+51,"fpu_top fmadd1 fadd1 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+51,"fpu_top fmadd1 fadd1 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+81,"fpu_top fmadd1 fadd1 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+82,"fpu_top fmadd1 fadd1 r0 mask", false,-1, 22,0);
        tracep->declBus(c+83,"fpu_top fmadd1 fadd1 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+84,"fpu_top fmadd1 fadd1 r0 i", false,-1, 31,0);
        tracep->declBus(c+253,"fpu_top fmadd1 fadd1 r0 j", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fmsub1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fmsub1 var2", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fmsub1 var3", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fmsub1 rm", false,-1, 2,0);
        tracep->declBus(c+52,"fpu_top fmsub1 res", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fmsub1 in1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fmsub1 in2", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fmsub1 in3", false,-1, 31,0);
        tracep->declBus(c+85,"fpu_top fmsub1 out", false,-1, 31,0);
        tracep->declBus(c+52,"fpu_top fmsub1 out2", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fmsub1 f1 num1", false,-1, 31,0);
        tracep->declBus(c+86,"fpu_top fmsub1 f1 num2", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fmsub1 f1 rm", false,-1, 2,0);
        tracep->declBus(c+85,"fpu_top fmsub1 f1 out_num", false,-1, 31,0);
        tracep->declBit(c+87,"fpu_top fmsub1 f1 largerMag", false,-1);
        tracep->declBit(c+88,"fpu_top fmsub1 f1 finalSign", false,-1);
        tracep->declBus(c+89,"fpu_top fmsub1 f1 num1Exp", false,-1, 7,0);
        tracep->declBus(c+90,"fpu_top fmsub1 f1 num2Exp", false,-1, 7,0);
        tracep->declBus(c+91,"fpu_top fmsub1 f1 finalExp", false,-1, 7,0);
        tracep->declBus(c+92,"fpu_top fmsub1 f1 num1Mant", false,-1, 23,0);
        tracep->declBus(c+93,"fpu_top fmsub1 f1 num2Mant", false,-1, 23,0);
        tracep->declBus(c+94,"fpu_top fmsub1 f1 finalMant", false,-1, 23,0);
        tracep->declBus(c+95,"fpu_top fmsub1 f1 sumMants", false,-1, 24,0);
        tracep->declBus(c+254,"fpu_top fmsub1 f1 i", false,-1, 31,0);
        tracep->declBus(c+96,"fpu_top fmsub1 f1 unrounded", false,-1, 31,0);
        tracep->declBus(c+96,"fpu_top fmsub1 f1 r0 num1", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fmsub1 f1 r0 rm", false,-1, 2,0);
        tracep->declBus(c+85,"fpu_top fmsub1 f1 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+85,"fpu_top fmsub1 f1 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+97,"fpu_top fmsub1 f1 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+98,"fpu_top fmsub1 f1 r0 mask", false,-1, 22,0);
        tracep->declBus(c+99,"fpu_top fmsub1 f1 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+100,"fpu_top fmsub1 f1 r0 i", false,-1, 31,0);
        tracep->declBus(c+255,"fpu_top fmsub1 f1 r0 j", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fnmsub1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fnmsub1 var2", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fnmsub1 var3", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fnmsub1 rm", false,-1, 2,0);
        tracep->declBus(c+53,"fpu_top fnmsub1 res", false,-1, 31,0);
        tracep->declBus(c+101,"fpu_top fnmsub1 in1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fnmsub1 in2", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fnmsub1 in3", false,-1, 31,0);
        tracep->declBus(c+102,"fpu_top fnmsub1 out", false,-1, 31,0);
        tracep->declBus(c+53,"fpu_top fnmsub1 out2", false,-1, 31,0);
        tracep->declBus(c+101,"fpu_top fnmsub1 fsub1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fnmsub1 fsub1 var2", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fnmsub1 fsub1 rm", false,-1, 2,0);
        tracep->declBus(c+53,"fpu_top fnmsub1 fsub1 res", false,-1, 31,0);
        tracep->declBus(c+101,"fpu_top fnmsub1 fsub1 f1 num1", false,-1, 31,0);
        tracep->declBus(c+86,"fpu_top fnmsub1 fsub1 f1 num2", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fnmsub1 fsub1 f1 rm", false,-1, 2,0);
        tracep->declBus(c+53,"fpu_top fnmsub1 fsub1 f1 out_num", false,-1, 31,0);
        tracep->declBit(c+103,"fpu_top fnmsub1 fsub1 f1 largerMag", false,-1);
        tracep->declBit(c+104,"fpu_top fnmsub1 fsub1 f1 finalSign", false,-1);
        tracep->declBus(c+105,"fpu_top fnmsub1 fsub1 f1 num1Exp", false,-1, 7,0);
        tracep->declBus(c+106,"fpu_top fnmsub1 fsub1 f1 num2Exp", false,-1, 7,0);
        tracep->declBus(c+107,"fpu_top fnmsub1 fsub1 f1 finalExp", false,-1, 7,0);
        tracep->declBus(c+108,"fpu_top fnmsub1 fsub1 f1 num1Mant", false,-1, 23,0);
        tracep->declBus(c+109,"fpu_top fnmsub1 fsub1 f1 num2Mant", false,-1, 23,0);
        tracep->declBus(c+110,"fpu_top fnmsub1 fsub1 f1 finalMant", false,-1, 23,0);
        tracep->declBus(c+111,"fpu_top fnmsub1 fsub1 f1 sumMants", false,-1, 24,0);
        tracep->declBus(c+256,"fpu_top fnmsub1 fsub1 f1 i", false,-1, 31,0);
        tracep->declBus(c+112,"fpu_top fnmsub1 fsub1 f1 unrounded", false,-1, 31,0);
        tracep->declBus(c+112,"fpu_top fnmsub1 fsub1 f1 r0 num1", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fnmsub1 fsub1 f1 r0 rm", false,-1, 2,0);
        tracep->declBus(c+53,"fpu_top fnmsub1 fsub1 f1 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+53,"fpu_top fnmsub1 fsub1 f1 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+113,"fpu_top fnmsub1 fsub1 f1 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+114,"fpu_top fnmsub1 fsub1 f1 r0 mask", false,-1, 22,0);
        tracep->declBus(c+115,"fpu_top fnmsub1 fsub1 f1 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+116,"fpu_top fnmsub1 fsub1 f1 r0 i", false,-1, 31,0);
        tracep->declBus(c+257,"fpu_top fnmsub1 fsub1 f1 r0 j", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fnmadd1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fnmadd1 var2", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fnmadd1 var3", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fnmadd1 rm", false,-1, 2,0);
        tracep->declBus(c+54,"fpu_top fnmadd1 res", false,-1, 31,0);
        tracep->declBus(c+101,"fpu_top fnmadd1 in1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fnmadd1 in2", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fnmadd1 in3", false,-1, 31,0);
        tracep->declBus(c+117,"fpu_top fnmadd1 out", false,-1, 31,0);
        tracep->declBus(c+54,"fpu_top fnmadd1 out2", false,-1, 31,0);
        tracep->declBus(c+117,"fpu_top fnmadd1 fadd1 num1", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fnmadd1 fadd1 num2", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fnmadd1 fadd1 rm", false,-1, 2,0);
        tracep->declBus(c+54,"fpu_top fnmadd1 fadd1 out_num", false,-1, 31,0);
        tracep->declBit(c+118,"fpu_top fnmadd1 fadd1 largerMag", false,-1);
        tracep->declBit(c+119,"fpu_top fnmadd1 fadd1 finalSign", false,-1);
        tracep->declBus(c+120,"fpu_top fnmadd1 fadd1 num1Exp", false,-1, 7,0);
        tracep->declBus(c+121,"fpu_top fnmadd1 fadd1 num2Exp", false,-1, 7,0);
        tracep->declBus(c+122,"fpu_top fnmadd1 fadd1 finalExp", false,-1, 7,0);
        tracep->declBus(c+123,"fpu_top fnmadd1 fadd1 num1Mant", false,-1, 23,0);
        tracep->declBus(c+124,"fpu_top fnmadd1 fadd1 num2Mant", false,-1, 23,0);
        tracep->declBus(c+125,"fpu_top fnmadd1 fadd1 finalMant", false,-1, 23,0);
        tracep->declBus(c+126,"fpu_top fnmadd1 fadd1 sumMants", false,-1, 24,0);
        tracep->declBus(c+258,"fpu_top fnmadd1 fadd1 i", false,-1, 31,0);
        tracep->declBus(c+127,"fpu_top fnmadd1 fadd1 unrounded", false,-1, 31,0);
        tracep->declBus(c+127,"fpu_top fnmadd1 fadd1 r0 num1", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fnmadd1 fadd1 r0 rm", false,-1, 2,0);
        tracep->declBus(c+54,"fpu_top fnmadd1 fadd1 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+54,"fpu_top fnmadd1 fadd1 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+128,"fpu_top fnmadd1 fadd1 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+129,"fpu_top fnmadd1 fadd1 r0 mask", false,-1, 22,0);
        tracep->declBus(c+130,"fpu_top fnmadd1 fadd1 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+131,"fpu_top fnmadd1 fadd1 r0 i", false,-1, 31,0);
        tracep->declBus(c+259,"fpu_top fnmadd1 fadd1 r0 j", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fadd1 num1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fadd1 num2", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fadd1 rm", false,-1, 2,0);
        tracep->declBus(c+55,"fpu_top fadd1 out_num", false,-1, 31,0);
        tracep->declBit(c+132,"fpu_top fadd1 largerMag", false,-1);
        tracep->declBit(c+133,"fpu_top fadd1 finalSign", false,-1);
        tracep->declBus(c+134,"fpu_top fadd1 num1Exp", false,-1, 7,0);
        tracep->declBus(c+135,"fpu_top fadd1 num2Exp", false,-1, 7,0);
        tracep->declBus(c+136,"fpu_top fadd1 finalExp", false,-1, 7,0);
        tracep->declBus(c+137,"fpu_top fadd1 num1Mant", false,-1, 23,0);
        tracep->declBus(c+138,"fpu_top fadd1 num2Mant", false,-1, 23,0);
        tracep->declBus(c+139,"fpu_top fadd1 finalMant", false,-1, 23,0);
        tracep->declBus(c+140,"fpu_top fadd1 sumMants", false,-1, 24,0);
        tracep->declBus(c+260,"fpu_top fadd1 i", false,-1, 31,0);
        tracep->declBus(c+141,"fpu_top fadd1 unrounded", false,-1, 31,0);
        tracep->declBus(c+141,"fpu_top fadd1 r0 num1", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fadd1 r0 rm", false,-1, 2,0);
        tracep->declBus(c+55,"fpu_top fadd1 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+55,"fpu_top fadd1 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+142,"fpu_top fadd1 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+143,"fpu_top fadd1 r0 mask", false,-1, 22,0);
        tracep->declBus(c+144,"fpu_top fadd1 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+145,"fpu_top fadd1 r0 i", false,-1, 31,0);
        tracep->declBus(c+261,"fpu_top fadd1 r0 j", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fsub1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fsub1 var2", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fsub1 rm", false,-1, 2,0);
        tracep->declBus(c+56,"fpu_top fsub1 res", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fsub1 f1 num1", false,-1, 31,0);
        tracep->declBus(c+86,"fpu_top fsub1 f1 num2", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fsub1 f1 rm", false,-1, 2,0);
        tracep->declBus(c+56,"fpu_top fsub1 f1 out_num", false,-1, 31,0);
        tracep->declBit(c+146,"fpu_top fsub1 f1 largerMag", false,-1);
        tracep->declBit(c+147,"fpu_top fsub1 f1 finalSign", false,-1);
        tracep->declBus(c+148,"fpu_top fsub1 f1 num1Exp", false,-1, 7,0);
        tracep->declBus(c+149,"fpu_top fsub1 f1 num2Exp", false,-1, 7,0);
        tracep->declBus(c+150,"fpu_top fsub1 f1 finalExp", false,-1, 7,0);
        tracep->declBus(c+151,"fpu_top fsub1 f1 num1Mant", false,-1, 23,0);
        tracep->declBus(c+152,"fpu_top fsub1 f1 num2Mant", false,-1, 23,0);
        tracep->declBus(c+153,"fpu_top fsub1 f1 finalMant", false,-1, 23,0);
        tracep->declBus(c+154,"fpu_top fsub1 f1 sumMants", false,-1, 24,0);
        tracep->declBus(c+262,"fpu_top fsub1 f1 i", false,-1, 31,0);
        tracep->declBus(c+155,"fpu_top fsub1 f1 unrounded", false,-1, 31,0);
        tracep->declBus(c+155,"fpu_top fsub1 f1 r0 num1", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fsub1 f1 r0 rm", false,-1, 2,0);
        tracep->declBus(c+56,"fpu_top fsub1 f1 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+56,"fpu_top fsub1 f1 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+156,"fpu_top fsub1 f1 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+157,"fpu_top fsub1 f1 r0 mask", false,-1, 22,0);
        tracep->declBus(c+158,"fpu_top fsub1 f1 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+159,"fpu_top fsub1 f1 r0 i", false,-1, 31,0);
        tracep->declBus(c+263,"fpu_top fsub1 f1 r0 j", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fdiv1 divisor", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fdiv1 dividend", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fdiv1 rm", false,-1, 2,0);
        tracep->declBus(c+58,"fpu_top fdiv1 div_out", false,-1, 31,0);
        tracep->declBus(c+160,"fpu_top fdiv1 temp_out", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fdiv1 fi0 num1", false,-1, 31,0);
        tracep->declBus(c+160,"fpu_top fdiv1 fi0 num_out", false,-1, 31,0);
        tracep->declBus(c+264,"fpu_top fdiv1 fi0 magic_number", false,-1, 31,0);
        tracep->declBus(c+161,"fpu_top fdiv1 fi0 temp_out", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fsqrt1 var1", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fsqrt1 rm", false,-1, 2,0);
        tracep->declBus(c+238,"fpu_top fsqrt1 res", false,-1, 31,0);
        tracep->declBus(c+249,"fpu_top fsqrt1 shifted_num", false,-1, 31,0);
        tracep->declBus(c+249,"fpu_top fsqrt1 r0 num1", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fsqrt1 r0 rm", false,-1, 2,0);
        tracep->declBus(c+238,"fpu_top fsqrt1 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+238,"fpu_top fsqrt1 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+239,"fpu_top fsqrt1 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+240,"fpu_top fsqrt1 r0 mask", false,-1, 22,0);
        tracep->declBus(c+241,"fpu_top fsqrt1 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+242,"fpu_top fsqrt1 r0 i", false,-1, 31,0);
        tracep->declBus(c+265,"fpu_top fsqrt1 r0 j", false,-1, 31,0);
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
        tracep->declBus(c+162,"fpu_top fmin1 exp1", false,-1, 7,0);
        tracep->declBus(c+163,"fpu_top fmin1 exp2", false,-1, 7,0);
        tracep->declBus(c+164,"fpu_top fmin1 mantissa1", false,-1, 22,0);
        tracep->declBus(c+165,"fpu_top fmin1 mantissa2", false,-1, 22,0);
        tracep->declBus(c+47,"fpu_top fmax1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fmax1 var2", false,-1, 31,0);
        tracep->declBus(c+63,"fpu_top fmax1 res", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fmax1 in1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fmax1 in2", false,-1, 31,0);
        tracep->declBus(c+63,"fpu_top fmax1 out", false,-1, 31,0);
        tracep->declBus(c+162,"fpu_top fmax1 exp1", false,-1, 7,0);
        tracep->declBus(c+163,"fpu_top fmax1 exp2", false,-1, 7,0);
        tracep->declBus(c+164,"fpu_top fmax1 mantissa1", false,-1, 22,0);
        tracep->declBus(c+165,"fpu_top fmax1 mantissa2", false,-1, 22,0);
        tracep->declBus(c+47,"fpu_top feq1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top feq1 var2", false,-1, 31,0);
        tracep->declBus(c+64,"fpu_top feq1 res", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top flt1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top flt1 var2", false,-1, 31,0);
        tracep->declBus(c+65,"fpu_top flt1 res", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top flt1 in1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top flt1 in2", false,-1, 31,0);
        tracep->declBus(c+65,"fpu_top flt1 out", false,-1, 31,0);
        tracep->declBus(c+162,"fpu_top flt1 exp1", false,-1, 7,0);
        tracep->declBus(c+163,"fpu_top flt1 exp2", false,-1, 7,0);
        tracep->declBus(c+164,"fpu_top flt1 mantissa1", false,-1, 22,0);
        tracep->declBus(c+165,"fpu_top flt1 mantissa2", false,-1, 22,0);
        tracep->declBus(c+47,"fpu_top fle1 var1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fle1 var2", false,-1, 31,0);
        tracep->declBus(c+66,"fpu_top fle1 res", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fle1 in1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fle1 in2", false,-1, 31,0);
        tracep->declBus(c+66,"fpu_top fle1 out", false,-1, 31,0);
        tracep->declBus(c+162,"fpu_top fle1 exp1", false,-1, 7,0);
        tracep->declBus(c+163,"fpu_top fle1 exp2", false,-1, 7,0);
        tracep->declBus(c+164,"fpu_top fle1 mantissa1", false,-1, 22,0);
        tracep->declBus(c+165,"fpu_top fle1 mantissa2", false,-1, 22,0);
        tracep->declBus(c+47,"fpu_top fclass1 val1", false,-1, 31,0);
        tracep->declBus(c+251,"fpu_top fclass1 out_val", false,-1, 31,0);
        tracep->declBus(c+251,"fpu_top fclass1 result", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fclass1 in1", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fmul1 num1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fmul1 num2", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fmul1 rm", false,-1, 2,0);
        tracep->declBus(c+57,"fpu_top fmul1 out_mul", false,-1, 31,0);
        tracep->declBit(c+166,"fpu_top fmul1 sign", false,-1);
        tracep->declBus(c+167,"fpu_top fmul1 expF", false,-1, 7,0);
        tracep->declBus(c+168,"fpu_top fmul1 mantissa", false,-1, 23,0);
        tracep->declBus(c+169,"fpu_top fmul1 mantissa1", false,-1, 23,0);
        tracep->declBus(c+170,"fpu_top fmul1 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+171,"fpu_top fmul1 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+266,"fpu_top fmul1 i", false,-1, 31,0);
        tracep->declBus(c+173,"fpu_top fmul1 r0 num1", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fmul1 r0 rm", false,-1, 2,0);
        tracep->declBus(c+57,"fpu_top fmul1 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+57,"fpu_top fmul1 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+174,"fpu_top fmul1 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+175,"fpu_top fmul1 r0 mask", false,-1, 22,0);
        tracep->declBus(c+176,"fpu_top fmul1 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+177,"fpu_top fmul1 r0 i", false,-1, 31,0);
        tracep->declBus(c+267,"fpu_top fmul1 r0 j", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fmadd1 fmul1 num1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fmadd1 fmul1 num2", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fmadd1 fmul1 rm", false,-1, 2,0);
        tracep->declBus(c+70,"fpu_top fmadd1 fmul1 out_mul", false,-1, 31,0);
        tracep->declBit(c+166,"fpu_top fmadd1 fmul1 sign", false,-1);
        tracep->declBus(c+178,"fpu_top fmadd1 fmul1 expF", false,-1, 7,0);
        tracep->declBus(c+179,"fpu_top fmadd1 fmul1 mantissa", false,-1, 23,0);
        tracep->declBus(c+169,"fpu_top fmadd1 fmul1 mantissa1", false,-1, 23,0);
        tracep->declBus(c+170,"fpu_top fmadd1 fmul1 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+180,"fpu_top fmadd1 fmul1 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+266,"fpu_top fmadd1 fmul1 i", false,-1, 31,0);
        tracep->declBus(c+182,"fpu_top fmadd1 fmul1 r0 num1", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fmadd1 fmul1 r0 rm", false,-1, 2,0);
        tracep->declBus(c+70,"fpu_top fmadd1 fmul1 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+70,"fpu_top fmadd1 fmul1 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+183,"fpu_top fmadd1 fmul1 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+184,"fpu_top fmadd1 fmul1 r0 mask", false,-1, 22,0);
        tracep->declBus(c+185,"fpu_top fmadd1 fmul1 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+186,"fpu_top fmadd1 fmul1 r0 i", false,-1, 31,0);
        tracep->declBus(c+268,"fpu_top fmadd1 fmul1 r0 j", false,-1, 31,0);
        tracep->declBus(c+85,"fpu_top fmsub1 fmul1 num1", false,-1, 31,0);
        tracep->declBus(c+49,"fpu_top fmsub1 fmul1 num2", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fmsub1 fmul1 rm", false,-1, 2,0);
        tracep->declBus(c+52,"fpu_top fmsub1 fmul1 out_mul", false,-1, 31,0);
        tracep->declBit(c+187,"fpu_top fmsub1 fmul1 sign", false,-1);
        tracep->declBus(c+188,"fpu_top fmsub1 fmul1 expF", false,-1, 7,0);
        tracep->declBus(c+189,"fpu_top fmsub1 fmul1 mantissa", false,-1, 23,0);
        tracep->declBus(c+190,"fpu_top fmsub1 fmul1 mantissa1", false,-1, 23,0);
        tracep->declBus(c+191,"fpu_top fmsub1 fmul1 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+192,"fpu_top fmsub1 fmul1 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+266,"fpu_top fmsub1 fmul1 i", false,-1, 31,0);
        tracep->declBus(c+194,"fpu_top fmsub1 fmul1 r0 num1", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fmsub1 fmul1 r0 rm", false,-1, 2,0);
        tracep->declBus(c+52,"fpu_top fmsub1 fmul1 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+52,"fpu_top fmsub1 fmul1 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+195,"fpu_top fmsub1 fmul1 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+196,"fpu_top fmsub1 fmul1 r0 mask", false,-1, 22,0);
        tracep->declBus(c+197,"fpu_top fmsub1 fmul1 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+198,"fpu_top fmsub1 fmul1 r0 i", false,-1, 31,0);
        tracep->declBus(c+269,"fpu_top fmsub1 fmul1 r0 j", false,-1, 31,0);
        tracep->declBus(c+101,"fpu_top fnmsub1 fmul1 num1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fnmsub1 fmul1 num2", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fnmsub1 fmul1 rm", false,-1, 2,0);
        tracep->declBus(c+102,"fpu_top fnmsub1 fmul1 out_mul", false,-1, 31,0);
        tracep->declBit(c+199,"fpu_top fnmsub1 fmul1 sign", false,-1);
        tracep->declBus(c+200,"fpu_top fnmsub1 fmul1 expF", false,-1, 7,0);
        tracep->declBus(c+201,"fpu_top fnmsub1 fmul1 mantissa", false,-1, 23,0);
        tracep->declBus(c+202,"fpu_top fnmsub1 fmul1 mantissa1", false,-1, 23,0);
        tracep->declBus(c+170,"fpu_top fnmsub1 fmul1 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+203,"fpu_top fnmsub1 fmul1 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+266,"fpu_top fnmsub1 fmul1 i", false,-1, 31,0);
        tracep->declBus(c+205,"fpu_top fnmsub1 fmul1 r0 num1", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fnmsub1 fmul1 r0 rm", false,-1, 2,0);
        tracep->declBus(c+102,"fpu_top fnmsub1 fmul1 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+102,"fpu_top fnmsub1 fmul1 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+206,"fpu_top fnmsub1 fmul1 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+207,"fpu_top fnmsub1 fmul1 r0 mask", false,-1, 22,0);
        tracep->declBus(c+208,"fpu_top fnmsub1 fmul1 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+209,"fpu_top fnmsub1 fmul1 r0 i", false,-1, 31,0);
        tracep->declBus(c+270,"fpu_top fnmsub1 fmul1 r0 j", false,-1, 31,0);
        tracep->declBus(c+101,"fpu_top fnmadd1 fmul1 num1", false,-1, 31,0);
        tracep->declBus(c+48,"fpu_top fnmadd1 fmul1 num2", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fnmadd1 fmul1 rm", false,-1, 2,0);
        tracep->declBus(c+117,"fpu_top fnmadd1 fmul1 out_mul", false,-1, 31,0);
        tracep->declBit(c+199,"fpu_top fnmadd1 fmul1 sign", false,-1);
        tracep->declBus(c+210,"fpu_top fnmadd1 fmul1 expF", false,-1, 7,0);
        tracep->declBus(c+211,"fpu_top fnmadd1 fmul1 mantissa", false,-1, 23,0);
        tracep->declBus(c+202,"fpu_top fnmadd1 fmul1 mantissa1", false,-1, 23,0);
        tracep->declBus(c+170,"fpu_top fnmadd1 fmul1 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+212,"fpu_top fnmadd1 fmul1 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+266,"fpu_top fnmadd1 fmul1 i", false,-1, 31,0);
        tracep->declBus(c+214,"fpu_top fnmadd1 fmul1 r0 num1", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fnmadd1 fmul1 r0 rm", false,-1, 2,0);
        tracep->declBus(c+117,"fpu_top fnmadd1 fmul1 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+117,"fpu_top fnmadd1 fmul1 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+215,"fpu_top fnmadd1 fmul1 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+216,"fpu_top fnmadd1 fmul1 r0 mask", false,-1, 22,0);
        tracep->declBus(c+217,"fpu_top fnmadd1 fmul1 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+218,"fpu_top fnmadd1 fmul1 r0 i", false,-1, 31,0);
        tracep->declBus(c+271,"fpu_top fnmadd1 fmul1 r0 j", false,-1, 31,0);
        tracep->declBus(c+47,"fpu_top fdiv1 fm0 num1", false,-1, 31,0);
        tracep->declBus(c+160,"fpu_top fdiv1 fm0 num2", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fdiv1 fm0 rm", false,-1, 2,0);
        tracep->declBus(c+58,"fpu_top fdiv1 fm0 out_mul", false,-1, 31,0);
        tracep->declBit(c+219,"fpu_top fdiv1 fm0 sign", false,-1);
        tracep->declBus(c+220,"fpu_top fdiv1 fm0 expF", false,-1, 7,0);
        tracep->declBus(c+221,"fpu_top fdiv1 fm0 mantissa", false,-1, 23,0);
        tracep->declBus(c+169,"fpu_top fdiv1 fm0 mantissa1", false,-1, 23,0);
        tracep->declBus(c+222,"fpu_top fdiv1 fm0 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+223,"fpu_top fdiv1 fm0 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+266,"fpu_top fdiv1 fm0 i", false,-1, 31,0);
        tracep->declBus(c+225,"fpu_top fdiv1 fm0 r0 num1", false,-1, 31,0);
        tracep->declBus(c+67,"fpu_top fdiv1 fm0 r0 rm", false,-1, 2,0);
        tracep->declBus(c+58,"fpu_top fdiv1 fm0 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+58,"fpu_top fdiv1 fm0 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+226,"fpu_top fdiv1 fm0 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+227,"fpu_top fdiv1 fm0 r0 mask", false,-1, 22,0);
        tracep->declBus(c+228,"fpu_top fdiv1 fm0 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+229,"fpu_top fdiv1 fm0 r0 i", false,-1, 31,0);
        tracep->declBus(c+272,"fpu_top fdiv1 fm0 r0 j", false,-1, 31,0);
        tracep->declBus(c+161,"fpu_top fdiv1 fi0 f1 num1", false,-1, 31,0);
        tracep->declBus(c+161,"fpu_top fdiv1 fi0 f1 num2", false,-1, 31,0);
        tracep->declBus(c+273,"fpu_top fdiv1 fi0 f1 rm", false,-1, 2,0);
        tracep->declBus(c+160,"fpu_top fdiv1 fi0 f1 out_mul", false,-1, 31,0);
        tracep->declBit(c+230,"fpu_top fdiv1 fi0 f1 sign", false,-1);
        tracep->declBus(c+231,"fpu_top fdiv1 fi0 f1 expF", false,-1, 7,0);
        tracep->declBus(c+232,"fpu_top fdiv1 fi0 f1 mantissa", false,-1, 23,0);
        tracep->declBus(c+233,"fpu_top fdiv1 fi0 f1 mantissa1", false,-1, 23,0);
        tracep->declBus(c+233,"fpu_top fdiv1 fi0 f1 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+234,"fpu_top fdiv1 fi0 f1 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+266,"fpu_top fdiv1 fi0 f1 i", false,-1, 31,0);
        tracep->declBus(c+236,"fpu_top fdiv1 fi0 f1 r0 num1", false,-1, 31,0);
        tracep->declBus(c+273,"fpu_top fdiv1 fi0 f1 r0 rm", false,-1, 2,0);
        tracep->declBus(c+160,"fpu_top fdiv1 fi0 f1 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+160,"fpu_top fdiv1 fi0 f1 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+237,"fpu_top fdiv1 fi0 f1 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+274,"fpu_top fdiv1 fi0 f1 r0 mask", false,-1, 22,0);
        tracep->declBus(c+275,"fpu_top fdiv1 fi0 f1 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+276,"fpu_top fdiv1 fi0 f1 r0 i", false,-1, 31,0);
        tracep->declBus(c+277,"fpu_top fdiv1 fi0 f1 r0 j", false,-1, 31,0);
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
        tracep->fullIData(oldp+51,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+52,(vlSymsp->TOP__fpu_top__DOT__fmsub1__DOT__fmul1.__PVT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+53,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+54,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+55,(vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+56,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+57,(vlSymsp->TOP__fpu_top__DOT__fmul1.__PVT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+58,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fm0.__PVT__r0__DOT__rounded),32);
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
        tracep->fullCData(oldp+67,(vlTOPp->fpu_top__DOT__rm),3);
        tracep->fullIData(oldp+68,(vlTOPp->fpu_top__DOT__writeback_data),32);
        tracep->fullIData(oldp+69,(vlTOPp->fpu_top__DOT__ins_p3),32);
        tracep->fullIData(oldp+70,(vlSymsp->TOP__fpu_top__DOT__fmadd1__DOT__fmul1.__PVT__r0__DOT__rounded),32);
        tracep->fullBit(oldp+71,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__largerMag));
        tracep->fullBit(oldp+72,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalSign));
        tracep->fullCData(oldp+73,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Exp),8);
        tracep->fullCData(oldp+74,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Exp),8);
        tracep->fullCData(oldp+75,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp),8);
        tracep->fullIData(oldp+76,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Mant),24);
        tracep->fullIData(oldp+77,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Mant),24);
        tracep->fullIData(oldp+78,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant),24);
        tracep->fullIData(oldp+79,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__sumMants),25);
        tracep->fullIData(oldp+80,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded),32);
        tracep->fullIData(oldp+81,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck),24);
        tracep->fullIData(oldp+82,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask),23);
        tracep->fullIData(oldp+83,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+84,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i),32);
        tracep->fullIData(oldp+85,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+86,(vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2),32);
        tracep->fullBit(oldp+87,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__largerMag));
        tracep->fullBit(oldp+88,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalSign));
        tracep->fullCData(oldp+89,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Exp),8);
        tracep->fullCData(oldp+90,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Exp),8);
        tracep->fullCData(oldp+91,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp),8);
        tracep->fullIData(oldp+92,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Mant),24);
        tracep->fullIData(oldp+93,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Mant),24);
        tracep->fullIData(oldp+94,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant),24);
        tracep->fullIData(oldp+95,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__sumMants),25);
        tracep->fullIData(oldp+96,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded),32);
        tracep->fullIData(oldp+97,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck),24);
        tracep->fullIData(oldp+98,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask),23);
        tracep->fullIData(oldp+99,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+100,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i),32);
        tracep->fullIData(oldp+101,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1),32);
        tracep->fullIData(oldp+102,(vlSymsp->TOP__fpu_top__DOT__fnmsub1__DOT__fmul1.__PVT__r0__DOT__rounded),32);
        tracep->fullBit(oldp+103,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__largerMag));
        tracep->fullBit(oldp+104,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalSign));
        tracep->fullCData(oldp+105,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Exp),8);
        tracep->fullCData(oldp+106,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Exp),8);
        tracep->fullCData(oldp+107,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp),8);
        tracep->fullIData(oldp+108,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Mant),24);
        tracep->fullIData(oldp+109,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Mant),24);
        tracep->fullIData(oldp+110,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant),24);
        tracep->fullIData(oldp+111,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__sumMants),25);
        tracep->fullIData(oldp+112,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded),32);
        tracep->fullIData(oldp+113,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck),24);
        tracep->fullIData(oldp+114,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask),23);
        tracep->fullIData(oldp+115,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+116,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i),32);
        tracep->fullIData(oldp+117,(vlSymsp->TOP__fpu_top__DOT__fnmadd1__DOT__fmul1.__PVT__r0__DOT__rounded),32);
        tracep->fullBit(oldp+118,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__largerMag));
        tracep->fullBit(oldp+119,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalSign));
        tracep->fullCData(oldp+120,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Exp),8);
        tracep->fullCData(oldp+121,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Exp),8);
        tracep->fullCData(oldp+122,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp),8);
        tracep->fullIData(oldp+123,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Mant),24);
        tracep->fullIData(oldp+124,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Mant),24);
        tracep->fullIData(oldp+125,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant),24);
        tracep->fullIData(oldp+126,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__sumMants),25);
        tracep->fullIData(oldp+127,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded),32);
        tracep->fullIData(oldp+128,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck),24);
        tracep->fullIData(oldp+129,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask),23);
        tracep->fullIData(oldp+130,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+131,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i),32);
        tracep->fullBit(oldp+132,(vlTOPp->fpu_top__DOT__fadd1__DOT__largerMag));
        tracep->fullBit(oldp+133,(vlTOPp->fpu_top__DOT__fadd1__DOT__finalSign));
        tracep->fullCData(oldp+134,(vlTOPp->fpu_top__DOT__fadd1__DOT__num1Exp),8);
        tracep->fullCData(oldp+135,(vlTOPp->fpu_top__DOT__fadd1__DOT__num2Exp),8);
        tracep->fullCData(oldp+136,(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp),8);
        tracep->fullIData(oldp+137,(vlTOPp->fpu_top__DOT__fadd1__DOT__num1Mant),24);
        tracep->fullIData(oldp+138,(vlTOPp->fpu_top__DOT__fadd1__DOT__num2Mant),24);
        tracep->fullIData(oldp+139,(vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant),24);
        tracep->fullIData(oldp+140,(vlTOPp->fpu_top__DOT__fadd1__DOT__sumMants),25);
        tracep->fullIData(oldp+141,(vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded),32);
        tracep->fullIData(oldp+142,(vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck),24);
        tracep->fullIData(oldp+143,(vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask),23);
        tracep->fullIData(oldp+144,(vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+145,(vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i),32);
        tracep->fullBit(oldp+146,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__largerMag));
        tracep->fullBit(oldp+147,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalSign));
        tracep->fullCData(oldp+148,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Exp),8);
        tracep->fullCData(oldp+149,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Exp),8);
        tracep->fullCData(oldp+150,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp),8);
        tracep->fullIData(oldp+151,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Mant),24);
        tracep->fullIData(oldp+152,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Mant),24);
        tracep->fullIData(oldp+153,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant),24);
        tracep->fullIData(oldp+154,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__sumMants),25);
        tracep->fullIData(oldp+155,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded),32);
        tracep->fullIData(oldp+156,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck),24);
        tracep->fullIData(oldp+157,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask),23);
        tracep->fullIData(oldp+158,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+159,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i),32);
        tracep->fullIData(oldp+160,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1.__PVT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+161,((((IData)(0xbe6eb3beU) 
                                      - vlTOPp->fpu_top__DOT__operand_two) 
                                     >> 1U)),32);
        tracep->fullCData(oldp+162,((0xffU & (vlTOPp->fpu_top__DOT__operand_one 
                                              >> 0x17U))),8);
        tracep->fullCData(oldp+163,((0xffU & (vlTOPp->fpu_top__DOT__operand_two 
                                              >> 0x17U))),8);
        tracep->fullIData(oldp+164,((0x7fffffU & vlTOPp->fpu_top__DOT__operand_one)),23);
        tracep->fullIData(oldp+165,((0x7fffffU & vlTOPp->fpu_top__DOT__operand_two)),23);
        tracep->fullBit(oldp+166,((1U & ((vlTOPp->fpu_top__DOT__operand_one 
                                          ^ vlTOPp->fpu_top__DOT__operand_two) 
                                         >> 0x1fU))));
        tracep->fullCData(oldp+167,(vlSymsp->TOP__fpu_top__DOT__fmul1.__PVT__expF),8);
        tracep->fullIData(oldp+168,(vlSymsp->TOP__fpu_top__DOT__fmul1.__PVT__mantissa),24);
        tracep->fullIData(oldp+169,(((0U == vlTOPp->fpu_top__DOT__operand_one)
                                      ? 0U : (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->fpu_top__DOT__operand_one)))),24);
        tracep->fullIData(oldp+170,(((0U == vlTOPp->fpu_top__DOT__operand_two)
                                      ? 0U : (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->fpu_top__DOT__operand_two)))),24);
        tracep->fullQData(oldp+171,(vlSymsp->TOP__fpu_top__DOT__fmul1.__PVT__mantissaProd),48);
        tracep->fullIData(oldp+173,(vlSymsp->TOP__fpu_top__DOT__fmul1.__Vcellinp__r0____pinNumber1),32);
        tracep->fullIData(oldp+174,(vlSymsp->TOP__fpu_top__DOT__fmul1.__PVT__r0__DOT__overflowCheck),24);
        tracep->fullIData(oldp+175,(vlSymsp->TOP__fpu_top__DOT__fmul1.__PVT__r0__DOT__mask),23);
        tracep->fullIData(oldp+176,(vlSymsp->TOP__fpu_top__DOT__fmul1.__PVT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+177,(vlSymsp->TOP__fpu_top__DOT__fmul1.__PVT__r0__DOT__i),32);
        tracep->fullCData(oldp+178,(vlSymsp->TOP__fpu_top__DOT__fmadd1__DOT__fmul1.__PVT__expF),8);
        tracep->fullIData(oldp+179,(vlSymsp->TOP__fpu_top__DOT__fmadd1__DOT__fmul1.__PVT__mantissa),24);
        tracep->fullQData(oldp+180,(vlSymsp->TOP__fpu_top__DOT__fmadd1__DOT__fmul1.__PVT__mantissaProd),48);
        tracep->fullIData(oldp+182,(vlSymsp->TOP__fpu_top__DOT__fmadd1__DOT__fmul1.__Vcellinp__r0____pinNumber1),32);
        tracep->fullIData(oldp+183,(vlSymsp->TOP__fpu_top__DOT__fmadd1__DOT__fmul1.__PVT__r0__DOT__overflowCheck),24);
        tracep->fullIData(oldp+184,(vlSymsp->TOP__fpu_top__DOT__fmadd1__DOT__fmul1.__PVT__r0__DOT__mask),23);
        tracep->fullIData(oldp+185,(vlSymsp->TOP__fpu_top__DOT__fmadd1__DOT__fmul1.__PVT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+186,(vlSymsp->TOP__fpu_top__DOT__fmadd1__DOT__fmul1.__PVT__r0__DOT__i),32);
        tracep->fullBit(oldp+187,((1U & ((vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                                          ^ vlTOPp->fpu_top__DOT__operand_three) 
                                         >> 0x1fU))));
        tracep->fullCData(oldp+188,(vlSymsp->TOP__fpu_top__DOT__fmsub1__DOT__fmul1.__PVT__expF),8);
        tracep->fullIData(oldp+189,(vlSymsp->TOP__fpu_top__DOT__fmsub1__DOT__fmul1.__PVT__mantissa),24);
        tracep->fullIData(oldp+190,(((0U == vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded)
                                      ? 0U : (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded)))),24);
        tracep->fullIData(oldp+191,(((0U == vlTOPp->fpu_top__DOT__operand_three)
                                      ? 0U : (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->fpu_top__DOT__operand_three)))),24);
        tracep->fullQData(oldp+192,(vlSymsp->TOP__fpu_top__DOT__fmsub1__DOT__fmul1.__PVT__mantissaProd),48);
        tracep->fullIData(oldp+194,(vlSymsp->TOP__fpu_top__DOT__fmsub1__DOT__fmul1.__Vcellinp__r0____pinNumber1),32);
        tracep->fullIData(oldp+195,(vlSymsp->TOP__fpu_top__DOT__fmsub1__DOT__fmul1.__PVT__r0__DOT__overflowCheck),24);
        tracep->fullIData(oldp+196,(vlSymsp->TOP__fpu_top__DOT__fmsub1__DOT__fmul1.__PVT__r0__DOT__mask),23);
        tracep->fullIData(oldp+197,(vlSymsp->TOP__fpu_top__DOT__fmsub1__DOT__fmul1.__PVT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+198,(vlSymsp->TOP__fpu_top__DOT__fmsub1__DOT__fmul1.__PVT__r0__DOT__i),32);
        tracep->fullBit(oldp+199,((1U & ((vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1 
                                          ^ vlTOPp->fpu_top__DOT__operand_two) 
                                         >> 0x1fU))));
        tracep->fullCData(oldp+200,(vlSymsp->TOP__fpu_top__DOT__fnmsub1__DOT__fmul1.__PVT__expF),8);
        tracep->fullIData(oldp+201,(vlSymsp->TOP__fpu_top__DOT__fnmsub1__DOT__fmul1.__PVT__mantissa),24);
        tracep->fullIData(oldp+202,(((0U == vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1)
                                      ? 0U : (0x800000U 
                                              | (0x7fffffU 
                                                 & vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1)))),24);
        tracep->fullQData(oldp+203,(vlSymsp->TOP__fpu_top__DOT__fnmsub1__DOT__fmul1.__PVT__mantissaProd),48);
        tracep->fullIData(oldp+205,(vlSymsp->TOP__fpu_top__DOT__fnmsub1__DOT__fmul1.__Vcellinp__r0____pinNumber1),32);
        tracep->fullIData(oldp+206,(vlSymsp->TOP__fpu_top__DOT__fnmsub1__DOT__fmul1.__PVT__r0__DOT__overflowCheck),24);
        tracep->fullIData(oldp+207,(vlSymsp->TOP__fpu_top__DOT__fnmsub1__DOT__fmul1.__PVT__r0__DOT__mask),23);
        tracep->fullIData(oldp+208,(vlSymsp->TOP__fpu_top__DOT__fnmsub1__DOT__fmul1.__PVT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+209,(vlSymsp->TOP__fpu_top__DOT__fnmsub1__DOT__fmul1.__PVT__r0__DOT__i),32);
        tracep->fullCData(oldp+210,(vlSymsp->TOP__fpu_top__DOT__fnmadd1__DOT__fmul1.__PVT__expF),8);
        tracep->fullIData(oldp+211,(vlSymsp->TOP__fpu_top__DOT__fnmadd1__DOT__fmul1.__PVT__mantissa),24);
        tracep->fullQData(oldp+212,(vlSymsp->TOP__fpu_top__DOT__fnmadd1__DOT__fmul1.__PVT__mantissaProd),48);
        tracep->fullIData(oldp+214,(vlSymsp->TOP__fpu_top__DOT__fnmadd1__DOT__fmul1.__Vcellinp__r0____pinNumber1),32);
        tracep->fullIData(oldp+215,(vlSymsp->TOP__fpu_top__DOT__fnmadd1__DOT__fmul1.__PVT__r0__DOT__overflowCheck),24);
        tracep->fullIData(oldp+216,(vlSymsp->TOP__fpu_top__DOT__fnmadd1__DOT__fmul1.__PVT__r0__DOT__mask),23);
        tracep->fullIData(oldp+217,(vlSymsp->TOP__fpu_top__DOT__fnmadd1__DOT__fmul1.__PVT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+218,(vlSymsp->TOP__fpu_top__DOT__fnmadd1__DOT__fmul1.__PVT__r0__DOT__i),32);
        tracep->fullBit(oldp+219,((1U & ((vlTOPp->fpu_top__DOT__operand_one 
                                          ^ vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1.__PVT__r0__DOT__rounded) 
                                         >> 0x1fU))));
        tracep->fullCData(oldp+220,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fm0.__PVT__expF),8);
        tracep->fullIData(oldp+221,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fm0.__PVT__mantissa),24);
        tracep->fullIData(oldp+222,(((0U == vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1.__PVT__r0__DOT__rounded)
                                      ? 0U : (0x800000U 
                                              | (0x7fffffU 
                                                 & vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1.__PVT__r0__DOT__rounded)))),24);
        tracep->fullQData(oldp+223,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fm0.__PVT__mantissaProd),48);
        tracep->fullIData(oldp+225,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fm0.__Vcellinp__r0____pinNumber1),32);
        tracep->fullIData(oldp+226,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fm0.__PVT__r0__DOT__overflowCheck),24);
        tracep->fullIData(oldp+227,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fm0.__PVT__r0__DOT__mask),23);
        tracep->fullIData(oldp+228,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fm0.__PVT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+229,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fm0.__PVT__r0__DOT__i),32);
        tracep->fullBit(oldp+230,(0U));
        tracep->fullCData(oldp+231,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1.__PVT__expF),8);
        tracep->fullIData(oldp+232,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1.__PVT__mantissa),24);
        tracep->fullIData(oldp+233,(((0U == (((IData)(0xbe6eb3beU) 
                                              - vlTOPp->fpu_top__DOT__operand_two) 
                                             >> 1U))
                                      ? 0U : (0x800000U 
                                              | (0x7fffffU 
                                                 & (((IData)(0xbe6eb3beU) 
                                                     - vlTOPp->fpu_top__DOT__operand_two) 
                                                    >> 1U))))),24);
        tracep->fullQData(oldp+234,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1.__PVT__mantissaProd),48);
        tracep->fullIData(oldp+236,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1.__Vcellinp__r0____pinNumber1),32);
        tracep->fullIData(oldp+237,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1.__PVT__r0__DOT__overflowCheck),24);
        tracep->fullIData(oldp+238,(vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+239,(vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck),24);
        tracep->fullIData(oldp+240,(vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask),23);
        tracep->fullIData(oldp+241,(vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+242,(vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i),32);
        tracep->fullIData(oldp+243,(vlTOPp->instruction),32);
        tracep->fullBit(oldp+244,(vlTOPp->clk));
        tracep->fullIData(oldp+245,(vlTOPp->fpu_out),32);
        tracep->fullCData(oldp+246,((0x1fU & (vlTOPp->instruction 
                                              >> 0xfU))),5);
        tracep->fullCData(oldp+247,((0x1fU & (vlTOPp->instruction 
                                              >> 0x14U))),5);
        tracep->fullCData(oldp+248,((0x1fU & (vlTOPp->instruction 
                                              >> 0x1bU))),5);
        tracep->fullIData(oldp+249,(vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num),32);
        tracep->fullIData(oldp+250,(vlTOPp->fpu_top__DOT__fcsr),32);
        tracep->fullIData(oldp+251,(0U),32);
        tracep->fullIData(oldp+252,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__i),32);
        tracep->fullIData(oldp+253,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__j),32);
        tracep->fullIData(oldp+254,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__i),32);
        tracep->fullIData(oldp+255,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__j),32);
        tracep->fullIData(oldp+256,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__i),32);
        tracep->fullIData(oldp+257,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__j),32);
        tracep->fullIData(oldp+258,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__i),32);
        tracep->fullIData(oldp+259,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__j),32);
        tracep->fullIData(oldp+260,(vlTOPp->fpu_top__DOT__fadd1__DOT__i),32);
        tracep->fullIData(oldp+261,(vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__j),32);
        tracep->fullIData(oldp+262,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__i),32);
        tracep->fullIData(oldp+263,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__j),32);
        tracep->fullIData(oldp+264,(0xbe6eb3beU),32);
        tracep->fullIData(oldp+265,(vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__j),32);
        tracep->fullIData(oldp+266,(0U),32);
        tracep->fullIData(oldp+267,(vlSymsp->TOP__fpu_top__DOT__fmul1.__PVT__r0__DOT__j),32);
        tracep->fullIData(oldp+268,(vlSymsp->TOP__fpu_top__DOT__fmadd1__DOT__fmul1.__PVT__r0__DOT__j),32);
        tracep->fullIData(oldp+269,(vlSymsp->TOP__fpu_top__DOT__fmsub1__DOT__fmul1.__PVT__r0__DOT__j),32);
        tracep->fullIData(oldp+270,(vlSymsp->TOP__fpu_top__DOT__fnmsub1__DOT__fmul1.__PVT__r0__DOT__j),32);
        tracep->fullIData(oldp+271,(vlSymsp->TOP__fpu_top__DOT__fnmadd1__DOT__fmul1.__PVT__r0__DOT__j),32);
        tracep->fullIData(oldp+272,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fm0.__PVT__r0__DOT__j),32);
        tracep->fullCData(oldp+273,(0U),3);
        tracep->fullIData(oldp+274,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1.__PVT__r0__DOT__mask),23);
        tracep->fullIData(oldp+275,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1.__PVT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+276,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1.__PVT__r0__DOT__i),32);
        tracep->fullIData(oldp+277,(vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1.__PVT__r0__DOT__j),32);
    }
}
