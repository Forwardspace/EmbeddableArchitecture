#include "ExecutionManager.h"

#include <vector>

namespace emarch {
	ExecutionManager::ExecutionManager() {
		dynDispatcher = new InstructionDispatcher(state);
		memMgr = new MemoryManager(state);
	}

	void ExecutionManager::executeProgram(std::vector<uint8_t>& code) {
		setProgram(code.data(), code.data() + code.size() * sizeof(uint8_t));

		executeProgramFromIP();
	}

	void ExecutionManager::setProgram(uint8_t* begin, uint8_t* end) {
		state.IP = state.progStart = begin;
		state.EOP = end;

		state.stream.updateBounds();
	}

	void ExecutionManager::stepProgramFromIP() {
		dynDispatcher->nextInstruction();
	}

	void ExecutionManager::executeProgramFromIP() {
		while (state.IP < state.EOP) {
			stepProgramFromIP();
		}
	}

}