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
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("fln.sv", 2, "",
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
            VL_FATAL_MT("fln.sv", 2, "",
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
                                                     - (IData)(vlTOPp->fln__DOT__fa0__DOT__num2Exp))))
                                                 ? 
                                                (0xffffffU 
                                                 & (vlTOPp->fln__DOT__fa0__DOT__num1Mant 
                                                    >> 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                                        - (IData)(vlTOPp->fln__DOT__fa0__DOT__num2Exp)))))
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
                                               + vlTOPp->fln__DOT__fa0__DOT__num1Mant));
    vlTOPp->fln__DOT__fa0__DOT__finalExp = (0xffU & 
                                            ((IData)(1U) 
                                             + (IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp)));
    vlTOPp->fln__DOT__fa0__DOT__finalSign = 1U;
    vlTOPp->fln__DOT__fa0__DOT__finalMant = (0xffffffU 
                                             & (vlTOPp->fln__DOT__fa0__DOT__sumMants 
                                                >> 1U));
    vlTOPp->fln__DOT__fa0__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x17U, vlTOPp->fln__DOT__fa0__DOT__i)) {
        if ((0x800000U & vlTOPp->fln__DOT__fa0__DOT__finalMant)) {
            vlTOPp->fln__DOT__fa0__DOT__i = 0x17U;
        } else {
            vlTOPp->fln__DOT__fa0__DOT__finalMant = 
                (0xffffffU & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                              << 1U));
            vlTOPp->fln__DOT__fa0__DOT__finalExp = 
                (0xffU & ((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                          - (IData)(1U)));
        }
        vlTOPp->fln__DOT__fa0__DOT__i = ((IData)(1U) 
                                         + vlTOPp->fln__DOT__fa0__DOT__i);
    }
    vlTOPp->fln__DOT__fa0__DOT__finalMant = (0xffffffU 
                                             & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                << 1U));
    if (((0U == (0x7fffffffU & vlTOPp->num1)) & (0U 
                                                 == (IData)(vlTOPp->fln__DOT__fa0__DOT__num2Exp)))) {
        vlTOPp->fln__DOT__fa0__DOT__finalMant = 0U;
        vlTOPp->fln__DOT__fa0__DOT__finalExp = 0U;
    }
    vlTOPp->fln__DOT__op1i = ((0x80000000U & ((~ (IData)(vlTOPp->fln__DOT__fa0__DOT__finalSign)) 
                                              << 0x1fU)) 
                              | (((IData)(vlTOPp->fln__DOT__fa0__DOT__finalExp) 
                                  << 0x17U) | (0x7fffffU 
                                               & (vlTOPp->fln__DOT__fa0__DOT__finalMant 
                                                  >> 1U))));
    vlTOPp->fln__DOT__fi0__DOT__f1__DOT__mantissaProd 
        = (0xffffffffffffULL & ((QData)((IData)((0x800000U 
                                                 | (0x7fffffU 
                                                    & (((IData)(0xbe6eb3beU) 
                                                        - vlTOPp->fln__DOT__op1i) 
                                                       >> 1U))))) 
                                * (QData)((IData)((0x800000U 
                                                   | (0x7fffffU 
                                                      & (((IData)(0xbe6eb3beU) 
                                                          - vlTOPp->fln__DOT__op1i) 
                                                         >> 1U)))))));
    vlTOPp->fln__DOT__fi0__DOT__f1__DOT__expF = (0xffU 
                                                 & (((((IData)(0xbe6eb3beU) 
                                                       - vlTOPp->fln__DOT__op1i) 
                                                      >> 0x18U) 
                                                     + 
                                                     (((IData)(0xbe6eb3beU) 
                                                       - vlTOPp->fln__DOT__op1i) 
                                                      >> 0x18U)) 
                                                    - (IData)(0x7fU)));
    vlTOPp->fln__DOT__fi0__DOT__f1__DOT__mantissa = 
        (0x7fffffU & (IData)((vlTOPp->fln__DOT__fi0__DOT__f1__DOT__mantissaProd 
                              >> 0x19U)));
    vlTOPp->fln__DOT__fi0__DOT__f1__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x17U, vlTOPp->fln__DOT__fi0__DOT__f1__DOT__i)) {
        if ((0x400000U & vlTOPp->fln__DOT__fi0__DOT__f1__DOT__mantissa)) {
            vlTOPp->fln__DOT__fi0__DOT__f1__DOT__i = 0x17U;
        } else {
            vlTOPp->fln__DOT__fi0__DOT__f1__DOT__mantissa 
                = (0x7fffffU & (vlTOPp->fln__DOT__fi0__DOT__f1__DOT__mantissa 
                                << 1U));
            vlTOPp->fln__DOT__fi0__DOT__f1__DOT__expF 
                = (0xffU & ((IData)(vlTOPp->fln__DOT__fi0__DOT__f1__DOT__expF) 
                            - (IData)(1U)));
            vlTOPp->fln__DOT__fi0__DOT__f1__DOT__mantissa 
                = ((0x7ffffeU & vlTOPp->fln__DOT__fi0__DOT__f1__DOT__mantissa) 
                   | (1U & (IData)((vlTOPp->fln__DOT__fi0__DOT__f1__DOT__mantissaProd 
                                    >> 0x18U))));
            vlTOPp->fln__DOT__fi0__DOT__f1__DOT__mantissaProd 
                = (0xffffffffffffULL & (vlTOPp->fln__DOT__fi0__DOT__f1__DOT__mantissaProd 
                                        << 1U));
        }
        vlTOPp->fln__DOT__fi0__DOT__f1__DOT__i = ((IData)(1U) 
                                                  + vlTOPp->fln__DOT__fi0__DOT__f1__DOT__i);
    }
    vlTOPp->fln__DOT__fi0__DOT__f1__DOT__mantissa = 
        (0x7fffffU & (vlTOPp->fln__DOT__fi0__DOT__f1__DOT__mantissa 
                      << 1U));
    vlTOPp->fln__DOT__fi0__DOT__f1__DOT__expF = (0xffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlTOPp->fln__DOT__fi0__DOT__f1__DOT__expF)));
    vlTOPp->fln__DOT__fi0__DOT__f1__DOT__mantissa = 
        ((0x7ffffeU & vlTOPp->fln__DOT__fi0__DOT__f1__DOT__mantissa) 
         | (1U & (IData)((vlTOPp->fln__DOT__fi0__DOT__f1__DOT__mantissaProd 
                          >> 0x18U))));
    vlTOPp->fln__DOT__temp1 = (((IData)(vlTOPp->fln__DOT__fi0__DOT__f1__DOT__expF) 
                                << 0x17U) | vlTOPp->fln__DOT__fi0__DOT__f1__DOT__mantissa);
    vlTOPp->fln__DOT__fm0__DOT__mantissaProd = (0xffffffffffffULL 
                                                & ((QData)((IData)(
                                                                   (0x800000U 
                                                                    | (0x7fffffU 
                                                                       & vlTOPp->fln__DOT__temp1)))) 
                                                   * (QData)((IData)(
                                                                     (0x800000U 
                                                                      | (0x7fffffU 
                                                                         & vlTOPp->fln__DOT__temp1))))));
    vlTOPp->fln__DOT__fm0__DOT__expF = (0xffU & (((vlTOPp->fln__DOT__temp1 
                                                   >> 0x17U) 
                                                  + 
                                                  (vlTOPp->fln__DOT__temp1 
                                                   >> 0x17U)) 
                                                 - (IData)(0x7fU)));
    vlTOPp->fln__DOT__fm0__DOT__mantissa = (0x7fffffU 
                                            & (IData)(
                                                      (vlTOPp->fln__DOT__fm0__DOT__mantissaProd 
                                                       >> 0x19U)));
    vlTOPp->fln__DOT__fm0__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x17U, vlTOPp->fln__DOT__fm0__DOT__i)) {
        if ((0x400000U & vlTOPp->fln__DOT__fm0__DOT__mantissa)) {
            vlTOPp->fln__DOT__fm0__DOT__i = 0x17U;
        } else {
            vlTOPp->fln__DOT__fm0__DOT__mantissa = 
                (0x7fffffU & (vlTOPp->fln__DOT__fm0__DOT__mantissa 
                              << 1U));
            vlTOPp->fln__DOT__fm0__DOT__expF = (0xffU 
                                                & ((IData)(vlTOPp->fln__DOT__fm0__DOT__expF) 
                                                   - (IData)(1U)));
            vlTOPp->fln__DOT__fm0__DOT__mantissa = 
                ((0x7ffffeU & vlTOPp->fln__DOT__fm0__DOT__mantissa) 
                 | (1U & (IData)((vlTOPp->fln__DOT__fm0__DOT__mantissaProd 
                                  >> 0x18U))));
            vlTOPp->fln__DOT__fm0__DOT__mantissaProd 
                = (0xffffffffffffULL & (vlTOPp->fln__DOT__fm0__DOT__mantissaProd 
                                        << 1U));
        }
        vlTOPp->fln__DOT__fm0__DOT__i = ((IData)(1U) 
                                         + vlTOPp->fln__DOT__fm0__DOT__i);
    }
    vlTOPp->fln__DOT__fm0__DOT__mantissa = (0x7fffffU 
                                            & (vlTOPp->fln__DOT__fm0__DOT__mantissa 
                                               << 1U));
    vlTOPp->fln__DOT__fm0__DOT__expF = (0xffU & ((IData)(1U) 
                                                 + (IData)(vlTOPp->fln__DOT__fm0__DOT__expF)));
    vlTOPp->fln__DOT__fm0__DOT__mantissa = ((0x7ffffeU 
                                             & vlTOPp->fln__DOT__fm0__DOT__mantissa) 
                                            | (1U & (IData)(
                                                            (vlTOPp->fln__DOT__fm0__DOT__mantissaProd 
                                                             >> 0x18U))));
    vlTOPp->fln__DOT__temp2 = (((IData)(vlTOPp->fln__DOT__fm0__DOT__expF) 
                                << 0x17U) | vlTOPp->fln__DOT__fm0__DOT__mantissa);
    vlTOPp->fln__DOT____Vcellinp__fa1____pinNumber2 
        = ((0x80000000U & ((~ (vlTOPp->fln__DOT__temp2 
                               >> 0x1fU)) << 0x1fU)) 
           | (0x7fffffffU & vlTOPp->fln__DOT__temp2));
    vlTOPp->fln__DOT__fm1__DOT__mantissaProd = (0xffffffffffffULL 
                                                & ((QData)((IData)(
                                                                   (0x800000U 
                                                                    | (0x7fffffU 
                                                                       & vlTOPp->fln__DOT__temp1)))) 
                                                   * (QData)((IData)(
                                                                     (0x800000U 
                                                                      | (0x7fffffU 
                                                                         & vlTOPp->fln__DOT__temp2))))));
    vlTOPp->fln__DOT__fm1__DOT__expF = (0xffU & (((vlTOPp->fln__DOT__temp1 
                                                   >> 0x17U) 
                                                  + 
                                                  (vlTOPp->fln__DOT__temp2 
                                                   >> 0x17U)) 
                                                 - (IData)(0x7fU)));
    vlTOPp->fln__DOT__fm1__DOT__mantissa = (0x7fffffU 
                                            & (IData)(
                                                      (vlTOPp->fln__DOT__fm1__DOT__mantissaProd 
                                                       >> 0x19U)));
    vlTOPp->fln__DOT__fm1__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x17U, vlTOPp->fln__DOT__fm1__DOT__i)) {
        if ((0x400000U & vlTOPp->fln__DOT__fm1__DOT__mantissa)) {
            vlTOPp->fln__DOT__fm1__DOT__i = 0x17U;
        } else {
            vlTOPp->fln__DOT__fm1__DOT__mantissa = 
                (0x7fffffU & (vlTOPp->fln__DOT__fm1__DOT__mantissa 
                              << 1U));
            vlTOPp->fln__DOT__fm1__DOT__expF = (0xffU 
                                                & ((IData)(vlTOPp->fln__DOT__fm1__DOT__expF) 
                                                   - (IData)(1U)));
            vlTOPp->fln__DOT__fm1__DOT__mantissa = 
                ((0x7ffffeU & vlTOPp->fln__DOT__fm1__DOT__mantissa) 
                 | (1U & (IData)((vlTOPp->fln__DOT__fm1__DOT__mantissaProd 
                                  >> 0x18U))));
            vlTOPp->fln__DOT__fm1__DOT__mantissaProd 
                = (0xffffffffffffULL & (vlTOPp->fln__DOT__fm1__DOT__mantissaProd 
                                        << 1U));
        }
        vlTOPp->fln__DOT__fm1__DOT__i = ((IData)(1U) 
                                         + vlTOPp->fln__DOT__fm1__DOT__i);
    }
    vlTOPp->fln__DOT__fm1__DOT__mantissa = (0x7fffffU 
                                            & (vlTOPp->fln__DOT__fm1__DOT__mantissa 
                                               << 1U));
    vlTOPp->fln__DOT__fm1__DOT__expF = (0xffU & ((IData)(1U) 
                                                 + (IData)(vlTOPp->fln__DOT__fm1__DOT__expF)));
    vlTOPp->fln__DOT__fm1__DOT__mantissa = ((0x7ffffeU 
                                             & vlTOPp->fln__DOT__fm1__DOT__mantissa) 
                                            | (1U & (IData)(
                                                            (vlTOPp->fln__DOT__fm1__DOT__mantissaProd 
                                                             >> 0x18U))));
    vlTOPp->fln__DOT__temp3i = ((0x80000000U & (vlTOPp->fln__DOT__temp1 
                                                ^ vlTOPp->fln__DOT__temp2)) 
                                | (((IData)(vlTOPp->fln__DOT__fm1__DOT__expF) 
                                    << 0x17U) | vlTOPp->fln__DOT__fm1__DOT__mantissa));
    vlTOPp->fln__DOT__fa1__DOT__finalSign = 0U;
    vlTOPp->fln__DOT__fa1__DOT__largerMag = 0U;
    vlTOPp->fln__DOT__fa1__DOT__num1Exp = (0xffU & 
                                           (vlTOPp->fln__DOT__temp1 
                                            >> 0x17U));
    vlTOPp->fln__DOT__fa1__DOT__num2Exp = (0xffU & 
                                           (vlTOPp->fln__DOT____Vcellinp__fa1____pinNumber2 
                                            >> 0x17U));
    vlTOPp->fln__DOT__fa1__DOT__num1Mant = (0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->fln__DOT__temp1));
    vlTOPp->fln__DOT__fa1__DOT__num2Mant = (0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->fln__DOT____Vcellinp__fa1____pinNumber2));
    if (((IData)(vlTOPp->fln__DOT__fa1__DOT__num1Exp) 
         < (IData)(vlTOPp->fln__DOT__fa1__DOT__num2Exp))) {
        vlTOPp->fln__DOT__fa1__DOT__finalExp = vlTOPp->fln__DOT__fa1__DOT__num2Exp;
        vlTOPp->fln__DOT__fa1__DOT__num1Mant = ((0x17U 
                                                 >= 
                                                 (0xffU 
                                                  & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                     - (IData)(vlTOPp->fln__DOT__fa1__DOT__num2Exp))))
                                                 ? 
                                                (0xffffffU 
                                                 & (vlTOPp->fln__DOT__fa1__DOT__num1Mant 
                                                    >> 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                                        - (IData)(vlTOPp->fln__DOT__fa1__DOT__num2Exp)))))
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
    if ((0x80000000U & (vlTOPp->fln__DOT__temp1 & vlTOPp->fln__DOT____Vcellinp__fa1____pinNumber2))) {
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
        if ((1U & ((vlTOPp->fln__DOT__temp1 >> 0x1fU) 
                   & (~ (vlTOPp->fln__DOT____Vcellinp__fa1____pinNumber2 
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
            if ((1U & ((~ (vlTOPp->fln__DOT__temp1 
                           >> 0x1fU)) & (vlTOPp->fln__DOT____Vcellinp__fa1____pinNumber2 
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
    vlTOPp->fln__DOT__fa1__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x17U, vlTOPp->fln__DOT__fa1__DOT__i)) {
        if ((0x800000U & vlTOPp->fln__DOT__fa1__DOT__finalMant)) {
            vlTOPp->fln__DOT__fa1__DOT__i = 0x17U;
        } else {
            vlTOPp->fln__DOT__fa1__DOT__finalMant = 
                (0xffffffU & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                              << 1U));
            vlTOPp->fln__DOT__fa1__DOT__finalExp = 
                (0xffU & ((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                          - (IData)(1U)));
        }
        vlTOPp->fln__DOT__fa1__DOT__i = ((IData)(1U) 
                                         + vlTOPp->fln__DOT__fa1__DOT__i);
    }
    vlTOPp->fln__DOT__fa1__DOT__finalMant = (0xffffffU 
                                             & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                << 1U));
    if (((0U == vlTOPp->fln__DOT__temp1) & (0U == (IData)(vlTOPp->fln__DOT__fa1__DOT__num2Exp)))) {
        vlTOPp->fln__DOT__fa1__DOT__finalMant = 0U;
        vlTOPp->fln__DOT__fa1__DOT__finalExp = 0U;
    }
    vlTOPp->fln__DOT__fm5__DOT__mantissaProd = (0xffffffffffffULL 
                                                & ((QData)((IData)(
                                                                   (0x800000U 
                                                                    | (0x7fffffU 
                                                                       & vlTOPp->fln__DOT__temp3i)))) 
                                                   * (QData)((IData)(
                                                                     (0x800000U 
                                                                      | (0x7fffffU 
                                                                         & vlTOPp->fln__DOT__temp2))))));
    vlTOPp->fln__DOT__fm5__DOT__expF = (0xffU & (((vlTOPp->fln__DOT__temp3i 
                                                   >> 0x17U) 
                                                  + 
                                                  (vlTOPp->fln__DOT__temp2 
                                                   >> 0x17U)) 
                                                 - (IData)(0x7fU)));
    vlTOPp->fln__DOT__fm5__DOT__mantissa = (0x7fffffU 
                                            & (IData)(
                                                      (vlTOPp->fln__DOT__fm5__DOT__mantissaProd 
                                                       >> 0x19U)));
    vlTOPp->fln__DOT__fm5__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x17U, vlTOPp->fln__DOT__fm5__DOT__i)) {
        if ((0x400000U & vlTOPp->fln__DOT__fm5__DOT__mantissa)) {
            vlTOPp->fln__DOT__fm5__DOT__i = 0x17U;
        } else {
            vlTOPp->fln__DOT__fm5__DOT__mantissa = 
                (0x7fffffU & (vlTOPp->fln__DOT__fm5__DOT__mantissa 
                              << 1U));
            vlTOPp->fln__DOT__fm5__DOT__expF = (0xffU 
                                                & ((IData)(vlTOPp->fln__DOT__fm5__DOT__expF) 
                                                   - (IData)(1U)));
            vlTOPp->fln__DOT__fm5__DOT__mantissa = 
                ((0x7ffffeU & vlTOPp->fln__DOT__fm5__DOT__mantissa) 
                 | (1U & (IData)((vlTOPp->fln__DOT__fm5__DOT__mantissaProd 
                                  >> 0x18U))));
            vlTOPp->fln__DOT__fm5__DOT__mantissaProd 
                = (0xffffffffffffULL & (vlTOPp->fln__DOT__fm5__DOT__mantissaProd 
                                        << 1U));
        }
        vlTOPp->fln__DOT__fm5__DOT__i = ((IData)(1U) 
                                         + vlTOPp->fln__DOT__fm5__DOT__i);
    }
    vlTOPp->fln__DOT__fm5__DOT__mantissa = (0x7fffffU 
                                            & (vlTOPp->fln__DOT__fm5__DOT__mantissa 
                                               << 1U));
    vlTOPp->fln__DOT__fm5__DOT__expF = (0xffU & ((IData)(1U) 
                                                 + (IData)(vlTOPp->fln__DOT__fm5__DOT__expF)));
    vlTOPp->fln__DOT__fm5__DOT__mantissa = ((0x7ffffeU 
                                             & vlTOPp->fln__DOT__fm5__DOT__mantissa) 
                                            | (1U & (IData)(
                                                            (vlTOPp->fln__DOT__fm5__DOT__mantissaProd 
                                                             >> 0x18U))));
    vlTOPp->fln__DOT__temp5i = ((0x80000000U & (vlTOPp->fln__DOT__temp3i 
                                                ^ vlTOPp->fln__DOT__temp2)) 
                                | (((IData)(vlTOPp->fln__DOT__fm5__DOT__expF) 
                                    << 0x17U) | vlTOPp->fln__DOT__fm5__DOT__mantissa));
    vlTOPp->fln__DOT__fm2__DOT__mantissaProd = (0xffffffffffffULL 
                                                & ((QData)((IData)(
                                                                   (0x800000U 
                                                                    | (0x7fffffU 
                                                                       & vlTOPp->fln__DOT__temp3i)))) 
                                                   << 0x17U));
    vlTOPp->fln__DOT__fm2__DOT__expF = (0xffU & ((IData)(1U) 
                                                 + 
                                                 (vlTOPp->fln__DOT__temp3i 
                                                  >> 0x17U)));
    vlTOPp->fln__DOT__fm2__DOT__mantissa = (0x7fffffU 
                                            & (IData)(
                                                      (vlTOPp->fln__DOT__fm2__DOT__mantissaProd 
                                                       >> 0x19U)));
    vlTOPp->fln__DOT__fm2__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x17U, vlTOPp->fln__DOT__fm2__DOT__i)) {
        if ((0x400000U & vlTOPp->fln__DOT__fm2__DOT__mantissa)) {
            vlTOPp->fln__DOT__fm2__DOT__i = 0x17U;
        } else {
            vlTOPp->fln__DOT__fm2__DOT__mantissa = 
                (0x7fffffU & (vlTOPp->fln__DOT__fm2__DOT__mantissa 
                              << 1U));
            vlTOPp->fln__DOT__fm2__DOT__expF = (0xffU 
                                                & ((IData)(vlTOPp->fln__DOT__fm2__DOT__expF) 
                                                   - (IData)(1U)));
            vlTOPp->fln__DOT__fm2__DOT__mantissa = 
                ((0x7ffffeU & vlTOPp->fln__DOT__fm2__DOT__mantissa) 
                 | (1U & (IData)((vlTOPp->fln__DOT__fm2__DOT__mantissaProd 
                                  >> 0x18U))));
            vlTOPp->fln__DOT__fm2__DOT__mantissaProd 
                = (0xffffffffffffULL & (vlTOPp->fln__DOT__fm2__DOT__mantissaProd 
                                        << 1U));
        }
        vlTOPp->fln__DOT__fm2__DOT__i = ((IData)(1U) 
                                         + vlTOPp->fln__DOT__fm2__DOT__i);
    }
    vlTOPp->fln__DOT__fm2__DOT__mantissa = (0x7fffffU 
                                            & (vlTOPp->fln__DOT__fm2__DOT__mantissa 
                                               << 1U));
    vlTOPp->fln__DOT__fm2__DOT__expF = (0xffU & ((IData)(1U) 
                                                 + (IData)(vlTOPp->fln__DOT__fm2__DOT__expF)));
    vlTOPp->fln__DOT__fm2__DOT__mantissa = ((0x7ffffeU 
                                             & vlTOPp->fln__DOT__fm2__DOT__mantissa) 
                                            | (1U & (IData)(
                                                            (vlTOPp->fln__DOT__fm2__DOT__mantissaProd 
                                                             >> 0x18U))));
    vlTOPp->fln__DOT__temp3 = ((0x80000000U & vlTOPp->fln__DOT__temp3i) 
                               | (((IData)(vlTOPp->fln__DOT__fm2__DOT__expF) 
                                   << 0x17U) | vlTOPp->fln__DOT__fm2__DOT__mantissa));
    vlTOPp->fln__DOT__fm3__DOT__mantissaProd = (0xffffffffffffULL 
                                                & ((QData)((IData)(
                                                                   (0x800000U 
                                                                    | (0x7fffffU 
                                                                       & vlTOPp->fln__DOT__temp3i)))) 
                                                   * (QData)((IData)(
                                                                     (0x800000U 
                                                                      | (0x7fffffU 
                                                                         & vlTOPp->fln__DOT__temp1))))));
    vlTOPp->fln__DOT__fm3__DOT__expF = (0xffU & (((vlTOPp->fln__DOT__temp3i 
                                                   >> 0x17U) 
                                                  + 
                                                  (vlTOPp->fln__DOT__temp1 
                                                   >> 0x17U)) 
                                                 - (IData)(0x7fU)));
    vlTOPp->fln__DOT__fm3__DOT__mantissa = (0x7fffffU 
                                            & (IData)(
                                                      (vlTOPp->fln__DOT__fm3__DOT__mantissaProd 
                                                       >> 0x19U)));
    vlTOPp->fln__DOT__fm3__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x17U, vlTOPp->fln__DOT__fm3__DOT__i)) {
        if ((0x400000U & vlTOPp->fln__DOT__fm3__DOT__mantissa)) {
            vlTOPp->fln__DOT__fm3__DOT__i = 0x17U;
        } else {
            vlTOPp->fln__DOT__fm3__DOT__mantissa = 
                (0x7fffffU & (vlTOPp->fln__DOT__fm3__DOT__mantissa 
                              << 1U));
            vlTOPp->fln__DOT__fm3__DOT__expF = (0xffU 
                                                & ((IData)(vlTOPp->fln__DOT__fm3__DOT__expF) 
                                                   - (IData)(1U)));
            vlTOPp->fln__DOT__fm3__DOT__mantissa = 
                ((0x7ffffeU & vlTOPp->fln__DOT__fm3__DOT__mantissa) 
                 | (1U & (IData)((vlTOPp->fln__DOT__fm3__DOT__mantissaProd 
                                  >> 0x18U))));
            vlTOPp->fln__DOT__fm3__DOT__mantissaProd 
                = (0xffffffffffffULL & (vlTOPp->fln__DOT__fm3__DOT__mantissaProd 
                                        << 1U));
        }
        vlTOPp->fln__DOT__fm3__DOT__i = ((IData)(1U) 
                                         + vlTOPp->fln__DOT__fm3__DOT__i);
    }
    vlTOPp->fln__DOT__fm3__DOT__mantissa = (0x7fffffU 
                                            & (vlTOPp->fln__DOT__fm3__DOT__mantissa 
                                               << 1U));
    vlTOPp->fln__DOT__fm3__DOT__expF = (0xffU & ((IData)(1U) 
                                                 + (IData)(vlTOPp->fln__DOT__fm3__DOT__expF)));
    vlTOPp->fln__DOT__fm3__DOT__mantissa = ((0x7ffffeU 
                                             & vlTOPp->fln__DOT__fm3__DOT__mantissa) 
                                            | (1U & (IData)(
                                                            (vlTOPp->fln__DOT__fm3__DOT__mantissaProd 
                                                             >> 0x18U))));
    vlTOPp->fln__DOT__temp4i = ((0x80000000U & (vlTOPp->fln__DOT__temp3i 
                                                ^ vlTOPp->fln__DOT__temp1)) 
                                | (((IData)(vlTOPp->fln__DOT__fm3__DOT__expF) 
                                    << 0x17U) | vlTOPp->fln__DOT__fm3__DOT__mantissa));
    vlTOPp->fln__DOT__temp6 = ((0x80000000U & ((~ (IData)(vlTOPp->fln__DOT__fa1__DOT__finalSign)) 
                                               << 0x1fU)) 
                               | (((IData)(vlTOPp->fln__DOT__fa1__DOT__finalExp) 
                                   << 0x17U) | (0x7fffffU 
                                                & (vlTOPp->fln__DOT__fa1__DOT__finalMant 
                                                   >> 1U))));
    vlTOPp->fln__DOT__fm6__DOT__mantissaProd = (0xffffffffffffULL 
                                                & (0xc00000ULL 
                                                   * (QData)((IData)(
                                                                     (0x800000U 
                                                                      | (0x7fffffU 
                                                                         & vlTOPp->fln__DOT__temp5i))))));
    vlTOPp->fln__DOT__fm6__DOT__expF = (0xffU & ((IData)(4U) 
                                                 + 
                                                 (vlTOPp->fln__DOT__temp5i 
                                                  >> 0x17U)));
    vlTOPp->fln__DOT__fm6__DOT__mantissa = (0x7fffffU 
                                            & (IData)(
                                                      (vlTOPp->fln__DOT__fm6__DOT__mantissaProd 
                                                       >> 0x19U)));
    vlTOPp->fln__DOT__fm6__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x17U, vlTOPp->fln__DOT__fm6__DOT__i)) {
        if ((0x400000U & vlTOPp->fln__DOT__fm6__DOT__mantissa)) {
            vlTOPp->fln__DOT__fm6__DOT__i = 0x17U;
        } else {
            vlTOPp->fln__DOT__fm6__DOT__mantissa = 
                (0x7fffffU & (vlTOPp->fln__DOT__fm6__DOT__mantissa 
                              << 1U));
            vlTOPp->fln__DOT__fm6__DOT__expF = (0xffU 
                                                & ((IData)(vlTOPp->fln__DOT__fm6__DOT__expF) 
                                                   - (IData)(1U)));
            vlTOPp->fln__DOT__fm6__DOT__mantissa = 
                ((0x7ffffeU & vlTOPp->fln__DOT__fm6__DOT__mantissa) 
                 | (1U & (IData)((vlTOPp->fln__DOT__fm6__DOT__mantissaProd 
                                  >> 0x18U))));
            vlTOPp->fln__DOT__fm6__DOT__mantissaProd 
                = (0xffffffffffffULL & (vlTOPp->fln__DOT__fm6__DOT__mantissaProd 
                                        << 1U));
        }
        vlTOPp->fln__DOT__fm6__DOT__i = ((IData)(1U) 
                                         + vlTOPp->fln__DOT__fm6__DOT__i);
    }
    vlTOPp->fln__DOT__fm6__DOT__mantissa = (0x7fffffU 
                                            & (vlTOPp->fln__DOT__fm6__DOT__mantissa 
                                               << 1U));
    vlTOPp->fln__DOT__fm6__DOT__expF = (0xffU & ((IData)(1U) 
                                                 + (IData)(vlTOPp->fln__DOT__fm6__DOT__expF)));
    vlTOPp->fln__DOT__fm6__DOT__mantissa = ((0x7ffffeU 
                                             & vlTOPp->fln__DOT__fm6__DOT__mantissa) 
                                            | (1U & (IData)(
                                                            (vlTOPp->fln__DOT__fm6__DOT__mantissaProd 
                                                             >> 0x18U))));
    vlTOPp->fln__DOT__temp5 = ((0x80000000U & vlTOPp->fln__DOT__temp5i) 
                               | (((IData)(vlTOPp->fln__DOT__fm6__DOT__expF) 
                                   << 0x17U) | vlTOPp->fln__DOT__fm6__DOT__mantissa));
    vlTOPp->fln__DOT__fm4__DOT__mantissaProd = (0xffffffffffffULL 
                                                & (0xc00000ULL 
                                                   * (QData)((IData)(
                                                                     (0x800000U 
                                                                      | (0x7fffffU 
                                                                         & vlTOPp->fln__DOT__temp4i))))));
    vlTOPp->fln__DOT__fm4__DOT__expF = (0xffU & ((IData)(2U) 
                                                 + 
                                                 (vlTOPp->fln__DOT__temp4i 
                                                  >> 0x17U)));
    vlTOPp->fln__DOT__fm4__DOT__mantissa = (0x7fffffU 
                                            & (IData)(
                                                      (vlTOPp->fln__DOT__fm4__DOT__mantissaProd 
                                                       >> 0x19U)));
    vlTOPp->fln__DOT__fm4__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x17U, vlTOPp->fln__DOT__fm4__DOT__i)) {
        if ((0x400000U & vlTOPp->fln__DOT__fm4__DOT__mantissa)) {
            vlTOPp->fln__DOT__fm4__DOT__i = 0x17U;
        } else {
            vlTOPp->fln__DOT__fm4__DOT__mantissa = 
                (0x7fffffU & (vlTOPp->fln__DOT__fm4__DOT__mantissa 
                              << 1U));
            vlTOPp->fln__DOT__fm4__DOT__expF = (0xffU 
                                                & ((IData)(vlTOPp->fln__DOT__fm4__DOT__expF) 
                                                   - (IData)(1U)));
            vlTOPp->fln__DOT__fm4__DOT__mantissa = 
                ((0x7ffffeU & vlTOPp->fln__DOT__fm4__DOT__mantissa) 
                 | (1U & (IData)((vlTOPp->fln__DOT__fm4__DOT__mantissaProd 
                                  >> 0x18U))));
            vlTOPp->fln__DOT__fm4__DOT__mantissaProd 
                = (0xffffffffffffULL & (vlTOPp->fln__DOT__fm4__DOT__mantissaProd 
                                        << 1U));
        }
        vlTOPp->fln__DOT__fm4__DOT__i = ((IData)(1U) 
                                         + vlTOPp->fln__DOT__fm4__DOT__i);
    }
    vlTOPp->fln__DOT__fm4__DOT__mantissa = (0x7fffffU 
                                            & (vlTOPp->fln__DOT__fm4__DOT__mantissa 
                                               << 1U));
    vlTOPp->fln__DOT__fm4__DOT__expF = (0xffU & ((IData)(1U) 
                                                 + (IData)(vlTOPp->fln__DOT__fm4__DOT__expF)));
    vlTOPp->fln__DOT__fm4__DOT__mantissa = ((0x7ffffeU 
                                             & vlTOPp->fln__DOT__fm4__DOT__mantissa) 
                                            | (1U & (IData)(
                                                            (vlTOPp->fln__DOT__fm4__DOT__mantissaProd 
                                                             >> 0x18U))));
    vlTOPp->fln__DOT__temp4 = ((0x80000000U & vlTOPp->fln__DOT__temp4i) 
                               | (((IData)(vlTOPp->fln__DOT__fm4__DOT__expF) 
                                   << 0x17U) | vlTOPp->fln__DOT__fm4__DOT__mantissa));
    vlTOPp->fln__DOT____Vcellinp__fa2____pinNumber2 
        = ((0x80000000U & ((~ (vlTOPp->fln__DOT__temp4 
                               >> 0x1fU)) << 0x1fU)) 
           | (0x7fffffffU & vlTOPp->fln__DOT__temp4));
    vlTOPp->fln__DOT__fa2__DOT__finalSign = 0U;
    vlTOPp->fln__DOT__fa2__DOT__largerMag = 0U;
    vlTOPp->fln__DOT__fa2__DOT__num1Exp = (0xffU & 
                                           (vlTOPp->fln__DOT__temp3 
                                            >> 0x17U));
    vlTOPp->fln__DOT__fa2__DOT__num2Exp = (0xffU & 
                                           (vlTOPp->fln__DOT____Vcellinp__fa2____pinNumber2 
                                            >> 0x17U));
    vlTOPp->fln__DOT__fa2__DOT__num1Mant = (0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->fln__DOT__temp3));
    vlTOPp->fln__DOT__fa2__DOT__num2Mant = (0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->fln__DOT____Vcellinp__fa2____pinNumber2));
    if (((IData)(vlTOPp->fln__DOT__fa2__DOT__num1Exp) 
         < (IData)(vlTOPp->fln__DOT__fa2__DOT__num2Exp))) {
        vlTOPp->fln__DOT__fa2__DOT__finalExp = vlTOPp->fln__DOT__fa2__DOT__num2Exp;
        vlTOPp->fln__DOT__fa2__DOT__num1Mant = ((0x17U 
                                                 >= 
                                                 (0xffU 
                                                  & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                     - (IData)(vlTOPp->fln__DOT__fa2__DOT__num2Exp))))
                                                 ? 
                                                (0xffffffU 
                                                 & (vlTOPp->fln__DOT__fa2__DOT__num1Mant 
                                                    >> 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                                        - (IData)(vlTOPp->fln__DOT__fa2__DOT__num2Exp)))))
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
    if ((0x80000000U & (vlTOPp->fln__DOT__temp3 & vlTOPp->fln__DOT____Vcellinp__fa2____pinNumber2))) {
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
        if ((1U & ((vlTOPp->fln__DOT__temp3 >> 0x1fU) 
                   & (~ (vlTOPp->fln__DOT____Vcellinp__fa2____pinNumber2 
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
            if ((1U & ((~ (vlTOPp->fln__DOT__temp3 
                           >> 0x1fU)) & (vlTOPp->fln__DOT____Vcellinp__fa2____pinNumber2 
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
    vlTOPp->fln__DOT__fa2__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x17U, vlTOPp->fln__DOT__fa2__DOT__i)) {
        if ((0x800000U & vlTOPp->fln__DOT__fa2__DOT__finalMant)) {
            vlTOPp->fln__DOT__fa2__DOT__i = 0x17U;
        } else {
            vlTOPp->fln__DOT__fa2__DOT__finalMant = 
                (0xffffffU & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                              << 1U));
            vlTOPp->fln__DOT__fa2__DOT__finalExp = 
                (0xffU & ((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                          - (IData)(1U)));
        }
        vlTOPp->fln__DOT__fa2__DOT__i = ((IData)(1U) 
                                         + vlTOPp->fln__DOT__fa2__DOT__i);
    }
    vlTOPp->fln__DOT__fa2__DOT__finalMant = (0xffffffU 
                                             & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                << 1U));
    if (((0U == vlTOPp->fln__DOT__temp3) & (0U == (IData)(vlTOPp->fln__DOT__fa2__DOT__num2Exp)))) {
        vlTOPp->fln__DOT__fa2__DOT__finalMant = 0U;
        vlTOPp->fln__DOT__fa2__DOT__finalExp = 0U;
    }
    vlTOPp->fln__DOT__temp7 = ((0x80000000U & ((~ (IData)(vlTOPp->fln__DOT__fa2__DOT__finalSign)) 
                                               << 0x1fU)) 
                               | (((IData)(vlTOPp->fln__DOT__fa2__DOT__finalExp) 
                                   << 0x17U) | (0x7fffffU 
                                                & (vlTOPp->fln__DOT__fa2__DOT__finalMant 
                                                   >> 1U))));
    vlTOPp->fln__DOT__fa3__DOT__finalSign = 0U;
    vlTOPp->fln__DOT__fa3__DOT__largerMag = 0U;
    vlTOPp->fln__DOT__fa3__DOT__num1Exp = (0xffU & 
                                           (vlTOPp->fln__DOT__temp6 
                                            >> 0x17U));
    vlTOPp->fln__DOT__fa3__DOT__num2Exp = (0xffU & 
                                           (vlTOPp->fln__DOT__temp7 
                                            >> 0x17U));
    vlTOPp->fln__DOT__fa3__DOT__num1Mant = (0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->fln__DOT__temp6));
    vlTOPp->fln__DOT__fa3__DOT__num2Mant = (0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->fln__DOT__temp7));
    if (((IData)(vlTOPp->fln__DOT__fa3__DOT__num1Exp) 
         < (IData)(vlTOPp->fln__DOT__fa3__DOT__num2Exp))) {
        vlTOPp->fln__DOT__fa3__DOT__finalExp = vlTOPp->fln__DOT__fa3__DOT__num2Exp;
        vlTOPp->fln__DOT__fa3__DOT__num1Mant = ((0x17U 
                                                 >= 
                                                 (0xffU 
                                                  & ((IData)(vlTOPp->fln__DOT__fa3__DOT__finalExp) 
                                                     - (IData)(vlTOPp->fln__DOT__fa3__DOT__num2Exp))))
                                                 ? 
                                                (0xffffffU 
                                                 & (vlTOPp->fln__DOT__fa3__DOT__num1Mant 
                                                    >> 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fln__DOT__fa3__DOT__finalExp) 
                                                        - (IData)(vlTOPp->fln__DOT__fa3__DOT__num2Exp)))))
                                                 : 0U);
        vlTOPp->fln__DOT__fa3__DOT__largerMag = 1U;
    } else {
        if (((IData)(vlTOPp->fln__DOT__fa3__DOT__num2Exp) 
             < (IData)(vlTOPp->fln__DOT__fa3__DOT__num1Exp))) {
            vlTOPp->fln__DOT__fa3__DOT__finalExp = vlTOPp->fln__DOT__fa3__DOT__num1Exp;
            vlTOPp->fln__DOT__fa3__DOT__num2Mant = 
                ((0x17U >= (0xffU & ((IData)(vlTOPp->fln__DOT__fa3__DOT__finalExp) 
                                     - (IData)(vlTOPp->fln__DOT__fa3__DOT__num2Exp))))
                  ? (0xffffffU & (vlTOPp->fln__DOT__fa3__DOT__num2Mant 
                                  >> (0xffU & ((IData)(vlTOPp->fln__DOT__fa3__DOT__finalExp) 
                                               - (IData)(vlTOPp->fln__DOT__fa3__DOT__num2Exp)))))
                  : 0U);
            vlTOPp->fln__DOT__fa3__DOT__largerMag = 0U;
        } else {
            vlTOPp->fln__DOT__fa3__DOT__finalExp = vlTOPp->fln__DOT__fa3__DOT__num1Exp;
            vlTOPp->fln__DOT__fa3__DOT__largerMag = 
                (vlTOPp->fln__DOT__fa3__DOT__num2Mant 
                 > vlTOPp->fln__DOT__fa3__DOT__num1Mant);
        }
    }
    if ((0x80000000U & (vlTOPp->fln__DOT__temp6 & vlTOPp->fln__DOT__temp7))) {
        vlTOPp->fln__DOT__fa3__DOT__sumMants = (0x1ffffffU 
                                                & (vlTOPp->fln__DOT__fa3__DOT__num2Mant 
                                                   + vlTOPp->fln__DOT__fa3__DOT__num1Mant));
        vlTOPp->fln__DOT__fa3__DOT__finalExp = (0xffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlTOPp->fln__DOT__fa3__DOT__finalExp)));
        vlTOPp->fln__DOT__fa3__DOT__finalSign = 0U;
        vlTOPp->fln__DOT__fa3__DOT__finalMant = (0xffffffU 
                                                 & (vlTOPp->fln__DOT__fa3__DOT__sumMants 
                                                    >> 1U));
    } else {
        if ((1U & ((vlTOPp->fln__DOT__temp6 >> 0x1fU) 
                   & (~ (vlTOPp->fln__DOT__temp7 >> 0x1fU))))) {
            vlTOPp->fln__DOT__fa3__DOT__sumMants = 
                (0x1ffffffU & (vlTOPp->fln__DOT__fa3__DOT__num1Mant 
                               - vlTOPp->fln__DOT__fa3__DOT__num2Mant));
            vlTOPp->fln__DOT__fa3__DOT__finalSign = vlTOPp->fln__DOT__fa3__DOT__largerMag;
            vlTOPp->fln__DOT__fa3__DOT__finalMant = 
                (0xffffffU & vlTOPp->fln__DOT__fa3__DOT__sumMants);
            vlTOPp->fln__DOT__fa3__DOT__finalMant = 
                (0xffffffU & ((0x1000000U & vlTOPp->fln__DOT__fa3__DOT__sumMants)
                               ? ((IData)(0xffffffffU) 
                                  * vlTOPp->fln__DOT__fa3__DOT__finalMant)
                               : vlTOPp->fln__DOT__fa3__DOT__finalMant));
        } else {
            if ((1U & ((~ (vlTOPp->fln__DOT__temp6 
                           >> 0x1fU)) & (vlTOPp->fln__DOT__temp7 
                                         >> 0x1fU)))) {
                vlTOPp->fln__DOT__fa3__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fln__DOT__fa3__DOT__num2Mant 
                                     - vlTOPp->fln__DOT__fa3__DOT__num1Mant));
                vlTOPp->fln__DOT__fa3__DOT__finalSign 
                    = (1U & (~ (IData)(vlTOPp->fln__DOT__fa3__DOT__largerMag)));
                vlTOPp->fln__DOT__fa3__DOT__finalMant 
                    = (0xffffffU & vlTOPp->fln__DOT__fa3__DOT__sumMants);
                vlTOPp->fln__DOT__fa3__DOT__finalMant 
                    = (0xffffffU & ((0x1000000U & vlTOPp->fln__DOT__fa3__DOT__sumMants)
                                     ? ((IData)(0xffffffffU) 
                                        * vlTOPp->fln__DOT__fa3__DOT__finalMant)
                                     : vlTOPp->fln__DOT__fa3__DOT__finalMant));
            } else {
                vlTOPp->fln__DOT__fa3__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fln__DOT__fa3__DOT__num2Mant 
                                     + vlTOPp->fln__DOT__fa3__DOT__num1Mant));
                vlTOPp->fln__DOT__fa3__DOT__finalExp 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fln__DOT__fa3__DOT__finalExp)));
                vlTOPp->fln__DOT__fa3__DOT__finalSign = 1U;
                vlTOPp->fln__DOT__fa3__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fln__DOT__fa3__DOT__sumMants 
                                    >> 1U));
            }
        }
    }
    vlTOPp->fln__DOT__fa3__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x17U, vlTOPp->fln__DOT__fa3__DOT__i)) {
        if ((0x800000U & vlTOPp->fln__DOT__fa3__DOT__finalMant)) {
            vlTOPp->fln__DOT__fa3__DOT__i = 0x17U;
        } else {
            vlTOPp->fln__DOT__fa3__DOT__finalMant = 
                (0xffffffU & (vlTOPp->fln__DOT__fa3__DOT__finalMant 
                              << 1U));
            vlTOPp->fln__DOT__fa3__DOT__finalExp = 
                (0xffU & ((IData)(vlTOPp->fln__DOT__fa3__DOT__finalExp) 
                          - (IData)(1U)));
        }
        vlTOPp->fln__DOT__fa3__DOT__i = ((IData)(1U) 
                                         + vlTOPp->fln__DOT__fa3__DOT__i);
    }
    vlTOPp->fln__DOT__fa3__DOT__finalMant = (0xffffffU 
                                             & (vlTOPp->fln__DOT__fa3__DOT__finalMant 
                                                << 1U));
    if (((0U == vlTOPp->fln__DOT__temp6) & (0U == (IData)(vlTOPp->fln__DOT__fa3__DOT__num2Exp)))) {
        vlTOPp->fln__DOT__fa3__DOT__finalMant = 0U;
        vlTOPp->fln__DOT__fa3__DOT__finalExp = 0U;
    }
    vlTOPp->fln__DOT__temp8i = ((0x80000000U & ((~ (IData)(vlTOPp->fln__DOT__fa3__DOT__finalSign)) 
                                                << 0x1fU)) 
                                | (((IData)(vlTOPp->fln__DOT__fa3__DOT__finalExp) 
                                    << 0x17U) | (0x7fffffU 
                                                 & (vlTOPp->fln__DOT__fa3__DOT__finalMant 
                                                    >> 1U))));
    vlTOPp->fln__DOT__fa4__DOT__finalSign = 0U;
    vlTOPp->fln__DOT__fa4__DOT__largerMag = 0U;
    vlTOPp->fln__DOT__fa4__DOT__num1Exp = (0xffU & 
                                           (vlTOPp->fln__DOT__temp8i 
                                            >> 0x17U));
    vlTOPp->fln__DOT__fa4__DOT__num2Exp = (0xffU & 
                                           (vlTOPp->fln__DOT__temp5 
                                            >> 0x17U));
    vlTOPp->fln__DOT__fa4__DOT__num1Mant = (0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->fln__DOT__temp8i));
    vlTOPp->fln__DOT__fa4__DOT__num2Mant = (0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->fln__DOT__temp5));
    if (((IData)(vlTOPp->fln__DOT__fa4__DOT__num1Exp) 
         < (IData)(vlTOPp->fln__DOT__fa4__DOT__num2Exp))) {
        vlTOPp->fln__DOT__fa4__DOT__finalExp = vlTOPp->fln__DOT__fa4__DOT__num2Exp;
        vlTOPp->fln__DOT__fa4__DOT__num1Mant = ((0x17U 
                                                 >= 
                                                 (0xffU 
                                                  & ((IData)(vlTOPp->fln__DOT__fa4__DOT__finalExp) 
                                                     - (IData)(vlTOPp->fln__DOT__fa4__DOT__num2Exp))))
                                                 ? 
                                                (0xffffffU 
                                                 & (vlTOPp->fln__DOT__fa4__DOT__num1Mant 
                                                    >> 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fln__DOT__fa4__DOT__finalExp) 
                                                        - (IData)(vlTOPp->fln__DOT__fa4__DOT__num2Exp)))))
                                                 : 0U);
        vlTOPp->fln__DOT__fa4__DOT__largerMag = 1U;
    } else {
        if (((IData)(vlTOPp->fln__DOT__fa4__DOT__num2Exp) 
             < (IData)(vlTOPp->fln__DOT__fa4__DOT__num1Exp))) {
            vlTOPp->fln__DOT__fa4__DOT__finalExp = vlTOPp->fln__DOT__fa4__DOT__num1Exp;
            vlTOPp->fln__DOT__fa4__DOT__num2Mant = 
                ((0x17U >= (0xffU & ((IData)(vlTOPp->fln__DOT__fa4__DOT__finalExp) 
                                     - (IData)(vlTOPp->fln__DOT__fa4__DOT__num2Exp))))
                  ? (0xffffffU & (vlTOPp->fln__DOT__fa4__DOT__num2Mant 
                                  >> (0xffU & ((IData)(vlTOPp->fln__DOT__fa4__DOT__finalExp) 
                                               - (IData)(vlTOPp->fln__DOT__fa4__DOT__num2Exp)))))
                  : 0U);
            vlTOPp->fln__DOT__fa4__DOT__largerMag = 0U;
        } else {
            vlTOPp->fln__DOT__fa4__DOT__finalExp = vlTOPp->fln__DOT__fa4__DOT__num1Exp;
            vlTOPp->fln__DOT__fa4__DOT__largerMag = 
                (vlTOPp->fln__DOT__fa4__DOT__num2Mant 
                 > vlTOPp->fln__DOT__fa4__DOT__num1Mant);
        }
    }
    if ((0x80000000U & (vlTOPp->fln__DOT__temp8i & vlTOPp->fln__DOT__temp5))) {
        vlTOPp->fln__DOT__fa4__DOT__sumMants = (0x1ffffffU 
                                                & (vlTOPp->fln__DOT__fa4__DOT__num2Mant 
                                                   + vlTOPp->fln__DOT__fa4__DOT__num1Mant));
        vlTOPp->fln__DOT__fa4__DOT__finalExp = (0xffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlTOPp->fln__DOT__fa4__DOT__finalExp)));
        vlTOPp->fln__DOT__fa4__DOT__finalSign = 0U;
        vlTOPp->fln__DOT__fa4__DOT__finalMant = (0xffffffU 
                                                 & (vlTOPp->fln__DOT__fa4__DOT__sumMants 
                                                    >> 1U));
    } else {
        if ((1U & ((vlTOPp->fln__DOT__temp8i >> 0x1fU) 
                   & (~ (vlTOPp->fln__DOT__temp5 >> 0x1fU))))) {
            vlTOPp->fln__DOT__fa4__DOT__sumMants = 
                (0x1ffffffU & (vlTOPp->fln__DOT__fa4__DOT__num1Mant 
                               - vlTOPp->fln__DOT__fa4__DOT__num2Mant));
            vlTOPp->fln__DOT__fa4__DOT__finalSign = vlTOPp->fln__DOT__fa4__DOT__largerMag;
            vlTOPp->fln__DOT__fa4__DOT__finalMant = 
                (0xffffffU & vlTOPp->fln__DOT__fa4__DOT__sumMants);
            vlTOPp->fln__DOT__fa4__DOT__finalMant = 
                (0xffffffU & ((0x1000000U & vlTOPp->fln__DOT__fa4__DOT__sumMants)
                               ? ((IData)(0xffffffffU) 
                                  * vlTOPp->fln__DOT__fa4__DOT__finalMant)
                               : vlTOPp->fln__DOT__fa4__DOT__finalMant));
        } else {
            if ((1U & ((~ (vlTOPp->fln__DOT__temp8i 
                           >> 0x1fU)) & (vlTOPp->fln__DOT__temp5 
                                         >> 0x1fU)))) {
                vlTOPp->fln__DOT__fa4__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fln__DOT__fa4__DOT__num2Mant 
                                     - vlTOPp->fln__DOT__fa4__DOT__num1Mant));
                vlTOPp->fln__DOT__fa4__DOT__finalSign 
                    = (1U & (~ (IData)(vlTOPp->fln__DOT__fa4__DOT__largerMag)));
                vlTOPp->fln__DOT__fa4__DOT__finalMant 
                    = (0xffffffU & vlTOPp->fln__DOT__fa4__DOT__sumMants);
                vlTOPp->fln__DOT__fa4__DOT__finalMant 
                    = (0xffffffU & ((0x1000000U & vlTOPp->fln__DOT__fa4__DOT__sumMants)
                                     ? ((IData)(0xffffffffU) 
                                        * vlTOPp->fln__DOT__fa4__DOT__finalMant)
                                     : vlTOPp->fln__DOT__fa4__DOT__finalMant));
            } else {
                vlTOPp->fln__DOT__fa4__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fln__DOT__fa4__DOT__num2Mant 
                                     + vlTOPp->fln__DOT__fa4__DOT__num1Mant));
                vlTOPp->fln__DOT__fa4__DOT__finalExp 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fln__DOT__fa4__DOT__finalExp)));
                vlTOPp->fln__DOT__fa4__DOT__finalSign = 1U;
                vlTOPp->fln__DOT__fa4__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fln__DOT__fa4__DOT__sumMants 
                                    >> 1U));
            }
        }
    }
    vlTOPp->fln__DOT__fa4__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x17U, vlTOPp->fln__DOT__fa4__DOT__i)) {
        if ((0x800000U & vlTOPp->fln__DOT__fa4__DOT__finalMant)) {
            vlTOPp->fln__DOT__fa4__DOT__i = 0x17U;
        } else {
            vlTOPp->fln__DOT__fa4__DOT__finalMant = 
                (0xffffffU & (vlTOPp->fln__DOT__fa4__DOT__finalMant 
                              << 1U));
            vlTOPp->fln__DOT__fa4__DOT__finalExp = 
                (0xffU & ((IData)(vlTOPp->fln__DOT__fa4__DOT__finalExp) 
                          - (IData)(1U)));
        }
        vlTOPp->fln__DOT__fa4__DOT__i = ((IData)(1U) 
                                         + vlTOPp->fln__DOT__fa4__DOT__i);
    }
    vlTOPp->fln__DOT__fa4__DOT__finalMant = (0xffffffU 
                                             & (vlTOPp->fln__DOT__fa4__DOT__finalMant 
                                                << 1U));
    if (((0U == vlTOPp->fln__DOT__temp8i) & (0U == (IData)(vlTOPp->fln__DOT__fa4__DOT__num2Exp)))) {
        vlTOPp->fln__DOT__fa4__DOT__finalMant = 0U;
        vlTOPp->fln__DOT__fa4__DOT__finalExp = 0U;
    }
    vlTOPp->out1 = ((0x80000000U & vlTOPp->num1) ? 0x7fc00000U
                     : ((0x80000000U & ((~ (IData)(vlTOPp->fln__DOT__fa4__DOT__finalSign)) 
                                        << 0x1fU)) 
                        | (((IData)(vlTOPp->fln__DOT__fa4__DOT__finalExp) 
                            << 0x17U) | (0x7fffffU 
                                         & (vlTOPp->fln__DOT__fa4__DOT__finalMant 
                                            >> 1U)))));
}

void Vfln::_eval(Vfln__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfln::_eval\n"); );
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
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
