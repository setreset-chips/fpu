#include <stdlib.h>
#include <verilated.h>
#include <iostream>
#include <verilated_vcd_c.h>
#include "Vround.h"
#include <bitset>
#include <math.h>

#define MAX_TIME 20
uint8_t cnt = 0;

float int32_to_float_32(uint32_t val) {
  float *f = (float*)&val;
  return *f;
}


 int main (int argc, char** argv, char** env) {
 	Vround *vdq = new Vround;
 	float f_a = 6.9;
 	
	vdq->num1 = *((uint32_t*)(&f_a));
	vdq->rm = 0x0;
		
 	while (cnt < MAX_TIME) {
 		vdq->eval();
 		cnt++;
 	}
 	
	uint32_t output = vdq->rounded_num;

	printf("Calculated: %f\nbits: %x\n", int32_to_float_32(output), output);
	//printf("Actual: %f\n", f_a+f_b);
 	exit(0);
 }
