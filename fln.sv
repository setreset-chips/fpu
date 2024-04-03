// TODO: Optimize Adds and Multiplications to become FMAs.
module fln (
            input logic [31:0] num1,
            output logic [31:0] out1
);

	logic nanFlag;
	assign nanFlag = num1[31];
	logic [31:0] op1 = {1'b0, num1[30:0]};
	
	logic [31:0] temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, op1i, temp9, temp10;
	fadd fa0(op1, 32'hBF800000, 3'b000, op1i); // term 1 of the taylor expansion - (x-1) (op1i)
	fmul fm0(op1i, op1i, 3'b000, temp1); // Term 2 intermediate - (x-1)^2
  	fmul fm1(temp1, 32'hBF000000, 3'b000, temp2); // Term 2 - -0.5 * (x-1)^2 (term2)
  	fmul fm2(temp1, op1i, 3'b000, temp3); // Term 3 intermediate - (x-1)^3
  	fmul fm3(temp3, 32'h3EAAAAAB, 3'b000, temp4); // Term 3 - (1/3) * (x-1)^3 (temp4)
  	fmul fm4(temp3, op1i, 3'b000, temp5); // Term 4 intermediate - (x-1)^4
  	FMA fma1(temp5, 32'hBE800000, temp4, temp6); // Term 4 - -0.25 * (x-1)^4 + term4
  	fadd fa1(temp6, temp2, 3'b000, temp7);
  	fadd fa2(temp7, op1i, 3'b000, temp8);
 	fmul fm5(temp4, op1i, 3'b000, temp9);
 	FMA fma2(temp9, 32'h3E4CCCCD, temp8, temp10);
   	
   	assign out1 = nanFlag ? 32'h7FC00000 : temp10;
   	
endmodule;
