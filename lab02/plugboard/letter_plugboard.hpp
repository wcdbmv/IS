#pragma once

#include "plugboard.hpp"

class LetterPlugboard final : public Plugboard {
public:
	LetterPlugboard();

	uint8_t map(uint8_t letter) final;
};
