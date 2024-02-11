module feq (
	input [31:0] var1,
	input [31:0] var2,
	output [31:0] res
);

	always_comb begin
		res = (var1 == var2) ? 32'b1 : 32'b0;
	end
endmodule
