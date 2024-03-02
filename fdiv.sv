module fdiv (
	input logic [31:0] divisor,
	input logic [31:0] dividend,
	input logic [2:0] rm,
	output logic [31:0] div_out
);

	logic [31:0] temp_out;
	finv fi0(dividend, temp_out);
	fmul fm0(divisor, temp_out, rm, div_out);

endmodule;
