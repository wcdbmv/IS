#pragma once

#include <array>

#include "configurable.hpp"
#include "encryptor.hpp"
#include "utils.hpp"

class Rotor : public Encryptor, public Configurable {
public:
	char map(char c) override;
	void connect(int from, int to) override;
	bool turn_next();

private:
	int times_rotated_{};
	bool rev_map_{};
	std::array<int, ALPHABET_SIZE> wire_to_{};
	std::array<int, ALPHABET_SIZE> wire_from_{};
};
