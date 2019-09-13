#pragma once
#include <iostream>

namespace emarch {
	const int regCount = 15;
	struct Registers {
		uint64_t regs[regCount];

		//Get access to a named register
		uint64_t& at(unsigned char name);
		//Set all registers to zero
		void clear();
	};

	class InstructionStream;

	//Stores the state of the instruction pipeline. Allows the
	//opcode handlers to easily access opcodes, operands and registers
	struct PipelineState {
		uint8_t* progStart = nullptr;	 //Where does the program start?
		uint8_t* IP = nullptr;		 //The current instruction offset
		uint8_t* EOP = nullptr;		 //Where does the program end?

		uint64_t instrNumber = 0;	//Incremented each instruction

		Registers regs;

		InstructionStream stream;	//Gets the next instruction/operand
	};

	//Does not inherit from std::istream; this is meant just to
	//serve as a helper object to get instructions and operands
	class InstructionStream {
	public:
		InstructionStream(PipelineState& state) : state(state) { progStart = state.progStart; progEnd = state.EOP; }

		inline void updateBounds() { progStart = currentPos = state.progStart; progEnd = state.EOP; }

		InstructionStream& operator>>(uint8_t& out);
		InstructionStream& operator>>(uint16_t& out);
		InstructionStream& operator>>(uint32_t& out);
		InstructionStream& operator>>(uint64_t& out);

	private:
		uint8_t *progStart = nullptr, *currentPos = nullptr, *progEnd = nullptr;
		PipelineState& state;
	};
}