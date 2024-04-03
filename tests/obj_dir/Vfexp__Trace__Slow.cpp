// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfexp__Syms.h"


//======================

void Vfexp::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vfexp::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vfexp__Syms* __restrict vlSymsp = static_cast<Vfexp__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vfexp::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vfexp::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vfexp__Syms* __restrict vlSymsp = static_cast<Vfexp__Syms*>(userp);
    Vfexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vfexp::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vfexp__Syms* __restrict vlSymsp = static_cast<Vfexp__Syms*>(userp);
    Vfexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+91,"exp", false,-1, 31,0);
        tracep->declBus(c+92,"out_num", false,-1, 31,0);
        tracep->declBus(c+91,"fexp exp", false,-1, 31,0);
        tracep->declBus(c+92,"fexp out_num", false,-1, 31,0);
        tracep->declBus(c+98,"fexp one", false,-1, 31,0);
        tracep->declBus(c+99,"fexp one_half", false,-1, 31,0);
        tracep->declBus(c+100,"fexp one_sixth", false,-1, 31,0);
        tracep->declBus(c+101,"fexp one_twenty_fourth", false,-1, 31,0);
        tracep->declBus(c+102,"fexp one_120th", false,-1, 31,0);
        tracep->declBus(c+1,"fexp temp1", false,-1, 31,0);
        tracep->declBus(c+2,"fexp temp2", false,-1, 31,0);
        tracep->declBus(c+3,"fexp temp3", false,-1, 31,0);
        tracep->declBus(c+4,"fexp temp4", false,-1, 31,0);
        tracep->declBus(c+5,"fexp temp5", false,-1, 31,0);
        tracep->declBus(c+6,"fexp temp6", false,-1, 31,0);
        tracep->declBus(c+7,"fexp temp7", false,-1, 31,0);
        tracep->declBus(c+8,"fexp temp8", false,-1, 31,0);
        tracep->declBus(c+98,"fexp fa0 num1", false,-1, 31,0);
        tracep->declBus(c+91,"fexp fa0 num2", false,-1, 31,0);
        tracep->declBus(c+103,"fexp fa0 rm", false,-1, 2,0);
        tracep->declBus(c+1,"fexp fa0 out_num", false,-1, 31,0);
        tracep->declBit(c+9,"fexp fa0 largerMag", false,-1);
        tracep->declBit(c+10,"fexp fa0 finalSign", false,-1);
        tracep->declBus(c+11,"fexp fa0 num1Exp", false,-1, 7,0);
        tracep->declBus(c+12,"fexp fa0 num2Exp", false,-1, 7,0);
        tracep->declBus(c+13,"fexp fa0 finalExp", false,-1, 7,0);
        tracep->declBus(c+14,"fexp fa0 num1Mant", false,-1, 23,0);
        tracep->declBus(c+15,"fexp fa0 num2Mant", false,-1, 23,0);
        tracep->declBus(c+16,"fexp fa0 finalMant", false,-1, 23,0);
        tracep->declBus(c+17,"fexp fa0 sumMants", false,-1, 24,0);
        tracep->declBus(c+104,"fexp fa0 i", false,-1, 31,0);
        tracep->declBus(c+18,"fexp fa0 unrounded", false,-1, 31,0);
        tracep->declBus(c+18,"fexp fa0 r0 num1", false,-1, 31,0);
        tracep->declBus(c+103,"fexp fa0 r0 rm", false,-1, 2,0);
        tracep->declBus(c+1,"fexp fa0 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+1,"fexp fa0 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+19,"fexp fa0 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+105,"fexp fa0 r0 mask", false,-1, 22,0);
        tracep->declBus(c+106,"fexp fa0 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+107,"fexp fa0 r0 i", false,-1, 31,0);
        tracep->declBus(c+108,"fexp fa0 r0 j", false,-1, 31,0);
        tracep->declBus(c+91,"fexp fm0 num1", false,-1, 31,0);
        tracep->declBus(c+91,"fexp fm0 num2", false,-1, 31,0);
        tracep->declBus(c+103,"fexp fm0 rm", false,-1, 2,0);
        tracep->declBus(c+2,"fexp fm0 out_mul", false,-1, 31,0);
        tracep->declBit(c+93,"fexp fm0 sign", false,-1);
        tracep->declBus(c+20,"fexp fm0 expF", false,-1, 7,0);
        tracep->declBus(c+21,"fexp fm0 mantissa", false,-1, 23,0);
        tracep->declBus(c+94,"fexp fm0 mantissa1", false,-1, 23,0);
        tracep->declBus(c+94,"fexp fm0 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+22,"fexp fm0 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+109,"fexp fm0 i", false,-1, 31,0);
        tracep->declBus(c+24,"fexp fm0 r0 num1", false,-1, 31,0);
        tracep->declBus(c+103,"fexp fm0 r0 rm", false,-1, 2,0);
        tracep->declBus(c+2,"fexp fm0 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+2,"fexp fm0 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+25,"fexp fm0 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+110,"fexp fm0 r0 mask", false,-1, 22,0);
        tracep->declBus(c+111,"fexp fm0 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+112,"fexp fm0 r0 i", false,-1, 31,0);
        tracep->declBus(c+113,"fexp fm0 r0 j", false,-1, 31,0);
        tracep->declBus(c+2,"fexp fma0 a_fp", false,-1, 31,0);
        tracep->declBus(c+99,"fexp fma0 b_fp", false,-1, 31,0);
        tracep->declBus(c+1,"fexp fma0 c_fp", false,-1, 31,0);
        tracep->declBus(c+3,"fexp fma0 out_fp", false,-1, 31,0);
        tracep->declBit(c+26,"fexp fma0 sign_out", false,-1);
        tracep->declBit(c+27,"fexp fma0 largerMag", false,-1);
        tracep->declBus(c+28,"fexp fma0 exp_out", false,-1, 7,0);
        tracep->declBus(c+29,"fexp fma0 final_exp", false,-1, 7,0);
        tracep->declBus(c+30,"fexp fma0 mantissa_a", false,-1, 23,0);
        tracep->declBus(c+114,"fexp fma0 mantissa_b", false,-1, 23,0);
        tracep->declBus(c+31,"fexp fma0 mantissa_c", false,-1, 23,0);
        tracep->declBus(c+32,"fexp fma0 mantissa_mul_norm", false,-1, 23,0);
        tracep->declBus(c+33,"fexp fma0 final_mantissa", false,-1, 23,0);
        tracep->declQuad(c+34,"fexp fma0 mantissa_mul_out", false,-1, 47,0);
        tracep->declBus(c+36,"fexp fma0 sum_mants", false,-1, 24,0);
        tracep->declBus(c+2,"fexp fm1 num1", false,-1, 31,0);
        tracep->declBus(c+91,"fexp fm1 num2", false,-1, 31,0);
        tracep->declBus(c+103,"fexp fm1 rm", false,-1, 2,0);
        tracep->declBus(c+4,"fexp fm1 out_mul", false,-1, 31,0);
        tracep->declBit(c+95,"fexp fm1 sign", false,-1);
        tracep->declBus(c+37,"fexp fm1 expF", false,-1, 7,0);
        tracep->declBus(c+38,"fexp fm1 mantissa", false,-1, 23,0);
        tracep->declBus(c+39,"fexp fm1 mantissa1", false,-1, 23,0);
        tracep->declBus(c+94,"fexp fm1 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+40,"fexp fm1 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+109,"fexp fm1 i", false,-1, 31,0);
        tracep->declBus(c+42,"fexp fm1 r0 num1", false,-1, 31,0);
        tracep->declBus(c+103,"fexp fm1 r0 rm", false,-1, 2,0);
        tracep->declBus(c+4,"fexp fm1 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+4,"fexp fm1 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+43,"fexp fm1 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+115,"fexp fm1 r0 mask", false,-1, 22,0);
        tracep->declBus(c+116,"fexp fm1 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+117,"fexp fm1 r0 i", false,-1, 31,0);
        tracep->declBus(c+118,"fexp fm1 r0 j", false,-1, 31,0);
        tracep->declBus(c+4,"fexp fma1 a_fp", false,-1, 31,0);
        tracep->declBus(c+100,"fexp fma1 b_fp", false,-1, 31,0);
        tracep->declBus(c+3,"fexp fma1 c_fp", false,-1, 31,0);
        tracep->declBus(c+5,"fexp fma1 out_fp", false,-1, 31,0);
        tracep->declBit(c+44,"fexp fma1 sign_out", false,-1);
        tracep->declBit(c+45,"fexp fma1 largerMag", false,-1);
        tracep->declBus(c+46,"fexp fma1 exp_out", false,-1, 7,0);
        tracep->declBus(c+47,"fexp fma1 final_exp", false,-1, 7,0);
        tracep->declBus(c+48,"fexp fma1 mantissa_a", false,-1, 23,0);
        tracep->declBus(c+119,"fexp fma1 mantissa_b", false,-1, 23,0);
        tracep->declBus(c+49,"fexp fma1 mantissa_c", false,-1, 23,0);
        tracep->declBus(c+50,"fexp fma1 mantissa_mul_norm", false,-1, 23,0);
        tracep->declBus(c+51,"fexp fma1 final_mantissa", false,-1, 23,0);
        tracep->declQuad(c+52,"fexp fma1 mantissa_mul_out", false,-1, 47,0);
        tracep->declBus(c+54,"fexp fma1 sum_mants", false,-1, 24,0);
        tracep->declBus(c+4,"fexp fm2 num1", false,-1, 31,0);
        tracep->declBus(c+91,"fexp fm2 num2", false,-1, 31,0);
        tracep->declBus(c+103,"fexp fm2 rm", false,-1, 2,0);
        tracep->declBus(c+6,"fexp fm2 out_mul", false,-1, 31,0);
        tracep->declBit(c+96,"fexp fm2 sign", false,-1);
        tracep->declBus(c+55,"fexp fm2 expF", false,-1, 7,0);
        tracep->declBus(c+56,"fexp fm2 mantissa", false,-1, 23,0);
        tracep->declBus(c+57,"fexp fm2 mantissa1", false,-1, 23,0);
        tracep->declBus(c+94,"fexp fm2 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+58,"fexp fm2 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+109,"fexp fm2 i", false,-1, 31,0);
        tracep->declBus(c+60,"fexp fm2 r0 num1", false,-1, 31,0);
        tracep->declBus(c+103,"fexp fm2 r0 rm", false,-1, 2,0);
        tracep->declBus(c+6,"fexp fm2 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+6,"fexp fm2 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+61,"fexp fm2 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+120,"fexp fm2 r0 mask", false,-1, 22,0);
        tracep->declBus(c+121,"fexp fm2 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+122,"fexp fm2 r0 i", false,-1, 31,0);
        tracep->declBus(c+123,"fexp fm2 r0 j", false,-1, 31,0);
        tracep->declBus(c+6,"fexp fma2 a_fp", false,-1, 31,0);
        tracep->declBus(c+101,"fexp fma2 b_fp", false,-1, 31,0);
        tracep->declBus(c+5,"fexp fma2 c_fp", false,-1, 31,0);
        tracep->declBus(c+7,"fexp fma2 out_fp", false,-1, 31,0);
        tracep->declBit(c+62,"fexp fma2 sign_out", false,-1);
        tracep->declBit(c+63,"fexp fma2 largerMag", false,-1);
        tracep->declBus(c+64,"fexp fma2 exp_out", false,-1, 7,0);
        tracep->declBus(c+65,"fexp fma2 final_exp", false,-1, 7,0);
        tracep->declBus(c+66,"fexp fma2 mantissa_a", false,-1, 23,0);
        tracep->declBus(c+119,"fexp fma2 mantissa_b", false,-1, 23,0);
        tracep->declBus(c+67,"fexp fma2 mantissa_c", false,-1, 23,0);
        tracep->declBus(c+68,"fexp fma2 mantissa_mul_norm", false,-1, 23,0);
        tracep->declBus(c+69,"fexp fma2 final_mantissa", false,-1, 23,0);
        tracep->declQuad(c+70,"fexp fma2 mantissa_mul_out", false,-1, 47,0);
        tracep->declBus(c+72,"fexp fma2 sum_mants", false,-1, 24,0);
        tracep->declBus(c+6,"fexp fm3 num1", false,-1, 31,0);
        tracep->declBus(c+91,"fexp fm3 num2", false,-1, 31,0);
        tracep->declBus(c+103,"fexp fm3 rm", false,-1, 2,0);
        tracep->declBus(c+8,"fexp fm3 out_mul", false,-1, 31,0);
        tracep->declBit(c+97,"fexp fm3 sign", false,-1);
        tracep->declBus(c+73,"fexp fm3 expF", false,-1, 7,0);
        tracep->declBus(c+74,"fexp fm3 mantissa", false,-1, 23,0);
        tracep->declBus(c+75,"fexp fm3 mantissa1", false,-1, 23,0);
        tracep->declBus(c+94,"fexp fm3 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+76,"fexp fm3 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+109,"fexp fm3 i", false,-1, 31,0);
        tracep->declBus(c+78,"fexp fm3 r0 num1", false,-1, 31,0);
        tracep->declBus(c+103,"fexp fm3 r0 rm", false,-1, 2,0);
        tracep->declBus(c+8,"fexp fm3 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+8,"fexp fm3 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+79,"fexp fm3 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+124,"fexp fm3 r0 mask", false,-1, 22,0);
        tracep->declBus(c+125,"fexp fm3 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+126,"fexp fm3 r0 i", false,-1, 31,0);
        tracep->declBus(c+127,"fexp fm3 r0 j", false,-1, 31,0);
        tracep->declBus(c+8,"fexp fma3 a_fp", false,-1, 31,0);
        tracep->declBus(c+102,"fexp fma3 b_fp", false,-1, 31,0);
        tracep->declBus(c+7,"fexp fma3 c_fp", false,-1, 31,0);
        tracep->declBus(c+92,"fexp fma3 out_fp", false,-1, 31,0);
        tracep->declBit(c+80,"fexp fma3 sign_out", false,-1);
        tracep->declBit(c+81,"fexp fma3 largerMag", false,-1);
        tracep->declBus(c+82,"fexp fma3 exp_out", false,-1, 7,0);
        tracep->declBus(c+83,"fexp fma3 final_exp", false,-1, 7,0);
        tracep->declBus(c+84,"fexp fma3 mantissa_a", false,-1, 23,0);
        tracep->declBus(c+128,"fexp fma3 mantissa_b", false,-1, 23,0);
        tracep->declBus(c+85,"fexp fma3 mantissa_c", false,-1, 23,0);
        tracep->declBus(c+86,"fexp fma3 mantissa_mul_norm", false,-1, 23,0);
        tracep->declBus(c+87,"fexp fma3 final_mantissa", false,-1, 23,0);
        tracep->declQuad(c+88,"fexp fma3 mantissa_mul_out", false,-1, 47,0);
        tracep->declBus(c+90,"fexp fma3 sum_mants", false,-1, 24,0);
    }
}

void Vfexp::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vfexp::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vfexp__Syms* __restrict vlSymsp = static_cast<Vfexp__Syms*>(userp);
    Vfexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vfexp::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vfexp__Syms* __restrict vlSymsp = static_cast<Vfexp__Syms*>(userp);
    Vfexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->fexp__DOT__fa0__DOT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+2,(vlTOPp->fexp__DOT__fm0__DOT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+3,(vlTOPp->fexp__DOT__temp3),32);
        tracep->fullIData(oldp+4,(vlTOPp->fexp__DOT__fm1__DOT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+5,(vlTOPp->fexp__DOT__temp5),32);
        tracep->fullIData(oldp+6,(vlTOPp->fexp__DOT__fm2__DOT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+7,(vlTOPp->fexp__DOT__temp7),32);
        tracep->fullIData(oldp+8,(vlTOPp->fexp__DOT__fm3__DOT__r0__DOT__rounded),32);
        tracep->fullBit(oldp+9,(vlTOPp->fexp__DOT__fa0__DOT__largerMag));
        tracep->fullBit(oldp+10,(vlTOPp->fexp__DOT__fa0__DOT__finalSign));
        tracep->fullCData(oldp+11,(vlTOPp->fexp__DOT__fa0__DOT__num1Exp),8);
        tracep->fullCData(oldp+12,(vlTOPp->fexp__DOT__fa0__DOT__num2Exp),8);
        tracep->fullCData(oldp+13,(vlTOPp->fexp__DOT__fa0__DOT__finalExp),8);
        tracep->fullIData(oldp+14,(vlTOPp->fexp__DOT__fa0__DOT__num1Mant),24);
        tracep->fullIData(oldp+15,(vlTOPp->fexp__DOT__fa0__DOT__num2Mant),24);
        tracep->fullIData(oldp+16,(vlTOPp->fexp__DOT__fa0__DOT__finalMant),24);
        tracep->fullIData(oldp+17,(vlTOPp->fexp__DOT__fa0__DOT__sumMants),25);
        tracep->fullIData(oldp+18,(vlTOPp->fexp__DOT__fa0__DOT__unrounded),32);
        tracep->fullIData(oldp+19,(vlTOPp->fexp__DOT__fa0__DOT__r0__DOT__overflowCheck),24);
        tracep->fullCData(oldp+20,(vlTOPp->fexp__DOT__fm0__DOT__expF),8);
        tracep->fullIData(oldp+21,(vlTOPp->fexp__DOT__fm0__DOT__mantissa),24);
        tracep->fullQData(oldp+22,(vlTOPp->fexp__DOT__fm0__DOT__mantissaProd),48);
        tracep->fullIData(oldp+24,(vlTOPp->fexp__DOT__fm0__DOT____Vcellinp__r0____pinNumber1),32);
        tracep->fullIData(oldp+25,(vlTOPp->fexp__DOT__fm0__DOT__r0__DOT__overflowCheck),24);
        tracep->fullBit(oldp+26,(vlTOPp->fexp__DOT__fma0__DOT__sign_out));
        tracep->fullBit(oldp+27,(vlTOPp->fexp__DOT__fma0__DOT__largerMag));
        tracep->fullCData(oldp+28,(vlTOPp->fexp__DOT__fma0__DOT__exp_out),8);
        tracep->fullCData(oldp+29,(vlTOPp->fexp__DOT__fma0__DOT__final_exp),8);
        tracep->fullIData(oldp+30,(vlTOPp->fexp__DOT__fma0__DOT__mantissa_a),24);
        tracep->fullIData(oldp+31,(vlTOPp->fexp__DOT__fma0__DOT__mantissa_c),24);
        tracep->fullIData(oldp+32,(vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm),24);
        tracep->fullIData(oldp+33,(vlTOPp->fexp__DOT__fma0__DOT__final_mantissa),24);
        tracep->fullQData(oldp+34,(vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_out),48);
        tracep->fullIData(oldp+36,(vlTOPp->fexp__DOT__fma0__DOT__sum_mants),25);
        tracep->fullCData(oldp+37,(vlTOPp->fexp__DOT__fm1__DOT__expF),8);
        tracep->fullIData(oldp+38,(vlTOPp->fexp__DOT__fm1__DOT__mantissa),24);
        tracep->fullIData(oldp+39,(((0U == vlTOPp->fexp__DOT__fm0__DOT__r0__DOT__rounded)
                                     ? 0U : (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->fexp__DOT__fm0__DOT__r0__DOT__rounded)))),24);
        tracep->fullQData(oldp+40,(vlTOPp->fexp__DOT__fm1__DOT__mantissaProd),48);
        tracep->fullIData(oldp+42,(vlTOPp->fexp__DOT__fm1__DOT____Vcellinp__r0____pinNumber1),32);
        tracep->fullIData(oldp+43,(vlTOPp->fexp__DOT__fm1__DOT__r0__DOT__overflowCheck),24);
        tracep->fullBit(oldp+44,(vlTOPp->fexp__DOT__fma1__DOT__sign_out));
        tracep->fullBit(oldp+45,(vlTOPp->fexp__DOT__fma1__DOT__largerMag));
        tracep->fullCData(oldp+46,(vlTOPp->fexp__DOT__fma1__DOT__exp_out),8);
        tracep->fullCData(oldp+47,(vlTOPp->fexp__DOT__fma1__DOT__final_exp),8);
        tracep->fullIData(oldp+48,(vlTOPp->fexp__DOT__fma1__DOT__mantissa_a),24);
        tracep->fullIData(oldp+49,(vlTOPp->fexp__DOT__fma1__DOT__mantissa_c),24);
        tracep->fullIData(oldp+50,(vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm),24);
        tracep->fullIData(oldp+51,(vlTOPp->fexp__DOT__fma1__DOT__final_mantissa),24);
        tracep->fullQData(oldp+52,(vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_out),48);
        tracep->fullIData(oldp+54,(vlTOPp->fexp__DOT__fma1__DOT__sum_mants),25);
        tracep->fullCData(oldp+55,(vlTOPp->fexp__DOT__fm2__DOT__expF),8);
        tracep->fullIData(oldp+56,(vlTOPp->fexp__DOT__fm2__DOT__mantissa),24);
        tracep->fullIData(oldp+57,(((0U == vlTOPp->fexp__DOT__fm1__DOT__r0__DOT__rounded)
                                     ? 0U : (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->fexp__DOT__fm1__DOT__r0__DOT__rounded)))),24);
        tracep->fullQData(oldp+58,(vlTOPp->fexp__DOT__fm2__DOT__mantissaProd),48);
        tracep->fullIData(oldp+60,(vlTOPp->fexp__DOT__fm2__DOT____Vcellinp__r0____pinNumber1),32);
        tracep->fullIData(oldp+61,(vlTOPp->fexp__DOT__fm2__DOT__r0__DOT__overflowCheck),24);
        tracep->fullBit(oldp+62,(vlTOPp->fexp__DOT__fma2__DOT__sign_out));
        tracep->fullBit(oldp+63,(vlTOPp->fexp__DOT__fma2__DOT__largerMag));
        tracep->fullCData(oldp+64,(vlTOPp->fexp__DOT__fma2__DOT__exp_out),8);
        tracep->fullCData(oldp+65,(vlTOPp->fexp__DOT__fma2__DOT__final_exp),8);
        tracep->fullIData(oldp+66,(vlTOPp->fexp__DOT__fma2__DOT__mantissa_a),24);
        tracep->fullIData(oldp+67,(vlTOPp->fexp__DOT__fma2__DOT__mantissa_c),24);
        tracep->fullIData(oldp+68,(vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm),24);
        tracep->fullIData(oldp+69,(vlTOPp->fexp__DOT__fma2__DOT__final_mantissa),24);
        tracep->fullQData(oldp+70,(vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_out),48);
        tracep->fullIData(oldp+72,(vlTOPp->fexp__DOT__fma2__DOT__sum_mants),25);
        tracep->fullCData(oldp+73,(vlTOPp->fexp__DOT__fm3__DOT__expF),8);
        tracep->fullIData(oldp+74,(vlTOPp->fexp__DOT__fm3__DOT__mantissa),24);
        tracep->fullIData(oldp+75,(((0U == vlTOPp->fexp__DOT__fm2__DOT__r0__DOT__rounded)
                                     ? 0U : (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->fexp__DOT__fm2__DOT__r0__DOT__rounded)))),24);
        tracep->fullQData(oldp+76,(vlTOPp->fexp__DOT__fm3__DOT__mantissaProd),48);
        tracep->fullIData(oldp+78,(vlTOPp->fexp__DOT__fm3__DOT____Vcellinp__r0____pinNumber1),32);
        tracep->fullIData(oldp+79,(vlTOPp->fexp__DOT__fm3__DOT__r0__DOT__overflowCheck),24);
        tracep->fullBit(oldp+80,(vlTOPp->fexp__DOT__fma3__DOT__sign_out));
        tracep->fullBit(oldp+81,(vlTOPp->fexp__DOT__fma3__DOT__largerMag));
        tracep->fullCData(oldp+82,(vlTOPp->fexp__DOT__fma3__DOT__exp_out),8);
        tracep->fullCData(oldp+83,(vlTOPp->fexp__DOT__fma3__DOT__final_exp),8);
        tracep->fullIData(oldp+84,(vlTOPp->fexp__DOT__fma3__DOT__mantissa_a),24);
        tracep->fullIData(oldp+85,(vlTOPp->fexp__DOT__fma3__DOT__mantissa_c),24);
        tracep->fullIData(oldp+86,(vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm),24);
        tracep->fullIData(oldp+87,(vlTOPp->fexp__DOT__fma3__DOT__final_mantissa),24);
        tracep->fullQData(oldp+88,(vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_out),48);
        tracep->fullIData(oldp+90,(vlTOPp->fexp__DOT__fma3__DOT__sum_mants),25);
        tracep->fullIData(oldp+91,(vlTOPp->exp),32);
        tracep->fullIData(oldp+92,(vlTOPp->out_num),32);
        tracep->fullBit(oldp+93,(0U));
        tracep->fullIData(oldp+94,(((0U == vlTOPp->exp)
                                     ? 0U : (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->exp)))),24);
        tracep->fullBit(oldp+95,((1U & ((vlTOPp->fexp__DOT__fm0__DOT__r0__DOT__rounded 
                                         ^ vlTOPp->exp) 
                                        >> 0x1fU))));
        tracep->fullBit(oldp+96,((1U & ((vlTOPp->fexp__DOT__fm1__DOT__r0__DOT__rounded 
                                         ^ vlTOPp->exp) 
                                        >> 0x1fU))));
        tracep->fullBit(oldp+97,((1U & ((vlTOPp->fexp__DOT__fm2__DOT__r0__DOT__rounded 
                                         ^ vlTOPp->exp) 
                                        >> 0x1fU))));
        tracep->fullIData(oldp+98,(0x3f800000U),32);
        tracep->fullIData(oldp+99,(0x3f000000U),32);
        tracep->fullIData(oldp+100,(0x3e2aaaabU),32);
        tracep->fullIData(oldp+101,(0x3d2aaaabU),32);
        tracep->fullIData(oldp+102,(0x3c088889U),32);
        tracep->fullCData(oldp+103,(0U),3);
        tracep->fullIData(oldp+104,(vlTOPp->fexp__DOT__fa0__DOT__i),32);
        tracep->fullIData(oldp+105,(vlTOPp->fexp__DOT__fa0__DOT__r0__DOT__mask),23);
        tracep->fullIData(oldp+106,(vlTOPp->fexp__DOT__fa0__DOT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+107,(vlTOPp->fexp__DOT__fa0__DOT__r0__DOT__i),32);
        tracep->fullIData(oldp+108,(vlTOPp->fexp__DOT__fa0__DOT__r0__DOT__j),32);
        tracep->fullIData(oldp+109,(0U),32);
        tracep->fullIData(oldp+110,(vlTOPp->fexp__DOT__fm0__DOT__r0__DOT__mask),23);
        tracep->fullIData(oldp+111,(vlTOPp->fexp__DOT__fm0__DOT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+112,(vlTOPp->fexp__DOT__fm0__DOT__r0__DOT__i),32);
        tracep->fullIData(oldp+113,(vlTOPp->fexp__DOT__fm0__DOT__r0__DOT__j),32);
        tracep->fullIData(oldp+114,(0x800000U),24);
        tracep->fullIData(oldp+115,(vlTOPp->fexp__DOT__fm1__DOT__r0__DOT__mask),23);
        tracep->fullIData(oldp+116,(vlTOPp->fexp__DOT__fm1__DOT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+117,(vlTOPp->fexp__DOT__fm1__DOT__r0__DOT__i),32);
        tracep->fullIData(oldp+118,(vlTOPp->fexp__DOT__fm1__DOT__r0__DOT__j),32);
        tracep->fullIData(oldp+119,(0xaaaaabU),24);
        tracep->fullIData(oldp+120,(vlTOPp->fexp__DOT__fm2__DOT__r0__DOT__mask),23);
        tracep->fullIData(oldp+121,(vlTOPp->fexp__DOT__fm2__DOT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+122,(vlTOPp->fexp__DOT__fm2__DOT__r0__DOT__i),32);
        tracep->fullIData(oldp+123,(vlTOPp->fexp__DOT__fm2__DOT__r0__DOT__j),32);
        tracep->fullIData(oldp+124,(vlTOPp->fexp__DOT__fm3__DOT__r0__DOT__mask),23);
        tracep->fullIData(oldp+125,(vlTOPp->fexp__DOT__fm3__DOT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+126,(vlTOPp->fexp__DOT__fm3__DOT__r0__DOT__i),32);
        tracep->fullIData(oldp+127,(vlTOPp->fexp__DOT__fm3__DOT__r0__DOT__j),32);
        tracep->fullIData(oldp+128,(0x888889U),24);
    }
}
