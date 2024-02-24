// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VFADD_H_
#define _VFADD_H_  // guard

#include "verilated.h"

//==========

class Vfadd__Syms;

//----------

VL_MODULE(Vfadd) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN(num1,31,0);
    VL_IN(num2,31,0);
    VL_OUT(out_num,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ fadd__DOT__largerMag;
    CData/*0:0*/ fadd__DOT__finalSign;
    CData/*7:0*/ fadd__DOT__num1Exp;
    CData/*7:0*/ fadd__DOT__num2Exp;
    CData/*7:0*/ fadd__DOT__finalExp;
    IData/*23:0*/ fadd__DOT__num1Mant;
    IData/*23:0*/ fadd__DOT__num2Mant;
    IData/*23:0*/ fadd__DOT__finalMant;
    IData/*24:0*/ fadd__DOT__sumMants;
    IData/*31:0*/ fadd__DOT__i;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vfadd__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vfadd);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vfadd(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vfadd();
    
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
    static void _eval_initial_loop(Vfadd__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vfadd__Syms* symsp, bool first);
  private:
    static QData _change_request(Vfadd__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vfadd__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vfadd__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vfadd__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vfadd__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vfadd__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
