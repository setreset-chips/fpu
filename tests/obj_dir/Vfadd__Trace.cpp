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
            tracep->chgBit(oldp+2,(vlTOPp->fadd__DOT__leadMantBit1));
            tracep->chgBit(oldp+3,(vlTOPp->fadd__DOT__leadMantBit2));
            tracep->chgBit(oldp+4,(vlTOPp->fadd__DOT__subnormal));
            tracep->chgCData(oldp+5,(vlTOPp->fadd__DOT__num1Exp),8);
            tracep->chgCData(oldp+6,(vlTOPp->fadd__DOT__num2Exp),8);
            tracep->chgCData(oldp+7,(vlTOPp->fadd__DOT__finalExp),8);
            tracep->chgIData(oldp+8,(vlTOPp->fadd__DOT__num1Mant),24);
            tracep->chgIData(oldp+9,(vlTOPp->fadd__DOT__num2Mant),24);
            tracep->chgIData(oldp+10,(vlTOPp->fadd__DOT__finalMant),24);
            tracep->chgIData(oldp+11,(vlTOPp->fadd__DOT__sumMants),25);
            tracep->chgIData(oldp+12,(vlTOPp->fadd__DOT__unrounded),32);
            tracep->chgIData(oldp+13,(vlTOPp->fadd__DOT__r0__DOT__rounded),32);
            tracep->chgIData(oldp+14,(vlTOPp->fadd__DOT__r0__DOT__overflowCheck),24);
            tracep->chgIData(oldp+15,(vlTOPp->fadd__DOT__r0__DOT__mask),23);
            tracep->chgIData(oldp+16,(vlTOPp->fadd__DOT__r0__DOT__mask2),23);
            tracep->chgIData(oldp+17,(vlTOPp->fadd__DOT__r0__DOT__i),32);
        }
        tracep->chgIData(oldp+18,(vlTOPp->num1),32);
        tracep->chgIData(oldp+19,(vlTOPp->num2),32);
        tracep->chgCData(oldp+20,(vlTOPp->rm),3);
        tracep->chgIData(oldp+21,(vlTOPp->out_num),32);
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
