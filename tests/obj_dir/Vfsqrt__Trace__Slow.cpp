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
        tracep->declBus(c+7,"var1", false,-1, 31,0);
        tracep->declBus(c+8,"rm", false,-1, 2,0);
        tracep->declBus(c+9,"res", false,-1, 31,0);
        tracep->declBus(c+7,"fsqrt var1", false,-1, 31,0);
        tracep->declBus(c+8,"fsqrt rm", false,-1, 2,0);
        tracep->declBus(c+9,"fsqrt res", false,-1, 31,0);
        tracep->declBus(c+1,"fsqrt shifted_num", false,-1, 31,0);
        tracep->declBus(c+1,"fsqrt r0 num1", false,-1, 31,0);
        tracep->declBus(c+8,"fsqrt r0 rm", false,-1, 2,0);
        tracep->declBus(c+9,"fsqrt r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+2,"fsqrt r0 rounded", false,-1, 31,0);
        tracep->declBus(c+3,"fsqrt r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+4,"fsqrt r0 mask", false,-1, 22,0);
        tracep->declBus(c+5,"fsqrt r0 mask2", false,-1, 22,0);
        tracep->declBus(c+6,"fsqrt r0 i", false,-1, 31,0);
        tracep->declBus(c+10,"fsqrt r0 j", false,-1, 31,0);
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
        tracep->fullIData(oldp+1,(vlTOPp->fsqrt__DOT__shifted_num),32);
        tracep->fullIData(oldp+2,(vlTOPp->fsqrt__DOT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+3,(vlTOPp->fsqrt__DOT__r0__DOT__overflowCheck),24);
        tracep->fullIData(oldp+4,(vlTOPp->fsqrt__DOT__r0__DOT__mask),23);
        tracep->fullIData(oldp+5,(vlTOPp->fsqrt__DOT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+6,(vlTOPp->fsqrt__DOT__r0__DOT__i),32);
        tracep->fullIData(oldp+7,(vlTOPp->var1),32);
        tracep->fullCData(oldp+8,(vlTOPp->rm),3);
        tracep->fullIData(oldp+9,(vlTOPp->res),32);
        tracep->fullIData(oldp+10,(vlTOPp->fsqrt__DOT__r0__DOT__j),32);
    }
}
