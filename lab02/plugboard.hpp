#pragma once

#include <array>

#include "configurable.hpp"
#include "encryptor.hpp"
#include "utils.hpp"

class Plugboard : public Encryptor, public Configurable {
public:
	void reset();
	uint8_t map(uint8_t c) override;
	void connect(int from, int to) override;

private:
	std::array<int, ALPHABET_SIZE> char_wire_{};
};
