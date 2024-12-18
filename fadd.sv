module fadd (
	input logic [31:0] num1,
	input logic [31:0] num2,
	input logic [2:0] rm,
	output logic [31:0] out_num
);
	// Arithmetic Signals
	logic largerMag, finalSign, leadMantBit1, leadMantBit2, subnormal;
	logic [7:0] num1Exp, num2Exp, finalExp;
	logic [23:0] num1Mant, num2Mant, finalMant;
	logic [24:0] sumMants;
	// Rounding Signals
	logic [23:0] mask, r_shifted_out;
	logic guard, round, sticky;

	//int i;
	
	always_comb begin
	
		finalSign = 1'b0;
		largerMag = 1'b0;
   		num1Exp = num1[30:23]; //mul
   		num2Exp = num2[30:23]; //add
   		leadMantBit1 = num1Exp == 8'h00 ? 1'b0 : 1'b1;
		leadMantBit2 = num2Exp == 8'h00 ? 1'b0 : 1'b1;
   		num1Mant = {leadMantBit1, num1[22:0]};
   		num2Mant = {leadMantBit2, num2[22:0]};
   		subnormal = ~(leadMantBit1 & leadMantBit2);
		mask = 24'hFFFFFF;
      
   		if(num1Exp < num2Exp) begin
   			finalExp = num2Exp;
			r_shifted_out = num1Mant;
  	 		num1Mant = num1Mant >> (finalExp - num1Exp);
  	 		largerMag = 1'b1;
			mask = mask << (finalExp-num1Exp);
			r_shifted_out = r_shifted_out&mask;
  	 	end else if (num2Exp < num1Exp) begin
   			finalExp = num1Exp;
			r_shifted_out = num2Mant;
   			num2Mant = num2Mant >> (finalExp - num2Exp);
   			largerMag = 1'b0;
			mask = mask << (finalExp-num1Exp);
			r_shifted_out = r_shifted_out&mask;
   		end else begin
   			finalExp = num1Exp;
   			if (num2Mant > num1Mant) begin
   				largerMag = 1'b1;
   			end else begin // tie breaker
   				largerMag = 1'b0;
   			end
			r_shifted_out = 24'b0;
  	 	end
  	 	
  	 	// Don't ask me how the sign logic works (I fixed it but it is extremely jank).
   	
  	 	if ((num1[31] == 1'b1) && (num2[31] == 1'b1)) begin 
   			sumMants = num2Mant + num1Mant;
   			finalSign = 1'b0;
   		
   			finalMant = sumMants[24:1];
   	   		finalExp = subnormal ? finalExp : finalExp+1;
  	 	end else if ((num1[31] == 1'b1) && (num2[31] == 1'b0)) begin
  	 		sumMants = num1Mant - num2Mant;
  	 		finalSign = largerMag ? 1'b1 : 1'b0;
  	 		
  	 		finalMant = sumMants[23:0];
  	 		finalMant = sumMants[24] ? finalMant * -1 : finalMant;
  	 	end else if ((num1[31] == 1'b0) && (num2[31] == 1'b1)) begin
  	 		sumMants = num2Mant - num1Mant;
  	 		finalSign = largerMag ? 1'b0 : 1'b1;
   		
  	 		finalMant = sumMants[23:0];
  	 		finalMant = sumMants[24] ? finalMant * -1 : finalMant;
  	 	end else begin
  	 		sumMants = num2Mant + num1Mant;
  	 		finalSign = 1'b1;
  	 		
  	 		finalMant = sumMants[24:1];
  	 		finalExp = subnormal ? finalExp : finalExp+1;
  	 	end
   	
  	 	//sumMants = addMant + mulMant; //have to change sign instead of two's complementing
  	 	
//	   	$display("%b", sumMants);


		if (!subnormal) begin

			if (finalMant[23]) begin
				finalMant = finalMant << 1;
				
			end else if (finalMant[22]) begin
				finalMant = finalMant << 2;
				finalExp = finalExp - 1;
			
			end else if (finalMant[21]) begin
				finalMant = finalMant << 3;
				finalExp = finalExp - 2;
			end else if (finalMant[20]) begin
				finalMant = finalMant << 4;
				finalExp = finalExp - 3;
			
			end else if (finalMant[19]) begin
				finalMant = finalMant << 5;
				finalExp = finalExp - 4;
			
			end else if (finalMant[18]) begin
				finalMant = finalMant << 6;
				finalExp = finalExp - 5;
			
			end else if (finalMant[17]) begin
				finalMant = finalMant << 7;
				finalExp = finalExp - 6;
			
			end else if (finalMant[16]) begin
				finalMant = finalMant << 8;
				finalExp = finalExp - 7;
			
			end else if (finalMant[15]) begin
				finalMant = finalMant << 9;
				finalExp = finalExp - 8;
			
			end else if (finalMant[14]) begin
				finalMant = finalMant << 10;
				finalExp = finalExp - 9;
			
			end else if (finalMant[13]) begin
				finalMant = finalMant << 11;
				finalExp = finalExp - 10;
			
			end else if (finalMant[12]) begin
				finalMant = finalMant << 12;
				finalExp = finalExp - 11;
			
			end else if (finalMant[11]) begin
				finalMant = finalMant << 13;
				finalExp = finalExp - 12;
			
			end else if (finalMant[10]) begin
				finalMant = finalMant << 14;
				finalExp = finalExp - 13;
			
			end else if (finalMant[9]) begin
				finalMant = finalMant << 15;
				finalExp = finalExp - 14;
			
			end else if (finalMant[8]) begin
				finalMant = finalMant << 16;
				finalExp = finalExp - 15;
			
			end else if (finalMant[7]) begin
				finalMant = finalMant << 17;
				finalExp = finalExp - 16;
			
			end else if (finalMant[6]) begin
				finalMant = finalMant << 18;
				finalExp = finalExp - 17;
			
			end else if (finalMant[5]) begin
				finalMant = finalMant << 19;
				finalExp = finalExp - 18;
			
			end else if (finalMant[4]) begin
				finalMant = finalMant << 20;
				finalExp = finalExp - 19;
			
			end else if (finalMant[3]) begin
				finalMant = finalMant << 21;
				finalExp = finalExp - 20;
			
			end else if (finalMant[2]) begin
				finalMant = finalMant << 22;
				finalExp = finalExp - 21;
			
			end else if (finalMant[1]) begin
				finalMant = finalMant << 23;
				finalExp = finalExp - 22;
			end
			else begin
				finalExp = finalExp - 1;
				finalMant = finalMant;
			end
		end else begin
			finalExp = finalExp;
			finalMant = finalMant;
		end

		/*if (num1Exp == 8'h00 && num2Exp == 8'h00) begin
			finalExp = 8'h00;
		end*/
   	
  	 	/*for (i = 0; i < 23; i++) begin //do this routine a max of 23 times in case the answer is zero
			if (finalMant[23] == 1'b1) begin // if we have encountered a one we are done bc we can make the final silent bit
				i = 23; 
			end
			else begin // if we haven't encountered a one then we have to continue left shifting to find a one for the silent bit.
				finalMant = finalMant << 1;
				finalExp = finalExp - 1;
//				$display("shifted left");
			end
  	   	end
  	   	finalMant = finalMant << 1;
  	   	//finalExp = finalExp - 1;*/
  	      //"rounding" denormalized values like 1e-34 (which is returned for some 0+n computations, down to zero
  	      if(num1 == 0 && num2Exp == 0) begin // Remove this code it should be redundant now/
  	         finalMant = 24'b0;
  	         finalExp = 8'b0;
  	      end	
  	      $display("%b", {~finalSign, finalExp, subnormal ? finalMant[22:0]<<1 : finalMant[23:1]});
	end
	logic [31:0] unrounded;
	assign unrounded = {~finalSign, finalExp, subnormal ? finalMant[22:0]<<1 : finalMant[23:1]};
	assign out_num = unrounded;
	//round r0(unrounded, rm, out_num);
	
endmodule
