#pragma once
#include "common.h"

#include <map>
#include <functional>

namespace emarch {
	class InstructionDispatcher {
	public:
		InstructionDispatcher(PipelineState& state) : state(state) {}

		//Execute the current instruction in the program
		void nextInstruction();

		//Register a new function to call when an opcode appears
		void registerHandler(uint16_t opcode, std::function<void(PipelineState&)> handler);

	private:
		//Run the handler of the next opcode in the program
		void dispatchCurrent();

		std::map<uint16_t, std::function<void(PipelineState&)>> handlers;
		PipelineState& state;
	};
}