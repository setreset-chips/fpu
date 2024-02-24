#include <stdlib.h>
#include <verilated.h>
#include <iostream>
#include <verilated_vcd_c.h>
#include "Vfln.h"
#include <bitset>
#include <math.h>

#define MAX_TIME 20
uint8_t cnt = 0;

float int32_to_float_32(uint32_t val) {
  float *f = (float*)&val;
  return *f;
}


 int main (int argc, char** argv, char** env) {
 	Vfln *vdq = new Vfln;
 	float f_a = 1.56;
 	
	vdq->num1 = *((uint32_t*)(&f_a));
		
 	while (cnt < MAX_TIME) {
 		vdq->eval();
 		cnt++;
 	}
 	
	uint32_t output = vdq->out1;

	printf("Calculated: %f\n", int32_to_float_32(output));
	printf("Actual: %f\n", ln(f_a));
 	exit(0);
 }
