#include "common.h"

#include <string>

namespace emarch {
	//Registers are named from 'A' to 'O' where register 'A' is the 0th register
	//Return the register index from the name of the register
	inline int indexFromLetter(unsigned char name) {
		if (name < 'A' || name > 'O') {
			throw std::runtime_error(
				"Out of range register access; attempted access to register: '" + std::to_string(name) + "'!"
			);
		}

		return static_cast<int>(name - 'A');
	}

	uint64_t& Registers::at(unsigned char name) {
		return regs[indexFromLetter(name)];
	}

	void Registers::clear() {
		std::fill(&regs[0], &regs[regCount - 1], 0);
	}

	InstructionStream& InstructionStream::operator>>(uint8_t& out) {
		if (currentPos + sizeof(uint8_t) > progEnd) {
			out = 0;
		}

		out = *currentPos;
		currentPos += sizeof(uint8_t);

		return *this;
	}
}