VerilatorCppFile = $(shell find ./verilator -name '*.cpp')

verilog:
	sbt "runMain sim.elaborate"

verilator: $(VerilatorCppFile) 
	verilator simTop.v \
	--trace \
	$(VerilatorCppFile) \
	--cc --exe -LDFLAGS "-ldl" \
	-CFLAGS "-g"
	make -C obj_dir -f VsimTop.mk

build:
	make verilator