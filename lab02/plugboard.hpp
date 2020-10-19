#pragma once

#include <array>

#include "configurable.hpp"
#include "encryptor.hpp"
#include "utils.hpp"

class Plugboard : public Encryptor, public Configurable {
public:
	void reset();
	char map(char c) override;
	void connect(int from, int to) override;

private:
	std::array<int, ALPHABET_SIZE> char_wire_{};
};
