// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpu_top.h for the primary calling header

#include "Vfpu_top.h"
#include "Vfpu_top__Syms.h"

//==========

VL_CTOR_IMP(Vfpu_top) {
    Vfpu_top__Syms* __restrict vlSymsp = __VlSymsp = new Vfpu_top__Syms(this, name());
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vfpu_top::__Vconfigure(Vfpu_top__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vfpu_top::~Vfpu_top() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vfpu_top::_eval_initial(Vfpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_top::_eval_initial\n"); );
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vfpu_top::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_top::final\n"); );
    // Variables
    Vfpu_top__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfpu_top::_eval_settle(Vfpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_top::_eval_settle\n"); );
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfpu_top::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_top::_ctor_var_reset\n"); );
    // Body
    instruction = VL_RAND_RESET_I(32);
    clk = VL_RAND_RESET_I(1);
    fpu_out = VL_RAND_RESET_I(32);
}
