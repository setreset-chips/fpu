fsqrt:
	verilator -I../ -Wall -Wno-fatal --trace --cc --exe --build tb_fsqrt.cpp ../fsqrt.sv 
	./obj_dir/Vfsqrt
	
FMA:
	verilator -I../ -Wall -Wno-fatal --trace --cc --exe --build tb_fma.cpp ../FMA.sv 
	./obj_dir/VFMA
	
fln:
	verilator -I../ -Wall -Wno-fatal --trace --cc --exe --build tb_fln.cpp ../fln.sv 
	./obj_dir/Vfln
	
fadd:
	verilator -I../ -Wall -Wno-fatal --trace --cc --exe --build tb_fadd.cpp ../fadd.sv 
	./obj_dir/Vfadd

fmul:
	verilator -I../ -Wall -Wno-fatal --trace --cc --exe --build tb_fmul.cpp ../fmul.sv 
	./obj_dir/Vfmul
	
fexp:
	verilator -I../ -Wall -Wno-fatal --trace --cc --exe --build tb_fexp.cpp ../fexp.sv 
	./obj_dir/Vfexp
	
ftop:
	verilator -I../ -Wall -Wno-fatal --trace --cc --exe --build tb_fpu_top.cpp ../fpu_top.sv 
	./obj_dir/Vfpu_top
	
round:
	verilator -I../ -Wall -Wno-fatal --trace --cc --exe --build tb_round.cpp ../round.sv 
	./obj_dir/Vround
