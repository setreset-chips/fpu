// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFMA__Syms.h"


void VFMA::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VFMA__Syms* __restrict vlSymsp = static_cast<VFMA__Syms*>(userp);
    VFMA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VFMA::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VFMA__Syms* __restrict vlSymsp = static_cast<VFMA__Syms*>(userp);
    VFMA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->FMA__DOT__sign_out));
            tracep->chgBit(oldp+1,(vlTOPp->FMA__DOT__largerMag));
            tracep->chgCData(oldp+2,(vlTOPp->FMA__DOT__exp_out),8);
            tracep->chgCData(oldp+3,(vlTOPp->FMA__DOT__final_exp),8);
            tracep->chgIData(oldp+4,(vlTOPp->FMA__DOT__mantissa_a),24);
            tracep->chgIData(oldp+5,(vlTOPp->FMA__DOT__mantissa_b),24);
            tracep->chgIData(oldp+6,(vlTOPp->FMA__DOT__mantissa_c),24);
            tracep->chgIData(oldp+7,(vlTOPp->FMA__DOT__mantissa_mul_norm),24);
            tracep->chgIData(oldp+8,(vlTOPp->FMA__DOT__final_mantissa),24);
            tracep->chgQData(oldp+9,(vlTOPp->FMA__DOT__mantissa_mul_out),48);
            tracep->chgIData(oldp+11,(vlTOPp->FMA__DOT__sum_mants),25);
        }
        tracep->chgIData(oldp+12,(vlTOPp->a_fp),32);
        tracep->chgIData(oldp+13,(vlTOPp->b_fp),32);
        tracep->chgIData(oldp+14,(vlTOPp->c_fp),32);
        tracep->chgIData(oldp+15,(vlTOPp->out_fp),32);
    }
}

void VFMA::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VFMA__Syms* __restrict vlSymsp = static_cast<VFMA__Syms*>(userp);
    VFMA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
