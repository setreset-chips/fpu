// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFMA__Syms.h"


//======================

void VFMA::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VFMA::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VFMA__Syms* __restrict vlSymsp = static_cast<VFMA__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VFMA::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VFMA::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VFMA__Syms* __restrict vlSymsp = static_cast<VFMA__Syms*>(userp);
    VFMA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VFMA::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VFMA__Syms* __restrict vlSymsp = static_cast<VFMA__Syms*>(userp);
    VFMA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+13,"a_fp", false,-1, 31,0);
        tracep->declBus(c+14,"b_fp", false,-1, 31,0);
        tracep->declBus(c+15,"c_fp", false,-1, 31,0);
        tracep->declBus(c+16,"out_fp", false,-1, 31,0);
        tracep->declBus(c+13,"FMA a_fp", false,-1, 31,0);
        tracep->declBus(c+14,"FMA b_fp", false,-1, 31,0);
        tracep->declBus(c+15,"FMA c_fp", false,-1, 31,0);
        tracep->declBus(c+16,"FMA out_fp", false,-1, 31,0);
        tracep->declBit(c+1,"FMA sign_out", false,-1);
        tracep->declBit(c+2,"FMA largerMag", false,-1);
        tracep->declBus(c+3,"FMA exp_out", false,-1, 7,0);
        tracep->declBus(c+4,"FMA final_exp", false,-1, 7,0);
        tracep->declBus(c+5,"FMA mantissa_a", false,-1, 23,0);
        tracep->declBus(c+6,"FMA mantissa_b", false,-1, 23,0);
        tracep->declBus(c+7,"FMA mantissa_c", false,-1, 23,0);
        tracep->declBus(c+8,"FMA mantissa_mul_norm", false,-1, 23,0);
        tracep->declBus(c+9,"FMA final_mantissa", false,-1, 23,0);
        tracep->declQuad(c+10,"FMA mantissa_mul_out", false,-1, 47,0);
        tracep->declBus(c+12,"FMA sum_mants", false,-1, 24,0);
    }
}

void VFMA::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VFMA::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VFMA__Syms* __restrict vlSymsp = static_cast<VFMA__Syms*>(userp);
    VFMA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VFMA::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VFMA__Syms* __restrict vlSymsp = static_cast<VFMA__Syms*>(userp);
    VFMA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->FMA__DOT__sign_out));
        tracep->fullBit(oldp+2,(vlTOPp->FMA__DOT__largerMag));
        tracep->fullCData(oldp+3,(vlTOPp->FMA__DOT__exp_out),8);
        tracep->fullCData(oldp+4,(vlTOPp->FMA__DOT__final_exp),8);
        tracep->fullIData(oldp+5,(vlTOPp->FMA__DOT__mantissa_a),24);
        tracep->fullIData(oldp+6,(vlTOPp->FMA__DOT__mantissa_b),24);
        tracep->fullIData(oldp+7,(vlTOPp->FMA__DOT__mantissa_c),24);
        tracep->fullIData(oldp+8,(vlTOPp->FMA__DOT__mantissa_mul_norm),24);
        tracep->fullIData(oldp+9,(vlTOPp->FMA__DOT__final_mantissa),24);
        tracep->fullQData(oldp+10,(vlTOPp->FMA__DOT__mantissa_mul_out),48);
        tracep->fullIData(oldp+12,(vlTOPp->FMA__DOT__sum_mants),25);
        tracep->fullIData(oldp+13,(vlTOPp->a_fp),32);
        tracep->fullIData(oldp+14,(vlTOPp->b_fp),32);
        tracep->fullIData(oldp+15,(vlTOPp->c_fp),32);
        tracep->fullIData(oldp+16,(vlTOPp->out_fp),32);
    }
}
