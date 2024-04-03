// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfsqrt__Syms.h"


void Vfsqrt::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vfsqrt__Syms* __restrict vlSymsp = static_cast<Vfsqrt__Syms*>(userp);
    Vfsqrt* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vfsqrt::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vfsqrt__Syms* __restrict vlSymsp = static_cast<Vfsqrt__Syms*>(userp);
    Vfsqrt* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+0,(vlTOPp->fsqrt__DOT__shifted_num),32);
            tracep->chgIData(oldp+1,(vlTOPp->fsqrt__DOT__r0__DOT__rounded),32);
            tracep->chgIData(oldp+2,(vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck),24);
            tracep->chgIData(oldp+3,(vlTOPp->fsqrt__DOT__r0__DOT__mask),23);
            tracep->chgIData(oldp+4,(vlTOPp->fsqrt__DOT__r0__DOT__mask2),23);
            tracep->chgIData(oldp+5,(vlTOPp->fsqrt__DOT__r0__DOT__i),32);
        }
        tracep->chgIData(oldp+6,(vlTOPp->var1),32);
        tracep->chgCData(oldp+7,(vlTOPp->rm),3);
        tracep->chgIData(oldp+8,(vlTOPp->res),32);
    }
}

void Vfsqrt::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vfsqrt__Syms* __restrict vlSymsp = static_cast<Vfsqrt__Syms*>(userp);
    Vfsqrt* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
