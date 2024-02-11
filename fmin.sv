module fmin (
	input [31:0] var1,
	input [31:0] var2,
	output [31:0] res
);

	logic [31:0] in1;
	logic [31:0] in2;
	logic [31:0] out;
	assign in1 = var1;
	assign in2 = var2;
	

	logic [7:0] exp1 = in1[30:23];
	logic [7:0] exp2 = in2[30:23];

	logic [22:0] mantissa1 = in1[22:0];
	logic [22:0] mantissa2 = in2[22:0];
	always_comb begin
		if (in1[31] == 1 && in2[31] == 0) begin
			res = in2;
		end else if (in1[31] == 0 && in2[31] == 1) begin
			res = in1;
		end else if (in1[31] == 0 && in2[31] == 0) begin
			if (exp1 > exp2) begin
				res = in1;
			end else if (exp2 > exp1) begin
				res = in2;
			end else begin
				res = (mantissa1 >= mantissa2) ? in1 : in2;
			end
		end else begin
			if (exp1 > exp2) begin
				res = in2;
			end else if (exp2 > exp1) begin
				res = in1;
			end else begin
				res = (mantissa1 >= mantissa2) ? in2 : in1;
			end
		end
	end
	
endmodule
