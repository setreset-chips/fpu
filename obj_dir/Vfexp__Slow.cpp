// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfexp.h for the primary calling header

#include "Vfexp.h"
#include "Vfexp__Syms.h"

//==========

VL_CTOR_IMP(Vfexp) {
    Vfexp__Syms* __restrict vlSymsp = __VlSymsp = new Vfexp__Syms(this, name());
    Vfexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vfexp::__Vconfigure(Vfexp__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vfexp::~Vfexp() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vfexp::_eval_initial(Vfexp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfexp::_eval_initial\n"); );
    Vfexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfexp::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfexp::final\n"); );
    // Variables
    Vfexp__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vfexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfexp::_eval_settle(Vfexp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfexp::_eval_settle\n"); );
    Vfexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vfexp::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfexp::_ctor_var_reset\n"); );
    // Body
    exp = VL_RAND_RESET_I(32);
    out_num = VL_RAND_RESET_I(32);
    fexp__DOT__temp1 = VL_RAND_RESET_I(32);
    fexp__DOT__temp2 = VL_RAND_RESET_I(32);
    fexp__DOT__temp3 = VL_RAND_RESET_I(32);
    fexp__DOT__temp4 = VL_RAND_RESET_I(32);
    fexp__DOT__temp5 = VL_RAND_RESET_I(32);
    fexp__DOT__temp6 = VL_RAND_RESET_I(32);
    fexp__DOT__temp7 = VL_RAND_RESET_I(32);
    fexp__DOT__temp8 = VL_RAND_RESET_I(32);
    fexp__DOT__fa0__DOT__largerMag = VL_RAND_RESET_I(1);
    fexp__DOT__fa0__DOT__finalSign = VL_RAND_RESET_I(1);
    fexp__DOT__fa0__DOT__num1Exp = VL_RAND_RESET_I(8);
    fexp__DOT__fa0__DOT__num2Exp = VL_RAND_RESET_I(8);
    fexp__DOT__fa0__DOT__finalExp = VL_RAND_RESET_I(8);
    fexp__DOT__fa0__DOT__num1Mant = VL_RAND_RESET_I(24);
    fexp__DOT__fa0__DOT__num2Mant = VL_RAND_RESET_I(24);
    fexp__DOT__fa0__DOT__finalMant = VL_RAND_RESET_I(24);
    fexp__DOT__fa0__DOT__sumMants = VL_RAND_RESET_I(25);
    fexp__DOT__fm0__DOT__expF = VL_RAND_RESET_I(8);
    fexp__DOT__fm0__DOT__mantissa = VL_RAND_RESET_I(23);
    fexp__DOT__fm0__DOT__mantissaProd = VL_RAND_RESET_Q(48);
    fexp__DOT__fma0__DOT__sign_out = VL_RAND_RESET_I(1);
    fexp__DOT__fma0__DOT__largerMag = VL_RAND_RESET_I(1);
    fexp__DOT__fma0__DOT__exp_out = VL_RAND_RESET_I(8);
    fexp__DOT__fma0__DOT__final_exp = VL_RAND_RESET_I(8);
    fexp__DOT__fma0__DOT__mantissa_a = VL_RAND_RESET_I(24);
    fexp__DOT__fma0__DOT__mantissa_c = VL_RAND_RESET_I(24);
    fexp__DOT__fma0__DOT__mantissa_mul_norm = VL_RAND_RESET_I(24);
    fexp__DOT__fma0__DOT__final_mantissa = VL_RAND_RESET_I(24);
    fexp__DOT__fma0__DOT__mantissa_mul_out = VL_RAND_RESET_Q(48);
    fexp__DOT__fma0__DOT__sum_mants = VL_RAND_RESET_I(25);
    fexp__DOT__fm1__DOT__expF = VL_RAND_RESET_I(8);
    fexp__DOT__fm1__DOT__mantissa = VL_RAND_RESET_I(23);
    fexp__DOT__fm1__DOT__mantissaProd = VL_RAND_RESET_Q(48);
    fexp__DOT__fma1__DOT__sign_out = VL_RAND_RESET_I(1);
    fexp__DOT__fma1__DOT__largerMag = VL_RAND_RESET_I(1);
    fexp__DOT__fma1__DOT__exp_out = VL_RAND_RESET_I(8);
    fexp__DOT__fma1__DOT__final_exp = VL_RAND_RESET_I(8);
    fexp__DOT__fma1__DOT__mantissa_a = VL_RAND_RESET_I(24);
    fexp__DOT__fma1__DOT__mantissa_c = VL_RAND_RESET_I(24);
    fexp__DOT__fma1__DOT__mantissa_mul_norm = VL_RAND_RESET_I(24);
    fexp__DOT__fma1__DOT__final_mantissa = VL_RAND_RESET_I(24);
    fexp__DOT__fma1__DOT__mantissa_mul_out = VL_RAND_RESET_Q(48);
    fexp__DOT__fma1__DOT__sum_mants = VL_RAND_RESET_I(25);
    fexp__DOT__fm2__DOT__expF = VL_RAND_RESET_I(8);
    fexp__DOT__fm2__DOT__mantissa = VL_RAND_RESET_I(23);
    fexp__DOT__fm2__DOT__mantissaProd = VL_RAND_RESET_Q(48);
    fexp__DOT__fma2__DOT__sign_out = VL_RAND_RESET_I(1);
    fexp__DOT__fma2__DOT__largerMag = VL_RAND_RESET_I(1);
    fexp__DOT__fma2__DOT__exp_out = VL_RAND_RESET_I(8);
    fexp__DOT__fma2__DOT__final_exp = VL_RAND_RESET_I(8);
    fexp__DOT__fma2__DOT__mantissa_a = VL_RAND_RESET_I(24);
    fexp__DOT__fma2__DOT__mantissa_c = VL_RAND_RESET_I(24);
    fexp__DOT__fma2__DOT__mantissa_mul_norm = VL_RAND_RESET_I(24);
    fexp__DOT__fma2__DOT__final_mantissa = VL_RAND_RESET_I(24);
    fexp__DOT__fma2__DOT__mantissa_mul_out = VL_RAND_RESET_Q(48);
    fexp__DOT__fma2__DOT__sum_mants = VL_RAND_RESET_I(25);
    fexp__DOT__fm3__DOT__expF = VL_RAND_RESET_I(8);
    fexp__DOT__fm3__DOT__mantissa = VL_RAND_RESET_I(23);
    fexp__DOT__fm3__DOT__mantissaProd = VL_RAND_RESET_Q(48);
    fexp__DOT__fma3__DOT__sign_out = VL_RAND_RESET_I(1);
    fexp__DOT__fma3__DOT__largerMag = VL_RAND_RESET_I(1);
    fexp__DOT__fma3__DOT__exp_out = VL_RAND_RESET_I(8);
    fexp__DOT__fma3__DOT__final_exp = VL_RAND_RESET_I(8);
    fexp__DOT__fma3__DOT__mantissa_a = VL_RAND_RESET_I(24);
    fexp__DOT__fma3__DOT__mantissa_c = VL_RAND_RESET_I(24);
    fexp__DOT__fma3__DOT__mantissa_mul_norm = VL_RAND_RESET_I(24);
    fexp__DOT__fma3__DOT__final_mantissa = VL_RAND_RESET_I(24);
    fexp__DOT__fma3__DOT__mantissa_mul_out = VL_RAND_RESET_Q(48);
    fexp__DOT__fma3__DOT__sum_mants = VL_RAND_RESET_I(25);
}
