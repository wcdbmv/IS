#include "letter_plugboard.hpp"

#include "common/letters.hpp"

LetterPlugboard::LetterPlugboard()
	: Plugboard(ALPHABET_SIZE)
	{ }

uint8_t LetterPlugboard::map(uint8_t letter) {
	return int_to_upper(Plugboard::char_wire_[upper_to_int(letter)]);
}
