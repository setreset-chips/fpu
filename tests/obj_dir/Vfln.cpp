// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfln.h for the primary calling header

#include "Vfln.h"
#include "Vfln__Syms.h"

//==========

void Vfln::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfln::eval\n"); );
    Vfln__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("../fln.sv", 2, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vfln::_eval_initial_loop(Vfln__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("../fln.sv", 2, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vfln::_combo__TOP__1(Vfln__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfln::_combo__TOP__1\n"); );
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->fln__DOT__fa0__DOT__finalSign = 0U;
    vlTOPp->fln__DOT__fa0__DOT__largerMag = 0U;
    vlTOPp->fln__DOT__fa0__DOT__num1Exp = (0xffU & 
                                           (vlTOPp->num1 
                                            >> 0x17U));
    vlTOPp->fln__DOT__fa0__DOT__num2Exp = 0x7fU;
    vlTOPp->fln__DOT__fa0__DOT__num1Mant = (0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->num1));
    vlTOPp->fln__DOT__fa0__DOT__num2Mant = 0x800000U;
    if ((0x7fU > (IData)(vlTOPp->fln__DOT__fa0__DOT__num1Exp))) {
        vlTOPp->fln__DOT__fa0__DOT__finalExp = vlTOPp->fln__DOT__fa0__DOT__num2Exp;
        vlTOPp->fln__DOT__fa0__DOT__num1Mant = ((0x17U 
                                                 >= 
                                                 (0xffU 
                                                  & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                     - (IData)(vlTOPp->fln__DOT__fa0__DOT__num1Exp))))
                                                 ? 
                                                (0xffffffU 
                                                 & (vlTOPp->fln__DOT__fa0__DOT__num1Mant 
                                                    >> 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                        - (IData)(vlTOPp->fln__DOT__fa0__DOT__num1Exp)))))
                                                 : 0U);
        vlTOPp->fln__DOT__fa0__DOT__largerMag = 1U;
    } else {
        if (((IData)(vlTOPp->fln__DOT__fa0__DOT__num2Exp) 
             < (IData)(vlTOPp->fln__DOT__fa0__DOT__num1Exp))) {
            vlTOPp->fln__DOT__fa0__DOT__finalExp = vlTOPp->fln__DOT__fa0__DOT__num1Exp;
            vlTOPp->fln__DOT__fa0__DOT__num2Mant = 
                ((0x17U >= (0xffU & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                     - (IData)(vlTOPp->fln__DOT__fa0__DOT__num2Exp))))
                  ? (0xffffffU & (vlTOPp->fln__DOT__fa0__DOT__num2Mant 
                                  >> (0xffU & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                               - (IData)(vlTOPp->fln__DOT__fa0__DOT__num2Exp)))))
                  : 0U);
            vlTOPp->fln__DOT__fa0__DOT__largerMag = 0U;
        } else {
            vlTOPp->fln__DOT__fa0__DOT__finalExp = vlTOPp->fln__DOT__fa0__DOT__num1Exp;
            vlTOPp->fln__DOT__fa0__DOT__largerMag = 
                (vlTOPp->fln__DOT__fa0__DOT__num2Mant 
                 > vlTOPp->fln__DOT__fa0__DOT__num1Mant);
        }
    }
    vlTOPp->fln__DOT__fa0__DOT__sumMants = (0x1ffffffU 
                                            & (vlTOPp->fln__DOT__fa0__DOT__num2Mant 
                                               - vlTOPp->fln__DOT__fa0__DOT__num1Mant));
    vlTOPp->fln__DOT__fa0__DOT__finalSign = (1U & (~ (IData)(vlTOPp->fln__DOT__fa0__DOT__largerMag)));
    vlTOPp->fln__DOT__fa0__DOT__finalMant = (0xffffffU 
                                             & vlTOPp->fln__DOT__fa0__DOT__sumMants);
    vlTOPp->fln__DOT__fa0__DOT__finalMant = (0xffffffU 
                                             & ((0x1000000U 
                                                 & vlTOPp->fln__DOT__fa0__DOT__sumMants)
                                                 ? 
                                                ((IData)(0xffffffffU) 
                                                 * vlTOPp->fln__DOT__fa0__DOT__finalMant)
                                                 : vlTOPp->fln__DOT__fa0__DOT__finalMant));
    if ((0x800000U & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
        vlTOPp->fln__DOT__fa0__DOT__finalMant = (0xffffffU 
                                                 & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                    << 1U));
    } else {
        if ((0x400000U & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
            vlTOPp->fln__DOT__fa0__DOT__finalMant = 
                (0xffffffU & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                              << 2U));
            vlTOPp->fln__DOT__fa0__DOT__finalExp = 
                (0xffU & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                          - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                vlTOPp->fln__DOT__fa0__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                    << 3U));
                vlTOPp->fln__DOT__fa0__DOT__finalExp 
                    = (0xffU & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                    vlTOPp->fln__DOT__fa0__DOT__finalMant 
                        = (0xffffffU & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                        << 4U));
                    vlTOPp->fln__DOT__fa0__DOT__finalExp 
                        = (0xffU & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                        vlTOPp->fln__DOT__fa0__DOT__finalMant 
                            = (0xffffffU & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                            << 5U));
                        vlTOPp->fln__DOT__fa0__DOT__finalExp 
                            = (0xffU & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                            vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                = (0xffffffU & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                << 6U));
                            vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                = (0xffU & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                                vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                    = (0xffffffU & 
                                       (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                        << 7U));
                                vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                    = (0xffU & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                                    vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                        = (0xffffffU 
                                           & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                              << 8U));
                                    vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                                        vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                            = (0xffffffU 
                                               & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                  << 9U));
                                        vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                                            vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                = (0xffffffU 
                                                   & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                      << 0xaU));
                                            vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                                                vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                        << 0xbU));
                                                vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                                                    vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                            << 0xcU));
                                                    vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                                                        vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                << 0xdU));
                                                        vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                                                            vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                    << 0xeU));
                                                            vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                                                                vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                        << 0xfU));
                                                                vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                                                                    vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                            << 0x10U));
                                                                    vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                                                                        vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                                << 0x11U));
                                                                        vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                                                                            vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                                << 0x12U));
                                                                            vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                                                                                vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                                << 0x13U));
                                                                                vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                                                                                vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                                << 0x14U));
                                                                                vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                                                                                vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                                << 0x15U));
                                                                                vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                                                                                vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                                << 0x16U));
                                                                                vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
                                                                                vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                                                << 0x17U));
                                                                                vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fln__DOT__fa0__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
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
    if (((0U == (0x7fffffffU & vlTOPp->num1)) & (0U 
                                                 == (IData)(vlTOPp->fln__DOT__fa0__DOT__num2Exp)))) {
        vlTOPp->fln__DOT__fa0__DOT__finalMant = 0U;
        vlTOPp->fln__DOT__fa0__DOT__finalExp = 0U;
    }
    vlTOPp->fln__DOT__fa0__DOT__unrounded = ((0x80000000U 
                                              & ((~ (IData)(vlTOPp->fln__DOT__fa0__DOT__finalSign)) 
                                                 << 0x1fU)) 
                                             | (((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                 << 0x17U) 
                                                | (0x7fffffU 
                                                   & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                      >> 1U))));
    if ((4U & vlTOPp->fln__DOT__fa0__DOT__unrounded)) {
        if ((0U == (3U & vlTOPp->fln__DOT__fa0__DOT__unrounded))) {
            if ((8U & vlTOPp->fln__DOT__fa0__DOT__unrounded)) {
                vlTOPp->fln__DOT__fa0__DOT__r0__DOT__overflowCheck 
                    = (0x7fffffU & vlTOPp->fln__DOT__fa0__DOT__unrounded);
                vlTOPp->fln__DOT__fa0__DOT__r0__DOT__overflowCheck 
                    = (0xffffffU & ((IData)(1U) + vlTOPp->fln__DOT__fa0__DOT__r0__DOT__overflowCheck));
                vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded 
                    = ((0x800000U & vlTOPp->fln__DOT__fa0__DOT__r0__DOT__overflowCheck)
                        ? ((0x80000000U & vlTOPp->fln__DOT__fa0__DOT__unrounded) 
                           | ((0x7f800000U & (((IData)(1U) 
                                               + (vlTOPp->fln__DOT__fa0__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                              | (0x7fffffU & vlTOPp->fln__DOT__fa0__DOT__r0__DOT__overflowCheck)))
                        : ((0xff800000U & vlTOPp->fln__DOT__fa0__DOT__unrounded) 
                           | (0x7fffffU & vlTOPp->fln__DOT__fa0__DOT__r0__DOT__overflowCheck)));
            } else {
                vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded 
                    = vlTOPp->fln__DOT__fa0__DOT__unrounded;
            }
        } else {
            vlTOPp->fln__DOT__fa0__DOT__r0__DOT__overflowCheck 
                = (0x7fffffU & vlTOPp->fln__DOT__fa0__DOT__unrounded);
            vlTOPp->fln__DOT__fa0__DOT__r0__DOT__overflowCheck 
                = (0xffffffU & ((IData)(1U) + vlTOPp->fln__DOT__fa0__DOT__r0__DOT__overflowCheck));
            vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded 
                = ((0x800000U & vlTOPp->fln__DOT__fa0__DOT__r0__DOT__overflowCheck)
                    ? ((0x80000000U & vlTOPp->fln__DOT__fa0__DOT__unrounded) 
                       | ((0x7f800000U & (((IData)(1U) 
                                           + (vlTOPp->fln__DOT__fa0__DOT__unrounded 
                                              >> 0x17U)) 
                                          << 0x17U)) 
                          | (0x7fffffU & vlTOPp->fln__DOT__fa0__DOT__r0__DOT__overflowCheck)))
                    : ((0xff800000U & vlTOPp->fln__DOT__fa0__DOT__unrounded) 
                       | (0x7fffffU & vlTOPp->fln__DOT__fa0__DOT__r0__DOT__overflowCheck)));
        }
    } else {
        vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded 
            = vlTOPp->fln__DOT__fa0__DOT__unrounded;
    }
}

VL_INLINE_OPT void Vfln::_combo__TOP__2(Vfln__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfln::_combo__TOP__2\n"); );
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->fln__DOT__fma1__DOT__mantissa_a = ((0U 
                                                == vlSymsp->TOP__fln__DOT__fm4.__PVT__r0__DOT__rounded)
                                                ? 0U
                                                : (0x800000U 
                                                   | (0x7fffffU 
                                                      & vlSymsp->TOP__fln__DOT__fm4.__PVT__r0__DOT__rounded)));
    vlTOPp->fln__DOT__fma1__DOT__mantissa_c = ((0U 
                                                == vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__rounded)
                                                ? 0U
                                                : (0x800000U 
                                                   | (0x7fffffU 
                                                      & vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__rounded)));
    vlTOPp->fln__DOT__fma1__DOT__sign_out = (1U & (~ 
                                                   (vlSymsp->TOP__fln__DOT__fm4.__PVT__r0__DOT__rounded 
                                                    >> 0x1fU)));
    vlTOPp->fln__DOT__fma1__DOT__exp_out = (0xffU & 
                                            ((IData)(0xfeU) 
                                             + (vlSymsp->TOP__fln__DOT__fm4.__PVT__r0__DOT__rounded 
                                                >> 0x17U)));
    vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_out = 
        (0xffffffffffffULL & ((QData)((IData)(vlTOPp->fln__DOT__fma1__DOT__mantissa_a)) 
                              << 0x17U));
    vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
        = (0xffffffU & (IData)((vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_out 
                                >> 0x18U)));
    if ((0x800000U & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
        vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
            = (0xffffffU & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                            << 1U));
    } else {
        if ((0x400000U & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
            vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                = (0xffffffU & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                << 2U));
            vlTOPp->fln__DOT__fma1__DOT__exp_out = 
                (0xffU & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                          - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                    = (0xffffffU & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                    << 3U));
                vlTOPp->fln__DOT__fma1__DOT__exp_out 
                    = (0xffU & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                    vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                        = (0xffffffU & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                        << 4U));
                    vlTOPp->fln__DOT__fma1__DOT__exp_out 
                        = (0xffU & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                        vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                            = (0xffffffU & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                            << 5U));
                        vlTOPp->fln__DOT__fma1__DOT__exp_out 
                            = (0xffU & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                            vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                = (0xffffffU & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                << 6U));
                            vlTOPp->fln__DOT__fma1__DOT__exp_out 
                                = (0xffU & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                                vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                    = (0xffffffU & 
                                       (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                        << 7U));
                                vlTOPp->fln__DOT__fma1__DOT__exp_out 
                                    = (0xffU & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                                    vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                        = (0xffffffU 
                                           & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                              << 8U));
                                    vlTOPp->fln__DOT__fma1__DOT__exp_out 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                                        vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                            = (0xffffffU 
                                               & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                  << 9U));
                                        vlTOPp->fln__DOT__fma1__DOT__exp_out 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                                            vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                = (0xffffffU 
                                                   & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                      << 0xaU));
                                            vlTOPp->fln__DOT__fma1__DOT__exp_out 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                        << 0xbU));
                                                vlTOPp->fln__DOT__fma1__DOT__exp_out 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                    vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                            << 0xcU));
                                                    vlTOPp->fln__DOT__fma1__DOT__exp_out 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                        vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                << 0xdU));
                                                        vlTOPp->fln__DOT__fma1__DOT__exp_out 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                            vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                    << 0xeU));
                                                            vlTOPp->fln__DOT__fma1__DOT__exp_out 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                                vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                        << 0xfU));
                                                                vlTOPp->fln__DOT__fma1__DOT__exp_out 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                                    vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                            << 0x10U));
                                                                    vlTOPp->fln__DOT__fma1__DOT__exp_out 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                                        vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                << 0x11U));
                                                                        vlTOPp->fln__DOT__fma1__DOT__exp_out 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                                            vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                << 0x12U));
                                                                            vlTOPp->fln__DOT__fma1__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                << 0x13U));
                                                                                vlTOPp->fln__DOT__fma1__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                << 0x14U));
                                                                                vlTOPp->fln__DOT__fma1__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                << 0x15U));
                                                                                vlTOPp->fln__DOT__fma1__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                << 0x16U));
                                                                                vlTOPp->fln__DOT__fma1__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                                                                << 0x17U));
                                                                                vlTOPp->fln__DOT__fma1__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fln__DOT__fma1__DOT__exp_out = 0xffU;
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
    vlTOPp->fln__DOT__fma1__DOT__exp_out = (0xffU & 
                                            ((IData)(1U) 
                                             + (IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out)));
    vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
        = ((0U == vlSymsp->TOP__fln__DOT__fm4.__PVT__r0__DOT__rounded)
            ? 0U : (0x800000U | (0x7fffffU & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                              >> 1U))));
    if (((IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out) 
         < (0xffU & (vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__rounded 
                     >> 0x17U)))) {
        vlTOPp->fln__DOT__fma1__DOT__final_exp = (0xffU 
                                                  & (vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__rounded 
                                                     >> 0x17U));
        vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
            = ((0x17U >= (0xffU & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                   - (IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out))))
                ? (0xffffffU & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                >> (0xffU & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                             - (IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out)))))
                : 0U);
        vlTOPp->fln__DOT__fma1__DOT__largerMag = 1U;
    } else {
        if (((0xffU & (vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__rounded 
                       >> 0x17U)) < (IData)(vlTOPp->fln__DOT__fma1__DOT__exp_out))) {
            vlTOPp->fln__DOT__fma1__DOT__final_exp 
                = vlTOPp->fln__DOT__fma1__DOT__exp_out;
            vlTOPp->fln__DOT__fma1__DOT__mantissa_c 
                = ((0x17U >= (0xffU & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                       - (vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__rounded 
                                          >> 0x17U))))
                    ? (0xffffffU & (vlTOPp->fln__DOT__fma1__DOT__mantissa_c 
                                    >> (0xffU & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                                 - 
                                                 (vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__rounded 
                                                  >> 0x17U)))))
                    : 0U);
            vlTOPp->fln__DOT__fma1__DOT__largerMag = 0U;
        } else {
            vlTOPp->fln__DOT__fma1__DOT__final_exp 
                = vlTOPp->fln__DOT__fma1__DOT__exp_out;
            vlTOPp->fln__DOT__fma1__DOT__largerMag 
                = (vlTOPp->fln__DOT__fma1__DOT__mantissa_c 
                   > vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm);
        }
    }
    if (((IData)(vlTOPp->fln__DOT__fma1__DOT__sign_out) 
         & (vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__rounded 
            >> 0x1fU))) {
        vlTOPp->fln__DOT__fma1__DOT__sum_mants = (0x1ffffffU 
                                                  & (vlTOPp->fln__DOT__fma1__DOT__mantissa_c 
                                                     + vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm));
        vlTOPp->fln__DOT__fma1__DOT__final_exp = (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp)));
        vlTOPp->fln__DOT__fma1__DOT__sign_out = 0U;
        vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
            = (0xffffffU & (vlTOPp->fln__DOT__fma1__DOT__sum_mants 
                            >> 1U));
    } else {
        if (((IData)(vlTOPp->fln__DOT__fma1__DOT__sign_out) 
             & (~ (vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__rounded 
                   >> 0x1fU)))) {
            vlTOPp->fln__DOT__fma1__DOT__sum_mants 
                = (0x1ffffffU & (vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm 
                                 - vlTOPp->fln__DOT__fma1__DOT__mantissa_c));
            vlTOPp->fln__DOT__fma1__DOT__sign_out = vlTOPp->fln__DOT__fma1__DOT__largerMag;
            vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                = (0xffffffU & vlTOPp->fln__DOT__fma1__DOT__sum_mants);
            vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                = (0xffffffU & ((0x1000000U & vlTOPp->fln__DOT__fma1__DOT__sum_mants)
                                 ? ((IData)(0xffffffffU) 
                                    * vlTOPp->fln__DOT__fma1__DOT__final_mantissa)
                                 : vlTOPp->fln__DOT__fma1__DOT__final_mantissa));
        } else {
            if ((1U & ((~ (IData)(vlTOPp->fln__DOT__fma1__DOT__sign_out)) 
                       & (vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__rounded 
                          >> 0x1fU)))) {
                vlTOPp->fln__DOT__fma1__DOT__sum_mants 
                    = (0x1ffffffU & (vlTOPp->fln__DOT__fma1__DOT__mantissa_c 
                                     - vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm));
                vlTOPp->fln__DOT__fma1__DOT__sign_out 
                    = (1U & (~ (IData)(vlTOPp->fln__DOT__fma1__DOT__largerMag)));
                vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                    = (0xffffffU & vlTOPp->fln__DOT__fma1__DOT__sum_mants);
                vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                    = (0xffffffU & ((0x1000000U & vlTOPp->fln__DOT__fma1__DOT__sum_mants)
                                     ? ((IData)(0xffffffffU) 
                                        * vlTOPp->fln__DOT__fma1__DOT__final_mantissa)
                                     : vlTOPp->fln__DOT__fma1__DOT__final_mantissa));
            } else {
                vlTOPp->fln__DOT__fma1__DOT__sum_mants 
                    = (0x1ffffffU & (vlTOPp->fln__DOT__fma1__DOT__mantissa_c 
                                     + vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm));
                vlTOPp->fln__DOT__fma1__DOT__final_exp 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp)));
                vlTOPp->fln__DOT__fma1__DOT__sign_out = 1U;
                vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                    = (0xffffffU & (vlTOPp->fln__DOT__fma1__DOT__sum_mants 
                                    >> 1U));
            }
        }
    }
    if ((0x800000U & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
        vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
            = (0xffffffU & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                            << 1U));
    } else {
        if ((0x400000U & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
            vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                = (0xffffffU & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                << 2U));
            vlTOPp->fln__DOT__fma1__DOT__final_exp 
                = (0xffU & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                            - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                    = (0xffffffU & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                    << 3U));
                vlTOPp->fln__DOT__fma1__DOT__final_exp 
                    = (0xffU & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                    vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                        = (0xffffffU & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                        << 4U));
                    vlTOPp->fln__DOT__fma1__DOT__final_exp 
                        = (0xffU & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                        vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                            = (0xffffffU & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                            << 5U));
                        vlTOPp->fln__DOT__fma1__DOT__final_exp 
                            = (0xffU & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                            vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                = (0xffffffU & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                << 6U));
                            vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                = (0xffU & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                                vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                    = (0xffffffU & 
                                       (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                        << 7U));
                                vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                    = (0xffU & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                                    vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                        = (0xffffffU 
                                           & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                              << 8U));
                                    vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                                        vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                            = (0xffffffU 
                                               & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                  << 9U));
                                        vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                                            vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                = (0xffffffU 
                                                   & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                      << 0xaU));
                                            vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                                                vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                        << 0xbU));
                                                vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                                                    vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                            << 0xcU));
                                                    vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                                                        vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                << 0xdU));
                                                        vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                                                            vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                    << 0xeU));
                                                            vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                                                                vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                        << 0xfU));
                                                                vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                                                                    vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                            << 0x10U));
                                                                    vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                                                                        vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                                << 0x11U));
                                                                        vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                                                                            vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                                << 0x12U));
                                                                            vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                                                                                vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                                << 0x13U));
                                                                                vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                                                                                vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                                << 0x14U));
                                                                                vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                                                                                vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                                << 0x15U));
                                                                                vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                                                                                vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                                << 0x16U));
                                                                                vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fln__DOT__fma1__DOT__final_mantissa)) {
                                                                                vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                                                << 0x17U));
                                                                                vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fln__DOT__fma1__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
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
    vlTOPp->fln__DOT__temp6 = ((0x80000000U & ((~ (IData)(vlTOPp->fln__DOT__fma1__DOT__sign_out)) 
                                               << 0x1fU)) 
                               | (((IData)(vlTOPp->fln__DOT__fma1__DOT__final_exp) 
                                   << 0x17U) | (0x7fffffU 
                                                & (vlTOPp->fln__DOT__fma1__DOT__final_mantissa 
                                                   >> 1U))));
    vlTOPp->fln__DOT__fa1__DOT__finalSign = 0U;
    vlTOPp->fln__DOT__fa1__DOT__largerMag = 0U;
    vlTOPp->fln__DOT__fa1__DOT__num1Exp = (0xffU & 
                                           (vlTOPp->fln__DOT__temp6 
                                            >> 0x17U));
    vlTOPp->fln__DOT__fa1__DOT__num2Exp = (0xffU & 
                                           (vlSymsp->TOP__fln__DOT__fm1.__PVT__r0__DOT__rounded 
                                            >> 0x17U));
    vlTOPp->fln__DOT__fa1__DOT__num1Mant = (0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->fln__DOT__temp6));
    vlTOPp->fln__DOT__fa1__DOT__num2Mant = (0x800000U 
                                            | (0x7fffffU 
                                               & vlSymsp->TOP__fln__DOT__fm1.__PVT__r0__DOT__rounded));
    if (((IData)(vlTOPp->fln__DOT__fa1__DOT__num1Exp) 
         < (IData)(vlTOPp->fln__DOT__fa1__DOT__num2Exp))) {
        vlTOPp->fln__DOT__fa1__DOT__finalExp = vlTOPp->fln__DOT__fa1__DOT__num2Exp;
        vlTOPp->fln__DOT__fa1__DOT__num1Mant = ((0x17U 
                                                 >= 
                                                 (0xffU 
                                                  & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                     - (IData)(vlTOPp->fln__DOT__fa1__DOT__num1Exp))))
                                                 ? 
                                                (0xffffffU 
                                                 & (vlTOPp->fln__DOT__fa1__DOT__num1Mant 
                                                    >> 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                        - (IData)(vlTOPp->fln__DOT__fa1__DOT__num1Exp)))))
                                                 : 0U);
        vlTOPp->fln__DOT__fa1__DOT__largerMag = 1U;
    } else {
        if (((IData)(vlTOPp->fln__DOT__fa1__DOT__num2Exp) 
             < (IData)(vlTOPp->fln__DOT__fa1__DOT__num1Exp))) {
            vlTOPp->fln__DOT__fa1__DOT__finalExp = vlTOPp->fln__DOT__fa1__DOT__num1Exp;
            vlTOPp->fln__DOT__fa1__DOT__num2Mant = 
                ((0x17U >= (0xffU & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                     - (IData)(vlTOPp->fln__DOT__fa1__DOT__num2Exp))))
                  ? (0xffffffU & (vlTOPp->fln__DOT__fa1__DOT__num2Mant 
                                  >> (0xffU & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                               - (IData)(vlTOPp->fln__DOT__fa1__DOT__num2Exp)))))
                  : 0U);
            vlTOPp->fln__DOT__fa1__DOT__largerMag = 0U;
        } else {
            vlTOPp->fln__DOT__fa1__DOT__finalExp = vlTOPp->fln__DOT__fa1__DOT__num1Exp;
            vlTOPp->fln__DOT__fa1__DOT__largerMag = 
                (vlTOPp->fln__DOT__fa1__DOT__num2Mant 
                 > vlTOPp->fln__DOT__fa1__DOT__num1Mant);
        }
    }
    if ((0x80000000U & (vlTOPp->fln__DOT__temp6 & vlSymsp->TOP__fln__DOT__fm1.__PVT__r0__DOT__rounded))) {
        vlTOPp->fln__DOT__fa1__DOT__sumMants = (0x1ffffffU 
                                                & (vlTOPp->fln__DOT__fa1__DOT__num2Mant 
                                                   + vlTOPp->fln__DOT__fa1__DOT__num1Mant));
        vlTOPp->fln__DOT__fa1__DOT__finalExp = (0xffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp)));
        vlTOPp->fln__DOT__fa1__DOT__finalSign = 0U;
        vlTOPp->fln__DOT__fa1__DOT__finalMant = (0xffffffU 
                                                 & (vlTOPp->fln__DOT__fa1__DOT__sumMants 
                                                    >> 1U));
    } else {
        if ((1U & ((vlTOPp->fln__DOT__temp6 >> 0x1fU) 
                   & (~ (vlSymsp->TOP__fln__DOT__fm1.__PVT__r0__DOT__rounded 
                         >> 0x1fU))))) {
            vlTOPp->fln__DOT__fa1__DOT__sumMants = 
                (0x1ffffffU & (vlTOPp->fln__DOT__fa1__DOT__num1Mant 
                               - vlTOPp->fln__DOT__fa1__DOT__num2Mant));
            vlTOPp->fln__DOT__fa1__DOT__finalSign = vlTOPp->fln__DOT__fa1__DOT__largerMag;
            vlTOPp->fln__DOT__fa1__DOT__finalMant = 
                (0xffffffU & vlTOPp->fln__DOT__fa1__DOT__sumMants);
            vlTOPp->fln__DOT__fa1__DOT__finalMant = 
                (0xffffffU & ((0x1000000U & vlTOPp->fln__DOT__fa1__DOT__sumMants)
                               ? ((IData)(0xffffffffU) 
                                  * vlTOPp->fln__DOT__fa1__DOT__finalMant)
                               : vlTOPp->fln__DOT__fa1__DOT__finalMant));
        } else {
            if ((1U & ((~ (vlTOPp->fln__DOT__temp6 
                           >> 0x1fU)) & (vlSymsp->TOP__fln__DOT__fm1.__PVT__r0__DOT__rounded 
                                         >> 0x1fU)))) {
                vlTOPp->fln__DOT__fa1__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fln__DOT__fa1__DOT__num2Mant 
                                     - vlTOPp->fln__DOT__fa1__DOT__num1Mant));
                vlTOPp->fln__DOT__fa1__DOT__finalSign 
                    = (1U & (~ (IData)(vlTOPp->fln__DOT__fa1__DOT__largerMag)));
                vlTOPp->fln__DOT__fa1__DOT__finalMant 
                    = (0xffffffU & vlTOPp->fln__DOT__fa1__DOT__sumMants);
                vlTOPp->fln__DOT__fa1__DOT__finalMant 
                    = (0xffffffU & ((0x1000000U & vlTOPp->fln__DOT__fa1__DOT__sumMants)
                                     ? ((IData)(0xffffffffU) 
                                        * vlTOPp->fln__DOT__fa1__DOT__finalMant)
                                     : vlTOPp->fln__DOT__fa1__DOT__finalMant));
            } else {
                vlTOPp->fln__DOT__fa1__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fln__DOT__fa1__DOT__num2Mant 
                                     + vlTOPp->fln__DOT__fa1__DOT__num1Mant));
                vlTOPp->fln__DOT__fa1__DOT__finalExp 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp)));
                vlTOPp->fln__DOT__fa1__DOT__finalSign = 1U;
                vlTOPp->fln__DOT__fa1__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fln__DOT__fa1__DOT__sumMants 
                                    >> 1U));
            }
        }
    }
    if ((0x800000U & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
        vlTOPp->fln__DOT__fa1__DOT__finalMant = (0xffffffU 
                                                 & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                    << 1U));
    } else {
        if ((0x400000U & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
            vlTOPp->fln__DOT__fa1__DOT__finalMant = 
                (0xffffffU & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                              << 2U));
            vlTOPp->fln__DOT__fa1__DOT__finalExp = 
                (0xffU & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                          - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                vlTOPp->fln__DOT__fa1__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                    << 3U));
                vlTOPp->fln__DOT__fa1__DOT__finalExp 
                    = (0xffU & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                    vlTOPp->fln__DOT__fa1__DOT__finalMant 
                        = (0xffffffU & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                        << 4U));
                    vlTOPp->fln__DOT__fa1__DOT__finalExp 
                        = (0xffU & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                        vlTOPp->fln__DOT__fa1__DOT__finalMant 
                            = (0xffffffU & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                            << 5U));
                        vlTOPp->fln__DOT__fa1__DOT__finalExp 
                            = (0xffU & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                            vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                = (0xffffffU & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                << 6U));
                            vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                = (0xffU & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                                vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                    = (0xffffffU & 
                                       (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                        << 7U));
                                vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                    = (0xffU & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                                    vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                        = (0xffffffU 
                                           & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                              << 8U));
                                    vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                                        vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                            = (0xffffffU 
                                               & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                  << 9U));
                                        vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                                            vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                = (0xffffffU 
                                                   & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                      << 0xaU));
                                            vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                                                vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                        << 0xbU));
                                                vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                                                    vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                            << 0xcU));
                                                    vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                                                        vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                << 0xdU));
                                                        vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                                                            vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                    << 0xeU));
                                                            vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                                                                vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                        << 0xfU));
                                                                vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                                                                    vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                            << 0x10U));
                                                                    vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                                                                        vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                                << 0x11U));
                                                                        vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                                                                            vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                                << 0x12U));
                                                                            vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                                                                                vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                                << 0x13U));
                                                                                vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                                                                                vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                                << 0x14U));
                                                                                vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                                                                                vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                                << 0x15U));
                                                                                vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                                                                                vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                                << 0x16U));
                                                                                vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
                                                                                vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                                                << 0x17U));
                                                                                vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fln__DOT__fa1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
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
    if (((0U == vlTOPp->fln__DOT__temp6) & (0U == (IData)(vlTOPp->fln__DOT__fa1__DOT__num2Exp)))) {
        vlTOPp->fln__DOT__fa1__DOT__finalMant = 0U;
        vlTOPp->fln__DOT__fa1__DOT__finalExp = 0U;
    }
    vlTOPp->fln__DOT__fa1__DOT__unrounded = ((0x80000000U 
                                              & ((~ (IData)(vlTOPp->fln__DOT__fa1__DOT__finalSign)) 
                                                 << 0x1fU)) 
                                             | (((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                 << 0x17U) 
                                                | (0x7fffffU 
                                                   & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                      >> 1U))));
    if ((4U & vlTOPp->fln__DOT__fa1__DOT__unrounded)) {
        if ((0U == (3U & vlTOPp->fln__DOT__fa1__DOT__unrounded))) {
            if ((8U & vlTOPp->fln__DOT__fa1__DOT__unrounded)) {
                vlTOPp->fln__DOT__fa1__DOT__r0__DOT__overflowCheck 
                    = (0x7fffffU & vlTOPp->fln__DOT__fa1__DOT__unrounded);
                vlTOPp->fln__DOT__fa1__DOT__r0__DOT__overflowCheck 
                    = (0xffffffU & ((IData)(1U) + vlTOPp->fln__DOT__fa1__DOT__r0__DOT__overflowCheck));
                vlTOPp->fln__DOT__fa1__DOT__r0__DOT__rounded 
                    = ((0x800000U & vlTOPp->fln__DOT__fa1__DOT__r0__DOT__overflowCheck)
                        ? ((0x80000000U & vlTOPp->fln__DOT__fa1__DOT__unrounded) 
                           | ((0x7f800000U & (((IData)(1U) 
                                               + (vlTOPp->fln__DOT__fa1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                              | (0x7fffffU & vlTOPp->fln__DOT__fa1__DOT__r0__DOT__overflowCheck)))
                        : ((0xff800000U & vlTOPp->fln__DOT__fa1__DOT__unrounded) 
                           | (0x7fffffU & vlTOPp->fln__DOT__fa1__DOT__r0__DOT__overflowCheck)));
            } else {
                vlTOPp->fln__DOT__fa1__DOT__r0__DOT__rounded 
                    = vlTOPp->fln__DOT__fa1__DOT__unrounded;
            }
        } else {
            vlTOPp->fln__DOT__fa1__DOT__r0__DOT__overflowCheck 
                = (0x7fffffU & vlTOPp->fln__DOT__fa1__DOT__unrounded);
            vlTOPp->fln__DOT__fa1__DOT__r0__DOT__overflowCheck 
                = (0xffffffU & ((IData)(1U) + vlTOPp->fln__DOT__fa1__DOT__r0__DOT__overflowCheck));
            vlTOPp->fln__DOT__fa1__DOT__r0__DOT__rounded 
                = ((0x800000U & vlTOPp->fln__DOT__fa1__DOT__r0__DOT__overflowCheck)
                    ? ((0x80000000U & vlTOPp->fln__DOT__fa1__DOT__unrounded) 
                       | ((0x7f800000U & (((IData)(1U) 
                                           + (vlTOPp->fln__DOT__fa1__DOT__unrounded 
                                              >> 0x17U)) 
                                          << 0x17U)) 
                          | (0x7fffffU & vlTOPp->fln__DOT__fa1__DOT__r0__DOT__overflowCheck)))
                    : ((0xff800000U & vlTOPp->fln__DOT__fa1__DOT__unrounded) 
                       | (0x7fffffU & vlTOPp->fln__DOT__fa1__DOT__r0__DOT__overflowCheck)));
        }
    } else {
        vlTOPp->fln__DOT__fa1__DOT__r0__DOT__rounded 
            = vlTOPp->fln__DOT__fa1__DOT__unrounded;
    }
    vlTOPp->fln__DOT__fa2__DOT__finalSign = 0U;
    vlTOPp->fln__DOT__fa2__DOT__largerMag = 0U;
    vlTOPp->fln__DOT__fa2__DOT__num1Exp = (0xffU & 
                                           (vlTOPp->fln__DOT__fa1__DOT__r0__DOT__rounded 
                                            >> 0x17U));
    vlTOPp->fln__DOT__fa2__DOT__num2Exp = (0xffU & 
                                           (vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded 
                                            >> 0x17U));
    vlTOPp->fln__DOT__fa2__DOT__num1Mant = (0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->fln__DOT__fa1__DOT__r0__DOT__rounded));
    vlTOPp->fln__DOT__fa2__DOT__num2Mant = (0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded));
    if (((IData)(vlTOPp->fln__DOT__fa2__DOT__num1Exp) 
         < (IData)(vlTOPp->fln__DOT__fa2__DOT__num2Exp))) {
        vlTOPp->fln__DOT__fa2__DOT__finalExp = vlTOPp->fln__DOT__fa2__DOT__num2Exp;
        vlTOPp->fln__DOT__fa2__DOT__num1Mant = ((0x17U 
                                                 >= 
                                                 (0xffU 
                                                  & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                     - (IData)(vlTOPp->fln__DOT__fa2__DOT__num1Exp))))
                                                 ? 
                                                (0xffffffU 
                                                 & (vlTOPp->fln__DOT__fa2__DOT__num1Mant 
                                                    >> 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                        - (IData)(vlTOPp->fln__DOT__fa2__DOT__num1Exp)))))
                                                 : 0U);
        vlTOPp->fln__DOT__fa2__DOT__largerMag = 1U;
    } else {
        if (((IData)(vlTOPp->fln__DOT__fa2__DOT__num2Exp) 
             < (IData)(vlTOPp->fln__DOT__fa2__DOT__num1Exp))) {
            vlTOPp->fln__DOT__fa2__DOT__finalExp = vlTOPp->fln__DOT__fa2__DOT__num1Exp;
            vlTOPp->fln__DOT__fa2__DOT__num2Mant = 
                ((0x17U >= (0xffU & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                     - (IData)(vlTOPp->fln__DOT__fa2__DOT__num2Exp))))
                  ? (0xffffffU & (vlTOPp->fln__DOT__fa2__DOT__num2Mant 
                                  >> (0xffU & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                               - (IData)(vlTOPp->fln__DOT__fa2__DOT__num2Exp)))))
                  : 0U);
            vlTOPp->fln__DOT__fa2__DOT__largerMag = 0U;
        } else {
            vlTOPp->fln__DOT__fa2__DOT__finalExp = vlTOPp->fln__DOT__fa2__DOT__num1Exp;
            vlTOPp->fln__DOT__fa2__DOT__largerMag = 
                (vlTOPp->fln__DOT__fa2__DOT__num2Mant 
                 > vlTOPp->fln__DOT__fa2__DOT__num1Mant);
        }
    }
    if ((0x80000000U & (vlTOPp->fln__DOT__fa1__DOT__r0__DOT__rounded 
                        & vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded))) {
        vlTOPp->fln__DOT__fa2__DOT__sumMants = (0x1ffffffU 
                                                & (vlTOPp->fln__DOT__fa2__DOT__num2Mant 
                                                   + vlTOPp->fln__DOT__fa2__DOT__num1Mant));
        vlTOPp->fln__DOT__fa2__DOT__finalExp = (0xffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp)));
        vlTOPp->fln__DOT__fa2__DOT__finalSign = 0U;
        vlTOPp->fln__DOT__fa2__DOT__finalMant = (0xffffffU 
                                                 & (vlTOPp->fln__DOT__fa2__DOT__sumMants 
                                                    >> 1U));
    } else {
        if ((1U & ((vlTOPp->fln__DOT__fa1__DOT__r0__DOT__rounded 
                    >> 0x1fU) & (~ (vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded 
                                    >> 0x1fU))))) {
            vlTOPp->fln__DOT__fa2__DOT__sumMants = 
                (0x1ffffffU & (vlTOPp->fln__DOT__fa2__DOT__num1Mant 
                               - vlTOPp->fln__DOT__fa2__DOT__num2Mant));
            vlTOPp->fln__DOT__fa2__DOT__finalSign = vlTOPp->fln__DOT__fa2__DOT__largerMag;
            vlTOPp->fln__DOT__fa2__DOT__finalMant = 
                (0xffffffU & vlTOPp->fln__DOT__fa2__DOT__sumMants);
            vlTOPp->fln__DOT__fa2__DOT__finalMant = 
                (0xffffffU & ((0x1000000U & vlTOPp->fln__DOT__fa2__DOT__sumMants)
                               ? ((IData)(0xffffffffU) 
                                  * vlTOPp->fln__DOT__fa2__DOT__finalMant)
                               : vlTOPp->fln__DOT__fa2__DOT__finalMant));
        } else {
            if ((1U & ((~ (vlTOPp->fln__DOT__fa1__DOT__r0__DOT__rounded 
                           >> 0x1fU)) & (vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded 
                                         >> 0x1fU)))) {
                vlTOPp->fln__DOT__fa2__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fln__DOT__fa2__DOT__num2Mant 
                                     - vlTOPp->fln__DOT__fa2__DOT__num1Mant));
                vlTOPp->fln__DOT__fa2__DOT__finalSign 
                    = (1U & (~ (IData)(vlTOPp->fln__DOT__fa2__DOT__largerMag)));
                vlTOPp->fln__DOT__fa2__DOT__finalMant 
                    = (0xffffffU & vlTOPp->fln__DOT__fa2__DOT__sumMants);
                vlTOPp->fln__DOT__fa2__DOT__finalMant 
                    = (0xffffffU & ((0x1000000U & vlTOPp->fln__DOT__fa2__DOT__sumMants)
                                     ? ((IData)(0xffffffffU) 
                                        * vlTOPp->fln__DOT__fa2__DOT__finalMant)
                                     : vlTOPp->fln__DOT__fa2__DOT__finalMant));
            } else {
                vlTOPp->fln__DOT__fa2__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fln__DOT__fa2__DOT__num2Mant 
                                     + vlTOPp->fln__DOT__fa2__DOT__num1Mant));
                vlTOPp->fln__DOT__fa2__DOT__finalExp 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp)));
                vlTOPp->fln__DOT__fa2__DOT__finalSign = 1U;
                vlTOPp->fln__DOT__fa2__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fln__DOT__fa2__DOT__sumMants 
                                    >> 1U));
            }
        }
    }
    if ((0x800000U & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
        vlTOPp->fln__DOT__fa2__DOT__finalMant = (0xffffffU 
                                                 & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                    << 1U));
    } else {
        if ((0x400000U & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
            vlTOPp->fln__DOT__fa2__DOT__finalMant = 
                (0xffffffU & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                              << 2U));
            vlTOPp->fln__DOT__fa2__DOT__finalExp = 
                (0xffU & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                          - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                vlTOPp->fln__DOT__fa2__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                    << 3U));
                vlTOPp->fln__DOT__fa2__DOT__finalExp 
                    = (0xffU & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                    vlTOPp->fln__DOT__fa2__DOT__finalMant 
                        = (0xffffffU & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                        << 4U));
                    vlTOPp->fln__DOT__fa2__DOT__finalExp 
                        = (0xffU & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                        vlTOPp->fln__DOT__fa2__DOT__finalMant 
                            = (0xffffffU & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                            << 5U));
                        vlTOPp->fln__DOT__fa2__DOT__finalExp 
                            = (0xffU & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                            vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                = (0xffffffU & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                << 6U));
                            vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                = (0xffU & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                                vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                    = (0xffffffU & 
                                       (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                        << 7U));
                                vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                    = (0xffU & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                                    vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                        = (0xffffffU 
                                           & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                              << 8U));
                                    vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                                        vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                            = (0xffffffU 
                                               & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                  << 9U));
                                        vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                                            vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                = (0xffffffU 
                                                   & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                      << 0xaU));
                                            vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                                                vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                        << 0xbU));
                                                vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                                                    vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                            << 0xcU));
                                                    vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                                                        vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                << 0xdU));
                                                        vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                                                            vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                    << 0xeU));
                                                            vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                                                                vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                        << 0xfU));
                                                                vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                                                                    vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                            << 0x10U));
                                                                    vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                                                                        vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                                << 0x11U));
                                                                        vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                                                                            vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                                << 0x12U));
                                                                            vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                                                                                vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                                << 0x13U));
                                                                                vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                                                                                vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                                << 0x14U));
                                                                                vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                                                                                vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                                << 0x15U));
                                                                                vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                                                                                vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                                << 0x16U));
                                                                                vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
                                                                                vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                                                << 0x17U));
                                                                                vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fln__DOT__fa2__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
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
    if (((0U == vlTOPp->fln__DOT__fa1__DOT__r0__DOT__rounded) 
         & (0U == (IData)(vlTOPp->fln__DOT__fa2__DOT__num2Exp)))) {
        vlTOPp->fln__DOT__fa2__DOT__finalMant = 0U;
        vlTOPp->fln__DOT__fa2__DOT__finalExp = 0U;
    }
    vlTOPp->fln__DOT__fa2__DOT__unrounded = ((0x80000000U 
                                              & ((~ (IData)(vlTOPp->fln__DOT__fa2__DOT__finalSign)) 
                                                 << 0x1fU)) 
                                             | (((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                 << 0x17U) 
                                                | (0x7fffffU 
                                                   & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                      >> 1U))));
    if ((4U & vlTOPp->fln__DOT__fa2__DOT__unrounded)) {
        if ((0U == (3U & vlTOPp->fln__DOT__fa2__DOT__unrounded))) {
            if ((8U & vlTOPp->fln__DOT__fa2__DOT__unrounded)) {
                vlTOPp->fln__DOT__fa2__DOT__r0__DOT__overflowCheck 
                    = (0x7fffffU & vlTOPp->fln__DOT__fa2__DOT__unrounded);
                vlTOPp->fln__DOT__fa2__DOT__r0__DOT__overflowCheck 
                    = (0xffffffU & ((IData)(1U) + vlTOPp->fln__DOT__fa2__DOT__r0__DOT__overflowCheck));
                vlTOPp->fln__DOT__fa2__DOT__r0__DOT__rounded 
                    = ((0x800000U & vlTOPp->fln__DOT__fa2__DOT__r0__DOT__overflowCheck)
                        ? ((0x80000000U & vlTOPp->fln__DOT__fa2__DOT__unrounded) 
                           | ((0x7f800000U & (((IData)(1U) 
                                               + (vlTOPp->fln__DOT__fa2__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                              | (0x7fffffU & vlTOPp->fln__DOT__fa2__DOT__r0__DOT__overflowCheck)))
                        : ((0xff800000U & vlTOPp->fln__DOT__fa2__DOT__unrounded) 
                           | (0x7fffffU & vlTOPp->fln__DOT__fa2__DOT__r0__DOT__overflowCheck)));
            } else {
                vlTOPp->fln__DOT__fa2__DOT__r0__DOT__rounded 
                    = vlTOPp->fln__DOT__fa2__DOT__unrounded;
            }
        } else {
            vlTOPp->fln__DOT__fa2__DOT__r0__DOT__overflowCheck 
                = (0x7fffffU & vlTOPp->fln__DOT__fa2__DOT__unrounded);
            vlTOPp->fln__DOT__fa2__DOT__r0__DOT__overflowCheck 
                = (0xffffffU & ((IData)(1U) + vlTOPp->fln__DOT__fa2__DOT__r0__DOT__overflowCheck));
            vlTOPp->fln__DOT__fa2__DOT__r0__DOT__rounded 
                = ((0x800000U & vlTOPp->fln__DOT__fa2__DOT__r0__DOT__overflowCheck)
                    ? ((0x80000000U & vlTOPp->fln__DOT__fa2__DOT__unrounded) 
                       | ((0x7f800000U & (((IData)(1U) 
                                           + (vlTOPp->fln__DOT__fa2__DOT__unrounded 
                                              >> 0x17U)) 
                                          << 0x17U)) 
                          | (0x7fffffU & vlTOPp->fln__DOT__fa2__DOT__r0__DOT__overflowCheck)))
                    : ((0xff800000U & vlTOPp->fln__DOT__fa2__DOT__unrounded) 
                       | (0x7fffffU & vlTOPp->fln__DOT__fa2__DOT__r0__DOT__overflowCheck)));
        }
    } else {
        vlTOPp->fln__DOT__fa2__DOT__r0__DOT__rounded 
            = vlTOPp->fln__DOT__fa2__DOT__unrounded;
    }
    vlTOPp->fln__DOT__fma2__DOT__mantissa_a = ((0U 
                                                == vlSymsp->TOP__fln__DOT__fm5.__PVT__r0__DOT__rounded)
                                                ? 0U
                                                : (0x800000U 
                                                   | (0x7fffffU 
                                                      & vlSymsp->TOP__fln__DOT__fm5.__PVT__r0__DOT__rounded)));
    vlTOPp->fln__DOT__fma2__DOT__mantissa_c = ((0U 
                                                == vlTOPp->fln__DOT__fa2__DOT__r0__DOT__rounded)
                                                ? 0U
                                                : (0x800000U 
                                                   | (0x7fffffU 
                                                      & vlTOPp->fln__DOT__fa2__DOT__r0__DOT__rounded)));
    vlTOPp->fln__DOT__fma2__DOT__sign_out = (1U & (vlSymsp->TOP__fln__DOT__fm5.__PVT__r0__DOT__rounded 
                                                   >> 0x1fU));
    vlTOPp->fln__DOT__fma2__DOT__exp_out = (0xffU & 
                                            ((IData)(0xfdU) 
                                             + (vlSymsp->TOP__fln__DOT__fm5.__PVT__r0__DOT__rounded 
                                                >> 0x17U)));
    vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_out = 
        (0xffffffffffffULL & (0xcccccdULL * (QData)((IData)(vlTOPp->fln__DOT__fma2__DOT__mantissa_a))));
    vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
        = (0xffffffU & (IData)((vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_out 
                                >> 0x18U)));
    if ((0x800000U & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
        vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
            = (0xffffffU & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                            << 1U));
    } else {
        if ((0x400000U & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
            vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                = (0xffffffU & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                << 2U));
            vlTOPp->fln__DOT__fma2__DOT__exp_out = 
                (0xffU & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                          - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                    = (0xffffffU & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                    << 3U));
                vlTOPp->fln__DOT__fma2__DOT__exp_out 
                    = (0xffU & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                    vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                        = (0xffffffU & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                        << 4U));
                    vlTOPp->fln__DOT__fma2__DOT__exp_out 
                        = (0xffU & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                        vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                            = (0xffffffU & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                            << 5U));
                        vlTOPp->fln__DOT__fma2__DOT__exp_out 
                            = (0xffU & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                            vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                = (0xffffffU & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                << 6U));
                            vlTOPp->fln__DOT__fma2__DOT__exp_out 
                                = (0xffU & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                                vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                    = (0xffffffU & 
                                       (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                        << 7U));
                                vlTOPp->fln__DOT__fma2__DOT__exp_out 
                                    = (0xffU & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                                    vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                        = (0xffffffU 
                                           & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                              << 8U));
                                    vlTOPp->fln__DOT__fma2__DOT__exp_out 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                                        vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                            = (0xffffffU 
                                               & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                  << 9U));
                                        vlTOPp->fln__DOT__fma2__DOT__exp_out 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                                            vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                = (0xffffffU 
                                                   & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                      << 0xaU));
                                            vlTOPp->fln__DOT__fma2__DOT__exp_out 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                        << 0xbU));
                                                vlTOPp->fln__DOT__fma2__DOT__exp_out 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                    vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                            << 0xcU));
                                                    vlTOPp->fln__DOT__fma2__DOT__exp_out 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                        vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                << 0xdU));
                                                        vlTOPp->fln__DOT__fma2__DOT__exp_out 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                            vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                    << 0xeU));
                                                            vlTOPp->fln__DOT__fma2__DOT__exp_out 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                                vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                        << 0xfU));
                                                                vlTOPp->fln__DOT__fma2__DOT__exp_out 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                                    vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                            << 0x10U));
                                                                    vlTOPp->fln__DOT__fma2__DOT__exp_out 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                                        vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                << 0x11U));
                                                                        vlTOPp->fln__DOT__fma2__DOT__exp_out 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                                            vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                << 0x12U));
                                                                            vlTOPp->fln__DOT__fma2__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                << 0x13U));
                                                                                vlTOPp->fln__DOT__fma2__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                << 0x14U));
                                                                                vlTOPp->fln__DOT__fma2__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                << 0x15U));
                                                                                vlTOPp->fln__DOT__fma2__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                << 0x16U));
                                                                                vlTOPp->fln__DOT__fma2__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm)) {
                                                                                vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                                                                << 0x17U));
                                                                                vlTOPp->fln__DOT__fma2__DOT__exp_out 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fln__DOT__fma2__DOT__exp_out = 0xffU;
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
    vlTOPp->fln__DOT__fma2__DOT__exp_out = (0xffU & 
                                            ((IData)(1U) 
                                             + (IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out)));
    vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
        = ((0U == vlSymsp->TOP__fln__DOT__fm5.__PVT__r0__DOT__rounded)
            ? 0U : (0x800000U | (0x7fffffU & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                              >> 1U))));
    if (((IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out) 
         < (0xffU & (vlTOPp->fln__DOT__fa2__DOT__r0__DOT__rounded 
                     >> 0x17U)))) {
        vlTOPp->fln__DOT__fma2__DOT__final_exp = (0xffU 
                                                  & (vlTOPp->fln__DOT__fa2__DOT__r0__DOT__rounded 
                                                     >> 0x17U));
        vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
            = ((0x17U >= (0xffU & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                   - (IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out))))
                ? (0xffffffU & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                >> (0xffU & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                             - (IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out)))))
                : 0U);
        vlTOPp->fln__DOT__fma2__DOT__largerMag = 1U;
    } else {
        if (((0xffU & (vlTOPp->fln__DOT__fa2__DOT__r0__DOT__rounded 
                       >> 0x17U)) < (IData)(vlTOPp->fln__DOT__fma2__DOT__exp_out))) {
            vlTOPp->fln__DOT__fma2__DOT__final_exp 
                = vlTOPp->fln__DOT__fma2__DOT__exp_out;
            vlTOPp->fln__DOT__fma2__DOT__mantissa_c 
                = ((0x17U >= (0xffU & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                       - (vlTOPp->fln__DOT__fa2__DOT__r0__DOT__rounded 
                                          >> 0x17U))))
                    ? (0xffffffU & (vlTOPp->fln__DOT__fma2__DOT__mantissa_c 
                                    >> (0xffU & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                                 - 
                                                 (vlTOPp->fln__DOT__fa2__DOT__r0__DOT__rounded 
                                                  >> 0x17U)))))
                    : 0U);
            vlTOPp->fln__DOT__fma2__DOT__largerMag = 0U;
        } else {
            vlTOPp->fln__DOT__fma2__DOT__final_exp 
                = vlTOPp->fln__DOT__fma2__DOT__exp_out;
            vlTOPp->fln__DOT__fma2__DOT__largerMag 
                = (vlTOPp->fln__DOT__fma2__DOT__mantissa_c 
                   > vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm);
        }
    }
    if (((IData)(vlTOPp->fln__DOT__fma2__DOT__sign_out) 
         & (vlTOPp->fln__DOT__fa2__DOT__r0__DOT__rounded 
            >> 0x1fU))) {
        vlTOPp->fln__DOT__fma2__DOT__sum_mants = (0x1ffffffU 
                                                  & (vlTOPp->fln__DOT__fma2__DOT__mantissa_c 
                                                     + vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm));
        vlTOPp->fln__DOT__fma2__DOT__final_exp = (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp)));
        vlTOPp->fln__DOT__fma2__DOT__sign_out = 0U;
        vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
            = (0xffffffU & (vlTOPp->fln__DOT__fma2__DOT__sum_mants 
                            >> 1U));
    } else {
        if (((IData)(vlTOPp->fln__DOT__fma2__DOT__sign_out) 
             & (~ (vlTOPp->fln__DOT__fa2__DOT__r0__DOT__rounded 
                   >> 0x1fU)))) {
            vlTOPp->fln__DOT__fma2__DOT__sum_mants 
                = (0x1ffffffU & (vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm 
                                 - vlTOPp->fln__DOT__fma2__DOT__mantissa_c));
            vlTOPp->fln__DOT__fma2__DOT__sign_out = vlTOPp->fln__DOT__fma2__DOT__largerMag;
            vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                = (0xffffffU & vlTOPp->fln__DOT__fma2__DOT__sum_mants);
            vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                = (0xffffffU & ((0x1000000U & vlTOPp->fln__DOT__fma2__DOT__sum_mants)
                                 ? ((IData)(0xffffffffU) 
                                    * vlTOPp->fln__DOT__fma2__DOT__final_mantissa)
                                 : vlTOPp->fln__DOT__fma2__DOT__final_mantissa));
        } else {
            if ((1U & ((~ (IData)(vlTOPp->fln__DOT__fma2__DOT__sign_out)) 
                       & (vlTOPp->fln__DOT__fa2__DOT__r0__DOT__rounded 
                          >> 0x1fU)))) {
                vlTOPp->fln__DOT__fma2__DOT__sum_mants 
                    = (0x1ffffffU & (vlTOPp->fln__DOT__fma2__DOT__mantissa_c 
                                     - vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm));
                vlTOPp->fln__DOT__fma2__DOT__sign_out 
                    = (1U & (~ (IData)(vlTOPp->fln__DOT__fma2__DOT__largerMag)));
                vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                    = (0xffffffU & vlTOPp->fln__DOT__fma2__DOT__sum_mants);
                vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                    = (0xffffffU & ((0x1000000U & vlTOPp->fln__DOT__fma2__DOT__sum_mants)
                                     ? ((IData)(0xffffffffU) 
                                        * vlTOPp->fln__DOT__fma2__DOT__final_mantissa)
                                     : vlTOPp->fln__DOT__fma2__DOT__final_mantissa));
            } else {
                vlTOPp->fln__DOT__fma2__DOT__sum_mants 
                    = (0x1ffffffU & (vlTOPp->fln__DOT__fma2__DOT__mantissa_c 
                                     + vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm));
                vlTOPp->fln__DOT__fma2__DOT__final_exp 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp)));
                vlTOPp->fln__DOT__fma2__DOT__sign_out = 1U;
                vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                    = (0xffffffU & (vlTOPp->fln__DOT__fma2__DOT__sum_mants 
                                    >> 1U));
            }
        }
    }
    if ((0x800000U & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
        vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
            = (0xffffffU & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                            << 1U));
    } else {
        if ((0x400000U & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
            vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                = (0xffffffU & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                << 2U));
            vlTOPp->fln__DOT__fma2__DOT__final_exp 
                = (0xffU & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                            - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                    = (0xffffffU & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                    << 3U));
                vlTOPp->fln__DOT__fma2__DOT__final_exp 
                    = (0xffU & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                    vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                        = (0xffffffU & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                        << 4U));
                    vlTOPp->fln__DOT__fma2__DOT__final_exp 
                        = (0xffU & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                        vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                            = (0xffffffU & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                            << 5U));
                        vlTOPp->fln__DOT__fma2__DOT__final_exp 
                            = (0xffU & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                            vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                = (0xffffffU & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                << 6U));
                            vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                = (0xffU & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                                vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                    = (0xffffffU & 
                                       (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                        << 7U));
                                vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                    = (0xffU & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                                    vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                        = (0xffffffU 
                                           & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                              << 8U));
                                    vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                                        vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                            = (0xffffffU 
                                               & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                  << 9U));
                                        vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                                            vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                = (0xffffffU 
                                                   & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                      << 0xaU));
                                            vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                                                vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                        << 0xbU));
                                                vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                                                    vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                            << 0xcU));
                                                    vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                                                        vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                << 0xdU));
                                                        vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                                                            vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                    << 0xeU));
                                                            vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                                                                vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                        << 0xfU));
                                                                vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                                                                    vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                            << 0x10U));
                                                                    vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                                                                        vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                                << 0x11U));
                                                                        vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                                                                            vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                                << 0x12U));
                                                                            vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                                                                                vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                                << 0x13U));
                                                                                vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                                                                                vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                                << 0x14U));
                                                                                vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                                                                                vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                                << 0x15U));
                                                                                vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                                                                                vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                                << 0x16U));
                                                                                vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fln__DOT__fma2__DOT__final_mantissa)) {
                                                                                vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                                                << 0x17U));
                                                                                vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fln__DOT__fma2__DOT__final_exp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
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
    vlTOPp->out1 = ((0x80000000U & vlTOPp->num1) ? 0x7fc00000U
                     : ((0x80000000U & ((~ (IData)(vlTOPp->fln__DOT__fma2__DOT__sign_out)) 
                                        << 0x1fU)) 
                        | (((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                            << 0x17U) | (0x7fffffU 
                                         & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                            >> 1U)))));
}

void Vfln::_eval(Vfln__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfln::_eval\n"); );
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlSymsp->TOP__fln__DOT__fm0._combo__TOP__fln__DOT__fm0__1(vlSymsp);
    vlSymsp->TOP__fln__DOT__fm1._combo__TOP__fln__DOT__fm1__2(vlSymsp);
    vlSymsp->TOP__fln__DOT__fm2._combo__TOP__fln__DOT__fm2__3(vlSymsp);
    vlSymsp->TOP__fln__DOT__fm4._combo__TOP__fln__DOT__fm4__4(vlSymsp);
    vlSymsp->TOP__fln__DOT__fm3._combo__TOP__fln__DOT__fm3__5(vlSymsp);
    vlSymsp->TOP__fln__DOT__fm5._combo__TOP__fln__DOT__fm5__6(vlSymsp);
    vlTOPp->_combo__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vfln::_change_request(Vfln__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfln::_change_request\n"); );
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vfln::_change_request_1(Vfln__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfln::_change_request_1\n"); );
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vfln::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfln::_eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
