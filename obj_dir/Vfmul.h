// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VFMUL_H_
#define _VFMUL_H_  // guard

#include "verilated.h"

//==========

class Vfmul__Syms;

//----------

VL_MODULE(Vfmul) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN(num1,31,0);
    VL_IN(num2,31,0);
    VL_OUT(out_mul,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*7:0*/ fmul__DOT__expF;
    IData/*22:0*/ fmul__DOT__mantissa;
    IData/*31:0*/ fmul__DOT__i;
    QData/*47:0*/ fmul__DOT__mantissaProd;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vfmul__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vfmul);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vfmul(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vfmul();
    
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
    static void _eval_initial_loop(Vfmul__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vfmul__Syms* symsp, bool first);
  private:
    static QData _change_request(Vfmul__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vfmul__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vfmul__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vfmul__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vfmul__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vfmul__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
