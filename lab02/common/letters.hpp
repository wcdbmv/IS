#pragma once

#include <cstdlib>

static constexpr int ALPHABET_SIZE = 26;

static constexpr int upper_to_int(uint8_t upper) {
	return upper - 'A';
}

static constexpr uint8_t int_to_upper(int n) {
	return static_cast<uint8_t>((n + ALPHABET_SIZE) % ALPHABET_SIZE + 'A');
}

static constexpr int rotate_letter(int n, int rot) {
	return (n + rot + ALPHABET_SIZE) % ALPHABET_SIZE;
}
