// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VFPU_TOP_H_
#define _VFPU_TOP_H_  // guard

#include "verilated.h"

//==========

class Vfpu_top__Syms;
class Vfpu_top_VerilatedVcd;
class Vfpu_top_fmul;


//----------

VL_MODULE(Vfpu_top) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vfpu_top_fmul* __PVT__fpu_top__DOT__fmul1;
    Vfpu_top_fmul* __PVT__fpu_top__DOT__fmadd1__DOT__fmul1;
    Vfpu_top_fmul* __PVT__fpu_top__DOT__fmsub1__DOT__fmul1;
    Vfpu_top_fmul* __PVT__fpu_top__DOT__fnmsub1__DOT__fmul1;
    Vfpu_top_fmul* __PVT__fpu_top__DOT__fnmadd1__DOT__fmul1;
    Vfpu_top_fmul* __PVT__fpu_top__DOT__fdiv1__DOT__fm0;
    Vfpu_top_fmul* __PVT__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN(instruction,31,0);
    VL_OUT(fpu_out,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*4:0*/ fpu_top__DOT__curr_op;
        CData/*4:0*/ fpu_top__DOT__exec_op;
        CData/*2:0*/ fpu_top__DOT__rm;
        CData/*0:0*/ fpu_top__DOT__fmadd1__DOT__fadd1__DOT__largerMag;
        CData/*0:0*/ fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalSign;
        CData/*7:0*/ fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Exp;
        CData/*7:0*/ fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Exp;
        CData/*7:0*/ fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp;
        CData/*0:0*/ fpu_top__DOT__fmsub1__DOT__f1__DOT__largerMag;
        CData/*0:0*/ fpu_top__DOT__fmsub1__DOT__f1__DOT__finalSign;
        CData/*7:0*/ fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Exp;
        CData/*7:0*/ fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Exp;
        CData/*7:0*/ fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp;
        CData/*0:0*/ fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__largerMag;
        CData/*0:0*/ fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalSign;
        CData/*7:0*/ fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Exp;
        CData/*7:0*/ fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Exp;
        CData/*7:0*/ fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp;
        CData/*0:0*/ fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__largerMag;
        CData/*0:0*/ fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalSign;
        CData/*7:0*/ fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Exp;
        CData/*7:0*/ fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Exp;
        CData/*7:0*/ fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp;
        CData/*0:0*/ fpu_top__DOT__fadd1__DOT__largerMag;
        CData/*0:0*/ fpu_top__DOT__fadd1__DOT__finalSign;
        CData/*7:0*/ fpu_top__DOT__fadd1__DOT__num1Exp;
        CData/*7:0*/ fpu_top__DOT__fadd1__DOT__num2Exp;
        CData/*7:0*/ fpu_top__DOT__fadd1__DOT__finalExp;
        CData/*0:0*/ fpu_top__DOT__fsub1__DOT__f1__DOT__largerMag;
        CData/*0:0*/ fpu_top__DOT__fsub1__DOT__f1__DOT__finalSign;
        CData/*7:0*/ fpu_top__DOT__fsub1__DOT__f1__DOT__num1Exp;
        CData/*7:0*/ fpu_top__DOT__fsub1__DOT__f1__DOT__num2Exp;
        CData/*7:0*/ fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp;
        IData/*31:0*/ fpu_top__DOT__operand_1;
        IData/*31:0*/ fpu_top__DOT__operand_2;
        IData/*31:0*/ fpu_top__DOT__operand_3;
        IData/*31:0*/ fpu_top__DOT__fcsr;
        IData/*31:0*/ fpu_top__DOT__ins_p1;
        IData/*31:0*/ fpu_top__DOT__oper1;
        IData/*31:0*/ fpu_top__DOT__oper2;
        IData/*31:0*/ fpu_top__DOT__oper3;
        IData/*31:0*/ fpu_top__DOT__ins_p2;
        IData/*31:0*/ fpu_top__DOT__operand_one;
        IData/*31:0*/ fpu_top__DOT__operand_two;
        IData/*31:0*/ fpu_top__DOT__operand_three;
        IData/*31:0*/ fpu_top__DOT__result;
        IData/*31:0*/ fpu_top__DOT__writeback_data;
        IData/*31:0*/ fpu_top__DOT__ins_p3;
        IData/*23:0*/ fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Mant;
        IData/*23:0*/ fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Mant;
        IData/*23:0*/ fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant;
        IData/*24:0*/ fpu_top__DOT__fmadd1__DOT__fadd1__DOT__sumMants;
        IData/*31:0*/ fpu_top__DOT__fmadd1__DOT__fadd1__DOT__i;
        IData/*31:0*/ fpu_top__DOT__fmadd1__DOT__fadd1__DOT__unrounded;
        IData/*31:0*/ fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__rounded;
        IData/*23:0*/ fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck;
        IData/*22:0*/ fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask;
        IData/*22:0*/ fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__mask2;
        IData/*31:0*/ fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__i;
        IData/*31:0*/ fpu_top__DOT__fmadd1__DOT__fadd1__DOT__r0__DOT__j;
        IData/*23:0*/ fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Mant;
        IData/*23:0*/ fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Mant;
        IData/*23:0*/ fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant;
        IData/*24:0*/ fpu_top__DOT__fmsub1__DOT__f1__DOT__sumMants;
    };
    struct {
        IData/*31:0*/ fpu_top__DOT__fmsub1__DOT__f1__DOT__i;
        IData/*31:0*/ fpu_top__DOT__fmsub1__DOT__f1__DOT__unrounded;
        IData/*31:0*/ fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__rounded;
        IData/*23:0*/ fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__overflowCheck;
        IData/*22:0*/ fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask;
        IData/*22:0*/ fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__mask2;
        IData/*31:0*/ fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__i;
        IData/*31:0*/ fpu_top__DOT__fmsub1__DOT__f1__DOT__r0__DOT__j;
        IData/*31:0*/ fpu_top__DOT__fnmsub1__DOT__in1;
        IData/*23:0*/ fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Mant;
        IData/*23:0*/ fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Mant;
        IData/*23:0*/ fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant;
        IData/*24:0*/ fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__sumMants;
        IData/*31:0*/ fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__i;
        IData/*31:0*/ fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__unrounded;
        IData/*31:0*/ fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded;
        IData/*23:0*/ fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck;
        IData/*22:0*/ fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask;
        IData/*22:0*/ fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask2;
        IData/*31:0*/ fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__i;
        IData/*31:0*/ fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__r0__DOT__j;
        IData/*23:0*/ fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Mant;
        IData/*23:0*/ fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Mant;
        IData/*23:0*/ fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant;
        IData/*24:0*/ fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__sumMants;
        IData/*31:0*/ fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__i;
        IData/*31:0*/ fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__unrounded;
        IData/*31:0*/ fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__rounded;
        IData/*23:0*/ fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__overflowCheck;
        IData/*22:0*/ fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask;
        IData/*22:0*/ fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__mask2;
        IData/*31:0*/ fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__i;
        IData/*31:0*/ fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__r0__DOT__j;
        IData/*23:0*/ fpu_top__DOT__fadd1__DOT__num1Mant;
        IData/*23:0*/ fpu_top__DOT__fadd1__DOT__num2Mant;
        IData/*23:0*/ fpu_top__DOT__fadd1__DOT__finalMant;
        IData/*24:0*/ fpu_top__DOT__fadd1__DOT__sumMants;
        IData/*31:0*/ fpu_top__DOT__fadd1__DOT__i;
        IData/*31:0*/ fpu_top__DOT__fadd1__DOT__unrounded;
        IData/*31:0*/ fpu_top__DOT__fadd1__DOT__r0__DOT__rounded;
        IData/*23:0*/ fpu_top__DOT__fadd1__DOT__r0__DOT__overflowCheck;
        IData/*22:0*/ fpu_top__DOT__fadd1__DOT__r0__DOT__mask;
        IData/*22:0*/ fpu_top__DOT__fadd1__DOT__r0__DOT__mask2;
        IData/*31:0*/ fpu_top__DOT__fadd1__DOT__r0__DOT__i;
        IData/*31:0*/ fpu_top__DOT__fadd1__DOT__r0__DOT__j;
        IData/*23:0*/ fpu_top__DOT__fsub1__DOT__f1__DOT__num1Mant;
        IData/*23:0*/ fpu_top__DOT__fsub1__DOT__f1__DOT__num2Mant;
        IData/*23:0*/ fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant;
        IData/*24:0*/ fpu_top__DOT__fsub1__DOT__f1__DOT__sumMants;
        IData/*31:0*/ fpu_top__DOT__fsub1__DOT__f1__DOT__i;
        IData/*31:0*/ fpu_top__DOT__fsub1__DOT__f1__DOT__unrounded;
        IData/*31:0*/ fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__rounded;
        IData/*23:0*/ fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__overflowCheck;
        IData/*22:0*/ fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask;
        IData/*22:0*/ fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__mask2;
        IData/*31:0*/ fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__i;
        IData/*31:0*/ fpu_top__DOT__fsub1__DOT__f1__DOT__r0__DOT__j;
        IData/*31:0*/ fpu_top__DOT__fsqrt1__DOT__shifted_num;
        IData/*31:0*/ fpu_top__DOT__fsqrt1__DOT__r0__DOT__rounded;
        IData/*23:0*/ fpu_top__DOT__fsqrt1__DOT__r0__DOT__overflowCheck;
        IData/*22:0*/ fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask;
        IData/*22:0*/ fpu_top__DOT__fsqrt1__DOT__r0__DOT__mask2;
        IData/*31:0*/ fpu_top__DOT__fsqrt1__DOT__r0__DOT__i;
        IData/*31:0*/ fpu_top__DOT__fsqrt1__DOT__r0__DOT__j;
    };
    struct {
        IData/*31:0*/ fpu_top__DOT__fmin1__DOT__out;
        IData/*31:0*/ fpu_top__DOT__fmax1__DOT__out;
        IData/*31:0*/ fpu_top__DOT__flt1__DOT__out;
        IData/*31:0*/ fpu_top__DOT__fle1__DOT__out;
        IData/*31:0*/ fpu_top__DOT__fclass1__DOT__result;
        IData/*31:0*/ fpu_top__DOT__regFile[32];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    IData/*31:0*/ fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2;
    IData/*31:0*/ __Vchglast__TOP__fpu_top__DOT__fsqrt1__DOT__shifted_num;
    CData/*0:0*/ __Vm_traceActivity[3];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vfpu_top__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vfpu_top);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vfpu_top(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vfpu_top();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vfpu_top__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vfpu_top__Syms* symsp, bool first);
  private:
    static QData _change_request(Vfpu_top__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vfpu_top__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__6(Vfpu_top__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vfpu_top__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vfpu_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vfpu_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vfpu_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vfpu_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vfpu_top__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(Vfpu_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
