// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfmul.h for the primary calling header

#include "Vfmul.h"
#include "Vfmul__Syms.h"

//==========

VL_CTOR_IMP(Vfmul) {
    Vfmul__Syms* __restrict vlSymsp = __VlSymsp = new Vfmul__Syms(this, name());
    Vfmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vfmul::__Vconfigure(Vfmul__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vfmul::~Vfmul() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vfmul::_eval_initial(Vfmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul::_eval_initial\n"); );
    Vfmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfmul::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul::final\n"); );
    // Variables
    Vfmul__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vfmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfmul::_eval_settle(Vfmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul::_eval_settle\n"); );
    Vfmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vfmul::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul::_ctor_var_reset\n"); );
    // Body
    num1 = VL_RAND_RESET_I(32);
    num2 = VL_RAND_RESET_I(32);
    out_mul = VL_RAND_RESET_I(32);
    fmul__DOT__expF = VL_RAND_RESET_I(8);
    fmul__DOT__mantissa = VL_RAND_RESET_I(23);
    fmul__DOT__mantissaProd = VL_RAND_RESET_Q(48);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
