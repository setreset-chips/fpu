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
        tracep->declBus(c+81,"exp", false,-1, 31,0);
        tracep->declBus(c+82,"out_num", false,-1, 31,0);
        tracep->declBus(c+81,"fexp exp", false,-1, 31,0);
        tracep->declBus(c+82,"fexp out_num", false,-1, 31,0);
        tracep->declBus(c+88,"fexp one", false,-1, 31,0);
        tracep->declBus(c+89,"fexp one_half", false,-1, 31,0);
        tracep->declBus(c+90,"fexp one_sixth", false,-1, 31,0);
        tracep->declBus(c+91,"fexp one_twenty_fourth", false,-1, 31,0);
        tracep->declBus(c+92,"fexp one_120th", false,-1, 31,0);
        tracep->declBus(c+1,"fexp temp1", false,-1, 31,0);
        tracep->declBus(c+2,"fexp temp2", false,-1, 31,0);
        tracep->declBus(c+3,"fexp temp3", false,-1, 31,0);
        tracep->declBus(c+4,"fexp temp4", false,-1, 31,0);
        tracep->declBus(c+5,"fexp temp5", false,-1, 31,0);
        tracep->declBus(c+6,"fexp temp6", false,-1, 31,0);
        tracep->declBus(c+7,"fexp temp7", false,-1, 31,0);
        tracep->declBus(c+8,"fexp temp8", false,-1, 31,0);
        tracep->declBus(c+88,"fexp fa0 num1", false,-1, 31,0);
        tracep->declBus(c+81,"fexp fa0 num2", false,-1, 31,0);
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
        tracep->declBus(c+93,"fexp fa0 i", false,-1, 31,0);
        tracep->declBus(c+81,"fexp fm0 num1", false,-1, 31,0);
        tracep->declBus(c+81,"fexp fm0 num2", false,-1, 31,0);
        tracep->declBus(c+2,"fexp fm0 out_mul", false,-1, 31,0);
        tracep->declBit(c+83,"fexp fm0 sign", false,-1);
        tracep->declBus(c+18,"fexp fm0 expF", false,-1, 7,0);
        tracep->declBus(c+19,"fexp fm0 mantissa", false,-1, 22,0);
        tracep->declBus(c+84,"fexp fm0 mantissa1", false,-1, 23,0);
        tracep->declBus(c+84,"fexp fm0 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+20,"fexp fm0 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+94,"fexp fm0 i", false,-1, 31,0);
        tracep->declBus(c+2,"fexp fma0 a_fp", false,-1, 31,0);
        tracep->declBus(c+89,"fexp fma0 b_fp", false,-1, 31,0);
        tracep->declBus(c+1,"fexp fma0 c_fp", false,-1, 31,0);
        tracep->declBus(c+3,"fexp fma0 out_fp", false,-1, 31,0);
        tracep->declBit(c+22,"fexp fma0 sign_out", false,-1);
        tracep->declBit(c+23,"fexp fma0 largerMag", false,-1);
        tracep->declBus(c+24,"fexp fma0 exp_out", false,-1, 7,0);
        tracep->declBus(c+25,"fexp fma0 final_exp", false,-1, 7,0);
        tracep->declBus(c+26,"fexp fma0 mantissa_a", false,-1, 23,0);
        tracep->declBus(c+95,"fexp fma0 mantissa_b", false,-1, 23,0);
        tracep->declBus(c+27,"fexp fma0 mantissa_c", false,-1, 23,0);
        tracep->declBus(c+28,"fexp fma0 mantissa_mul_norm", false,-1, 23,0);
        tracep->declBus(c+29,"fexp fma0 final_mantissa", false,-1, 23,0);
        tracep->declQuad(c+30,"fexp fma0 mantissa_mul_out", false,-1, 47,0);
        tracep->declBus(c+32,"fexp fma0 sum_mants", false,-1, 24,0);
        tracep->declBus(c+2,"fexp fm1 num1", false,-1, 31,0);
        tracep->declBus(c+81,"fexp fm1 num2", false,-1, 31,0);
        tracep->declBus(c+4,"fexp fm1 out_mul", false,-1, 31,0);
        tracep->declBit(c+85,"fexp fm1 sign", false,-1);
        tracep->declBus(c+33,"fexp fm1 expF", false,-1, 7,0);
        tracep->declBus(c+34,"fexp fm1 mantissa", false,-1, 22,0);
        tracep->declBus(c+35,"fexp fm1 mantissa1", false,-1, 23,0);
        tracep->declBus(c+84,"fexp fm1 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+36,"fexp fm1 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+94,"fexp fm1 i", false,-1, 31,0);
        tracep->declBus(c+4,"fexp fma1 a_fp", false,-1, 31,0);
        tracep->declBus(c+90,"fexp fma1 b_fp", false,-1, 31,0);
        tracep->declBus(c+3,"fexp fma1 c_fp", false,-1, 31,0);
        tracep->declBus(c+5,"fexp fma1 out_fp", false,-1, 31,0);
        tracep->declBit(c+38,"fexp fma1 sign_out", false,-1);
        tracep->declBit(c+39,"fexp fma1 largerMag", false,-1);
        tracep->declBus(c+40,"fexp fma1 exp_out", false,-1, 7,0);
        tracep->declBus(c+41,"fexp fma1 final_exp", false,-1, 7,0);
        tracep->declBus(c+42,"fexp fma1 mantissa_a", false,-1, 23,0);
        tracep->declBus(c+96,"fexp fma1 mantissa_b", false,-1, 23,0);
        tracep->declBus(c+43,"fexp fma1 mantissa_c", false,-1, 23,0);
        tracep->declBus(c+44,"fexp fma1 mantissa_mul_norm", false,-1, 23,0);
        tracep->declBus(c+45,"fexp fma1 final_mantissa", false,-1, 23,0);
        tracep->declQuad(c+46,"fexp fma1 mantissa_mul_out", false,-1, 47,0);
        tracep->declBus(c+48,"fexp fma1 sum_mants", false,-1, 24,0);
        tracep->declBus(c+4,"fexp fm2 num1", false,-1, 31,0);
        tracep->declBus(c+81,"fexp fm2 num2", false,-1, 31,0);
        tracep->declBus(c+6,"fexp fm2 out_mul", false,-1, 31,0);
        tracep->declBit(c+86,"fexp fm2 sign", false,-1);
        tracep->declBus(c+49,"fexp fm2 expF", false,-1, 7,0);
        tracep->declBus(c+50,"fexp fm2 mantissa", false,-1, 22,0);
        tracep->declBus(c+51,"fexp fm2 mantissa1", false,-1, 23,0);
        tracep->declBus(c+84,"fexp fm2 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+52,"fexp fm2 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+94,"fexp fm2 i", false,-1, 31,0);
        tracep->declBus(c+6,"fexp fma2 a_fp", false,-1, 31,0);
        tracep->declBus(c+91,"fexp fma2 b_fp", false,-1, 31,0);
        tracep->declBus(c+5,"fexp fma2 c_fp", false,-1, 31,0);
        tracep->declBus(c+7,"fexp fma2 out_fp", false,-1, 31,0);
        tracep->declBit(c+54,"fexp fma2 sign_out", false,-1);
        tracep->declBit(c+55,"fexp fma2 largerMag", false,-1);
        tracep->declBus(c+56,"fexp fma2 exp_out", false,-1, 7,0);
        tracep->declBus(c+57,"fexp fma2 final_exp", false,-1, 7,0);
        tracep->declBus(c+58,"fexp fma2 mantissa_a", false,-1, 23,0);
        tracep->declBus(c+96,"fexp fma2 mantissa_b", false,-1, 23,0);
        tracep->declBus(c+59,"fexp fma2 mantissa_c", false,-1, 23,0);
        tracep->declBus(c+60,"fexp fma2 mantissa_mul_norm", false,-1, 23,0);
        tracep->declBus(c+61,"fexp fma2 final_mantissa", false,-1, 23,0);
        tracep->declQuad(c+62,"fexp fma2 mantissa_mul_out", false,-1, 47,0);
        tracep->declBus(c+64,"fexp fma2 sum_mants", false,-1, 24,0);
        tracep->declBus(c+6,"fexp fm3 num1", false,-1, 31,0);
        tracep->declBus(c+81,"fexp fm3 num2", false,-1, 31,0);
        tracep->declBus(c+8,"fexp fm3 out_mul", false,-1, 31,0);
        tracep->declBit(c+87,"fexp fm3 sign", false,-1);
        tracep->declBus(c+65,"fexp fm3 expF", false,-1, 7,0);
        tracep->declBus(c+66,"fexp fm3 mantissa", false,-1, 22,0);
        tracep->declBus(c+67,"fexp fm3 mantissa1", false,-1, 23,0);
        tracep->declBus(c+84,"fexp fm3 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+68,"fexp fm3 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+94,"fexp fm3 i", false,-1, 31,0);
        tracep->declBus(c+8,"fexp fma3 a_fp", false,-1, 31,0);
        tracep->declBus(c+92,"fexp fma3 b_fp", false,-1, 31,0);
        tracep->declBus(c+7,"fexp fma3 c_fp", false,-1, 31,0);
        tracep->declBus(c+82,"fexp fma3 out_fp", false,-1, 31,0);
        tracep->declBit(c+70,"fexp fma3 sign_out", false,-1);
        tracep->declBit(c+71,"fexp fma3 largerMag", false,-1);
        tracep->declBus(c+72,"fexp fma3 exp_out", false,-1, 7,0);
        tracep->declBus(c+73,"fexp fma3 final_exp", false,-1, 7,0);
        tracep->declBus(c+74,"fexp fma3 mantissa_a", false,-1, 23,0);
        tracep->declBus(c+97,"fexp fma3 mantissa_b", false,-1, 23,0);
        tracep->declBus(c+75,"fexp fma3 mantissa_c", false,-1, 23,0);
        tracep->declBus(c+76,"fexp fma3 mantissa_mul_norm", false,-1, 23,0);
        tracep->declBus(c+77,"fexp fma3 final_mantissa", false,-1, 23,0);
        tracep->declQuad(c+78,"fexp fma3 mantissa_mul_out", false,-1, 47,0);
        tracep->declBus(c+80,"fexp fma3 sum_mants", false,-1, 24,0);
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
        tracep->fullIData(oldp+1,(vlTOPp->fexp__DOT__temp1),32);
        tracep->fullIData(oldp+2,(vlTOPp->fexp__DOT__temp2),32);
        tracep->fullIData(oldp+3,(vlTOPp->fexp__DOT__temp3),32);
        tracep->fullIData(oldp+4,(vlTOPp->fexp__DOT__temp4),32);
        tracep->fullIData(oldp+5,(vlTOPp->fexp__DOT__temp5),32);
        tracep->fullIData(oldp+6,(vlTOPp->fexp__DOT__temp6),32);
        tracep->fullIData(oldp+7,(vlTOPp->fexp__DOT__temp7),32);
        tracep->fullIData(oldp+8,(vlTOPp->fexp__DOT__temp8),32);
        tracep->fullBit(oldp+9,(vlTOPp->fexp__DOT__fa0__DOT__largerMag));
        tracep->fullBit(oldp+10,(vlTOPp->fexp__DOT__fa0__DOT__finalSign));
        tracep->fullCData(oldp+11,(vlTOPp->fexp__DOT__fa0__DOT__num1Exp),8);
        tracep->fullCData(oldp+12,(vlTOPp->fexp__DOT__fa0__DOT__num2Exp),8);
        tracep->fullCData(oldp+13,(vlTOPp->fexp__DOT__fa0__DOT__finalExp),8);
        tracep->fullIData(oldp+14,(vlTOPp->fexp__DOT__fa0__DOT__num1Mant),24);
        tracep->fullIData(oldp+15,(vlTOPp->fexp__DOT__fa0__DOT__num2Mant),24);
        tracep->fullIData(oldp+16,(vlTOPp->fexp__DOT__fa0__DOT__finalMant),24);
        tracep->fullIData(oldp+17,(vlTOPp->fexp__DOT__fa0__DOT__sumMants),25);
        tracep->fullCData(oldp+18,(vlTOPp->fexp__DOT__fm0__DOT__expF),8);
        tracep->fullIData(oldp+19,(vlTOPp->fexp__DOT__fm0__DOT__mantissa),23);
        tracep->fullQData(oldp+20,(vlTOPp->fexp__DOT__fm0__DOT__mantissaProd),48);
        tracep->fullBit(oldp+22,(vlTOPp->fexp__DOT__fma0__DOT__sign_out));
        tracep->fullBit(oldp+23,(vlTOPp->fexp__DOT__fma0__DOT__largerMag));
        tracep->fullCData(oldp+24,(vlTOPp->fexp__DOT__fma0__DOT__exp_out),8);
        tracep->fullCData(oldp+25,(vlTOPp->fexp__DOT__fma0__DOT__final_exp),8);
        tracep->fullIData(oldp+26,(vlTOPp->fexp__DOT__fma0__DOT__mantissa_a),24);
        tracep->fullIData(oldp+27,(vlTOPp->fexp__DOT__fma0__DOT__mantissa_c),24);
        tracep->fullIData(oldp+28,(vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm),24);
        tracep->fullIData(oldp+29,(vlTOPp->fexp__DOT__fma0__DOT__final_mantissa),24);
        tracep->fullQData(oldp+30,(vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_out),48);
        tracep->fullIData(oldp+32,(vlTOPp->fexp__DOT__fma0__DOT__sum_mants),25);
        tracep->fullCData(oldp+33,(vlTOPp->fexp__DOT__fm1__DOT__expF),8);
        tracep->fullIData(oldp+34,(vlTOPp->fexp__DOT__fm1__DOT__mantissa),23);
        tracep->fullIData(oldp+35,(((0U == vlTOPp->fexp__DOT__temp2)
                                     ? 0U : (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->fexp__DOT__temp2)))),24);
        tracep->fullQData(oldp+36,(vlTOPp->fexp__DOT__fm1__DOT__mantissaProd),48);
        tracep->fullBit(oldp+38,(vlTOPp->fexp__DOT__fma1__DOT__sign_out));
        tracep->fullBit(oldp+39,(vlTOPp->fexp__DOT__fma1__DOT__largerMag));
        tracep->fullCData(oldp+40,(vlTOPp->fexp__DOT__fma1__DOT__exp_out),8);
        tracep->fullCData(oldp+41,(vlTOPp->fexp__DOT__fma1__DOT__final_exp),8);
        tracep->fullIData(oldp+42,(vlTOPp->fexp__DOT__fma1__DOT__mantissa_a),24);
        tracep->fullIData(oldp+43,(vlTOPp->fexp__DOT__fma1__DOT__mantissa_c),24);
        tracep->fullIData(oldp+44,(vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm),24);
        tracep->fullIData(oldp+45,(vlTOPp->fexp__DOT__fma1__DOT__final_mantissa),24);
        tracep->fullQData(oldp+46,(vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_out),48);
        tracep->fullIData(oldp+48,(vlTOPp->fexp__DOT__fma1__DOT__sum_mants),25);
        tracep->fullCData(oldp+49,(vlTOPp->fexp__DOT__fm2__DOT__expF),8);
        tracep->fullIData(oldp+50,(vlTOPp->fexp__DOT__fm2__DOT__mantissa),23);
        tracep->fullIData(oldp+51,(((0U == vlTOPp->fexp__DOT__temp4)
                                     ? 0U : (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->fexp__DOT__temp4)))),24);
        tracep->fullQData(oldp+52,(vlTOPp->fexp__DOT__fm2__DOT__mantissaProd),48);
        tracep->fullBit(oldp+54,(vlTOPp->fexp__DOT__fma2__DOT__sign_out));
        tracep->fullBit(oldp+55,(vlTOPp->fexp__DOT__fma2__DOT__largerMag));
        tracep->fullCData(oldp+56,(vlTOPp->fexp__DOT__fma2__DOT__exp_out),8);
        tracep->fullCData(oldp+57,(vlTOPp->fexp__DOT__fma2__DOT__final_exp),8);
        tracep->fullIData(oldp+58,(vlTOPp->fexp__DOT__fma2__DOT__mantissa_a),24);
        tracep->fullIData(oldp+59,(vlTOPp->fexp__DOT__fma2__DOT__mantissa_c),24);
        tracep->fullIData(oldp+60,(vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm),24);
        tracep->fullIData(oldp+61,(vlTOPp->fexp__DOT__fma2__DOT__final_mantissa),24);
        tracep->fullQData(oldp+62,(vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_out),48);
        tracep->fullIData(oldp+64,(vlTOPp->fexp__DOT__fma2__DOT__sum_mants),25);
        tracep->fullCData(oldp+65,(vlTOPp->fexp__DOT__fm3__DOT__expF),8);
        tracep->fullIData(oldp+66,(vlTOPp->fexp__DOT__fm3__DOT__mantissa),23);
        tracep->fullIData(oldp+67,(((0U == vlTOPp->fexp__DOT__temp6)
                                     ? 0U : (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->fexp__DOT__temp6)))),24);
        tracep->fullQData(oldp+68,(vlTOPp->fexp__DOT__fm3__DOT__mantissaProd),48);
        tracep->fullBit(oldp+70,(vlTOPp->fexp__DOT__fma3__DOT__sign_out));
        tracep->fullBit(oldp+71,(vlTOPp->fexp__DOT__fma3__DOT__largerMag));
        tracep->fullCData(oldp+72,(vlTOPp->fexp__DOT__fma3__DOT__exp_out),8);
        tracep->fullCData(oldp+73,(vlTOPp->fexp__DOT__fma3__DOT__final_exp),8);
        tracep->fullIData(oldp+74,(vlTOPp->fexp__DOT__fma3__DOT__mantissa_a),24);
        tracep->fullIData(oldp+75,(vlTOPp->fexp__DOT__fma3__DOT__mantissa_c),24);
        tracep->fullIData(oldp+76,(vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm),24);
        tracep->fullIData(oldp+77,(vlTOPp->fexp__DOT__fma3__DOT__final_mantissa),24);
        tracep->fullQData(oldp+78,(vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_out),48);
        tracep->fullIData(oldp+80,(vlTOPp->fexp__DOT__fma3__DOT__sum_mants),25);
        tracep->fullIData(oldp+81,(vlTOPp->exp),32);
        tracep->fullIData(oldp+82,(vlTOPp->out_num),32);
        tracep->fullBit(oldp+83,(0U));
        tracep->fullIData(oldp+84,(((0U == vlTOPp->exp)
                                     ? 0U : (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->exp)))),24);
        tracep->fullBit(oldp+85,((1U & ((vlTOPp->fexp__DOT__temp2 
                                         ^ vlTOPp->exp) 
                                        >> 0x1fU))));
        tracep->fullBit(oldp+86,((1U & ((vlTOPp->fexp__DOT__temp4 
                                         ^ vlTOPp->exp) 
                                        >> 0x1fU))));
        tracep->fullBit(oldp+87,((1U & ((vlTOPp->fexp__DOT__temp6 
                                         ^ vlTOPp->exp) 
                                        >> 0x1fU))));
        tracep->fullIData(oldp+88,(0x3f800000U),32);
        tracep->fullIData(oldp+89,(0x3f000000U),32);
        tracep->fullIData(oldp+90,(0x3e2aaaabU),32);
        tracep->fullIData(oldp+91,(0x3d2aaaabU),32);
        tracep->fullIData(oldp+92,(0x3c088889U),32);
        tracep->fullIData(oldp+93,(vlTOPp->fexp__DOT__fa0__DOT__i),32);
        tracep->fullIData(oldp+94,(0U),32);
        tracep->fullIData(oldp+95,(0x800000U),24);
        tracep->fullIData(oldp+96,(0xaaaaabU),24);
        tracep->fullIData(oldp+97,(0x888889U),24);
    }
}
