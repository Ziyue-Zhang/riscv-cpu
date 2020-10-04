VerilatorCppFile = $(shell find ./verilator -name '*.cpp')

verilog:
	sbt "runMain sim.elaborate"