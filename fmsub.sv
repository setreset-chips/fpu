module fmsub ( 
	input [31:0] var1,
	input [31:0] var2,
	input [31:0] var3,
	output [31:0] res
);

	logic [31:0] in1;
	logic [31:0] in2;
	logic [31:0] in3;
	logic [31:0] out;
	logic [31:0] out2;
	assign in1 = var1;
	assign in2 = var2;
	assign in3 = var3;
	
		fadd f1(.num1(in1), .num2({~in2[31], in2[30:0]}), .out_num(out));
		fmul fmul1(.num1(out), .num2(in3), .out_mul(out2));

		assign res = out2;

endmodule
