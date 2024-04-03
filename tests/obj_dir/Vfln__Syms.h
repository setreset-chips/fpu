// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VFLN__SYMS_H_
#define _VFLN__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vfln.h"
#include "Vfln_fmul.h"

// SYMS CLASS
class Vfln__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vfln*                          TOPp;
    Vfln_fmul                      TOP__fln__DOT__fm0;
    Vfln_fmul                      TOP__fln__DOT__fm1;
    Vfln_fmul                      TOP__fln__DOT__fm2;
    Vfln_fmul                      TOP__fln__DOT__fm3;
    Vfln_fmul                      TOP__fln__DOT__fm4;
    Vfln_fmul                      TOP__fln__DOT__fm5;
    
    // CREATORS
    Vfln__Syms(Vfln* topp, const char* namep);
    ~Vfln__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
