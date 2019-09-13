#pragma once
#include <iostream>

namespace emarch {

	struct MemAccess {
		uint8_t operator=(uint8_t& var) { return var = *bytes[0]; }
		uint16_t operator=(uint16_t& var) { uint16_t res = (*bytes[0] << 8) + *bytes[1]; return var = res; }
		uint32_t operator=(uint32_t& var) {
			std::copy(&bytes[0]);
		}
		uint64_t operator=(uint64_t& var) {

		}
	};

	class MemoryManager {
	public:
		MemoryManager(PipelineState& state);

		//Get access to one or more memory locations at a specified address
		MemAccess at(uint64_t address, uint64_t size);

		void clear();
	};
}