// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfsqrt.h for the primary calling header

#include "Vfsqrt.h"
#include "Vfsqrt__Syms.h"

//==========

void Vfsqrt::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfsqrt::eval\n"); );
    Vfsqrt__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vfsqrt* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("../fsqrt.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vfsqrt::_eval_initial_loop(Vfsqrt__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("../fsqrt.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vfsqrt::_combo__TOP__1(Vfsqrt__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt::_combo__TOP__1\n"); );
    Vfsqrt* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->fsqrt__DOT__shifted_num = ((IData)(0x3f800000U) 
                                       + vlTOPp->var1);
    vlTOPp->fsqrt__DOT__shifted_num = (vlTOPp->fsqrt__DOT__shifted_num 
                                       >> 1U);
    if ((0U == (IData)(vlTOPp->rm))) {
        if ((4U & vlTOPp->fsqrt__DOT__shifted_num)) {
            if ((0U == (3U & vlTOPp->fsqrt__DOT__shifted_num))) {
                if ((8U & vlTOPp->fsqrt__DOT__shifted_num)) {
                    vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck 
                        = (0x7fffffU & vlTOPp->fsqrt__DOT__shifted_num);
                    vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck 
                        = (0xffffffU & ((IData)(1U) 
                                        + vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck));
                    vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                        = ((0x800000U & vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck)
                            ? ((0x80000000U & vlTOPp->fsqrt__DOT__shifted_num) 
                               | ((0x7f800000U & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->fsqrt__DOT__shifted_num 
                                                    >> 0x17U)) 
                                                  << 0x17U)) 
                                  | (0x7fffffU & vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck)))
                            : ((0xff800000U & vlTOPp->fsqrt__DOT__shifted_num) 
                               | (0x7fffffU & vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck)));
                } else {
                    vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                        = vlTOPp->fsqrt__DOT__shifted_num;
                }
            } else {
                vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck 
                    = (0x7fffffU & vlTOPp->fsqrt__DOT__shifted_num);
                vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck 
                    = (0xffffffU & ((IData)(1U) + vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck));
                vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                    = ((0x800000U & vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck)
                        ? ((0x80000000U & vlTOPp->fsqrt__DOT__shifted_num) 
                           | ((0x7f800000U & (((IData)(1U) 
                                               + (vlTOPp->fsqrt__DOT__shifted_num 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                              | (0x7fffffU & vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck)))
                        : ((0xff800000U & vlTOPp->fsqrt__DOT__shifted_num) 
                           | (0x7fffffU & vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck)));
            }
        } else {
            vlTOPp->fsqrt__DOT__r0__DOT__rounded = vlTOPp->fsqrt__DOT__shifted_num;
        }
    } else {
        if ((1U == (IData)(vlTOPp->rm))) {
            vlTOPp->fsqrt__DOT__r0__DOT__i = VL_EXTENDS_II(32,8, 
                                                           (0xffU 
                                                            & ((vlTOPp->fsqrt__DOT__shifted_num 
                                                                >> 0x17U) 
                                                               - (IData)(0x7fU))));
            if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fsqrt__DOT__r0__DOT__i) 
                 & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fsqrt__DOT__r0__DOT__i))) {
                vlTOPp->fsqrt__DOT__r0__DOT__mask = 
                    ((0x16U >= vlTOPp->fsqrt__DOT__r0__DOT__i)
                      ? (0x7fffffU & (0x7fffffU >> vlTOPp->fsqrt__DOT__r0__DOT__i))
                      : 0U);
                vlTOPp->fsqrt__DOT__r0__DOT__mask = 
                    (0x7fffffU & (~ vlTOPp->fsqrt__DOT__r0__DOT__mask));
                vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                    = ((0xff800000U & vlTOPp->fsqrt__DOT__shifted_num) 
                       | (vlTOPp->fsqrt__DOT__shifted_num 
                          & vlTOPp->fsqrt__DOT__r0__DOT__mask));
            } else {
                vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                    = ((0U == vlTOPp->fsqrt__DOT__r0__DOT__i)
                        ? 0x3f800000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fsqrt__DOT__r0__DOT__i)
                                          ? vlTOPp->fsqrt__DOT__shifted_num
                                          : 0U));
            }
        } else {
            if ((2U == (IData)(vlTOPp->rm))) {
                if ((0x80000000U & vlTOPp->fsqrt__DOT__shifted_num)) {
                    vlTOPp->fsqrt__DOT__r0__DOT__i 
                        = VL_EXTENDS_II(32,8, (0xffU 
                                               & ((vlTOPp->fsqrt__DOT__shifted_num 
                                                   >> 0x17U) 
                                                  - (IData)(0x7fU))));
                    if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fsqrt__DOT__r0__DOT__i) 
                         & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fsqrt__DOT__r0__DOT__i))) {
                        vlTOPp->fsqrt__DOT__r0__DOT__mask 
                            = ((0x16U >= vlTOPp->fsqrt__DOT__r0__DOT__i)
                                ? (0x7fffffU & (0x7fffffU 
                                                >> vlTOPp->fsqrt__DOT__r0__DOT__i))
                                : 0U);
                        vlTOPp->fsqrt__DOT__r0__DOT__mask2 
                            = ((0x16U >= (vlTOPp->fsqrt__DOT__r0__DOT__i 
                                          - (IData)(1U)))
                                ? (0x7fffffU & (0x400000U 
                                                >> 
                                                (vlTOPp->fsqrt__DOT__r0__DOT__i 
                                                 - (IData)(1U))))
                                : 0U);
                        vlTOPp->fsqrt__DOT__r0__DOT__mask 
                            = (0x7fffffU & (~ vlTOPp->fsqrt__DOT__r0__DOT__mask));
                        vlTOPp->fsqrt__DOT__r0__DOT__mask 
                            = (vlTOPp->fsqrt__DOT__shifted_num 
                               & vlTOPp->fsqrt__DOT__r0__DOT__mask);
                        vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck 
                            = vlTOPp->fsqrt__DOT__r0__DOT__mask;
                        vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck 
                            = (0xffffffU & (vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck 
                                            + vlTOPp->fsqrt__DOT__r0__DOT__mask2));
                        vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                            = ((0x800000U & vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck)
                                ? ((0x80000000U & vlTOPp->fsqrt__DOT__shifted_num) 
                                   | ((0x7f800000U 
                                       & (((IData)(1U) 
                                           + (vlTOPp->fsqrt__DOT__shifted_num 
                                              >> 0x17U)) 
                                          << 0x17U)) 
                                      | (0x7fffffU 
                                         & vlTOPp->fsqrt__DOT__shifted_num)))
                                : ((0xff800000U & vlTOPp->fsqrt__DOT__shifted_num) 
                                   | (0x7fffffU & vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck)));
                    } else {
                        vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                            = ((0U == vlTOPp->fsqrt__DOT__r0__DOT__i)
                                ? 0x40000000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fsqrt__DOT__r0__DOT__i)
                                                  ? vlTOPp->fsqrt__DOT__shifted_num
                                                  : 0U));
                    }
                } else {
                    vlTOPp->fsqrt__DOT__r0__DOT__i 
                        = VL_EXTENDS_II(32,8, (0xffU 
                                               & ((vlTOPp->fsqrt__DOT__shifted_num 
                                                   >> 0x17U) 
                                                  - (IData)(0x7fU))));
                    if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fsqrt__DOT__r0__DOT__i) 
                         & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fsqrt__DOT__r0__DOT__i))) {
                        vlTOPp->fsqrt__DOT__r0__DOT__mask 
                            = ((0x16U >= vlTOPp->fsqrt__DOT__r0__DOT__i)
                                ? (0x7fffffU & (0x7fffffU 
                                                >> vlTOPp->fsqrt__DOT__r0__DOT__i))
                                : 0U);
                        vlTOPp->fsqrt__DOT__r0__DOT__mask 
                            = (0x7fffffU & (~ vlTOPp->fsqrt__DOT__r0__DOT__mask));
                        vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                            = ((0xff800000U & vlTOPp->fsqrt__DOT__shifted_num) 
                               | (vlTOPp->fsqrt__DOT__shifted_num 
                                  & vlTOPp->fsqrt__DOT__r0__DOT__mask));
                    } else {
                        vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                            = ((0U == vlTOPp->fsqrt__DOT__r0__DOT__i)
                                ? 0x3f800000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fsqrt__DOT__r0__DOT__i)
                                                  ? vlTOPp->fsqrt__DOT__shifted_num
                                                  : 0U));
                    }
                }
            } else {
                if ((3U == (IData)(vlTOPp->rm))) {
                    if ((0x80000000U & vlTOPp->fsqrt__DOT__shifted_num)) {
                        vlTOPp->fsqrt__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fsqrt__DOT__shifted_num 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fsqrt__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fsqrt__DOT__r0__DOT__i))) {
                            vlTOPp->fsqrt__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fsqrt__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fsqrt__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fsqrt__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fsqrt__DOT__r0__DOT__mask));
                            vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                                = ((0xff800000U & vlTOPp->fsqrt__DOT__shifted_num) 
                                   | (vlTOPp->fsqrt__DOT__shifted_num 
                                      & vlTOPp->fsqrt__DOT__r0__DOT__mask));
                        } else {
                            vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fsqrt__DOT__r0__DOT__i)
                                    ? 0x3f800000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fsqrt__DOT__r0__DOT__i)
                                     ? vlTOPp->fsqrt__DOT__shifted_num
                                     : 0U));
                        }
                    } else {
                        vlTOPp->fsqrt__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fsqrt__DOT__shifted_num 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fsqrt__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fsqrt__DOT__r0__DOT__i))) {
                            vlTOPp->fsqrt__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fsqrt__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fsqrt__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fsqrt__DOT__r0__DOT__mask2 
                                = ((0x16U >= (vlTOPp->fsqrt__DOT__r0__DOT__i 
                                              - (IData)(1U)))
                                    ? (0x7fffffU & 
                                       (0x400000U >> 
                                        (vlTOPp->fsqrt__DOT__r0__DOT__i 
                                         - (IData)(1U))))
                                    : 0U);
                            vlTOPp->fsqrt__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fsqrt__DOT__r0__DOT__mask));
                            vlTOPp->fsqrt__DOT__r0__DOT__mask 
                                = (vlTOPp->fsqrt__DOT__shifted_num 
                                   & vlTOPp->fsqrt__DOT__r0__DOT__mask);
                            vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck 
                                = vlTOPp->fsqrt__DOT__r0__DOT__mask;
                            vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck 
                                = (0xffffffU & (vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck 
                                                + vlTOPp->fsqrt__DOT__r0__DOT__mask2));
                            vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                                = ((0x800000U & vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck)
                                    ? ((0x80000000U 
                                        & vlTOPp->fsqrt__DOT__shifted_num) 
                                       | ((0x7f800000U 
                                           & (((IData)(1U) 
                                               + (vlTOPp->fsqrt__DOT__shifted_num 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                                          | (0x7fffffU 
                                             & vlTOPp->fsqrt__DOT__shifted_num)))
                                    : ((0xff800000U 
                                        & vlTOPp->fsqrt__DOT__shifted_num) 
                                       | (0x7fffffU 
                                          & vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck)));
                        } else {
                            vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fsqrt__DOT__r0__DOT__i)
                                    ? 0x40000000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fsqrt__DOT__r0__DOT__i)
                                     ? vlTOPp->fsqrt__DOT__shifted_num
                                     : 0U));
                        }
                    }
                } else {
                    if ((4U == (IData)(vlTOPp->rm))) {
                        vlTOPp->fsqrt__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fsqrt__DOT__shifted_num 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fsqrt__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fsqrt__DOT__r0__DOT__i))) {
                            vlTOPp->fsqrt__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fsqrt__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fsqrt__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fsqrt__DOT__r0__DOT__mask2 
                                = ((0x16U >= (vlTOPp->fsqrt__DOT__r0__DOT__i 
                                              - (IData)(1U)))
                                    ? (0x7fffffU & 
                                       (0x400000U >> 
                                        (vlTOPp->fsqrt__DOT__r0__DOT__i 
                                         - (IData)(1U))))
                                    : 0U);
                            vlTOPp->fsqrt__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fsqrt__DOT__r0__DOT__mask));
                            vlTOPp->fsqrt__DOT__r0__DOT__mask 
                                = (vlTOPp->fsqrt__DOT__shifted_num 
                                   & vlTOPp->fsqrt__DOT__r0__DOT__mask);
                            vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck 
                                = vlTOPp->fsqrt__DOT__r0__DOT__mask;
                            vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck 
                                = (0xffffffU & (vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck 
                                                + vlTOPp->fsqrt__DOT__r0__DOT__mask2));
                            vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                                = ((0x800000U & vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck)
                                    ? ((0x80000000U 
                                        & vlTOPp->fsqrt__DOT__shifted_num) 
                                       | ((0x7f800000U 
                                           & (((IData)(1U) 
                                               + (vlTOPp->fsqrt__DOT__shifted_num 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                                          | (0x7fffffU 
                                             & vlTOPp->fsqrt__DOT__shifted_num)))
                                    : ((0xff800000U 
                                        & vlTOPp->fsqrt__DOT__shifted_num) 
                                       | (0x7fffffU 
                                          & vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck)));
                        } else {
                            vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fsqrt__DOT__r0__DOT__i)
                                    ? 0x40000000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fsqrt__DOT__r0__DOT__i)
                                     ? vlTOPp->fsqrt__DOT__shifted_num
                                     : 0U));
                        }
                    } else {
                        if ((4U & vlTOPp->fsqrt__DOT__shifted_num)) {
                            if ((0U == (3U & vlTOPp->fsqrt__DOT__shifted_num))) {
                                if ((8U & vlTOPp->fsqrt__DOT__shifted_num)) {
                                    vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck 
                                        = (0x7fffffU 
                                           & vlTOPp->fsqrt__DOT__shifted_num);
                                    vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck 
                                        = (0xffffffU 
                                           & ((IData)(1U) 
                                              + vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck));
                                    vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                                        = ((0x800000U 
                                            & vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck)
                                            ? ((0x80000000U 
                                                & vlTOPp->fsqrt__DOT__shifted_num) 
                                               | ((0x7f800000U 
                                                   & (((IData)(1U) 
                                                       + 
                                                       (vlTOPp->fsqrt__DOT__shifted_num 
                                                        >> 0x17U)) 
                                                      << 0x17U)) 
                                                  | (0x7fffffU 
                                                     & vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck)))
                                            : ((0xff800000U 
                                                & vlTOPp->fsqrt__DOT__shifted_num) 
                                               | (0x7fffffU 
                                                  & vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck)));
                                } else {
                                    vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                                        = vlTOPp->fsqrt__DOT__shifted_num;
                                }
                            } else {
                                vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck 
                                    = (0x7fffffU & vlTOPp->fsqrt__DOT__shifted_num);
                                vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck 
                                    = (0xffffffU & 
                                       ((IData)(1U) 
                                        + vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck));
                                vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                                    = ((0x800000U & vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck)
                                        ? ((0x80000000U 
                                            & vlTOPp->fsqrt__DOT__shifted_num) 
                                           | ((0x7f800000U 
                                               & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->fsqrt__DOT__shifted_num 
                                                    >> 0x17U)) 
                                                  << 0x17U)) 
                                              | (0x7fffffU 
                                                 & vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck)))
                                        : ((0xff800000U 
                                            & vlTOPp->fsqrt__DOT__shifted_num) 
                                           | (0x7fffffU 
                                              & vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck)));
                            }
                        } else {
                            vlTOPp->fsqrt__DOT__r0__DOT__rounded 
                                = vlTOPp->fsqrt__DOT__shifted_num;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->res = vlTOPp->fsqrt__DOT__r0__DOT__rounded;
}

void Vfsqrt::_eval(Vfsqrt__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt::_eval\n"); );
    Vfsqrt* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
}

VL_INLINE_OPT QData Vfsqrt::_change_request(Vfsqrt__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt::_change_request\n"); );
    Vfsqrt* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vfsqrt::_change_request_1(Vfsqrt__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt::_change_request_1\n"); );
    Vfsqrt* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->fsqrt__DOT__shifted_num ^ vlTOPp->__Vchglast__TOP__fsqrt__DOT__shifted_num));
    VL_DEBUG_IF( if(__req && ((vlTOPp->fsqrt__DOT__shifted_num ^ vlTOPp->__Vchglast__TOP__fsqrt__DOT__shifted_num))) VL_DBG_MSGF("        CHANGE: ../fsqrt.sv:13: fsqrt.shifted_num\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__fsqrt__DOT__shifted_num 
        = vlTOPp->fsqrt__DOT__shifted_num;
    return __req;
}

#ifdef VL_DEBUG
void Vfsqrt::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((rm & 0xf8U))) {
        Verilated::overWidthError("rm");}
}
#endif  // VL_DEBUG
