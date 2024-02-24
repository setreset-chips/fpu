module frelu(
	input logic [31:0] num1,
	output logic [31:0] out1
);	
		
	fmax f0(num1, 32'b0, out1);

endmodule;
