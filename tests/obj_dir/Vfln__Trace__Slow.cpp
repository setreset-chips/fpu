// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfln__Syms.h"


//======================

void Vfln::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vfln::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vfln__Syms* __restrict vlSymsp = static_cast<Vfln__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vfln::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vfln::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vfln__Syms* __restrict vlSymsp = static_cast<Vfln__Syms*>(userp);
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vfln::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vfln__Syms* __restrict vlSymsp = static_cast<Vfln__Syms*>(userp);
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+101,"num1", false,-1, 31,0);
        tracep->declBus(c+102,"out1", false,-1, 31,0);
        tracep->declBus(c+101,"fln num1", false,-1, 31,0);
        tracep->declBus(c+102,"fln out1", false,-1, 31,0);
        tracep->declBit(c+103,"fln nanFlag", false,-1);
        tracep->declBus(c+104,"fln op1", false,-1, 31,0);
        tracep->declBus(c+1,"fln temp1", false,-1, 31,0);
        tracep->declBus(c+2,"fln temp2", false,-1, 31,0);
        tracep->declBus(c+3,"fln temp3", false,-1, 31,0);
        tracep->declBus(c+4,"fln temp4", false,-1, 31,0);
        tracep->declBus(c+5,"fln temp5", false,-1, 31,0);
        tracep->declBus(c+6,"fln temp6", false,-1, 31,0);
        tracep->declBus(c+7,"fln temp7", false,-1, 31,0);
        tracep->declBus(c+8,"fln temp8", false,-1, 31,0);
        tracep->declBus(c+9,"fln op1i", false,-1, 31,0);
        tracep->declBus(c+10,"fln temp9", false,-1, 31,0);
        tracep->declBus(c+11,"fln temp10", false,-1, 31,0);
        tracep->declBus(c+104,"fln fa0 num1", false,-1, 31,0);
        tracep->declBus(c+105,"fln fa0 num2", false,-1, 31,0);
        tracep->declBus(c+9,"fln fa0 out_num", false,-1, 31,0);
        tracep->declBit(c+12,"fln fa0 largerMag", false,-1);
        tracep->declBit(c+13,"fln fa0 finalSign", false,-1);
        tracep->declBus(c+14,"fln fa0 num1Exp", false,-1, 7,0);
        tracep->declBus(c+15,"fln fa0 num2Exp", false,-1, 7,0);
        tracep->declBus(c+16,"fln fa0 finalExp", false,-1, 7,0);
        tracep->declBus(c+17,"fln fa0 num1Mant", false,-1, 23,0);
        tracep->declBus(c+18,"fln fa0 num2Mant", false,-1, 23,0);
        tracep->declBus(c+19,"fln fa0 finalMant", false,-1, 23,0);
        tracep->declBus(c+20,"fln fa0 sumMants", false,-1, 24,0);
        tracep->declBus(c+106,"fln fa0 i", false,-1, 31,0);
        tracep->declBus(c+9,"fln fm0 num1", false,-1, 31,0);
        tracep->declBus(c+9,"fln fm0 num2", false,-1, 31,0);
        tracep->declBus(c+1,"fln fm0 out_mul", false,-1, 31,0);
        tracep->declBit(c+21,"fln fm0 sign", false,-1);
        tracep->declBus(c+22,"fln fm0 expF", false,-1, 7,0);
        tracep->declBus(c+23,"fln fm0 mantissa", false,-1, 22,0);
        tracep->declBus(c+24,"fln fm0 mantissa1", false,-1, 23,0);
        tracep->declBus(c+24,"fln fm0 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+25,"fln fm0 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+27,"fln fm0 i", false,-1, 31,0);
        tracep->declBus(c+1,"fln fm1 num1", false,-1, 31,0);
        tracep->declBus(c+107,"fln fm1 num2", false,-1, 31,0);
        tracep->declBus(c+2,"fln fm1 out_mul", false,-1, 31,0);
        tracep->declBit(c+28,"fln fm1 sign", false,-1);
        tracep->declBus(c+29,"fln fm1 expF", false,-1, 7,0);
        tracep->declBus(c+30,"fln fm1 mantissa", false,-1, 22,0);
        tracep->declBus(c+31,"fln fm1 mantissa1", false,-1, 23,0);
        tracep->declBus(c+108,"fln fm1 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+32,"fln fm1 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+34,"fln fm1 i", false,-1, 31,0);
        tracep->declBus(c+1,"fln fm2 num1", false,-1, 31,0);
        tracep->declBus(c+9,"fln fm2 num2", false,-1, 31,0);
        tracep->declBus(c+3,"fln fm2 out_mul", false,-1, 31,0);
        tracep->declBit(c+35,"fln fm2 sign", false,-1);
        tracep->declBus(c+36,"fln fm2 expF", false,-1, 7,0);
        tracep->declBus(c+37,"fln fm2 mantissa", false,-1, 22,0);
        tracep->declBus(c+31,"fln fm2 mantissa1", false,-1, 23,0);
        tracep->declBus(c+24,"fln fm2 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+38,"fln fm2 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+40,"fln fm2 i", false,-1, 31,0);
        tracep->declBus(c+3,"fln fm3 num1", false,-1, 31,0);
        tracep->declBus(c+109,"fln fm3 num2", false,-1, 31,0);
        tracep->declBus(c+4,"fln fm3 out_mul", false,-1, 31,0);
        tracep->declBit(c+41,"fln fm3 sign", false,-1);
        tracep->declBus(c+42,"fln fm3 expF", false,-1, 7,0);
        tracep->declBus(c+43,"fln fm3 mantissa", false,-1, 22,0);
        tracep->declBus(c+44,"fln fm3 mantissa1", false,-1, 23,0);
        tracep->declBus(c+110,"fln fm3 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+45,"fln fm3 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+47,"fln fm3 i", false,-1, 31,0);
        tracep->declBus(c+3,"fln fm4 num1", false,-1, 31,0);
        tracep->declBus(c+9,"fln fm4 num2", false,-1, 31,0);
        tracep->declBus(c+5,"fln fm4 out_mul", false,-1, 31,0);
        tracep->declBit(c+48,"fln fm4 sign", false,-1);
        tracep->declBus(c+49,"fln fm4 expF", false,-1, 7,0);
        tracep->declBus(c+50,"fln fm4 mantissa", false,-1, 22,0);
        tracep->declBus(c+44,"fln fm4 mantissa1", false,-1, 23,0);
        tracep->declBus(c+24,"fln fm4 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+51,"fln fm4 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+53,"fln fm4 i", false,-1, 31,0);
        tracep->declBus(c+5,"fln fma1 a_fp", false,-1, 31,0);
        tracep->declBus(c+111,"fln fma1 b_fp", false,-1, 31,0);
        tracep->declBus(c+4,"fln fma1 c_fp", false,-1, 31,0);
        tracep->declBus(c+6,"fln fma1 out_fp", false,-1, 31,0);
        tracep->declBit(c+54,"fln fma1 sign_out", false,-1);
        tracep->declBit(c+55,"fln fma1 largerMag", false,-1);
        tracep->declBus(c+56,"fln fma1 exp_out", false,-1, 7,0);
        tracep->declBus(c+57,"fln fma1 final_exp", false,-1, 7,0);
        tracep->declBus(c+58,"fln fma1 mantissa_a", false,-1, 23,0);
        tracep->declBus(c+108,"fln fma1 mantissa_b", false,-1, 23,0);
        tracep->declBus(c+59,"fln fma1 mantissa_c", false,-1, 23,0);
        tracep->declBus(c+60,"fln fma1 mantissa_mul_norm", false,-1, 23,0);
        tracep->declBus(c+61,"fln fma1 final_mantissa", false,-1, 23,0);
        tracep->declQuad(c+62,"fln fma1 mantissa_mul_out", false,-1, 47,0);
        tracep->declBus(c+64,"fln fma1 sum_mants", false,-1, 24,0);
        tracep->declBus(c+6,"fln fa1 num1", false,-1, 31,0);
        tracep->declBus(c+2,"fln fa1 num2", false,-1, 31,0);
        tracep->declBus(c+7,"fln fa1 out_num", false,-1, 31,0);
        tracep->declBit(c+65,"fln fa1 largerMag", false,-1);
        tracep->declBit(c+66,"fln fa1 finalSign", false,-1);
        tracep->declBus(c+67,"fln fa1 num1Exp", false,-1, 7,0);
        tracep->declBus(c+68,"fln fa1 num2Exp", false,-1, 7,0);
        tracep->declBus(c+69,"fln fa1 finalExp", false,-1, 7,0);
        tracep->declBus(c+70,"fln fa1 num1Mant", false,-1, 23,0);
        tracep->declBus(c+71,"fln fa1 num2Mant", false,-1, 23,0);
        tracep->declBus(c+72,"fln fa1 finalMant", false,-1, 23,0);
        tracep->declBus(c+73,"fln fa1 sumMants", false,-1, 24,0);
        tracep->declBus(c+112,"fln fa1 i", false,-1, 31,0);
        tracep->declBus(c+7,"fln fa2 num1", false,-1, 31,0);
        tracep->declBus(c+9,"fln fa2 num2", false,-1, 31,0);
        tracep->declBus(c+8,"fln fa2 out_num", false,-1, 31,0);
        tracep->declBit(c+74,"fln fa2 largerMag", false,-1);
        tracep->declBit(c+75,"fln fa2 finalSign", false,-1);
        tracep->declBus(c+76,"fln fa2 num1Exp", false,-1, 7,0);
        tracep->declBus(c+77,"fln fa2 num2Exp", false,-1, 7,0);
        tracep->declBus(c+78,"fln fa2 finalExp", false,-1, 7,0);
        tracep->declBus(c+79,"fln fa2 num1Mant", false,-1, 23,0);
        tracep->declBus(c+80,"fln fa2 num2Mant", false,-1, 23,0);
        tracep->declBus(c+81,"fln fa2 finalMant", false,-1, 23,0);
        tracep->declBus(c+82,"fln fa2 sumMants", false,-1, 24,0);
        tracep->declBus(c+113,"fln fa2 i", false,-1, 31,0);
        tracep->declBus(c+4,"fln fm5 num1", false,-1, 31,0);
        tracep->declBus(c+9,"fln fm5 num2", false,-1, 31,0);
        tracep->declBus(c+10,"fln fm5 out_mul", false,-1, 31,0);
        tracep->declBit(c+83,"fln fm5 sign", false,-1);
        tracep->declBus(c+84,"fln fm5 expF", false,-1, 7,0);
        tracep->declBus(c+85,"fln fm5 mantissa", false,-1, 22,0);
        tracep->declBus(c+86,"fln fm5 mantissa1", false,-1, 23,0);
        tracep->declBus(c+24,"fln fm5 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+87,"fln fm5 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+89,"fln fm5 i", false,-1, 31,0);
        tracep->declBus(c+10,"fln fma2 a_fp", false,-1, 31,0);
        tracep->declBus(c+114,"fln fma2 b_fp", false,-1, 31,0);
        tracep->declBus(c+8,"fln fma2 c_fp", false,-1, 31,0);
        tracep->declBus(c+11,"fln fma2 out_fp", false,-1, 31,0);
        tracep->declBit(c+90,"fln fma2 sign_out", false,-1);
        tracep->declBit(c+91,"fln fma2 largerMag", false,-1);
        tracep->declBus(c+92,"fln fma2 exp_out", false,-1, 7,0);
        tracep->declBus(c+93,"fln fma2 final_exp", false,-1, 7,0);
        tracep->declBus(c+94,"fln fma2 mantissa_a", false,-1, 23,0);
        tracep->declBus(c+115,"fln fma2 mantissa_b", false,-1, 23,0);
        tracep->declBus(c+95,"fln fma2 mantissa_c", false,-1, 23,0);
        tracep->declBus(c+96,"fln fma2 mantissa_mul_norm", false,-1, 23,0);
        tracep->declBus(c+97,"fln fma2 final_mantissa", false,-1, 23,0);
        tracep->declQuad(c+98,"fln fma2 mantissa_mul_out", false,-1, 47,0);
        tracep->declBus(c+100,"fln fma2 sum_mants", false,-1, 24,0);
    }
}

void Vfln::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vfln::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vfln__Syms* __restrict vlSymsp = static_cast<Vfln__Syms*>(userp);
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vfln::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vfln__Syms* __restrict vlSymsp = static_cast<Vfln__Syms*>(userp);
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->fln__DOT__temp1),32);
        tracep->fullIData(oldp+2,(vlTOPp->fln__DOT__temp2),32);
        tracep->fullIData(oldp+3,(vlTOPp->fln__DOT__temp3),32);
        tracep->fullIData(oldp+4,(vlTOPp->fln__DOT__temp4),32);
        tracep->fullIData(oldp+5,(vlTOPp->fln__DOT__temp5),32);
        tracep->fullIData(oldp+6,(vlTOPp->fln__DOT__temp6),32);
        tracep->fullIData(oldp+7,(vlTOPp->fln__DOT__temp7),32);
        tracep->fullIData(oldp+8,(vlTOPp->fln__DOT__temp8),32);
        tracep->fullIData(oldp+9,(vlTOPp->fln__DOT__op1i),32);
        tracep->fullIData(oldp+10,(vlTOPp->fln__DOT__temp9),32);
        tracep->fullIData(oldp+11,(((0x80000000U & 
                                     ((~ (IData)(vlTOPp->fln__DOT__fma2__DOT__sign_out)) 
                                      << 0x1fU)) | 
                                    (((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                      << 0x17U) | (0x7fffffU 
                                                   & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                      >> 1U))))),32);
        tracep->fullBit(oldp+12,(vlTOPp->fln__DOT__fa0__DOT__largerMag));
        tracep->fullBit(oldp+13,(vlTOPp->fln__DOT__fa0__DOT__finalSign));
        tracep->fullCData(oldp+14,(vlTOPp->fln__DOT__fa0__DOT__num1Exp),8);
        tracep->fullCData(oldp+15,(vlTOPp->fln__DOT__fa0__DOT__num2Exp),8);
        tracep->fullCData(oldp+16,(vlTOPp->fln__DOT__fa0__DOT__finalExp),8);
        tracep->fullIData(oldp+17,(vlTOPp->fln__DOT__fa0__DOT__num1Mant),24);
        tracep->fullIData(oldp+18,(vlTOPp->fln__DOT__fa0__DOT__num2Mant),24);
        tracep->fullIData(oldp+19,(vlTOPp->fln__DOT__fa0__DOT__finalMant),24);
        tracep->fullIData(oldp+20,(vlTOPp->fln__DOT__fa0__DOT__sumMants),25);
        tracep->fullBit(oldp+21,(0U));
        tracep->fullCData(oldp+22,(vlTOPp->fln__DOT__fm0__DOT__expF),8);
        tracep->fullIData(oldp+23,(vlTOPp->fln__DOT__fm0__DOT__mantissa),23);
        tracep->fullIData(oldp+24,((0x800000U | (0x7fffffU 
                                                 & vlTOPp->fln__DOT__op1i))),24);
        tracep->fullQData(oldp+25,(vlTOPp->fln__DOT__fm0__DOT__mantissaProd),48);
        tracep->fullIData(oldp+27,(vlTOPp->fln__DOT__fm0__DOT__i),32);
        tracep->fullBit(oldp+28,((1U & (~ (vlTOPp->fln__DOT__temp1 
                                           >> 0x1fU)))));
        tracep->fullCData(oldp+29,(vlTOPp->fln__DOT__fm1__DOT__expF),8);
        tracep->fullIData(oldp+30,(vlTOPp->fln__DOT__fm1__DOT__mantissa),23);
        tracep->fullIData(oldp+31,((0x800000U | (0x7fffffU 
                                                 & vlTOPp->fln__DOT__temp1))),24);
        tracep->fullQData(oldp+32,(vlTOPp->fln__DOT__fm1__DOT__mantissaProd),48);
        tracep->fullIData(oldp+34,(vlTOPp->fln__DOT__fm1__DOT__i),32);
        tracep->fullBit(oldp+35,((1U & ((vlTOPp->fln__DOT__temp1 
                                         ^ vlTOPp->fln__DOT__op1i) 
                                        >> 0x1fU))));
        tracep->fullCData(oldp+36,(vlTOPp->fln__DOT__fm2__DOT__expF),8);
        tracep->fullIData(oldp+37,(vlTOPp->fln__DOT__fm2__DOT__mantissa),23);
        tracep->fullQData(oldp+38,(vlTOPp->fln__DOT__fm2__DOT__mantissaProd),48);
        tracep->fullIData(oldp+40,(vlTOPp->fln__DOT__fm2__DOT__i),32);
        tracep->fullBit(oldp+41,((1U & (vlTOPp->fln__DOT__temp3 
                                        >> 0x1fU))));
        tracep->fullCData(oldp+42,(vlTOPp->fln__DOT__fm3__DOT__expF),8);
        tracep->fullIData(oldp+43,(vlTOPp->fln__DOT__fm3__DOT__mantissa),23);
        tracep->fullIData(oldp+44,((0x800000U | (0x7fffffU 
                                                 & vlTOPp->fln__DOT__temp3))),24);
        tracep->fullQData(oldp+45,(vlTOPp->fln__DOT__fm3__DOT__mantissaProd),48);
        tracep->fullIData(oldp+47,(vlTOPp->fln__DOT__fm3__DOT__i),32);
        tracep->fullBit(oldp+48,((1U & ((vlTOPp->fln__DOT__temp3 
                                         ^ vlTOPp->fln__DOT__op1i) 
                                        >> 0x1fU))));
        tracep->fullCData(oldp+49,(vlTOPp->fln__DOT__fm4__DOT__expF),8);
        tracep->fullIData(oldp+50,(vlTOPp->fln__DOT__fm4__DOT__mantissa),23);
        tracep->fullQData(oldp+51,(vlTOPp->fln__DOT__fm4__DOT__mantissaProd),48);
        tracep->fullIData(oldp+53,(vlTOPp->fln__DOT__fm4__DOT__i),32);
        tracep->fullBit(oldp+54,(vlTOPp->fln__DOT__fma1__DOT__sign_out));
        tracep->fullBit(oldp+55,(vlTOPp->fln__DOT__fma1__DOT__largerMag));
        tracep->fullCData(oldp+56,(vlTOPp->fln__DOT__fma1__DOT__exp_out),8);
        tracep->fullCData(oldp+57,(vlTOPp->fln__DOT__fma1__DOT__final_exp),8);
        tracep->fullIData(oldp+58,(vlTOPp->fln__DOT__fma1__DOT__mantissa_a),24);
        tracep->fullIData(oldp+59,(vlTOPp->fln__DOT__fma1__DOT__mantissa_c),24);
        tracep->fullIData(oldp+60,(vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm),24);
        tracep->fullIData(oldp+61,(vlTOPp->fln__DOT__fma1__DOT__final_mantissa),24);
        tracep->fullQData(oldp+62,(vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_out),48);
        tracep->fullIData(oldp+64,(vlTOPp->fln__DOT__fma1__DOT__sum_mants),25);
        tracep->fullBit(oldp+65,(vlTOPp->fln__DOT__fa1__DOT__largerMag));
        tracep->fullBit(oldp+66,(vlTOPp->fln__DOT__fa1__DOT__finalSign));
        tracep->fullCData(oldp+67,(vlTOPp->fln__DOT__fa1__DOT__num1Exp),8);
        tracep->fullCData(oldp+68,(vlTOPp->fln__DOT__fa1__DOT__num2Exp),8);
        tracep->fullCData(oldp+69,(vlTOPp->fln__DOT__fa1__DOT__finalExp),8);
        tracep->fullIData(oldp+70,(vlTOPp->fln__DOT__fa1__DOT__num1Mant),24);
        tracep->fullIData(oldp+71,(vlTOPp->fln__DOT__fa1__DOT__num2Mant),24);
        tracep->fullIData(oldp+72,(vlTOPp->fln__DOT__fa1__DOT__finalMant),24);
        tracep->fullIData(oldp+73,(vlTOPp->fln__DOT__fa1__DOT__sumMants),25);
        tracep->fullBit(oldp+74,(vlTOPp->fln__DOT__fa2__DOT__largerMag));
        tracep->fullBit(oldp+75,(vlTOPp->fln__DOT__fa2__DOT__finalSign));
        tracep->fullCData(oldp+76,(vlTOPp->fln__DOT__fa2__DOT__num1Exp),8);
        tracep->fullCData(oldp+77,(vlTOPp->fln__DOT__fa2__DOT__num2Exp),8);
        tracep->fullCData(oldp+78,(vlTOPp->fln__DOT__fa2__DOT__finalExp),8);
        tracep->fullIData(oldp+79,(vlTOPp->fln__DOT__fa2__DOT__num1Mant),24);
        tracep->fullIData(oldp+80,(vlTOPp->fln__DOT__fa2__DOT__num2Mant),24);
        tracep->fullIData(oldp+81,(vlTOPp->fln__DOT__fa2__DOT__finalMant),24);
        tracep->fullIData(oldp+82,(vlTOPp->fln__DOT__fa2__DOT__sumMants),25);
        tracep->fullBit(oldp+83,((1U & ((vlTOPp->fln__DOT__temp4 
                                         ^ vlTOPp->fln__DOT__op1i) 
                                        >> 0x1fU))));
        tracep->fullCData(oldp+84,(vlTOPp->fln__DOT__fm5__DOT__expF),8);
        tracep->fullIData(oldp+85,(vlTOPp->fln__DOT__fm5__DOT__mantissa),23);
        tracep->fullIData(oldp+86,((0x800000U | (0x7fffffU 
                                                 & vlTOPp->fln__DOT__temp4))),24);
        tracep->fullQData(oldp+87,(vlTOPp->fln__DOT__fm5__DOT__mantissaProd),48);
        tracep->fullIData(oldp+89,(vlTOPp->fln__DOT__fm5__DOT__i),32);
        tracep->fullBit(oldp+90,(vlTOPp->fln__DOT__fma2__DOT__sign_out));
        tracep->fullBit(oldp+91,(vlTOPp->fln__DOT__fma2__DOT__largerMag));
        tracep->fullCData(oldp+92,(vlTOPp->fln__DOT__fma2__DOT__exp_out),8);
        tracep->fullCData(oldp+93,(vlTOPp->fln__DOT__fma2__DOT__final_exp),8);
        tracep->fullIData(oldp+94,(vlTOPp->fln__DOT__fma2__DOT__mantissa_a),24);
        tracep->fullIData(oldp+95,(vlTOPp->fln__DOT__fma2__DOT__mantissa_c),24);
        tracep->fullIData(oldp+96,(vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm),24);
        tracep->fullIData(oldp+97,(vlTOPp->fln__DOT__fma2__DOT__final_mantissa),24);
        tracep->fullQData(oldp+98,(vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_out),48);
        tracep->fullIData(oldp+100,(vlTOPp->fln__DOT__fma2__DOT__sum_mants),25);
        tracep->fullIData(oldp+101,(vlTOPp->num1),32);
        tracep->fullIData(oldp+102,(vlTOPp->out1),32);
        tracep->fullBit(oldp+103,((1U & (vlTOPp->num1 
                                         >> 0x1fU))));
        tracep->fullIData(oldp+104,((0x7fffffffU & vlTOPp->num1)),32);
        tracep->fullIData(oldp+105,(0xbf800000U),32);
        tracep->fullIData(oldp+106,(vlTOPp->fln__DOT__fa0__DOT__i),32);
        tracep->fullIData(oldp+107,(0xbf000000U),32);
        tracep->fullIData(oldp+108,(0x800000U),24);
        tracep->fullIData(oldp+109,(0x3eaaaaabU),32);
        tracep->fullIData(oldp+110,(0xaaaaabU),24);
        tracep->fullIData(oldp+111,(0xbe800000U),32);
        tracep->fullIData(oldp+112,(vlTOPp->fln__DOT__fa1__DOT__i),32);
        tracep->fullIData(oldp+113,(vlTOPp->fln__DOT__fa2__DOT__i),32);
        tracep->fullIData(oldp+114,(0x3e4ccccdU),32);
        tracep->fullIData(oldp+115,(0xcccccdU),24);
    }
}
