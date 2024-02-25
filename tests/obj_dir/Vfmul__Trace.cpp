// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfmul__Syms.h"


void Vfmul::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vfmul__Syms* __restrict vlSymsp = static_cast<Vfmul__Syms*>(userp);
    Vfmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vfmul::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vfmul__Syms* __restrict vlSymsp = static_cast<Vfmul__Syms*>(userp);
    Vfmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+0,(vlTOPp->fmul__DOT__expF),8);
            tracep->chgIData(oldp+1,(vlTOPp->fmul__DOT__mantissa),24);
            tracep->chgQData(oldp+2,(vlTOPp->fmul__DOT__mantissaProd),48);
        }
        tracep->chgIData(oldp+4,(vlTOPp->num1),32);
        tracep->chgIData(oldp+5,(vlTOPp->num2),32);
        tracep->chgIData(oldp+6,(vlTOPp->out_mul),32);
        tracep->chgBit(oldp+7,((1U & ((vlTOPp->num1 
                                       ^ vlTOPp->num2) 
                                      >> 0x1fU))));
        tracep->chgIData(oldp+8,(((0U == vlTOPp->num1)
                                   ? 0U : (0x800000U 
                                           | (0x7fffffU 
                                              & vlTOPp->num1)))),24);
        tracep->chgIData(oldp+9,(((0U == vlTOPp->num2)
                                   ? 0U : (0x800000U 
                                           | (0x7fffffU 
                                              & vlTOPp->num2)))),24);
    }
}

void Vfmul::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vfmul__Syms* __restrict vlSymsp = static_cast<Vfmul__Syms*>(userp);
    Vfmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
