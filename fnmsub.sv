module fnmsub ( 
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
	
		assign in1 = {!var1[31], var1[30:0]};
		assign in2 = var2;
		assign in3 = var3;
	
	
		fmul fmul1(.var1(in1), .var2(in2), .res(out));
		fsub fsub1(.var1(in1), .var2(in2), .res(out2));

		assign res = out2;

endmodule
