#include <stdlib.h>
#include <verilated.h>
#include <iostream>
#include <verilated_vcd_c.h>
#include "Vfma.h"
#include <bitset>
#include <math.h>

#define MAX_TIME 20
uint8_t cnt = 0;

float int32_to_float_32(uint32_t val) {
  float *f = (float*)&val;
  return *f;
}


 int main (int argc, char** argv, char** env) {
 	Vfma *vdq = new Vfma;
 	float f_a = 1.0;
 	float f_b = 2.0;
 	float f_c = 3.0;
 	Verilated::traceEverOn(true);
 	VerilatedVcdC *l_trace = new VerilatedVcdC;
 	vdq->trace(l_trace, 5);
 	l_trace->open("vfma.vcd");
 	
	vdq->a_fp = *((uint32_t*)(&f_a));
	vdq->b_fp = *((uint32_t*)(&f_b));
	vdq->c_fp = *((uint32_t*)(&f_c));
		
 	while (cnt < MAX_TIME) {
 		vdq->eval();
 		l_trace->dump(cnt);
 		cnt++;
 	}
 	
	uint32_t output = vdq->out_fp;

	//printf("Actual: %f\n", s);
	printf("Calculated: %f\n", int32_to_float_32(output));
	printf("Actual: %f\n", (f_a*f_b)+f_c);
 	l_trace->close();
 	exit(0);
 }
