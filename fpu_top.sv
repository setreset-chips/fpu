module fpu_top (
	input logic [31:0] instruction,
	input logic clk,
	
	output logic [31:0] fpu_out
);
	logic [31:0] operand_one, operand_two, operand_three;
	logic [31:0] regFile [4:0];
	typedef enum logic [4:0] {
		FMADD, FMSUB, FNMSUB, FNMADD, FADD, FSUB, FMUL, FDIV, 
		FSQRT, FSGNJ, FSGNJN, FSGNJX, FMIN, FMAX, FCVRTWS, FCVRTWUS, 
		FMVXW, FEQ, FLT, FLE, FCLASS, FCVRTSW, FCVRTSWU, FMVWX
	} operations;
// No Memory Operations Supported (Yet)
// 4-Stage Pipeline
// Stage 1: Fetch Operands
// Stage 2: Decode
// Stage 3: Execute
// Stage 4: Writeback
//Wait State - might be buggy - hold state too
//
// RISC-V INSTRUCTION OPCODES ARE ACTUAL POO:
//
// FEQ/FLE/FLT - Check opcode2 and 14-12
// FCVRTWS/WUS - Check opcode2 and 20
// FSGNJ(X/N) - Check opcode2 and 14-12
// FMIN/FMAX - Check opcode2 and 14-12
// FCVRTSW/SWU - Check opcode2 and 20
// Rest are chill
//
//	Stage 1: Fetch Operands
	logic [4:0] op1_addr, op2_addr, op3_addr;
	assign op1_addr = instruction[19:15];
	assign op2_addr = instruction[24:20];
	assign op3_addr = instruction[31:27];

	always_ff @ (posedge clk, posedge s1flag) begin // Stage 1: Fetch Operands
                operand_one <= regFile[op1_addr];
		operand_two <= regFile[op2_addr];
		operand_three <= regFile[op3_addr];	
	end

	logic [4:0] dest_reg;
	assign dest_reg = instruction[11:7];
	
	logic [4:0] opcode1;
	assign opcode1 = instruction[6:2];
	logic [4:0] opcode2;
	assign opcode2 = instruction[31:27];
	logic [1:0] opcode3;
	assign opcode3 = instruction[13:12];
	logic opcode4;
	assign opcode4 = instruction[20];

	operations curr_op;

	always @ (posedge clk) begin // Stage 2: Decode
		if (opcode1[4:2] == 3'b101) begin
			case (opcode1[1:0]) 
				2'b00: curr_op = FMADD;
				2'b01: curr_op = FMSUB;
				2'b10: curr_op = FNMSUB;
				2'b11: curr_op = FNMADD;
			endcase
		end
		else if (opcode1[4:2] == 3'b100) begin
			case (opcode2) 
				5'b00000: curr_op = FADD;
				5'b00001: curr_op = FSUB;
				5'b00010: curr_op = FMUL;
				5'b00011: curr_op = FDIV;
				5'b01011: curr_op = FSQRT;
				5'b00100: curr_op = opcode3[1] ? FSGNJX : opcode[0] ? FSGNJN : FSGNJ;
				5'b00101: curr_op = opcode3[0] ? FMAX : FMIN;
				5'b11000: curr_op = opcode4 ? FCVRTWUS : FCVRTWS;
				5'b11100: curr_op = opcode3[0] ? FCLASS : FMVXW;
				5'b10100: curr_op = opcode3[1] ? FEQ : opcode[0] ? FLT : FLE;
				5'b11010: curr_op = opcode4 ? FCVRTSWU : FCVRTSW;
				5'b11110: curr_op = FMVWX;
			endcase
		end
	end

	always_comb begin // Stage 3: Execution

	end

endmodule
