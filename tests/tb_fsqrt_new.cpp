#include <stdlib.h>
#include <verilated.h>
#include <iostream>
#include <verilated_vcd_c.h>
#include "Vfsqrt_new.h"
#include <bitset>
#include <math.h>

#define MAX_TIME 20
uint8_t cnt = 0;

float int32_to_float_32(uint32_t val) {
  float *f = (float*)&val;
  return *f;
}


 int main (int argc, char** argv, char** env) {
 	Vfsqrt_new *vdq = new Vfsqrt_new;
 	float sc = 96;
 	Verilated::traceEverOn(true);
 	VerilatedVcdC *l_trace = new VerilatedVcdC;
 	vdq->trace(l_trace, 5);
 	l_trace->open("vfsqrt.vcd");

	vdq->var1 = *((uint32_t*)(&sc));

 	while (cnt < MAX_TIME) {
 		vdq->eval();
 		l_trace->dump(cnt);
 		cnt++;
 	}

	uint32_t output = vdq->res;

	//printf("Actual: %f\n", s);
	printf("Calculated: %f\n", int32_to_float_32(output));
	printf("Actual: %f\n", sqrt(sc));
 	l_trace->close();
 	exit(0);
 }
