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

//----------

VL_MODULE(Vfln) {
  public:
    
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
        CData/*7:0*/ fln__DOT__fi0__DOT__f1__DOT__expF;
        CData/*7:0*/ fln__DOT__fm0__DOT__expF;
        CData/*7:0*/ fln__DOT__fm1__DOT__expF;
        CData/*7:0*/ fln__DOT__fm2__DOT__expF;
        CData/*7:0*/ fln__DOT__fm3__DOT__expF;
        CData/*7:0*/ fln__DOT__fm4__DOT__expF;
        CData/*7:0*/ fln__DOT__fm5__DOT__expF;
        CData/*7:0*/ fln__DOT__fm6__DOT__expF;
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
        CData/*0:0*/ fln__DOT__fa3__DOT__largerMag;
        CData/*0:0*/ fln__DOT__fa3__DOT__finalSign;
        CData/*7:0*/ fln__DOT__fa3__DOT__num1Exp;
        CData/*7:0*/ fln__DOT__fa3__DOT__num2Exp;
        CData/*7:0*/ fln__DOT__fa3__DOT__finalExp;
        CData/*0:0*/ fln__DOT__fa4__DOT__largerMag;
        CData/*0:0*/ fln__DOT__fa4__DOT__finalSign;
        CData/*7:0*/ fln__DOT__fa4__DOT__num1Exp;
        CData/*7:0*/ fln__DOT__fa4__DOT__num2Exp;
        CData/*7:0*/ fln__DOT__fa4__DOT__finalExp;
        IData/*31:0*/ fln__DOT__temp1;
        IData/*31:0*/ fln__DOT__temp2;
        IData/*31:0*/ fln__DOT__temp3i;
        IData/*31:0*/ fln__DOT__temp3;
        IData/*31:0*/ fln__DOT__temp4i;
        IData/*31:0*/ fln__DOT__temp4;
        IData/*31:0*/ fln__DOT__temp5i;
        IData/*31:0*/ fln__DOT__temp5;
        IData/*31:0*/ fln__DOT__temp6;
        IData/*31:0*/ fln__DOT__temp7;
        IData/*31:0*/ fln__DOT__temp8i;
        IData/*31:0*/ fln__DOT__op1i;
        IData/*23:0*/ fln__DOT__fa0__DOT__num1Mant;
        IData/*23:0*/ fln__DOT__fa0__DOT__num2Mant;
        IData/*23:0*/ fln__DOT__fa0__DOT__finalMant;
        IData/*24:0*/ fln__DOT__fa0__DOT__sumMants;
        IData/*31:0*/ fln__DOT__fa0__DOT__i;
        IData/*22:0*/ fln__DOT__fi0__DOT__f1__DOT__mantissa;
        IData/*31:0*/ fln__DOT__fi0__DOT__f1__DOT__i;
        IData/*22:0*/ fln__DOT__fm0__DOT__mantissa;
        IData/*31:0*/ fln__DOT__fm0__DOT__i;
        IData/*22:0*/ fln__DOT__fm1__DOT__mantissa;
        IData/*31:0*/ fln__DOT__fm1__DOT__i;
        IData/*22:0*/ fln__DOT__fm2__DOT__mantissa;
        IData/*31:0*/ fln__DOT__fm2__DOT__i;
        IData/*22:0*/ fln__DOT__fm3__DOT__mantissa;
        IData/*31:0*/ fln__DOT__fm3__DOT__i;
        IData/*22:0*/ fln__DOT__fm4__DOT__mantissa;
        IData/*31:0*/ fln__DOT__fm4__DOT__i;
        IData/*22:0*/ fln__DOT__fm5__DOT__mantissa;
        IData/*31:0*/ fln__DOT__fm5__DOT__i;
    };
    struct {
        IData/*22:0*/ fln__DOT__fm6__DOT__mantissa;
        IData/*31:0*/ fln__DOT__fm6__DOT__i;
        IData/*23:0*/ fln__DOT__fa1__DOT__num1Mant;
        IData/*23:0*/ fln__DOT__fa1__DOT__num2Mant;
        IData/*23:0*/ fln__DOT__fa1__DOT__finalMant;
        IData/*24:0*/ fln__DOT__fa1__DOT__sumMants;
        IData/*31:0*/ fln__DOT__fa1__DOT__i;
        IData/*23:0*/ fln__DOT__fa2__DOT__num1Mant;
        IData/*23:0*/ fln__DOT__fa2__DOT__num2Mant;
        IData/*23:0*/ fln__DOT__fa2__DOT__finalMant;
        IData/*24:0*/ fln__DOT__fa2__DOT__sumMants;
        IData/*31:0*/ fln__DOT__fa2__DOT__i;
        IData/*23:0*/ fln__DOT__fa3__DOT__num1Mant;
        IData/*23:0*/ fln__DOT__fa3__DOT__num2Mant;
        IData/*23:0*/ fln__DOT__fa3__DOT__finalMant;
        IData/*24:0*/ fln__DOT__fa3__DOT__sumMants;
        IData/*31:0*/ fln__DOT__fa3__DOT__i;
        IData/*23:0*/ fln__DOT__fa4__DOT__num1Mant;
        IData/*23:0*/ fln__DOT__fa4__DOT__num2Mant;
        IData/*23:0*/ fln__DOT__fa4__DOT__finalMant;
        IData/*24:0*/ fln__DOT__fa4__DOT__sumMants;
        IData/*31:0*/ fln__DOT__fa4__DOT__i;
        QData/*47:0*/ fln__DOT__fi0__DOT__f1__DOT__mantissaProd;
        QData/*47:0*/ fln__DOT__fm0__DOT__mantissaProd;
        QData/*47:0*/ fln__DOT__fm1__DOT__mantissaProd;
        QData/*47:0*/ fln__DOT__fm2__DOT__mantissaProd;
        QData/*47:0*/ fln__DOT__fm3__DOT__mantissaProd;
        QData/*47:0*/ fln__DOT__fm4__DOT__mantissaProd;
        QData/*47:0*/ fln__DOT__fm5__DOT__mantissaProd;
        QData/*47:0*/ fln__DOT__fm6__DOT__mantissaProd;
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    IData/*31:0*/ fln__DOT____Vcellinp__fa1____pinNumber2;
    IData/*31:0*/ fln__DOT____Vcellinp__fa2____pinNumber2;
    
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
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
