#include <stdlib.h>
#include <verilated.h>
#include <iostream>
#include <verilated_vcd_c.h>
#include "VFMA.h"
#include <bitset>
#include <math.h>

#define MAX_TIME 20
uint8_t cnt = 0;

float int32_to_float_32(uint32_t val) {
  float *f = (float*)&val;
  return *f;
}


 int main (int argc, char** argv, char** env) {
 	VFMA *vdq = new VFMA;
 	float f_a = -7.284;
 	float f_b = 8.883;
 	float f_c = 69.487;
 	
	vdq->a_fp = *((uint32_t*)(&f_a));
	vdq->b_fp = *((uint32_t*)(&f_b));
	vdq->c_fp = *((uint32_t*)(&f_c));
		
 	while (cnt < MAX_TIME) {
 		vdq->eval();
 		cnt++;
 	}
 	
	uint32_t output = vdq->out_fp;
	//uint32_t output_mul = vdq->out_mul;

	//printf("Actual: %f\n", s);
	printf("Calculated: %f\n", int32_to_float_32(output));
	printf("Actual: %f\n", (f_a*f_b)+f_c);
	//printf("Mul Res: %f\n", int32_to_float_32(output_mul));
 	//l_trace->close();
 	exit(0);
 }
