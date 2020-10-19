#include "plugboard.hpp"

Plugboard::Plugboard(size_t alphabet_size)
	: alphabet_size_(alphabet_size)
	, char_wire_(alphabet_size)
	{ }

Plugboard::~Plugboard() { }

void Plugboard::reset() {
	for (size_t i = 0; i < alphabet_size_; ++i) {
		char_wire_[i] = i;
	}
}

void Plugboard::connect(int from, int to) {
	char_wire_[from] = to;
	char_wire_[to] = from;
}
