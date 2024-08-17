module fsqrt_new(
input [31:0] num1,
output [31:0] sqrt_num
);

logic [31:0] magic_number, half, one_half, half_num1, int1, int2, int3;
logic [2:0] rm;
assign rm = 3'b000;
assign magic_number = 32'h5f375a86;
assign half = 32'h3F000000;
assign one_half = 32'h3FC00000
fmul fmul0(half, num1, rm, half_num1);
assign int1 = magic_number-(num1>>1);
// Newton Step
fmul fmul1(int1, int1, rm, int2);
fmul fmul2(int2, half_num1, rm, int3);
fadd fadd0(one_half, {1'b1, int3[30:0]}, rm, sqrt_num)

// If you want better precision do more Newton Steps (Need 4 intermediates per step)
endmodule
