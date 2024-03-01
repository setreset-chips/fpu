module fmadd ( 
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
	

	
	fmul fmul1(.num1(in1), .num2(in2), .out_mul(out));
	fadd fadd1(.num1(out), .num2(in3), .out_num(out2));	
		
	assign res = out2;

endmodule
