// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfsqrt__Syms.h"


//======================

void Vfsqrt::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vfsqrt::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vfsqrt__Syms* __restrict vlSymsp = static_cast<Vfsqrt__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vfsqrt::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vfsqrt::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vfsqrt__Syms* __restrict vlSymsp = static_cast<Vfsqrt__Syms*>(userp);
    Vfsqrt* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vfsqrt::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vfsqrt__Syms* __restrict vlSymsp = static_cast<Vfsqrt__Syms*>(userp);
    Vfsqrt* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+1,"var1", false,-1, 31,0);
        tracep->declBus(c+2,"res", false,-1, 31,0);
        tracep->declBus(c+1,"fsqrt var1", false,-1, 31,0);
        tracep->declBus(c+2,"fsqrt res", false,-1, 31,0);
        tracep->declBus(c+3,"fsqrt shifted_num", false,-1, 31,0);
    }
}

void Vfsqrt::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vfsqrt::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vfsqrt__Syms* __restrict vlSymsp = static_cast<Vfsqrt__Syms*>(userp);
    Vfsqrt* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vfsqrt::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vfsqrt__Syms* __restrict vlSymsp = static_cast<Vfsqrt__Syms*>(userp);
    Vfsqrt* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->var1),32);
        tracep->fullIData(oldp+2,(vlTOPp->res),32);
        tracep->fullIData(oldp+3,(vlTOPp->fsqrt__DOT__shifted_num),32);
    }
}
