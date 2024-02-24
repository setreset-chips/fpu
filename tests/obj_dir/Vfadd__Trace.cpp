// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfadd__Syms.h"


void Vfadd::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vfadd__Syms* __restrict vlSymsp = static_cast<Vfadd__Syms*>(userp);
    Vfadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vfadd::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vfadd__Syms* __restrict vlSymsp = static_cast<Vfadd__Syms*>(userp);
    Vfadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->fadd__DOT__largerMag));
            tracep->chgBit(oldp+1,(vlTOPp->fadd__DOT__finalSign));
            tracep->chgCData(oldp+2,(vlTOPp->fadd__DOT__num1Exp),8);
            tracep->chgCData(oldp+3,(vlTOPp->fadd__DOT__num2Exp),8);
            tracep->chgCData(oldp+4,(vlTOPp->fadd__DOT__finalExp),8);
            tracep->chgIData(oldp+5,(vlTOPp->fadd__DOT__num1Mant),24);
            tracep->chgIData(oldp+6,(vlTOPp->fadd__DOT__num2Mant),24);
            tracep->chgIData(oldp+7,(vlTOPp->fadd__DOT__finalMant),24);
            tracep->chgIData(oldp+8,(vlTOPp->fadd__DOT__sumMants),25);
        }
        tracep->chgIData(oldp+9,(vlTOPp->num1),32);
        tracep->chgIData(oldp+10,(vlTOPp->num2),32);
        tracep->chgIData(oldp+11,(vlTOPp->out_num),32);
    }
}

void Vfadd::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vfadd__Syms* __restrict vlSymsp = static_cast<Vfadd__Syms*>(userp);
    Vfadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
