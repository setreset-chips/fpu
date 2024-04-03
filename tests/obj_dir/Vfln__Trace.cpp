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
            tracep->chgIData(oldp+0,(vlSymsp->TOP__fln__DOT__fm0.__PVT__r0__DOT__rounded),32);
            tracep->chgIData(oldp+1,(vlSymsp->TOP__fln__DOT__fm1.__PVT__r0__DOT__rounded),32);
            tracep->chgIData(oldp+2,(vlSymsp->TOP__fln__DOT__fm2.__PVT__r0__DOT__rounded),32);
            tracep->chgIData(oldp+3,(vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__rounded),32);
            tracep->chgIData(oldp+4,(vlSymsp->TOP__fln__DOT__fm4.__PVT__r0__DOT__rounded),32);
            tracep->chgIData(oldp+5,(vlTOPp->fln__DOT__temp6),32);
            tracep->chgIData(oldp+6,(vlTOPp->fln__DOT__fa1__DOT__r0__DOT__rounded),32);
            tracep->chgIData(oldp+7,(vlTOPp->fln__DOT__fa2__DOT__r0__DOT__rounded),32);
            tracep->chgIData(oldp+8,(vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded),32);
            tracep->chgIData(oldp+9,(vlSymsp->TOP__fln__DOT__fm5.__PVT__r0__DOT__rounded),32);
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
            tracep->chgIData(oldp+20,(vlTOPp->fln__DOT__fa0__DOT__unrounded),32);
            tracep->chgIData(oldp+21,(vlTOPp->fln__DOT__fa0__DOT__r0__DOT__overflowCheck),24);
            tracep->chgBit(oldp+22,(vlTOPp->fln__DOT__fma1__DOT__sign_out));
            tracep->chgBit(oldp+23,(vlTOPp->fln__DOT__fma1__DOT__largerMag));
            tracep->chgCData(oldp+24,(vlTOPp->fln__DOT__fma1__DOT__exp_out),8);
            tracep->chgCData(oldp+25,(vlTOPp->fln__DOT__fma1__DOT__final_exp),8);
            tracep->chgIData(oldp+26,(vlTOPp->fln__DOT__fma1__DOT__mantissa_a),24);
            tracep->chgIData(oldp+27,(vlTOPp->fln__DOT__fma1__DOT__mantissa_c),24);
            tracep->chgIData(oldp+28,(vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm),24);
            tracep->chgIData(oldp+29,(vlTOPp->fln__DOT__fma1__DOT__final_mantissa),24);
            tracep->chgQData(oldp+30,(vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_out),48);
            tracep->chgIData(oldp+32,(vlTOPp->fln__DOT__fma1__DOT__sum_mants),25);
            tracep->chgBit(oldp+33,(vlTOPp->fln__DOT__fa1__DOT__largerMag));
            tracep->chgBit(oldp+34,(vlTOPp->fln__DOT__fa1__DOT__finalSign));
            tracep->chgCData(oldp+35,(vlTOPp->fln__DOT__fa1__DOT__num1Exp),8);
            tracep->chgCData(oldp+36,(vlTOPp->fln__DOT__fa1__DOT__num2Exp),8);
            tracep->chgCData(oldp+37,(vlTOPp->fln__DOT__fa1__DOT__finalExp),8);
            tracep->chgIData(oldp+38,(vlTOPp->fln__DOT__fa1__DOT__num1Mant),24);
            tracep->chgIData(oldp+39,(vlTOPp->fln__DOT__fa1__DOT__num2Mant),24);
            tracep->chgIData(oldp+40,(vlTOPp->fln__DOT__fa1__DOT__finalMant),24);
            tracep->chgIData(oldp+41,(vlTOPp->fln__DOT__fa1__DOT__sumMants),25);
            tracep->chgIData(oldp+42,(vlTOPp->fln__DOT__fa1__DOT__unrounded),32);
            tracep->chgIData(oldp+43,(vlTOPp->fln__DOT__fa1__DOT__r0__DOT__overflowCheck),24);
            tracep->chgBit(oldp+44,(vlTOPp->fln__DOT__fa2__DOT__largerMag));
            tracep->chgBit(oldp+45,(vlTOPp->fln__DOT__fa2__DOT__finalSign));
            tracep->chgCData(oldp+46,(vlTOPp->fln__DOT__fa2__DOT__num1Exp),8);
            tracep->chgCData(oldp+47,(vlTOPp->fln__DOT__fa2__DOT__num2Exp),8);
            tracep->chgCData(oldp+48,(vlTOPp->fln__DOT__fa2__DOT__finalExp),8);
            tracep->chgIData(oldp+49,(vlTOPp->fln__DOT__fa2__DOT__num1Mant),24);
            tracep->chgIData(oldp+50,(vlTOPp->fln__DOT__fa2__DOT__num2Mant),24);
            tracep->chgIData(oldp+51,(vlTOPp->fln__DOT__fa2__DOT__finalMant),24);
            tracep->chgIData(oldp+52,(vlTOPp->fln__DOT__fa2__DOT__sumMants),25);
            tracep->chgIData(oldp+53,(vlTOPp->fln__DOT__fa2__DOT__unrounded),32);
            tracep->chgIData(oldp+54,(vlTOPp->fln__DOT__fa2__DOT__r0__DOT__overflowCheck),24);
            tracep->chgBit(oldp+55,(vlTOPp->fln__DOT__fma2__DOT__sign_out));
            tracep->chgBit(oldp+56,(vlTOPp->fln__DOT__fma2__DOT__largerMag));
            tracep->chgCData(oldp+57,(vlTOPp->fln__DOT__fma2__DOT__exp_out),8);
            tracep->chgCData(oldp+58,(vlTOPp->fln__DOT__fma2__DOT__final_exp),8);
            tracep->chgIData(oldp+59,(vlTOPp->fln__DOT__fma2__DOT__mantissa_a),24);
            tracep->chgIData(oldp+60,(vlTOPp->fln__DOT__fma2__DOT__mantissa_c),24);
            tracep->chgIData(oldp+61,(vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm),24);
            tracep->chgIData(oldp+62,(vlTOPp->fln__DOT__fma2__DOT__final_mantissa),24);
            tracep->chgQData(oldp+63,(vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_out),48);
            tracep->chgIData(oldp+65,(vlTOPp->fln__DOT__fma2__DOT__sum_mants),25);
            tracep->chgBit(oldp+66,(0U));
            tracep->chgCData(oldp+67,(vlSymsp->TOP__fln__DOT__fm0.__PVT__expF),8);
            tracep->chgIData(oldp+68,(vlSymsp->TOP__fln__DOT__fm0.__PVT__mantissa),24);
            tracep->chgIData(oldp+69,(((0U == vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded)
                                        ? 0U : (0x800000U 
                                                | (0x7fffffU 
                                                   & vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded)))),24);
            tracep->chgQData(oldp+70,(vlSymsp->TOP__fln__DOT__fm0.__PVT__mantissaProd),48);
            tracep->chgIData(oldp+72,(vlSymsp->TOP__fln__DOT__fm0.__Vcellinp__r0____pinNumber1),32);
            tracep->chgIData(oldp+73,(vlSymsp->TOP__fln__DOT__fm0.__PVT__r0__DOT__overflowCheck),24);
            tracep->chgBit(oldp+74,((1U & (~ (vlSymsp->TOP__fln__DOT__fm0.__PVT__r0__DOT__rounded 
                                              >> 0x1fU)))));
            tracep->chgCData(oldp+75,(vlSymsp->TOP__fln__DOT__fm1.__PVT__expF),8);
            tracep->chgIData(oldp+76,(vlSymsp->TOP__fln__DOT__fm1.__PVT__mantissa),24);
            tracep->chgIData(oldp+77,(((0U == vlSymsp->TOP__fln__DOT__fm0.__PVT__r0__DOT__rounded)
                                        ? 0U : (0x800000U 
                                                | (0x7fffffU 
                                                   & vlSymsp->TOP__fln__DOT__fm0.__PVT__r0__DOT__rounded)))),24);
            tracep->chgQData(oldp+78,(vlSymsp->TOP__fln__DOT__fm1.__PVT__mantissaProd),48);
            tracep->chgIData(oldp+80,(vlSymsp->TOP__fln__DOT__fm1.__Vcellinp__r0____pinNumber1),32);
            tracep->chgIData(oldp+81,(vlSymsp->TOP__fln__DOT__fm1.__PVT__r0__DOT__overflowCheck),24);
            tracep->chgBit(oldp+82,((1U & ((vlSymsp->TOP__fln__DOT__fm0.__PVT__r0__DOT__rounded 
                                            ^ vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded) 
                                           >> 0x1fU))));
            tracep->chgCData(oldp+83,(vlSymsp->TOP__fln__DOT__fm2.__PVT__expF),8);
            tracep->chgIData(oldp+84,(vlSymsp->TOP__fln__DOT__fm2.__PVT__mantissa),24);
            tracep->chgQData(oldp+85,(vlSymsp->TOP__fln__DOT__fm2.__PVT__mantissaProd),48);
            tracep->chgIData(oldp+87,(vlSymsp->TOP__fln__DOT__fm2.__Vcellinp__r0____pinNumber1),32);
            tracep->chgIData(oldp+88,(vlSymsp->TOP__fln__DOT__fm2.__PVT__r0__DOT__overflowCheck),24);
            tracep->chgBit(oldp+89,((1U & (vlSymsp->TOP__fln__DOT__fm2.__PVT__r0__DOT__rounded 
                                           >> 0x1fU))));
            tracep->chgCData(oldp+90,(vlSymsp->TOP__fln__DOT__fm3.__PVT__expF),8);
            tracep->chgIData(oldp+91,(vlSymsp->TOP__fln__DOT__fm3.__PVT__mantissa),24);
            tracep->chgIData(oldp+92,(((0U == vlSymsp->TOP__fln__DOT__fm2.__PVT__r0__DOT__rounded)
                                        ? 0U : (0x800000U 
                                                | (0x7fffffU 
                                                   & vlSymsp->TOP__fln__DOT__fm2.__PVT__r0__DOT__rounded)))),24);
            tracep->chgQData(oldp+93,(vlSymsp->TOP__fln__DOT__fm3.__PVT__mantissaProd),48);
            tracep->chgIData(oldp+95,(vlSymsp->TOP__fln__DOT__fm3.__Vcellinp__r0____pinNumber1),32);
            tracep->chgIData(oldp+96,(vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__overflowCheck),24);
            tracep->chgBit(oldp+97,((1U & ((vlSymsp->TOP__fln__DOT__fm2.__PVT__r0__DOT__rounded 
                                            ^ vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded) 
                                           >> 0x1fU))));
            tracep->chgCData(oldp+98,(vlSymsp->TOP__fln__DOT__fm4.__PVT__expF),8);
            tracep->chgIData(oldp+99,(vlSymsp->TOP__fln__DOT__fm4.__PVT__mantissa),24);
            tracep->chgQData(oldp+100,(vlSymsp->TOP__fln__DOT__fm4.__PVT__mantissaProd),48);
            tracep->chgIData(oldp+102,(vlSymsp->TOP__fln__DOT__fm4.__Vcellinp__r0____pinNumber1),32);
            tracep->chgIData(oldp+103,(vlSymsp->TOP__fln__DOT__fm4.__PVT__r0__DOT__overflowCheck),24);
            tracep->chgBit(oldp+104,((1U & ((vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__rounded 
                                             ^ vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded) 
                                            >> 0x1fU))));
            tracep->chgCData(oldp+105,(vlSymsp->TOP__fln__DOT__fm5.__PVT__expF),8);
            tracep->chgIData(oldp+106,(vlSymsp->TOP__fln__DOT__fm5.__PVT__mantissa),24);
            tracep->chgIData(oldp+107,(((0U == vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__rounded)
                                         ? 0U : (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__rounded)))),24);
            tracep->chgQData(oldp+108,(vlSymsp->TOP__fln__DOT__fm5.__PVT__mantissaProd),48);
            tracep->chgIData(oldp+110,(vlSymsp->TOP__fln__DOT__fm5.__Vcellinp__r0____pinNumber1),32);
            tracep->chgIData(oldp+111,(vlSymsp->TOP__fln__DOT__fm5.__PVT__r0__DOT__overflowCheck),24);
        }
        tracep->chgIData(oldp+112,(vlTOPp->num1),32);
        tracep->chgIData(oldp+113,(vlTOPp->out1),32);
        tracep->chgBit(oldp+114,((1U & (vlTOPp->num1 
                                        >> 0x1fU))));
        tracep->chgIData(oldp+115,((0x7fffffffU & vlTOPp->num1)),32);
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
