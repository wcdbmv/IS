#pragma once

#include "reflector.hpp"

class LetterReflector final : public Reflector {
public:
	LetterReflector();

	uint8_t map(uint8_t letter) final;
};
