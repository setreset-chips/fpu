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
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("fadd.sv", 1, "",
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
            VL_FATAL_MT("fadd.sv", 1, "",
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
    vlTOPp->fadd__DOT__num1Mant = (0x800000U | (0x7fffffU 
                                                & vlTOPp->num1));
    vlTOPp->fadd__DOT__num2Mant = (0x800000U | (0x7fffffU 
                                                & vlTOPp->num2));
    if (((IData)(vlTOPp->fadd__DOT__num1Exp) < (IData)(vlTOPp->fadd__DOT__num2Exp))) {
        vlTOPp->fadd__DOT__finalExp = vlTOPp->fadd__DOT__num2Exp;
        vlTOPp->fadd__DOT__num1Mant = ((0x17U >= (0xffU 
                                                  & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                     - (IData)(vlTOPp->fadd__DOT__num2Exp))))
                                        ? (0xffffffU 
                                           & (vlTOPp->fadd__DOT__num1Mant 
                                              >> (0xffU 
                                                  & ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                                     - (IData)(vlTOPp->fadd__DOT__num2Exp)))))
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
        vlTOPp->fadd__DOT__finalExp = (0xffU & ((IData)(1U) 
                                                + (IData)(vlTOPp->fadd__DOT__finalExp)));
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
                                               & ((IData)(1U) 
                                                  + (IData)(vlTOPp->fadd__DOT__finalExp)));
                vlTOPp->fadd__DOT__finalSign = 1U;
                vlTOPp->fadd__DOT__finalMant = (0xffffffU 
                                                & (vlTOPp->fadd__DOT__sumMants 
                                                   >> 1U));
            }
        }
    }
    vlTOPp->fadd__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x17U, vlTOPp->fadd__DOT__i)) {
        if ((0x800000U & vlTOPp->fadd__DOT__finalMant)) {
            vlTOPp->fadd__DOT__i = 0x17U;
        } else {
            vlTOPp->fadd__DOT__finalMant = (0xffffffU 
                                            & (vlTOPp->fadd__DOT__finalMant 
                                               << 1U));
            vlTOPp->fadd__DOT__finalExp = (0xffU & 
                                           ((IData)(vlTOPp->fadd__DOT__finalExp) 
                                            - (IData)(1U)));
        }
        vlTOPp->fadd__DOT__i = ((IData)(1U) + vlTOPp->fadd__DOT__i);
    }
    vlTOPp->fadd__DOT__finalMant = (0xffffffU & (vlTOPp->fadd__DOT__finalMant 
                                                 << 1U));
    if (((0U == vlTOPp->num1) & (0U == (IData)(vlTOPp->fadd__DOT__num2Exp)))) {
        vlTOPp->fadd__DOT__finalMant = 0U;
        vlTOPp->fadd__DOT__finalExp = 0U;
    }
    vlTOPp->out_num = ((0x80000000U & ((~ (IData)(vlTOPp->fadd__DOT__finalSign)) 
                                       << 0x1fU)) | 
                       (((IData)(vlTOPp->fadd__DOT__finalExp) 
                         << 0x17U) | (0x7fffffU & (vlTOPp->fadd__DOT__finalMant 
                                                   >> 1U))));
}

void Vfadd::_eval(Vfadd__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd::_eval\n"); );
    Vfadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
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
}
#endif  // VL_DEBUG
