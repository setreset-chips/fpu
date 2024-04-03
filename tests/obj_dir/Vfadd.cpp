// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfadd.h for the primary calling header

#include "Vfadd.h"
#include "Vfadd__Syms.h"

//==========

void Vfadd::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfadd::eval\n"); );
    Vfadd__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vfadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("../fadd.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vfadd::_eval_initial_loop(Vfadd__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("../fadd.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vfadd::_combo__TOP__1(Vfadd__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd::_combo__TOP__1\n"); );
    Vfadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->fadd__DOT__finalSign = 0U;
    vlTOPp->fadd__DOT__largerMag = 0U;
    vlTOPp->fadd__DOT__num1Exp = (0xffU & (vlTOPp->num1 
                                           >> 0x17U));
    vlTOPp->fadd__DOT__num2Exp = (0xffU & (vlTOPp->num2 
                                           >> 0x17U));
    vlTOPp->fadd__DOT__leadMantBit1 = (0U != (IData)(vlTOPp->fadd__DOT__num1Exp));
    vlTOPp->fadd__DOT__leadMantBit2 = (0U != (IData)(vlTOPp->fadd__DOT__num2Exp));
    vlTOPp->fadd__DOT__num1Mant = (((IData)(vlTOPp->fadd__DOT__leadMantBit1) 
                                    << 0x17U) | (0x7fffffU 
                                                 & vlTOPp->num1));
    vlTOPp->fadd__DOT__num2Mant = (((IData)(vlTOPp->fadd__DOT__leadMantBit2) 
                                    << 0x17U) | (0x7fffffU 
                                                 & vlTOPp->num2));
    vlTOPp->fadd__DOT__subnormal = (1U & (~ ((IData)(vlTOPp->fadd__DOT__leadMantBit1) 
                                             & (IData)(vlTOPp->fadd__DOT__leadMantBit2))));
    if (((IData)(vlTOPp->fadd__DOT__num1Exp) < (IData)(vlTOPp->fadd__DOT__num2Exp))) {
        vlTOPp->fadd__DOT__finalExp = vlTOPp->fadd__DOT__num2Exp;
        vlTOPp->fadd__DOT__num1Mant = ((0x17U >= (0xffU 
                                                  & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                     - (IData)(vlTOPp->fadd__DOT__num1Exp))))
                                        ? (0xffffffU 
                                           & (vlTOPp->fadd__DOT__num1Mant 
                                              >> (0xffU 
                                                  & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                     - (IData)(vlTOPp->fadd__DOT__num1Exp)))))
                                        : 0U);
        vlTOPp->fadd__DOT__largerMag = 1U;
    } else {
        if (((IData)(vlTOPp->fadd__DOT__num2Exp) < (IData)(vlTOPp->fadd__DOT__num1Exp))) {
            vlTOPp->fadd__DOT__finalExp = vlTOPp->fadd__DOT__num1Exp;
            vlTOPp->fadd__DOT__num2Mant = ((0x17U >= 
                                            (0xffU 
                                             & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                - (IData)(vlTOPp->fadd__DOT__num2Exp))))
                                            ? (0xffffffU 
                                               & (vlTOPp->fadd__DOT__num2Mant 
                                                  >> 
                                                  (0xffU 
                                                   & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                      - (IData)(vlTOPp->fadd__DOT__num2Exp)))))
                                            : 0U);
            vlTOPp->fadd__DOT__largerMag = 0U;
        } else {
            vlTOPp->fadd__DOT__finalExp = vlTOPp->fadd__DOT__num1Exp;
            vlTOPp->fadd__DOT__largerMag = (vlTOPp->fadd__DOT__num2Mant 
                                            > vlTOPp->fadd__DOT__num1Mant);
        }
    }
    if ((0x80000000U & (vlTOPp->num1 & vlTOPp->num2))) {
        vlTOPp->fadd__DOT__sumMants = (0x1ffffffU & 
                                       (vlTOPp->fadd__DOT__num2Mant 
                                        + vlTOPp->fadd__DOT__num1Mant));
        vlTOPp->fadd__DOT__finalExp = (0xffU & ((IData)(vlTOPp->fadd__DOT__subnormal)
                                                 ? (IData)(vlTOPp->fadd__DOT__finalExp)
                                                 : 
                                                ((IData)(1U) 
                                                 + (IData)(vlTOPp->fadd__DOT__finalExp))));
        vlTOPp->fadd__DOT__finalSign = 0U;
        vlTOPp->fadd__DOT__finalMant = (0xffffffU & 
                                        (vlTOPp->fadd__DOT__sumMants 
                                         >> 1U));
    } else {
        if ((1U & ((vlTOPp->num1 >> 0x1fU) & (~ (vlTOPp->num2 
                                                 >> 0x1fU))))) {
            vlTOPp->fadd__DOT__sumMants = (0x1ffffffU 
                                           & (vlTOPp->fadd__DOT__num1Mant 
                                              - vlTOPp->fadd__DOT__num2Mant));
            vlTOPp->fadd__DOT__finalSign = vlTOPp->fadd__DOT__largerMag;
            vlTOPp->fadd__DOT__finalMant = (0xffffffU 
                                            & vlTOPp->fadd__DOT__sumMants);
            vlTOPp->fadd__DOT__finalMant = (0xffffffU 
                                            & ((0x1000000U 
                                                & vlTOPp->fadd__DOT__sumMants)
                                                ? ((IData)(0xffffffffU) 
                                                   * vlTOPp->fadd__DOT__finalMant)
                                                : vlTOPp->fadd__DOT__finalMant));
        } else {
            if ((1U & ((~ (vlTOPp->num1 >> 0x1fU)) 
                       & (vlTOPp->num2 >> 0x1fU)))) {
                vlTOPp->fadd__DOT__sumMants = (0x1ffffffU 
                                               & (vlTOPp->fadd__DOT__num2Mant 
                                                  - vlTOPp->fadd__DOT__num1Mant));
                vlTOPp->fadd__DOT__finalSign = (1U 
                                                & (~ (IData)(vlTOPp->fadd__DOT__largerMag)));
                vlTOPp->fadd__DOT__finalMant = (0xffffffU 
                                                & vlTOPp->fadd__DOT__sumMants);
                vlTOPp->fadd__DOT__finalMant = (0xffffffU 
                                                & ((0x1000000U 
                                                    & vlTOPp->fadd__DOT__sumMants)
                                                    ? 
                                                   ((IData)(0xffffffffU) 
                                                    * vlTOPp->fadd__DOT__finalMant)
                                                    : vlTOPp->fadd__DOT__finalMant));
            } else {
                vlTOPp->fadd__DOT__sumMants = (0x1ffffffU 
                                               & (vlTOPp->fadd__DOT__num2Mant 
                                                  + vlTOPp->fadd__DOT__num1Mant));
                vlTOPp->fadd__DOT__finalExp = (0xffU 
                                               & ((IData)(vlTOPp->fadd__DOT__subnormal)
                                                   ? (IData)(vlTOPp->fadd__DOT__finalExp)
                                                   : 
                                                  ((IData)(1U) 
                                                   + (IData)(vlTOPp->fadd__DOT__finalExp))));
                vlTOPp->fadd__DOT__finalSign = 1U;
                vlTOPp->fadd__DOT__finalMant = (0xffffffU 
                                                & (vlTOPp->fadd__DOT__sumMants 
                                                   >> 1U));
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->fadd__DOT__subnormal)))) {
        if ((0x800000U & vlTOPp->fadd__DOT__finalMant)) {
            vlTOPp->fadd__DOT__finalMant = (0xffffffU 
                                            & (vlTOPp->fadd__DOT__finalMant 
                                               << 1U));
        } else {
            if ((0x400000U & vlTOPp->fadd__DOT__finalMant)) {
                vlTOPp->fadd__DOT__finalMant = (0xffffffU 
                                                & (vlTOPp->fadd__DOT__finalMant 
                                                   << 2U));
                vlTOPp->fadd__DOT__finalExp = (0xffU 
                                               & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                  - (IData)(1U)));
            } else {
                if ((0x200000U & vlTOPp->fadd__DOT__finalMant)) {
                    vlTOPp->fadd__DOT__finalMant = 
                        (0xffffffU & (vlTOPp->fadd__DOT__finalMant 
                                      << 3U));
                    vlTOPp->fadd__DOT__finalExp = (0xffU 
                                                   & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                      - (IData)(2U)));
                } else {
                    if ((0x100000U & vlTOPp->fadd__DOT__finalMant)) {
                        vlTOPp->fadd__DOT__finalMant 
                            = (0xffffffU & (vlTOPp->fadd__DOT__finalMant 
                                            << 4U));
                        vlTOPp->fadd__DOT__finalExp 
                            = (0xffU & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                        - (IData)(3U)));
                    } else {
                        if ((0x80000U & vlTOPp->fadd__DOT__finalMant)) {
                            vlTOPp->fadd__DOT__finalMant 
                                = (0xffffffU & (vlTOPp->fadd__DOT__finalMant 
                                                << 5U));
                            vlTOPp->fadd__DOT__finalExp 
                                = (0xffU & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                            - (IData)(4U)));
                        } else {
                            if ((0x40000U & vlTOPp->fadd__DOT__finalMant)) {
                                vlTOPp->fadd__DOT__finalMant 
                                    = (0xffffffU & 
                                       (vlTOPp->fadd__DOT__finalMant 
                                        << 6U));
                                vlTOPp->fadd__DOT__finalExp 
                                    = (0xffU & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                - (IData)(5U)));
                            } else {
                                if ((0x20000U & vlTOPp->fadd__DOT__finalMant)) {
                                    vlTOPp->fadd__DOT__finalMant 
                                        = (0xffffffU 
                                           & (vlTOPp->fadd__DOT__finalMant 
                                              << 7U));
                                    vlTOPp->fadd__DOT__finalExp 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                            - (IData)(6U)));
                                } else {
                                    if ((0x10000U & vlTOPp->fadd__DOT__finalMant)) {
                                        vlTOPp->fadd__DOT__finalMant 
                                            = (0xffffffU 
                                               & (vlTOPp->fadd__DOT__finalMant 
                                                  << 8U));
                                        vlTOPp->fadd__DOT__finalExp 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                  - (IData)(7U)));
                                    } else {
                                        if ((0x8000U 
                                             & vlTOPp->fadd__DOT__finalMant)) {
                                            vlTOPp->fadd__DOT__finalMant 
                                                = (0xffffffU 
                                                   & (vlTOPp->fadd__DOT__finalMant 
                                                      << 9U));
                                            vlTOPp->fadd__DOT__finalExp 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                      - (IData)(8U)));
                                        } else {
                                            if ((0x4000U 
                                                 & vlTOPp->fadd__DOT__finalMant)) {
                                                vlTOPp->fadd__DOT__finalMant 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fadd__DOT__finalMant 
                                                        << 0xaU));
                                                vlTOPp->fadd__DOT__finalExp 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                        - (IData)(9U)));
                                            } else {
                                                if (
                                                    (0x2000U 
                                                     & vlTOPp->fadd__DOT__finalMant)) {
                                                    vlTOPp->fadd__DOT__finalMant 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fadd__DOT__finalMant 
                                                            << 0xbU));
                                                    vlTOPp->fadd__DOT__finalExp 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                            - (IData)(0xaU)));
                                                } else {
                                                    if (
                                                        (0x1000U 
                                                         & vlTOPp->fadd__DOT__finalMant)) {
                                                        vlTOPp->fadd__DOT__finalMant 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fadd__DOT__finalMant 
                                                                << 0xcU));
                                                        vlTOPp->fadd__DOT__finalExp 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                                - (IData)(0xbU)));
                                                    } else {
                                                        if (
                                                            (0x800U 
                                                             & vlTOPp->fadd__DOT__finalMant)) {
                                                            vlTOPp->fadd__DOT__finalMant 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fadd__DOT__finalMant 
                                                                    << 0xdU));
                                                            vlTOPp->fadd__DOT__finalExp 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                                    - (IData)(0xcU)));
                                                        } else {
                                                            if (
                                                                (0x400U 
                                                                 & vlTOPp->fadd__DOT__finalMant)) {
                                                                vlTOPp->fadd__DOT__finalMant 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fadd__DOT__finalMant 
                                                                        << 0xeU));
                                                                vlTOPp->fadd__DOT__finalExp 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                                        - (IData)(0xdU)));
                                                            } else {
                                                                if (
                                                                    (0x200U 
                                                                     & vlTOPp->fadd__DOT__finalMant)) {
                                                                    vlTOPp->fadd__DOT__finalMant 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fadd__DOT__finalMant 
                                                                            << 0xfU));
                                                                    vlTOPp->fadd__DOT__finalExp 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                                            - (IData)(0xeU)));
                                                                } else {
                                                                    if (
                                                                        (0x100U 
                                                                         & vlTOPp->fadd__DOT__finalMant)) {
                                                                        vlTOPp->fadd__DOT__finalMant 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fadd__DOT__finalMant 
                                                                                << 0x10U));
                                                                        vlTOPp->fadd__DOT__finalExp 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                                                - (IData)(0xfU)));
                                                                    } else {
                                                                        if (
                                                                            (0x80U 
                                                                             & vlTOPp->fadd__DOT__finalMant)) {
                                                                            vlTOPp->fadd__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fadd__DOT__finalMant 
                                                                                << 0x11U));
                                                                            vlTOPp->fadd__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                                                - (IData)(0x10U)));
                                                                        } else {
                                                                            if (
                                                                                (0x40U 
                                                                                & vlTOPp->fadd__DOT__finalMant)) {
                                                                                vlTOPp->fadd__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fadd__DOT__finalMant 
                                                                                << 0x12U));
                                                                                vlTOPp->fadd__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                                                - (IData)(0x11U)));
                                                                            } else {
                                                                                if (
                                                                                (0x20U 
                                                                                & vlTOPp->fadd__DOT__finalMant)) {
                                                                                vlTOPp->fadd__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fadd__DOT__finalMant 
                                                                                << 0x13U));
                                                                                vlTOPp->fadd__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                                                - (IData)(0x12U)));
                                                                                } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fadd__DOT__finalMant)) {
                                                                                vlTOPp->fadd__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fadd__DOT__finalMant 
                                                                                << 0x14U));
                                                                                vlTOPp->fadd__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fadd__DOT__finalMant)) {
                                                                                vlTOPp->fadd__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fadd__DOT__finalMant 
                                                                                << 0x15U));
                                                                                vlTOPp->fadd__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fadd__DOT__finalMant)) {
                                                                                vlTOPp->fadd__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fadd__DOT__finalMant 
                                                                                << 0x16U));
                                                                                vlTOPp->fadd__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fadd__DOT__finalMant)) {
                                                                                vlTOPp->fadd__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fadd__DOT__finalMant 
                                                                                << 0x17U));
                                                                                vlTOPp->fadd__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fadd__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fadd__DOT__finalExp) 
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
    }
    if (((0U == vlTOPp->num1) & (0U == (IData)(vlTOPp->fadd__DOT__num2Exp)))) {
        vlTOPp->fadd__DOT__finalMant = 0U;
        vlTOPp->fadd__DOT__finalExp = 0U;
    }
    VL_WRITEF("%b\n",32,((0x80000000U & ((~ (IData)(vlTOPp->fadd__DOT__finalSign)) 
                                         << 0x1fU)) 
                         | (((IData)(vlTOPp->fadd__DOT__finalExp) 
                             << 0x17U) | (0x7fffffU 
                                          & ((IData)(vlTOPp->fadd__DOT__subnormal)
                                              ? (vlTOPp->fadd__DOT__finalMant 
                                                 << 1U)
                                              : (vlTOPp->fadd__DOT__finalMant 
                                                 >> 1U))))));
    vlTOPp->fadd__DOT__unrounded = ((0x80000000U & 
                                     ((~ (IData)(vlTOPp->fadd__DOT__finalSign)) 
                                      << 0x1fU)) | 
                                    (((IData)(vlTOPp->fadd__DOT__finalExp) 
                                      << 0x17U) | (0x7fffffU 
                                                   & ((IData)(vlTOPp->fadd__DOT__subnormal)
                                                       ? 
                                                      (vlTOPp->fadd__DOT__finalMant 
                                                       << 1U)
                                                       : 
                                                      (vlTOPp->fadd__DOT__finalMant 
                                                       >> 1U)))));
    if ((0U == (IData)(vlTOPp->rm))) {
        if ((4U & vlTOPp->fadd__DOT__unrounded)) {
            if ((0U == (3U & vlTOPp->fadd__DOT__unrounded))) {
                if ((8U & vlTOPp->fadd__DOT__unrounded)) {
                    vlTOPp->fadd__DOT__r0__DOT__overflowCheck 
                        = (0x7fffffU & vlTOPp->fadd__DOT__unrounded);
                    vlTOPp->fadd__DOT__r0__DOT__overflowCheck 
                        = (0xffffffU & ((IData)(1U) 
                                        + vlTOPp->fadd__DOT__r0__DOT__overflowCheck));
                    vlTOPp->fadd__DOT__r0__DOT__rounded 
                        = ((0x800000U & vlTOPp->fadd__DOT__r0__DOT__overflowCheck)
                            ? ((0x80000000U & vlTOPp->fadd__DOT__unrounded) 
                               | ((0x7f800000U & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->fadd__DOT__unrounded 
                                                    >> 0x17U)) 
                                                  << 0x17U)) 
                                  | (0x7fffffU & vlTOPp->fadd__DOT__r0__DOT__overflowCheck)))
                            : ((0xff800000U & vlTOPp->fadd__DOT__unrounded) 
                               | (0x7fffffU & vlTOPp->fadd__DOT__r0__DOT__overflowCheck)));
                } else {
                    vlTOPp->fadd__DOT__r0__DOT__rounded 
                        = vlTOPp->fadd__DOT__unrounded;
                }
            } else {
                vlTOPp->fadd__DOT__r0__DOT__overflowCheck 
                    = (0x7fffffU & vlTOPp->fadd__DOT__unrounded);
                vlTOPp->fadd__DOT__r0__DOT__overflowCheck 
                    = (0xffffffU & ((IData)(1U) + vlTOPp->fadd__DOT__r0__DOT__overflowCheck));
                vlTOPp->fadd__DOT__r0__DOT__rounded 
                    = ((0x800000U & vlTOPp->fadd__DOT__r0__DOT__overflowCheck)
                        ? ((0x80000000U & vlTOPp->fadd__DOT__unrounded) 
                           | ((0x7f800000U & (((IData)(1U) 
                                               + (vlTOPp->fadd__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                              | (0x7fffffU & vlTOPp->fadd__DOT__r0__DOT__overflowCheck)))
                        : ((0xff800000U & vlTOPp->fadd__DOT__unrounded) 
                           | (0x7fffffU & vlTOPp->fadd__DOT__r0__DOT__overflowCheck)));
            }
        } else {
            vlTOPp->fadd__DOT__r0__DOT__rounded = vlTOPp->fadd__DOT__unrounded;
        }
    } else {
        if ((1U == (IData)(vlTOPp->rm))) {
            vlTOPp->fadd__DOT__r0__DOT__i = VL_EXTENDS_II(32,8, 
                                                          (0xffU 
                                                           & ((vlTOPp->fadd__DOT__unrounded 
                                                               >> 0x17U) 
                                                              - (IData)(0x7fU))));
            if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fadd__DOT__r0__DOT__i) 
                 & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fadd__DOT__r0__DOT__i))) {
                vlTOPp->fadd__DOT__r0__DOT__mask = 
                    ((0x16U >= vlTOPp->fadd__DOT__r0__DOT__i)
                      ? (0x7fffffU & (0x7fffffU >> vlTOPp->fadd__DOT__r0__DOT__i))
                      : 0U);
                vlTOPp->fadd__DOT__r0__DOT__mask = 
                    (0x7fffffU & (~ vlTOPp->fadd__DOT__r0__DOT__mask));
                vlTOPp->fadd__DOT__r0__DOT__rounded 
                    = ((0xff800000U & vlTOPp->fadd__DOT__unrounded) 
                       | (vlTOPp->fadd__DOT__unrounded 
                          & vlTOPp->fadd__DOT__r0__DOT__mask));
            } else {
                vlTOPp->fadd__DOT__r0__DOT__rounded 
                    = ((0U == vlTOPp->fadd__DOT__r0__DOT__i)
                        ? 0x3f800000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fadd__DOT__r0__DOT__i)
                                          ? vlTOPp->fadd__DOT__unrounded
                                          : 0U));
            }
        } else {
            if ((2U == (IData)(vlTOPp->rm))) {
                if ((0x80000000U & vlTOPp->fadd__DOT__unrounded)) {
                    vlTOPp->fadd__DOT__r0__DOT__i = 
                        VL_EXTENDS_II(32,8, (0xffU 
                                             & ((vlTOPp->fadd__DOT__unrounded 
                                                 >> 0x17U) 
                                                - (IData)(0x7fU))));
                    if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fadd__DOT__r0__DOT__i) 
                         & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fadd__DOT__r0__DOT__i))) {
                        vlTOPp->fadd__DOT__r0__DOT__mask 
                            = ((0x16U >= vlTOPp->fadd__DOT__r0__DOT__i)
                                ? (0x7fffffU & (0x7fffffU 
                                                >> vlTOPp->fadd__DOT__r0__DOT__i))
                                : 0U);
                        vlTOPp->fadd__DOT__r0__DOT__mask2 
                            = ((0x16U >= (vlTOPp->fadd__DOT__r0__DOT__i 
                                          - (IData)(1U)))
                                ? (0x7fffffU & (0x400000U 
                                                >> 
                                                (vlTOPp->fadd__DOT__r0__DOT__i 
                                                 - (IData)(1U))))
                                : 0U);
                        vlTOPp->fadd__DOT__r0__DOT__mask 
                            = (0x7fffffU & (~ vlTOPp->fadd__DOT__r0__DOT__mask));
                        vlTOPp->fadd__DOT__r0__DOT__mask 
                            = (vlTOPp->fadd__DOT__unrounded 
                               & vlTOPp->fadd__DOT__r0__DOT__mask);
                        vlTOPp->fadd__DOT__r0__DOT__overflowCheck 
                            = vlTOPp->fadd__DOT__r0__DOT__mask;
                        vlTOPp->fadd__DOT__r0__DOT__overflowCheck 
                            = (0xffffffU & (vlTOPp->fadd__DOT__r0__DOT__overflowCheck 
                                            + vlTOPp->fadd__DOT__r0__DOT__mask2));
                        vlTOPp->fadd__DOT__r0__DOT__rounded 
                            = ((0x800000U & vlTOPp->fadd__DOT__r0__DOT__overflowCheck)
                                ? ((0x80000000U & vlTOPp->fadd__DOT__unrounded) 
                                   | ((0x7f800000U 
                                       & (((IData)(1U) 
                                           + (vlTOPp->fadd__DOT__unrounded 
                                              >> 0x17U)) 
                                          << 0x17U)) 
                                      | (0x7fffffU 
                                         & vlTOPp->fadd__DOT__unrounded)))
                                : ((0xff800000U & vlTOPp->fadd__DOT__unrounded) 
                                   | (0x7fffffU & vlTOPp->fadd__DOT__r0__DOT__overflowCheck)));
                    } else {
                        vlTOPp->fadd__DOT__r0__DOT__rounded 
                            = ((0U == vlTOPp->fadd__DOT__r0__DOT__i)
                                ? 0x40000000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fadd__DOT__r0__DOT__i)
                                                  ? vlTOPp->fadd__DOT__unrounded
                                                  : 0U));
                    }
                } else {
                    vlTOPp->fadd__DOT__r0__DOT__i = 
                        VL_EXTENDS_II(32,8, (0xffU 
                                             & ((vlTOPp->fadd__DOT__unrounded 
                                                 >> 0x17U) 
                                                - (IData)(0x7fU))));
                    if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fadd__DOT__r0__DOT__i) 
                         & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fadd__DOT__r0__DOT__i))) {
                        vlTOPp->fadd__DOT__r0__DOT__mask 
                            = ((0x16U >= vlTOPp->fadd__DOT__r0__DOT__i)
                                ? (0x7fffffU & (0x7fffffU 
                                                >> vlTOPp->fadd__DOT__r0__DOT__i))
                                : 0U);
                        vlTOPp->fadd__DOT__r0__DOT__mask 
                            = (0x7fffffU & (~ vlTOPp->fadd__DOT__r0__DOT__mask));
                        vlTOPp->fadd__DOT__r0__DOT__rounded 
                            = ((0xff800000U & vlTOPp->fadd__DOT__unrounded) 
                               | (vlTOPp->fadd__DOT__unrounded 
                                  & vlTOPp->fadd__DOT__r0__DOT__mask));
                    } else {
                        vlTOPp->fadd__DOT__r0__DOT__rounded 
                            = ((0U == vlTOPp->fadd__DOT__r0__DOT__i)
                                ? 0x3f800000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fadd__DOT__r0__DOT__i)
                                                  ? vlTOPp->fadd__DOT__unrounded
                                                  : 0U));
                    }
                }
            } else {
                if ((3U == (IData)(vlTOPp->rm))) {
                    if ((0x80000000U & vlTOPp->fadd__DOT__unrounded)) {
                        vlTOPp->fadd__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fadd__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fadd__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fadd__DOT__r0__DOT__i))) {
                            vlTOPp->fadd__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fadd__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fadd__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fadd__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fadd__DOT__r0__DOT__mask));
                            vlTOPp->fadd__DOT__r0__DOT__rounded 
                                = ((0xff800000U & vlTOPp->fadd__DOT__unrounded) 
                                   | (vlTOPp->fadd__DOT__unrounded 
                                      & vlTOPp->fadd__DOT__r0__DOT__mask));
                        } else {
                            vlTOPp->fadd__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fadd__DOT__r0__DOT__i)
                                    ? 0x3f800000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fadd__DOT__r0__DOT__i)
                                     ? vlTOPp->fadd__DOT__unrounded
                                     : 0U));
                        }
                    } else {
                        vlTOPp->fadd__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fadd__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fadd__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fadd__DOT__r0__DOT__i))) {
                            vlTOPp->fadd__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fadd__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fadd__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fadd__DOT__r0__DOT__mask2 
                                = ((0x16U >= (vlTOPp->fadd__DOT__r0__DOT__i 
                                              - (IData)(1U)))
                                    ? (0x7fffffU & 
                                       (0x400000U >> 
                                        (vlTOPp->fadd__DOT__r0__DOT__i 
                                         - (IData)(1U))))
                                    : 0U);
                            vlTOPp->fadd__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fadd__DOT__r0__DOT__mask));
                            vlTOPp->fadd__DOT__r0__DOT__mask 
                                = (vlTOPp->fadd__DOT__unrounded 
                                   & vlTOPp->fadd__DOT__r0__DOT__mask);
                            vlTOPp->fadd__DOT__r0__DOT__overflowCheck 
                                = vlTOPp->fadd__DOT__r0__DOT__mask;
                            vlTOPp->fadd__DOT__r0__DOT__overflowCheck 
                                = (0xffffffU & (vlTOPp->fadd__DOT__r0__DOT__overflowCheck 
                                                + vlTOPp->fadd__DOT__r0__DOT__mask2));
                            vlTOPp->fadd__DOT__r0__DOT__rounded 
                                = ((0x800000U & vlTOPp->fadd__DOT__r0__DOT__overflowCheck)
                                    ? ((0x80000000U 
                                        & vlTOPp->fadd__DOT__unrounded) 
                                       | ((0x7f800000U 
                                           & (((IData)(1U) 
                                               + (vlTOPp->fadd__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                                          | (0x7fffffU 
                                             & vlTOPp->fadd__DOT__unrounded)))
                                    : ((0xff800000U 
                                        & vlTOPp->fadd__DOT__unrounded) 
                                       | (0x7fffffU 
                                          & vlTOPp->fadd__DOT__r0__DOT__overflowCheck)));
                        } else {
                            vlTOPp->fadd__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fadd__DOT__r0__DOT__i)
                                    ? 0x40000000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fadd__DOT__r0__DOT__i)
                                     ? vlTOPp->fadd__DOT__unrounded
                                     : 0U));
                        }
                    }
                } else {
                    if ((4U == (IData)(vlTOPp->rm))) {
                        vlTOPp->fadd__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fadd__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fadd__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fadd__DOT__r0__DOT__i))) {
                            vlTOPp->fadd__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fadd__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fadd__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fadd__DOT__r0__DOT__mask2 
                                = ((0x16U >= (vlTOPp->fadd__DOT__r0__DOT__i 
                                              - (IData)(1U)))
                                    ? (0x7fffffU & 
                                       (0x400000U >> 
                                        (vlTOPp->fadd__DOT__r0__DOT__i 
                                         - (IData)(1U))))
                                    : 0U);
                            vlTOPp->fadd__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fadd__DOT__r0__DOT__mask));
                            vlTOPp->fadd__DOT__r0__DOT__mask 
                                = (vlTOPp->fadd__DOT__unrounded 
                                   & vlTOPp->fadd__DOT__r0__DOT__mask);
                            vlTOPp->fadd__DOT__r0__DOT__overflowCheck 
                                = vlTOPp->fadd__DOT__r0__DOT__mask;
                            vlTOPp->fadd__DOT__r0__DOT__overflowCheck 
                                = (0xffffffU & (vlTOPp->fadd__DOT__r0__DOT__overflowCheck 
                                                + vlTOPp->fadd__DOT__r0__DOT__mask2));
                            vlTOPp->fadd__DOT__r0__DOT__rounded 
                                = ((0x800000U & vlTOPp->fadd__DOT__r0__DOT__overflowCheck)
                                    ? ((0x80000000U 
                                        & vlTOPp->fadd__DOT__unrounded) 
                                       | ((0x7f800000U 
                                           & (((IData)(1U) 
                                               + (vlTOPp->fadd__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                                          | (0x7fffffU 
                                             & vlTOPp->fadd__DOT__unrounded)))
                                    : ((0xff800000U 
                                        & vlTOPp->fadd__DOT__unrounded) 
                                       | (0x7fffffU 
                                          & vlTOPp->fadd__DOT__r0__DOT__overflowCheck)));
                        } else {
                            vlTOPp->fadd__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fadd__DOT__r0__DOT__i)
                                    ? 0x40000000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fadd__DOT__r0__DOT__i)
                                     ? vlTOPp->fadd__DOT__unrounded
                                     : 0U));
                        }
                    } else {
                        if ((4U & vlTOPp->fadd__DOT__unrounded)) {
                            if ((0U == (3U & vlTOPp->fadd__DOT__unrounded))) {
                                if ((8U & vlTOPp->fadd__DOT__unrounded)) {
                                    vlTOPp->fadd__DOT__r0__DOT__overflowCheck 
                                        = (0x7fffffU 
                                           & vlTOPp->fadd__DOT__unrounded);
                                    vlTOPp->fadd__DOT__r0__DOT__overflowCheck 
                                        = (0xffffffU 
                                           & ((IData)(1U) 
                                              + vlTOPp->fadd__DOT__r0__DOT__overflowCheck));
                                    vlTOPp->fadd__DOT__r0__DOT__rounded 
                                        = ((0x800000U 
                                            & vlTOPp->fadd__DOT__r0__DOT__overflowCheck)
                                            ? ((0x80000000U 
                                                & vlTOPp->fadd__DOT__unrounded) 
                                               | ((0x7f800000U 
                                                   & (((IData)(1U) 
                                                       + 
                                                       (vlTOPp->fadd__DOT__unrounded 
                                                        >> 0x17U)) 
                                                      << 0x17U)) 
                                                  | (0x7fffffU 
                                                     & vlTOPp->fadd__DOT__r0__DOT__overflowCheck)))
                                            : ((0xff800000U 
                                                & vlTOPp->fadd__DOT__unrounded) 
                                               | (0x7fffffU 
                                                  & vlTOPp->fadd__DOT__r0__DOT__overflowCheck)));
                                } else {
                                    vlTOPp->fadd__DOT__r0__DOT__rounded 
                                        = vlTOPp->fadd__DOT__unrounded;
                                }
                            } else {
                                vlTOPp->fadd__DOT__r0__DOT__overflowCheck 
                                    = (0x7fffffU & vlTOPp->fadd__DOT__unrounded);
                                vlTOPp->fadd__DOT__r0__DOT__overflowCheck 
                                    = (0xffffffU & 
                                       ((IData)(1U) 
                                        + vlTOPp->fadd__DOT__r0__DOT__overflowCheck));
                                vlTOPp->fadd__DOT__r0__DOT__rounded 
                                    = ((0x800000U & vlTOPp->fadd__DOT__r0__DOT__overflowCheck)
                                        ? ((0x80000000U 
                                            & vlTOPp->fadd__DOT__unrounded) 
                                           | ((0x7f800000U 
                                               & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->fadd__DOT__unrounded 
                                                    >> 0x17U)) 
                                                  << 0x17U)) 
                                              | (0x7fffffU 
                                                 & vlTOPp->fadd__DOT__r0__DOT__overflowCheck)))
                                        : ((0xff800000U 
                                            & vlTOPp->fadd__DOT__unrounded) 
                                           | (0x7fffffU 
                                              & vlTOPp->fadd__DOT__r0__DOT__overflowCheck)));
                            }
                        } else {
                            vlTOPp->fadd__DOT__r0__DOT__rounded 
                                = vlTOPp->fadd__DOT__unrounded;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->out_num = vlTOPp->fadd__DOT__r0__DOT__rounded;
}

void Vfadd::_eval(Vfadd__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd::_eval\n"); );
    Vfadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
}

VL_INLINE_OPT QData Vfadd::_change_request(Vfadd__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd::_change_request\n"); );
    Vfadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vfadd::_change_request_1(Vfadd__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd::_change_request_1\n"); );
    Vfadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vfadd::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((rm & 0xf8U))) {
        Verilated::overWidthError("rm");}
}
#endif  // VL_DEBUG
