// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfsqrt.h for the primary calling header

#include "Vfsqrt.h"
#include "Vfsqrt__Syms.h"

//==========

VL_CTOR_IMP(Vfsqrt) {
    Vfsqrt__Syms* __restrict vlSymsp = __VlSymsp = new Vfsqrt__Syms(this, name());
    Vfsqrt* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vfsqrt::__Vconfigure(Vfsqrt__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vfsqrt::~Vfsqrt() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vfsqrt::_eval_initial(Vfsqrt__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt::_eval_initial\n"); );
    Vfsqrt* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfsqrt::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt::final\n"); );
    // Variables
    Vfsqrt__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vfsqrt* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfsqrt::_eval_settle(Vfsqrt__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt::_eval_settle\n"); );
    Vfsqrt* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vfsqrt::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt::_ctor_var_reset\n"); );
    // Body
    var1 = VL_RAND_RESET_I(32);
    rm = VL_RAND_RESET_I(3);
    res = VL_RAND_RESET_I(32);
    fsqrt__DOT__shifted_num = VL_RAND_RESET_I(32);
    fsqrt__DOT__r0__DOT__rounded = VL_RAND_RESET_I(32);
    fsqrt__DOT__r0__DOT__overflowCheck = VL_RAND_RESET_I(24);
    fsqrt__DOT__r0__DOT__mask = VL_RAND_RESET_I(23);
    fsqrt__DOT__r0__DOT__mask2 = VL_RAND_RESET_I(23);
    fsqrt__DOT__r0__DOT__i = 0;
    fsqrt__DOT__r0__DOT__j = 0;
    __Vchglast__TOP__fsqrt__DOT__shifted_num = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
