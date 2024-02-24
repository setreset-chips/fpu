// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfadd__Syms.h"


//======================

void Vfadd::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vfadd::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vfadd__Syms* __restrict vlSymsp = static_cast<Vfadd__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vfadd::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vfadd::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vfadd__Syms* __restrict vlSymsp = static_cast<Vfadd__Syms*>(userp);
    Vfadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vfadd::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vfadd__Syms* __restrict vlSymsp = static_cast<Vfadd__Syms*>(userp);
    Vfadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+10,"num1", false,-1, 31,0);
        tracep->declBus(c+11,"num2", false,-1, 31,0);
        tracep->declBus(c+12,"out_num", false,-1, 31,0);
        tracep->declBus(c+10,"fadd num1", false,-1, 31,0);
        tracep->declBus(c+11,"fadd num2", false,-1, 31,0);
        tracep->declBus(c+12,"fadd out_num", false,-1, 31,0);
        tracep->declBit(c+1,"fadd largerMag", false,-1);
        tracep->declBit(c+2,"fadd finalSign", false,-1);
        tracep->declBus(c+3,"fadd num1Exp", false,-1, 7,0);
        tracep->declBus(c+4,"fadd num2Exp", false,-1, 7,0);
        tracep->declBus(c+5,"fadd finalExp", false,-1, 7,0);
        tracep->declBus(c+6,"fadd num1Mant", false,-1, 23,0);
        tracep->declBus(c+7,"fadd num2Mant", false,-1, 23,0);
        tracep->declBus(c+8,"fadd finalMant", false,-1, 23,0);
        tracep->declBus(c+9,"fadd sumMants", false,-1, 24,0);
        tracep->declBus(c+13,"fadd i", false,-1, 31,0);
    }
}

void Vfadd::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vfadd::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vfadd__Syms* __restrict vlSymsp = static_cast<Vfadd__Syms*>(userp);
    Vfadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vfadd::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vfadd__Syms* __restrict vlSymsp = static_cast<Vfadd__Syms*>(userp);
    Vfadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->fadd__DOT__largerMag));
        tracep->fullBit(oldp+2,(vlTOPp->fadd__DOT__finalSign));
        tracep->fullCData(oldp+3,(vlTOPp->fadd__DOT__num1Exp),8);
        tracep->fullCData(oldp+4,(vlTOPp->fadd__DOT__num2Exp),8);
        tracep->fullCData(oldp+5,(vlTOPp->fadd__DOT__finalExp),8);
        tracep->fullIData(oldp+6,(vlTOPp->fadd__DOT__num1Mant),24);
        tracep->fullIData(oldp+7,(vlTOPp->fadd__DOT__num2Mant),24);
        tracep->fullIData(oldp+8,(vlTOPp->fadd__DOT__finalMant),24);
        tracep->fullIData(oldp+9,(vlTOPp->fadd__DOT__sumMants),25);
        tracep->fullIData(oldp+10,(vlTOPp->num1),32);
        tracep->fullIData(oldp+11,(vlTOPp->num2),32);
        tracep->fullIData(oldp+12,(vlTOPp->out_num),32);
        tracep->fullIData(oldp+13,(vlTOPp->fadd__DOT__i),32);
    }
}
