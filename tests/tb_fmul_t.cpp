#include <stdlib.h>
#include <verilated.h>
#include <iostream>
#include <verilated_vcd_c.h>
#include "Vfmul_new_total.h"
//#include "Vfmul.h"
#include <bitset>
#include <math.h>

#define MAX_TIME 20
uint8_t cnt = 0;

float int32_to_float_32(uint32_t val) {
  float *f = (float*)&val;
  return *f;
}


 int main (int argc, char** argv, char** env) {
 	Vfmul_new_total *vdq = new Vfmul_new_total;
    //Vfmul *dut = new Vfmul;
 	float f_a = 0.0021;
 	float f_b = 1.8e35;
 	
	vdq->num1 = *((uint32_t*)(&f_a));
	vdq->num2 = *((uint32_t*)(&f_b));
    //vdq->rm = 0;
	vdq->eval();

    //dut->num1 = *((uint32_t*)(&f_a));
    //dut->num2 = *((uint32_t*)(&f_b));
    //dut->rm = 0;
	//dut->eval();
 	// while (cnt < MAX_TIME) {
 	// 	vdq->eval();
 	// 	cnt++;
 	// }
 	
	uint32_t output = vdq->out_mul;
    //uint32_t output_gold = dut->out_mul;

	printf("Calculated: %f\n", int32_to_float_32(output));
	printf("Actual: %f\n", f_a*f_b);
    //printf("Actual(fmul): %f\n", int32_to_float_32(output_gold));
 	exit(0);
 }
