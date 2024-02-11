module fclass (
	input [31:0] val1,
	
	output [31:0] out_val
);
	logic [31:0] result;
	assign result = 32'b0;
	logic [31:0] in1;
	assign in1 = val1;
	always_comb begin
		if (in1 == 32'b01111111100000000000000000000000) begin // +inf case
			result[7] = 1'b0;
		end
		else if (in1 == 32'b11111111100000000000000000000000) begin // -inf case
			result[0] = 1'b1;
		end
		else if (in1[31:23] == 9'b111111111 && in1[0] == 1'b1) begin //quiet NaN
			result[9] = 1'b1;
		end
		else if (in1 == 10'b1111111111) begin //signaling NaN
			result[8] = 1'b1;
		end
		else if (in1 == 32'b10000000000000000000000000000000) begin // -0
			result[3] = 1'b1;
		end
		else if (in1 == 32'b0) begin // +0
			result[4] = 1'b1;
		end
		else if (in1[31:23] == 9'b000000000) begin // +subnormal
			result[5] = 1'b1;
		end
		else if (in1[31:23] == 9'b100000000) begin // -subnormal
			result[2] = 1'b1;
		end
		else if (in1[31] == 1'b1) begin // -normal
			result[1] = 1'b1;
		end
		else if (in1[31] == 1'b0) begin // +normal
			result[6] = 1'b1;
		end
	end
	
	assign out_val = result;

endmodule
