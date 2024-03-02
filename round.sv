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
		else if (rm == 3'b011) begin // round up (towards +inf)
		// Break this into two parts: round up for positive number magnitudes, round toward zero for negative number magnitudes.
			if (num1[31]) begin // round toward zero -> negative magnitudes
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
				rounded = 32'h40000000;
			end
			else if (i > 23) begin
				rounded = num1;
			end 
			else begin // exp < 0 so it will just round to zero.
				rounded = 32'b0;
			end
		end
		else begin // default rounding mode is RNE (Round to Nearest Even)
			if (!num1[2]) begin // round down (do nothing)
				rounded = num1;
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
	
endmodule
