// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfmul__Syms.h"


//======================

void Vfmul::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vfmul::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vfmul__Syms* __restrict vlSymsp = static_cast<Vfmul__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vfmul::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vfmul::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vfmul__Syms* __restrict vlSymsp = static_cast<Vfmul__Syms*>(userp);
    Vfmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vfmul::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vfmul__Syms* __restrict vlSymsp = static_cast<Vfmul__Syms*>(userp);
    Vfmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+5,"num1", false,-1, 31,0);
        tracep->declBus(c+6,"num2", false,-1, 31,0);
        tracep->declBus(c+7,"out_mul", false,-1, 31,0);
        tracep->declBus(c+5,"fmul num1", false,-1, 31,0);
        tracep->declBus(c+6,"fmul num2", false,-1, 31,0);
        tracep->declBus(c+7,"fmul out_mul", false,-1, 31,0);
        tracep->declBit(c+8,"fmul sign", false,-1);
        tracep->declBus(c+1,"fmul expF", false,-1, 7,0);
        tracep->declBus(c+2,"fmul mantissa", false,-1, 22,0);
        tracep->declBus(c+9,"fmul mantissa1", false,-1, 23,0);
        tracep->declBus(c+10,"fmul mantissa2", false,-1, 23,0);
        tracep->declQuad(c+3,"fmul mantissaProd", false,-1, 47,0);
        tracep->declBus(c+11,"fmul i", false,-1, 31,0);
    }
}

void Vfmul::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vfmul::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vfmul__Syms* __restrict vlSymsp = static_cast<Vfmul__Syms*>(userp);
    Vfmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vfmul::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vfmul__Syms* __restrict vlSymsp = static_cast<Vfmul__Syms*>(userp);
    Vfmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->fmul__DOT__expF),8);
        tracep->fullIData(oldp+2,(vlTOPp->fmul__DOT__mantissa),23);
        tracep->fullQData(oldp+3,(vlTOPp->fmul__DOT__mantissaProd),48);
        tracep->fullIData(oldp+5,(vlTOPp->num1),32);
        tracep->fullIData(oldp+6,(vlTOPp->num2),32);
        tracep->fullIData(oldp+7,(vlTOPp->out_mul),32);
        tracep->fullBit(oldp+8,((1U & ((vlTOPp->num1 
                                        ^ vlTOPp->num2) 
                                       >> 0x1fU))));
        tracep->fullIData(oldp+9,(((0U == vlTOPp->num1)
                                    ? 0U : (0x800000U 
                                            | (0x7fffffU 
                                               & vlTOPp->num1)))),24);
        tracep->fullIData(oldp+10,(((0U == vlTOPp->num2)
                                     ? 0U : (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->num2)))),24);
        tracep->fullIData(oldp+11,(0U),32);
    }
}
