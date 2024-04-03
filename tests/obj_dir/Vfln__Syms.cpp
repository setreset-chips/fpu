// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vfln__Syms.h"
#include "Vfln.h"
#include "Vfln_fmul.h"



// FUNCTIONS
Vfln__Syms::Vfln__Syms(Vfln* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_activity(false)
    , __Vm_baseCode(0)
    , __Vm_didInit(false)
    // Setup submodule names
    , TOP__fln__DOT__fm0(Verilated::catName(topp->name(), "fln.fm0"))
    , TOP__fln__DOT__fm1(Verilated::catName(topp->name(), "fln.fm1"))
    , TOP__fln__DOT__fm2(Verilated::catName(topp->name(), "fln.fm2"))
    , TOP__fln__DOT__fm3(Verilated::catName(topp->name(), "fln.fm3"))
    , TOP__fln__DOT__fm4(Verilated::catName(topp->name(), "fln.fm4"))
    , TOP__fln__DOT__fm5(Verilated::catName(topp->name(), "fln.fm5"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->__PVT__fln__DOT__fm0 = &TOP__fln__DOT__fm0;
    TOPp->__PVT__fln__DOT__fm1 = &TOP__fln__DOT__fm1;
    TOPp->__PVT__fln__DOT__fm2 = &TOP__fln__DOT__fm2;
    TOPp->__PVT__fln__DOT__fm3 = &TOP__fln__DOT__fm3;
    TOPp->__PVT__fln__DOT__fm4 = &TOP__fln__DOT__fm4;
    TOPp->__PVT__fln__DOT__fm5 = &TOP__fln__DOT__fm5;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__fln__DOT__fm0.__Vconfigure(this, true);
    TOP__fln__DOT__fm1.__Vconfigure(this, false);
    TOP__fln__DOT__fm2.__Vconfigure(this, false);
    TOP__fln__DOT__fm3.__Vconfigure(this, false);
    TOP__fln__DOT__fm4.__Vconfigure(this, false);
    TOP__fln__DOT__fm5.__Vconfigure(this, false);
}
