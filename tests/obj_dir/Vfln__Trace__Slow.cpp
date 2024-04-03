// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfln__Syms.h"


//======================

void Vfln::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vfln::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vfln__Syms* __restrict vlSymsp = static_cast<Vfln__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vfln::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vfln::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vfln__Syms* __restrict vlSymsp = static_cast<Vfln__Syms*>(userp);
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vfln::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vfln__Syms* __restrict vlSymsp = static_cast<Vfln__Syms*>(userp);
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+113,"num1", false,-1, 31,0);
        tracep->declBus(c+114,"out1", false,-1, 31,0);
        tracep->declBus(c+113,"fln num1", false,-1, 31,0);
        tracep->declBus(c+114,"fln out1", false,-1, 31,0);
        tracep->declBit(c+115,"fln nanFlag", false,-1);
        tracep->declBus(c+116,"fln op1", false,-1, 31,0);
        tracep->declBus(c+1,"fln temp1", false,-1, 31,0);
        tracep->declBus(c+2,"fln temp2", false,-1, 31,0);
        tracep->declBus(c+3,"fln temp3", false,-1, 31,0);
        tracep->declBus(c+4,"fln temp4", false,-1, 31,0);
        tracep->declBus(c+5,"fln temp5", false,-1, 31,0);
        tracep->declBus(c+6,"fln temp6", false,-1, 31,0);
        tracep->declBus(c+7,"fln temp7", false,-1, 31,0);
        tracep->declBus(c+8,"fln temp8", false,-1, 31,0);
        tracep->declBus(c+9,"fln op1i", false,-1, 31,0);
        tracep->declBus(c+10,"fln temp9", false,-1, 31,0);
        tracep->declBus(c+11,"fln temp10", false,-1, 31,0);
        tracep->declBus(c+116,"fln fa0 num1", false,-1, 31,0);
        tracep->declBus(c+117,"fln fa0 num2", false,-1, 31,0);
        tracep->declBus(c+118,"fln fa0 rm", false,-1, 2,0);
        tracep->declBus(c+9,"fln fa0 out_num", false,-1, 31,0);
        tracep->declBit(c+12,"fln fa0 largerMag", false,-1);
        tracep->declBit(c+13,"fln fa0 finalSign", false,-1);
        tracep->declBus(c+14,"fln fa0 num1Exp", false,-1, 7,0);
        tracep->declBus(c+15,"fln fa0 num2Exp", false,-1, 7,0);
        tracep->declBus(c+16,"fln fa0 finalExp", false,-1, 7,0);
        tracep->declBus(c+17,"fln fa0 num1Mant", false,-1, 23,0);
        tracep->declBus(c+18,"fln fa0 num2Mant", false,-1, 23,0);
        tracep->declBus(c+19,"fln fa0 finalMant", false,-1, 23,0);
        tracep->declBus(c+20,"fln fa0 sumMants", false,-1, 24,0);
        tracep->declBus(c+119,"fln fa0 i", false,-1, 31,0);
        tracep->declBus(c+21,"fln fa0 unrounded", false,-1, 31,0);
        tracep->declBus(c+21,"fln fa0 r0 num1", false,-1, 31,0);
        tracep->declBus(c+118,"fln fa0 r0 rm", false,-1, 2,0);
        tracep->declBus(c+9,"fln fa0 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+9,"fln fa0 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+22,"fln fa0 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+120,"fln fa0 r0 mask", false,-1, 22,0);
        tracep->declBus(c+121,"fln fa0 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+122,"fln fa0 r0 i", false,-1, 31,0);
        tracep->declBus(c+123,"fln fa0 r0 j", false,-1, 31,0);
        tracep->declBus(c+5,"fln fma1 a_fp", false,-1, 31,0);
        tracep->declBus(c+124,"fln fma1 b_fp", false,-1, 31,0);
        tracep->declBus(c+4,"fln fma1 c_fp", false,-1, 31,0);
        tracep->declBus(c+6,"fln fma1 out_fp", false,-1, 31,0);
        tracep->declBit(c+23,"fln fma1 sign_out", false,-1);
        tracep->declBit(c+24,"fln fma1 largerMag", false,-1);
        tracep->declBus(c+25,"fln fma1 exp_out", false,-1, 7,0);
        tracep->declBus(c+26,"fln fma1 final_exp", false,-1, 7,0);
        tracep->declBus(c+27,"fln fma1 mantissa_a", false,-1, 23,0);
        tracep->declBus(c+125,"fln fma1 mantissa_b", false,-1, 23,0);
        tracep->declBus(c+28,"fln fma1 mantissa_c", false,-1, 23,0);
        tracep->declBus(c+29,"fln fma1 mantissa_mul_norm", false,-1, 23,0);
        tracep->declBus(c+30,"fln fma1 final_mantissa", false,-1, 23,0);
        tracep->declQuad(c+31,"fln fma1 mantissa_mul_out", false,-1, 47,0);
        tracep->declBus(c+33,"fln fma1 sum_mants", false,-1, 24,0);
        tracep->declBus(c+6,"fln fa1 num1", false,-1, 31,0);
        tracep->declBus(c+2,"fln fa1 num2", false,-1, 31,0);
        tracep->declBus(c+118,"fln fa1 rm", false,-1, 2,0);
        tracep->declBus(c+7,"fln fa1 out_num", false,-1, 31,0);
        tracep->declBit(c+34,"fln fa1 largerMag", false,-1);
        tracep->declBit(c+35,"fln fa1 finalSign", false,-1);
        tracep->declBus(c+36,"fln fa1 num1Exp", false,-1, 7,0);
        tracep->declBus(c+37,"fln fa1 num2Exp", false,-1, 7,0);
        tracep->declBus(c+38,"fln fa1 finalExp", false,-1, 7,0);
        tracep->declBus(c+39,"fln fa1 num1Mant", false,-1, 23,0);
        tracep->declBus(c+40,"fln fa1 num2Mant", false,-1, 23,0);
        tracep->declBus(c+41,"fln fa1 finalMant", false,-1, 23,0);
        tracep->declBus(c+42,"fln fa1 sumMants", false,-1, 24,0);
        tracep->declBus(c+126,"fln fa1 i", false,-1, 31,0);
        tracep->declBus(c+43,"fln fa1 unrounded", false,-1, 31,0);
        tracep->declBus(c+43,"fln fa1 r0 num1", false,-1, 31,0);
        tracep->declBus(c+118,"fln fa1 r0 rm", false,-1, 2,0);
        tracep->declBus(c+7,"fln fa1 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+7,"fln fa1 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+44,"fln fa1 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+127,"fln fa1 r0 mask", false,-1, 22,0);
        tracep->declBus(c+128,"fln fa1 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+129,"fln fa1 r0 i", false,-1, 31,0);
        tracep->declBus(c+130,"fln fa1 r0 j", false,-1, 31,0);
        tracep->declBus(c+7,"fln fa2 num1", false,-1, 31,0);
        tracep->declBus(c+9,"fln fa2 num2", false,-1, 31,0);
        tracep->declBus(c+118,"fln fa2 rm", false,-1, 2,0);
        tracep->declBus(c+8,"fln fa2 out_num", false,-1, 31,0);
        tracep->declBit(c+45,"fln fa2 largerMag", false,-1);
        tracep->declBit(c+46,"fln fa2 finalSign", false,-1);
        tracep->declBus(c+47,"fln fa2 num1Exp", false,-1, 7,0);
        tracep->declBus(c+48,"fln fa2 num2Exp", false,-1, 7,0);
        tracep->declBus(c+49,"fln fa2 finalExp", false,-1, 7,0);
        tracep->declBus(c+50,"fln fa2 num1Mant", false,-1, 23,0);
        tracep->declBus(c+51,"fln fa2 num2Mant", false,-1, 23,0);
        tracep->declBus(c+52,"fln fa2 finalMant", false,-1, 23,0);
        tracep->declBus(c+53,"fln fa2 sumMants", false,-1, 24,0);
        tracep->declBus(c+131,"fln fa2 i", false,-1, 31,0);
        tracep->declBus(c+54,"fln fa2 unrounded", false,-1, 31,0);
        tracep->declBus(c+54,"fln fa2 r0 num1", false,-1, 31,0);
        tracep->declBus(c+118,"fln fa2 r0 rm", false,-1, 2,0);
        tracep->declBus(c+8,"fln fa2 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+8,"fln fa2 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+55,"fln fa2 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+132,"fln fa2 r0 mask", false,-1, 22,0);
        tracep->declBus(c+133,"fln fa2 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+134,"fln fa2 r0 i", false,-1, 31,0);
        tracep->declBus(c+135,"fln fa2 r0 j", false,-1, 31,0);
        tracep->declBus(c+10,"fln fma2 a_fp", false,-1, 31,0);
        tracep->declBus(c+136,"fln fma2 b_fp", false,-1, 31,0);
        tracep->declBus(c+8,"fln fma2 c_fp", false,-1, 31,0);
        tracep->declBus(c+11,"fln fma2 out_fp", false,-1, 31,0);
        tracep->declBit(c+56,"fln fma2 sign_out", false,-1);
        tracep->declBit(c+57,"fln fma2 largerMag", false,-1);
        tracep->declBus(c+58,"fln fma2 exp_out", false,-1, 7,0);
        tracep->declBus(c+59,"fln fma2 final_exp", false,-1, 7,0);
        tracep->declBus(c+60,"fln fma2 mantissa_a", false,-1, 23,0);
        tracep->declBus(c+137,"fln fma2 mantissa_b", false,-1, 23,0);
        tracep->declBus(c+61,"fln fma2 mantissa_c", false,-1, 23,0);
        tracep->declBus(c+62,"fln fma2 mantissa_mul_norm", false,-1, 23,0);
        tracep->declBus(c+63,"fln fma2 final_mantissa", false,-1, 23,0);
        tracep->declQuad(c+64,"fln fma2 mantissa_mul_out", false,-1, 47,0);
        tracep->declBus(c+66,"fln fma2 sum_mants", false,-1, 24,0);
        tracep->declBus(c+9,"fln fm0 num1", false,-1, 31,0);
        tracep->declBus(c+9,"fln fm0 num2", false,-1, 31,0);
        tracep->declBus(c+118,"fln fm0 rm", false,-1, 2,0);
        tracep->declBus(c+1,"fln fm0 out_mul", false,-1, 31,0);
        tracep->declBit(c+67,"fln fm0 sign", false,-1);
        tracep->declBus(c+68,"fln fm0 expF", false,-1, 7,0);
        tracep->declBus(c+69,"fln fm0 mantissa", false,-1, 23,0);
        tracep->declBus(c+70,"fln fm0 mantissa1", false,-1, 23,0);
        tracep->declBus(c+70,"fln fm0 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+71,"fln fm0 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+138,"fln fm0 i", false,-1, 31,0);
        tracep->declBus(c+73,"fln fm0 r0 num1", false,-1, 31,0);
        tracep->declBus(c+118,"fln fm0 r0 rm", false,-1, 2,0);
        tracep->declBus(c+1,"fln fm0 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+1,"fln fm0 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+74,"fln fm0 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+139,"fln fm0 r0 mask", false,-1, 22,0);
        tracep->declBus(c+140,"fln fm0 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+141,"fln fm0 r0 i", false,-1, 31,0);
        tracep->declBus(c+142,"fln fm0 r0 j", false,-1, 31,0);
        tracep->declBus(c+1,"fln fm1 num1", false,-1, 31,0);
        tracep->declBus(c+143,"fln fm1 num2", false,-1, 31,0);
        tracep->declBus(c+118,"fln fm1 rm", false,-1, 2,0);
        tracep->declBus(c+2,"fln fm1 out_mul", false,-1, 31,0);
        tracep->declBit(c+75,"fln fm1 sign", false,-1);
        tracep->declBus(c+76,"fln fm1 expF", false,-1, 7,0);
        tracep->declBus(c+77,"fln fm1 mantissa", false,-1, 23,0);
        tracep->declBus(c+78,"fln fm1 mantissa1", false,-1, 23,0);
        tracep->declBus(c+125,"fln fm1 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+79,"fln fm1 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+138,"fln fm1 i", false,-1, 31,0);
        tracep->declBus(c+81,"fln fm1 r0 num1", false,-1, 31,0);
        tracep->declBus(c+118,"fln fm1 r0 rm", false,-1, 2,0);
        tracep->declBus(c+2,"fln fm1 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+2,"fln fm1 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+82,"fln fm1 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+144,"fln fm1 r0 mask", false,-1, 22,0);
        tracep->declBus(c+145,"fln fm1 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+146,"fln fm1 r0 i", false,-1, 31,0);
        tracep->declBus(c+147,"fln fm1 r0 j", false,-1, 31,0);
        tracep->declBus(c+1,"fln fm2 num1", false,-1, 31,0);
        tracep->declBus(c+9,"fln fm2 num2", false,-1, 31,0);
        tracep->declBus(c+118,"fln fm2 rm", false,-1, 2,0);
        tracep->declBus(c+3,"fln fm2 out_mul", false,-1, 31,0);
        tracep->declBit(c+83,"fln fm2 sign", false,-1);
        tracep->declBus(c+84,"fln fm2 expF", false,-1, 7,0);
        tracep->declBus(c+85,"fln fm2 mantissa", false,-1, 23,0);
        tracep->declBus(c+78,"fln fm2 mantissa1", false,-1, 23,0);
        tracep->declBus(c+70,"fln fm2 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+86,"fln fm2 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+138,"fln fm2 i", false,-1, 31,0);
        tracep->declBus(c+88,"fln fm2 r0 num1", false,-1, 31,0);
        tracep->declBus(c+118,"fln fm2 r0 rm", false,-1, 2,0);
        tracep->declBus(c+3,"fln fm2 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+3,"fln fm2 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+89,"fln fm2 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+148,"fln fm2 r0 mask", false,-1, 22,0);
        tracep->declBus(c+149,"fln fm2 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+150,"fln fm2 r0 i", false,-1, 31,0);
        tracep->declBus(c+151,"fln fm2 r0 j", false,-1, 31,0);
        tracep->declBus(c+3,"fln fm3 num1", false,-1, 31,0);
        tracep->declBus(c+152,"fln fm3 num2", false,-1, 31,0);
        tracep->declBus(c+118,"fln fm3 rm", false,-1, 2,0);
        tracep->declBus(c+4,"fln fm3 out_mul", false,-1, 31,0);
        tracep->declBit(c+90,"fln fm3 sign", false,-1);
        tracep->declBus(c+91,"fln fm3 expF", false,-1, 7,0);
        tracep->declBus(c+92,"fln fm3 mantissa", false,-1, 23,0);
        tracep->declBus(c+93,"fln fm3 mantissa1", false,-1, 23,0);
        tracep->declBus(c+153,"fln fm3 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+94,"fln fm3 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+138,"fln fm3 i", false,-1, 31,0);
        tracep->declBus(c+96,"fln fm3 r0 num1", false,-1, 31,0);
        tracep->declBus(c+118,"fln fm3 r0 rm", false,-1, 2,0);
        tracep->declBus(c+4,"fln fm3 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+4,"fln fm3 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+97,"fln fm3 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+154,"fln fm3 r0 mask", false,-1, 22,0);
        tracep->declBus(c+155,"fln fm3 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+156,"fln fm3 r0 i", false,-1, 31,0);
        tracep->declBus(c+157,"fln fm3 r0 j", false,-1, 31,0);
        tracep->declBus(c+3,"fln fm4 num1", false,-1, 31,0);
        tracep->declBus(c+9,"fln fm4 num2", false,-1, 31,0);
        tracep->declBus(c+118,"fln fm4 rm", false,-1, 2,0);
        tracep->declBus(c+5,"fln fm4 out_mul", false,-1, 31,0);
        tracep->declBit(c+98,"fln fm4 sign", false,-1);
        tracep->declBus(c+99,"fln fm4 expF", false,-1, 7,0);
        tracep->declBus(c+100,"fln fm4 mantissa", false,-1, 23,0);
        tracep->declBus(c+93,"fln fm4 mantissa1", false,-1, 23,0);
        tracep->declBus(c+70,"fln fm4 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+101,"fln fm4 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+138,"fln fm4 i", false,-1, 31,0);
        tracep->declBus(c+103,"fln fm4 r0 num1", false,-1, 31,0);
        tracep->declBus(c+118,"fln fm4 r0 rm", false,-1, 2,0);
        tracep->declBus(c+5,"fln fm4 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+5,"fln fm4 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+104,"fln fm4 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+158,"fln fm4 r0 mask", false,-1, 22,0);
        tracep->declBus(c+159,"fln fm4 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+160,"fln fm4 r0 i", false,-1, 31,0);
        tracep->declBus(c+161,"fln fm4 r0 j", false,-1, 31,0);
        tracep->declBus(c+4,"fln fm5 num1", false,-1, 31,0);
        tracep->declBus(c+9,"fln fm5 num2", false,-1, 31,0);
        tracep->declBus(c+118,"fln fm5 rm", false,-1, 2,0);
        tracep->declBus(c+10,"fln fm5 out_mul", false,-1, 31,0);
        tracep->declBit(c+105,"fln fm5 sign", false,-1);
        tracep->declBus(c+106,"fln fm5 expF", false,-1, 7,0);
        tracep->declBus(c+107,"fln fm5 mantissa", false,-1, 23,0);
        tracep->declBus(c+108,"fln fm5 mantissa1", false,-1, 23,0);
        tracep->declBus(c+70,"fln fm5 mantissa2", false,-1, 23,0);
        tracep->declQuad(c+109,"fln fm5 mantissaProd", false,-1, 47,0);
        tracep->declBus(c+138,"fln fm5 i", false,-1, 31,0);
        tracep->declBus(c+111,"fln fm5 r0 num1", false,-1, 31,0);
        tracep->declBus(c+118,"fln fm5 r0 rm", false,-1, 2,0);
        tracep->declBus(c+10,"fln fm5 r0 rounded_num", false,-1, 31,0);
        tracep->declBus(c+10,"fln fm5 r0 rounded", false,-1, 31,0);
        tracep->declBus(c+112,"fln fm5 r0 overflowCheck", false,-1, 23,0);
        tracep->declBus(c+162,"fln fm5 r0 mask", false,-1, 22,0);
        tracep->declBus(c+163,"fln fm5 r0 mask2", false,-1, 22,0);
        tracep->declBus(c+164,"fln fm5 r0 i", false,-1, 31,0);
        tracep->declBus(c+165,"fln fm5 r0 j", false,-1, 31,0);
    }
}

void Vfln::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vfln::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vfln__Syms* __restrict vlSymsp = static_cast<Vfln__Syms*>(userp);
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vfln::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vfln__Syms* __restrict vlSymsp = static_cast<Vfln__Syms*>(userp);
    Vfln* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlSymsp->TOP__fln__DOT__fm0.__PVT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+2,(vlSymsp->TOP__fln__DOT__fm1.__PVT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+3,(vlSymsp->TOP__fln__DOT__fm2.__PVT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+4,(vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+5,(vlSymsp->TOP__fln__DOT__fm4.__PVT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+6,(vlTOPp->fln__DOT__temp6),32);
        tracep->fullIData(oldp+7,(vlTOPp->fln__DOT__fa1__DOT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+8,(vlTOPp->fln__DOT__fa2__DOT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+9,(vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+10,(vlSymsp->TOP__fln__DOT__fm5.__PVT__r0__DOT__rounded),32);
        tracep->fullIData(oldp+11,(((0x80000000U & 
                                     ((~ (IData)(vlTOPp->fln__DOT__fma2__DOT__sign_out)) 
                                      << 0x1fU)) | 
                                    (((IData)(vlTOPp->fln__DOT__fma2__DOT__final_exp) 
                                      << 0x17U) | (0x7fffffU 
                                                   & (vlTOPp->fln__DOT__fma2__DOT__final_mantissa 
                                                      >> 1U))))),32);
        tracep->fullBit(oldp+12,(vlTOPp->fln__DOT__fa0__DOT__largerMag));
        tracep->fullBit(oldp+13,(vlTOPp->fln__DOT__fa0__DOT__finalSign));
        tracep->fullCData(oldp+14,(vlTOPp->fln__DOT__fa0__DOT__num1Exp),8);
        tracep->fullCData(oldp+15,(vlTOPp->fln__DOT__fa0__DOT__num2Exp),8);
        tracep->fullCData(oldp+16,(vlTOPp->fln__DOT__fa0__DOT__finalExp),8);
        tracep->fullIData(oldp+17,(vlTOPp->fln__DOT__fa0__DOT__num1Mant),24);
        tracep->fullIData(oldp+18,(vlTOPp->fln__DOT__fa0__DOT__num2Mant),24);
        tracep->fullIData(oldp+19,(vlTOPp->fln__DOT__fa0__DOT__finalMant),24);
        tracep->fullIData(oldp+20,(vlTOPp->fln__DOT__fa0__DOT__sumMants),25);
        tracep->fullIData(oldp+21,(vlTOPp->fln__DOT__fa0__DOT__unrounded),32);
        tracep->fullIData(oldp+22,(vlTOPp->fln__DOT__fa0__DOT__r0__DOT__overflowCheck),24);
        tracep->fullBit(oldp+23,(vlTOPp->fln__DOT__fma1__DOT__sign_out));
        tracep->fullBit(oldp+24,(vlTOPp->fln__DOT__fma1__DOT__largerMag));
        tracep->fullCData(oldp+25,(vlTOPp->fln__DOT__fma1__DOT__exp_out),8);
        tracep->fullCData(oldp+26,(vlTOPp->fln__DOT__fma1__DOT__final_exp),8);
        tracep->fullIData(oldp+27,(vlTOPp->fln__DOT__fma1__DOT__mantissa_a),24);
        tracep->fullIData(oldp+28,(vlTOPp->fln__DOT__fma1__DOT__mantissa_c),24);
        tracep->fullIData(oldp+29,(vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_norm),24);
        tracep->fullIData(oldp+30,(vlTOPp->fln__DOT__fma1__DOT__final_mantissa),24);
        tracep->fullQData(oldp+31,(vlTOPp->fln__DOT__fma1__DOT__mantissa_mul_out),48);
        tracep->fullIData(oldp+33,(vlTOPp->fln__DOT__fma1__DOT__sum_mants),25);
        tracep->fullBit(oldp+34,(vlTOPp->fln__DOT__fa1__DOT__largerMag));
        tracep->fullBit(oldp+35,(vlTOPp->fln__DOT__fa1__DOT__finalSign));
        tracep->fullCData(oldp+36,(vlTOPp->fln__DOT__fa1__DOT__num1Exp),8);
        tracep->fullCData(oldp+37,(vlTOPp->fln__DOT__fa1__DOT__num2Exp),8);
        tracep->fullCData(oldp+38,(vlTOPp->fln__DOT__fa1__DOT__finalExp),8);
        tracep->fullIData(oldp+39,(vlTOPp->fln__DOT__fa1__DOT__num1Mant),24);
        tracep->fullIData(oldp+40,(vlTOPp->fln__DOT__fa1__DOT__num2Mant),24);
        tracep->fullIData(oldp+41,(vlTOPp->fln__DOT__fa1__DOT__finalMant),24);
        tracep->fullIData(oldp+42,(vlTOPp->fln__DOT__fa1__DOT__sumMants),25);
        tracep->fullIData(oldp+43,(vlTOPp->fln__DOT__fa1__DOT__unrounded),32);
        tracep->fullIData(oldp+44,(vlTOPp->fln__DOT__fa1__DOT__r0__DOT__overflowCheck),24);
        tracep->fullBit(oldp+45,(vlTOPp->fln__DOT__fa2__DOT__largerMag));
        tracep->fullBit(oldp+46,(vlTOPp->fln__DOT__fa2__DOT__finalSign));
        tracep->fullCData(oldp+47,(vlTOPp->fln__DOT__fa2__DOT__num1Exp),8);
        tracep->fullCData(oldp+48,(vlTOPp->fln__DOT__fa2__DOT__num2Exp),8);
        tracep->fullCData(oldp+49,(vlTOPp->fln__DOT__fa2__DOT__finalExp),8);
        tracep->fullIData(oldp+50,(vlTOPp->fln__DOT__fa2__DOT__num1Mant),24);
        tracep->fullIData(oldp+51,(vlTOPp->fln__DOT__fa2__DOT__num2Mant),24);
        tracep->fullIData(oldp+52,(vlTOPp->fln__DOT__fa2__DOT__finalMant),24);
        tracep->fullIData(oldp+53,(vlTOPp->fln__DOT__fa2__DOT__sumMants),25);
        tracep->fullIData(oldp+54,(vlTOPp->fln__DOT__fa2__DOT__unrounded),32);
        tracep->fullIData(oldp+55,(vlTOPp->fln__DOT__fa2__DOT__r0__DOT__overflowCheck),24);
        tracep->fullBit(oldp+56,(vlTOPp->fln__DOT__fma2__DOT__sign_out));
        tracep->fullBit(oldp+57,(vlTOPp->fln__DOT__fma2__DOT__largerMag));
        tracep->fullCData(oldp+58,(vlTOPp->fln__DOT__fma2__DOT__exp_out),8);
        tracep->fullCData(oldp+59,(vlTOPp->fln__DOT__fma2__DOT__final_exp),8);
        tracep->fullIData(oldp+60,(vlTOPp->fln__DOT__fma2__DOT__mantissa_a),24);
        tracep->fullIData(oldp+61,(vlTOPp->fln__DOT__fma2__DOT__mantissa_c),24);
        tracep->fullIData(oldp+62,(vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_norm),24);
        tracep->fullIData(oldp+63,(vlTOPp->fln__DOT__fma2__DOT__final_mantissa),24);
        tracep->fullQData(oldp+64,(vlTOPp->fln__DOT__fma2__DOT__mantissa_mul_out),48);
        tracep->fullIData(oldp+66,(vlTOPp->fln__DOT__fma2__DOT__sum_mants),25);
        tracep->fullBit(oldp+67,(0U));
        tracep->fullCData(oldp+68,(vlSymsp->TOP__fln__DOT__fm0.__PVT__expF),8);
        tracep->fullIData(oldp+69,(vlSymsp->TOP__fln__DOT__fm0.__PVT__mantissa),24);
        tracep->fullIData(oldp+70,(((0U == vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded)
                                     ? 0U : (0x800000U 
                                             | (0x7fffffU 
                                                & vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded)))),24);
        tracep->fullQData(oldp+71,(vlSymsp->TOP__fln__DOT__fm0.__PVT__mantissaProd),48);
        tracep->fullIData(oldp+73,(vlSymsp->TOP__fln__DOT__fm0.__Vcellinp__r0____pinNumber1),32);
        tracep->fullIData(oldp+74,(vlSymsp->TOP__fln__DOT__fm0.__PVT__r0__DOT__overflowCheck),24);
        tracep->fullBit(oldp+75,((1U & (~ (vlSymsp->TOP__fln__DOT__fm0.__PVT__r0__DOT__rounded 
                                           >> 0x1fU)))));
        tracep->fullCData(oldp+76,(vlSymsp->TOP__fln__DOT__fm1.__PVT__expF),8);
        tracep->fullIData(oldp+77,(vlSymsp->TOP__fln__DOT__fm1.__PVT__mantissa),24);
        tracep->fullIData(oldp+78,(((0U == vlSymsp->TOP__fln__DOT__fm0.__PVT__r0__DOT__rounded)
                                     ? 0U : (0x800000U 
                                             | (0x7fffffU 
                                                & vlSymsp->TOP__fln__DOT__fm0.__PVT__r0__DOT__rounded)))),24);
        tracep->fullQData(oldp+79,(vlSymsp->TOP__fln__DOT__fm1.__PVT__mantissaProd),48);
        tracep->fullIData(oldp+81,(vlSymsp->TOP__fln__DOT__fm1.__Vcellinp__r0____pinNumber1),32);
        tracep->fullIData(oldp+82,(vlSymsp->TOP__fln__DOT__fm1.__PVT__r0__DOT__overflowCheck),24);
        tracep->fullBit(oldp+83,((1U & ((vlSymsp->TOP__fln__DOT__fm0.__PVT__r0__DOT__rounded 
                                         ^ vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded) 
                                        >> 0x1fU))));
        tracep->fullCData(oldp+84,(vlSymsp->TOP__fln__DOT__fm2.__PVT__expF),8);
        tracep->fullIData(oldp+85,(vlSymsp->TOP__fln__DOT__fm2.__PVT__mantissa),24);
        tracep->fullQData(oldp+86,(vlSymsp->TOP__fln__DOT__fm2.__PVT__mantissaProd),48);
        tracep->fullIData(oldp+88,(vlSymsp->TOP__fln__DOT__fm2.__Vcellinp__r0____pinNumber1),32);
        tracep->fullIData(oldp+89,(vlSymsp->TOP__fln__DOT__fm2.__PVT__r0__DOT__overflowCheck),24);
        tracep->fullBit(oldp+90,((1U & (vlSymsp->TOP__fln__DOT__fm2.__PVT__r0__DOT__rounded 
                                        >> 0x1fU))));
        tracep->fullCData(oldp+91,(vlSymsp->TOP__fln__DOT__fm3.__PVT__expF),8);
        tracep->fullIData(oldp+92,(vlSymsp->TOP__fln__DOT__fm3.__PVT__mantissa),24);
        tracep->fullIData(oldp+93,(((0U == vlSymsp->TOP__fln__DOT__fm2.__PVT__r0__DOT__rounded)
                                     ? 0U : (0x800000U 
                                             | (0x7fffffU 
                                                & vlSymsp->TOP__fln__DOT__fm2.__PVT__r0__DOT__rounded)))),24);
        tracep->fullQData(oldp+94,(vlSymsp->TOP__fln__DOT__fm3.__PVT__mantissaProd),48);
        tracep->fullIData(oldp+96,(vlSymsp->TOP__fln__DOT__fm3.__Vcellinp__r0____pinNumber1),32);
        tracep->fullIData(oldp+97,(vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__overflowCheck),24);
        tracep->fullBit(oldp+98,((1U & ((vlSymsp->TOP__fln__DOT__fm2.__PVT__r0__DOT__rounded 
                                         ^ vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded) 
                                        >> 0x1fU))));
        tracep->fullCData(oldp+99,(vlSymsp->TOP__fln__DOT__fm4.__PVT__expF),8);
        tracep->fullIData(oldp+100,(vlSymsp->TOP__fln__DOT__fm4.__PVT__mantissa),24);
        tracep->fullQData(oldp+101,(vlSymsp->TOP__fln__DOT__fm4.__PVT__mantissaProd),48);
        tracep->fullIData(oldp+103,(vlSymsp->TOP__fln__DOT__fm4.__Vcellinp__r0____pinNumber1),32);
        tracep->fullIData(oldp+104,(vlSymsp->TOP__fln__DOT__fm4.__PVT__r0__DOT__overflowCheck),24);
        tracep->fullBit(oldp+105,((1U & ((vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__rounded 
                                          ^ vlTOPp->fln__DOT__fa0__DOT__r0__DOT__rounded) 
                                         >> 0x1fU))));
        tracep->fullCData(oldp+106,(vlSymsp->TOP__fln__DOT__fm5.__PVT__expF),8);
        tracep->fullIData(oldp+107,(vlSymsp->TOP__fln__DOT__fm5.__PVT__mantissa),24);
        tracep->fullIData(oldp+108,(((0U == vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__rounded)
                                      ? 0U : (0x800000U 
                                              | (0x7fffffU 
                                                 & vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__rounded)))),24);
        tracep->fullQData(oldp+109,(vlSymsp->TOP__fln__DOT__fm5.__PVT__mantissaProd),48);
        tracep->fullIData(oldp+111,(vlSymsp->TOP__fln__DOT__fm5.__Vcellinp__r0____pinNumber1),32);
        tracep->fullIData(oldp+112,(vlSymsp->TOP__fln__DOT__fm5.__PVT__r0__DOT__overflowCheck),24);
        tracep->fullIData(oldp+113,(vlTOPp->num1),32);
        tracep->fullIData(oldp+114,(vlTOPp->out1),32);
        tracep->fullBit(oldp+115,((1U & (vlTOPp->num1 
                                         >> 0x1fU))));
        tracep->fullIData(oldp+116,((0x7fffffffU & vlTOPp->num1)),32);
        tracep->fullIData(oldp+117,(0xbf800000U),32);
        tracep->fullCData(oldp+118,(0U),3);
        tracep->fullIData(oldp+119,(vlTOPp->fln__DOT__fa0__DOT__i),32);
        tracep->fullIData(oldp+120,(vlTOPp->fln__DOT__fa0__DOT__r0__DOT__mask),23);
        tracep->fullIData(oldp+121,(vlTOPp->fln__DOT__fa0__DOT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+122,(vlTOPp->fln__DOT__fa0__DOT__r0__DOT__i),32);
        tracep->fullIData(oldp+123,(vlTOPp->fln__DOT__fa0__DOT__r0__DOT__j),32);
        tracep->fullIData(oldp+124,(0xbe800000U),32);
        tracep->fullIData(oldp+125,(0x800000U),24);
        tracep->fullIData(oldp+126,(vlTOPp->fln__DOT__fa1__DOT__i),32);
        tracep->fullIData(oldp+127,(vlTOPp->fln__DOT__fa1__DOT__r0__DOT__mask),23);
        tracep->fullIData(oldp+128,(vlTOPp->fln__DOT__fa1__DOT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+129,(vlTOPp->fln__DOT__fa1__DOT__r0__DOT__i),32);
        tracep->fullIData(oldp+130,(vlTOPp->fln__DOT__fa1__DOT__r0__DOT__j),32);
        tracep->fullIData(oldp+131,(vlTOPp->fln__DOT__fa2__DOT__i),32);
        tracep->fullIData(oldp+132,(vlTOPp->fln__DOT__fa2__DOT__r0__DOT__mask),23);
        tracep->fullIData(oldp+133,(vlTOPp->fln__DOT__fa2__DOT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+134,(vlTOPp->fln__DOT__fa2__DOT__r0__DOT__i),32);
        tracep->fullIData(oldp+135,(vlTOPp->fln__DOT__fa2__DOT__r0__DOT__j),32);
        tracep->fullIData(oldp+136,(0x3e4ccccdU),32);
        tracep->fullIData(oldp+137,(0xcccccdU),24);
        tracep->fullIData(oldp+138,(0U),32);
        tracep->fullIData(oldp+139,(vlSymsp->TOP__fln__DOT__fm0.__PVT__r0__DOT__mask),23);
        tracep->fullIData(oldp+140,(vlSymsp->TOP__fln__DOT__fm0.__PVT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+141,(vlSymsp->TOP__fln__DOT__fm0.__PVT__r0__DOT__i),32);
        tracep->fullIData(oldp+142,(vlSymsp->TOP__fln__DOT__fm0.__PVT__r0__DOT__j),32);
        tracep->fullIData(oldp+143,(0xbf000000U),32);
        tracep->fullIData(oldp+144,(vlSymsp->TOP__fln__DOT__fm1.__PVT__r0__DOT__mask),23);
        tracep->fullIData(oldp+145,(vlSymsp->TOP__fln__DOT__fm1.__PVT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+146,(vlSymsp->TOP__fln__DOT__fm1.__PVT__r0__DOT__i),32);
        tracep->fullIData(oldp+147,(vlSymsp->TOP__fln__DOT__fm1.__PVT__r0__DOT__j),32);
        tracep->fullIData(oldp+148,(vlSymsp->TOP__fln__DOT__fm2.__PVT__r0__DOT__mask),23);
        tracep->fullIData(oldp+149,(vlSymsp->TOP__fln__DOT__fm2.__PVT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+150,(vlSymsp->TOP__fln__DOT__fm2.__PVT__r0__DOT__i),32);
        tracep->fullIData(oldp+151,(vlSymsp->TOP__fln__DOT__fm2.__PVT__r0__DOT__j),32);
        tracep->fullIData(oldp+152,(0x3eaaaaabU),32);
        tracep->fullIData(oldp+153,(0xaaaaabU),24);
        tracep->fullIData(oldp+154,(vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__mask),23);
        tracep->fullIData(oldp+155,(vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+156,(vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__i),32);
        tracep->fullIData(oldp+157,(vlSymsp->TOP__fln__DOT__fm3.__PVT__r0__DOT__j),32);
        tracep->fullIData(oldp+158,(vlSymsp->TOP__fln__DOT__fm4.__PVT__r0__DOT__mask),23);
        tracep->fullIData(oldp+159,(vlSymsp->TOP__fln__DOT__fm4.__PVT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+160,(vlSymsp->TOP__fln__DOT__fm4.__PVT__r0__DOT__i),32);
        tracep->fullIData(oldp+161,(vlSymsp->TOP__fln__DOT__fm4.__PVT__r0__DOT__j),32);
        tracep->fullIData(oldp+162,(vlSymsp->TOP__fln__DOT__fm5.__PVT__r0__DOT__mask),23);
        tracep->fullIData(oldp+163,(vlSymsp->TOP__fln__DOT__fm5.__PVT__r0__DOT__mask2),23);
        tracep->fullIData(oldp+164,(vlSymsp->TOP__fln__DOT__fm5.__PVT__r0__DOT__i),32);
        tracep->fullIData(oldp+165,(vlSymsp->TOP__fln__DOT__fm5.__PVT__r0__DOT__j),32);
    }
}
