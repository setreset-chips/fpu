module fsqrt ( 
	input [31:0] var1,

	output [31:0] res
);

	logic [31:0] in1;
	logic [31:0] out;
	
	always_comb begin

		in1 = var1;
	
		in1 = in1 >> 1;
	
		out = in1-32'h5F3759DF;
	
		res = out;
	
	end
	
endmodule
