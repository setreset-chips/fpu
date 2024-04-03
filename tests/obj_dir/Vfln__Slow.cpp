// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfln.h for the primary calling header

#include "Vfln.h"
#include "Vfln__Syms.h"

//==========

VL_CTOR_IMP(Vfln) {
    Vfln__Syms* __restrict vlSymsp = __VlSymsp = new Vfln__Syms(this, name());
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(__PVT__fln__DOT__fm0, Vfln_fmul);
    VL_CELL(__PVT__fln__DOT__fm1, Vfln_fmul);
    VL_CELL(__PVT__fln__DOT__fm2, Vfln_fmul);
    VL_CELL(__PVT__fln__DOT__fm3, Vfln_fmul);
    VL_CELL(__PVT__fln__DOT__fm4, Vfln_fmul);
    VL_CELL(__PVT__fln__DOT__fm5, Vfln_fmul);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vfln::__Vconfigure(Vfln__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vfln::~Vfln() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vfln::_eval_initial(Vfln__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfln::_eval_initial\n"); );
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfln::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfln::final\n"); );
    // Variables
    Vfln__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfln::_eval_settle(Vfln__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfln::_eval_settle\n"); );
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlSymsp->TOP__fln__DOT__fm0._combo__TOP__fln__DOT__fm0__1(vlSymsp);
    vlSymsp->TOP__fln__DOT__fm1._combo__TOP__fln__DOT__fm1__2(vlSymsp);
    vlSymsp->TOP__fln__DOT__fm2._combo__TOP__fln__DOT__fm2__3(vlSymsp);
    vlSymsp->TOP__fln__DOT__fm4._combo__TOP__fln__DOT__fm4__4(vlSymsp);
    vlSymsp->TOP__fln__DOT__fm3._combo__TOP__fln__DOT__fm3__5(vlSymsp);
    vlSymsp->TOP__fln__DOT__fm5._combo__TOP__fln__DOT__fm5__6(vlSymsp);
    vlTOPp->_combo__TOP__2(vlSymsp);
}

void Vfln::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfln::_ctor_var_reset\n"); );
    // Body
    num1 = VL_RAND_RESET_I(32);
    out1 = VL_RAND_RESET_I(32);
    fln__DOT__temp6 = VL_RAND_RESET_I(32);
    fln__DOT__fa0__DOT__largerMag = VL_RAND_RESET_I(1);
    fln__DOT__fa0__DOT__finalSign = VL_RAND_RESET_I(1);
    fln__DOT__fa0__DOT__num1Exp = VL_RAND_RESET_I(8);
    fln__DOT__fa0__DOT__num2Exp = VL_RAND_RESET_I(8);
    fln__DOT__fa0__DOT__finalExp = VL_RAND_RESET_I(8);
    fln__DOT__fa0__DOT__num1Mant = VL_RAND_RESET_I(24);
    fln__DOT__fa0__DOT__num2Mant = VL_RAND_RESET_I(24);
    fln__DOT__fa0__DOT__finalMant = VL_RAND_RESET_I(24);
    fln__DOT__fa0__DOT__sumMants = VL_RAND_RESET_I(25);
    fln__DOT__fa0__DOT__i = 0;
    fln__DOT__fa0__DOT__unrounded = VL_RAND_RESET_I(32);
    fln__DOT__fa0__DOT__r0__DOT__rounded = VL_RAND_RESET_I(32);
    fln__DOT__fa0__DOT__r0__DOT__overflowCheck = VL_RAND_RESET_I(24);
    fln__DOT__fa0__DOT__r0__DOT__mask = VL_RAND_RESET_I(23);
    fln__DOT__fa0__DOT__r0__DOT__mask2 = VL_RAND_RESET_I(23);
    fln__DOT__fa0__DOT__r0__DOT__i = 0;
    fln__DOT__fa0__DOT__r0__DOT__j = 0;
    fln__DOT__fma1__DOT__sign_out = VL_RAND_RESET_I(1);
    fln__DOT__fma1__DOT__largerMag = VL_RAND_RESET_I(1);
    fln__DOT__fma1__DOT__exp_out = VL_RAND_RESET_I(8);
    fln__DOT__fma1__DOT__final_exp = VL_RAND_RESET_I(8);
    fln__DOT__fma1__DOT__mantissa_a = VL_RAND_RESET_I(24);
    fln__DOT__fma1__DOT__mantissa_c = VL_RAND_RESET_I(24);
    fln__DOT__fma1__DOT__mantissa_mul_norm = VL_RAND_RESET_I(24);
    fln__DOT__fma1__DOT__final_mantissa = VL_RAND_RESET_I(24);
    fln__DOT__fma1__DOT__mantissa_mul_out = VL_RAND_RESET_Q(48);
    fln__DOT__fma1__DOT__sum_mants = VL_RAND_RESET_I(25);
    fln__DOT__fa1__DOT__largerMag = VL_RAND_RESET_I(1);
    fln__DOT__fa1__DOT__finalSign = VL_RAND_RESET_I(1);
    fln__DOT__fa1__DOT__num1Exp = VL_RAND_RESET_I(8);
    fln__DOT__fa1__DOT__num2Exp = VL_RAND_RESET_I(8);
    fln__DOT__fa1__DOT__finalExp = VL_RAND_RESET_I(8);
    fln__DOT__fa1__DOT__num1Mant = VL_RAND_RESET_I(24);
    fln__DOT__fa1__DOT__num2Mant = VL_RAND_RESET_I(24);
    fln__DOT__fa1__DOT__finalMant = VL_RAND_RESET_I(24);
    fln__DOT__fa1__DOT__sumMants = VL_RAND_RESET_I(25);
    fln__DOT__fa1__DOT__i = 0;
    fln__DOT__fa1__DOT__unrounded = VL_RAND_RESET_I(32);
    fln__DOT__fa1__DOT__r0__DOT__rounded = VL_RAND_RESET_I(32);
    fln__DOT__fa1__DOT__r0__DOT__overflowCheck = VL_RAND_RESET_I(24);
    fln__DOT__fa1__DOT__r0__DOT__mask = VL_RAND_RESET_I(23);
    fln__DOT__fa1__DOT__r0__DOT__mask2 = VL_RAND_RESET_I(23);
    fln__DOT__fa1__DOT__r0__DOT__i = 0;
    fln__DOT__fa1__DOT__r0__DOT__j = 0;
    fln__DOT__fa2__DOT__largerMag = VL_RAND_RESET_I(1);
    fln__DOT__fa2__DOT__finalSign = VL_RAND_RESET_I(1);
    fln__DOT__fa2__DOT__num1Exp = VL_RAND_RESET_I(8);
    fln__DOT__fa2__DOT__num2Exp = VL_RAND_RESET_I(8);
    fln__DOT__fa2__DOT__finalExp = VL_RAND_RESET_I(8);
    fln__DOT__fa2__DOT__num1Mant = VL_RAND_RESET_I(24);
    fln__DOT__fa2__DOT__num2Mant = VL_RAND_RESET_I(24);
    fln__DOT__fa2__DOT__finalMant = VL_RAND_RESET_I(24);
    fln__DOT__fa2__DOT__sumMants = VL_RAND_RESET_I(25);
    fln__DOT__fa2__DOT__i = 0;
    fln__DOT__fa2__DOT__unrounded = VL_RAND_RESET_I(32);
    fln__DOT__fa2__DOT__r0__DOT__rounded = VL_RAND_RESET_I(32);
    fln__DOT__fa2__DOT__r0__DOT__overflowCheck = VL_RAND_RESET_I(24);
    fln__DOT__fa2__DOT__r0__DOT__mask = VL_RAND_RESET_I(23);
    fln__DOT__fa2__DOT__r0__DOT__mask2 = VL_RAND_RESET_I(23);
    fln__DOT__fa2__DOT__r0__DOT__i = 0;
    fln__DOT__fa2__DOT__r0__DOT__j = 0;
    fln__DOT__fma2__DOT__sign_out = VL_RAND_RESET_I(1);
    fln__DOT__fma2__DOT__largerMag = VL_RAND_RESET_I(1);
    fln__DOT__fma2__DOT__exp_out = VL_RAND_RESET_I(8);
    fln__DOT__fma2__DOT__final_exp = VL_RAND_RESET_I(8);
    fln__DOT__fma2__DOT__mantissa_a = VL_RAND_RESET_I(24);
    fln__DOT__fma2__DOT__mantissa_c = VL_RAND_RESET_I(24);
    fln__DOT__fma2__DOT__mantissa_mul_norm = VL_RAND_RESET_I(24);
    fln__DOT__fma2__DOT__final_mantissa = VL_RAND_RESET_I(24);
    fln__DOT__fma2__DOT__mantissa_mul_out = VL_RAND_RESET_Q(48);
    fln__DOT__fma2__DOT__sum_mants = VL_RAND_RESET_I(25);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
