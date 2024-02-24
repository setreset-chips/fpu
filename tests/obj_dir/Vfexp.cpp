// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfexp.h for the primary calling header

#include "Vfexp.h"
#include "Vfexp__Syms.h"

//==========

void Vfexp::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfexp::eval\n"); );
    Vfexp__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vfexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../fexp.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vfexp::_eval_initial_loop(Vfexp__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../fexp.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vfexp::_combo__TOP__1(Vfexp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfexp::_combo__TOP__1\n"); );
    Vfexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->fexp__DOT__fm0__DOT__mantissaProd = (0xffffffffffffULL 
                                                 & ((QData)((IData)(
                                                                    ((0U 
                                                                      == vlTOPp->exp)
                                                                      ? 0U
                                                                      : 
                                                                     (0x800000U 
                                                                      | (0x7fffffU 
                                                                         & vlTOPp->exp))))) 
                                                    * (QData)((IData)(
                                                                      ((0U 
                                                                        == vlTOPp->exp)
                                                                        ? 0U
                                                                        : 
                                                                       (0x800000U 
                                                                        | (0x7fffffU 
                                                                           & vlTOPp->exp)))))));
    vlTOPp->fexp__DOT__fm0__DOT__expF = (0xffU & ((
                                                   (vlTOPp->exp 
                                                    >> 0x17U) 
                                                   + 
                                                   (vlTOPp->exp 
                                                    >> 0x17U)) 
                                                  - (IData)(0x7fU)));
    vlTOPp->fexp__DOT__fm0__DOT__mantissa = (0x7fffffU 
                                             & (IData)(
                                                       (vlTOPp->fexp__DOT__fm0__DOT__mantissaProd 
                                                        >> 0x19U)));
    if ((0x400000U & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
        vlTOPp->fexp__DOT__fm0__DOT__mantissa = (0x7fffffU 
                                                 & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                    << 2U));
        vlTOPp->fexp__DOT__fm0__DOT__expF = (0xffU 
                                             & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                                - (IData)(1U)));
    } else {
        if ((0x200000U & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
            vlTOPp->fexp__DOT__fm0__DOT__mantissa = 
                (0x7fffffU & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                              << 3U));
            vlTOPp->fexp__DOT__fm0__DOT__expF = (0xffU 
                                                 & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                                    - (IData)(2U)));
        } else {
            if ((0x100000U & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                    = (0x7fffffU & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                    << 4U));
                vlTOPp->fexp__DOT__fm0__DOT__expF = 
                    (0xffU & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                              - (IData)(3U)));
            } else {
                if ((0x80000U & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                    vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                        = (0x7fffffU & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                        << 5U));
                    vlTOPp->fexp__DOT__fm0__DOT__expF 
                        = (0xffU & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                    - (IData)(4U)));
                } else {
                    if ((0x40000U & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                        vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                            = (0x7fffffU & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                            << 6U));
                        vlTOPp->fexp__DOT__fm0__DOT__expF 
                            = (0xffU & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                        - (IData)(5U)));
                    } else {
                        if ((0x20000U & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                            vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                = (0x7fffffU & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                << 7U));
                            vlTOPp->fexp__DOT__fm0__DOT__expF 
                                = (0xffU & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                            - (IData)(6U)));
                        } else {
                            if ((0x10000U & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                                vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                    = (0x7fffffU & 
                                       (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                        << 8U));
                                vlTOPp->fexp__DOT__fm0__DOT__expF 
                                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                                - (IData)(7U)));
                            } else {
                                if ((0x8000U & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                                    vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                        = (0x7fffffU 
                                           & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                              << 9U));
                                    vlTOPp->fexp__DOT__fm0__DOT__expF 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                            - (IData)(8U)));
                                } else {
                                    if ((0x4000U & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                                        vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                            = (0x7fffffU 
                                               & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                  << 0xaU));
                                        vlTOPp->fexp__DOT__fm0__DOT__expF 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                                  - (IData)(9U)));
                                    } else {
                                        if ((0x2000U 
                                             & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                                            vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                = (0x7fffffU 
                                                   & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                      << 0xbU));
                                            vlTOPp->fexp__DOT__fm0__DOT__expF 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                                      - (IData)(0xaU)));
                                        } else {
                                            if ((0x1000U 
                                                 & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                                                vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                    = 
                                                    (0x7fffffU 
                                                     & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                        << 0xcU));
                                                vlTOPp->fexp__DOT__fm0__DOT__expF 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                                        - (IData)(0xbU)));
                                            } else {
                                                if (
                                                    (0x800U 
                                                     & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                                                    vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                        = 
                                                        (0x7fffffU 
                                                         & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                            << 0xdU));
                                                    vlTOPp->fexp__DOT__fm0__DOT__expF 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                                            - (IData)(0xcU)));
                                                } else {
                                                    if (
                                                        (0x400U 
                                                         & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                                                        vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                            = 
                                                            (0x7fffffU 
                                                             & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                                << 0xeU));
                                                        vlTOPp->fexp__DOT__fm0__DOT__expF 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                                                - (IData)(0xdU)));
                                                    } else {
                                                        if (
                                                            (0x200U 
                                                             & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                                                            vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                                = 
                                                                (0x7fffffU 
                                                                 & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                                    << 0xfU));
                                                            vlTOPp->fexp__DOT__fm0__DOT__expF 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                                                    - (IData)(0xeU)));
                                                        } else {
                                                            if (
                                                                (0x100U 
                                                                 & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                                                                vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                                    = 
                                                                    (0x7fffffU 
                                                                     & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                                        << 0x10U));
                                                                vlTOPp->fexp__DOT__fm0__DOT__expF 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                                                        - (IData)(0xfU)));
                                                            } else {
                                                                if (
                                                                    (0x80U 
                                                                     & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                                                                    vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                                        = 
                                                                        (0x7fffffU 
                                                                         & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                                            << 0x11U));
                                                                    vlTOPp->fexp__DOT__fm0__DOT__expF 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                                                            - (IData)(0x10U)));
                                                                } else {
                                                                    if (
                                                                        (0x40U 
                                                                         & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                                                                        vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                                            = 
                                                                            (0x7fffffU 
                                                                             & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                                                << 0x12U));
                                                                        vlTOPp->fexp__DOT__fm0__DOT__expF 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                                                                - (IData)(0x11U)));
                                                                    } else {
                                                                        if (
                                                                            (0x20U 
                                                                             & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                                                                            vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                                                << 0x13U));
                                                                            vlTOPp->fexp__DOT__fm0__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                                                                - (IData)(0x12U)));
                                                                        } else {
                                                                            if (
                                                                                (0x10U 
                                                                                & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                                                                                vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                                                << 0x14U));
                                                                                vlTOPp->fexp__DOT__fm0__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                                                                - (IData)(0x13U)));
                                                                            } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                                                                                vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                                                << 0x15U));
                                                                                vlTOPp->fexp__DOT__fm0__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                                                                                vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                                                << 0x16U));
                                                                                vlTOPp->fexp__DOT__fm0__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fexp__DOT__fm0__DOT__mantissa)) {
                                                                                vlTOPp->fexp__DOT__fm0__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                                                                - (IData)(0x16U)));
                                                                                vlTOPp->fexp__DOT__fm0__DOT__mantissa = 0U;
                                                                                } else {
                                                                                vlTOPp->fexp__DOT__fm0__DOT__expF = 0xffU;
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
    vlTOPp->fexp__DOT__fm0__DOT__expF = (0xffU & ((IData)(1U) 
                                                  + (IData)(vlTOPp->fexp__DOT__fm0__DOT__expF)));
    vlTOPp->fexp__DOT__fm0__DOT__mantissa = (0x7fffffU 
                                             & (vlTOPp->fexp__DOT__fm0__DOT__mantissa 
                                                >> 1U));
    vlTOPp->fexp__DOT__fm0__DOT__expF = (0xffU & ((IData)(1U) 
                                                  + (IData)(vlTOPp->fexp__DOT__fm0__DOT__expF)));
    vlTOPp->fexp__DOT__temp2 = (((IData)(vlTOPp->fexp__DOT__fm0__DOT__expF) 
                                 << 0x17U) | vlTOPp->fexp__DOT__fm0__DOT__mantissa);
    vlTOPp->fexp__DOT__fa0__DOT__largerMag = 0U;
    vlTOPp->fexp__DOT__fa0__DOT__num1Exp = 0x7fU;
    vlTOPp->fexp__DOT__fa0__DOT__num2Exp = (0xffU & 
                                            (vlTOPp->exp 
                                             >> 0x17U));
    vlTOPp->fexp__DOT__fa0__DOT__num1Mant = 0x800000U;
    vlTOPp->fexp__DOT__fa0__DOT__num2Mant = (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->exp));
    if ((0x7fU < (IData)(vlTOPp->fexp__DOT__fa0__DOT__num2Exp))) {
        vlTOPp->fexp__DOT__fa0__DOT__finalExp = vlTOPp->fexp__DOT__fa0__DOT__num2Exp;
        vlTOPp->fexp__DOT__fa0__DOT__num1Mant = ((0x17U 
                                                  >= 
                                                  (0xffU 
                                                   & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                                      - (IData)(vlTOPp->fexp__DOT__fa0__DOT__num1Exp))))
                                                  ? 
                                                 (0xffffffU 
                                                  & (vlTOPp->fexp__DOT__fa0__DOT__num1Mant 
                                                     >> 
                                                     (0xffU 
                                                      & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                                         - (IData)(vlTOPp->fexp__DOT__fa0__DOT__num1Exp)))))
                                                  : 0U);
        vlTOPp->fexp__DOT__fa0__DOT__largerMag = 1U;
    } else {
        if (((IData)(vlTOPp->fexp__DOT__fa0__DOT__num2Exp) 
             < (IData)(vlTOPp->fexp__DOT__fa0__DOT__num1Exp))) {
            vlTOPp->fexp__DOT__fa0__DOT__finalExp = vlTOPp->fexp__DOT__fa0__DOT__num1Exp;
            vlTOPp->fexp__DOT__fa0__DOT__num2Mant = 
                ((0x17U >= (0xffU & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                     - (IData)(vlTOPp->fexp__DOT__fa0__DOT__num2Exp))))
                  ? (0xffffffU & (vlTOPp->fexp__DOT__fa0__DOT__num2Mant 
                                  >> (0xffU & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                               - (IData)(vlTOPp->fexp__DOT__fa0__DOT__num2Exp)))))
                  : 0U);
            vlTOPp->fexp__DOT__fa0__DOT__largerMag = 0U;
        } else {
            vlTOPp->fexp__DOT__fa0__DOT__finalExp = vlTOPp->fexp__DOT__fa0__DOT__num1Exp;
            vlTOPp->fexp__DOT__fa0__DOT__largerMag 
                = (vlTOPp->fexp__DOT__fa0__DOT__num2Mant 
                   > vlTOPp->fexp__DOT__fa0__DOT__num1Mant);
        }
    }
    if ((0x80000000U & vlTOPp->exp)) {
        vlTOPp->fexp__DOT__fa0__DOT__sumMants = (0x1ffffffU 
                                                 & (vlTOPp->fexp__DOT__fa0__DOT__num2Mant 
                                                    - vlTOPp->fexp__DOT__fa0__DOT__num1Mant));
        vlTOPp->fexp__DOT__fa0__DOT__finalSign = (1U 
                                                  & (~ (IData)(vlTOPp->fexp__DOT__fa0__DOT__largerMag)));
        vlTOPp->fexp__DOT__fa0__DOT__finalMant = (0xffffffU 
                                                  & vlTOPp->fexp__DOT__fa0__DOT__sumMants);
        vlTOPp->fexp__DOT__fa0__DOT__finalMant = (0xffffffU 
                                                  & ((0x1000000U 
                                                      & vlTOPp->fexp__DOT__fa0__DOT__sumMants)
                                                      ? 
                                                     ((IData)(0xffffffffU) 
                                                      * vlTOPp->fexp__DOT__fa0__DOT__finalMant)
                                                      : vlTOPp->fexp__DOT__fa0__DOT__finalMant));
    } else {
        vlTOPp->fexp__DOT__fa0__DOT__sumMants = (0x1ffffffU 
                                                 & (vlTOPp->fexp__DOT__fa0__DOT__num2Mant 
                                                    + vlTOPp->fexp__DOT__fa0__DOT__num1Mant));
        vlTOPp->fexp__DOT__fa0__DOT__finalExp = (0xffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp)));
        vlTOPp->fexp__DOT__fa0__DOT__finalSign = 1U;
        vlTOPp->fexp__DOT__fa0__DOT__finalMant = (0xffffffU 
                                                  & (vlTOPp->fexp__DOT__fa0__DOT__sumMants 
                                                     >> 1U));
    }
    if ((0x800000U & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
        vlTOPp->fexp__DOT__fa0__DOT__finalMant = (0xffffffU 
                                                  & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                     << 1U));
    } else {
        if ((0x400000U & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
            vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                = (0xffffffU & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                << 2U));
            vlTOPp->fexp__DOT__fa0__DOT__finalExp = 
                (0xffU & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                          - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                    << 3U));
                vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                    vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                        = (0xffffffU & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                        << 4U));
                    vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                        = (0xffU & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                        vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                            = (0xffffffU & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                            << 5U));
                        vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                            = (0xffU & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                            vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                = (0xffffffU & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                << 6U));
                            vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                = (0xffU & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                                vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                    = (0xffffffU & 
                                       (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                        << 7U));
                                vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                                    vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                        = (0xffffffU 
                                           & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                              << 8U));
                                    vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                                        vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                            = (0xffffffU 
                                               & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                  << 9U));
                                        vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                                            vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                = (0xffffffU 
                                                   & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                      << 0xaU));
                                            vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                                                vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                        << 0xbU));
                                                vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                                                    vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                            << 0xcU));
                                                    vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                                                        vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                << 0xdU));
                                                        vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                                                            vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                    << 0xeU));
                                                            vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                                                                vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                        << 0xfU));
                                                                vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                                                                    vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                            << 0x10U));
                                                                    vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                                                                        vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                                << 0x11U));
                                                                        vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                                                                            vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                                << 0x12U));
                                                                            vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                                                                                vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                                << 0x13U));
                                                                                vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                                                                                vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                                << 0x14U));
                                                                                vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                                                                                vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                                << 0x15U));
                                                                                vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                                                                                vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                                << 0x16U));
                                                                                vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fexp__DOT__fa0__DOT__finalMant)) {
                                                                                vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                                                << 0x17U));
                                                                                vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fexp__DOT__fa0__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
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
    vlTOPp->fexp__DOT__fm1__DOT__mantissaProd = (0xffffffffffffULL 
                                                 & ((QData)((IData)(
                                                                    ((0U 
                                                                      == vlTOPp->fexp__DOT__temp2)
                                                                      ? 0U
                                                                      : 
                                                                     (0x800000U 
                                                                      | (0x7fffffU 
                                                                         & vlTOPp->fexp__DOT__temp2))))) 
                                                    * (QData)((IData)(
                                                                      ((0U 
                                                                        == vlTOPp->exp)
                                                                        ? 0U
                                                                        : 
                                                                       (0x800000U 
                                                                        | (0x7fffffU 
                                                                           & vlTOPp->exp)))))));
    vlTOPp->fexp__DOT__fm1__DOT__expF = (0xffU & ((
                                                   (vlTOPp->fexp__DOT__temp2 
                                                    >> 0x17U) 
                                                   + 
                                                   (vlTOPp->exp 
                                                    >> 0x17U)) 
                                                  - (IData)(0x7fU)));
    vlTOPp->fexp__DOT__fm1__DOT__mantissa = (0x7fffffU 
                                             & (IData)(
                                                       (vlTOPp->fexp__DOT__fm1__DOT__mantissaProd 
                                                        >> 0x19U)));
    if ((0x400000U & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
        vlTOPp->fexp__DOT__fm1__DOT__mantissa = (0x7fffffU 
                                                 & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                    << 2U));
        vlTOPp->fexp__DOT__fm1__DOT__expF = (0xffU 
                                             & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                                - (IData)(1U)));
    } else {
        if ((0x200000U & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
            vlTOPp->fexp__DOT__fm1__DOT__mantissa = 
                (0x7fffffU & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                              << 3U));
            vlTOPp->fexp__DOT__fm1__DOT__expF = (0xffU 
                                                 & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                                    - (IData)(2U)));
        } else {
            if ((0x100000U & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                    = (0x7fffffU & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                    << 4U));
                vlTOPp->fexp__DOT__fm1__DOT__expF = 
                    (0xffU & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                              - (IData)(3U)));
            } else {
                if ((0x80000U & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                    vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                        = (0x7fffffU & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                        << 5U));
                    vlTOPp->fexp__DOT__fm1__DOT__expF 
                        = (0xffU & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                    - (IData)(4U)));
                } else {
                    if ((0x40000U & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                        vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                            = (0x7fffffU & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                            << 6U));
                        vlTOPp->fexp__DOT__fm1__DOT__expF 
                            = (0xffU & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                        - (IData)(5U)));
                    } else {
                        if ((0x20000U & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                            vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                = (0x7fffffU & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                << 7U));
                            vlTOPp->fexp__DOT__fm1__DOT__expF 
                                = (0xffU & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                            - (IData)(6U)));
                        } else {
                            if ((0x10000U & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                                vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                    = (0x7fffffU & 
                                       (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                        << 8U));
                                vlTOPp->fexp__DOT__fm1__DOT__expF 
                                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                                - (IData)(7U)));
                            } else {
                                if ((0x8000U & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                                    vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                        = (0x7fffffU 
                                           & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                              << 9U));
                                    vlTOPp->fexp__DOT__fm1__DOT__expF 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                            - (IData)(8U)));
                                } else {
                                    if ((0x4000U & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                                        vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                            = (0x7fffffU 
                                               & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                  << 0xaU));
                                        vlTOPp->fexp__DOT__fm1__DOT__expF 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                                  - (IData)(9U)));
                                    } else {
                                        if ((0x2000U 
                                             & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                                            vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                = (0x7fffffU 
                                                   & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                      << 0xbU));
                                            vlTOPp->fexp__DOT__fm1__DOT__expF 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                                      - (IData)(0xaU)));
                                        } else {
                                            if ((0x1000U 
                                                 & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                                                vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                    = 
                                                    (0x7fffffU 
                                                     & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                        << 0xcU));
                                                vlTOPp->fexp__DOT__fm1__DOT__expF 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                                        - (IData)(0xbU)));
                                            } else {
                                                if (
                                                    (0x800U 
                                                     & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                                                    vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                        = 
                                                        (0x7fffffU 
                                                         & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                            << 0xdU));
                                                    vlTOPp->fexp__DOT__fm1__DOT__expF 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                                            - (IData)(0xcU)));
                                                } else {
                                                    if (
                                                        (0x400U 
                                                         & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                                                        vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                            = 
                                                            (0x7fffffU 
                                                             & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                                << 0xeU));
                                                        vlTOPp->fexp__DOT__fm1__DOT__expF 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                                                - (IData)(0xdU)));
                                                    } else {
                                                        if (
                                                            (0x200U 
                                                             & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                                                            vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                                = 
                                                                (0x7fffffU 
                                                                 & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                                    << 0xfU));
                                                            vlTOPp->fexp__DOT__fm1__DOT__expF 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                                                    - (IData)(0xeU)));
                                                        } else {
                                                            if (
                                                                (0x100U 
                                                                 & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                                                                vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                                    = 
                                                                    (0x7fffffU 
                                                                     & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                                        << 0x10U));
                                                                vlTOPp->fexp__DOT__fm1__DOT__expF 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                                                        - (IData)(0xfU)));
                                                            } else {
                                                                if (
                                                                    (0x80U 
                                                                     & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                                                                    vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                                        = 
                                                                        (0x7fffffU 
                                                                         & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                                            << 0x11U));
                                                                    vlTOPp->fexp__DOT__fm1__DOT__expF 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                                                            - (IData)(0x10U)));
                                                                } else {
                                                                    if (
                                                                        (0x40U 
                                                                         & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                                                                        vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                                            = 
                                                                            (0x7fffffU 
                                                                             & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                                                << 0x12U));
                                                                        vlTOPp->fexp__DOT__fm1__DOT__expF 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                                                                - (IData)(0x11U)));
                                                                    } else {
                                                                        if (
                                                                            (0x20U 
                                                                             & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                                                                            vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                                                << 0x13U));
                                                                            vlTOPp->fexp__DOT__fm1__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                                                                - (IData)(0x12U)));
                                                                        } else {
                                                                            if (
                                                                                (0x10U 
                                                                                & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                                                                                vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                                                << 0x14U));
                                                                                vlTOPp->fexp__DOT__fm1__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                                                                - (IData)(0x13U)));
                                                                            } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                                                                                vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                                                << 0x15U));
                                                                                vlTOPp->fexp__DOT__fm1__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                                                                                vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                                                << 0x16U));
                                                                                vlTOPp->fexp__DOT__fm1__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fexp__DOT__fm1__DOT__mantissa)) {
                                                                                vlTOPp->fexp__DOT__fm1__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                                                                - (IData)(0x16U)));
                                                                                vlTOPp->fexp__DOT__fm1__DOT__mantissa = 0U;
                                                                                } else {
                                                                                vlTOPp->fexp__DOT__fm1__DOT__expF = 0xffU;
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
    vlTOPp->fexp__DOT__fm1__DOT__expF = (0xffU & ((IData)(1U) 
                                                  + (IData)(vlTOPp->fexp__DOT__fm1__DOT__expF)));
    vlTOPp->fexp__DOT__fm1__DOT__mantissa = (0x7fffffU 
                                             & (vlTOPp->fexp__DOT__fm1__DOT__mantissa 
                                                >> 1U));
    vlTOPp->fexp__DOT__fm1__DOT__expF = (0xffU & ((IData)(1U) 
                                                  + (IData)(vlTOPp->fexp__DOT__fm1__DOT__expF)));
    vlTOPp->fexp__DOT__temp4 = ((0x80000000U & (vlTOPp->fexp__DOT__temp2 
                                                ^ vlTOPp->exp)) 
                                | (((IData)(vlTOPp->fexp__DOT__fm1__DOT__expF) 
                                    << 0x17U) | vlTOPp->fexp__DOT__fm1__DOT__mantissa));
    vlTOPp->fexp__DOT__temp1 = ((0x80000000U & ((~ (IData)(vlTOPp->fexp__DOT__fa0__DOT__finalSign)) 
                                                << 0x1fU)) 
                                | (((IData)(vlTOPp->fexp__DOT__fa0__DOT__finalExp) 
                                    << 0x17U) | (0x7fffffU 
                                                 & (vlTOPp->fexp__DOT__fa0__DOT__finalMant 
                                                    >> 1U))));
    vlTOPp->fexp__DOT__fm2__DOT__mantissaProd = (0xffffffffffffULL 
                                                 & ((QData)((IData)(
                                                                    ((0U 
                                                                      == vlTOPp->fexp__DOT__temp4)
                                                                      ? 0U
                                                                      : 
                                                                     (0x800000U 
                                                                      | (0x7fffffU 
                                                                         & vlTOPp->fexp__DOT__temp4))))) 
                                                    * (QData)((IData)(
                                                                      ((0U 
                                                                        == vlTOPp->exp)
                                                                        ? 0U
                                                                        : 
                                                                       (0x800000U 
                                                                        | (0x7fffffU 
                                                                           & vlTOPp->exp)))))));
    vlTOPp->fexp__DOT__fm2__DOT__expF = (0xffU & ((
                                                   (vlTOPp->fexp__DOT__temp4 
                                                    >> 0x17U) 
                                                   + 
                                                   (vlTOPp->exp 
                                                    >> 0x17U)) 
                                                  - (IData)(0x7fU)));
    vlTOPp->fexp__DOT__fm2__DOT__mantissa = (0x7fffffU 
                                             & (IData)(
                                                       (vlTOPp->fexp__DOT__fm2__DOT__mantissaProd 
                                                        >> 0x19U)));
    if ((0x400000U & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
        vlTOPp->fexp__DOT__fm2__DOT__mantissa = (0x7fffffU 
                                                 & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                    << 2U));
        vlTOPp->fexp__DOT__fm2__DOT__expF = (0xffU 
                                             & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                                - (IData)(1U)));
    } else {
        if ((0x200000U & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
            vlTOPp->fexp__DOT__fm2__DOT__mantissa = 
                (0x7fffffU & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                              << 3U));
            vlTOPp->fexp__DOT__fm2__DOT__expF = (0xffU 
                                                 & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                                    - (IData)(2U)));
        } else {
            if ((0x100000U & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                    = (0x7fffffU & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                    << 4U));
                vlTOPp->fexp__DOT__fm2__DOT__expF = 
                    (0xffU & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                              - (IData)(3U)));
            } else {
                if ((0x80000U & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                    vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                        = (0x7fffffU & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                        << 5U));
                    vlTOPp->fexp__DOT__fm2__DOT__expF 
                        = (0xffU & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                    - (IData)(4U)));
                } else {
                    if ((0x40000U & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                        vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                            = (0x7fffffU & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                            << 6U));
                        vlTOPp->fexp__DOT__fm2__DOT__expF 
                            = (0xffU & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                        - (IData)(5U)));
                    } else {
                        if ((0x20000U & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                            vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                = (0x7fffffU & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                << 7U));
                            vlTOPp->fexp__DOT__fm2__DOT__expF 
                                = (0xffU & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                            - (IData)(6U)));
                        } else {
                            if ((0x10000U & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                                vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                    = (0x7fffffU & 
                                       (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                        << 8U));
                                vlTOPp->fexp__DOT__fm2__DOT__expF 
                                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                                - (IData)(7U)));
                            } else {
                                if ((0x8000U & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                                    vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                        = (0x7fffffU 
                                           & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                              << 9U));
                                    vlTOPp->fexp__DOT__fm2__DOT__expF 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                            - (IData)(8U)));
                                } else {
                                    if ((0x4000U & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                                        vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                            = (0x7fffffU 
                                               & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                  << 0xaU));
                                        vlTOPp->fexp__DOT__fm2__DOT__expF 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                                  - (IData)(9U)));
                                    } else {
                                        if ((0x2000U 
                                             & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                                            vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                = (0x7fffffU 
                                                   & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                      << 0xbU));
                                            vlTOPp->fexp__DOT__fm2__DOT__expF 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                                      - (IData)(0xaU)));
                                        } else {
                                            if ((0x1000U 
                                                 & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                                                vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                    = 
                                                    (0x7fffffU 
                                                     & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                        << 0xcU));
                                                vlTOPp->fexp__DOT__fm2__DOT__expF 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                                        - (IData)(0xbU)));
                                            } else {
                                                if (
                                                    (0x800U 
                                                     & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                                                    vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                        = 
                                                        (0x7fffffU 
                                                         & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                            << 0xdU));
                                                    vlTOPp->fexp__DOT__fm2__DOT__expF 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                                            - (IData)(0xcU)));
                                                } else {
                                                    if (
                                                        (0x400U 
                                                         & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                                                        vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                            = 
                                                            (0x7fffffU 
                                                             & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                                << 0xeU));
                                                        vlTOPp->fexp__DOT__fm2__DOT__expF 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                                                - (IData)(0xdU)));
                                                    } else {
                                                        if (
                                                            (0x200U 
                                                             & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                                                            vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                                = 
                                                                (0x7fffffU 
                                                                 & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                                    << 0xfU));
                                                            vlTOPp->fexp__DOT__fm2__DOT__expF 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                                                    - (IData)(0xeU)));
                                                        } else {
                                                            if (
                                                                (0x100U 
                                                                 & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                                                                vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                                    = 
                                                                    (0x7fffffU 
                                                                     & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                                        << 0x10U));
                                                                vlTOPp->fexp__DOT__fm2__DOT__expF 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                                                        - (IData)(0xfU)));
                                                            } else {
                                                                if (
                                                                    (0x80U 
                                                                     & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                                                                    vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                                        = 
                                                                        (0x7fffffU 
                                                                         & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                                            << 0x11U));
                                                                    vlTOPp->fexp__DOT__fm2__DOT__expF 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                                                            - (IData)(0x10U)));
                                                                } else {
                                                                    if (
                                                                        (0x40U 
                                                                         & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                                                                        vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                                            = 
                                                                            (0x7fffffU 
                                                                             & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                                                << 0x12U));
                                                                        vlTOPp->fexp__DOT__fm2__DOT__expF 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                                                                - (IData)(0x11U)));
                                                                    } else {
                                                                        if (
                                                                            (0x20U 
                                                                             & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                                                                            vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                                                << 0x13U));
                                                                            vlTOPp->fexp__DOT__fm2__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                                                                - (IData)(0x12U)));
                                                                        } else {
                                                                            if (
                                                                                (0x10U 
                                                                                & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                                                                                vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                                                << 0x14U));
                                                                                vlTOPp->fexp__DOT__fm2__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                                                                - (IData)(0x13U)));
                                                                            } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                                                                                vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                                                << 0x15U));
                                                                                vlTOPp->fexp__DOT__fm2__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                                                                                vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                                                << 0x16U));
                                                                                vlTOPp->fexp__DOT__fm2__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fexp__DOT__fm2__DOT__mantissa)) {
                                                                                vlTOPp->fexp__DOT__fm2__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                                                                - (IData)(0x16U)));
                                                                                vlTOPp->fexp__DOT__fm2__DOT__mantissa = 0U;
                                                                                } else {
                                                                                vlTOPp->fexp__DOT__fm2__DOT__expF = 0xffU;
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
    vlTOPp->fexp__DOT__fm2__DOT__expF = (0xffU & ((IData)(1U) 
                                                  + (IData)(vlTOPp->fexp__DOT__fm2__DOT__expF)));
    vlTOPp->fexp__DOT__fm2__DOT__mantissa = (0x7fffffU 
                                             & (vlTOPp->fexp__DOT__fm2__DOT__mantissa 
                                                >> 1U));
    vlTOPp->fexp__DOT__fm2__DOT__expF = (0xffU & ((IData)(1U) 
                                                  + (IData)(vlTOPp->fexp__DOT__fm2__DOT__expF)));
    vlTOPp->fexp__DOT__temp6 = ((0x80000000U & (vlTOPp->fexp__DOT__temp4 
                                                ^ vlTOPp->exp)) 
                                | (((IData)(vlTOPp->fexp__DOT__fm2__DOT__expF) 
                                    << 0x17U) | vlTOPp->fexp__DOT__fm2__DOT__mantissa));
    vlTOPp->fexp__DOT__fma0__DOT__mantissa_a = ((0U 
                                                 == vlTOPp->fexp__DOT__temp2)
                                                 ? 0U
                                                 : 
                                                (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlTOPp->fexp__DOT__temp2)));
    vlTOPp->fexp__DOT__fma0__DOT__mantissa_c = ((0U 
                                                 == vlTOPp->fexp__DOT__temp1)
                                                 ? 0U
                                                 : 
                                                (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlTOPp->fexp__DOT__temp1)));
    vlTOPp->fexp__DOT__fma0__DOT__sign_out = (1U & 
                                              (vlTOPp->fexp__DOT__temp2 
                                               >> 0x1fU));
    vlTOPp->fexp__DOT__fma0__DOT__exp_out = (0xffU 
                                             & ((IData)(0xffU) 
                                                + (vlTOPp->fexp__DOT__temp2 
                                                   >> 0x17U)));
    vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_out 
        = (0xffffffffffffULL & ((QData)((IData)(vlTOPp->fexp__DOT__fma0__DOT__mantissa_a)) 
                                << 0x17U));
    vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
        = (0xffffffU & (IData)((vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_out 
                                >> 0x18U)));
    if ((0x800000U & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
        vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
            = (0xffffffU & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                            << 1U));
    } else {
        if ((0x400000U & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
            vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                = (0xffffffU & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                << 2U));
            vlTOPp->fexp__DOT__fma0__DOT__exp_out = 
                (0xffU & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                          - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                    = (0xffffffU & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                    << 3U));
                vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                    vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                        = (0xffffffU & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                        << 4U));
                    vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                        = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                        vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                            = (0xffffffU & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                            << 5U));
                        vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                            = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                            vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                = (0xffffffU & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                << 6U));
                            vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                                = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                                vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                    = (0xffffffU & 
                                       (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                        << 7U));
                                vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                                    vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                        = (0xffffffU 
                                           & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                              << 8U));
                                    vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                                        vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                            = (0xffffffU 
                                               & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                  << 9U));
                                        vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                                            vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                = (0xffffffU 
                                                   & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                      << 0xaU));
                                            vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                                                vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                        << 0xbU));
                                                vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                                                    vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                            << 0xcU));
                                                    vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                                                        vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                << 0xdU));
                                                        vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                                                            vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                    << 0xeU));
                                                            vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                                                                vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                        << 0xfU));
                                                                vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                                                                    vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                            << 0x10U));
                                                                    vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                                                                        vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                                << 0x11U));
                                                                        vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                                                                            vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                                << 0x12U));
                                                                            vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                                << 0x13U));
                                                                                vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                                << 0x14U));
                                                                                vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                                << 0x15U));
                                                                                vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                                << 0x16U));
                                                                                vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                                                                << 0x17U));
                                                                                vlTOPp->fexp__DOT__fma0__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fexp__DOT__fma0__DOT__exp_out = 0xffU;
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
    vlTOPp->fexp__DOT__fma0__DOT__exp_out = (0xffU 
                                             & ((IData)(1U) 
                                                + (IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out)));
    vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
        = ((0U == vlTOPp->fexp__DOT__temp2) ? 0U : 
           (0x800000U | (0x7fffffU & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                      >> 1U))));
    if (((IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out) 
         < (0xffU & (vlTOPp->fexp__DOT__temp1 >> 0x17U)))) {
        vlTOPp->fexp__DOT__fma0__DOT__final_exp = (0xffU 
                                                   & (vlTOPp->fexp__DOT__temp1 
                                                      >> 0x17U));
        vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
            = ((0x17U >= (0xffU & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                   - (IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out))))
                ? (0xffffffU & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                >> (0xffU & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                             - (IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out)))))
                : 0U);
        vlTOPp->fexp__DOT__fma0__DOT__largerMag = 1U;
    } else {
        if (((0xffU & (vlTOPp->fexp__DOT__temp1 >> 0x17U)) 
             < (IData)(vlTOPp->fexp__DOT__fma0__DOT__exp_out))) {
            vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                = vlTOPp->fexp__DOT__fma0__DOT__exp_out;
            vlTOPp->fexp__DOT__fma0__DOT__mantissa_c 
                = ((0x17U >= (0xffU & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                       - (vlTOPp->fexp__DOT__temp1 
                                          >> 0x17U))))
                    ? (0xffffffU & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_c 
                                    >> (0xffU & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                                 - 
                                                 (vlTOPp->fexp__DOT__temp1 
                                                  >> 0x17U)))))
                    : 0U);
            vlTOPp->fexp__DOT__fma0__DOT__largerMag = 0U;
        } else {
            vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                = vlTOPp->fexp__DOT__fma0__DOT__exp_out;
            vlTOPp->fexp__DOT__fma0__DOT__largerMag 
                = (vlTOPp->fexp__DOT__fma0__DOT__mantissa_c 
                   > vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm);
        }
    }
    if (((IData)(vlTOPp->fexp__DOT__fma0__DOT__sign_out) 
         & (vlTOPp->fexp__DOT__temp1 >> 0x1fU))) {
        vlTOPp->fexp__DOT__fma0__DOT__sum_mants = (0x1ffffffU 
                                                   & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_c 
                                                      + vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm));
        vlTOPp->fexp__DOT__fma0__DOT__final_exp = (0xffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp)));
        vlTOPp->fexp__DOT__fma0__DOT__sign_out = 0U;
        vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
            = (0xffffffU & (vlTOPp->fexp__DOT__fma0__DOT__sum_mants 
                            >> 1U));
    } else {
        if (((IData)(vlTOPp->fexp__DOT__fma0__DOT__sign_out) 
             & (~ (vlTOPp->fexp__DOT__temp1 >> 0x1fU)))) {
            vlTOPp->fexp__DOT__fma0__DOT__sum_mants 
                = (0x1ffffffU & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm 
                                 - vlTOPp->fexp__DOT__fma0__DOT__mantissa_c));
            vlTOPp->fexp__DOT__fma0__DOT__sign_out 
                = vlTOPp->fexp__DOT__fma0__DOT__largerMag;
            vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                = (0xffffffU & vlTOPp->fexp__DOT__fma0__DOT__sum_mants);
            vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                = (0xffffffU & ((0x1000000U & vlTOPp->fexp__DOT__fma0__DOT__sum_mants)
                                 ? ((IData)(0xffffffffU) 
                                    * vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)
                                 : vlTOPp->fexp__DOT__fma0__DOT__final_mantissa));
        } else {
            if ((1U & ((~ (IData)(vlTOPp->fexp__DOT__fma0__DOT__sign_out)) 
                       & (vlTOPp->fexp__DOT__temp1 
                          >> 0x1fU)))) {
                vlTOPp->fexp__DOT__fma0__DOT__sum_mants 
                    = (0x1ffffffU & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_c 
                                     - vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm));
                vlTOPp->fexp__DOT__fma0__DOT__sign_out 
                    = (1U & (~ (IData)(vlTOPp->fexp__DOT__fma0__DOT__largerMag)));
                vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                    = (0xffffffU & vlTOPp->fexp__DOT__fma0__DOT__sum_mants);
                vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                    = (0xffffffU & ((0x1000000U & vlTOPp->fexp__DOT__fma0__DOT__sum_mants)
                                     ? ((IData)(0xffffffffU) 
                                        * vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)
                                     : vlTOPp->fexp__DOT__fma0__DOT__final_mantissa));
            } else {
                vlTOPp->fexp__DOT__fma0__DOT__sum_mants 
                    = (0x1ffffffU & (vlTOPp->fexp__DOT__fma0__DOT__mantissa_c 
                                     + vlTOPp->fexp__DOT__fma0__DOT__mantissa_mul_norm));
                vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp)));
                vlTOPp->fexp__DOT__fma0__DOT__sign_out = 1U;
                vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                    = (0xffffffU & (vlTOPp->fexp__DOT__fma0__DOT__sum_mants 
                                    >> 1U));
            }
        }
    }
    if ((0x800000U & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
        vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
            = (0xffffffU & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                            << 1U));
    } else {
        if ((0x400000U & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
            vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                = (0xffffffU & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                << 2U));
            vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                            - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                    = (0xffffffU & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                    << 3U));
                vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                    vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                        = (0xffffffU & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                        << 4U));
                    vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                        = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                        vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                            = (0xffffffU & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                            << 5U));
                        vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                            = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                            vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                = (0xffffffU & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                << 6U));
                            vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                                vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                    = (0xffffffU & 
                                       (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                        << 7U));
                                vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                                    vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                        = (0xffffffU 
                                           & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                              << 8U));
                                    vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                                        vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                            = (0xffffffU 
                                               & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                  << 9U));
                                        vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                                            vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                = (0xffffffU 
                                                   & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                      << 0xaU));
                                            vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                                                vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                        << 0xbU));
                                                vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                                                    vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                            << 0xcU));
                                                    vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                                                        vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                << 0xdU));
                                                        vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                                                            vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                    << 0xeU));
                                                            vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                                                                vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                        << 0xfU));
                                                                vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                                                                    vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                            << 0x10U));
                                                                    vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                                                                        vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                                << 0x11U));
                                                                        vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                                                                            vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                                << 0x12U));
                                                                            vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                                << 0x13U));
                                                                                vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                                << 0x14U));
                                                                                vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                                << 0x15U));
                                                                                vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                                << 0x16U));
                                                                                vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fexp__DOT__fma0__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                                                << 0x17U));
                                                                                vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fexp__DOT__fma0__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
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
    vlTOPp->fexp__DOT__fm3__DOT__mantissaProd = (0xffffffffffffULL 
                                                 & ((QData)((IData)(
                                                                    ((0U 
                                                                      == vlTOPp->fexp__DOT__temp6)
                                                                      ? 0U
                                                                      : 
                                                                     (0x800000U 
                                                                      | (0x7fffffU 
                                                                         & vlTOPp->fexp__DOT__temp6))))) 
                                                    * (QData)((IData)(
                                                                      ((0U 
                                                                        == vlTOPp->exp)
                                                                        ? 0U
                                                                        : 
                                                                       (0x800000U 
                                                                        | (0x7fffffU 
                                                                           & vlTOPp->exp)))))));
    vlTOPp->fexp__DOT__fm3__DOT__expF = (0xffU & ((
                                                   (vlTOPp->fexp__DOT__temp6 
                                                    >> 0x17U) 
                                                   + 
                                                   (vlTOPp->exp 
                                                    >> 0x17U)) 
                                                  - (IData)(0x7fU)));
    vlTOPp->fexp__DOT__fm3__DOT__mantissa = (0x7fffffU 
                                             & (IData)(
                                                       (vlTOPp->fexp__DOT__fm3__DOT__mantissaProd 
                                                        >> 0x19U)));
    if ((0x400000U & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
        vlTOPp->fexp__DOT__fm3__DOT__mantissa = (0x7fffffU 
                                                 & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                    << 2U));
        vlTOPp->fexp__DOT__fm3__DOT__expF = (0xffU 
                                             & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                                - (IData)(1U)));
    } else {
        if ((0x200000U & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
            vlTOPp->fexp__DOT__fm3__DOT__mantissa = 
                (0x7fffffU & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                              << 3U));
            vlTOPp->fexp__DOT__fm3__DOT__expF = (0xffU 
                                                 & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                                    - (IData)(2U)));
        } else {
            if ((0x100000U & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                    = (0x7fffffU & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                    << 4U));
                vlTOPp->fexp__DOT__fm3__DOT__expF = 
                    (0xffU & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                              - (IData)(3U)));
            } else {
                if ((0x80000U & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                    vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                        = (0x7fffffU & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                        << 5U));
                    vlTOPp->fexp__DOT__fm3__DOT__expF 
                        = (0xffU & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                    - (IData)(4U)));
                } else {
                    if ((0x40000U & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                        vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                            = (0x7fffffU & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                            << 6U));
                        vlTOPp->fexp__DOT__fm3__DOT__expF 
                            = (0xffU & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                        - (IData)(5U)));
                    } else {
                        if ((0x20000U & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                            vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                = (0x7fffffU & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                << 7U));
                            vlTOPp->fexp__DOT__fm3__DOT__expF 
                                = (0xffU & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                            - (IData)(6U)));
                        } else {
                            if ((0x10000U & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                                vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                    = (0x7fffffU & 
                                       (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                        << 8U));
                                vlTOPp->fexp__DOT__fm3__DOT__expF 
                                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                                - (IData)(7U)));
                            } else {
                                if ((0x8000U & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                                    vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                        = (0x7fffffU 
                                           & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                              << 9U));
                                    vlTOPp->fexp__DOT__fm3__DOT__expF 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                            - (IData)(8U)));
                                } else {
                                    if ((0x4000U & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                                        vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                            = (0x7fffffU 
                                               & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                  << 0xaU));
                                        vlTOPp->fexp__DOT__fm3__DOT__expF 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                                  - (IData)(9U)));
                                    } else {
                                        if ((0x2000U 
                                             & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                                            vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                = (0x7fffffU 
                                                   & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                      << 0xbU));
                                            vlTOPp->fexp__DOT__fm3__DOT__expF 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                                      - (IData)(0xaU)));
                                        } else {
                                            if ((0x1000U 
                                                 & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                                                vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                    = 
                                                    (0x7fffffU 
                                                     & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                        << 0xcU));
                                                vlTOPp->fexp__DOT__fm3__DOT__expF 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                                        - (IData)(0xbU)));
                                            } else {
                                                if (
                                                    (0x800U 
                                                     & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                                                    vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                        = 
                                                        (0x7fffffU 
                                                         & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                            << 0xdU));
                                                    vlTOPp->fexp__DOT__fm3__DOT__expF 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                                            - (IData)(0xcU)));
                                                } else {
                                                    if (
                                                        (0x400U 
                                                         & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                                                        vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                            = 
                                                            (0x7fffffU 
                                                             & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                                << 0xeU));
                                                        vlTOPp->fexp__DOT__fm3__DOT__expF 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                                                - (IData)(0xdU)));
                                                    } else {
                                                        if (
                                                            (0x200U 
                                                             & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                                                            vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                                = 
                                                                (0x7fffffU 
                                                                 & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                                    << 0xfU));
                                                            vlTOPp->fexp__DOT__fm3__DOT__expF 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                                                    - (IData)(0xeU)));
                                                        } else {
                                                            if (
                                                                (0x100U 
                                                                 & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                                                                vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                                    = 
                                                                    (0x7fffffU 
                                                                     & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                                        << 0x10U));
                                                                vlTOPp->fexp__DOT__fm3__DOT__expF 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                                                        - (IData)(0xfU)));
                                                            } else {
                                                                if (
                                                                    (0x80U 
                                                                     & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                                                                    vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                                        = 
                                                                        (0x7fffffU 
                                                                         & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                                            << 0x11U));
                                                                    vlTOPp->fexp__DOT__fm3__DOT__expF 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                                                            - (IData)(0x10U)));
                                                                } else {
                                                                    if (
                                                                        (0x40U 
                                                                         & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                                                                        vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                                            = 
                                                                            (0x7fffffU 
                                                                             & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                                                << 0x12U));
                                                                        vlTOPp->fexp__DOT__fm3__DOT__expF 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                                                                - (IData)(0x11U)));
                                                                    } else {
                                                                        if (
                                                                            (0x20U 
                                                                             & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                                                                            vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                                                << 0x13U));
                                                                            vlTOPp->fexp__DOT__fm3__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                                                                - (IData)(0x12U)));
                                                                        } else {
                                                                            if (
                                                                                (0x10U 
                                                                                & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                                                                                vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                                                << 0x14U));
                                                                                vlTOPp->fexp__DOT__fm3__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                                                                - (IData)(0x13U)));
                                                                            } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                                                                                vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                                                << 0x15U));
                                                                                vlTOPp->fexp__DOT__fm3__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                                                                                vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                                                << 0x16U));
                                                                                vlTOPp->fexp__DOT__fm3__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fexp__DOT__fm3__DOT__mantissa)) {
                                                                                vlTOPp->fexp__DOT__fm3__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                                                                - (IData)(0x16U)));
                                                                                vlTOPp->fexp__DOT__fm3__DOT__mantissa = 0U;
                                                                                } else {
                                                                                vlTOPp->fexp__DOT__fm3__DOT__expF = 0xffU;
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
    vlTOPp->fexp__DOT__fm3__DOT__expF = (0xffU & ((IData)(1U) 
                                                  + (IData)(vlTOPp->fexp__DOT__fm3__DOT__expF)));
    vlTOPp->fexp__DOT__fm3__DOT__mantissa = (0x7fffffU 
                                             & (vlTOPp->fexp__DOT__fm3__DOT__mantissa 
                                                >> 1U));
    vlTOPp->fexp__DOT__fm3__DOT__expF = (0xffU & ((IData)(1U) 
                                                  + (IData)(vlTOPp->fexp__DOT__fm3__DOT__expF)));
    vlTOPp->fexp__DOT__temp8 = ((0x80000000U & (vlTOPp->fexp__DOT__temp6 
                                                ^ vlTOPp->exp)) 
                                | (((IData)(vlTOPp->fexp__DOT__fm3__DOT__expF) 
                                    << 0x17U) | vlTOPp->fexp__DOT__fm3__DOT__mantissa));
    vlTOPp->fexp__DOT__temp3 = ((0x80000000U & ((~ (IData)(vlTOPp->fexp__DOT__fma0__DOT__sign_out)) 
                                                << 0x1fU)) 
                                | (((IData)(vlTOPp->fexp__DOT__fma0__DOT__final_exp) 
                                    << 0x17U) | (0x7fffffU 
                                                 & (vlTOPp->fexp__DOT__fma0__DOT__final_mantissa 
                                                    >> 1U))));
    vlTOPp->fexp__DOT__fma1__DOT__mantissa_a = ((0U 
                                                 == vlTOPp->fexp__DOT__temp4)
                                                 ? 0U
                                                 : 
                                                (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlTOPp->fexp__DOT__temp4)));
    vlTOPp->fexp__DOT__fma1__DOT__mantissa_c = ((0U 
                                                 == vlTOPp->fexp__DOT__temp3)
                                                 ? 0U
                                                 : 
                                                (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlTOPp->fexp__DOT__temp3)));
    vlTOPp->fexp__DOT__fma1__DOT__sign_out = (1U & 
                                              (vlTOPp->fexp__DOT__temp4 
                                               >> 0x1fU));
    vlTOPp->fexp__DOT__fma1__DOT__exp_out = (0xffU 
                                             & ((IData)(0xfdU) 
                                                + (vlTOPp->fexp__DOT__temp4 
                                                   >> 0x17U)));
    vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_out 
        = (0xffffffffffffULL & (0xaaaaabULL * (QData)((IData)(vlTOPp->fexp__DOT__fma1__DOT__mantissa_a))));
    vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
        = (0xffffffU & (IData)((vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_out 
                                >> 0x18U)));
    if ((0x800000U & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
        vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
            = (0xffffffU & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                            << 1U));
    } else {
        if ((0x400000U & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
            vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                = (0xffffffU & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                << 2U));
            vlTOPp->fexp__DOT__fma1__DOT__exp_out = 
                (0xffU & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                          - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                    = (0xffffffU & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                    << 3U));
                vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                    vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                        = (0xffffffU & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                        << 4U));
                    vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                        = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                        vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                            = (0xffffffU & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                            << 5U));
                        vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                            = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                            vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                = (0xffffffU & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                << 6U));
                            vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                                = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                                vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                    = (0xffffffU & 
                                       (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                        << 7U));
                                vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                                    vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                        = (0xffffffU 
                                           & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                              << 8U));
                                    vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                                        vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                            = (0xffffffU 
                                               & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                  << 9U));
                                        vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                                            vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                = (0xffffffU 
                                                   & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                      << 0xaU));
                                            vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                        << 0xbU));
                                                vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                    vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                            << 0xcU));
                                                    vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                        vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                << 0xdU));
                                                        vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                            vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                    << 0xeU));
                                                            vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                                vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                        << 0xfU));
                                                                vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                                    vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                            << 0x10U));
                                                                    vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                                        vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                << 0x11U));
                                                                        vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                                            vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                << 0x12U));
                                                                            vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                << 0x13U));
                                                                                vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                << 0x14U));
                                                                                vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                << 0x15U));
                                                                                vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                << 0x16U));
                                                                                vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                << 0x17U));
                                                                                vlTOPp->fexp__DOT__fma1__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fexp__DOT__fma1__DOT__exp_out = 0xffU;
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
    vlTOPp->fexp__DOT__fma1__DOT__exp_out = (0xffU 
                                             & ((IData)(1U) 
                                                + (IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out)));
    vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
        = ((0U == vlTOPp->fexp__DOT__temp4) ? 0U : 
           (0x800000U | (0x7fffffU & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                      >> 1U))));
    if (((IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out) 
         < (0xffU & (vlTOPp->fexp__DOT__temp3 >> 0x17U)))) {
        vlTOPp->fexp__DOT__fma1__DOT__final_exp = (0xffU 
                                                   & (vlTOPp->fexp__DOT__temp3 
                                                      >> 0x17U));
        vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
            = ((0x17U >= (0xffU & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                   - (IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out))))
                ? (0xffffffU & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                >> (0xffU & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                             - (IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out)))))
                : 0U);
        vlTOPp->fexp__DOT__fma1__DOT__largerMag = 1U;
    } else {
        if (((0xffU & (vlTOPp->fexp__DOT__temp3 >> 0x17U)) 
             < (IData)(vlTOPp->fexp__DOT__fma1__DOT__exp_out))) {
            vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                = vlTOPp->fexp__DOT__fma1__DOT__exp_out;
            vlTOPp->fexp__DOT__fma1__DOT__mantissa_c 
                = ((0x17U >= (0xffU & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                       - (vlTOPp->fexp__DOT__temp3 
                                          >> 0x17U))))
                    ? (0xffffffU & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_c 
                                    >> (0xffU & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                                 - 
                                                 (vlTOPp->fexp__DOT__temp3 
                                                  >> 0x17U)))))
                    : 0U);
            vlTOPp->fexp__DOT__fma1__DOT__largerMag = 0U;
        } else {
            vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                = vlTOPp->fexp__DOT__fma1__DOT__exp_out;
            vlTOPp->fexp__DOT__fma1__DOT__largerMag 
                = (vlTOPp->fexp__DOT__fma1__DOT__mantissa_c 
                   > vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm);
        }
    }
    if (((IData)(vlTOPp->fexp__DOT__fma1__DOT__sign_out) 
         & (vlTOPp->fexp__DOT__temp3 >> 0x1fU))) {
        vlTOPp->fexp__DOT__fma1__DOT__sum_mants = (0x1ffffffU 
                                                   & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_c 
                                                      + vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm));
        vlTOPp->fexp__DOT__fma1__DOT__final_exp = (0xffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp)));
        vlTOPp->fexp__DOT__fma1__DOT__sign_out = 0U;
        vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
            = (0xffffffU & (vlTOPp->fexp__DOT__fma1__DOT__sum_mants 
                            >> 1U));
    } else {
        if (((IData)(vlTOPp->fexp__DOT__fma1__DOT__sign_out) 
             & (~ (vlTOPp->fexp__DOT__temp3 >> 0x1fU)))) {
            vlTOPp->fexp__DOT__fma1__DOT__sum_mants 
                = (0x1ffffffU & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm 
                                 - vlTOPp->fexp__DOT__fma1__DOT__mantissa_c));
            vlTOPp->fexp__DOT__fma1__DOT__sign_out 
                = vlTOPp->fexp__DOT__fma1__DOT__largerMag;
            vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                = (0xffffffU & vlTOPp->fexp__DOT__fma1__DOT__sum_mants);
            vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                = (0xffffffU & ((0x1000000U & vlTOPp->fexp__DOT__fma1__DOT__sum_mants)
                                 ? ((IData)(0xffffffffU) 
                                    * vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)
                                 : vlTOPp->fexp__DOT__fma1__DOT__final_mantissa));
        } else {
            if ((1U & ((~ (IData)(vlTOPp->fexp__DOT__fma1__DOT__sign_out)) 
                       & (vlTOPp->fexp__DOT__temp3 
                          >> 0x1fU)))) {
                vlTOPp->fexp__DOT__fma1__DOT__sum_mants 
                    = (0x1ffffffU & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_c 
                                     - vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm));
                vlTOPp->fexp__DOT__fma1__DOT__sign_out 
                    = (1U & (~ (IData)(vlTOPp->fexp__DOT__fma1__DOT__largerMag)));
                vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                    = (0xffffffU & vlTOPp->fexp__DOT__fma1__DOT__sum_mants);
                vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                    = (0xffffffU & ((0x1000000U & vlTOPp->fexp__DOT__fma1__DOT__sum_mants)
                                     ? ((IData)(0xffffffffU) 
                                        * vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)
                                     : vlTOPp->fexp__DOT__fma1__DOT__final_mantissa));
            } else {
                vlTOPp->fexp__DOT__fma1__DOT__sum_mants 
                    = (0x1ffffffU & (vlTOPp->fexp__DOT__fma1__DOT__mantissa_c 
                                     + vlTOPp->fexp__DOT__fma1__DOT__mantissa_mul_norm));
                vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp)));
                vlTOPp->fexp__DOT__fma1__DOT__sign_out = 1U;
                vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                    = (0xffffffU & (vlTOPp->fexp__DOT__fma1__DOT__sum_mants 
                                    >> 1U));
            }
        }
    }
    if ((0x800000U & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
        vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
            = (0xffffffU & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                            << 1U));
    } else {
        if ((0x400000U & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
            vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                = (0xffffffU & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                << 2U));
            vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                            - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                    = (0xffffffU & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                    << 3U));
                vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                    vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                        = (0xffffffU & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                        << 4U));
                    vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                        = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                        vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                            = (0xffffffU & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                            << 5U));
                        vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                            = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                            vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                = (0xffffffU & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                << 6U));
                            vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                                vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                    = (0xffffffU & 
                                       (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                        << 7U));
                                vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                                    vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                        = (0xffffffU 
                                           & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                              << 8U));
                                    vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                                        vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                            = (0xffffffU 
                                               & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                  << 9U));
                                        vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                                            vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                = (0xffffffU 
                                                   & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                      << 0xaU));
                                            vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                                                vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                        << 0xbU));
                                                vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                                                    vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                            << 0xcU));
                                                    vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                                                        vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                << 0xdU));
                                                        vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                                                            vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                    << 0xeU));
                                                            vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                                                                vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                        << 0xfU));
                                                                vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                                                                    vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                            << 0x10U));
                                                                    vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                                                                        vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                                << 0x11U));
                                                                        vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                                                                            vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                                << 0x12U));
                                                                            vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                                << 0x13U));
                                                                                vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                                << 0x14U));
                                                                                vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                                << 0x15U));
                                                                                vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                                << 0x16U));
                                                                                vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fexp__DOT__fma1__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                                                << 0x17U));
                                                                                vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fexp__DOT__fma1__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
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
    vlTOPp->fexp__DOT__temp5 = ((0x80000000U & ((~ (IData)(vlTOPp->fexp__DOT__fma1__DOT__sign_out)) 
                                                << 0x1fU)) 
                                | (((IData)(vlTOPp->fexp__DOT__fma1__DOT__final_exp) 
                                    << 0x17U) | (0x7fffffU 
                                                 & (vlTOPp->fexp__DOT__fma1__DOT__final_mantissa 
                                                    >> 1U))));
    vlTOPp->fexp__DOT__fma2__DOT__mantissa_a = ((0U 
                                                 == vlTOPp->fexp__DOT__temp6)
                                                 ? 0U
                                                 : 
                                                (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlTOPp->fexp__DOT__temp6)));
    vlTOPp->fexp__DOT__fma2__DOT__mantissa_c = ((0U 
                                                 == vlTOPp->fexp__DOT__temp5)
                                                 ? 0U
                                                 : 
                                                (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlTOPp->fexp__DOT__temp5)));
    vlTOPp->fexp__DOT__fma2__DOT__sign_out = (1U & 
                                              (vlTOPp->fexp__DOT__temp6 
                                               >> 0x1fU));
    vlTOPp->fexp__DOT__fma2__DOT__exp_out = (0xffU 
                                             & ((IData)(0xfbU) 
                                                + (vlTOPp->fexp__DOT__temp6 
                                                   >> 0x17U)));
    vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_out 
        = (0xffffffffffffULL & (0xaaaaabULL * (QData)((IData)(vlTOPp->fexp__DOT__fma2__DOT__mantissa_a))));
    vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
        = (0xffffffU & (IData)((vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_out 
                                >> 0x18U)));
    if ((0x800000U & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
        vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
            = (0xffffffU & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                            << 1U));
    } else {
        if ((0x400000U & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
            vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                = (0xffffffU & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                << 2U));
            vlTOPp->fexp__DOT__fma2__DOT__exp_out = 
                (0xffU & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                          - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                    = (0xffffffU & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                    << 3U));
                vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                    vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                        = (0xffffffU & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                        << 4U));
                    vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                        = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                        vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                            = (0xffffffU & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                            << 5U));
                        vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                            = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                            vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                = (0xffffffU & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                << 6U));
                            vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                                = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                                vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                    = (0xffffffU & 
                                       (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                        << 7U));
                                vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                                    vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                        = (0xffffffU 
                                           & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                              << 8U));
                                    vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                                        vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                            = (0xffffffU 
                                               & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                  << 9U));
                                        vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                                            vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                = (0xffffffU 
                                                   & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                      << 0xaU));
                                            vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                        << 0xbU));
                                                vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                    vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                            << 0xcU));
                                                    vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                        vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                << 0xdU));
                                                        vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                            vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                    << 0xeU));
                                                            vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                                vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                        << 0xfU));
                                                                vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                                    vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                            << 0x10U));
                                                                    vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                                        vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                << 0x11U));
                                                                        vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                                            vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                << 0x12U));
                                                                            vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                << 0x13U));
                                                                                vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                << 0x14U));
                                                                                vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                << 0x15U));
                                                                                vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                << 0x16U));
                                                                                vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                << 0x17U));
                                                                                vlTOPp->fexp__DOT__fma2__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fexp__DOT__fma2__DOT__exp_out = 0xffU;
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
    vlTOPp->fexp__DOT__fma2__DOT__exp_out = (0xffU 
                                             & ((IData)(1U) 
                                                + (IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out)));
    vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
        = ((0U == vlTOPp->fexp__DOT__temp6) ? 0U : 
           (0x800000U | (0x7fffffU & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                      >> 1U))));
    if (((IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out) 
         < (0xffU & (vlTOPp->fexp__DOT__temp5 >> 0x17U)))) {
        vlTOPp->fexp__DOT__fma2__DOT__final_exp = (0xffU 
                                                   & (vlTOPp->fexp__DOT__temp5 
                                                      >> 0x17U));
        vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
            = ((0x17U >= (0xffU & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                   - (IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out))))
                ? (0xffffffU & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                >> (0xffU & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                             - (IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out)))))
                : 0U);
        vlTOPp->fexp__DOT__fma2__DOT__largerMag = 1U;
    } else {
        if (((0xffU & (vlTOPp->fexp__DOT__temp5 >> 0x17U)) 
             < (IData)(vlTOPp->fexp__DOT__fma2__DOT__exp_out))) {
            vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                = vlTOPp->fexp__DOT__fma2__DOT__exp_out;
            vlTOPp->fexp__DOT__fma2__DOT__mantissa_c 
                = ((0x17U >= (0xffU & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                       - (vlTOPp->fexp__DOT__temp5 
                                          >> 0x17U))))
                    ? (0xffffffU & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_c 
                                    >> (0xffU & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                                 - 
                                                 (vlTOPp->fexp__DOT__temp5 
                                                  >> 0x17U)))))
                    : 0U);
            vlTOPp->fexp__DOT__fma2__DOT__largerMag = 0U;
        } else {
            vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                = vlTOPp->fexp__DOT__fma2__DOT__exp_out;
            vlTOPp->fexp__DOT__fma2__DOT__largerMag 
                = (vlTOPp->fexp__DOT__fma2__DOT__mantissa_c 
                   > vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm);
        }
    }
    if (((IData)(vlTOPp->fexp__DOT__fma2__DOT__sign_out) 
         & (vlTOPp->fexp__DOT__temp5 >> 0x1fU))) {
        vlTOPp->fexp__DOT__fma2__DOT__sum_mants = (0x1ffffffU 
                                                   & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_c 
                                                      + vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm));
        vlTOPp->fexp__DOT__fma2__DOT__final_exp = (0xffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp)));
        vlTOPp->fexp__DOT__fma2__DOT__sign_out = 0U;
        vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
            = (0xffffffU & (vlTOPp->fexp__DOT__fma2__DOT__sum_mants 
                            >> 1U));
    } else {
        if (((IData)(vlTOPp->fexp__DOT__fma2__DOT__sign_out) 
             & (~ (vlTOPp->fexp__DOT__temp5 >> 0x1fU)))) {
            vlTOPp->fexp__DOT__fma2__DOT__sum_mants 
                = (0x1ffffffU & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm 
                                 - vlTOPp->fexp__DOT__fma2__DOT__mantissa_c));
            vlTOPp->fexp__DOT__fma2__DOT__sign_out 
                = vlTOPp->fexp__DOT__fma2__DOT__largerMag;
            vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                = (0xffffffU & vlTOPp->fexp__DOT__fma2__DOT__sum_mants);
            vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                = (0xffffffU & ((0x1000000U & vlTOPp->fexp__DOT__fma2__DOT__sum_mants)
                                 ? ((IData)(0xffffffffU) 
                                    * vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)
                                 : vlTOPp->fexp__DOT__fma2__DOT__final_mantissa));
        } else {
            if ((1U & ((~ (IData)(vlTOPp->fexp__DOT__fma2__DOT__sign_out)) 
                       & (vlTOPp->fexp__DOT__temp5 
                          >> 0x1fU)))) {
                vlTOPp->fexp__DOT__fma2__DOT__sum_mants 
                    = (0x1ffffffU & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_c 
                                     - vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm));
                vlTOPp->fexp__DOT__fma2__DOT__sign_out 
                    = (1U & (~ (IData)(vlTOPp->fexp__DOT__fma2__DOT__largerMag)));
                vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                    = (0xffffffU & vlTOPp->fexp__DOT__fma2__DOT__sum_mants);
                vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                    = (0xffffffU & ((0x1000000U & vlTOPp->fexp__DOT__fma2__DOT__sum_mants)
                                     ? ((IData)(0xffffffffU) 
                                        * vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)
                                     : vlTOPp->fexp__DOT__fma2__DOT__final_mantissa));
            } else {
                vlTOPp->fexp__DOT__fma2__DOT__sum_mants 
                    = (0x1ffffffU & (vlTOPp->fexp__DOT__fma2__DOT__mantissa_c 
                                     + vlTOPp->fexp__DOT__fma2__DOT__mantissa_mul_norm));
                vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp)));
                vlTOPp->fexp__DOT__fma2__DOT__sign_out = 1U;
                vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                    = (0xffffffU & (vlTOPp->fexp__DOT__fma2__DOT__sum_mants 
                                    >> 1U));
            }
        }
    }
    if ((0x800000U & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
        vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
            = (0xffffffU & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                            << 1U));
    } else {
        if ((0x400000U & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
            vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                = (0xffffffU & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                << 2U));
            vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                            - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                    = (0xffffffU & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                    << 3U));
                vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                    vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                        = (0xffffffU & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                        << 4U));
                    vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                        = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                        vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                            = (0xffffffU & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                            << 5U));
                        vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                            = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                            vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                = (0xffffffU & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                << 6U));
                            vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                                vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                    = (0xffffffU & 
                                       (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                        << 7U));
                                vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                                    vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                        = (0xffffffU 
                                           & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                              << 8U));
                                    vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                                        vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                            = (0xffffffU 
                                               & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                  << 9U));
                                        vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                                            vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                = (0xffffffU 
                                                   & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                      << 0xaU));
                                            vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                                                vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                        << 0xbU));
                                                vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                                                    vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                            << 0xcU));
                                                    vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                                                        vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                << 0xdU));
                                                        vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                                                            vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                    << 0xeU));
                                                            vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                                                                vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                        << 0xfU));
                                                                vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                                                                    vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                            << 0x10U));
                                                                    vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                                                                        vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                                << 0x11U));
                                                                        vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                                                                            vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                                << 0x12U));
                                                                            vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                                << 0x13U));
                                                                                vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                                << 0x14U));
                                                                                vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                                << 0x15U));
                                                                                vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                                << 0x16U));
                                                                                vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fexp__DOT__fma2__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                                                << 0x17U));
                                                                                vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fexp__DOT__fma2__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
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
    vlTOPp->fexp__DOT__temp7 = ((0x80000000U & ((~ (IData)(vlTOPp->fexp__DOT__fma2__DOT__sign_out)) 
                                                << 0x1fU)) 
                                | (((IData)(vlTOPp->fexp__DOT__fma2__DOT__final_exp) 
                                    << 0x17U) | (0x7fffffU 
                                                 & (vlTOPp->fexp__DOT__fma2__DOT__final_mantissa 
                                                    >> 1U))));
    vlTOPp->fexp__DOT__fma3__DOT__mantissa_a = ((0U 
                                                 == vlTOPp->fexp__DOT__temp8)
                                                 ? 0U
                                                 : 
                                                (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlTOPp->fexp__DOT__temp8)));
    vlTOPp->fexp__DOT__fma3__DOT__mantissa_c = ((0U 
                                                 == vlTOPp->fexp__DOT__temp7)
                                                 ? 0U
                                                 : 
                                                (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlTOPp->fexp__DOT__temp7)));
    vlTOPp->fexp__DOT__fma3__DOT__sign_out = (1U & 
                                              (vlTOPp->fexp__DOT__temp8 
                                               >> 0x1fU));
    vlTOPp->fexp__DOT__fma3__DOT__exp_out = (0xffU 
                                             & ((IData)(0xf9U) 
                                                + (vlTOPp->fexp__DOT__temp8 
                                                   >> 0x17U)));
    vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_out 
        = (0xffffffffffffULL & (0x888889ULL * (QData)((IData)(vlTOPp->fexp__DOT__fma3__DOT__mantissa_a))));
    vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
        = (0xffffffU & (IData)((vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_out 
                                >> 0x18U)));
    if ((0x800000U & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
        vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
            = (0xffffffU & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                            << 1U));
    } else {
        if ((0x400000U & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
            vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                = (0xffffffU & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                << 2U));
            vlTOPp->fexp__DOT__fma3__DOT__exp_out = 
                (0xffU & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                          - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                    = (0xffffffU & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                    << 3U));
                vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                    vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                        = (0xffffffU & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                        << 4U));
                    vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                        = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                        vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                            = (0xffffffU & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                            << 5U));
                        vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                            = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                            vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                = (0xffffffU & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                << 6U));
                            vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                                = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                                vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                    = (0xffffffU & 
                                       (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                        << 7U));
                                vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                                    vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                        = (0xffffffU 
                                           & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                              << 8U));
                                    vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                                        vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                            = (0xffffffU 
                                               & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                  << 9U));
                                        vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                                            vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                = (0xffffffU 
                                                   & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                      << 0xaU));
                                            vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                                                vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                        << 0xbU));
                                                vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                                                    vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                            << 0xcU));
                                                    vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                                                        vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                << 0xdU));
                                                        vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                                                            vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                    << 0xeU));
                                                            vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                                                                vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                        << 0xfU));
                                                                vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                                                                    vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                            << 0x10U));
                                                                    vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                                                                        vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                                << 0x11U));
                                                                        vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                                                                            vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                                << 0x12U));
                                                                            vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                                << 0x13U));
                                                                                vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                                << 0x14U));
                                                                                vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                                << 0x15U));
                                                                                vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                                << 0x16U));
                                                                                vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                                                                << 0x17U));
                                                                                vlTOPp->fexp__DOT__fma3__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fexp__DOT__fma3__DOT__exp_out = 0xffU;
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
    vlTOPp->fexp__DOT__fma3__DOT__exp_out = (0xffU 
                                             & ((IData)(1U) 
                                                + (IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out)));
    vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
        = ((0U == vlTOPp->fexp__DOT__temp8) ? 0U : 
           (0x800000U | (0x7fffffU & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                      >> 1U))));
    if (((IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out) 
         < (0xffU & (vlTOPp->fexp__DOT__temp7 >> 0x17U)))) {
        vlTOPp->fexp__DOT__fma3__DOT__final_exp = (0xffU 
                                                   & (vlTOPp->fexp__DOT__temp7 
                                                      >> 0x17U));
        vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
            = ((0x17U >= (0xffU & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                   - (IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out))))
                ? (0xffffffU & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                >> (0xffU & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                             - (IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out)))))
                : 0U);
        vlTOPp->fexp__DOT__fma3__DOT__largerMag = 1U;
    } else {
        if (((0xffU & (vlTOPp->fexp__DOT__temp7 >> 0x17U)) 
             < (IData)(vlTOPp->fexp__DOT__fma3__DOT__exp_out))) {
            vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                = vlTOPp->fexp__DOT__fma3__DOT__exp_out;
            vlTOPp->fexp__DOT__fma3__DOT__mantissa_c 
                = ((0x17U >= (0xffU & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                       - (vlTOPp->fexp__DOT__temp7 
                                          >> 0x17U))))
                    ? (0xffffffU & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_c 
                                    >> (0xffU & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                                 - 
                                                 (vlTOPp->fexp__DOT__temp7 
                                                  >> 0x17U)))))
                    : 0U);
            vlTOPp->fexp__DOT__fma3__DOT__largerMag = 0U;
        } else {
            vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                = vlTOPp->fexp__DOT__fma3__DOT__exp_out;
            vlTOPp->fexp__DOT__fma3__DOT__largerMag 
                = (vlTOPp->fexp__DOT__fma3__DOT__mantissa_c 
                   > vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm);
        }
    }
    if (((IData)(vlTOPp->fexp__DOT__fma3__DOT__sign_out) 
         & (vlTOPp->fexp__DOT__temp7 >> 0x1fU))) {
        vlTOPp->fexp__DOT__fma3__DOT__sum_mants = (0x1ffffffU 
                                                   & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_c 
                                                      + vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm));
        vlTOPp->fexp__DOT__fma3__DOT__final_exp = (0xffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp)));
        vlTOPp->fexp__DOT__fma3__DOT__sign_out = 0U;
        vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
            = (0xffffffU & (vlTOPp->fexp__DOT__fma3__DOT__sum_mants 
                            >> 1U));
    } else {
        if (((IData)(vlTOPp->fexp__DOT__fma3__DOT__sign_out) 
             & (~ (vlTOPp->fexp__DOT__temp7 >> 0x1fU)))) {
            vlTOPp->fexp__DOT__fma3__DOT__sum_mants 
                = (0x1ffffffU & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm 
                                 - vlTOPp->fexp__DOT__fma3__DOT__mantissa_c));
            vlTOPp->fexp__DOT__fma3__DOT__sign_out 
                = vlTOPp->fexp__DOT__fma3__DOT__largerMag;
            vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                = (0xffffffU & vlTOPp->fexp__DOT__fma3__DOT__sum_mants);
            vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                = (0xffffffU & ((0x1000000U & vlTOPp->fexp__DOT__fma3__DOT__sum_mants)
                                 ? ((IData)(0xffffffffU) 
                                    * vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)
                                 : vlTOPp->fexp__DOT__fma3__DOT__final_mantissa));
        } else {
            if ((1U & ((~ (IData)(vlTOPp->fexp__DOT__fma3__DOT__sign_out)) 
                       & (vlTOPp->fexp__DOT__temp7 
                          >> 0x1fU)))) {
                vlTOPp->fexp__DOT__fma3__DOT__sum_mants 
                    = (0x1ffffffU & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_c 
                                     - vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm));
                vlTOPp->fexp__DOT__fma3__DOT__sign_out 
                    = (1U & (~ (IData)(vlTOPp->fexp__DOT__fma3__DOT__largerMag)));
                vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                    = (0xffffffU & vlTOPp->fexp__DOT__fma3__DOT__sum_mants);
                vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                    = (0xffffffU & ((0x1000000U & vlTOPp->fexp__DOT__fma3__DOT__sum_mants)
                                     ? ((IData)(0xffffffffU) 
                                        * vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)
                                     : vlTOPp->fexp__DOT__fma3__DOT__final_mantissa));
            } else {
                vlTOPp->fexp__DOT__fma3__DOT__sum_mants 
                    = (0x1ffffffU & (vlTOPp->fexp__DOT__fma3__DOT__mantissa_c 
                                     + vlTOPp->fexp__DOT__fma3__DOT__mantissa_mul_norm));
                vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp)));
                vlTOPp->fexp__DOT__fma3__DOT__sign_out = 1U;
                vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                    = (0xffffffU & (vlTOPp->fexp__DOT__fma3__DOT__sum_mants 
                                    >> 1U));
            }
        }
    }
    if ((0x800000U & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
        vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
            = (0xffffffU & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                            << 1U));
    } else {
        if ((0x400000U & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
            vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                = (0xffffffU & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                << 2U));
            vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                            - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                    = (0xffffffU & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                    << 3U));
                vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                    vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                        = (0xffffffU & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                        << 4U));
                    vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                        = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                        vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                            = (0xffffffU & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                            << 5U));
                        vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                            = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                            vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                = (0xffffffU & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                << 6U));
                            vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                                vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                    = (0xffffffU & 
                                       (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                        << 7U));
                                vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                    = (0xffU & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                                    vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                        = (0xffffffU 
                                           & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                              << 8U));
                                    vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                                        vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                            = (0xffffffU 
                                               & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                  << 9U));
                                        vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                                            vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                = (0xffffffU 
                                                   & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                      << 0xaU));
                                            vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                                                vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                        << 0xbU));
                                                vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                                                    vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                            << 0xcU));
                                                    vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                                                        vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                << 0xdU));
                                                        vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                                                            vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                    << 0xeU));
                                                            vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                                                                vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                        << 0xfU));
                                                                vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                                                                    vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                            << 0x10U));
                                                                    vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                                                                        vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                                << 0x11U));
                                                                        vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                                                                            vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                                << 0x12U));
                                                                            vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                                << 0x13U));
                                                                                vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                                << 0x14U));
                                                                                vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                                << 0x15U));
                                                                                vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                                << 0x16U));
                                                                                vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fexp__DOT__fma3__DOT__final_mantissa)) {
                                                                                vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                                                << 0x17U));
                                                                                vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fexp__DOT__fma3__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
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
    vlTOPp->out_num = ((0x80000000U & ((~ (IData)(vlTOPp->fexp__DOT__fma3__DOT__sign_out)) 
                                       << 0x1fU)) | 
                       (((IData)(vlTOPp->fexp__DOT__fma3__DOT__final_exp) 
                         << 0x17U) | (0x7fffffU & (vlTOPp->fexp__DOT__fma3__DOT__final_mantissa 
                                                   >> 1U))));
}

void Vfexp::_eval(Vfexp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfexp::_eval\n"); );
    Vfexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
}

VL_INLINE_OPT QData Vfexp::_change_request(Vfexp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfexp::_change_request\n"); );
    Vfexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vfexp::_change_request_1(Vfexp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfexp::_change_request_1\n"); );
    Vfexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vfexp::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfexp::_eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
