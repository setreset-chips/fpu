// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VFEXP_H_
#define _VFEXP_H_  // guard

#include "verilated.h"

//==========

class Vfexp__Syms;

//----------

VL_MODULE(Vfexp) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN(exp,31,0);
    VL_OUT(out_num,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ fexp__DOT__fa0__DOT__largerMag;
        CData/*0:0*/ fexp__DOT__fa0__DOT__finalSign;
        CData/*7:0*/ fexp__DOT__fa0__DOT__num1Exp;
        CData/*7:0*/ fexp__DOT__fa0__DOT__num2Exp;
        CData/*7:0*/ fexp__DOT__fa0__DOT__finalExp;
        CData/*7:0*/ fexp__DOT__fm0__DOT__expF;
        CData/*0:0*/ fexp__DOT__fma0__DOT__sign_out;
        CData/*0:0*/ fexp__DOT__fma0__DOT__largerMag;
        CData/*7:0*/ fexp__DOT__fma0__DOT__exp_out;
        CData/*7:0*/ fexp__DOT__fma0__DOT__final_exp;
        CData/*7:0*/ fexp__DOT__fm1__DOT__expF;
        CData/*0:0*/ fexp__DOT__fma1__DOT__sign_out;
        CData/*0:0*/ fexp__DOT__fma1__DOT__largerMag;
        CData/*7:0*/ fexp__DOT__fma1__DOT__exp_out;
        CData/*7:0*/ fexp__DOT__fma1__DOT__final_exp;
        CData/*7:0*/ fexp__DOT__fm2__DOT__expF;
        CData/*0:0*/ fexp__DOT__fma2__DOT__sign_out;
        CData/*0:0*/ fexp__DOT__fma2__DOT__largerMag;
        CData/*7:0*/ fexp__DOT__fma2__DOT__exp_out;
        CData/*7:0*/ fexp__DOT__fma2__DOT__final_exp;
        CData/*7:0*/ fexp__DOT__fm3__DOT__expF;
        CData/*0:0*/ fexp__DOT__fma3__DOT__sign_out;
        CData/*0:0*/ fexp__DOT__fma3__DOT__largerMag;
        CData/*7:0*/ fexp__DOT__fma3__DOT__exp_out;
        CData/*7:0*/ fexp__DOT__fma3__DOT__final_exp;
        IData/*31:0*/ fexp__DOT__temp1;
        IData/*31:0*/ fexp__DOT__temp2;
        IData/*31:0*/ fexp__DOT__temp3;
        IData/*31:0*/ fexp__DOT__temp4;
        IData/*31:0*/ fexp__DOT__temp5;
        IData/*31:0*/ fexp__DOT__temp6;
        IData/*31:0*/ fexp__DOT__temp7;
        IData/*31:0*/ fexp__DOT__temp8;
        IData/*23:0*/ fexp__DOT__fa0__DOT__num1Mant;
        IData/*23:0*/ fexp__DOT__fa0__DOT__num2Mant;
        IData/*23:0*/ fexp__DOT__fa0__DOT__finalMant;
        IData/*24:0*/ fexp__DOT__fa0__DOT__sumMants;
        IData/*22:0*/ fexp__DOT__fm0__DOT__mantissa;
        IData/*23:0*/ fexp__DOT__fma0__DOT__mantissa_a;
        IData/*23:0*/ fexp__DOT__fma0__DOT__mantissa_c;
        IData/*23:0*/ fexp__DOT__fma0__DOT__mantissa_mul_norm;
        IData/*23:0*/ fexp__DOT__fma0__DOT__final_mantissa;
        IData/*24:0*/ fexp__DOT__fma0__DOT__sum_mants;
        IData/*22:0*/ fexp__DOT__fm1__DOT__mantissa;
        IData/*23:0*/ fexp__DOT__fma1__DOT__mantissa_a;
        IData/*23:0*/ fexp__DOT__fma1__DOT__mantissa_c;
        IData/*23:0*/ fexp__DOT__fma1__DOT__mantissa_mul_norm;
        IData/*23:0*/ fexp__DOT__fma1__DOT__final_mantissa;
        IData/*24:0*/ fexp__DOT__fma1__DOT__sum_mants;
        IData/*22:0*/ fexp__DOT__fm2__DOT__mantissa;
        IData/*23:0*/ fexp__DOT__fma2__DOT__mantissa_a;
        IData/*23:0*/ fexp__DOT__fma2__DOT__mantissa_c;
        IData/*23:0*/ fexp__DOT__fma2__DOT__mantissa_mul_norm;
        IData/*23:0*/ fexp__DOT__fma2__DOT__final_mantissa;
        IData/*24:0*/ fexp__DOT__fma2__DOT__sum_mants;
        IData/*22:0*/ fexp__DOT__fm3__DOT__mantissa;
        IData/*23:0*/ fexp__DOT__fma3__DOT__mantissa_a;
        IData/*23:0*/ fexp__DOT__fma3__DOT__mantissa_c;
        IData/*23:0*/ fexp__DOT__fma3__DOT__mantissa_mul_norm;
        IData/*23:0*/ fexp__DOT__fma3__DOT__final_mantissa;
        IData/*24:0*/ fexp__DOT__fma3__DOT__sum_mants;
        QData/*47:0*/ fexp__DOT__fm0__DOT__mantissaProd;
        QData/*47:0*/ fexp__DOT__fma0__DOT__mantissa_mul_out;
        QData/*47:0*/ fexp__DOT__fm1__DOT__mantissaProd;
    };
    struct {
        QData/*47:0*/ fexp__DOT__fma1__DOT__mantissa_mul_out;
        QData/*47:0*/ fexp__DOT__fm2__DOT__mantissaProd;
        QData/*47:0*/ fexp__DOT__fma2__DOT__mantissa_mul_out;
        QData/*47:0*/ fexp__DOT__fm3__DOT__mantissaProd;
        QData/*47:0*/ fexp__DOT__fma3__DOT__mantissa_mul_out;
    };
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vfexp__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vfexp);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vfexp(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vfexp();
    
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
    static void _eval_initial_loop(Vfexp__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vfexp__Syms* symsp, bool first);
  private:
    static QData _change_request(Vfexp__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vfexp__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vfexp__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vfexp__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vfexp__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vfexp__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
