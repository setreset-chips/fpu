module fsub (
	input logic [31:0] var1,
	input logic [31:0] var2,
	input logic [2:0] rm,
	output logic [31:0] res
);
	fadd f1(var1, {~var2[31], var2[30:0]}, rm, res);
endmodule;
