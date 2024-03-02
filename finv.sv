module finv(
	input logic [31:0] num1,
	output logic [31:0] num_out
);

	logic [31:0] magic_number, temp_out;
	assign magic_number = 32'hBE6EB3BE;
	assign temp_out = ((magic_number - num1) >> 1);
	fmul f1 (temp_out, temp_out, 3'b000, num_out);
	
endmodule
