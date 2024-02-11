module fsgnj (
	input [31:0] val1,
	input [31:0] val2,
	
	output [31:0] out_val
);

	assign out_val = {val2[31], val1[30:0]};

endmodule
