module fcvrt_w_s(
	input logic [31:0] num1, // input of floating point number to be converted
	input logic [2:0] rm, // rounding applied to the number before integer conversion
	
	output logic [31:0] out_num // output of signed integer
); 
	
	logic [31:0] rounded_num, final_int;
	int i;
	logic [23:0] mantissa;
	round r0(num1, rm, rounded_num);
	
	always_comb begin
		if (rounded_num[30:23] >= 158 && rounded_num[31]) begin
			final_int = 32'h7FFFFFFF;
		end else if (rounded_num[30:23] >= 158 && !rounded_num[31]) begin
			final_int = 32'h10000000;
		end else if (rounded_num[30:23] < 127) begin
			final_int = 32'h00000000;
		end else begin
			i = 32'(rounded_num[30:23] - 127);
			final_int = 32'h00000001;
			final_int = final_int << i;
			mantissa = num1[22:0];
			mantissa = mantissa >> (23-i);
			final_int = final_int + mantissa;
		end
	end
	
	assign out_num = num1[31] ? (~final_int+1'b1) : final_int;
	
endmodule
