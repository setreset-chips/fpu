// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFMA.h for the primary calling header

#include "VFMA.h"
#include "VFMA__Syms.h"

//==========

VL_CTOR_IMP(VFMA) {
    VFMA__Syms* __restrict vlSymsp = __VlSymsp = new VFMA__Syms(this, name());
    VFMA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VFMA::__Vconfigure(VFMA__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VFMA::~VFMA() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VFMA::_eval_initial(VFMA__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFMA::_eval_initial\n"); );
    VFMA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VFMA::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFMA::final\n"); );
    // Variables
    VFMA__Syms* __restrict vlSymsp = this->__VlSymsp;
    VFMA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VFMA::_eval_settle(VFMA__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFMA::_eval_settle\n"); );
    VFMA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void VFMA::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFMA::_ctor_var_reset\n"); );
    // Body
    a_fp = VL_RAND_RESET_I(32);
    b_fp = VL_RAND_RESET_I(32);
    c_fp = VL_RAND_RESET_I(32);
    out_fp = VL_RAND_RESET_I(32);
    FMA__DOT__sign_out = VL_RAND_RESET_I(1);
    FMA__DOT__largerMag = VL_RAND_RESET_I(1);
    FMA__DOT__exp_out = VL_RAND_RESET_I(8);
    FMA__DOT__final_exp = VL_RAND_RESET_I(8);
    FMA__DOT__mantissa_a = VL_RAND_RESET_I(24);
    FMA__DOT__mantissa_b = VL_RAND_RESET_I(24);
    FMA__DOT__mantissa_c = VL_RAND_RESET_I(24);
    FMA__DOT__mantissa_mul_norm = VL_RAND_RESET_I(24);
    FMA__DOT__final_mantissa = VL_RAND_RESET_I(24);
    FMA__DOT__mantissa_mul_out = VL_RAND_RESET_Q(48);
    FMA__DOT__sum_mants = VL_RAND_RESET_I(25);
    FMA__DOT__offset = 0;
}
