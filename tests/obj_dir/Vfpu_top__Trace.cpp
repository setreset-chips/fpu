// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfpu_top__Syms.h"


void Vfpu_top::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vfpu_top__Syms* __restrict vlSymsp = static_cast<Vfpu_top__Syms*>(userp);
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vfpu_top::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vfpu_top__Syms* __restrict vlSymsp = static_cast<Vfpu_top__Syms*>(userp);
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+0,(vlTOPp->fpu_top__DOT__operand_1),32);
            tracep->chgIData(oldp+1,(vlTOPp->fpu_top__DOT__operand_2),32);
            tracep->chgIData(oldp+2,(vlTOPp->fpu_top__DOT__operand_3),32);
            tracep->chgIData(oldp+3,(vlTOPp->fpu_top__DOT__regFile[0]),32);
            tracep->chgIData(oldp+4,(vlTOPp->fpu_top__DOT__regFile[1]),32);
            tracep->chgIData(oldp+5,(vlTOPp->fpu_top__DOT__regFile[2]),32);
            tracep->chgIData(oldp+6,(vlTOPp->fpu_top__DOT__regFile[3]),32);
            tracep->chgIData(oldp+7,(vlTOPp->fpu_top__DOT__regFile[4]),32);
            tracep->chgIData(oldp+8,(vlTOPp->fpu_top__DOT__regFile[5]),32);
            tracep->chgIData(oldp+9,(vlTOPp->fpu_top__DOT__regFile[6]),32);
            tracep->chgIData(oldp+10,(vlTOPp->fpu_top__DOT__regFile[7]),32);
            tracep->chgIData(oldp+11,(vlTOPp->fpu_top__DOT__regFile[8]),32);
            tracep->chgIData(oldp+12,(vlTOPp->fpu_top__DOT__regFile[9]),32);
            tracep->chgIData(oldp+13,(vlTOPp->fpu_top__DOT__regFile[10]),32);
            tracep->chgIData(oldp+14,(vlTOPp->fpu_top__DOT__regFile[11]),32);
            tracep->chgIData(oldp+15,(vlTOPp->fpu_top__DOT__regFile[12]),32);
            tracep->chgIData(oldp+16,(vlTOPp->fpu_top__DOT__regFile[13]),32);
            tracep->chgIData(oldp+17,(vlTOPp->fpu_top__DOT__regFile[14]),32);
            tracep->chgIData(oldp+18,(vlTOPp->fpu_top__DOT__regFile[15]),32);
            tracep->chgIData(oldp+19,(vlTOPp->fpu_top__DOT__regFile[16]),32);
            tracep->chgIData(oldp+20,(vlTOPp->fpu_top__DOT__regFile[17]),32);
            tracep->chgIData(oldp+21,(vlTOPp->fpu_top__DOT__regFile[18]),32);
            tracep->chgIData(oldp+22,(vlTOPp->fpu_top__DOT__regFile[19]),32);
            tracep->chgIData(oldp+23,(vlTOPp->fpu_top__DOT__regFile[20]),32);
            tracep->chgIData(oldp+24,(vlTOPp->fpu_top__DOT__regFile[21]),32);
            tracep->chgIData(oldp+25,(vlTOPp->fpu_top__DOT__regFile[22]),32);
            tracep->chgIData(oldp+26,(vlTOPp->fpu_top__DOT__regFile[23]),32);
            tracep->chgIData(oldp+27,(vlTOPp->fpu_top__DOT__regFile[24]),32);
            tracep->chgIData(oldp+28,(vlTOPp->fpu_top__DOT__regFile[25]),32);
            tracep->chgIData(oldp+29,(vlTOPp->fpu_top__DOT__regFile[26]),32);
            tracep->chgIData(oldp+30,(vlTOPp->fpu_top__DOT__regFile[27]),32);
            tracep->chgIData(oldp+31,(vlTOPp->fpu_top__DOT__regFile[28]),32);
            tracep->chgIData(oldp+32,(vlTOPp->fpu_top__DOT__regFile[29]),32);
            tracep->chgIData(oldp+33,(vlTOPp->fpu_top__DOT__regFile[30]),32);
            tracep->chgIData(oldp+34,(vlTOPp->fpu_top__DOT__regFile[31]),32);
            tracep->chgIData(oldp+35,(vlTOPp->fpu_top__DOT__ins_p1),32);
            tracep->chgCData(oldp+36,((0x1fU & (vlTOPp->fpu_top__DOT__ins_p1 
                                                >> 2U))),5);
            tracep->chgCData(oldp+37,((0x1fU & (vlTOPp->fpu_top__DOT__ins_p1 
                                                >> 0x1bU))),5);
            tracep->chgCData(oldp+38,((3U & (vlTOPp->fpu_top__DOT__ins_p1 
                                             >> 0xcU))),2);
            tracep->chgBit(oldp+39,((1U & (vlTOPp->fpu_top__DOT__ins_p1 
                                           >> 0x14U))));
            tracep->chgCData(oldp+40,(vlTOPp->fpu_top__DOT__curr_op),5);
            tracep->chgIData(oldp+41,(vlTOPp->fpu_top__DOT__oper1),32);
            tracep->chgIData(oldp+42,(vlTOPp->fpu_top__DOT__oper2),32);
            tracep->chgIData(oldp+43,(vlTOPp->fpu_top__DOT__oper3),32);
            tracep->chgCData(oldp+44,(vlTOPp->fpu_top__DOT__exec_op),5);
            tracep->chgIData(oldp+45,(vlTOPp->fpu_top__DOT__ins_p2),32);
            tracep->chgIData(oldp+46,(vlTOPp->fpu_top__DOT__operand_one),32);
            tracep->chgIData(oldp+47,(vlTOPp->fpu_top__DOT__operand_two),32);
            tracep->chgIData(oldp+48,(vlTOPp->fpu_top__DOT__operand_three),32);
            tracep->chgIData(oldp+49,(vlTOPp->fpu_top__DOT__result),32);
            tracep->chgIData(oldp+50,(((0x80000000U 
                                        & ((~ (IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalSign)) 
                                           << 0x1fU)) 
                                       | (((IData)(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp) 
                                           << 0x17U) 
                                          | (0x7fffffU 
                                             & (vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant 
                                                >> 1U))))),32);
            tracep->chgIData(oldp+51,(vlTOPp->fpu_top__DOT__fmsub1__DOT__out2),32);
            tracep->chgIData(oldp+52,(((0x80000000U 
                                        & ((~ (IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalSign)) 
                                           << 0x1fU)) 
                                       | (((IData)(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                           << 0x17U) 
                                          | (0x7fffffU 
                                             & (vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                >> 1U))))),32);
            tracep->chgIData(oldp+53,(((0x80000000U 
                                        & ((~ (IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalSign)) 
                                           << 0x1fU)) 
                                       | (((IData)(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp) 
                                           << 0x17U) 
                                          | (0x7fffffU 
                                             & (vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant 
                                                >> 1U))))),32);
            tracep->chgIData(oldp+54,(((0x80000000U 
                                        & ((~ (IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalSign)) 
                                           << 0x1fU)) 
                                       | (((IData)(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp) 
                                           << 0x17U) 
                                          | (0x7fffffU 
                                             & (vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant 
                                                >> 1U))))),32);
            tracep->chgIData(oldp+55,(((0x80000000U 
                                        & ((~ (IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalSign)) 
                                           << 0x1fU)) 
                                       | (((IData)(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp) 
                                           << 0x17U) 
                                          | (0x7fffffU 
                                             & (vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant 
                                                >> 1U))))),32);
            tracep->chgIData(oldp+56,(vlTOPp->fpu_top__DOT__fmu),32);
            tracep->chgIData(oldp+57,(vlTOPp->fpu_top__DOT__fdi),32);
            tracep->chgIData(oldp+58,(((0x80000000U 
                                        & vlTOPp->fpu_top__DOT__operand_two) 
                                       | (0x7fffffffU 
                                          & vlTOPp->fpu_top__DOT__operand_one))),32);
            tracep->chgIData(oldp+59,(((0x80000000U 
                                        & ((~ (vlTOPp->fpu_top__DOT__operand_two 
                                               >> 0x1fU)) 
                                           << 0x1fU)) 
                                       | (0x7fffffffU 
                                          & vlTOPp->fpu_top__DOT__operand_one))),32);
            tracep->chgIData(oldp+60,(((0x80000000U 
                                        & (vlTOPp->fpu_top__DOT__operand_two 
                                           ^ vlTOPp->fpu_top__DOT__operand_one)) 
                                       | (0x7fffffffU 
                                          & vlTOPp->fpu_top__DOT__operand_one))),32);
            tracep->chgIData(oldp+61,(vlTOPp->fpu_top__DOT__fmin1__DOT__out),32);
            tracep->chgIData(oldp+62,(vlTOPp->fpu_top__DOT__fmax1__DOT__out),32);
            tracep->chgIData(oldp+63,(((vlTOPp->fpu_top__DOT__operand_one 
                                        == vlTOPp->fpu_top__DOT__operand_two)
                                        ? 1U : 0U)),32);
            tracep->chgIData(oldp+64,(vlTOPp->fpu_top__DOT__flt1__DOT__out),32);
            tracep->chgIData(oldp+65,(vlTOPp->fpu_top__DOT__fle1__DOT__out),32);
            tracep->chgIData(oldp+66,(vlTOPp->fpu_top__DOT__writeback_data),32);
            tracep->chgIData(oldp+67,(vlTOPp->fpu_top__DOT__ins_p3),32);
            tracep->chgIData(oldp+68,(vlTOPp->fpu_top__DOT__fmadd1__DOT__out),32);
            tracep->chgBit(oldp+69,((1U & ((vlTOPp->fpu_top__DOT__operand_one 
                                            ^ vlTOPp->fpu_top__DOT__operand_two) 
                                           >> 0x1fU))));
            tracep->chgCData(oldp+70,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fmul1__DOT__expF),8);
            tracep->chgIData(oldp+71,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fmul1__DOT__mantissa),24);
            tracep->chgIData(oldp+72,(((0U == vlTOPp->fpu_top__DOT__operand_one)
                                        ? 0U : (0x800000U 
                                                | (0x7fffffU 
                                                   & vlTOPp->fpu_top__DOT__operand_one)))),24);
            tracep->chgIData(oldp+73,(((0U == vlTOPp->fpu_top__DOT__operand_two)
                                        ? 0U : (0x800000U 
                                                | (0x7fffffU 
                                                   & vlTOPp->fpu_top__DOT__operand_two)))),24);
            tracep->chgQData(oldp+74,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fmul1__DOT__mantissaProd),48);
            tracep->chgBit(oldp+76,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__largerMag));
            tracep->chgBit(oldp+77,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalSign));
            tracep->chgCData(oldp+78,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Exp),8);
            tracep->chgCData(oldp+79,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Exp),8);
            tracep->chgCData(oldp+80,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalExp),8);
            tracep->chgIData(oldp+81,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num1Mant),24);
            tracep->chgIData(oldp+82,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__num2Mant),24);
            tracep->chgIData(oldp+83,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__finalMant),24);
            tracep->chgIData(oldp+84,(vlTOPp->fpu_top__DOT__fmadd1__DOT__fadd1__DOT__sumMants),25);
            tracep->chgIData(oldp+85,(vlTOPp->fpu_top__DOT__fmsub1__DOT__out),32);
            tracep->chgIData(oldp+86,(vlTOPp->fpu_top__DOT__fmsub1__DOT____Vcellinp__f1__num2),32);
            tracep->chgBit(oldp+87,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__largerMag));
            tracep->chgBit(oldp+88,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalSign));
            tracep->chgCData(oldp+89,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Exp),8);
            tracep->chgCData(oldp+90,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Exp),8);
            tracep->chgCData(oldp+91,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalExp),8);
            tracep->chgIData(oldp+92,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num1Mant),24);
            tracep->chgIData(oldp+93,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__num2Mant),24);
            tracep->chgIData(oldp+94,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__finalMant),24);
            tracep->chgIData(oldp+95,(vlTOPp->fpu_top__DOT__fmsub1__DOT__f1__DOT__sumMants),25);
            tracep->chgBit(oldp+96,((1U & ((vlTOPp->fpu_top__DOT__fmsub1__DOT__out 
                                            ^ vlTOPp->fpu_top__DOT__operand_three) 
                                           >> 0x1fU))));
            tracep->chgCData(oldp+97,(vlTOPp->fpu_top__DOT__fmsub1__DOT__fmul1__DOT__expF),8);
            tracep->chgIData(oldp+98,(vlTOPp->fpu_top__DOT__fmsub1__DOT__fmul1__DOT__mantissa),24);
            tracep->chgIData(oldp+99,(((0U == vlTOPp->fpu_top__DOT__fmsub1__DOT__out)
                                        ? 0U : (0x800000U 
                                                | (0x7fffffU 
                                                   & vlTOPp->fpu_top__DOT__fmsub1__DOT__out)))),24);
            tracep->chgIData(oldp+100,(((0U == vlTOPp->fpu_top__DOT__operand_three)
                                         ? 0U : (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlTOPp->fpu_top__DOT__operand_three)))),24);
            tracep->chgQData(oldp+101,(vlTOPp->fpu_top__DOT__fmsub1__DOT__fmul1__DOT__mantissaProd),48);
            tracep->chgIData(oldp+103,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1),32);
            tracep->chgIData(oldp+104,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__out),32);
            tracep->chgBit(oldp+105,((1U & ((vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1 
                                             ^ vlTOPp->fpu_top__DOT__operand_two) 
                                            >> 0x1fU))));
            tracep->chgCData(oldp+106,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fmul1__DOT__expF),8);
            tracep->chgIData(oldp+107,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fmul1__DOT__mantissa),24);
            tracep->chgIData(oldp+108,(((0U == vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1)
                                         ? 0U : (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlTOPp->fpu_top__DOT__fnmsub1__DOT__in1)))),24);
            tracep->chgQData(oldp+109,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fmul1__DOT__mantissaProd),48);
            tracep->chgBit(oldp+111,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__largerMag));
            tracep->chgBit(oldp+112,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalSign));
            tracep->chgCData(oldp+113,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Exp),8);
            tracep->chgCData(oldp+114,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Exp),8);
            tracep->chgCData(oldp+115,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalExp),8);
            tracep->chgIData(oldp+116,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num1Mant),24);
            tracep->chgIData(oldp+117,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__num2Mant),24);
            tracep->chgIData(oldp+118,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__finalMant),24);
            tracep->chgIData(oldp+119,(vlTOPp->fpu_top__DOT__fnmsub1__DOT__fsub1__DOT__f1__DOT__sumMants),25);
            tracep->chgIData(oldp+120,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__out),32);
            tracep->chgCData(oldp+121,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fmul1__DOT__expF),8);
            tracep->chgIData(oldp+122,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fmul1__DOT__mantissa),24);
            tracep->chgQData(oldp+123,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fmul1__DOT__mantissaProd),48);
            tracep->chgBit(oldp+125,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__largerMag));
            tracep->chgBit(oldp+126,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalSign));
            tracep->chgCData(oldp+127,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Exp),8);
            tracep->chgCData(oldp+128,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Exp),8);
            tracep->chgCData(oldp+129,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalExp),8);
            tracep->chgIData(oldp+130,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num1Mant),24);
            tracep->chgIData(oldp+131,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__num2Mant),24);
            tracep->chgIData(oldp+132,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__finalMant),24);
            tracep->chgIData(oldp+133,(vlTOPp->fpu_top__DOT__fnmadd1__DOT__fadd1__DOT__sumMants),25);
            tracep->chgBit(oldp+134,(vlTOPp->fpu_top__DOT__fadd1__DOT__largerMag));
            tracep->chgBit(oldp+135,(vlTOPp->fpu_top__DOT__fadd1__DOT__finalSign));
            tracep->chgCData(oldp+136,(vlTOPp->fpu_top__DOT__fadd1__DOT__num1Exp),8);
            tracep->chgCData(oldp+137,(vlTOPp->fpu_top__DOT__fadd1__DOT__num2Exp),8);
            tracep->chgCData(oldp+138,(vlTOPp->fpu_top__DOT__fadd1__DOT__finalExp),8);
            tracep->chgIData(oldp+139,(vlTOPp->fpu_top__DOT__fadd1__DOT__num1Mant),24);
            tracep->chgIData(oldp+140,(vlTOPp->fpu_top__DOT__fadd1__DOT__num2Mant),24);
            tracep->chgIData(oldp+141,(vlTOPp->fpu_top__DOT__fadd1__DOT__finalMant),24);
            tracep->chgIData(oldp+142,(vlTOPp->fpu_top__DOT__fadd1__DOT__sumMants),25);
            tracep->chgBit(oldp+143,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__largerMag));
            tracep->chgBit(oldp+144,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalSign));
            tracep->chgCData(oldp+145,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Exp),8);
            tracep->chgCData(oldp+146,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Exp),8);
            tracep->chgCData(oldp+147,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalExp),8);
            tracep->chgIData(oldp+148,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num1Mant),24);
            tracep->chgIData(oldp+149,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__num2Mant),24);
            tracep->chgIData(oldp+150,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__finalMant),24);
            tracep->chgIData(oldp+151,(vlTOPp->fpu_top__DOT__fsub1__DOT__f1__DOT__sumMants),25);
            tracep->chgCData(oldp+152,(vlTOPp->fpu_top__DOT__fmul1__DOT__expF),8);
            tracep->chgIData(oldp+153,(vlTOPp->fpu_top__DOT__fmul1__DOT__mantissa),24);
            tracep->chgQData(oldp+154,(vlTOPp->fpu_top__DOT__fmul1__DOT__mantissaProd),48);
            tracep->chgIData(oldp+156,(vlTOPp->fpu_top__DOT__fdiv1__DOT__temp_out),32);
            tracep->chgIData(oldp+157,((((IData)(0xbe6eb3beU) 
                                         - vlTOPp->fpu_top__DOT__operand_two) 
                                        >> 1U)),32);
            tracep->chgBit(oldp+158,(0U));
            tracep->chgCData(oldp+159,(vlTOPp->fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1__DOT__expF),8);
            tracep->chgIData(oldp+160,(vlTOPp->fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1__DOT__mantissa),24);
            tracep->chgIData(oldp+161,(((0U == (((IData)(0xbe6eb3beU) 
                                                 - vlTOPp->fpu_top__DOT__operand_two) 
                                                >> 1U))
                                         ? 0U : (0x800000U 
                                                 | (0x7fffffU 
                                                    & (((IData)(0xbe6eb3beU) 
                                                        - vlTOPp->fpu_top__DOT__operand_two) 
                                                       >> 1U))))),24);
            tracep->chgQData(oldp+162,(vlTOPp->fpu_top__DOT__fdiv1__DOT__fi0__DOT__f1__DOT__mantissaProd),48);
            tracep->chgBit(oldp+164,((1U & ((vlTOPp->fpu_top__DOT__operand_one 
                                             ^ vlTOPp->fpu_top__DOT__fdiv1__DOT__temp_out) 
                                            >> 0x1fU))));
            tracep->chgCData(oldp+165,(vlTOPp->fpu_top__DOT__fdiv1__DOT__fm0__DOT__expF),8);
            tracep->chgIData(oldp+166,(vlTOPp->fpu_top__DOT__fdiv1__DOT__fm0__DOT__mantissa),24);
            tracep->chgIData(oldp+167,(((0U == vlTOPp->fpu_top__DOT__fdiv1__DOT__temp_out)
                                         ? 0U : (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlTOPp->fpu_top__DOT__fdiv1__DOT__temp_out)))),24);
            tracep->chgQData(oldp+168,(vlTOPp->fpu_top__DOT__fdiv1__DOT__fm0__DOT__mantissaProd),48);
            tracep->chgCData(oldp+170,((0xffU & (vlTOPp->fpu_top__DOT__operand_one 
                                                 >> 0x17U))),8);
            tracep->chgCData(oldp+171,((0xffU & (vlTOPp->fpu_top__DOT__operand_two 
                                                 >> 0x17U))),8);
            tracep->chgIData(oldp+172,((0x7fffffU & vlTOPp->fpu_top__DOT__operand_one)),23);
            tracep->chgIData(oldp+173,((0x7fffffU & vlTOPp->fpu_top__DOT__operand_two)),23);
        }
        tracep->chgIData(oldp+174,(vlTOPp->instruction),32);
        tracep->chgBit(oldp+175,(vlTOPp->clk));
        tracep->chgIData(oldp+176,(vlTOPp->fpu_out),32);
        tracep->chgCData(oldp+177,((0x1fU & (vlTOPp->instruction 
                                             >> 0xfU))),5);
        tracep->chgCData(oldp+178,((0x1fU & (vlTOPp->instruction 
                                             >> 0x14U))),5);
        tracep->chgCData(oldp+179,((0x1fU & (vlTOPp->instruction 
                                             >> 0x1bU))),5);
        tracep->chgIData(oldp+180,(vlTOPp->fpu_top__DOT__fsqrt1__DOT__shifted_num),32);
    }
}

void Vfpu_top::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vfpu_top__Syms* __restrict vlSymsp = static_cast<Vfpu_top__Syms*>(userp);
    Vfpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
