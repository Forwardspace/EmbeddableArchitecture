#include "InstructionDispatcher.h"

namespace emarch {
	void InstructionDispatcher::nextInstruction() {
		dispatchCurrent();
	}
	
	void InstructionDispatcher::registerHandler(uint16_t opcode, std::function<void(PipelineState&)> handler) {
		handlers[opcode] = handler;
	}

	void InstructionDispatcher::dispatchCurrent() {
		//Get the current opcode
		uint8_t opcode;
		uint16_t extendedOpcode;

		state.stream >> opcode;

		if (opcode == 0xFF) {
			//After this opcode is the actual 16 bit opcode, get it
			state.stream >> extendedOpcode;

			if (handlers[extendedOpcode] == nullptr) {
				throw std::runtime_error("Unknown opcode: " + extendedOpcode);
			}

			handlers[extendedOpcode]();
		}
		else {
			//It's just a regular 8 bit opcode
			if (handlers[opcode] == nullptr) {
				throw std::runtime_error("Unknown opcode: " + opcode);
			}

			handlers[opcode]();
		}
	}
}