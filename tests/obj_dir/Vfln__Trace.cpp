// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfln__Syms.h"


void Vfln::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vfln__Syms* __restrict vlSymsp = static_cast<Vfln__Syms*>(userp);
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vfln::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vfln__Syms* __restrict vlSymsp = static_cast<Vfln__Syms*>(userp);
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+0,(vlTOPp->fln__DOT__temp1),32);
            tracep->chgIData(oldp+1,(vlTOPp->fln__DOT__temp2),32);
            tracep->chgIData(oldp+2,(vlTOPp->fln__DOT__temp3),32);
            tracep->chgIData(oldp+3,(vlTOPp->fln__DOT__temp4),32);
            tracep->chgIData(oldp+4,(vlTOPp->fln__DOT__temp5),32);
            tracep->chgIData(oldp+5,(vlTOPp->fln__DOT__temp6),32);
            tracep->chgIData(oldp+6,(vlTOPp->fln__DOT__temp7),32);
            tracep->chgIData(oldp+7,(vlTOPp->fln__DOT__temp8),32);
            tracep->chgIData(oldp+8,(vlTOPp->fln__DOT__op1i),32);
            tracep->chgIData(oldp+9,(vlTOPp->fln__DOT__temp9),32);
            tracep->chgIData(oldp+10,(((0x80000000U 
                                        & ((~ (IData)(vlTOPp->fln__DOT__fma2__DOT__sign_out)) 
                                           << 0x1fU)) 
                                       | (((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                           << 0x17U) 
                                          | (0x7fffffU 
                                             & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                >> 1U))))),32);
            tracep->chgBit(oldp+11,(vlTOPp->fln__DOT__fa0__DOT__largerMag));
            tracep->chgBit(oldp+12,(vlTOPp->fln__DOT__fa0__DOT__finalSign));
            tracep->chgCData(oldp+13,(vlTOPp->fln__DOT__fa0__DOT__num1Exp),8);
            tracep->chgCData(oldp+14,(vlTOPp->fln__DOT__fa0__DOT__num2Exp),8);
            tracep->chgCData(oldp+15,(vlTOPp->fln__DOT__fa0__DOT__finalExp),8);
            tracep->chgIData(oldp+16,(vlTOPp->fln__DOT__fa0__DOT__num1Mant),24);
            tracep->chgIData(oldp+17,(vlTOPp->fln__DOT__fa0__DOT__num2Mant),24);
            tracep->chgIData(oldp+18,(vlTOPp->fln__DOT__fa0__DOT__finalMant),24);
            tracep->chgIData(oldp+19,(vlTOPp->fln__DOT__fa0__DOT__sumMants),25);
            tracep->chgBit(oldp+20,(0U));
            tracep->chgCData(oldp+21,(vlTOPp->fln__DOT__fm0__DOT__expF),8);
            tracep->chgIData(oldp+22,(vlTOPp->fln__DOT__fm0__DOT__mantissa),23);
            tracep->chgIData(oldp+23,((0x800000U | 
                                       (0x7fffffU & vlTOPp->fln__DOT__op1i))),24);
            tracep->chgQData(oldp+24,(vlTOPp->fln__DOT__fm0__DOT__mantissaProd),48);
            tracep->chgIData(oldp+26,(vlTOPp->fln__DOT__fm0__DOT__i),32);
            tracep->chgBit(oldp+27,((1U & (~ (vlTOPp->fln__DOT__temp1 
                                              >> 0x1fU)))));
            tracep->chgCData(oldp+28,(vlTOPp->fln__DOT__fm1__DOT__expF),8);
            tracep->chgIData(oldp+29,(vlTOPp->fln__DOT__fm1__DOT__mantissa),23);
            tracep->chgIData(oldp+30,((0x800000U | 
                                       (0x7fffffU & vlTOPp->fln__DOT__temp1))),24);
            tracep->chgQData(oldp+31,(vlTOPp->fln__DOT__fm1__DOT__mantissaProd),48);
            tracep->chgIData(oldp+33,(vlTOPp->fln__DOT__fm1__DOT__i),32);
            tracep->chgBit(oldp+34,((1U & ((vlTOPp->fln__DOT__temp1 
                                            ^ vlTOPp->fln__DOT__op1i) 
                                           >> 0x1fU))));
            tracep->chgCData(oldp+35,(vlTOPp->fln__DOT__fm2__DOT__expF),8);
            tracep->chgIData(oldp+36,(vlTOPp->fln__DOT__fm2__DOT__mantissa),23);
            tracep->chgQData(oldp+37,(vlTOPp->fln__DOT__fm2__DOT__mantissaProd),48);
            tracep->chgIData(oldp+39,(vlTOPp->fln__DOT__fm2__DOT__i),32);
            tracep->chgBit(oldp+40,((1U & (vlTOPp->fln__DOT__temp3 
                                           >> 0x1fU))));
            tracep->chgCData(oldp+41,(vlTOPp->fln__DOT__fm3__DOT__expF),8);
            tracep->chgIData(oldp+42,(vlTOPp->fln__DOT__fm3__DOT__mantissa),23);
            tracep->chgIData(oldp+43,((0x800000U | 
                                       (0x7fffffU & vlTOPp->fln__DOT__temp3))),24);
            tracep->chgQData(oldp+44,(vlTOPp->fln__DOT__fm3__DOT__mantissaProd),48);
            tracep->chgIData(oldp+46,(vlTOPp->fln__DOT__fm3__DOT__i),32);
            tracep->chgBit(oldp+47,((1U & ((vlTOPp->fln__DOT__temp3 
                                            ^ vlTOPp->fln__DOT__op1i) 
                                           >> 0x1fU))));
            tracep->chgCData(oldp+48,(vlTOPp->fln__DOT__fm4__DOT__expF),8);
            tracep->chgIData(oldp+49,(vlTOPp->fln__DOT__fm4__DOT__mantissa),23);
            tracep->chgQData(oldp+50,(vlTOPp->fln__DOT__fm4__DOT__mantissaProd),48);
            tracep->chgIData(oldp+52,(vlTOPp->fln__DOT__fm4__DOT__i),32);
            tracep->chgBit(oldp+53,(vlTOPp->fln__DOT__fma1__DOT__sign_out));
            tracep->chgBit(oldp+54,(vlTOPp->fln__DOT__fma1__DOT__largerMag));
            tracep->chgCData(oldp+55,(vlTOPp->fln__DOT__fma1__DOT__exp_out),8);
            tracep->chgCData(oldp+56,(vlTOPp->fln__DOT__fma1__DOT__final_exp),8);
            tracep->chgIData(oldp+57,(vlTOPp->fln__DOT__fma1__DOT__mantissa_a),24);
            tracep->chgIData(oldp+58,(vlTOPp->fln__DOT__fma1__DOT__mantissa_c),24);
            tracep->chgIData(oldp+59,(vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm),24);
            tracep->chgIData(oldp+60,(vlTOPp->fln__DOT__fma1__DOT__final_mantissa),24);
            tracep->chgQData(oldp+61,(vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_out),48);
            tracep->chgIData(oldp+63,(vlTOPp->fln__DOT__fma1__DOT__sum_mants),25);
            tracep->chgBit(oldp+64,(vlTOPp->fln__DOT__fa1__DOT__largerMag));
            tracep->chgBit(oldp+65,(vlTOPp->fln__DOT__fa1__DOT__finalSign));
            tracep->chgCData(oldp+66,(vlTOPp->fln__DOT__fa1__DOT__num1Exp),8);
            tracep->chgCData(oldp+67,(vlTOPp->fln__DOT__fa1__DOT__num2Exp),8);
            tracep->chgCData(oldp+68,(vlTOPp->fln__DOT__fa1__DOT__finalExp),8);
            tracep->chgIData(oldp+69,(vlTOPp->fln__DOT__fa1__DOT__num1Mant),24);
            tracep->chgIData(oldp+70,(vlTOPp->fln__DOT__fa1__DOT__num2Mant),24);
            tracep->chgIData(oldp+71,(vlTOPp->fln__DOT__fa1__DOT__finalMant),24);
            tracep->chgIData(oldp+72,(vlTOPp->fln__DOT__fa1__DOT__sumMants),25);
            tracep->chgBit(oldp+73,(vlTOPp->fln__DOT__fa2__DOT__largerMag));
            tracep->chgBit(oldp+74,(vlTOPp->fln__DOT__fa2__DOT__finalSign));
            tracep->chgCData(oldp+75,(vlTOPp->fln__DOT__fa2__DOT__num1Exp),8);
            tracep->chgCData(oldp+76,(vlTOPp->fln__DOT__fa2__DOT__num2Exp),8);
            tracep->chgCData(oldp+77,(vlTOPp->fln__DOT__fa2__DOT__finalExp),8);
            tracep->chgIData(oldp+78,(vlTOPp->fln__DOT__fa2__DOT__num1Mant),24);
            tracep->chgIData(oldp+79,(vlTOPp->fln__DOT__fa2__DOT__num2Mant),24);
            tracep->chgIData(oldp+80,(vlTOPp->fln__DOT__fa2__DOT__finalMant),24);
            tracep->chgIData(oldp+81,(vlTOPp->fln__DOT__fa2__DOT__sumMants),25);
            tracep->chgBit(oldp+82,((1U & ((vlTOPp->fln__DOT__temp4 
                                            ^ vlTOPp->fln__DOT__op1i) 
                                           >> 0x1fU))));
            tracep->chgCData(oldp+83,(vlTOPp->fln__DOT__fm5__DOT__expF),8);
            tracep->chgIData(oldp+84,(vlTOPp->fln__DOT__fm5__DOT__mantissa),23);
            tracep->chgIData(oldp+85,((0x800000U | 
                                       (0x7fffffU & vlTOPp->fln__DOT__temp4))),24);
            tracep->chgQData(oldp+86,(vlTOPp->fln__DOT__fm5__DOT__mantissaProd),48);
            tracep->chgIData(oldp+88,(vlTOPp->fln__DOT__fm5__DOT__i),32);
            tracep->chgBit(oldp+89,(vlTOPp->fln__DOT__fma2__DOT__sign_out));
            tracep->chgBit(oldp+90,(vlTOPp->fln__DOT__fma2__DOT__largerMag));
            tracep->chgCData(oldp+91,(vlTOPp->fln__DOT__fma2__DOT__exp_out),8);
            tracep->chgCData(oldp+92,(vlTOPp->fln__DOT__fma2__DOT__final_exp),8);
            tracep->chgIData(oldp+93,(vlTOPp->fln__DOT__fma2__DOT__mantissa_a),24);
            tracep->chgIData(oldp+94,(vlTOPp->fln__DOT__fma2__DOT__mantissa_c),24);
            tracep->chgIData(oldp+95,(vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm),24);
            tracep->chgIData(oldp+96,(vlTOPp->fln__DOT__fma2__DOT__final_mantissa),24);
            tracep->chgQData(oldp+97,(vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_out),48);
            tracep->chgIData(oldp+99,(vlTOPp->fln__DOT__fma2__DOT__sum_mants),25);
        }
        tracep->chgIData(oldp+100,(vlTOPp->num1),32);
        tracep->chgIData(oldp+101,(vlTOPp->out1),32);
        tracep->chgBit(oldp+102,((1U & (vlTOPp->num1 
                                        >> 0x1fU))));
        tracep->chgIData(oldp+103,((0x7fffffffU & vlTOPp->num1)),32);
    }
}

void Vfln::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vfln__Syms* __restrict vlSymsp = static_cast<Vfln__Syms*>(userp);
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
