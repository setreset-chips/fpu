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
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("fmul.sv", 1, "",
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
            VL_FATAL_MT("fmul.sv", 1, "",
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
    vlTOPp->fmul__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x17U, vlTOPp->fmul__DOT__i)) {
        if ((0x400000U & vlTOPp->fmul__DOT__mantissa)) {
            vlTOPp->fmul__DOT__i = 0x17U;
        } else {
            vlTOPp->fmul__DOT__mantissa = (0x7fffffU 
                                           & (vlTOPp->fmul__DOT__mantissa 
                                              << 1U));
            vlTOPp->fmul__DOT__expF = (0xffU & ((IData)(vlTOPp->fmul__DOT__expF) 
                                                - (IData)(1U)));
            vlTOPp->fmul__DOT__mantissa = ((0x7ffffeU 
                                            & vlTOPp->fmul__DOT__mantissa) 
                                           | (1U & (IData)(
                                                           (vlTOPp->fmul__DOT__mantissaProd 
                                                            >> 0x18U))));
            vlTOPp->fmul__DOT__mantissaProd = (0xffffffffffffULL 
                                               & (vlTOPp->fmul__DOT__mantissaProd 
                                                  << 1U));
        }
        vlTOPp->fmul__DOT__i = ((IData)(1U) + vlTOPp->fmul__DOT__i);
    }
    vlTOPp->fmul__DOT__mantissa = (0x7fffffU & (vlTOPp->fmul__DOT__mantissa 
                                                << 1U));
    vlTOPp->fmul__DOT__expF = (0xffU & ((IData)(1U) 
                                        + (IData)(vlTOPp->fmul__DOT__expF)));
    vlTOPp->fmul__DOT__mantissa = ((0x7ffffeU & vlTOPp->fmul__DOT__mantissa) 
                                   | (1U & (IData)(
                                                   (vlTOPp->fmul__DOT__mantissaProd 
                                                    >> 0x18U))));
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
