// TODO: Optimize Adds and Multiplications to become FMAs.
module fln (
            input logic [31:0] num1,
            output logic [31:0] out1
);

	logic nanFlag;
	assign nanFlag = num1[31];
	logic [31:0] op1 = {1'b0, num1[30:0]};
	
	logic [31:0] temp1, temp2, temp3i, temp3, temp4, temp5, temp6, temp7, temp8;
	fadd fa0(op1, 32'h3F800000, op1);
	finv fi0(op1,temp1);
	fmul fm0(temp1, temp1, temp2);
	fmul fm1(temp1, temp2, temp3i);
	fmul fm2(temp3i, 32'h40000000, temp3);
	fmul fm3(temp3i, temp1, temp4);
	fmul fm4(temp4, 32'h40C00000, temp4);
	fmul fm5(temp3i, temp2, temp5);
	fmul fm6(temp5, 32'h41C00000, temp5);
	//temp1-temp2+temp3-temp4+temp5
   	fadd fa0(temp1, {~temp2[31], temp2[30:0]}, temp6);
   	fadd fa1(temp3, {~temp4[31], temp4[30:0]}, temp7);
   	fadd fa2(temp6, temp7, temp8);
   	fadd fa3(temp8, temp5, temp8);
  
   	
   	assign out1 = nanFlag ? 32'h7FC00000 : temp8;
   	
endmodule;
