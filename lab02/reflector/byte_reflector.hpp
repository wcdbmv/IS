#pragma once

#include "reflector.hpp"

class ByteReflector final : public Reflector {
public:
	ByteReflector();

	uint8_t map(uint8_t byte) final;
};
