#include "plugboard.hpp"

char Plugboard::map(char c) {
	return int_to_upper(char_wire_[upper_to_int(c)]);
}

void Plugboard::reset() {
	for (size_t i = 0; i < ALPHABET_SIZE; ++i) {
		char_wire_[i] = i;
	}
}

void Plugboard::connect(int from, int to) {
	char_wire_[from] = to;
	char_wire_[to] = from;
}
