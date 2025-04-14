cmake: CMakeLists.txt CMath/CMakeLists.txt
	@cmake . -B CMake -DCMAKE_EXPORT_COMPILE_COMMANDS=1
	@rm -f compile_commands.json
	@ln -s CMake/compile_commands.json compile_commands.json

tests: cmake
	@${MAKE} --no-print-directory -C CMake -f Makefile

run:
	@./Tests/Copper-Math-Test
