// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfadd.h for the primary calling header

#include "Vfadd.h"
#include "Vfadd__Syms.h"

//==========

VL_CTOR_IMP(Vfadd) {
    Vfadd__Syms* __restrict vlSymsp = __VlSymsp = new Vfadd__Syms(this, name());
    Vfadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vfadd::__Vconfigure(Vfadd__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vfadd::~Vfadd() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vfadd::_eval_initial(Vfadd__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd::_eval_initial\n"); );
    Vfadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfadd::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd::final\n"); );
    // Variables
    Vfadd__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vfadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfadd::_eval_settle(Vfadd__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd::_eval_settle\n"); );
    Vfadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vfadd::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd::_ctor_var_reset\n"); );
    // Body
    num1 = VL_RAND_RESET_I(32);
    num2 = VL_RAND_RESET_I(32);
    out_num = VL_RAND_RESET_I(32);
    fadd__DOT__largerMag = VL_RAND_RESET_I(1);
    fadd__DOT__finalSign = VL_RAND_RESET_I(1);
    fadd__DOT__num1Exp = VL_RAND_RESET_I(8);
    fadd__DOT__num2Exp = VL_RAND_RESET_I(8);
    fadd__DOT__finalExp = VL_RAND_RESET_I(8);
    fadd__DOT__num1Mant = VL_RAND_RESET_I(24);
    fadd__DOT__num2Mant = VL_RAND_RESET_I(24);
    fadd__DOT__finalMant = VL_RAND_RESET_I(24);
    fadd__DOT__sumMants = VL_RAND_RESET_I(25);
    fadd__DOT__i = 0;
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
