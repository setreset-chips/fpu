module fcvrt_swu(
	input logic [31:0] num1, // input of a signed 32-bit integer
	input logic [2:0] rm, // rounding mode for once we're done
	output logic [31:0] out_num // output of a rounded floating-point number
);
	
	logic sign;
	logic [22:0] mantissa;
	logic [7:0] exp;
	logic [54:0] total_num;
	int offset;
	
	always_comb begin
		sign = 1'b0;
		exp = 8'h7F;
		if (num1[31]) begin
			offset = 31;
		end else if (num1[30]) begin
			offset = 30;
		end else if (num1[29]) begin
			offset = 29;
		end else if (num1[28]) begin
			offset = 28;
		end else if (num1[27]) begin
			offset = 27;
		end else if (num1[26]) begin
			offset = 26;
		end else if (num1[25]) begin
			offset = 25;
		end else if (num1[24]) begin
			offset = 24;
		end else if (num1[23]) begin
			offset = 23;
		end else if (num1[22]) begin
			offset = 22;
		end else if (num1[21]) begin
			offset = 21;
		end else if (num1[20]) begin
			offset = 20;
		end else if (num1[19]) begin
			offset = 19;
		end else if (num1[18]) begin
			offset = 18;
		end else if (num1[17]) begin
			offset = 17;
		end else if (num1[16]) begin
			offset = 16;
		end else if (num1[15]) begin
			offset = 15;
		end else if (num1[14]) begin
			offset = 14;
		end else if (num1[13]) begin
			offset = 13;
		end else if (num1[12]) begin
			offset = 12;
		end else if (num1[11]) begin
			offset = 11;
		end else if (num1[10]) begin
			offset = 10;
		end else if (num1[9]) begin
			offset = 9;
		end else if (num1[8]) begin
			offset = 8;
		end else if (num1[7]) begin
			offset = 7;
		end else if (num1[6]) begin
			offset = 6;
		end else if (num1[5]) begin
			offset = 5;
		end else if (num1[4]) begin
			offset = 4;
		end else if (num1[3]) begin
			offset = 3;
		end else if (num1[2]) begin
			offset = 2;
		end else if (num1[1]) begin
			offset = 1;
		end else if (num1[0]) begin
			offset = 0;
		end else begin
			offset = -1;
		end
		total_num = {num1, 23'b0};
		exp += 8'(offset);
		mantissa = (offset == -1) ? 23'b0 : total_num[offset+22 -: 23];
	end
	
	assign out_num = offset == -1 ? 32'b0 : {sign, exp, mantissa};
	
endmodule
