module fadd_total (
	input logic [31:0] num1,
	input logic [31:0] num2,
	input logic [2:0] rm,
	output logic [31:0] out_num
);
	logic largerMag, finalSign, leadMantBit1, leadMantBit2, subnormal;
	logic [7:0] num1Exp, num2Exp, finalExp;
	logic [23:0] num1Mant, num2Mant, finalMant;
	logic [24:0] sumMants;
	int i;
	
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
      
   		if(num1Exp < num2Exp) begin
   			finalExp = num2Exp;
  	 		num1Mant = num1Mant >> (finalExp - num1Exp);
  	 		largerMag = 1'b1;
  	 	end else if (num2Exp < num1Exp) begin
   			finalExp = num1Exp;
   			num2Mant = num2Mant >> (finalExp - num2Exp);
   			largerMag = 1'b0;
   		end else begin
   			finalExp = num1Exp;
   			if (num2Mant > num1Mant) begin
   				largerMag = 1'b1;
   			end else begin
   				largerMag = 1'b0;
   			end
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
		end
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
	//assign out_num = unrounded;
	round r0(unrounded, rm, out_num);
	
endmodule;

module round(
	input logic [31:0] num1,
	input logic [2:0] rm,
	output logic [31:0] rounded_num
);
	logic [31:0] rounded;
	logic [23:0] overflowCheck;
	logic [22:0] mask, mask2;
	int i, j;
	
	// I have to justify floating point rounding to myself for sanity reasons:
	// Floating point rounding is useful because large numbers cannot simply be converted to 32-bit unsigned integers.
	// Very interesting and as I am designing this I'm still confused as to why every single instruction needs rounding.
	// I (kind of) understand. Floating point rounding is a way to process a number and give an approximation for the by-hand arithmetic.
	
	always_comb begin
		if(rm == 3'b000) begin // round to nearest, ties to even
			if (!num1[2]) begin // round down (do nothing)
				rounded = num1;
			end
			else begin
				if (num1[1:0] == 2'b00) begin // tie -> check bit before guard
                    i = 0;
					if (num1[3]) begin // round up -> add one to mantissa and check for overflow
						overflowCheck = {1'b0, num1[22:0]};
						overflowCheck = overflowCheck+1;
						if (overflowCheck[23]) begin 
							rounded = {num1[31], num1[30:23]+1'b1, overflowCheck[22:0]};
						end
						else begin
							rounded = {num1[31:23], overflowCheck[22:0]};
						end
					end else begin // round down (do nothing)
						rounded = num1;
					end
				end
				else begin // round up -> add one to mantissa and check for overflow
					overflowCheck = {1'b0, num1[22:0]};
					overflowCheck = overflowCheck+1;
					if (overflowCheck[23]) begin
						rounded = {num1[31], num1[30:23]+1'b1, overflowCheck[22:0]};
					end
					else begin
						rounded = {num1[31:23], overflowCheck[22:0]};
					end
				end
			end
		end 
		else if (rm == 3'b001) begin // round towards zero (truncate)
			i = 32'(signed'(num1[30:23] - 8'h7F));
			if(i > 0 && i < 23) begin // exp >= 0 so will round to at least one.
				mask = 23'b11111111111111111111111;
				mask = mask >> i; 
				mask = ~mask;// creating a mask that allows me to zero out the bits that are getting truncated.
				rounded = {num1[31:23], (num1[22:0]&mask)};
			end 
			else if (i == 0) begin
				rounded = 32'h3F800000;
			end
			else if (i > 23) begin
				rounded = num1;
			end 
			else begin // exp < 0 so it will just round to zero.
				rounded = 32'b0;
			end
		end
		else if (rm == 3'b010) begin // round down (towards -inf)
		// Break this into two parts: round up for negative number magnitudes, round toward zero for positive number magnitudes.
		// In order to round up we need to do the same thing as last time but this time add 1 to the lsb of the truncated mantissa.
			if (!num1[31]) begin // round toward zero -> positive magnitudes
				i = 32'(signed'(num1[30:23] - 8'h7F));
				if(i > 0 && i < 23) begin // exp >= 0 so will round to at least one.
					mask = 23'b11111111111111111111111;
					mask = mask >> i; 
					mask = ~mask;// creating a mask that allows me to zero out the bits that are getting truncated.
					rounded = {num1[31:23], (num1[22:0]&mask)};
				end 
				else if (i == 0) begin
					rounded = 32'h3F800000;
				end
				else if (i > 23) begin
					rounded = num1;
				end 
				else begin // exp < 0 so it will just round to zero.
					rounded = 32'b0;
				end
			end 
			else begin // round up -> negative magnitudes
				i = 32'(signed'(num1[30:23] - 8'h7F));
				if(i > 0 && i < 23) begin // exp >= 0 so will round to at least one.
					mask = 23'b11111111111111111111111;
					mask2 = 23'b10000000000000000000000;
					mask = mask >> i; 
					mask2 = mask2 >> (i-1); // creating another mask that allows me to add one to the truncated bits.
					mask = ~mask;// creating a mask that allows me to zero out the bits that are getting truncated.
					mask = num1[22:0] & mask;
					overflowCheck = {1'b0, mask};
					overflowCheck = overflowCheck + mask2;
					if (overflowCheck[23]) begin
						rounded = {num1[31], (num1[30:23]+1'b1), num1[22:0]};
					end
					else begin
						rounded = {num1[31:23], overflowCheck[22:0]};
					end
				end 
				else if (i == 0) begin
					rounded = 32'h40000000;
				end
				else if (i > 23) begin
					rounded = num1;
				end 
				else begin // exp < 0 so it will just round to zero.
					rounded = 32'b0;
				end
			end
		end
        //
        //
        // HERE ON UP ^^^ NEED TO DO LATCH PREVENTION !!!
        //
        //
		else if (rm == 3'b011) begin // round up (towards +inf)
		// Break this into two parts: round up for positive number magnitudes, round toward zero for negative number magnitudes.
			if (num1[31]) begin // round toward zero -> negative magnitudes
				i = 32'(signed'(num1[30:23] - 8'h7F));
				if(i > 0 && i < 23) begin // exp >= 0 so will round to at least one.
                    mask2 = 0;
					mask = 23'b11111111111111111111111;
					mask = mask >> i; 
					mask = ~mask;// creating a mask that allows me to zero out the bits that are getting truncated.
                    overflowCheck = 0;
					rounded = {num1[31:23], (num1[22:0]&mask)};
				end 
				else if (i == 0) begin
                    mask = 0;
                    mask2 = 0;
                    overflowCheck = 0;
					rounded = 32'h3F800000;
				end
				else if (i > 23) begin
                    mask = 0;
                    mask2 = 0;
                    overflowCheck = 0;
					rounded = num1;
				end 
				else begin // exp < 0 so it will just round to zero.
                    mask = 0;
                    mask2 = 0;
                    overflowCheck = 0;
					rounded = 32'b0;
				end
			end 
			else begin // round up -> positive magnitudes
				i = 32'(signed'(num1[30:23] - 8'h7F));
				if(i > 0 && i < 23) begin // exp >= 0 so will round to at least one.
					mask = 23'b11111111111111111111111;
					mask2 = 23'b10000000000000000000000;
					mask = mask >> i; 
					mask2 = mask2 >> (i-1); // creating another mask that allows me to add one to the truncated bits.
					mask = ~mask;// creating a mask that allows me to zero out the bits that are getting truncated.
					mask = num1[22:0] & mask;
					overflowCheck = {1'b0, mask};
					overflowCheck = overflowCheck + mask2;
					if (overflowCheck[23]) begin
						rounded = {num1[31], (num1[30:23]+1'b1), num1[22:0]};
					end
					else begin
						rounded = {num1[31:23], overflowCheck[22:0]};
					end
				end 
				else if (i == 0) begin
                    mask = 0;
                    mask2 = 0;
                    overflowCheck = 0;
					rounded = 32'h40000000;
				end
				else if (i > 23) begin
					rounded = num1;
                    mask = 0;
                    mask2 = 0;
                    overflowCheck = 0;
				end 
				else begin // exp < 0 so it will just round to zero.
					rounded = 32'b0;
                    mask = 0;
                    mask2 = 0;
                    overflowCheck = 0;
				end
			end
			
		end
		else if (rm == 3'b100) begin // round to nearest, ties to Max Magnitude
			i = 32'(signed'(num1[30:23] - 8'h7F));
			if(i > 0 && i < 23) begin // exp >= 0 so will round to at least one.
				mask = 23'b11111111111111111111111;
				mask2 = 23'b10000000000000000000000;
				mask = mask >> i; 
				mask2 = mask2 >> (i-1); // creating another mask that allows me to add one to the truncated bits.
				mask = ~mask;// creating a mask that allows me to zero out the bits that are getting truncated.
				mask = num1[22:0] & mask;
				overflowCheck = {1'b0, mask};
				overflowCheck = overflowCheck + mask2;
				if (overflowCheck[23]) begin
					rounded = {num1[31], (num1[30:23]+1'b1), num1[22:0]};
				end
				else begin
					rounded = {num1[31:23], overflowCheck[22:0]};
				end
			end 
			else if (i == 0) begin
                mask = 0;
                mask2 = 0;
                overflowCheck = 0;
				rounded = 32'h40000000;
			end
			else if (i > 23) begin
                mask = 0;
                mask2 = 0;
                overflowCheck = 0;
				rounded = num1;
			end 
			else begin // exp < 0 so it will just round to zero.
                mask = 0;
                mask2 = 0;
                overflowCheck = 0;
				rounded = 32'b0;
			end
		end
		else begin // default rounding mode is RNE (Round to Nearest Even)
            i = 0;
            mask = 23'b0;
            mas2 = 23'b0;
            
			if (!num1[2]) begin // round down (do nothing)
				rounded = num1;
                overflowCheck = 0;
			end
			else begin
				if (num1[1:0] == 2'b00) begin // tie -> check bit before guard
					if (num1[3]) begin // round up -> add one to mantissa and check for overflow
						overflowCheck = {1'b0, num1[22:0]};
						overflowCheck = overflowCheck+1;
						if (overflowCheck[23]) begin 
							rounded = {num1[31], num1[30:23]+1'b1, overflowCheck[22:0]};
						end
						else begin
							rounded = {num1[31:23], overflowCheck[22:0]};
						end
					end else begin // round down (do nothing)
                        overflowCheck = 0;
						rounded = num1;
					end
				end
				else begin // round up -> add one to mantissa and check for overflow
					overflowCheck = {1'b0, num1[22:0]};
					overflowCheck = overflowCheck+1;
					if (overflowCheck[23]) begin
						rounded = {num1[31], num1[30:23]+1'b1, overflowCheck[22:0]};
					end
					else begin
						rounded = {num1[31:23], overflowCheck[22:0]};
					end
				end
			end
		end
	end
	
	assign rounded_num = rounded;
	
endmodule;
