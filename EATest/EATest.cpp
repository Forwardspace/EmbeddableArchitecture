#include "../EmbeddableArchitecture/EmbeddableArchitecture.h"

void opcode69(emarch::PipelineState& state) {
	uint8_t arg1;
	uint16_t arg2;
	state.stream >> arg1 >> arg2;

	if (arg1 != 21 && arg2 != 420) {
		throw std::runtime_error("Operand values are not properly passed to the opcode handler!");
	}
}

int main() {
	auto emarchManager = new emarch::ExecutionManager;

	emarchManager->registerOpcode(69, opcode69);

	uint8_t instructions[] = {
		69, 21, 164, 1 /* 164 and 1, are, when reversed (remember, little endian) 420 */
	};

	emarchManager->executeProgram(instructions);
}