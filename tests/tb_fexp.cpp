#include <stdlib.h>
#include <verilated.h>
#include <iostream>
#include <verilated_vcd_c.h>
#include "Vfexp.h"
#include <bitset>
#include <math.h>

#define MAX_TIME 20
uint8_t cnt = 0;

float int32_to_float_32(uint32_t val) {
  float *f = (float*)&val;
  return *f;
}


 int main (int argc, char** argv, char** env) {
 	Vfexp *vdq = new Vfexp;
 	float f_a = 1;
 	
	vdq->exp = *((uint32_t*)(&f_a));
	//vdq->num2 = *((uint32_t*)(&f_b));
		
 	while (cnt < MAX_TIME) {
 		vdq->eval();
 		cnt++;
 	}
 	
	uint32_t output = vdq->out_num;

	printf("Calculated: %f\n", int32_to_float_32(output));
	printf("Actual: %f\n", exp(f_a));
 	exit(0);
 }
