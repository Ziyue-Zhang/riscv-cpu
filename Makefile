VerilatorCppFile = $(shell find ./verilator -name '*.cpp')

verilog1:
	sbt "runMain sim.elaborate"

verilog2:
	sbt "runMain sim.elaborateysyx_zzy"

verilator1: $(VerilatorCppFile) 
	verilator simTop.v \
	--trace \
	$(VerilatorCppFile) \
	--cc --exe -LDFLAGS "-ldl" \
	-CFLAGS "-g"
	make -C obj_dir -f VsimTop.mk

build:
	make verilator1