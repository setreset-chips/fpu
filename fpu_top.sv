module fpu_top (
	input logic [31:0] instruction,
	input logic clk,
	
	output logic [31:0] fpu_out
);
	logic [31:0] operand_1, operand_2, operand_3;
	logic [31:0] regFile [32];
	logic [31:0] fcsr;
	typedef enum logic [4:0] {
		FMADD=5'b00000, FMSUB=5'b00001, FNMSUB=5'b00010, FNMADD=5'b00011, FADD=5'b00100, FSUB, FMUL, FDIV, 
		FSQRT, FSGNJ, FSGNJN, FSGNJX, FMIN, FMAX, FCVRTWS, FCVRTWUS, 
		FMVXW, FEQ, FLT, FLE, FCLASS, FCVRTSW, FCVRTSWU, FMVWX,
		FINVALID
	} operations;
	
	assign regFile[0] = 32'h40000000;
	assign regFile[3] = 32'h40000000;
	assign regFile[15] = 32'h40000000;
	
// Excluded Opcodes: Any of the CVRT Family, MV Family.	

// No Memory Operations Supported Inside FPU (Which explains itself tbh).
// 4-Stage Pipeline
// Stage 1: Fetch Operands
// Stage 2: Decode
// Stage 3: Execute
// Stage 4: Writeback
//Wait State - might be buggy - hold state too
//
// RISC-V INSTRUCTION OPCODES ARE ACTUALLY WACK:
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
	
	logic [31:0] ins_p1;
	
	// Stage 1: Fetch Operands
	always_ff @ (posedge clk) begin // Pipeline Registers -> Fetch Operands - Decode
                operand_1 <= regFile[op1_addr];
		operand_2 <= regFile[op2_addr];
		operand_3 <= regFile[op3_addr];
		ins_p1 <= instruction;
	end
	
	logic [4:0] opcode1;
	assign opcode1 = ins_p1[6:2];
	logic [4:0] opcode2;
	assign opcode2 = ins_p1[31:27];
	logic [1:0] opcode3;
	assign opcode3 = ins_p1[13:12];
	logic opcode4;
	assign opcode4 = ins_p1[20];

	operations curr_op;
	logic [31:0] oper1, oper2, oper3;

	always @ (posedge clk) begin // Stage 2: Decode
		oper1 = operand_1;
		oper2 = operand_2;
		oper3 = operand_3;
		if (opcode1[4:2] == 3'b100) begin
			case (opcode1[1:0]) 
				2'b00: curr_op = FMADD;
				2'b01: curr_op = FMSUB;
				2'b10: curr_op = FNMSUB;
				2'b11: curr_op = FNMADD;
				default: curr_op = FINVALID;
			endcase
		end
		else if (opcode1[4:2] == 3'b101) begin
			case (opcode2) 
				5'b00000: curr_op = FADD;
				5'b00001: curr_op = FSUB;
				5'b00010: curr_op = FMUL;
				5'b00011: curr_op = FDIV;
				5'b01011: curr_op = FSQRT;
				5'b00100: curr_op = opcode3[1] ? FSGNJX : opcode3[0] ? FSGNJN : FSGNJ;
				5'b00101: curr_op = opcode3[0] ? FMAX : FMIN;
				5'b11000: curr_op = opcode4 ? FCVRTWUS : FCVRTWS;
				5'b11100: curr_op = opcode3[0] ? FCLASS : FMVXW;
				5'b10100: curr_op = opcode3[1] ? FEQ : opcode3[0] ? FLT : FLE;
				5'b11010: curr_op = opcode4 ? FCVRTSWU : FCVRTSW;
				5'b11110: curr_op = FMVWX;
				default: curr_op = FINVALID;
			endcase
		end
	end
	
	operations exec_op;
	logic [31:0] ins_p2, operand_one, operand_two, operand_three;
	
	always_ff @ (posedge clk) begin // Pipeline Register -> Decode - Execution
		operand_one <= oper1;
		operand_two <= oper2;
		operand_three <= oper3;
		exec_op <= curr_op;
		ins_p2 <= ins_p1;
	end

	logic [31:0] result;
	logic [31:0] fma, fms, fnms, fnma, fad, fsu, fmu, fdi, fsq, fsj, fsn, fsx, fmi, fmx, fq, ft, fe, fcls;
	logic [2:0] rm;
	assign rm = (ins_p2[14:12] == 3'b111) ? fcsr[7:5] : ins_p2[14:12];
	fmadd fmadd1(operand_one, operand_two, operand_three, rm, fma);
	fmsub fmsub1(operand_one, operand_two, operand_three, rm, fms);
	fnmsub fnmsub1(operand_one, operand_two, operand_three, rm, fnms);
	fnmadd fnmadd1(operand_one, operand_two, operand_three, rm, fnma);
	fadd fadd1(operand_one, operand_two, rm, fad);
	fsub fsub1(operand_one, operand_two, rm, fsu);
	fmul fmul1(operand_one, operand_two, rm, fmu);
	fdiv fdiv1(operand_one, operand_two, rm, fdi);
	fsqrt fsqrt1(operand_one, rm, fsq);
	fsgnj fsgnj1(operand_one, operand_two, fsj);
	fsgnjn fsgnjn1(operand_one, operand_two, fsn);
	fsgnjx fsgnjx1(operand_one, operand_two, fsx);
	fmin fmin1(operand_one, operand_two, fmi);
	fmax fmax1(operand_one, operand_two, fmx);
	//FCVRTWS fcvrtws(); -> Belongs in ALU_TOP with integer RegFile and FPU RegFile
	//FCVRTWUS fcvrtwus(); -> Belongs in ALU_TOP with integer RegFile and FPU RegFile
	//FMVXW fmvxw(); -> Not implemented as it is a memory instruction -> Goes in LSU
	feq feq1(operand_one, operand_two, fq);
	flt flt1(operand_one, operand_two, ft);
	fle fle1(operand_one, operand_two, fe);
	fclass fclass1(operand_one, fcls);
	//FCVRTSW fcvrtsw(); -> Belongs in ALU_TOP with integer RegFile and FPU RegFile
	//FCVRTSWU fcvrtswu(); -> Belongs in ALU_TOP with integer RegFile and FPU RegFile
	//FMVWX fmvwx(); -> Not implemented as it is a memory instruction -> Goes in LSU
	
	// What if you could pass through Floating Point Immediates? (12 bits)
	// 12 Bits -> 1 sign, 4 exp, 7 mantissa
	// +/- 2^(exp-7) * 1.mant
	// Would be pretty cool
	// Anyways here's the exec pipeline stage
	
	// Stage 3: Execution
	always @ (posedge clk) begin 
		case (exec_op) 
			FMADD: result = fma;
			FMSUB: result = fms;
			FNMSUB: result = fnms;
			FNMADD: result = fnma;
			FADD: result = fad;
			FSUB: result = fsu;
			FMUL: result = fmu;
			FDIV: result = fdi;
			FSQRT: result = fsq;
			FSGNJ: result = fsj;
			FSGNJN: result = fsn;
			FSGNJX: result = fsx;
			FMIN: result = fmi;
			FMAX: result = fmx;
			FEQ: result = fq;
			FLT: result = ft;
			FLE: result = fe;
			FCLASS: result = fcls;
			FINVALID: result = 32'h7FC00000;
			default: result = 32'h7FC00000;
		endcase
	end
	
	logic [31:0] writeback_data, ins_p3;
	
	always_ff @ (posedge clk) begin // Pipeline Register -> Execution - Writeback
		writeback_data <= result;
		ins_p3 <= ins_p2;
	end
	
	// Stage 4: Writeback
	always_ff @ (posedge clk) begin
		regFile[ins_p3[11:7]] <= writeback_data;
	end
	assign fpu_out = writeback_data;

endmodule
