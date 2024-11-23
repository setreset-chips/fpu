module fsqrt ( 
	input logic [31:0] var1,
	input logic [2:0] rm,
	output logic [31:0] res
);

	/*logic [31:0] num_out, temp2_out;
	
	logic [31:0] magic_number, temp_out;
	assign magic_number = 32'hBE6EB3BE;
	assign temp_out = ((magic_number - var1) >> 1);
	finv i0(temp_out, res);*/
       logic [31:0] shifted_num;
       assign shifted_num = (var1 + (127 << 23)) >> 1;
       //assign shifted_num = shifted_num >> 1;
       round r0(shifted_num, rm, res);
endmodule
