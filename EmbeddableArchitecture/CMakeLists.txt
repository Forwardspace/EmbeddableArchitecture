# CMakeList.txt : CMake project for EmbeddableArchitecture, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_library (EA
	"EmbeddableArchitecture.h"
	"common.h"
	"common.cpp"
	"ExecutionManager.h"
	"ExecutionManager.cpp"
	"InstructionDispatcher.h"
	"InstructionDispatcher.cpp"
	"MemoryManager.h"
	"MemoryManager.cpp"
)

# TODO: Add tests and install targets if needed.
