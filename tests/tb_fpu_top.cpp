#include <stdlib.h>
#include <verilated.h>
#include <iostream>
#include <verilated_vcd_c.h>
#include "Vfpu_top.h"
#include <bitset>
#include <math.h>

#define MAX_TIME 20
uint8_t cnt = 0;

float int32_to_float_32(uint32_t val) {
  float *f = (float*)&val;
  return *f;
}


 int main (int argc, char** argv, char** env) {
 	Vfpu_top *vdq = new Vfpu_top;
 	float f_a = 2.0;
 	uint32_t instr = 0x18078083; 
 	//x180780C3 -> fmadd rs0 x rs15 + rs3 -> rs1
 	//x000780C3 = 0x0000 0000 0000 0111 1000 0000 1101 0011
 	// fadd -> rs0 + rs15 -> rs1
 	
	vdq->instruction = instr;
	vdq->clk = 0;
	//vdq->regFile[0] = *((uint32_t*)(&f_a));
	//vdq->regFile[15] = *((uint32_t*)(&f_a));
	
	Verilated::traceEverOn(true);
 	VerilatedVcdC *l_trace = new VerilatedVcdC;
 	vdq->trace(l_trace, 5);
 	l_trace->open("Waveform.vcd");
		
 	while (cnt < MAX_TIME) {
 		vdq->clk ^= 1;
 		vdq->eval();
 		l_trace->dump(cnt);
 		cnt++;
 	}
 	
	uint32_t output = vdq->fpu_out;

	printf("Calculated: %f\n", int32_to_float_32(output));
	printf("Actual: %f\n", f_a+f_a);
 	l_trace->close();
 	exit(0);
 }
