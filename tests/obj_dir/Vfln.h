// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VFLN_H_
#define _VFLN_H_  // guard

#include "verilated.h"

//==========

class Vfln__Syms;
class Vfln_VerilatedVcd;
class Vfln_fmul;


//----------

VL_MODULE(Vfln) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vfln_fmul* __PVT__fln__DOT__fm0;
    Vfln_fmul* __PVT__fln__DOT__fm1;
    Vfln_fmul* __PVT__fln__DOT__fm2;
    Vfln_fmul* __PVT__fln__DOT__fm3;
    Vfln_fmul* __PVT__fln__DOT__fm4;
    Vfln_fmul* __PVT__fln__DOT__fm5;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN(num1,31,0);
    VL_OUT(out1,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ fln__DOT__fa0__DOT__largerMag;
        CData/*0:0*/ fln__DOT__fa0__DOT__finalSign;
        CData/*7:0*/ fln__DOT__fa0__DOT__num1Exp;
        CData/*7:0*/ fln__DOT__fa0__DOT__num2Exp;
        CData/*7:0*/ fln__DOT__fa0__DOT__finalExp;
        CData/*0:0*/ fln__DOT__fma1__DOT__sign_out;
        CData/*0:0*/ fln__DOT__fma1__DOT__largerMag;
        CData/*7:0*/ fln__DOT__fma1__DOT__exp_out;
        CData/*7:0*/ fln__DOT__fma1__DOT__final_exp;
        CData/*0:0*/ fln__DOT__fa1__DOT__largerMag;
        CData/*0:0*/ fln__DOT__fa1__DOT__finalSign;
        CData/*7:0*/ fln__DOT__fa1__DOT__num1Exp;
        CData/*7:0*/ fln__DOT__fa1__DOT__num2Exp;
        CData/*7:0*/ fln__DOT__fa1__DOT__finalExp;
        CData/*0:0*/ fln__DOT__fa2__DOT__largerMag;
        CData/*0:0*/ fln__DOT__fa2__DOT__finalSign;
        CData/*7:0*/ fln__DOT__fa2__DOT__num1Exp;
        CData/*7:0*/ fln__DOT__fa2__DOT__num2Exp;
        CData/*7:0*/ fln__DOT__fa2__DOT__finalExp;
        CData/*0:0*/ fln__DOT__fma2__DOT__sign_out;
        CData/*0:0*/ fln__DOT__fma2__DOT__largerMag;
        CData/*7:0*/ fln__DOT__fma2__DOT__exp_out;
        CData/*7:0*/ fln__DOT__fma2__DOT__final_exp;
        IData/*31:0*/ fln__DOT__temp6;
        IData/*23:0*/ fln__DOT__fa0__DOT__num1Mant;
        IData/*23:0*/ fln__DOT__fa0__DOT__num2Mant;
        IData/*23:0*/ fln__DOT__fa0__DOT__finalMant;
        IData/*24:0*/ fln__DOT__fa0__DOT__sumMants;
        IData/*31:0*/ fln__DOT__fa0__DOT__i;
        IData/*31:0*/ fln__DOT__fa0__DOT__unrounded;
        IData/*31:0*/ fln__DOT__fa0__DOT__r0__DOT__rounded;
        IData/*23:0*/ fln__DOT__fa0__DOT__r0__DOT__overflowCheck;
        IData/*22:0*/ fln__DOT__fa0__DOT__r0__DOT__mask;
        IData/*22:0*/ fln__DOT__fa0__DOT__r0__DOT__mask2;
        IData/*31:0*/ fln__DOT__fa0__DOT__r0__DOT__i;
        IData/*31:0*/ fln__DOT__fa0__DOT__r0__DOT__j;
        IData/*23:0*/ fln__DOT__fma1__DOT__mantissa_a;
        IData/*23:0*/ fln__DOT__fma1__DOT__mantissa_c;
        IData/*23:0*/ fln__DOT__fma1__DOT__mantissa_mul_norm;
        IData/*23:0*/ fln__DOT__fma1__DOT__final_mantissa;
        IData/*24:0*/ fln__DOT__fma1__DOT__sum_mants;
        IData/*23:0*/ fln__DOT__fa1__DOT__num1Mant;
        IData/*23:0*/ fln__DOT__fa1__DOT__num2Mant;
        IData/*23:0*/ fln__DOT__fa1__DOT__finalMant;
        IData/*24:0*/ fln__DOT__fa1__DOT__sumMants;
        IData/*31:0*/ fln__DOT__fa1__DOT__i;
        IData/*31:0*/ fln__DOT__fa1__DOT__unrounded;
        IData/*31:0*/ fln__DOT__fa1__DOT__r0__DOT__rounded;
        IData/*23:0*/ fln__DOT__fa1__DOT__r0__DOT__overflowCheck;
        IData/*22:0*/ fln__DOT__fa1__DOT__r0__DOT__mask;
        IData/*22:0*/ fln__DOT__fa1__DOT__r0__DOT__mask2;
        IData/*31:0*/ fln__DOT__fa1__DOT__r0__DOT__i;
        IData/*31:0*/ fln__DOT__fa1__DOT__r0__DOT__j;
        IData/*23:0*/ fln__DOT__fa2__DOT__num1Mant;
        IData/*23:0*/ fln__DOT__fa2__DOT__num2Mant;
        IData/*23:0*/ fln__DOT__fa2__DOT__finalMant;
        IData/*24:0*/ fln__DOT__fa2__DOT__sumMants;
        IData/*31:0*/ fln__DOT__fa2__DOT__i;
        IData/*31:0*/ fln__DOT__fa2__DOT__unrounded;
        IData/*31:0*/ fln__DOT__fa2__DOT__r0__DOT__rounded;
        IData/*23:0*/ fln__DOT__fa2__DOT__r0__DOT__overflowCheck;
        IData/*22:0*/ fln__DOT__fa2__DOT__r0__DOT__mask;
        IData/*22:0*/ fln__DOT__fa2__DOT__r0__DOT__mask2;
        IData/*31:0*/ fln__DOT__fa2__DOT__r0__DOT__i;
    };
    struct {
        IData/*31:0*/ fln__DOT__fa2__DOT__r0__DOT__j;
        IData/*23:0*/ fln__DOT__fma2__DOT__mantissa_a;
        IData/*23:0*/ fln__DOT__fma2__DOT__mantissa_c;
        IData/*23:0*/ fln__DOT__fma2__DOT__mantissa_mul_norm;
        IData/*23:0*/ fln__DOT__fma2__DOT__final_mantissa;
        IData/*24:0*/ fln__DOT__fma2__DOT__sum_mants;
        QData/*47:0*/ fln__DOT__fma1__DOT__mantissa_mul_out;
        QData/*47:0*/ fln__DOT__fma2__DOT__mantissa_mul_out;
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vm_traceActivity[2];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vfln__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vfln);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vfln(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vfln();
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
    static void _eval_initial_loop(Vfln__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vfln__Syms* symsp, bool first);
  private:
    static QData _change_request(Vfln__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vfln__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vfln__Syms* __restrict vlSymsp);
    static void _combo__TOP__2(Vfln__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vfln__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vfln__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vfln__Syms* __restrict vlSymsp) VL_ATTR_COLD;
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
