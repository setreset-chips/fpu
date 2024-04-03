// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfexp__Syms.h"


void Vfexp::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vfexp__Syms* __restrict vlSymsp = static_cast<Vfexp__Syms*>(userp);
    Vfexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vfexp::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vfexp__Syms* __restrict vlSymsp = static_cast<Vfexp__Syms*>(userp);
    Vfexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+0,(vlTOPp->fexp__DOT__fa0__DOT__r0__DOT__rounded),32);
            tracep->chgIData(oldp+1,(vlTOPp->fexp__DOT__fm0__DOT__r0__DOT__rounded),32);
            tracep->chgIData(oldp+2,(vlTOPp->fexp__DOT__temp3),32);
            tracep->chgIData(oldp+3,(vlTOPp->fexp__DOT__fm1__DOT__r0__DOT__rounded),32);
            tracep->chgIData(oldp+4,(vlTOPp->fexp__DOT__temp5),32);
            tracep->chgIData(oldp+5,(vlTOPp->fexp__DOT__fm2__DOT__r0__DOT__rounded),32);
            tracep->chgIData(oldp+6,(vlTOPp->fexp__DOT__temp7),32);
            tracep->chgIData(oldp+7,(vlTOPp->fexp__DOT__fm3__DOT__r0__DOT__rounded),32);
            tracep->chgBit(oldp+8,(vlTOPp->fexp__DOT__fa0__DOT__largerMag));
            tracep->chgBit(oldp+9,(vlTOPp->fexp__DOT__fa0__DOT__finalSign));
            tracep->chgCData(oldp+10,(vlTOPp->fexp__DOT__fa0__DOT__num1Exp),8);
            tracep->chgCData(oldp+11,(vlTOPp->fexp__DOT__fa0__DOT__num2Exp),8);
            tracep->chgCData(oldp+12,(vlTOPp->fexp__DOT__fa0__DOT__finalExp),8);
            tracep->chgIData(oldp+13,(vlTOPp->fexp__DOT__fa0__DOT__num1Mant),24);
            tracep->chgIData(oldp+14,(vlTOPp->fexp__DOT__fa0__DOT__num2Mant),24);
            tracep->chgIData(oldp+15,(vlTOPp->fexp__DOT__fa0__DOT__finalMant),24);
            tracep->chgIData(oldp+16,(vlTOPp->fexp__DOT__fa0__DOT__sumMants),25);
            tracep->chgIData(oldp+17,(vlTOPp->fexp__DOT__fa0__DOT__unrounded),32);
            tracep->chgIData(oldp+18,(vlTOPp->fexp__DOT__fa0__DOT__r0__DOT__overflowCheck),24);
            tracep->chgCData(oldp+19,(vlTOPp->fexp__DOT__fm0__DOT__expF),8);
            tracep->chgIData(oldp+20,(vlTOPp->fexp__DOT__fm0__DOT__mantissa),24);
            tracep->chgQData(oldp+21,(vlTOPp->fexp__DOT__fm0__DOT__mantissaProd),48);
            tracep->chgIData(oldp+23,(vlTOPp->fexp__DOT__fm0__DOT____Vcellinp__r0____pinNumber1),32);
            tracep->chgIData(oldp+24,(vlTOPp->fexp__DOT__fm0__DOT__r0__DOT__overflowCheck),24);
            tracep->chgBit(oldp+25,(vlTOPp->fexp__DOT__fma0__DOT__sign_out));
            tracep->chgBit(oldp+26,(vlTOPp->fexp__DOT__fma0__DOT__largerMag));
            tracep->chgCData(oldp+27,(vlTOPp->fexp__DOT__fma0__DOT__exp_out),8);
            tracep->chgCData(oldp+28,(vlTOPp->fexp__DOT__fma0__DOT__final_exp),8);
            tracep->chgIData(oldp+29,(vlTOPp->fexp__DOT__fma0__DOT__mantissa_a),24);
            tracep->chgIData(oldp+30,(vlTOPp->fexp__DOT__fma0__DOT__mantissa_c),24);
            tracep->chgIData(oldp+31,(vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm),24);
            tracep->chgIData(oldp+32,(vlTOPp->fexp__DOT__fma0__DOT__final_mantissa),24);
            tracep->chgQData(oldp+33,(vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_out),48);
            tracep->chgIData(oldp+35,(vlTOPp->fexp__DOT__fma0__DOT__sum_mants),25);
            tracep->chgCData(oldp+36,(vlTOPp->fexp__DOT__fm1__DOT__expF),8);
            tracep->chgIData(oldp+37,(vlTOPp->fexp__DOT__fm1__DOT__mantissa),24);
            tracep->chgIData(oldp+38,(((0U == vlTOPp->fexp__DOT__fm0__DOT__r0__DOT__rounded)
                                        ? 0U : (0x800000U 
                                                | (0x7fffffU 
                                                   & vlTOPp->fexp__DOT__fm0__DOT__r0__DOT__rounded)))),24);
            tracep->chgQData(oldp+39,(vlTOPp->fexp__DOT__fm1__DOT__mantissaProd),48);
            tracep->chgIData(oldp+41,(vlTOPp->fexp__DOT__fm1__DOT____Vcellinp__r0____pinNumber1),32);
            tracep->chgIData(oldp+42,(vlTOPp->fexp__DOT__fm1__DOT__r0__DOT__overflowCheck),24);
            tracep->chgBit(oldp+43,(vlTOPp->fexp__DOT__fma1__DOT__sign_out));
            tracep->chgBit(oldp+44,(vlTOPp->fexp__DOT__fma1__DOT__largerMag));
            tracep->chgCData(oldp+45,(vlTOPp->fexp__DOT__fma1__DOT__exp_out),8);
            tracep->chgCData(oldp+46,(vlTOPp->fexp__DOT__fma1__DOT__final_exp),8);
            tracep->chgIData(oldp+47,(vlTOPp->fexp__DOT__fma1__DOT__mantissa_a),24);
            tracep->chgIData(oldp+48,(vlTOPp->fexp__DOT__fma1__DOT__mantissa_c),24);
            tracep->chgIData(oldp+49,(vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm),24);
            tracep->chgIData(oldp+50,(vlTOPp->fexp__DOT__fma1__DOT__final_mantissa),24);
            tracep->chgQData(oldp+51,(vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_out),48);
            tracep->chgIData(oldp+53,(vlTOPp->fexp__DOT__fma1__DOT__sum_mants),25);
            tracep->chgCData(oldp+54,(vlTOPp->fexp__DOT__fm2__DOT__expF),8);
            tracep->chgIData(oldp+55,(vlTOPp->fexp__DOT__fm2__DOT__mantissa),24);
            tracep->chgIData(oldp+56,(((0U == vlTOPp->fexp__DOT__fm1__DOT__r0__DOT__rounded)
                                        ? 0U : (0x800000U 
                                                | (0x7fffffU 
                                                   & vlTOPp->fexp__DOT__fm1__DOT__r0__DOT__rounded)))),24);
            tracep->chgQData(oldp+57,(vlTOPp->fexp__DOT__fm2__DOT__mantissaProd),48);
            tracep->chgIData(oldp+59,(vlTOPp->fexp__DOT__fm2__DOT____Vcellinp__r0____pinNumber1),32);
            tracep->chgIData(oldp+60,(vlTOPp->fexp__DOT__fm2__DOT__r0__DOT__overflowCheck),24);
            tracep->chgBit(oldp+61,(vlTOPp->fexp__DOT__fma2__DOT__sign_out));
            tracep->chgBit(oldp+62,(vlTOPp->fexp__DOT__fma2__DOT__largerMag));
            tracep->chgCData(oldp+63,(vlTOPp->fexp__DOT__fma2__DOT__exp_out),8);
            tracep->chgCData(oldp+64,(vlTOPp->fexp__DOT__fma2__DOT__final_exp),8);
            tracep->chgIData(oldp+65,(vlTOPp->fexp__DOT__fma2__DOT__mantissa_a),24);
            tracep->chgIData(oldp+66,(vlTOPp->fexp__DOT__fma2__DOT__mantissa_c),24);
            tracep->chgIData(oldp+67,(vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm),24);
            tracep->chgIData(oldp+68,(vlTOPp->fexp__DOT__fma2__DOT__final_mantissa),24);
            tracep->chgQData(oldp+69,(vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_out),48);
            tracep->chgIData(oldp+71,(vlTOPp->fexp__DOT__fma2__DOT__sum_mants),25);
            tracep->chgCData(oldp+72,(vlTOPp->fexp__DOT__fm3__DOT__expF),8);
            tracep->chgIData(oldp+73,(vlTOPp->fexp__DOT__fm3__DOT__mantissa),24);
            tracep->chgIData(oldp+74,(((0U == vlTOPp->fexp__DOT__fm2__DOT__r0__DOT__rounded)
                                        ? 0U : (0x800000U 
                                                | (0x7fffffU 
                                                   & vlTOPp->fexp__DOT__fm2__DOT__r0__DOT__rounded)))),24);
            tracep->chgQData(oldp+75,(vlTOPp->fexp__DOT__fm3__DOT__mantissaProd),48);
            tracep->chgIData(oldp+77,(vlTOPp->fexp__DOT__fm3__DOT____Vcellinp__r0____pinNumber1),32);
            tracep->chgIData(oldp+78,(vlTOPp->fexp__DOT__fm3__DOT__r0__DOT__overflowCheck),24);
            tracep->chgBit(oldp+79,(vlTOPp->fexp__DOT__fma3__DOT__sign_out));
            tracep->chgBit(oldp+80,(vlTOPp->fexp__DOT__fma3__DOT__largerMag));
            tracep->chgCData(oldp+81,(vlTOPp->fexp__DOT__fma3__DOT__exp_out),8);
            tracep->chgCData(oldp+82,(vlTOPp->fexp__DOT__fma3__DOT__final_exp),8);
            tracep->chgIData(oldp+83,(vlTOPp->fexp__DOT__fma3__DOT__mantissa_a),24);
            tracep->chgIData(oldp+84,(vlTOPp->fexp__DOT__fma3__DOT__mantissa_c),24);
            tracep->chgIData(oldp+85,(vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm),24);
            tracep->chgIData(oldp+86,(vlTOPp->fexp__DOT__fma3__DOT__final_mantissa),24);
            tracep->chgQData(oldp+87,(vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_out),48);
            tracep->chgIData(oldp+89,(vlTOPp->fexp__DOT__fma3__DOT__sum_mants),25);
        }
        tracep->chgIData(oldp+90,(vlTOPp->exp),32);
        tracep->chgIData(oldp+91,(vlTOPp->out_num),32);
        tracep->chgBit(oldp+92,(0U));
        tracep->chgIData(oldp+93,(((0U == vlTOPp->exp)
                                    ? 0U : (0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->exp)))),24);
        tracep->chgBit(oldp+94,((1U & ((vlTOPp->fexp__DOT__fm0__DOT__r0__DOT__rounded 
                                        ^ vlTOPp->exp) 
                                       >> 0x1fU))));
        tracep->chgBit(oldp+95,((1U & ((vlTOPp->fexp__DOT__fm1__DOT__r0__DOT__rounded 
                                        ^ vlTOPp->exp) 
                                       >> 0x1fU))));
        tracep->chgBit(oldp+96,((1U & ((vlTOPp->fexp__DOT__fm2__DOT__r0__DOT__rounded 
                                        ^ vlTOPp->exp) 
                                       >> 0x1fU))));
    }
}

void Vfexp::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vfexp__Syms* __restrict vlSymsp = static_cast<Vfexp__Syms*>(userp);
    Vfexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
