module fpu_top (
	input logic [31:0] instructions,
	input logic clk,
	
	output logic [31:0] fpu_out
);

	logic [31:0] regFile [4:0];
// 4-Stage Pipeline
// Stage 1: Fetch Operands (Only for Memory)
// Stage 2: Decode
// Stage 3: Execute
// Stage 4: Writeback
	
	always @ () begin // Stage 1: Fetch Operands
		
		
		
	end
	always_ff @ (posedge clk, posedge s1flag) begin // Stage 1 Register
	
	end
	
endmodule
