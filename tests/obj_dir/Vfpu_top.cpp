// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpu_top.h for the primary calling header

#include "Vfpu_top.h"
#include "Vfpu_top__Syms.h"

//==========

void Vfpu_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfpu_top::eval\n"); );
    Vfpu_top__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("../fpu_top.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vfpu_top::_eval_initial_loop(Vfpu_top__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("../fpu_top.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vfpu_top::_sequent__TOP__2(Vfpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_top::_sequent__TOP__2\n"); );
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__fpu_top__DOT__regFile__v0;
    CData/*0:0*/ __Vdlyvset__fpu_top__DOT__regFile__v0;
    IData/*31:0*/ __Vdlyvval__fpu_top__DOT__regFile__v0;
    // Body
    __Vdlyvset__fpu_top__DOT__regFile__v0 = 0U;
    vlTOPp->fpu_top__DOT__final_op = vlTOPp->fpu_top__DOT__exec_op;
    if ((4U == (7U & (vlTOPp->fpu_top__DOT__ins_p1 
                      >> 4U)))) {
        vlTOPp->fpu_top__DOT__curr_op = ((8U & vlTOPp->fpu_top__DOT__ins_p1)
                                          ? ((4U & vlTOPp->fpu_top__DOT__ins_p1)
                                              ? 4U : 3U)
                                          : ((4U & vlTOPp->fpu_top__DOT__ins_p1)
                                              ? 2U : 1U));
    } else {
        if ((5U == (7U & (vlTOPp->fpu_top__DOT__ins_p1 
                          >> 4U)))) {
            vlTOPp->fpu_top__DOT__curr_op = ((0x80000000U 
                                              & vlTOPp->fpu_top__DOT__ins_p1)
                                              ? ((0x40000000U 
                                                  & vlTOPp->fpu_top__DOT__ins_p1)
                                                  ? 
                                                 ((0x20000000U 
                                                   & vlTOPp->fpu_top__DOT__ins_p1)
                                                   ? 
                                                  ((0x10000000U 
                                                    & vlTOPp->fpu_top__DOT__ins_p1)
                                                    ? 
                                                   ((0x8000000U 
                                                     & vlTOPp->fpu_top__DOT__ins_p1)
                                                     ? 0x19U
                                                     : 0x18U)
                                                    : 
                                                   ((0x8000000U 
                                                     & vlTOPp->fpu_top__DOT__ins_p1)
                                                     ? 0x19U
                                                     : 
                                                    ((0x1000U 
                                                      & vlTOPp->fpu_top__DOT__ins_p1)
                                                      ? 0x15U
                                                      : 0x11U)))
                                                   : 
                                                  ((0x10000000U 
                                                    & vlTOPp->fpu_top__DOT__ins_p1)
                                                    ? 
                                                   ((0x8000000U 
                                                     & vlTOPp->fpu_top__DOT__ins_p1)
                                                     ? 0x19U
                                                     : 
                                                    ((0x100000U 
                                                      & vlTOPp->fpu_top__DOT__ins_p1)
                                                      ? 0x17U
                                                      : 0x16U))
                                                    : 
                                                   ((0x8000000U 
                                                     & vlTOPp->fpu_top__DOT__ins_p1)
                                                     ? 0x19U
                                                     : 
                                                    ((0x100000U 
                                                      & vlTOPp->fpu_top__DOT__ins_p1)
                                                      ? 0x10U
                                                      : 0xfU))))
                                                  : 
                                                 ((0x20000000U 
                                                   & vlTOPp->fpu_top__DOT__ins_p1)
                                                   ? 
                                                  ((0x10000000U 
                                                    & vlTOPp->fpu_top__DOT__ins_p1)
                                                    ? 0x19U
                                                    : 
                                                   ((0x8000000U 
                                                     & vlTOPp->fpu_top__DOT__ins_p1)
                                                     ? 0x19U
                                                     : 
                                                    ((0x2000U 
                                                      & vlTOPp->fpu_top__DOT__ins_p1)
                                                      ? 0x12U
                                                      : 
                                                     ((0x1000U 
                                                       & vlTOPp->fpu_top__DOT__ins_p1)
                                                       ? 0x13U
                                                       : 0x14U))))
                                                   : 0x19U))
                                              : ((0x40000000U 
                                                  & vlTOPp->fpu_top__DOT__ins_p1)
                                                  ? 
                                                 ((0x20000000U 
                                                   & vlTOPp->fpu_top__DOT__ins_p1)
                                                   ? 0x19U
                                                   : 
                                                  ((0x10000000U 
                                                    & vlTOPp->fpu_top__DOT__ins_p1)
                                                    ? 
                                                   ((0x8000000U 
                                                     & vlTOPp->fpu_top__DOT__ins_p1)
                                                     ? 9U
                                                     : 0x19U)
                                                    : 0x19U))
                                                  : 
                                                 ((0x20000000U 
                                                   & vlTOPp->fpu_top__DOT__ins_p1)
                                                   ? 
                                                  ((0x10000000U 
                                                    & vlTOPp->fpu_top__DOT__ins_p1)
                                                    ? 0x19U
                                                    : 
                                                   ((0x8000000U 
                                                     & vlTOPp->fpu_top__DOT__ins_p1)
                                                     ? 
                                                    ((0x1000U 
                                                      & vlTOPp->fpu_top__DOT__ins_p1)
                                                      ? 0xeU
                                                      : 0xdU)
                                                     : 
                                                    ((0x2000U 
                                                      & vlTOPp->fpu_top__DOT__ins_p1)
                                                      ? 0xcU
                                                      : 
                                                     ((0x1000U 
                                                       & vlTOPp->fpu_top__DOT__ins_p1)
                                                       ? 0xbU
                                                       : 0xaU))))
                                                   : 
                                                  ((0x10000000U 
                                                    & vlTOPp->fpu_top__DOT__ins_p1)
                                                    ? 
                                                   ((0x8000000U 
                                                     & vlTOPp->fpu_top__DOT__ins_p1)
                                                     ? 8U
                                                     : 7U)
                                                    : 
                                                   ((0x8000000U 
                                                     & vlTOPp->fpu_top__DOT__ins_p1)
                                                     ? 6U
                                                     : 5U)))));
        }
    }
    vlTOPp->fpu_top__DOT__oper1 = vlTOPp->fpu_top__DOT__operand_1;
    vlTOPp->fpu_top__DOT__oper2 = vlTOPp->fpu_top__DOT__operand_2;
    vlTOPp->fpu_top__DOT__oper3 = vlTOPp->fpu_top__DOT__operand_3;
    vlTOPp->fpu_top__DOT__result = ((0x10U & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                     ? ((8U & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                         ? 0x7fc00000U
                                         : ((4U & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                             ? ((2U 
                                                 & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                                 ? 0x7fc00000U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                                  ? 0U
                                                  : vlTOPp->fpu_top__DOT__fle1__DOT__out))
                                             : ((2U 
                                                 & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                                  ? vlTOPp->fpu_top__DOT__flt1__DOT__out
                                                  : 
                                                 ((vlTOPp->fpu_top__DOT__operand_one 
                                                   == vlTOPp->fpu_top__DOT__operand_two)
                                                   ? 1U
                                                   : 0U))
                                                 : 0x7fc00000U)))
                                     : ((8U & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                         ? ((4U & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                             ? ((2U 
                                                 & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                                  ? 0x7fc00000U
                                                  : vlTOPp->fpu_top__DOT__fmax1__DOT__out)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                                  ? vlTOPp->fpu_top__DOT__fmin1__DOT__out
                                                  : 
                                                 ((0x80000000U 
                                                   & (vlTOPp->fpu_top__DOT__operand_two 
                                                      ^ vlTOPp->fpu_top__DOT__operand_one)) 
                                                  | (0x7fffffffU 
                                                     & vlTOPp->fpu_top__DOT__operand_one))))
                                             : ((2U 
                                                 & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                                  ? 
                                                 ((0x80000000U 
                                                   & ((~ 
                                                       (vlTOPp->fpu_top__DOT__operand_two 
                                                        >> 0x1fU)) 
                                                      << 0x1fU)) 
                                                  | (0x7fffffffU 
                                                     & vlTOPp->fpu_top__DOT__operand_one))
                                                  : 
                                                 ((0x80000000U 
                                                   & vlTOPp->fpu_top__DOT__operand_two) 
                                                  | (0x7fffffffU 
                                                     & vlTOPp->fpu_top__DOT__operand_one)))
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                                  ? vlTOPp->fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded
                                                  : vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fm0.__PVT__r0__DOT__rounded)))
                                         : ((4U & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                             ? ((2U 
                                                 & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                                  ? vlSymsp->TOP__fpu_top__DOT__fmul1.__PVT__r0__DOT__rounded
                                                  : vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                                  ? vlTOPp->fpu_top__DOT__fadd1__DOT__r0__DOT__rounded
                                                  : vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded))
                                             : ((2U 
                                                 & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                                  ? vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded
                                                  : vlSymsp->TOP__fpu_top__DOT__fmsub1__DOT__fmul1.__PVT__r0__DOT__rounded)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->fpu_top__DOT__exec_op))
                                                  ? vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded
                                                  : 0U)))));
    vlTOPp->fpu_top__DOT__operand_three = vlTOPp->fpu_top__DOT__oper3;
    if (((0x19U != (IData)(vlTOPp->fpu_top__DOT__final_op)) 
         & (0U != (IData)(vlTOPp->fpu_top__DOT__final_op)))) {
        __Vdlyvval__fpu_top__DOT__regFile__v0 = vlTOPp->fpu_top__DOT__writeback_data;
        __Vdlyvset__fpu_top__DOT__regFile__v0 = 1U;
        __Vdlyvdim0__fpu_top__DOT__regFile__v0 = (0x1fU 
                                                  & (vlTOPp->fpu_top__DOT__ins_p3 
                                                     >> 7U));
    }
    vlTOPp->fpu_top__DOT__operand_1 = vlTOPp->fpu_top__DOT__regFile
        [(0x1fU & (vlTOPp->instruction >> 0xfU))];
    vlTOPp->fpu_top__DOT__operand_2 = vlTOPp->fpu_top__DOT__regFile
        [(0x1fU & (vlTOPp->instruction >> 0x14U))];
    vlTOPp->fpu_top__DOT__operand_3 = vlTOPp->fpu_top__DOT__regFile
        [(0x1fU & (vlTOPp->instruction >> 0x1bU))];
    vlTOPp->fpu_top__DOT__exec_op = vlTOPp->fpu_top__DOT__curr_op;
    vlTOPp->fpu_top__DOT__operand_one = vlTOPp->fpu_top__DOT__oper1;
    vlTOPp->fpu_top__DOT__operand_two = vlTOPp->fpu_top__DOT__oper2;
    vlTOPp->fpu_top__DOT__writeback_data = vlTOPp->fpu_top__DOT__result;
    vlTOPp->fpu_top__DOT__ins_p3 = vlTOPp->fpu_top__DOT__ins_p2;
    if (__Vdlyvset__fpu_top__DOT__regFile__v0) {
        vlTOPp->fpu_top__DOT__regFile[__Vdlyvdim0__fpu_top__DOT__regFile__v0] 
            = __Vdlyvval__fpu_top__DOT__regFile__v0;
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
    vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1 = ((0x80000000U 
                                                & ((~ 
                                                    (vlTOPp->fpu_top__DOT__operand_one 
                                                     >> 0x1fU)) 
                                                   << 0x1fU)) 
                                               | (0x7fffffffU 
                                                  & vlTOPp->fpu_top__DOT__operand_one));
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
    vlTOPp->fpu_out = vlTOPp->fpu_top__DOT__writeback_data;
    vlTOPp->fpu_top__DOT__ins_p2 = vlTOPp->fpu_top__DOT__ins_p1;
    vlTOPp->fpu_top__DOT__fadd1__DOT__unrounded = (
                                                   (0x80000000U 
                                                    & ((~ (IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalSign)) 
                                                       << 0x1fU)) 
                                                   | (((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                                       << 0x17U) 
                                                      | (0x7fffffU 
                                                         & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                            >> 1U))));
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
    vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded 
        = ((0x80000000U & ((~ (IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalSign)) 
                           << 0x1fU)) | (((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                          << 0x17U) 
                                         | (0x7fffffU 
                                            & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                               >> 1U))));
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
    vlTOPp->fpu_top__DOT__ins_p1 = vlTOPp->instruction;
    vlTOPp->fpu_top__DOT__rm = (7U & ((7U == (7U & 
                                              (vlTOPp->fpu_top__DOT__ins_p2 
                                               >> 0xcU)))
                                       ? (vlTOPp->fpu_top__DOT__fcsr 
                                          >> 5U) : 
                                      (vlTOPp->fpu_top__DOT__ins_p2 
                                       >> 0xcU)));
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
}

VL_INLINE_OPT void Vfpu_top::_sequent__TOP__3(Vfpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_top::_sequent__TOP__3\n"); );
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalSign = 0U;
    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__largerMag = 0U;
    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Exp 
        = (0xffU & (vlSymsp->TOP__fpu_top__DOT__fmadd1__DOT__fmul1.__PVT__r0__DOT__rounded 
                    >> 0x17U));
    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Exp 
        = (0xffU & (vlTOPp->fpu_top__DOT__operand_three 
                    >> 0x17U));
    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Mant 
        = (0x800000U | (0x7fffffU & vlSymsp->TOP__fpu_top__DOT__fmadd1__DOT__fmul1.__PVT__r0__DOT__rounded));
    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Mant 
        = (0x800000U | (0x7fffffU & vlTOPp->fpu_top__DOT__operand_three));
    if (((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Exp) 
         < (IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Exp))) {
        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
            = vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Exp;
        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Mant 
            = ((0x17U >= (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                   - (IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Exp))))
                ? (0xffffffU & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Mant 
                                >> (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                             - (IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Exp)))))
                : 0U);
        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__largerMag = 1U;
    } else {
        if (((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Exp) 
             < (IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Exp))) {
            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                = vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Exp;
            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Mant 
                = ((0x17U >= (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                       - (IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Exp))))
                    ? (0xffffffU & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Mant 
                                    >> (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                                 - (IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Exp)))))
                    : 0U);
            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__largerMag = 0U;
        } else {
            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                = vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Exp;
            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__largerMag 
                = (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Mant 
                   > vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Mant);
        }
    }
    if ((0x80000000U & (vlSymsp->TOP__fpu_top__DOT__fmadd1__DOT__fmul1.__PVT__r0__DOT__rounded 
                        & vlTOPp->fpu_top__DOT__operand_three))) {
        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__sumMants 
            = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Mant 
                             + vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Mant));
        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
            = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp)));
        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalSign = 0U;
        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
            = (0xffffffU & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__sumMants 
                            >> 1U));
    } else {
        if ((1U & ((vlSymsp->TOP__fpu_top__DOT__fmadd1__DOT__fmul1.__PVT__r0__DOT__rounded 
                    >> 0x1fU) & (~ (vlTOPp->fpu_top__DOT__operand_three 
                                    >> 0x1fU))))) {
            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__sumMants 
                = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Mant 
                                 - vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Mant));
            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalSign 
                = vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__largerMag;
            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                = (0xffffffU & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__sumMants);
            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                = (0xffffffU & ((0x1000000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__sumMants)
                                 ? ((IData)(0xffffffffU) 
                                    * vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)
                                 : vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant));
        } else {
            if ((1U & ((~ (vlSymsp->TOP__fpu_top__DOT__fmadd1__DOT__fmul1.__PVT__r0__DOT__rounded 
                           >> 0x1fU)) & (vlTOPp->fpu_top__DOT__operand_three 
                                         >> 0x1fU)))) {
                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Mant 
                                     - vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Mant));
                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalSign 
                    = (1U & (~ (IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__largerMag)));
                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                    = (0xffffffU & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__sumMants);
                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                    = (0xffffffU & ((0x1000000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__sumMants)
                                     ? ((IData)(0xffffffffU) 
                                        * vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)
                                     : vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant));
            } else {
                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Mant 
                                     + vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Mant));
                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp)));
                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalSign = 1U;
                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__sumMants 
                                    >> 1U));
            }
        }
    }
    if ((0x800000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
            = (0xffffffU & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                            << 1U));
    } else {
        if ((0x400000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                = (0xffffffU & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                << 2U));
            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                            - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                    << 3U));
                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                    = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                        = (0xffffffU & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                        << 4U));
                    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                        = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                            = (0xffffffU & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                            << 5U));
                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                            = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                << 6U));
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                    = (0xffffffU & 
                                       (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                        << 7U));
                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                    = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                                    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                        = (0xffffffU 
                                           & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                              << 8U));
                                    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                            = (0xffffffU 
                                               & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                  << 9U));
                                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                = (0xffffffU 
                                                   & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                      << 0xaU));
                                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                        << 0xbU));
                                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                                                    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                            << 0xcU));
                                                    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                                                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                << 0xdU));
                                                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                                                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                    << 0xeU));
                                                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                                                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                        << 0xfU));
                                                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                                                                    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                            << 0x10U));
                                                                    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                                                                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                                << 0x11U));
                                                                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                                                                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                                << 0x12U));
                                                                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                                << 0x13U));
                                                                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                                << 0x14U));
                                                                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                                << 0x15U));
                                                                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                                << 0x16U));
                                                                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                                                << 0x17U));
                                                                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
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
    if (((0U == vlSymsp->TOP__fpu_top__DOT__fmadd1__DOT__fmul1.__PVT__r0__DOT__rounded) 
         & (0U == (IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Exp)))) {
        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant = 0U;
        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp = 0U;
    }
    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalSign = 0U;
    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__largerMag = 0U;
    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Exp 
        = (0xffU & (vlSymsp->TOP__fpu_top__DOT__fnmadd1__DOT__fmul1.__PVT__r0__DOT__rounded 
                    >> 0x17U));
    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Exp 
        = (0xffU & (vlTOPp->fpu_top__DOT__operand_three 
                    >> 0x17U));
    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Mant 
        = (0x800000U | (0x7fffffU & vlSymsp->TOP__fpu_top__DOT__fnmadd1__DOT__fmul1.__PVT__r0__DOT__rounded));
    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Mant 
        = (0x800000U | (0x7fffffU & vlTOPp->fpu_top__DOT__operand_three));
    if (((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Exp) 
         < (IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Exp))) {
        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
            = vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Exp;
        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Mant 
            = ((0x17U >= (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                   - (IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Exp))))
                ? (0xffffffU & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Mant 
                                >> (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                             - (IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Exp)))))
                : 0U);
        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__largerMag = 1U;
    } else {
        if (((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Exp) 
             < (IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Exp))) {
            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                = vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Exp;
            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Mant 
                = ((0x17U >= (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                       - (IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Exp))))
                    ? (0xffffffU & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Mant 
                                    >> (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                                 - (IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Exp)))))
                    : 0U);
            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__largerMag = 0U;
        } else {
            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                = vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Exp;
            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__largerMag 
                = (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Mant 
                   > vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Mant);
        }
    }
    if ((0x80000000U & (vlSymsp->TOP__fpu_top__DOT__fnmadd1__DOT__fmul1.__PVT__r0__DOT__rounded 
                        & vlTOPp->fpu_top__DOT__operand_three))) {
        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__sumMants 
            = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Mant 
                             + vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Mant));
        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
            = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp)));
        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalSign = 0U;
        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
            = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__sumMants 
                            >> 1U));
    } else {
        if ((1U & ((vlSymsp->TOP__fpu_top__DOT__fnmadd1__DOT__fmul1.__PVT__r0__DOT__rounded 
                    >> 0x1fU) & (~ (vlTOPp->fpu_top__DOT__operand_three 
                                    >> 0x1fU))))) {
            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__sumMants 
                = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Mant 
                                 - vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Mant));
            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalSign 
                = vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__largerMag;
            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                = (0xffffffU & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__sumMants);
            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                = (0xffffffU & ((0x1000000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__sumMants)
                                 ? ((IData)(0xffffffffU) 
                                    * vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)
                                 : vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant));
        } else {
            if ((1U & ((~ (vlSymsp->TOP__fpu_top__DOT__fnmadd1__DOT__fmul1.__PVT__r0__DOT__rounded 
                           >> 0x1fU)) & (vlTOPp->fpu_top__DOT__operand_three 
                                         >> 0x1fU)))) {
                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Mant 
                                     - vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Mant));
                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalSign 
                    = (1U & (~ (IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__largerMag)));
                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                    = (0xffffffU & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__sumMants);
                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                    = (0xffffffU & ((0x1000000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__sumMants)
                                     ? ((IData)(0xffffffffU) 
                                        * vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)
                                     : vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant));
            } else {
                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__sumMants 
                    = (0x1ffffffU & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Mant 
                                     + vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Mant));
                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp)));
                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalSign = 1U;
                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__sumMants 
                                    >> 1U));
            }
        }
    }
    if ((0x800000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
            = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                            << 1U));
    } else {
        if ((0x400000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                << 2U));
            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                            - (IData)(1U)));
        } else {
            if ((0x200000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                    = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                    << 3U));
                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                    = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                - (IData)(2U)));
            } else {
                if ((0x100000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                        = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                        << 4U));
                    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                        = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                    - (IData)(3U)));
                } else {
                    if ((0x80000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                            = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                            << 5U));
                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                            = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                        - (IData)(4U)));
                    } else {
                        if ((0x40000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                << 6U));
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                            - (IData)(5U)));
                        } else {
                            if ((0x20000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                    = (0xffffffU & 
                                       (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                        << 7U));
                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                    = (0xffU & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                                - (IData)(6U)));
                            } else {
                                if ((0x10000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                                    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                        = (0xffffffU 
                                           & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                              << 8U));
                                    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                            - (IData)(7U)));
                                } else {
                                    if ((0x8000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                            = (0xffffffU 
                                               & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                  << 9U));
                                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                            = (0xffU 
                                               & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                                  - (IData)(8U)));
                                    } else {
                                        if ((0x4000U 
                                             & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                = (0xffffffU 
                                                   & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                      << 0xaU));
                                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                                      - (IData)(9U)));
                                        } else {
                                            if ((0x2000U 
                                                 & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                    = 
                                                    (0xffffffU 
                                                     & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                        << 0xbU));
                                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                                        - (IData)(0xaU)));
                                            } else {
                                                if (
                                                    (0x1000U 
                                                     & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                                                    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                        = 
                                                        (0xffffffU 
                                                         & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                            << 0xcU));
                                                    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                                            - (IData)(0xbU)));
                                                } else {
                                                    if (
                                                        (0x800U 
                                                         & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                                                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                            = 
                                                            (0xffffffU 
                                                             & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                << 0xdU));
                                                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                                                - (IData)(0xcU)));
                                                    } else {
                                                        if (
                                                            (0x400U 
                                                             & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                                                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                = 
                                                                (0xffffffU 
                                                                 & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                    << 0xeU));
                                                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                                                = 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                                                    - (IData)(0xdU)));
                                                        } else {
                                                            if (
                                                                (0x200U 
                                                                 & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                                                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                    = 
                                                                    (0xffffffU 
                                                                     & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                        << 0xfU));
                                                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                                                    = 
                                                                    (0xffU 
                                                                     & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                                                        - (IData)(0xeU)));
                                                            } else {
                                                                if (
                                                                    (0x100U 
                                                                     & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                                                                    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                        = 
                                                                        (0xffffffU 
                                                                         & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                            << 0x10U));
                                                                    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                                                        = 
                                                                        (0xffU 
                                                                         & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                                                            - (IData)(0xfU)));
                                                                } else {
                                                                    if (
                                                                        (0x80U 
                                                                         & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                                                                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                            = 
                                                                            (0xffffffU 
                                                                             & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                                << 0x11U));
                                                                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                                                            = 
                                                                            (0xffU 
                                                                             & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x10U)));
                                                                    } else {
                                                                        if (
                                                                            (0x40U 
                                                                             & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                                                                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                                << 0x12U));
                                                                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x11U)));
                                                                        } else {
                                                                            if (
                                                                                (0x20U 
                                                                                & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                                << 0x13U));
                                                                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x12U)));
                                                                            } else {
                                                                                if (
                                                                                (0x10U 
                                                                                & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                                << 0x14U));
                                                                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x13U)));
                                                                                } else {
                                                                                if (
                                                                                (8U 
                                                                                & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                                << 0x15U));
                                                                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x14U)));
                                                                                } else {
                                                                                if (
                                                                                (4U 
                                                                                & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                                << 0x16U));
                                                                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x15U)));
                                                                                } else {
                                                                                if (
                                                                                (2U 
                                                                                & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant)) {
                                                                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                                = 
                                                                                (0xffffffU 
                                                                                & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                                                << 0x17U));
                                                                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                                                                - (IData)(0x16U)));
                                                                                } else {
                                                                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
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
    if (((0U == vlSymsp->TOP__fpu_top__DOT__fnmadd1__DOT__fmul1.__PVT__r0__DOT__rounded) 
         & (0U == (IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Exp)))) {
        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant = 0U;
        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp = 0U;
    }
    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
        = ((0x80000000U & ((~ (IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalSign)) 
                           << 0x1fU)) | (((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                          << 0x17U) 
                                         | (0x7fffffU 
                                            & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                               >> 1U))));
    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
        = ((0x80000000U & ((~ (IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalSign)) 
                           << 0x1fU)) | (((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                          << 0x17U) 
                                         | (0x7fffffU 
                                            & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                               >> 1U))));
    if ((0U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
        if ((4U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded)) {
            if ((0U == (3U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded))) {
                if ((8U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded)) {
                    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                        = (0x7fffffU & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded);
                    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                        = (0xffffffU & ((IData)(1U) 
                                        + vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck));
                    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                        = ((0x800000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                            ? ((0x80000000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded) 
                               | ((0x7f800000U & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                                                    >> 0x17U)) 
                                                  << 0x17U)) 
                                  | (0x7fffffU & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)))
                            : ((0xff800000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded) 
                               | (0x7fffffU & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
                } else {
                    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                        = vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded;
                }
            } else {
                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                    = (0x7fffffU & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded);
                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                    = (0xffffffU & ((IData)(1U) + vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck));
                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                    = ((0x800000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                        ? ((0x80000000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded) 
                           | ((0x7f800000U & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                              | (0x7fffffU & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)))
                        : ((0xff800000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded) 
                           | (0x7fffffU & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
            }
        } else {
            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                = vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded;
        }
    } else {
        if ((1U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i 
                = VL_EXTENDS_II(32,8, (0xffU & ((vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                                                 >> 0x17U) 
                                                - (IData)(0x7fU))));
            if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i) 
                 & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i))) {
                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                    = ((0x16U >= vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i)
                        ? (0x7fffffU & (0x7fffffU >> vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i))
                        : 0U);
                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                    = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask));
                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                    = ((0xff800000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded) 
                       | (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                          & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask));
            } else {
                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                    = ((0U == vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i)
                        ? 0x3f800000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                          ? vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded
                                          : 0U));
            }
        } else {
            if ((2U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                if ((0x80000000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded)) {
                    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i 
                        = VL_EXTENDS_II(32,8, (0xffU 
                                               & ((vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                                                   >> 0x17U) 
                                                  - (IData)(0x7fU))));
                    if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i) 
                         & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i))) {
                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                            = ((0x16U >= vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                ? (0x7fffffU & (0x7fffffU 
                                                >> vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask2 
                            = ((0x16U >= (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i 
                                          - (IData)(1U)))
                                ? (0x7fffffU & (0x400000U 
                                                >> 
                                                (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i 
                                                 - (IData)(1U))))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                            = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask));
                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                            = (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                               & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask);
                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                            = vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask;
                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                            = (0xffffffU & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                            + vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask2));
                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                            = ((0x800000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                                ? ((0x80000000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded) 
                                   | ((0x7f800000U 
                                       & (((IData)(1U) 
                                           + (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                                              >> 0x17U)) 
                                          << 0x17U)) 
                                      | (0x7fffffU 
                                         & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded)))
                                : ((0xff800000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded) 
                                   | (0x7fffffU & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
                    } else {
                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                            = ((0U == vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                ? 0x40000000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                                  ? vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded
                                                  : 0U));
                    }
                } else {
                    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i 
                        = VL_EXTENDS_II(32,8, (0xffU 
                                               & ((vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                                                   >> 0x17U) 
                                                  - (IData)(0x7fU))));
                    if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i) 
                         & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i))) {
                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                            = ((0x16U >= vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                ? (0x7fffffU & (0x7fffffU 
                                                >> vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                            = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask));
                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                            = ((0xff800000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded) 
                               | (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                                  & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask));
                    } else {
                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                            = ((0U == vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                ? 0x3f800000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                                  ? vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded
                                                  : 0U));
                    }
                }
            } else {
                if ((3U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                    if ((0x80000000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded)) {
                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                = ((0xff800000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded) 
                                   | (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                                      & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask));
                        } else {
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                    ? 0x3f800000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded
                                     : 0U));
                        }
                    } else {
                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask2 
                                = ((0x16U >= (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i 
                                              - (IData)(1U)))
                                    ? (0x7fffffU & 
                                       (0x400000U >> 
                                        (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i 
                                         - (IData)(1U))))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                                = (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                                   & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask);
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                = vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask;
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                                + vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask2));
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                = ((0x800000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                                    ? ((0x80000000U 
                                        & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded) 
                                       | ((0x7f800000U 
                                           & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                                          | (0x7fffffU 
                                             & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded)))
                                    : ((0xff800000U 
                                        & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded) 
                                       | (0x7fffffU 
                                          & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
                        } else {
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                    ? 0x40000000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded
                                     : 0U));
                        }
                    }
                } else {
                    if ((4U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                        vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask2 
                                = ((0x16U >= (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i 
                                              - (IData)(1U)))
                                    ? (0x7fffffU & 
                                       (0x400000U >> 
                                        (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i 
                                         - (IData)(1U))))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                                = (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                                   & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask);
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                = vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask;
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                                + vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask2));
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                = ((0x800000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                                    ? ((0x80000000U 
                                        & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded) 
                                       | ((0x7f800000U 
                                           & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                                          | (0x7fffffU 
                                             & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded)))
                                    : ((0xff800000U 
                                        & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded) 
                                       | (0x7fffffU 
                                          & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
                        } else {
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                    ? 0x40000000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded
                                     : 0U));
                        }
                    } else {
                        if ((4U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded)) {
                            if ((0U == (3U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded))) {
                                if ((8U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded)) {
                                    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                        = (0x7fffffU 
                                           & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded);
                                    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                        = (0xffffffU 
                                           & ((IData)(1U) 
                                              + vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck));
                                    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                        = ((0x800000U 
                                            & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                                            ? ((0x80000000U 
                                                & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded) 
                                               | ((0x7f800000U 
                                                   & (((IData)(1U) 
                                                       + 
                                                       (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                                                        >> 0x17U)) 
                                                      << 0x17U)) 
                                                  | (0x7fffffU 
                                                     & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)))
                                            : ((0xff800000U 
                                                & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded) 
                                               | (0x7fffffU 
                                                  & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
                                } else {
                                    vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                        = vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded;
                                }
                            } else {
                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                    = (0x7fffffU & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded);
                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                    = (0xffffffU & 
                                       ((IData)(1U) 
                                        + vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck));
                                vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                    = ((0x800000U & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                                        ? ((0x80000000U 
                                            & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded) 
                                           | ((0x7f800000U 
                                               & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded 
                                                    >> 0x17U)) 
                                                  << 0x17U)) 
                                              | (0x7fffffU 
                                                 & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)))
                                        : ((0xff800000U 
                                            & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded) 
                                           | (0x7fffffU 
                                              & vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
                            }
                        } else {
                            vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                = vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded;
                        }
                    }
                }
            }
        }
    }
    if ((0U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
        if ((4U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded)) {
            if ((0U == (3U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded))) {
                if ((8U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded)) {
                    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                        = (0x7fffffU & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded);
                    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                        = (0xffffffU & ((IData)(1U) 
                                        + vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck));
                    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                        = ((0x800000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                            ? ((0x80000000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded) 
                               | ((0x7f800000U & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                                                    >> 0x17U)) 
                                                  << 0x17U)) 
                                  | (0x7fffffU & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)))
                            : ((0xff800000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded) 
                               | (0x7fffffU & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
                } else {
                    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                        = vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded;
                }
            } else {
                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                    = (0x7fffffU & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded);
                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                    = (0xffffffU & ((IData)(1U) + vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck));
                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                    = ((0x800000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                        ? ((0x80000000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded) 
                           | ((0x7f800000U & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                              | (0x7fffffU & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)))
                        : ((0xff800000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded) 
                           | (0x7fffffU & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
            }
        } else {
            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                = vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded;
        }
    } else {
        if ((1U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i 
                = VL_EXTENDS_II(32,8, (0xffU & ((vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                                                 >> 0x17U) 
                                                - (IData)(0x7fU))));
            if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i) 
                 & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i))) {
                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                    = ((0x16U >= vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i)
                        ? (0x7fffffU & (0x7fffffU >> vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i))
                        : 0U);
                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                    = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask));
                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                    = ((0xff800000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded) 
                       | (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                          & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask));
            } else {
                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                    = ((0U == vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i)
                        ? 0x3f800000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                          ? vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded
                                          : 0U));
            }
        } else {
            if ((2U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                if ((0x80000000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded)) {
                    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i 
                        = VL_EXTENDS_II(32,8, (0xffU 
                                               & ((vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                                                   >> 0x17U) 
                                                  - (IData)(0x7fU))));
                    if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i) 
                         & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i))) {
                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                            = ((0x16U >= vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                ? (0x7fffffU & (0x7fffffU 
                                                >> vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask2 
                            = ((0x16U >= (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i 
                                          - (IData)(1U)))
                                ? (0x7fffffU & (0x400000U 
                                                >> 
                                                (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i 
                                                 - (IData)(1U))))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                            = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask));
                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                            = (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                               & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask);
                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                            = vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask;
                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                            = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                            + vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask2));
                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                            = ((0x800000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                                ? ((0x80000000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded) 
                                   | ((0x7f800000U 
                                       & (((IData)(1U) 
                                           + (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                                              >> 0x17U)) 
                                          << 0x17U)) 
                                      | (0x7fffffU 
                                         & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded)))
                                : ((0xff800000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded) 
                                   | (0x7fffffU & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
                    } else {
                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                            = ((0U == vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                ? 0x40000000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                                  ? vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded
                                                  : 0U));
                    }
                } else {
                    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i 
                        = VL_EXTENDS_II(32,8, (0xffU 
                                               & ((vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                                                   >> 0x17U) 
                                                  - (IData)(0x7fU))));
                    if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i) 
                         & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i))) {
                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                            = ((0x16U >= vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                ? (0x7fffffU & (0x7fffffU 
                                                >> vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i))
                                : 0U);
                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                            = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask));
                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                            = ((0xff800000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded) 
                               | (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                                  & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask));
                    } else {
                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                            = ((0U == vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                ? 0x3f800000U : (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                                  ? vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded
                                                  : 0U));
                    }
                }
            } else {
                if ((3U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                    if ((0x80000000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded)) {
                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                = ((0xff800000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded) 
                                   | (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                                      & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask));
                        } else {
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                    ? 0x3f800000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded
                                     : 0U));
                        }
                    } else {
                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask2 
                                = ((0x16U >= (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i 
                                              - (IData)(1U)))
                                    ? (0x7fffffU & 
                                       (0x400000U >> 
                                        (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i 
                                         - (IData)(1U))))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                                = (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                                   & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask);
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                = vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask;
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                                + vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask2));
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                = ((0x800000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                                    ? ((0x80000000U 
                                        & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded) 
                                       | ((0x7f800000U 
                                           & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                                          | (0x7fffffU 
                                             & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded)))
                                    : ((0xff800000U 
                                        & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded) 
                                       | (0x7fffffU 
                                          & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
                        } else {
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                    ? 0x40000000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded
                                     : 0U));
                        }
                    }
                } else {
                    if ((4U == (IData)(vlTOPp->fpu_top__DOT__rm))) {
                        vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i 
                            = VL_EXTENDS_II(32,8, (0xffU 
                                                   & ((vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                                                       >> 0x17U) 
                                                      - (IData)(0x7fU))));
                        if ((VL_LTS_III(1,32,32, 0U, vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i) 
                             & VL_GTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i))) {
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                                = ((0x16U >= vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                    ? (0x7fffffU & 
                                       (0x7fffffU >> vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask2 
                                = ((0x16U >= (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i 
                                              - (IData)(1U)))
                                    ? (0x7fffffU & 
                                       (0x400000U >> 
                                        (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i 
                                         - (IData)(1U))))
                                    : 0U);
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                                = (0x7fffffU & (~ vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask));
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask 
                                = (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                                   & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask);
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                = vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask;
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                = (0xffffffU & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                                + vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask2));
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                = ((0x800000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                                    ? ((0x80000000U 
                                        & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded) 
                                       | ((0x7f800000U 
                                           & (((IData)(1U) 
                                               + (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                                                  >> 0x17U)) 
                                              << 0x17U)) 
                                          | (0x7fffffU 
                                             & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded)))
                                    : ((0xff800000U 
                                        & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded) 
                                       | (0x7fffffU 
                                          & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
                        } else {
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                = ((0U == vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                    ? 0x40000000U : 
                                   (VL_LTS_III(1,32,32, 0x17U, vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i)
                                     ? vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded
                                     : 0U));
                        }
                    } else {
                        if ((4U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded)) {
                            if ((0U == (3U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded))) {
                                if ((8U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded)) {
                                    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                        = (0x7fffffU 
                                           & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded);
                                    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                        = (0xffffffU 
                                           & ((IData)(1U) 
                                              + vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck));
                                    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                        = ((0x800000U 
                                            & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                                            ? ((0x80000000U 
                                                & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded) 
                                               | ((0x7f800000U 
                                                   & (((IData)(1U) 
                                                       + 
                                                       (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                                                        >> 0x17U)) 
                                                      << 0x17U)) 
                                                  | (0x7fffffU 
                                                     & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)))
                                            : ((0xff800000U 
                                                & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded) 
                                               | (0x7fffffU 
                                                  & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
                                } else {
                                    vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                        = vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded;
                                }
                            } else {
                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                    = (0x7fffffU & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded);
                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck 
                                    = (0xffffffU & 
                                       ((IData)(1U) 
                                        + vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck));
                                vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                    = ((0x800000U & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)
                                        ? ((0x80000000U 
                                            & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded) 
                                           | ((0x7f800000U 
                                               & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded 
                                                    >> 0x17U)) 
                                                  << 0x17U)) 
                                              | (0x7fffffU 
                                                 & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)))
                                        : ((0xff800000U 
                                            & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded) 
                                           | (0x7fffffU 
                                              & vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck)));
                            }
                        } else {
                            vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded 
                                = vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded;
                        }
                    }
                }
            }
        }
    }
}

VL_INLINE_OPT void Vfpu_top::_combo__TOP__6(Vfpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_top::_combo__TOP__6\n"); );
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
        = (vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num 
           >> 1U);
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
}

void Vfpu_top::_eval(Vfpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_top::_eval\n"); );
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
        vlSymsp->TOP__fpu_top__DOT__fmul1._sequent__TOP__fpu_top__DOT__fmul1__1(vlSymsp);
        vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1._sequent__TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1__2(vlSymsp);
        vlSymsp->TOP__fpu_top__DOT__fmadd1__DOT__fmul1._sequent__TOP__fpu_top__DOT__fmul1__1(vlSymsp);
        vlSymsp->TOP__fpu_top__DOT__fnmsub1__DOT__fmul1._sequent__TOP__fpu_top__DOT__fnmsub1__DOT__fmul1__4(vlSymsp);
        vlSymsp->TOP__fpu_top__DOT__fnmadd1__DOT__fmul1._sequent__TOP__fpu_top__DOT__fnmsub1__DOT__fmul1__4(vlSymsp);
        vlSymsp->TOP__fpu_top__DOT__fmsub1__DOT__fmul1._sequent__TOP__fpu_top__DOT__fmsub1__DOT__fmul1__6(vlSymsp);
        vlSymsp->TOP__fpu_top__DOT__fdiv1__DOT__fm0._sequent__TOP__fpu_top__DOT__fdiv1__DOT__fm0__7(vlSymsp);
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    vlTOPp->_combo__TOP__6(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vfpu_top::_change_request(Vfpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_top::_change_request\n"); );
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vfpu_top::_change_request_1(Vfpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_top::_change_request_1\n"); );
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num ^ vlTOPp->__Vchglast__TOP__fpu_top__DOT__fsqrt1__DOT__shifted_num));
    VL_DEBUG_IF( if(__req && ((vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num ^ vlTOPp->__Vchglast__TOP__fpu_top__DOT__fsqrt1__DOT__shifted_num))) VL_DBG_MSGF("        CHANGE: ..//fsqrt.sv:13: fpu_top.fsqrt1.shifted_num\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__fpu_top__DOT__fsqrt1__DOT__shifted_num 
        = vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num;
    return __req;
}

#ifdef VL_DEBUG
void Vfpu_top::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_top::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
