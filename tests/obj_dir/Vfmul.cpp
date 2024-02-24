// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfmul.h for the primary calling header

#include "Vfmul.h"
#include "Vfmul__Syms.h"

//==========

void Vfmul::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfmul::eval\n"); );
    Vfmul__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vfmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("../fmul.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vfmul::_eval_initial_loop(Vfmul__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("../fmul.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vfmul::_combo__TOP__1(Vfmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul::_combo__TOP__1\n"); );
    Vfmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->fmul__DOT__mantissaProd = (0xffffffffffffULL 
                                       & ((QData)((IData)(
                                                          ((0U 
                                                            == vlTOPp->num1)
                                                            ? 0U
                                                            : 
                                                           (0x800000U 
                                                            | (0x7fffffU 
                                                               & vlTOPp->num1))))) 
                                          * (QData)((IData)(
                                                            ((0U 
                                                              == vlTOPp->num2)
                                                              ? 0U
                                                              : 
                                                             (0x800000U 
                                                              | (0x7fffffU 
                                                                 & vlTOPp->num2)))))));
    vlTOPp->fmul__DOT__expF = (0xffU & (((vlTOPp->num1 
                                          >> 0x17U) 
                                         + (vlTOPp->num2 
                                            >> 0x17U)) 
                                        - (IData)(0x7fU)));
    vlTOPp->fmul__DOT__mantissa = (0x7fffffU & (IData)(
                                                       (vlTOPp->fmul__DOT__mantissaProd 
                                                        >> 0x19U)));
    if ((0x400000U & vlTOPp->fmul__DOT__mantissa)) {
        vlTOPp->fmul__DOT__mantissa = (0x7fffffU & 
                                       (vlTOPp->fmul__DOT__mantissa 
                                        << 2U));
        vlTOPp->fmul__DOT__expF = (0xffU & ((IData)(vlTOPp->fmul__DOT__expF) 
                                            - (IData)(1U)));
    } else {
        if ((0x200000U & vlTOPp->fmul__DOT__mantissa)) {
            vlTOPp->fmul__DOT__mantissa = (0x7fffffU 
                                           & (vlTOPp->fmul__DOT__mantissa 
                                              << 3U));
            vlTOPp->fmul__DOT__expF = (0xffU & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                - (IData)(2U)));
        } else {
            if ((0x100000U & vlTOPp->fmul__DOT__mantissa)) {
                vlTOPp->fmul__DOT__mantissa = (0x7fffffU 
                                               & (vlTOPp->fmul__DOT__mantissa 
                                                  << 4U));
                vlTOPp->fmul__DOT__expF = (0xffU & 
                                           ((IData)(vlTOPp->fmul__DOT__expF) 
                                            - (IData)(3U)));
            } else {
                if ((0x80000U & vlTOPp->fmul__DOT__mantissa)) {
                    vlTOPp->fmul__DOT__mantissa = (0x7fffffU 
                                                   & (vlTOPp->fmul__DOT__mantissa 
                                                      << 5U));
                    vlTOPp->fmul__DOT__expF = (0xffU 
                                               & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                  - (IData)(4U)));
                } else {
                    if ((0x40000U & vlTOPp->fmul__DOT__mantissa)) {
                        vlTOPp->fmul__DOT__mantissa 
                            = (0x7fffffU & (vlTOPp->fmul__DOT__mantissa 
                                            << 6U));
                        vlTOPp->fmul__DOT__expF = (0xffU 
                                                   & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                      - (IData)(5U)));
                    } else {
                        if ((0x20000U & vlTOPp->fmul__DOT__mantissa)) {
                            vlTOPp->fmul__DOT__mantissa 
                                = (0x7fffffU & (vlTOPp->fmul__DOT__mantissa 
                                                << 7U));
                            vlTOPp->fmul__DOT__expF 
                                = (0xffU & ((IData)(vlTOPp->fmul__DOT__expF) 
                                            - (IData)(6U)));
                        } else {
                            if ((0x10000U & vlTOPp->fmul__DOT__mantissa)) {
                                vlTOPp->fmul__DOT__mantissa 
                                    = (0x7fffffU & 
                                       (vlTOPp->fmul__DOT__mantissa 
                                        << 8U));
                                vlTOPp->fmul__DOT__expF 
                                    = (0xffU & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                - (IData)(7U)));
                            } else {
                                if ((0x8000U & vlTOPp->fmul__DOT__mantissa)) {
                                    vlTOPp->fmul__DOT__mantissa 
                                        = (0x7fffffU 
                                           & (vlTOPp->fmul__DOT__mantissa 
                                              << 9U));
                                    vlTOPp->fmul__DOT__expF 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fmul__DOT__expF) 
                                            - (IData)(8U)));
                                } else {
                                    if ((0x4000U & vlTOPp->fmul__DOT__mantissa)) {
                                        vlTOPp->fmul__DOT__mantissa 
                                            = (0x7fffffU 
                                               & (vlTOPp->fmul__DOT__mantissa 
                                                  << 0xaU));
                                        vlTOPp->fmul__DOT__expF 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                  - (IData)(9U)));
                                    } else {
                                        if ((0x2000U 
                                             & vlTOPp->fmul__DOT__mantissa)) {
                                            vlTOPp->fmul__DOT__mantissa 
                                                = (0x7fffffU 
                                                   & (vlTOPp->fmul__DOT__mantissa 
                                                      << 0xbU));
                                            vlTOPp->fmul__DOT__expF 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                      - (IData)(0xaU)));
                                        } else {
                                            if ((0x1000U 
                                                 & vlTOPp->fmul__DOT__mantissa)) {
                                                vlTOPp->fmul__DOT__mantissa 
                                                    = 
                                                    (0x7fffffU 
                                                     & (vlTOPp->fmul__DOT__mantissa 
                                                        << 0xcU));
                                                vlTOPp->fmul__DOT__expF 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                        - (IData)(0xbU)));
                                            } else {
                                                if (
                                                    (0x800U 
                                                     & vlTOPp->fmul__DOT__mantissa)) {
                                                    vlTOPp->fmul__DOT__mantissa 
                                                        = 
                                                        (0x7fffffU 
                                                         & (vlTOPp->fmul__DOT__mantissa 
                                                            << 0xdU));
                                                    vlTOPp->fmul__DOT__expF 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                            - (IData)(0xcU)));
                                                } else {
                                                    if (
                                                        (0x400U 
                                                         & vlTOPp->fmul__DOT__mantissa)) {
                                                        vlTOPp->fmul__DOT__mantissa 
                                                            = 
                                                            (0x7fffffU 
                                                             & (vlTOPp->fmul__DOT__mantissa 
                                                                << 0xeU));
                                                        vlTOPp->fmul__DOT__expF 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                                - (IData)(0xdU)));
                                                    } else {
                                                        if (
                                                            (0x200U 
                                                             & vlTOPp->fmul__DOT__mantissa)) {
                                                            vlTOPp->fmul__DOT__mantissa 
                                                                = 
                                                                (0x7fffffU 
                                                                 & (vlTOPp->fmul__DOT__mantissa 
                                                                    << 0xfU));
                                                            vlTOPp->fmul__DOT__expF 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                                    - (IData)(0xeU)));
                                                        } else {
                                                            if (
                                                                (0x100U 
                                                                 & vlTOPp->fmul__DOT__mantissa)) {
                                                                vlTOPp->fmul__DOT__mantissa 
                                                                    = 
                                                                    (0x7fffffU 
                                                                     & (vlTOPp->fmul__DOT__mantissa 
                                                                        << 0x10U));
                                                                vlTOPp->fmul__DOT__expF 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                                        - (IData)(0xfU)));
                                                            } else {
                                                                if (
                                                                    (0x80U 
                                                                     & vlTOPp->fmul__DOT__mantissa)) {
                                                                    vlTOPp->fmul__DOT__mantissa 
                                                                        = 
                                                                        (0x7fffffU 
                                                                         & (vlTOPp->fmul__DOT__mantissa 
                                                                            << 0x11U));
                                                                    vlTOPp->fmul__DOT__expF 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                                            - (IData)(0x10U)));
                                                                } else {
                                                                    if (
                                                                        (0x40U 
                                                                         & vlTOPp->fmul__DOT__mantissa)) {
                                                                        vlTOPp->fmul__DOT__mantissa 
                                                                            = 
                                                                            (0x7fffffU 
                                                                             & (vlTOPp->fmul__DOT__mantissa 
                                                                                << 0x12U));
                                                                        vlTOPp->fmul__DOT__expF 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                                                - (IData)(0x11U)));
                                                                    } else {
                                                                        if (
                                                                            (0x20U 
                                                                             & vlTOPp->fmul__DOT__mantissa)) {
                                                                            vlTOPp->fmul__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fmul__DOT__mantissa 
                                                                                << 0x13U));
                                                                            vlTOPp->fmul__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                                                - (IData)(0x12U)));
                                                                        } else {
                                                                            if (
                                                                                (0x10U 
                                                                                & vlTOPp->fmul__DOT__mantissa)) {
                                                                                vlTOPp->fmul__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fmul__DOT__mantissa 
                                                                                << 0x14U));
                                                                                vlTOPp->fmul__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                                                - (IData)(0x13U)));
                                                                            } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fmul__DOT__mantissa)) {
                                                                                vlTOPp->fmul__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fmul__DOT__mantissa 
                                                                                << 0x15U));
                                                                                vlTOPp->fmul__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fmul__DOT__mantissa)) {
                                                                                vlTOPp->fmul__DOT__mantissa 
                                                                                = 
                                                                                (0x7fffffU 
                                                                                & (vlTOPp->fmul__DOT__mantissa 
                                                                                << 0x16U));
                                                                                vlTOPp->fmul__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fmul__DOT__mantissa)) {
                                                                                vlTOPp->fmul__DOT__expF 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                                                - (IData)(0x16U)));
                                                                                vlTOPp->fmul__DOT__mantissa = 0U;
                                                                                } else {
                                                                                vlTOPp->fmul__DOT__expF = 0xffU;
                                                                                }
                                                                                }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->fmul__DOT__expF = (0xffU & ((IData)(1U) 
                                        + (IData)(vlTOPp->fmul__DOT__expF)));
    vlTOPp->fmul__DOT__mantissa = (0x7fffffU & (vlTOPp->fmul__DOT__mantissa 
                                                >> 1U));
    vlTOPp->fmul__DOT__expF = (0xffU & ((IData)(1U) 
                                        + (IData)(vlTOPp->fmul__DOT__expF)));
    vlTOPp->out_mul = ((0x80000000U & (vlTOPp->num1 
                                       ^ vlTOPp->num2)) 
                       | (((IData)(vlTOPp->fmul__DOT__expF) 
                           << 0x17U) | vlTOPp->fmul__DOT__mantissa));
}

void Vfmul::_eval(Vfmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul::_eval\n"); );
    Vfmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
}

VL_INLINE_OPT QData Vfmul::_change_request(Vfmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul::_change_request\n"); );
    Vfmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vfmul::_change_request_1(Vfmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul::_change_request_1\n"); );
    Vfmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vfmul::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul::_eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
