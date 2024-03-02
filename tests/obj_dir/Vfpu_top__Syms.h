// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VFPU_TOP__SYMS_H_
#define _VFPU_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vfpu_top.h"
#include "Vfpu_top_fmul.h"

// SYMS CLASS
class Vfpu_top__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vfpu_top*                      TOPp;
    Vfpu_top_fmul                  TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1;
    Vfpu_top_fmul                  TOP__fpu_top__DOT__fdiv1__DOT__fm0;
    Vfpu_top_fmul                  TOP__fpu_top__DOT__fmadd1__DOT__fmul1;
    Vfpu_top_fmul                  TOP__fpu_top__DOT__fmsub1__DOT__fmul1;
    Vfpu_top_fmul                  TOP__fpu_top__DOT__fmul1;
    Vfpu_top_fmul                  TOP__fpu_top__DOT__fnmadd1__DOT__fmul1;
    Vfpu_top_fmul                  TOP__fpu_top__DOT__fnmsub1__DOT__fmul1;
    
    // CREATORS
    Vfpu_top__Syms(Vfpu_top* topp, const char* namep);
    ~Vfpu_top__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
