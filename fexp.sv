module fexp(
	input logic [31:0] exp,
	
	output logic [31:0] out_num
);

	logic [31:0] one, one_half, one_sixth, one_twenty_fourth, one_120th;
	assign one = 32'h3F800000;
	assign one_half = 32'h3F000000;
	assign one_sixth = 32'h3E2AAAAB;
	assign one_twenty_fourth = 32'h3D2AAAAB;
	assign one_120th = 32'h3C088889;
	
	logic [31:0] temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8;
	
	fadd fa0(one, exp, temp1); // first two terms = 1 + x
	fmul fm0(exp, exp, temp2); // generate intermediate for term three, x^2
	FMA fma0(temp2, one_half, temp1, temp3); // generate term 3, x^2/2, and add to running total
	fmul fm1(temp2, exp, temp4); // generate intermediate for term 4, x^3.
	FMA fma1(temp4, one_sixth, temp3, temp5); // generate term 4, x^3/6 and add to running total
	fmul fm2(temp4, exp, temp6); // generate intermediate for term 5, x^4.
	FMA fma2(temp6, one_twenty_fourth, temp5, temp7); // generate term 5, x^4/24 and add to running total
	fmul fm3(temp6, exp, temp8); // generate intermediate for term 6, x^5
	FMA fma3(temp8, one_120th, temp7, out_num); // generate term 6, x^5/120 and add to total to get the output.
	
endmodule
