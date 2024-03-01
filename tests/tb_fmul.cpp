#include <stdlib.h>
#include <verilated.h>
#include <iostream>
#include <verilated_vcd_c.h>
#include "Vfmul.h"
#include <bitset>
#include <math.h>

#define MAX_TIME 20
uint8_t cnt = 0;

float int32_to_float_32(uint32_t val) {
  float *f = (float*)&val;
  return *f;
}


 int main (int argc, char** argv, char** env) {
 	Vfmul *vdq = new Vfmul;
 	float f_a = 6.9;
 	float f_b = 4.0;
 	
	vdq->num1 = *((uint32_t*)(&f_a));
	vdq->num2 = *((uint32_t*)(&f_b));
		
 	while (cnt < MAX_TIME) {
 		vdq->eval();
 		cnt++;
 	}
 	
	uint32_t output = vdq->out_mul;

	printf("Calculated: %f\n", int32_to_float_32(output));
	printf("Actual: %f\n", f_a*f_b);
 	exit(0);
 }
