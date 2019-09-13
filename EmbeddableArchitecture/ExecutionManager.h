#pragma once
#include "common.h"

#include <iostream>
#include <string>
#include <functional>

#include "InstructionDispatcher.h"

namespace emarch {
	class ExecutionManager {
	public:
		ExecutionManager();

		//Execute a program directly without copying it to memory
		void executeProgram(std::vector<uint8_t>& code);

		//Set the instruction pointer to point to a start address
		void setProgram(uint8_t* begin, uint8_t* end);
		void stepProgramFromIP();
		void executeProgramFromIP();

		//Registering functions

		void registerOpcode(uint16_t opcode, std::function<void(PipelineState&)> handler);
		void registerFunction(std::string name, std::function<void(Registers&)> function);

	private:
		PipelineState state;

		InstructionDispatcher* dynDispatcher;
		MemoryManager* memMgr;
	};
}