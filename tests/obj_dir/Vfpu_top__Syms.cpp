// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vfpu_top__Syms.h"
#include "Vfpu_top.h"
#include "Vfpu_top_fmul.h"



// FUNCTIONS
Vfpu_top__Syms::Vfpu_top__Syms(Vfpu_top* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_activity(false)
    , __Vm_baseCode(0)
    , __Vm_didInit(false)
    // Setup submodule names
    , TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1(Verilated::catName(topp->name(), "fpu_top.fdiv1.fi0.f1"))
    , TOP__fpu_top__DOT__fdiv1__DOT__fm0(Verilated::catName(topp->name(), "fpu_top.fdiv1.fm0"))
    , TOP__fpu_top__DOT__fmadd1__DOT__fmul1(Verilated::catName(topp->name(), "fpu_top.fmadd1.fmul1"))
    , TOP__fpu_top__DOT__fmsub1__DOT__fmul1(Verilated::catName(topp->name(), "fpu_top.fmsub1.fmul1"))
    , TOP__fpu_top__DOT__fmul1(Verilated::catName(topp->name(), "fpu_top.fmul1"))
    , TOP__fpu_top__DOT__fnmadd1__DOT__fmul1(Verilated::catName(topp->name(), "fpu_top.fnmadd1.fmul1"))
    , TOP__fpu_top__DOT__fnmsub1__DOT__fmul1(Verilated::catName(topp->name(), "fpu_top.fnmsub1.fmul1"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->__PVT__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1 = &TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1;
    TOPp->__PVT__fpu_top__DOT__fdiv1__DOT__fm0 = &TOP__fpu_top__DOT__fdiv1__DOT__fm0;
    TOPp->__PVT__fpu_top__DOT__fmadd1__DOT__fmul1 = &TOP__fpu_top__DOT__fmadd1__DOT__fmul1;
    TOPp->__PVT__fpu_top__DOT__fmsub1__DOT__fmul1 = &TOP__fpu_top__DOT__fmsub1__DOT__fmul1;
    TOPp->__PVT__fpu_top__DOT__fmul1 = &TOP__fpu_top__DOT__fmul1;
    TOPp->__PVT__fpu_top__DOT__fnmadd1__DOT__fmul1 = &TOP__fpu_top__DOT__fnmadd1__DOT__fmul1;
    TOPp->__PVT__fpu_top__DOT__fnmsub1__DOT__fmul1 = &TOP__fpu_top__DOT__fnmsub1__DOT__fmul1;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1.__Vconfigure(this, true);
    TOP__fpu_top__DOT__fdiv1__DOT__fm0.__Vconfigure(this, false);
    TOP__fpu_top__DOT__fmadd1__DOT__fmul1.__Vconfigure(this, false);
    TOP__fpu_top__DOT__fmsub1__DOT__fmul1.__Vconfigure(this, false);
    TOP__fpu_top__DOT__fmul1.__Vconfigure(this, false);
    TOP__fpu_top__DOT__fnmadd1__DOT__fmul1.__Vconfigure(this, false);
    TOP__fpu_top__DOT__fnmsub1__DOT__fmul1.__Vconfigure(this, false);
}
