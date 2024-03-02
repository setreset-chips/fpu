// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpu_top.h for the primary calling header

#include "Vfpu_top.h"
#include "Vfpu_top__Syms.h"

//==========

VL_CTOR_IMP(Vfpu_top) {
    Vfpu_top__Syms* __restrict vlSymsp = __VlSymsp = new Vfpu_top__Syms(this, name());
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(__PVT__fpu_top__DOT__fmul1, Vfpu_top_fmul);
    VL_CELL(__PVT__fpu_top__DOT__fmadd1__DOT__fmul1, Vfpu_top_fmul);
    VL_CELL(__PVT__fpu_top__DOT__fmsub1__DOT__fmul1, Vfpu_top_fmul);
    VL_CELL(__PVT__fpu_top__DOT__fnmsub1__DOT__fmul1, Vfpu_top_fmul);
    VL_CELL(__PVT__fpu_top__DOT__fnmadd1__DOT__fmul1, Vfpu_top_fmul);
    VL_CELL(__PVT__fpu_top__DOT__fdiv1__DOT__fm0, Vfpu_top_fmul);
    VL_CELL(__PVT__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1, Vfpu_top_fmul);
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

void Vfpu_top::_initial__TOP__1(Vfpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_top::_initial__TOP__1\n"); );
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->fpu_top__DOT__fclass1__DOT__result = 0U;
}

void Vfpu_top::_settle__TOP__4(Vfpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_top::_settle__TOP__4\n"); );
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->fpu_top__DOT__regFile[0U] = 0x40000000U;
    vlTOPp->fpu_top__DOT__regFile[3U] = 0x40000000U;
    vlTOPp->fpu_top__DOT__regFile[0xfU] = 0x40000000U;
    if ((1U & ((vlTOPp->fpu_top__DOT__operand_one >> 0x1fU) 
               & (~ (vlTOPp->fpu_top__DOT__operand_two 
                     >> 0x1fU))))) {
        vlTOPp->fpu_top__DOT__fmin1__DOT__out = vlTOPp->fpu_top__DOT__operand_two;
        vlTOPp->fpu_top__DOT__fmax1__DOT__out = vlTOPp->fpu_top__DOT__operand_one;
        vlTOPp->fpu_top__DOT__flt1__DOT__out = 0U;
        vlTOPp->fpu_top__DOT__fle1__DOT__out = 0U;
    } else {
        vlTOPp->fpu_top__DOT__fmin1__DOT__out = ((1U 
                                                  & ((~ 
                                                      (vlTOPp->fpu_top__DOT__operand_one 
                                                       >> 0x1fU)) 
                                                     & (vlTOPp->fpu_top__DOT__operand_two 
                                                        >> 0x1fU)))
                                                  ? vlTOPp->fpu_top__DOT__operand_one
                                                  : 
                                                 ((1U 
                                                   & ((~ 
                                                       (vlTOPp->fpu_top__DOT__operand_one 
                                                        >> 0x1fU)) 
                                                      & (~ 
                                                         (vlTOPp->fpu_top__DOT__operand_two 
                                                          >> 0x1fU))))
                                                   ? 
                                                  (((0xffU 
                                                     & (vlTOPp->fpu_top__DOT__operand_one 
                                                        >> 0x17U)) 
                                                    > 
                                                    (0xffU 
                                                     & (vlTOPp->fpu_top__DOT__operand_two 
                                                        >> 0x17U)))
                                                    ? vlTOPp->fpu_top__DOT__operand_one
                                                    : 
                                                   (((0xffU 
                                                      & (vlTOPp->fpu_top__DOT__operand_two 
                                                         >> 0x17U)) 
                                                     > 
                                                     (0xffU 
                                                      & (vlTOPp->fpu_top__DOT__operand_one 
                                                         >> 0x17U)))
                                                     ? vlTOPp->fpu_top__DOT__operand_two
                                                     : 
                                                    (((0x7fffffU 
                                                       & vlTOPp->fpu_top__DOT__operand_one) 
                                                      >= 
                                                      (0x7fffffU 
                                                       & vlTOPp->fpu_top__DOT__operand_two))
                                                      ? vlTOPp->fpu_top__DOT__operand_one
                                                      : vlTOPp->fpu_top__DOT__operand_two)))
                                                   : 
                                                  (((0xffU 
                                                     & (vlTOPp->fpu_top__DOT__operand_one 
                                                        >> 0x17U)) 
                                                    > 
                                                    (0xffU 
                                                     & (vlTOPp->fpu_top__DOT__operand_two 
                                                        >> 0x17U)))
                                                    ? vlTOPp->fpu_top__DOT__operand_two
                                                    : 
                                                   (((0xffU 
                                                      & (vlTOPp->fpu_top__DOT__operand_two 
                                                         >> 0x17U)) 
                                                     > 
                                                     (0xffU 
                                                      & (vlTOPp->fpu_top__DOT__operand_one 
                                                         >> 0x17U)))
                                                     ? vlTOPp->fpu_top__DOT__operand_one
                                                     : 
                                                    (((0x7fffffU 
                                                       & vlTOPp->fpu_top__DOT__operand_one) 
                                                      >= 
                                                      (0x7fffffU 
                                                       & vlTOPp->fpu_top__DOT__operand_two))
                                                      ? vlTOPp->fpu_top__DOT__operand_two
                                                      : vlTOPp->fpu_top__DOT__operand_one)))));
        vlTOPp->fpu_top__DOT__fmax1__DOT__out = ((1U 
                                                  & ((~ 
                                                      (vlTOPp->fpu_top__DOT__operand_one 
                                                       >> 0x1fU)) 
                                                     & (vlTOPp->fpu_top__DOT__operand_two 
                                                        >> 0x1fU)))
                                                  ? vlTOPp->fpu_top__DOT__operand_two
                                                  : 
                                                 ((1U 
                                                   & ((~ 
                                                       (vlTOPp->fpu_top__DOT__operand_one 
                                                        >> 0x1fU)) 
                                                      & (~ 
                                                         (vlTOPp->fpu_top__DOT__operand_two 
                                                          >> 0x1fU))))
                                                   ? 
                                                  (((0xffU 
                                                     & (vlTOPp->fpu_top__DOT__operand_one 
                                                        >> 0x17U)) 
                                                    > 
                                                    (0xffU 
                                                     & (vlTOPp->fpu_top__DOT__operand_two 
                                                        >> 0x17U)))
                                                    ? vlTOPp->fpu_top__DOT__operand_two
                                                    : 
                                                   (((0xffU 
                                                      & (vlTOPp->fpu_top__DOT__operand_two 
                                                         >> 0x17U)) 
                                                     > 
                                                     (0xffU 
                                                      & (vlTOPp->fpu_top__DOT__operand_one 
                                                         >> 0x17U)))
                                                     ? vlTOPp->fpu_top__DOT__operand_one
                                                     : 
                                                    (((0x7fffffU 
                                                       & vlTOPp->fpu_top__DOT__operand_one) 
                                                      >= 
                                                      (0x7fffffU 
                                                       & vlTOPp->fpu_top__DOT__operand_two))
                                                      ? vlTOPp->fpu_top__DOT__operand_two
                                                      : vlTOPp->fpu_top__DOT__operand_one)))
                                                   : 
                                                  (((0xffU 
                                                     & (vlTOPp->fpu_top__DOT__operand_one 
                                                        >> 0x17U)) 
                                                    > 
                                                    (0xffU 
                                                     & (vlTOPp->fpu_top__DOT__operand_two 
                                                        >> 0x17U)))
                                                    ? vlTOPp->fpu_top__DOT__operand_one
                                                    : 
                                                   (((0xffU 
                                                      & (vlTOPp->fpu_top__DOT__operand_two 
                                                         >> 0x17U)) 
                                                     > 
                                                     (0xffU 
                                                      & (vlTOPp->fpu_top__DOT__operand_one 
                                                         >> 0x17U)))
                                                     ? vlTOPp->fpu_top__DOT__operand_two
                                                     : 
                                                    (((0x7fffffU 
                                                       & vlTOPp->fpu_top__DOT__operand_one) 
                                                      >= 
                                                      (0x7fffffU 
                                                       & vlTOPp->fpu_top__DOT__operand_two))
                                                      ? vlTOPp->fpu_top__DOT__operand_one
                                                      : vlTOPp->fpu_top__DOT__operand_two)))));
        vlTOPp->fpu_top__DOT__flt1__DOT__out = ((1U 
                                                 & ((~ 
                                                     (vlTOPp->fpu_top__DOT__operand_one 
                                                      >> 0x1fU)) 
                                                    & (vlTOPp->fpu_top__DOT__operand_two 
                                                       >> 0x1fU)))
                                                 ? 1U
                                                 : 
                                                ((1U 
                                                  & ((~ 
                                                      (vlTOPp->fpu_top__DOT__operand_one 
                                                       >> 0x1fU)) 
                                                     & (~ 
                                                        (vlTOPp->fpu_top__DOT__operand_two 
                                                         >> 0x1fU))))
                                                  ? 
                                                 (((0xffU 
                                                    & (vlTOPp->fpu_top__DOT__operand_one 
                                                       >> 0x17U)) 
                                                   > 
                                                   (0xffU 
                                                    & (vlTOPp->fpu_top__DOT__operand_two 
                                                       >> 0x17U)))
                                                   ? 1U
                                                   : 
                                                  (((0xffU 
                                                     & (vlTOPp->fpu_top__DOT__operand_two 
                                                        >> 0x17U)) 
                                                    > 
                                                    (0xffU 
                                                     & (vlTOPp->fpu_top__DOT__operand_one 
                                                        >> 0x17U)))
                                                    ? 0U
                                                    : 
                                                   (((0x7fffffU 
                                                      & vlTOPp->fpu_top__DOT__operand_one) 
                                                     < 
                                                     (0x7fffffU 
                                                      & vlTOPp->fpu_top__DOT__operand_two))
                                                     ? 0U
                                                     : 1U)))
                                                  : 
                                                 (((0xffU 
                                                    & (vlTOPp->fpu_top__DOT__operand_one 
                                                       >> 0x17U)) 
                                                   > 
                                                   (0xffU 
                                                    & (vlTOPp->fpu_top__DOT__operand_two 
                                                       >> 0x17U)))
                                                   ? 0U
                                                   : 
                                                  (((0xffU 
                                                     & (vlTOPp->fpu_top__DOT__operand_two 
                                                        >> 0x17U)) 
                                                    > 
                                                    (0xffU 
                                                     & (vlTOPp->fpu_top__DOT__operand_one 
                                                        >> 0x17U)))
                                                    ? 1U
                                                    : 
                                                   (((0x7fffffU 
                                                      & vlTOPp->fpu_top__DOT__operand_one) 
                                                     < 
                                                     (0x7fffffU 
                                                      & vlTOPp->fpu_top__DOT__operand_two))
                                                     ? 1U
                                                     : 0U)))));
        vlTOPp->fpu_top__DOT__fle1__DOT__out = ((1U 
                                                 & ((~ 
                                                     (vlTOPp->fpu_top__DOT__operand_one 
                                                      >> 0x1fU)) 
                                                    & (vlTOPp->fpu_top__DOT__operand_two 
                                                       >> 0x1fU)))
                                                 ? 1U
                                                 : 
                                                ((1U 
                                                  & ((~ 
                                                      (vlTOPp->fpu_top__DOT__operand_one 
                                                       >> 0x1fU)) 
                                                     & (~ 
                                                        (vlTOPp->fpu_top__DOT__operand_two 
                                                         >> 0x1fU))))
                                                  ? 
                                                 (((0xffU 
                                                    & (vlTOPp->fpu_top__DOT__operand_one 
                                                       >> 0x17U)) 
                                                   > 
                                                   (0xffU 
                                                    & (vlTOPp->fpu_top__DOT__operand_two 
                                                       >> 0x17U)))
                                                   ? 1U
                                                   : 
                                                  (((0xffU 
                                                     & (vlTOPp->fpu_top__DOT__operand_two 
                                                        >> 0x17U)) 
                                                    > 
                                                    (0xffU 
                                                     & (vlTOPp->fpu_top__DOT__operand_one 
                                                        >> 0x17U)))
                                                    ? 0U
                                                    : 
                                                   (((0x7fffffU 
                                                      & vlTOPp->fpu_top__DOT__operand_one) 
                                                     <= 
                                                     (0x7fffffU 
                                                      & vlTOPp->fpu_top__DOT__operand_two))
                                                     ? 0U
                                                     : 1U)))
                                                  : 
                                                 (((0xffU 
                                                    & (vlTOPp->fpu_top__DOT__operand_one 
                                                       >> 0x17U)) 
                                                   > 
                                                   (0xffU 
                                                    & (vlTOPp->fpu_top__DOT__operand_two 
                                                       >> 0x17U)))
                                                   ? 0U
                                                   : 
                                                  (((0xffU 
                                                     & (vlTOPp->fpu_top__DOT__operand_two 
                                                        >> 0x17U)) 
                                                    > 
                                                    (0xffU 
                                                     & (vlTOPp->fpu_top__DOT__operand_one 
                                                        >> 0x17U)))
                                                    ? 1U
                                                    : 
                                                   (((0x7fffffU 
                                                      & vlTOPp->fpu_top__DOT__operand_one) 
                                                     <= 
                                                     (0x7fffffU 
                                                      & vlTOPp->fpu_top__DOT__operand_two))
                                                     ? 1U
                                                     : 0U)))));
    }
    if ((0x7f800000U == vlTOPp->fpu_top__DOT__operand_one)) {
        vlTOPp->fpu_top__DOT__fclass1__DOT__result 
            = (0xffffff7fU & vlTOPp->fpu_top__DOT__fclass1__DOT__result);
    } else {
        if ((0xff800000U == vlTOPp->fpu_top__DOT__operand_one)) {
            vlTOPp->fpu_top__DOT__fclass1__DOT__result 
                = (1U | vlTOPp->fpu_top__DOT__fclass1__DOT__result);
        } else {
            if ((0x1ffU == (0x1ffU & (vlTOPp->fpu_top__DOT__operand_one 
                                      >> 0x16U)))) {
                vlTOPp->fpu_top__DOT__fclass1__DOT__result 
                    = (0x200U | vlTOPp->fpu_top__DOT__fclass1__DOT__result);
            } else {
                if ((0xffU == (0xffU & (vlTOPp->fpu_top__DOT__operand_one 
                                        >> 0x17U)))) {
                    vlTOPp->fpu_top__DOT__fclass1__DOT__result 
                        = (0x100U | vlTOPp->fpu_top__DOT__fclass1__DOT__result);
                } else {
                    if ((0x80000000U == vlTOPp->fpu_top__DOT__operand_one)) {
                        vlTOPp->fpu_top__DOT__fclass1__DOT__result 
                            = (8U | vlTOPp->fpu_top__DOT__fclass1__DOT__result);
                    } else {
                        if ((0U == vlTOPp->fpu_top__DOT__operand_one)) {
                            vlTOPp->fpu_top__DOT__fclass1__DOT__result 
                                = (0x10U | vlTOPp->fpu_top__DOT__fclass1__DOT__result);
                        } else {
                            if ((0U == (0x1ffU & (vlTOPp->fpu_top__DOT__operand_one 
                                                  >> 0x17U)))) {
                                vlTOPp->fpu_top__DOT__fclass1__DOT__result 
                                    = (0x20U | vlTOPp->fpu_top__DOT__fclass1__DOT__result);
                            } else {
                                if ((0x100U == (0x1ffU 
                                                & (vlTOPp->fpu_top__DOT__operand_one 
                                                   >> 0x17U)))) {
                                    vlTOPp->fpu_top__DOT__fclass1__DOT__result 
                                        = (4U | vlTOPp->fpu_top__DOT__fclass1__DOT__result);
                                } else {
                                    if ((0x80000000U 
                                         & vlTOPp->fpu_top__DOT__operand_one)) {
                                        vlTOPp->fpu_top__DOT__fclass1__DOT__result 
                                            = (2U | vlTOPp->fpu_top__DOT__fclass1__DOT__result);
                                    } else {
                                        if ((1U & (~ 
                                                   (vlTOPp->fpu_top__DOT__operand_one 
                                                    >> 0x1fU)))) {
                                            vlTOPp->fpu_top__DOT__fclass1__DOT__result 
                                                = (0x40U 
                                                   | vlTOPp->fpu_top__DOT__fclass1__DOT__result);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
        = ((IData)(0x3f800000U) + vlTOPp->fpu_top__DOT__operand_one);
    vlTOPp->fpu_top__DOT__fadd1__DOT__finalSign = 0U;
    vlTOPp->fpu_top__DOT__fadd1__DOT__largerMag = 0U;
    vlTOPp->fpu_top__DOT__fadd1__DOT__num1Exp = (0xffU 
                                                 & (vlTOPp->fpu_top__DOT__operand_one 
                                                    >> 0x17U));
    vlTOPp->fpu_top__DOT__fadd1__DOT__num2Exp = (0xffU 
                                                 & (vlTOPp->fpu_top__DOT__operand_two 
                                                    >> 0x17U));
    vlTOPp->fpu_top__DOT__fadd1__DOT__num1Mant = (0x800000U 
                                                  | (0x7fffffU 
                                                     & vlTOPp->fpu_top__DOT__operand_one));
    vlTOPp->fpu_top__DOT__fadd1__DOT__num2Mant = (0x800000U 
                                                  | (0x7fffffU 
                                                     & vlTOPp->fpu_top__DOT__operand_two));
    if (((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__num1Exp) 
         < (IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__num2Exp))) {
        vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
            = vlTOPp->fpu_top__DOT__fadd1__DOT__num2Exp;
        vlTOPp->fpu_top__DOT__fadd1__DOT__num1Mant 
            = ((0x17U >= (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                   - (IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__num1Exp))))
                ? (0xffffffU & (vlTOPp->fpu_top__DOT__fadd1__DOT__num1Mant 
                                >> (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                             - (IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__num1Exp)))))
                : 0U);
        vlTOPp->fpu_top__DOT__fadd1__DOT__largerMag = 1U;
    } else {
        if (((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__num2Exp) 
             < (IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__num1Exp))) {
            vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                = vlTOPp->fpu_top__DOT__fadd1__DOT__num1Exp;
            vlTOPp->fpu_top__DOT__fadd1__DOT__num2Mant 
                = ((0x17U >= (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                       - (IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__num2Exp))))
                    ? (0xffffffU & (vlTOPp->fpu_top__DOT__fadd1__DOT__num2Mant 
                                    >> (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                 - (IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__num2Exp)))))
                    : 0U);
            vlTOPp->fpu_top__DOT__fadd1__DOT__largerMag = 0U;
        } else {
            vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                = vlTOPp->fpu_top__DOT__fadd1__DOT__num1Exp;
            vlTOPp->fpu_top__DOT__fadd1__DOT__largerMag 
                = (vlTOPp->fpu_top__DOT__fadd1__DOT__num2Mant 
                   > vlTOPp->fpu_top__DOT__fadd1__DOT__num1Mant);
        }
    }
    if ((0x80000000U & (vlTOPp->fpu_top__DOT__operand_one 
                        & vlTOPp->fpu_top__DOT__operand_two))) {
        vlTOPp->fpu_top__DOT__fadd1__DOT__sumMants 
            = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fadd1__DOT__num2Mant 
                             + vlTOPp->fpu_top__DOT__fadd1__DOT__num1Mant));
        vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
            = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp)));
        vlTOPp->fpu_top__DOT__fadd1__DOT__finalSign = 0U;
        vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
            = (0xffffffU & (vlTOPp->fpu_top__DOT__fadd1__DOT__sumMants 
                            >> 1U));
    } else {
        if ((1U & ((vlTOPp->fpu_top__DOT__operand_one 
                    >> 0x1fU) & (~ (vlTOPp->fpu_top__DOT__operand_two 
                                    >> 0x1fU))))) {
            vlTOPp->fpu_top__DOT__fadd1__DOT__sumMants 
                = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fadd1__DOT__num1Mant 
                                 - vlTOPp->fpu_top__DOT__fadd1__DOT__num2Mant));
            vlTOPp->fpu_top__DOT__fadd1__DOT__finalSign 
                = vlTOPp->fpu_top__DOT__fadd1__DOT__largerMag;
            vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                = (0xffffffU & vlTOPp->fpu_top__DOT__fadd1__DOT__sumMants);
            vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                = (0xffffffU & ((0x1000000U & vlTOPp->fpu_top__DOT__fadd1__DOT__sumMants)
                                 ? ((IData)(0xffffffffU) 
                                    * vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)
                                 : vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant));
        } else {
            if ((1U & ((~ (vlTOPp->fpu_top__DOT__operand_one 
                           >> 0x1fU)) & (vlTOPp->fpu_top__DOT__operand_two 
                                         >> 0x1fU)))) {
                vlTOPp->fpu_top__DOT__fadd1__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fadd1__DOT__num2Mant 
                                     - vlTOPp->fpu_top__DOT__fadd1__DOT__num1Mant));
                vlTOPp->fpu_top__DOT__fadd1__DOT__finalSign 
                    = (1U & (~ (IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__largerMag)));
                vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                    = (0xffffffU & vlTOPp->fpu_top__DOT__fadd1__DOT__sumMants);
                vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                    = (0xffffffU & ((0x1000000U & vlTOPp->fpu_top__DOT__fadd1__DOT__sumMants)
                                     ? ((IData)(0xffffffffU) 
                                        * vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)
                                     : vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant));
            } else {
                vlTOPp->fpu_top__DOT__fadd1__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fadd1__DOT__num2Mant 
                                     + vlTOPp->fpu_top__DOT__fadd1__DOT__num1Mant));
                vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp)));
                vlTOPp->fpu_top__DOT__fadd1__DOT__finalSign = 1U;
                vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fpu_top__DOT__fadd1__DOT__sumMants 
                                    >> 1U));
            }
        }
    }
    if ((0x800000U & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
        vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
            = (0xffffffU & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                            << 1U));
    } else {
        if ((0x400000U & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
            vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                = (0xffffffU & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                << 2U));
            vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                            - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                    << 3U));
                vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                    = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                    vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                        = (0xffffffU & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                        << 4U));
                    vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                        = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                        vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                            = (0xffffffU & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                            << 5U));
                        vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                            = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                            vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                << 6U));
                            vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                                vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                    = (0xffffffU & 
                                       (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                        << 7U));
                                vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                    = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                                    vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                        = (0xffffffU 
                                           & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                              << 8U));
                                    vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                                        vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                            = (0xffffffU 
                                               & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                  << 9U));
                                        vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                                            vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                = (0xffffffU 
                                                   & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                      << 0xaU));
                                            vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                                                vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                        << 0xbU));
                                                vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                                                    vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                            << 0xcU));
                                                    vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                                                        vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                << 0xdU));
                                                        vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                                                            vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                    << 0xeU));
                                                            vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                                                                vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                        << 0xfU));
                                                                vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                                                                    vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                            << 0x10U));
                                                                    vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                                                                        vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                                << 0x11U));
                                                                        vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                                                                            vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                                << 0x12U));
                                                                            vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                                << 0x13U));
                                                                                vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                                << 0x14U));
                                                                                vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                                << 0x15U));
                                                                                vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                                << 0x16U));
                                                                                vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                                                << 0x17U));
                                                                                vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(1U)));
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((0U == vlTOPp->fpu_top__DOT__operand_one) 
         & (0U == (IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__num2Exp)))) {
        vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant = 0U;
        vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp = 0U;
    }
    vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2 
        = ((0x80000000U & ((~ (vlTOPp->fpu_top__DOT__operand_two 
                               >> 0x1fU)) << 0x1fU)) 
           | (0x7fffffffU & vlTOPp->fpu_top__DOT__operand_two));
    vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1 = ((0x80000000U 
                                                & ((~ 
                                                    (vlTOPp->fpu_top__DOT__operand_one 
                                                     >> 0x1fU)) 
                                                   << 0x1fU)) 
                                               | (0x7fffffffU 
                                                  & vlTOPp->fpu_top__DOT__operand_one));
    vlTOPp->fpu_out = vlTOPp->fpu_top__DOT__writeback_data;
    vlTOPp->fpu_top__DOT__rm = (7U & ((7U == (7U & 
                                              (vlTOPp->fpu_top__DOT__ins_p2 
                                               >> 0xcU)))
                                       ? (vlTOPp->fpu_top__DOT__fcsr 
                                          >> 5U) : 
                                      (vlTOPp->fpu_top__DOT__ins_p2 
                                       >> 0xcU)));
    vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
        = (vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
           >> 1U);
    vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded = (
                                                   (0x80000000U 
                                                    & ((~ (IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalSign)) 
                                                       << 0x1fU)) 
                                                   | (((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                       << 0x17U) 
                                                      | (0x7fffffU 
                                                         & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                            >> 1U))));
    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalSign = 0U;
    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__largerMag = 0U;
    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Exp 
        = (0xffU & (vlTOPp->fpu_top__DOT__operand_one 
                    >> 0x17U));
    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Exp 
        = (0xffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2 
                    >> 0x17U));
    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Mant 
        = (0x800000U | (0x7fffffU & vlTOPp->fpu_top__DOT__operand_one));
    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Mant 
        = (0x800000U | (0x7fffffU & vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2));
    if (((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Exp) 
         < (IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Exp))) {
        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
            = vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Exp;
        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Mant 
            = ((0x17U >= (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                   - (IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Exp))))
                ? (0xffffffU & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Mant 
                                >> (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                             - (IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Exp)))))
                : 0U);
        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__largerMag = 1U;
    } else {
        if (((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Exp) 
             < (IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Exp))) {
            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                = vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Exp;
            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Mant 
                = ((0x17U >= (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                       - (IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Exp))))
                    ? (0xffffffU & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Mant 
                                    >> (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                 - (IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Exp)))))
                    : 0U);
            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__largerMag = 0U;
        } else {
            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                = vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Exp;
            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__largerMag 
                = (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Mant 
                   > vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Mant);
        }
    }
    if ((0x80000000U & (vlTOPp->fpu_top__DOT__operand_one 
                        & vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2))) {
        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__sumMants 
            = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Mant 
                             + vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Mant));
        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
            = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp)));
        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalSign = 0U;
        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
            = (0xffffffU & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__sumMants 
                            >> 1U));
    } else {
        if ((1U & ((vlTOPp->fpu_top__DOT__operand_one 
                    >> 0x1fU) & (~ (vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2 
                                    >> 0x1fU))))) {
            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__sumMants 
                = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Mant 
                                 - vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Mant));
            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalSign 
                = vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__largerMag;
            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                = (0xffffffU & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__sumMants);
            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                = (0xffffffU & ((0x1000000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__sumMants)
                                 ? ((IData)(0xffffffffU) 
                                    * vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)
                                 : vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant));
        } else {
            if ((1U & ((~ (vlTOPp->fpu_top__DOT__operand_one 
                           >> 0x1fU)) & (vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2 
                                         >> 0x1fU)))) {
                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Mant 
                                     - vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Mant));
                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalSign 
                    = (1U & (~ (IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__largerMag)));
                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                    = (0xffffffU & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__sumMants);
                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                    = (0xffffffU & ((0x1000000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__sumMants)
                                     ? ((IData)(0xffffffffU) 
                                        * vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)
                                     : vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant));
            } else {
                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Mant 
                                     + vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Mant));
                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp)));
                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalSign = 1U;
                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__sumMants 
                                    >> 1U));
            }
        }
    }
    if ((0x800000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
            = (0xffffffU & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                            << 1U));
    } else {
        if ((0x400000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                = (0xffffffU & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                << 2U));
            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                            - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                    << 3U));
                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                    = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                        = (0xffffffU & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                        << 4U));
                    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                        = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                            = (0xffffffU & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                            << 5U));
                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                            = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                << 6U));
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                    = (0xffffffU & 
                                       (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                        << 7U));
                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                    = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                        = (0xffffffU 
                                           & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                              << 8U));
                                    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                            = (0xffffffU 
                                               & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                  << 9U));
                                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                = (0xffffffU 
                                                   & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                      << 0xaU));
                                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                        << 0xbU));
                                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                            << 0xcU));
                                                    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                << 0xdU));
                                                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                    << 0xeU));
                                                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                        << 0xfU));
                                                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                                    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                            << 0x10U));
                                                                    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x11U));
                                                                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x12U));
                                                                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x13U));
                                                                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x14U));
                                                                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x15U));
                                                                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x16U));
                                                                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x17U));
                                                                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(1U)));
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((0U == vlTOPp->fpu_top__DOT__operand_one) 
         & (0U == (IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Exp)))) {
        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant = 0U;
        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp = 0U;
    }
    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalSign = 0U;
    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__largerMag = 0U;
    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Exp 
        = (0xffU & (vlTOPp->fpu_top__DOT__operand_one 
                    >> 0x17U));
    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Exp 
        = (0xffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2 
                    >> 0x17U));
    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Mant 
        = (0x800000U | (0x7fffffU & vlTOPp->fpu_top__DOT__operand_one));
    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Mant 
        = (0x800000U | (0x7fffffU & vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2));
    if (((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Exp) 
         < (IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Exp))) {
        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
            = vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Exp;
        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Mant 
            = ((0x17U >= (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                   - (IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Exp))))
                ? (0xffffffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Mant 
                                >> (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                             - (IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Exp)))))
                : 0U);
        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__largerMag = 1U;
    } else {
        if (((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Exp) 
             < (IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Exp))) {
            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                = vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Exp;
            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Mant 
                = ((0x17U >= (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                       - (IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Exp))))
                    ? (0xffffffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Mant 
                                    >> (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                                 - (IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Exp)))))
                    : 0U);
            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__largerMag = 0U;
        } else {
            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                = vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Exp;
            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__largerMag 
                = (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Mant 
                   > vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Mant);
        }
    }
    if ((0x80000000U & (vlTOPp->fpu_top__DOT__operand_one 
                        & vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2))) {
        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__sumMants 
            = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Mant 
                             + vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Mant));
        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
            = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp)));
        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalSign = 0U;
        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
            = (0xffffffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__sumMants 
                            >> 1U));
    } else {
        if ((1U & ((vlTOPp->fpu_top__DOT__operand_one 
                    >> 0x1fU) & (~ (vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2 
                                    >> 0x1fU))))) {
            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__sumMants 
                = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Mant 
                                 - vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Mant));
            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalSign 
                = vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__largerMag;
            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                = (0xffffffU & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__sumMants);
            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                = (0xffffffU & ((0x1000000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__sumMants)
                                 ? ((IData)(0xffffffffU) 
                                    * vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)
                                 : vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant));
        } else {
            if ((1U & ((~ (vlTOPp->fpu_top__DOT__operand_one 
                           >> 0x1fU)) & (vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2 
                                         >> 0x1fU)))) {
                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Mant 
                                     - vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Mant));
                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalSign 
                    = (1U & (~ (IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__largerMag)));
                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                    = (0xffffffU & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__sumMants);
                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                    = (0xffffffU & ((0x1000000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__sumMants)
                                     ? ((IData)(0xffffffffU) 
                                        * vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)
                                     : vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant));
            } else {
                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Mant 
                                     + vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Mant));
                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp)));
                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalSign = 1U;
                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__sumMants 
                                    >> 1U));
            }
        }
    }
    if ((0x800000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
            = (0xffffffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                            << 1U));
    } else {
        if ((0x400000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                = (0xffffffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                << 2U));
            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                            - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                    << 3U));
                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                    = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                        = (0xffffffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                        << 4U));
                    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                        = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                            = (0xffffffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                            << 5U));
                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                            = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                << 6U));
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                    = (0xffffffU & 
                                       (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                        << 7U));
                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                    = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                                    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                        = (0xffffffU 
                                           & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                              << 8U));
                                    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                            = (0xffffffU 
                                               & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                  << 9U));
                                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                = (0xffffffU 
                                                   & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                      << 0xaU));
                                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                        << 0xbU));
                                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                                                    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                            << 0xcU));
                                                    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                                                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                << 0xdU));
                                                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                                                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                    << 0xeU));
                                                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                                                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                        << 0xfU));
                                                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                                                                    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                            << 0x10U));
                                                                    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                                                                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x11U));
                                                                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                                                                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x12U));
                                                                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x13U));
                                                                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x14U));
                                                                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x15U));
                                                                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x16U));
                                                                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x17U));
                                                                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(1U)));
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((0U == vlTOPp->fpu_top__DOT__operand_one) 
         & (0U == (IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Exp)))) {
        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant = 0U;
        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp = 0U;
    }
    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalSign = 0U;
    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__largerMag = 0U;
    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Exp 
        = (0xffU & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1 
                    >> 0x17U));
    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Exp 
        = (0xffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2 
                    >> 0x17U));
    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Mant 
        = (0x800000U | (0x7fffffU & vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1));
    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Mant 
        = (0x800000U | (0x7fffffU & vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2));
    if (((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Exp) 
         < (IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Exp))) {
        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
            = vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Exp;
        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Mant 
            = ((0x17U >= (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                   - (IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Exp))))
                ? (0xffffffU & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Mant 
                                >> (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                             - (IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Exp)))))
                : 0U);
        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__largerMag = 1U;
    } else {
        if (((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Exp) 
             < (IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Exp))) {
            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                = vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Exp;
            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Mant 
                = ((0x17U >= (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                       - (IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Exp))))
                    ? (0xffffffU & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Mant 
                                    >> (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                 - (IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Exp)))))
                    : 0U);
            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__largerMag = 0U;
        } else {
            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                = vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Exp;
            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__largerMag 
                = (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Mant 
                   > vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Mant);
        }
    }
    if ((0x80000000U & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1 
                        & vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2))) {
        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__sumMants 
            = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Mant 
                             + vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Mant));
        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
            = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp)));
        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalSign = 0U;
        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
            = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__sumMants 
                            >> 1U));
    } else {
        if ((1U & ((vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1 
                    >> 0x1fU) & (~ (vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2 
                                    >> 0x1fU))))) {
            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__sumMants 
                = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Mant 
                                 - vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Mant));
            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalSign 
                = vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__largerMag;
            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                = (0xffffffU & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__sumMants);
            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                = (0xffffffU & ((0x1000000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__sumMants)
                                 ? ((IData)(0xffffffffU) 
                                    * vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)
                                 : vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant));
        } else {
            if ((1U & ((~ (vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1 
                           >> 0x1fU)) & (vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2 
                                         >> 0x1fU)))) {
                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Mant 
                                     - vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Mant));
                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalSign 
                    = (1U & (~ (IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__largerMag)));
                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                    = (0xffffffU & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__sumMants);
                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                    = (0xffffffU & ((0x1000000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__sumMants)
                                     ? ((IData)(0xffffffffU) 
                                        * vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)
                                     : vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant));
            } else {
                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Mant 
                                     + vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Mant));
                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp)));
                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalSign = 1U;
                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__sumMants 
                                    >> 1U));
            }
        }
    }
    if ((0x800000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
            = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                            << 1U));
    } else {
        if ((0x400000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                << 2U));
            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                            - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                    << 3U));
                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                    = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                        = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                        << 4U));
                    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                        = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                            = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                            << 5U));
                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                            = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                << 6U));
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                    = (0xffffffU & 
                                       (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                        << 7U));
                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                    = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                        = (0xffffffU 
                                           & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                              << 8U));
                                    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                            = (0xffffffU 
                                               & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                  << 9U));
                                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                = (0xffffffU 
                                                   & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                      << 0xaU));
                                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                        << 0xbU));
                                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                            << 0xcU));
                                                    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                << 0xdU));
                                                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                    << 0xeU));
                                                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                        << 0xfU));
                                                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                                    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                            << 0x10U));
                                                                    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x11U));
                                                                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x12U));
                                                                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x13U));
                                                                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x14U));
                                                                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x15U));
                                                                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x16U));
                                                                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                                                << 0x17U));
                                                                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                                                                - (IData)(1U)));
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((0U == vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1) 
         & (0U == (IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Exp)))) {
        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant = 0U;
        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp = 0U;
    }
    if ((0U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
        if ((4U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num)) {
            if ((0U == (3U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num))) {
                if ((8U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num)) {
                    vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck 
                        = (0x7fffffU & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num);
                    vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck 
                        = (0xffffffU & ((IData)(1U) 
                                        + vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck));
                    vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                        = ((0x800000U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck)
                            ? ((0x80000000U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num) 
                               | ((0x7f800000U & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                                                    >> 0x17U)) 
                                                  << 0x17U)) 
                                  | (0x7fffffU & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck)))
                            : ((0xff800000U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num) 
                               | (0x7fffffU & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck)));
                } else {
                    vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                        = vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num;
                }
            } else {
                vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck 
                    = (0x7fffffU & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num);
                vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck 
                    = (0xffffffU & ((IData)(1U) + vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck));
                vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                    = ((0x800000U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck)
                        ? ((0x80000000U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num) 
                           | ((0x7f800000U & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                              | (0x7fffffU & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck)))
                        : ((0xff800000U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num) 
                           | (0x7fffffU & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck)));
            }
        } else {
            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                = vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num;
        }
    } else {
        if ((1U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i 
                = VL_EXTENDS_II(32,8, (0xffU & ((vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                                                 >> 0x17U) 
                                                - (IData)(0x7fU))));
            if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i) 
                 & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i))) {
                vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask 
                    = ((0x16U >= vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i)
                        ? (0x7fffffU & (0x7fffffU >> vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i))
                        : 0U);
                vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask 
                    = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask));
                vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                    = ((0xff800000U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num) 
                       | (vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                          & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask));
            } else {
                vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                    = ((0U == vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i)
                        ? 0x3f800000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i)
                                          ? vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num
                                          : 0U));
            }
        } else {
            if ((2U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                if ((0x80000000U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num)) {
                    vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i 
                        = VL_EXTENDS_II(32,8, (0xffU 
                                               & ((vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                                                   >> 0x17U) 
                                                  - (IData)(0x7fU))));
                    if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i) 
                         & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i))) {
                        vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask 
                            = ((0x16U >= vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i)
                                ? (0x7fffffU & (0x7fffffU 
                                                >> vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask2 
                            = ((0x16U >= (vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i 
                                          - (IData)(1U)))
                                ? (0x7fffffU & (0x400000U 
                                                >> 
                                                (vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i 
                                                 - (IData)(1U))))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask 
                            = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask));
                        vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask 
                            = (vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                               & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask);
                        vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck 
                            = vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask;
                        vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck 
                            = (0xffffffU & (vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck 
                                            + vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask2));
                        vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                            = ((0x800000U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck)
                                ? ((0x80000000U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num) 
                                   | ((0x7f800000U 
                                       & (((IData)(1U) 
                                           + (vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                                              >> 0x17U)) 
                                          << 0x17U)) 
                                      | (0x7fffffU 
                                         & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num)))
                                : ((0xff800000U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num) 
                                   | (0x7fffffU & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck)));
                    } else {
                        vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                            = ((0U == vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i)
                                ? 0x40000000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i)
                                                  ? vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num
                                                  : 0U));
                    }
                } else {
                    vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i 
                        = VL_EXTENDS_II(32,8, (0xffU 
                                               & ((vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                                                   >> 0x17U) 
                                                  - (IData)(0x7fU))));
                    if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i) 
                         & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i))) {
                        vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask 
                            = ((0x16U >= vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i)
                                ? (0x7fffffU & (0x7fffffU 
                                                >> vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask 
                            = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask));
                        vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                            = ((0xff800000U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num) 
                               | (vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                                  & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask));
                    } else {
                        vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                            = ((0U == vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i)
                                ? 0x3f800000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i)
                                                  ? vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num
                                                  : 0U));
                    }
                }
            } else {
                if ((3U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                    if ((0x80000000U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num)) {
                        vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                                = ((0xff800000U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num) 
                                   | (vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                                      & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask));
                        } else {
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i)
                                    ? 0x3f800000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num
                                     : 0U));
                        }
                    } else {
                        vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask2 
                                = ((0x16U >= (vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i 
                                              - (IData)(1U)))
                                    ? (0x7fffffU & 
                                       (0x400000U >> 
                                        (vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i 
                                         - (IData)(1U))))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask 
                                = (vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                                   & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask);
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck 
                                = vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask;
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck 
                                                + vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask2));
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                                = ((0x800000U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck)
                                    ? ((0x80000000U 
                                        & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num) 
                                       | ((0x7f800000U 
                                           & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                                          | (0x7fffffU 
                                             & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num)))
                                    : ((0xff800000U 
                                        & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num) 
                                       | (0x7fffffU 
                                          & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck)));
                        } else {
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i)
                                    ? 0x40000000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num
                                     : 0U));
                        }
                    }
                } else {
                    if ((4U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                        vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask2 
                                = ((0x16U >= (vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i 
                                              - (IData)(1U)))
                                    ? (0x7fffffU & 
                                       (0x400000U >> 
                                        (vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i 
                                         - (IData)(1U))))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask 
                                = (vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                                   & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask);
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck 
                                = vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask;
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck 
                                                + vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask2));
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                                = ((0x800000U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck)
                                    ? ((0x80000000U 
                                        & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num) 
                                       | ((0x7f800000U 
                                           & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                                          | (0x7fffffU 
                                             & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num)))
                                    : ((0xff800000U 
                                        & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num) 
                                       | (0x7fffffU 
                                          & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck)));
                        } else {
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i)
                                    ? 0x40000000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num
                                     : 0U));
                        }
                    } else {
                        if ((4U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num)) {
                            if ((0U == (3U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num))) {
                                if ((8U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num)) {
                                    vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck 
                                        = (0x7fffffU 
                                           & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num);
                                    vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck 
                                        = (0xffffffU 
                                           & ((IData)(1U) 
                                              + vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck));
                                    vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                                        = ((0x800000U 
                                            & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck)
                                            ? ((0x80000000U 
                                                & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num) 
                                               | ((0x7f800000U 
                                                   & (((IData)(1U) 
                                                       + 
                                                       (vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                                                        >> 0x17U)) 
                                                      << 0x17U)) 
                                                  | (0x7fffffU 
                                                     & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck)))
                                            : ((0xff800000U 
                                                & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num) 
                                               | (0x7fffffU 
                                                  & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck)));
                                } else {
                                    vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                                        = vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num;
                                }
                            } else {
                                vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck 
                                    = (0x7fffffU & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num);
                                vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck 
                                    = (0xffffffU & 
                                       ((IData)(1U) 
                                        + vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck));
                                vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                                    = ((0x800000U & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck)
                                        ? ((0x80000000U 
                                            & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num) 
                                           | ((0x7f800000U 
                                               & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
                                                    >> 0x17U)) 
                                                  << 0x17U)) 
                                              | (0x7fffffU 
                                                 & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck)))
                                        : ((0xff800000U 
                                            & vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num) 
                                           | (0x7fffffU 
                                              & vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck)));
                            }
                        } else {
                            vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded 
                                = vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num;
                        }
                    }
                }
            }
        }
    }
    if ((0U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
        if ((4U & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded)) {
            if ((0U == (3U & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded))) {
                if ((8U & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded)) {
                    vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                        = (0x7fffffU & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded);
                    vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                        = (0xffffffU & ((IData)(1U) 
                                        + vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck));
                    vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                        = ((0x800000U & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                            ? ((0x80000000U & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded) 
                               | ((0x7f800000U & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                                                    >> 0x17U)) 
                                                  << 0x17U)) 
                                  | (0x7fffffU & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck)))
                            : ((0xff800000U & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded) 
                               | (0x7fffffU & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
                } else {
                    vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                        = vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded;
                }
            } else {
                vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                    = (0x7fffffU & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded);
                vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                    = (0xffffffU & ((IData)(1U) + vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck));
                vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                    = ((0x800000U & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                        ? ((0x80000000U & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded) 
                           | ((0x7f800000U & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                              | (0x7fffffU & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck)))
                        : ((0xff800000U & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded) 
                           | (0x7fffffU & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
            }
        } else {
            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                = vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded;
        }
    } else {
        if ((1U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i 
                = VL_EXTENDS_II(32,8, (0xffU & ((vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                                                 >> 0x17U) 
                                                - (IData)(0x7fU))));
            if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i) 
                 & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i))) {
                vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask 
                    = ((0x16U >= vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i)
                        ? (0x7fffffU & (0x7fffffU >> vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i))
                        : 0U);
                vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask 
                    = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask));
                vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                    = ((0xff800000U & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded) 
                       | (vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                          & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask));
            } else {
                vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                    = ((0U == vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i)
                        ? 0x3f800000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i)
                                          ? vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded
                                          : 0U));
            }
        } else {
            if ((2U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                if ((0x80000000U & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded)) {
                    vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i 
                        = VL_EXTENDS_II(32,8, (0xffU 
                                               & ((vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                                                   >> 0x17U) 
                                                  - (IData)(0x7fU))));
                    if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i) 
                         & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i))) {
                        vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask 
                            = ((0x16U >= vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i)
                                ? (0x7fffffU & (0x7fffffU 
                                                >> vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask2 
                            = ((0x16U >= (vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i 
                                          - (IData)(1U)))
                                ? (0x7fffffU & (0x400000U 
                                                >> 
                                                (vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i 
                                                 - (IData)(1U))))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask 
                            = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask));
                        vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask 
                            = (vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                               & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask);
                        vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                            = vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask;
                        vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                            = (0xffffffU & (vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                            + vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask2));
                        vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                            = ((0x800000U & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                                ? ((0x80000000U & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded) 
                                   | ((0x7f800000U 
                                       & (((IData)(1U) 
                                           + (vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                                              >> 0x17U)) 
                                          << 0x17U)) 
                                      | (0x7fffffU 
                                         & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded)))
                                : ((0xff800000U & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded) 
                                   | (0x7fffffU & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
                    } else {
                        vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                            = ((0U == vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i)
                                ? 0x40000000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i)
                                                  ? vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded
                                                  : 0U));
                    }
                } else {
                    vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i 
                        = VL_EXTENDS_II(32,8, (0xffU 
                                               & ((vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                                                   >> 0x17U) 
                                                  - (IData)(0x7fU))));
                    if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i) 
                         & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i))) {
                        vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask 
                            = ((0x16U >= vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i)
                                ? (0x7fffffU & (0x7fffffU 
                                                >> vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask 
                            = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask));
                        vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                            = ((0xff800000U & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded) 
                               | (vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                                  & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask));
                    } else {
                        vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                            = ((0U == vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i)
                                ? 0x3f800000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i)
                                                  ? vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded
                                                  : 0U));
                    }
                }
            } else {
                if ((3U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                    if ((0x80000000U & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded)) {
                        vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                                = ((0xff800000U & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded) 
                                   | (vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                                      & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask));
                        } else {
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i)
                                    ? 0x3f800000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded
                                     : 0U));
                        }
                    } else {
                        vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask2 
                                = ((0x16U >= (vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i 
                                              - (IData)(1U)))
                                    ? (0x7fffffU & 
                                       (0x400000U >> 
                                        (vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i 
                                         - (IData)(1U))))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask 
                                = (vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                                   & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask);
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                = vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask;
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                                + vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask2));
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                                = ((0x800000U & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                                    ? ((0x80000000U 
                                        & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded) 
                                       | ((0x7f800000U 
                                           & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                                          | (0x7fffffU 
                                             & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded)))
                                    : ((0xff800000U 
                                        & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded) 
                                       | (0x7fffffU 
                                          & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
                        } else {
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i)
                                    ? 0x40000000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded
                                     : 0U));
                        }
                    }
                } else {
                    if ((4U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                        vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask2 
                                = ((0x16U >= (vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i 
                                              - (IData)(1U)))
                                    ? (0x7fffffU & 
                                       (0x400000U >> 
                                        (vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i 
                                         - (IData)(1U))))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask 
                                = (vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                                   & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask);
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                = vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask;
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                                + vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__mask2));
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                                = ((0x800000U & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                                    ? ((0x80000000U 
                                        & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded) 
                                       | ((0x7f800000U 
                                           & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                                          | (0x7fffffU 
                                             & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded)))
                                    : ((0xff800000U 
                                        & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded) 
                                       | (0x7fffffU 
                                          & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
                        } else {
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i)
                                    ? 0x40000000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded
                                     : 0U));
                        }
                    } else {
                        if ((4U & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded)) {
                            if ((0U == (3U & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded))) {
                                if ((8U & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded)) {
                                    vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                        = (0x7fffffU 
                                           & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded);
                                    vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                        = (0xffffffU 
                                           & ((IData)(1U) 
                                              + vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck));
                                    vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                                        = ((0x800000U 
                                            & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                                            ? ((0x80000000U 
                                                & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded) 
                                               | ((0x7f800000U 
                                                   & (((IData)(1U) 
                                                       + 
                                                       (vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                                                        >> 0x17U)) 
                                                      << 0x17U)) 
                                                  | (0x7fffffU 
                                                     & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck)))
                                            : ((0xff800000U 
                                                & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded) 
                                               | (0x7fffffU 
                                                  & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
                                } else {
                                    vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                                        = vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded;
                                }
                            } else {
                                vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                    = (0x7fffffU & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded);
                                vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                    = (0xffffffU & 
                                       ((IData)(1U) 
                                        + vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck));
                                vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                                    = ((0x800000U & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                                        ? ((0x80000000U 
                                            & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded) 
                                           | ((0x7f800000U 
                                               & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded 
                                                    >> 0x17U)) 
                                                  << 0x17U)) 
                                              | (0x7fffffU 
                                                 & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck)))
                                        : ((0xff800000U 
                                            & vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded) 
                                           | (0x7fffffU 
                                              & vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
                            }
                        } else {
                            vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded 
                                = vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
        = ((0x80000000U & ((~ (IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalSign)) 
                           << 0x1fU)) | (((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                          << 0x17U) 
                                         | (0x7fffffU 
                                            & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                               >> 1U))));
    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
        = ((0x80000000U & ((~ (IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalSign)) 
                           << 0x1fU)) | (((IData)(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp) 
                                          << 0x17U) 
                                         | (0x7fffffU 
                                            & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant 
                                               >> 1U))));
    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
        = ((0x80000000U & ((~ (IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalSign)) 
                           << 0x1fU)) | (((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                          << 0x17U) 
                                         | (0x7fffffU 
                                            & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                               >> 1U))));
    if ((0U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
        if ((4U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded)) {
            if ((0U == (3U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded))) {
                if ((8U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded)) {
                    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                        = (0x7fffffU & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded);
                    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                        = (0xffffffU & ((IData)(1U) 
                                        + vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck));
                    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                        = ((0x800000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                            ? ((0x80000000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded) 
                               | ((0x7f800000U & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                    >> 0x17U)) 
                                                  << 0x17U)) 
                                  | (0x7fffffU & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)))
                            : ((0xff800000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded) 
                               | (0x7fffffU & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
                } else {
                    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                        = vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded;
                }
            } else {
                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                    = (0x7fffffU & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded);
                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                    = (0xffffffU & ((IData)(1U) + vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck));
                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                    = ((0x800000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                        ? ((0x80000000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded) 
                           | ((0x7f800000U & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                              | (0x7fffffU & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)))
                        : ((0xff800000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded) 
                           | (0x7fffffU & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
            }
        } else {
            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                = vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded;
        }
    } else {
        if ((1U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                = VL_EXTENDS_II(32,8, (0xffU & ((vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                 >> 0x17U) 
                                                - (IData)(0x7fU))));
            if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i) 
                 & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))) {
                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                    = ((0x16U >= vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                        ? (0x7fffffU & (0x7fffffU >> vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))
                        : 0U);
                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                    = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask));
                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                    = ((0xff800000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded) 
                       | (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                          & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask));
            } else {
                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                    = ((0U == vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                        ? 0x3f800000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                          ? vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded
                                          : 0U));
            }
        } else {
            if ((2U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                if ((0x80000000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded)) {
                    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                        = VL_EXTENDS_II(32,8, (0xffU 
                                               & ((vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                   >> 0x17U) 
                                                  - (IData)(0x7fU))));
                    if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i) 
                         & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))) {
                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                            = ((0x16U >= vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                ? (0x7fffffU & (0x7fffffU 
                                                >> vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask2 
                            = ((0x16U >= (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                                          - (IData)(1U)))
                                ? (0x7fffffU & (0x400000U 
                                                >> 
                                                (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                                                 - (IData)(1U))))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                            = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask));
                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                            = (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                               & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask);
                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                            = vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask;
                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                            = (0xffffffU & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                            + vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask2));
                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                            = ((0x800000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                                ? ((0x80000000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                   | ((0x7f800000U 
                                       & (((IData)(1U) 
                                           + (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                                              >> 0x17U)) 
                                          << 0x17U)) 
                                      | (0x7fffffU 
                                         & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded)))
                                : ((0xff800000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                   | (0x7fffffU & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
                    } else {
                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                            = ((0U == vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                ? 0x40000000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                                  ? vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded
                                                  : 0U));
                    }
                } else {
                    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                        = VL_EXTENDS_II(32,8, (0xffU 
                                               & ((vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                   >> 0x17U) 
                                                  - (IData)(0x7fU))));
                    if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i) 
                         & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))) {
                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                            = ((0x16U >= vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                ? (0x7fffffU & (0x7fffffU 
                                                >> vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                            = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask));
                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                            = ((0xff800000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded) 
                               | (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                                  & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask));
                    } else {
                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                            = ((0U == vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                ? 0x3f800000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                                  ? vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded
                                                  : 0U));
                    }
                }
            } else {
                if ((3U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                    if ((0x80000000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded)) {
                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = ((0xff800000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                   | (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                                      & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask));
                        } else {
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                    ? 0x3f800000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded
                                     : 0U));
                        }
                    } else {
                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask2 
                                = ((0x16U >= (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                                              - (IData)(1U)))
                                    ? (0x7fffffU & 
                                       (0x400000U >> 
                                        (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                                         - (IData)(1U))))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                                = (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                                   & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask);
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                = vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask;
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                                + vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask2));
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = ((0x800000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                                    ? ((0x80000000U 
                                        & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                       | ((0x7f800000U 
                                           & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                                          | (0x7fffffU 
                                             & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded)))
                                    : ((0xff800000U 
                                        & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                       | (0x7fffffU 
                                          & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
                        } else {
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                    ? 0x40000000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded
                                     : 0U));
                        }
                    }
                } else {
                    if ((4U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                        vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask2 
                                = ((0x16U >= (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                                              - (IData)(1U)))
                                    ? (0x7fffffU & 
                                       (0x400000U >> 
                                        (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                                         - (IData)(1U))))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                                = (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                                   & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask);
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                = vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask;
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                                + vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask2));
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = ((0x800000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                                    ? ((0x80000000U 
                                        & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                       | ((0x7f800000U 
                                           & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                                          | (0x7fffffU 
                                             & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded)))
                                    : ((0xff800000U 
                                        & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                       | (0x7fffffU 
                                          & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
                        } else {
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                    ? 0x40000000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded
                                     : 0U));
                        }
                    } else {
                        if ((4U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded)) {
                            if ((0U == (3U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded))) {
                                if ((8U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded)) {
                                    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                        = (0x7fffffU 
                                           & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded);
                                    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                        = (0xffffffU 
                                           & ((IData)(1U) 
                                              + vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck));
                                    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                        = ((0x800000U 
                                            & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                                            ? ((0x80000000U 
                                                & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                               | ((0x7f800000U 
                                                   & (((IData)(1U) 
                                                       + 
                                                       (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                        >> 0x17U)) 
                                                      << 0x17U)) 
                                                  | (0x7fffffU 
                                                     & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)))
                                            : ((0xff800000U 
                                                & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                               | (0x7fffffU 
                                                  & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
                                } else {
                                    vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                        = vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded;
                                }
                            } else {
                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                    = (0x7fffffU & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded);
                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                    = (0xffffffU & 
                                       ((IData)(1U) 
                                        + vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck));
                                vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                    = ((0x800000U & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                                        ? ((0x80000000U 
                                            & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                           | ((0x7f800000U 
                                               & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                    >> 0x17U)) 
                                                  << 0x17U)) 
                                              | (0x7fffffU 
                                                 & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)))
                                        : ((0xff800000U 
                                            & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                           | (0x7fffffU 
                                              & vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
                            }
                        } else {
                            vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded;
                        }
                    }
                }
            }
        }
    }
    if ((0U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
        if ((4U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded)) {
            if ((0U == (3U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded))) {
                if ((8U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded)) {
                    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                        = (0x7fffffU & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded);
                    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                        = (0xffffffU & ((IData)(1U) 
                                        + vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck));
                    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                        = ((0x800000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                            ? ((0x80000000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded) 
                               | ((0x7f800000U & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                                                    >> 0x17U)) 
                                                  << 0x17U)) 
                                  | (0x7fffffU & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck)))
                            : ((0xff800000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded) 
                               | (0x7fffffU & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
                } else {
                    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                        = vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded;
                }
            } else {
                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                    = (0x7fffffU & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded);
                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                    = (0xffffffU & ((IData)(1U) + vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck));
                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                    = ((0x800000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                        ? ((0x80000000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded) 
                           | ((0x7f800000U & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                              | (0x7fffffU & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck)))
                        : ((0xff800000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded) 
                           | (0x7fffffU & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
            }
        } else {
            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                = vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded;
        }
    } else {
        if ((1U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i 
                = VL_EXTENDS_II(32,8, (0xffU & ((vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                                                 >> 0x17U) 
                                                - (IData)(0x7fU))));
            if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i) 
                 & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i))) {
                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask 
                    = ((0x16U >= vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i)
                        ? (0x7fffffU & (0x7fffffU >> vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i))
                        : 0U);
                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask 
                    = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask));
                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                    = ((0xff800000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded) 
                       | (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                          & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask));
            } else {
                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                    = ((0U == vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i)
                        ? 0x3f800000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i)
                                          ? vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded
                                          : 0U));
            }
        } else {
            if ((2U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                if ((0x80000000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded)) {
                    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i 
                        = VL_EXTENDS_II(32,8, (0xffU 
                                               & ((vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                                                   >> 0x17U) 
                                                  - (IData)(0x7fU))));
                    if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i) 
                         & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i))) {
                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask 
                            = ((0x16U >= vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i)
                                ? (0x7fffffU & (0x7fffffU 
                                                >> vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask2 
                            = ((0x16U >= (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i 
                                          - (IData)(1U)))
                                ? (0x7fffffU & (0x400000U 
                                                >> 
                                                (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i 
                                                 - (IData)(1U))))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask 
                            = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask));
                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask 
                            = (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                               & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask);
                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                            = vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask;
                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                            = (0xffffffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                            + vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask2));
                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                            = ((0x800000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                                ? ((0x80000000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded) 
                                   | ((0x7f800000U 
                                       & (((IData)(1U) 
                                           + (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                                              >> 0x17U)) 
                                          << 0x17U)) 
                                      | (0x7fffffU 
                                         & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded)))
                                : ((0xff800000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded) 
                                   | (0x7fffffU & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
                    } else {
                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                            = ((0U == vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i)
                                ? 0x40000000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i)
                                                  ? vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded
                                                  : 0U));
                    }
                } else {
                    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i 
                        = VL_EXTENDS_II(32,8, (0xffU 
                                               & ((vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                                                   >> 0x17U) 
                                                  - (IData)(0x7fU))));
                    if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i) 
                         & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i))) {
                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask 
                            = ((0x16U >= vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i)
                                ? (0x7fffffU & (0x7fffffU 
                                                >> vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask 
                            = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask));
                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                            = ((0xff800000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded) 
                               | (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                                  & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask));
                    } else {
                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                            = ((0U == vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i)
                                ? 0x3f800000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i)
                                                  ? vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded
                                                  : 0U));
                    }
                }
            } else {
                if ((3U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                    if ((0x80000000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded)) {
                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = ((0xff800000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded) 
                                   | (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                                      & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask));
                        } else {
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i)
                                    ? 0x3f800000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded
                                     : 0U));
                        }
                    } else {
                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask2 
                                = ((0x16U >= (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i 
                                              - (IData)(1U)))
                                    ? (0x7fffffU & 
                                       (0x400000U >> 
                                        (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i 
                                         - (IData)(1U))))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask 
                                = (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                                   & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask);
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                = vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask;
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                                + vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask2));
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = ((0x800000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                                    ? ((0x80000000U 
                                        & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded) 
                                       | ((0x7f800000U 
                                           & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                                          | (0x7fffffU 
                                             & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded)))
                                    : ((0xff800000U 
                                        & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded) 
                                       | (0x7fffffU 
                                          & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
                        } else {
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i)
                                    ? 0x40000000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded
                                     : 0U));
                        }
                    }
                } else {
                    if ((4U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                        vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask2 
                                = ((0x16U >= (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i 
                                              - (IData)(1U)))
                                    ? (0x7fffffU & 
                                       (0x400000U >> 
                                        (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i 
                                         - (IData)(1U))))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask 
                                = (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                                   & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask);
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                = vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask;
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                                + vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask2));
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = ((0x800000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                                    ? ((0x80000000U 
                                        & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded) 
                                       | ((0x7f800000U 
                                           & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                                          | (0x7fffffU 
                                             & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded)))
                                    : ((0xff800000U 
                                        & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded) 
                                       | (0x7fffffU 
                                          & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
                        } else {
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i)
                                    ? 0x40000000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded
                                     : 0U));
                        }
                    } else {
                        if ((4U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded)) {
                            if ((0U == (3U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded))) {
                                if ((8U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded)) {
                                    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                        = (0x7fffffU 
                                           & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded);
                                    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                        = (0xffffffU 
                                           & ((IData)(1U) 
                                              + vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck));
                                    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                                        = ((0x800000U 
                                            & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                                            ? ((0x80000000U 
                                                & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded) 
                                               | ((0x7f800000U 
                                                   & (((IData)(1U) 
                                                       + 
                                                       (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                                                        >> 0x17U)) 
                                                      << 0x17U)) 
                                                  | (0x7fffffU 
                                                     & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck)))
                                            : ((0xff800000U 
                                                & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded) 
                                               | (0x7fffffU 
                                                  & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
                                } else {
                                    vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                                        = vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded;
                                }
                            } else {
                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                    = (0x7fffffU & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded);
                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                    = (0xffffffU & 
                                       ((IData)(1U) 
                                        + vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck));
                                vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                                    = ((0x800000U & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                                        ? ((0x80000000U 
                                            & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded) 
                                           | ((0x7f800000U 
                                               & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded 
                                                    >> 0x17U)) 
                                                  << 0x17U)) 
                                              | (0x7fffffU 
                                                 & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck)))
                                        : ((0xff800000U 
                                            & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded) 
                                           | (0x7fffffU 
                                              & vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
                            }
                        } else {
                            vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded;
                        }
                    }
                }
            }
        }
    }
    if ((0U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
        if ((4U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded)) {
            if ((0U == (3U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded))) {
                if ((8U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded)) {
                    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                        = (0x7fffffU & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded);
                    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                        = (0xffffffU & ((IData)(1U) 
                                        + vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck));
                    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                        = ((0x800000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                            ? ((0x80000000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded) 
                               | ((0x7f800000U & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                    >> 0x17U)) 
                                                  << 0x17U)) 
                                  | (0x7fffffU & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)))
                            : ((0xff800000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded) 
                               | (0x7fffffU & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
                } else {
                    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                        = vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded;
                }
            } else {
                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                    = (0x7fffffU & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded);
                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                    = (0xffffffU & ((IData)(1U) + vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck));
                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                    = ((0x800000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                        ? ((0x80000000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded) 
                           | ((0x7f800000U & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                              | (0x7fffffU & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)))
                        : ((0xff800000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded) 
                           | (0x7fffffU & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
            }
        } else {
            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                = vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded;
        }
    } else {
        if ((1U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                = VL_EXTENDS_II(32,8, (0xffU & ((vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                 >> 0x17U) 
                                                - (IData)(0x7fU))));
            if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i) 
                 & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))) {
                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                    = ((0x16U >= vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                        ? (0x7fffffU & (0x7fffffU >> vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))
                        : 0U);
                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                    = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask));
                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                    = ((0xff800000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded) 
                       | (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                          & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask));
            } else {
                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                    = ((0U == vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                        ? 0x3f800000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                          ? vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded
                                          : 0U));
            }
        } else {
            if ((2U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                if ((0x80000000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded)) {
                    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                        = VL_EXTENDS_II(32,8, (0xffU 
                                               & ((vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                   >> 0x17U) 
                                                  - (IData)(0x7fU))));
                    if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i) 
                         & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))) {
                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                            = ((0x16U >= vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                ? (0x7fffffU & (0x7fffffU 
                                                >> vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask2 
                            = ((0x16U >= (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                                          - (IData)(1U)))
                                ? (0x7fffffU & (0x400000U 
                                                >> 
                                                (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                                                 - (IData)(1U))))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                            = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask));
                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                            = (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                               & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask);
                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                            = vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask;
                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                            = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                            + vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask2));
                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                            = ((0x800000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                                ? ((0x80000000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                   | ((0x7f800000U 
                                       & (((IData)(1U) 
                                           + (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                                              >> 0x17U)) 
                                          << 0x17U)) 
                                      | (0x7fffffU 
                                         & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded)))
                                : ((0xff800000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                   | (0x7fffffU & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
                    } else {
                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                            = ((0U == vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                ? 0x40000000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                                  ? vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded
                                                  : 0U));
                    }
                } else {
                    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                        = VL_EXTENDS_II(32,8, (0xffU 
                                               & ((vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                   >> 0x17U) 
                                                  - (IData)(0x7fU))));
                    if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i) 
                         & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))) {
                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                            = ((0x16U >= vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                ? (0x7fffffU & (0x7fffffU 
                                                >> vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                            = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask));
                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                            = ((0xff800000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded) 
                               | (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                                  & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask));
                    } else {
                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                            = ((0U == vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                ? 0x3f800000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                                  ? vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded
                                                  : 0U));
                    }
                }
            } else {
                if ((3U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                    if ((0x80000000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded)) {
                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = ((0xff800000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                   | (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                                      & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask));
                        } else {
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                    ? 0x3f800000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded
                                     : 0U));
                        }
                    } else {
                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask2 
                                = ((0x16U >= (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                                              - (IData)(1U)))
                                    ? (0x7fffffU & 
                                       (0x400000U >> 
                                        (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                                         - (IData)(1U))))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                                = (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                                   & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask);
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                = vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask;
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                                + vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask2));
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = ((0x800000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                                    ? ((0x80000000U 
                                        & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                       | ((0x7f800000U 
                                           & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                                          | (0x7fffffU 
                                             & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded)))
                                    : ((0xff800000U 
                                        & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                       | (0x7fffffU 
                                          & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
                        } else {
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                    ? 0x40000000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded
                                     : 0U));
                        }
                    }
                } else {
                    if ((4U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                        vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask2 
                                = ((0x16U >= (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                                              - (IData)(1U)))
                                    ? (0x7fffffU & 
                                       (0x400000U >> 
                                        (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i 
                                         - (IData)(1U))))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask 
                                = (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                                   & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask);
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                = vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask;
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                                + vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask2));
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = ((0x800000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                                    ? ((0x80000000U 
                                        & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                       | ((0x7f800000U 
                                           & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                                          | (0x7fffffU 
                                             & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded)))
                                    : ((0xff800000U 
                                        & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                       | (0x7fffffU 
                                          & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
                        } else {
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                    ? 0x40000000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded
                                     : 0U));
                        }
                    } else {
                        if ((4U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded)) {
                            if ((0U == (3U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded))) {
                                if ((8U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded)) {
                                    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                        = (0x7fffffU 
                                           & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded);
                                    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                        = (0xffffffU 
                                           & ((IData)(1U) 
                                              + vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck));
                                    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                        = ((0x800000U 
                                            & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                                            ? ((0x80000000U 
                                                & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                               | ((0x7f800000U 
                                                   & (((IData)(1U) 
                                                       + 
                                                       (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                        >> 0x17U)) 
                                                      << 0x17U)) 
                                                  | (0x7fffffU 
                                                     & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)))
                                            : ((0xff800000U 
                                                & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                               | (0x7fffffU 
                                                  & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
                                } else {
                                    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                        = vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded;
                                }
                            } else {
                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                    = (0x7fffffU & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded);
                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck 
                                    = (0xffffffU & 
                                       ((IData)(1U) 
                                        + vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck));
                                vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                    = ((0x800000U & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)
                                        ? ((0x80000000U 
                                            & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                           | ((0x7f800000U 
                                               & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
                                                    >> 0x17U)) 
                                                  << 0x17U)) 
                                              | (0x7fffffU 
                                                 & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)))
                                        : ((0xff800000U 
                                            & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded) 
                                           | (0x7fffffU 
                                              & vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck)));
                            }
                        } else {
                            vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded 
                                = vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded;
                        }
                    }
                }
            }
        }
    }
}

void Vfpu_top::_eval_initial(Vfpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_top::_eval_initial\n"); );
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
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
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlSymsp->TOP__fpu_top__DOT__fmul1._sequent__TOP__fpu_top__DOT__fmul1__1(vlSymsp);
    vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1._sequent__TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1__2(vlSymsp);
    vlSymsp->TOP__fpu_top__DOT__fmadd1__DOT__fmul1._sequent__TOP__fpu_top__DOT__fmul1__1(vlSymsp);
    vlSymsp->TOP__fpu_top__DOT__fnmsub1__DOT__fmul1._sequent__TOP__fpu_top__DOT__fnmsub1__DOT__fmul1__4(vlSymsp);
    vlSymsp->TOP__fpu_top__DOT__fnmadd1__DOT__fmul1._sequent__TOP__fpu_top__DOT__fnmsub1__DOT__fmul1__4(vlSymsp);
    vlSymsp->TOP__fpu_top__DOT__fmsub1__DOT__fmul1._sequent__TOP__fpu_top__DOT__fmsub1__DOT__fmul1__6(vlSymsp);
    vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fm0._sequent__TOP__fpu_top__DOT__fdiv1__DOT__fm0__7(vlSymsp);
    vlTOPp->_sequent__TOP__3(vlSymsp);
}

void Vfpu_top::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_top::_ctor_var_reset\n"); );
    // Body
    instruction = VL_RAND_RESET_I(32);
    clk = VL_RAND_RESET_I(1);
    fpu_out = VL_RAND_RESET_I(32);
    fpu_top__DOT__operand_1 = VL_RAND_RESET_I(32);
    fpu_top__DOT__operand_2 = VL_RAND_RESET_I(32);
    fpu_top__DOT__operand_3 = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            fpu_top__DOT__regFile[__Vi0] = VL_RAND_RESET_I(32);
    }}
    fpu_top__DOT__fcsr = VL_RAND_RESET_I(32);
    fpu_top__DOT__ins_p1 = VL_RAND_RESET_I(32);
    fpu_top__DOT__curr_op = VL_RAND_RESET_I(5);
    fpu_top__DOT__oper1 = VL_RAND_RESET_I(32);
    fpu_top__DOT__oper2 = VL_RAND_RESET_I(32);
    fpu_top__DOT__oper3 = VL_RAND_RESET_I(32);
    fpu_top__DOT__exec_op = VL_RAND_RESET_I(5);
    fpu_top__DOT__ins_p2 = VL_RAND_RESET_I(32);
    fpu_top__DOT__operand_one = VL_RAND_RESET_I(32);
    fpu_top__DOT__operand_two = VL_RAND_RESET_I(32);
    fpu_top__DOT__operand_three = VL_RAND_RESET_I(32);
    fpu_top__DOT__result = VL_RAND_RESET_I(32);
    fpu_top__DOT__rm = VL_RAND_RESET_I(3);
    fpu_top__DOT__writeback_data = VL_RAND_RESET_I(32);
    fpu_top__DOT__ins_p3 = VL_RAND_RESET_I(32);
    fpu_top__DOT__fmadd1__DOT__fadd1__DOT__largerMag = VL_RAND_RESET_I(1);
    fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalSign = VL_RAND_RESET_I(1);
    fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Exp = VL_RAND_RESET_I(8);
    fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Exp = VL_RAND_RESET_I(8);
    fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp = VL_RAND_RESET_I(8);
    fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Mant = VL_RAND_RESET_I(24);
    fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Mant = VL_RAND_RESET_I(24);
    fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant = VL_RAND_RESET_I(24);
    fpu_top__DOT__fmadd1__DOT__fadd1__DOT__sumMants = VL_RAND_RESET_I(25);
    fpu_top__DOT__fmadd1__DOT__fadd1__DOT__i = 0;
    fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded = VL_RAND_RESET_I(32);
    fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded = VL_RAND_RESET_I(32);
    fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck = VL_RAND_RESET_I(24);
    fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask = VL_RAND_RESET_I(23);
    fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask2 = VL_RAND_RESET_I(23);
    fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i = 0;
    fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__j = 0;
    fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2 = VL_RAND_RESET_I(32);
    fpu_top__DOT__fmsub1__DOT__f1__DOT__largerMag = VL_RAND_RESET_I(1);
    fpu_top__DOT__fmsub1__DOT__f1__DOT__finalSign = VL_RAND_RESET_I(1);
    fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Exp = VL_RAND_RESET_I(8);
    fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Exp = VL_RAND_RESET_I(8);
    fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp = VL_RAND_RESET_I(8);
    fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Mant = VL_RAND_RESET_I(24);
    fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Mant = VL_RAND_RESET_I(24);
    fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant = VL_RAND_RESET_I(24);
    fpu_top__DOT__fmsub1__DOT__f1__DOT__sumMants = VL_RAND_RESET_I(25);
    fpu_top__DOT__fmsub1__DOT__f1__DOT__i = 0;
    fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded = VL_RAND_RESET_I(32);
    fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded = VL_RAND_RESET_I(32);
    fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck = VL_RAND_RESET_I(24);
    fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask = VL_RAND_RESET_I(23);
    fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask2 = VL_RAND_RESET_I(23);
    fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i = 0;
    fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__j = 0;
    fpu_top__DOT__fnmsub1__DOT__in1 = VL_RAND_RESET_I(32);
    fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__largerMag = VL_RAND_RESET_I(1);
    fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalSign = VL_RAND_RESET_I(1);
    fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Exp = VL_RAND_RESET_I(8);
    fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Exp = VL_RAND_RESET_I(8);
    fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp = VL_RAND_RESET_I(8);
    fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Mant = VL_RAND_RESET_I(24);
    fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Mant = VL_RAND_RESET_I(24);
    fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant = VL_RAND_RESET_I(24);
    fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__sumMants = VL_RAND_RESET_I(25);
    fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__i = 0;
    fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded = VL_RAND_RESET_I(32);
    fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded = VL_RAND_RESET_I(32);
    fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck = VL_RAND_RESET_I(24);
    fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask = VL_RAND_RESET_I(23);
    fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask2 = VL_RAND_RESET_I(23);
    fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i = 0;
    fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__j = 0;
    fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__largerMag = VL_RAND_RESET_I(1);
    fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalSign = VL_RAND_RESET_I(1);
    fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Exp = VL_RAND_RESET_I(8);
    fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Exp = VL_RAND_RESET_I(8);
    fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp = VL_RAND_RESET_I(8);
    fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Mant = VL_RAND_RESET_I(24);
    fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Mant = VL_RAND_RESET_I(24);
    fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant = VL_RAND_RESET_I(24);
    fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__sumMants = VL_RAND_RESET_I(25);
    fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__i = 0;
    fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded = VL_RAND_RESET_I(32);
    fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded = VL_RAND_RESET_I(32);
    fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck = VL_RAND_RESET_I(24);
    fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask = VL_RAND_RESET_I(23);
    fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask2 = VL_RAND_RESET_I(23);
    fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i = 0;
    fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__j = 0;
    fpu_top__DOT__fadd1__DOT__largerMag = VL_RAND_RESET_I(1);
    fpu_top__DOT__fadd1__DOT__finalSign = VL_RAND_RESET_I(1);
    fpu_top__DOT__fadd1__DOT__num1Exp = VL_RAND_RESET_I(8);
    fpu_top__DOT__fadd1__DOT__num2Exp = VL_RAND_RESET_I(8);
    fpu_top__DOT__fadd1__DOT__finalExp = VL_RAND_RESET_I(8);
    fpu_top__DOT__fadd1__DOT__num1Mant = VL_RAND_RESET_I(24);
    fpu_top__DOT__fadd1__DOT__num2Mant = VL_RAND_RESET_I(24);
    fpu_top__DOT__fadd1__DOT__finalMant = VL_RAND_RESET_I(24);
    fpu_top__DOT__fadd1__DOT__sumMants = VL_RAND_RESET_I(25);
    fpu_top__DOT__fadd1__DOT__i = 0;
    fpu_top__DOT__fadd1__DOT__unrounded = VL_RAND_RESET_I(32);
    fpu_top__DOT__fadd1__DOT__r0__DOT__rounded = VL_RAND_RESET_I(32);
    fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck = VL_RAND_RESET_I(24);
    fpu_top__DOT__fadd1__DOT__r0__DOT__mask = VL_RAND_RESET_I(23);
    fpu_top__DOT__fadd1__DOT__r0__DOT__mask2 = VL_RAND_RESET_I(23);
    fpu_top__DOT__fadd1__DOT__r0__DOT__i = 0;
    fpu_top__DOT__fadd1__DOT__r0__DOT__j = 0;
    fpu_top__DOT__fsub1__DOT__f1__DOT__largerMag = VL_RAND_RESET_I(1);
    fpu_top__DOT__fsub1__DOT__f1__DOT__finalSign = VL_RAND_RESET_I(1);
    fpu_top__DOT__fsub1__DOT__f1__DOT__num1Exp = VL_RAND_RESET_I(8);
    fpu_top__DOT__fsub1__DOT__f1__DOT__num2Exp = VL_RAND_RESET_I(8);
    fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp = VL_RAND_RESET_I(8);
    fpu_top__DOT__fsub1__DOT__f1__DOT__num1Mant = VL_RAND_RESET_I(24);
    fpu_top__DOT__fsub1__DOT__f1__DOT__num2Mant = VL_RAND_RESET_I(24);
    fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant = VL_RAND_RESET_I(24);
    fpu_top__DOT__fsub1__DOT__f1__DOT__sumMants = VL_RAND_RESET_I(25);
    fpu_top__DOT__fsub1__DOT__f1__DOT__i = 0;
    fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded = VL_RAND_RESET_I(32);
    fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded = VL_RAND_RESET_I(32);
    fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck = VL_RAND_RESET_I(24);
    fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask = VL_RAND_RESET_I(23);
    fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask2 = VL_RAND_RESET_I(23);
    fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i = 0;
    fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__j = 0;
    fpu_top__DOT__fsqrt1__DOT__shifted_num = VL_RAND_RESET_I(32);
    fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded = VL_RAND_RESET_I(32);
    fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck = VL_RAND_RESET_I(24);
    fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask = VL_RAND_RESET_I(23);
    fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask2 = VL_RAND_RESET_I(23);
    fpu_top__DOT__fsqrt1__DOT__r0__DOT__i = 0;
    fpu_top__DOT__fsqrt1__DOT__r0__DOT__j = 0;
    fpu_top__DOT__fmin1__DOT__out = VL_RAND_RESET_I(32);
    fpu_top__DOT__fmax1__DOT__out = VL_RAND_RESET_I(32);
    fpu_top__DOT__flt1__DOT__out = VL_RAND_RESET_I(32);
    fpu_top__DOT__fle1__DOT__out = VL_RAND_RESET_I(32);
    fpu_top__DOT__fclass1__DOT__result = VL_RAND_RESET_I(32);
    __Vchglast__TOP__fpu_top__DOT__fsqrt1__DOT__shifted_num = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
