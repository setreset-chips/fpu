#include <stdlib.h>
#include <verilated.h>
#include <iostream>
#include <verilated_vcd_c.h>
#include "Vfadd.h"
#include <bitset>
#include <math.h>

#define MAX_TIME 20
uint8_t cnt = 0;

float int32_to_float_32(uint32_t val) {
  float *f = (float*)&val;
  return *f;
}


 int main (int argc, char** argv, char** env) {
 	Vfadd *vdq = new Vfadd;
 	float f_a = 5e-43;
 	float f_b = 9.23e-45;
 	float f_c = f_a+f_b;
 	
	vdq->num1 = *((uint32_t*)(&f_a));
	vdq->num2 = *((uint32_t*)(&f_b));
		
 	while (cnt < MAX_TIME) {
 		vdq->eval();
 		cnt++;
 	}
 	
	uint32_t output = vdq->out_num;
	std::scientific;
	printf("Calculated: %e\n", int32_to_float_32(output));
	printf("Actual    : %e\n", f_c);
 	exit(0);
 }
