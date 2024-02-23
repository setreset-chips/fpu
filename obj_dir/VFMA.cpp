// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFMA.h for the primary calling header

#include "VFMA.h"
#include "VFMA__Syms.h"

//==========

void VFMA::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VFMA::eval\n"); );
    VFMA__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VFMA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("FMA.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VFMA::_eval_initial_loop(VFMA__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("FMA.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VFMA::_combo__TOP__1(VFMA__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFMA::_combo__TOP__1\n"); );
    VFMA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->FMA__DOT__mantissa_a = (0x800000U | (0x7fffffU 
                                                 & vlTOPp->a_fp));
    vlTOPp->FMA__DOT__mantissa_b = (0x800000U | (0x7fffffU 
                                                 & vlTOPp->b_fp));
    vlTOPp->FMA__DOT__mantissa_c = (0x800000U | (0x7fffffU 
                                                 & vlTOPp->c_fp));
    vlTOPp->FMA__DOT__sign_out = (1U & ((vlTOPp->a_fp 
                                         ^ vlTOPp->b_fp) 
                                        >> 0x1fU));
    vlTOPp->FMA__DOT__exp_out = (0xffU & (((vlTOPp->a_fp 
                                            >> 0x17U) 
                                           + (vlTOPp->b_fp 
                                              >> 0x17U)) 
                                          - (IData)(0x7fU)));
    vlTOPp->FMA__DOT__mantissa_mul_out = (0xffffffffffffULL 
                                          & ((QData)((IData)(vlTOPp->FMA__DOT__mantissa_a)) 
                                             * (QData)((IData)(vlTOPp->FMA__DOT__mantissa_b))));
    vlTOPp->FMA__DOT__mantissa_mul_norm = (0xffffffU 
                                           & (IData)(
                                                     (vlTOPp->FMA__DOT__mantissa_mul_out 
                                                      >> 0x18U)));
    vlTOPp->FMA__DOT__offset = ((1U == vlTOPp->FMA__DOT__mantissa_mul_norm)
                                 ? 0x18U : 0U);
    vlTOPp->FMA__DOT__mantissa_mul_norm = ((0x17U >= vlTOPp->FMA__DOT__offset)
                                            ? (0xffffffU 
                                               & (vlTOPp->FMA__DOT__mantissa_mul_norm 
                                                  << vlTOPp->FMA__DOT__offset))
                                            : 0U);
    vlTOPp->FMA__DOT__exp_out = (0xffU & ((IData)(vlTOPp->FMA__DOT__exp_out) 
                                          - (vlTOPp->FMA__DOT__offset 
                                             - (IData)(1U))));
    if (((IData)(vlTOPp->FMA__DOT__exp_out) < (0xffU 
                                               & (vlTOPp->c_fp 
                                                  >> 0x17U)))) {
        vlTOPp->FMA__DOT__final_exp = (0xffU & (vlTOPp->c_fp 
                                                >> 0x17U));
        vlTOPp->FMA__DOT__mantissa_mul_norm = ((0x17U 
                                                >= 
                                                (0xffU 
                                                 & ((IData)(vlTOPp->FMA__DOT__final_exp) 
                                                    - (IData)(vlTOPp->FMA__DOT__exp_out))))
                                                ? (0xffffffU 
                                                   & (vlTOPp->FMA__DOT__mantissa_mul_norm 
                                                      >> 
                                                      (0xffU 
                                                       & ((IData)(vlTOPp->FMA__DOT__final_exp) 
                                                          - (IData)(vlTOPp->FMA__DOT__exp_out)))))
                                                : 0U);
        vlTOPp->FMA__DOT__largerMag = 1U;
    } else {
        if (((0xffU & (vlTOPp->c_fp >> 0x17U)) < (IData)(vlTOPp->FMA__DOT__exp_out))) {
            vlTOPp->FMA__DOT__final_exp = vlTOPp->FMA__DOT__exp_out;
            vlTOPp->FMA__DOT__mantissa_c = ((0x17U 
                                             >= (0xffU 
                                                 & ((IData)(vlTOPp->FMA__DOT__final_exp) 
                                                    - 
                                                    (vlTOPp->c_fp 
                                                     >> 0x17U))))
                                             ? (0xffffffU 
                                                & (vlTOPp->FMA__DOT__mantissa_c 
                                                   >> 
                                                   (0xffU 
                                                    & ((IData)(vlTOPp->FMA__DOT__final_exp) 
                                                       - 
                                                       (vlTOPp->c_fp 
                                                        >> 0x17U)))))
                                             : 0U);
            vlTOPp->FMA__DOT__largerMag = 0U;
        } else {
            vlTOPp->FMA__DOT__final_exp = vlTOPp->FMA__DOT__exp_out;
            vlTOPp->FMA__DOT__largerMag = (vlTOPp->FMA__DOT__mantissa_c 
                                           > vlTOPp->FMA__DOT__mantissa_mul_norm);
        }
    }
    if (((IData)(vlTOPp->FMA__DOT__sign_out) & (vlTOPp->c_fp 
                                                >> 0x1fU))) {
        vlTOPp->FMA__DOT__sum_mants = (0x1ffffffU & 
                                       (vlTOPp->FMA__DOT__mantissa_c 
                                        + vlTOPp->FMA__DOT__mantissa_mul_norm));
        vlTOPp->FMA__DOT__final_exp = (0xffU & ((IData)(1U) 
                                                + (IData)(vlTOPp->FMA__DOT__final_exp)));
        vlTOPp->FMA__DOT__sign_out = 0U;
        vlTOPp->FMA__DOT__final_mantissa = (0xffffffU 
                                            & (vlTOPp->FMA__DOT__sum_mants 
                                               >> 1U));
    } else {
        if (((IData)(vlTOPp->FMA__DOT__sign_out) & 
             (~ (vlTOPp->c_fp >> 0x1fU)))) {
            vlTOPp->FMA__DOT__sum_mants = (0x1ffffffU 
                                           & (vlTOPp->FMA__DOT__mantissa_mul_norm 
                                              - vlTOPp->FMA__DOT__mantissa_c));
            vlTOPp->FMA__DOT__sign_out = vlTOPp->FMA__DOT__largerMag;
            vlTOPp->FMA__DOT__final_mantissa = (0xffffffU 
                                                & vlTOPp->FMA__DOT__sum_mants);
            vlTOPp->FMA__DOT__final_mantissa = (0xffffffU 
                                                & ((0x1000000U 
                                                    & vlTOPp->FMA__DOT__sum_mants)
                                                    ? 
                                                   ((IData)(0xffffffffU) 
                                                    * vlTOPp->FMA__DOT__final_mantissa)
                                                    : vlTOPp->FMA__DOT__final_mantissa));
        } else {
            if ((1U & ((~ (IData)(vlTOPp->FMA__DOT__sign_out)) 
                       & (vlTOPp->c_fp >> 0x1fU)))) {
                vlTOPp->FMA__DOT__sum_mants = (0x1ffffffU 
                                               & (vlTOPp->FMA__DOT__mantissa_c 
                                                  - vlTOPp->FMA__DOT__mantissa_mul_norm));
                vlTOPp->FMA__DOT__sign_out = (1U & 
                                              (~ (IData)(vlTOPp->FMA__DOT__largerMag)));
                vlTOPp->FMA__DOT__final_mantissa = 
                    (0xffffffU & vlTOPp->FMA__DOT__sum_mants);
                vlTOPp->FMA__DOT__final_mantissa = 
                    (0xffffffU & ((0x1000000U & vlTOPp->FMA__DOT__sum_mants)
                                   ? ((IData)(0xffffffffU) 
                                      * vlTOPp->FMA__DOT__final_mantissa)
                                   : vlTOPp->FMA__DOT__final_mantissa));
            } else {
                vlTOPp->FMA__DOT__sum_mants = (0x1ffffffU 
                                               & (vlTOPp->FMA__DOT__mantissa_c 
                                                  + vlTOPp->FMA__DOT__mantissa_mul_norm));
                vlTOPp->FMA__DOT__final_exp = (0xffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlTOPp->FMA__DOT__final_exp)));
                vlTOPp->FMA__DOT__sign_out = 1U;
                vlTOPp->FMA__DOT__final_mantissa = 
                    (0xffffffU & (vlTOPp->FMA__DOT__sum_mants 
                                  >> 1U));
            }
        }
    }
    vlTOPp->FMA__DOT__offset = ((1U == vlTOPp->FMA__DOT__final_mantissa)
                                 ? 0x18U : 0U);
    vlTOPp->FMA__DOT__final_mantissa = ((0x17U >= vlTOPp->FMA__DOT__offset)
                                         ? (0xffffffU 
                                            & (vlTOPp->FMA__DOT__final_mantissa 
                                               << vlTOPp->FMA__DOT__offset))
                                         : 0U);
    vlTOPp->FMA__DOT__final_exp = (0xffU & ((IData)(vlTOPp->FMA__DOT__final_exp) 
                                            - (vlTOPp->FMA__DOT__offset 
                                               - (IData)(1U))));
    vlTOPp->out_fp = ((0x80000000U & ((~ (IData)(vlTOPp->FMA__DOT__sign_out)) 
                                      << 0x1fU)) | 
                      (((IData)(vlTOPp->FMA__DOT__final_exp) 
                        << 0x17U) | (0x7fffffU & (vlTOPp->FMA__DOT__final_mantissa 
                                                  >> 1U))));
}

void VFMA::_eval(VFMA__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFMA::_eval\n"); );
    VFMA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData VFMA::_change_request(VFMA__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFMA::_change_request\n"); );
    VFMA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VFMA::_change_request_1(VFMA__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFMA::_change_request_1\n"); );
    VFMA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VFMA::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFMA::_eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
