// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VFMA_H_
#define _VFMA_H_  // guard

#include "verilated.h"

//==========

class VFMA__Syms;

//----------

VL_MODULE(VFMA) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN(a_fp,31,0);
    VL_IN(b_fp,31,0);
    VL_IN(c_fp,31,0);
    VL_OUT(out_fp,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ FMA__DOT__sign_out;
    CData/*0:0*/ FMA__DOT__largerMag;
    CData/*7:0*/ FMA__DOT__exp_out;
    CData/*7:0*/ FMA__DOT__final_exp;
    IData/*23:0*/ FMA__DOT__mantissa_a;
    IData/*23:0*/ FMA__DOT__mantissa_b;
    IData/*23:0*/ FMA__DOT__mantissa_c;
    IData/*23:0*/ FMA__DOT__mantissa_mul_norm;
    IData/*23:0*/ FMA__DOT__final_mantissa;
    IData/*24:0*/ FMA__DOT__sum_mants;
    IData/*31:0*/ FMA__DOT__offset;
    QData/*47:0*/ FMA__DOT__mantissa_mul_out;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VFMA__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VFMA);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VFMA(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VFMA();
    
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
    static void _eval_initial_loop(VFMA__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VFMA__Syms* symsp, bool first);
  private:
    static QData _change_request(VFMA__Syms* __restrict vlSymsp);
    static QData _change_request_1(VFMA__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(VFMA__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VFMA__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VFMA__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VFMA__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
