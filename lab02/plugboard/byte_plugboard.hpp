#pragma once

#include "plugboard.hpp"

class BytePlugboard final : public Plugboard {
public:
	BytePlugboard();

	uint8_t map(uint8_t byte) final;
};
