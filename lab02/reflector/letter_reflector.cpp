#include "letter_reflector.hpp"

#include "common/letters.hpp"

LetterReflector::LetterReflector()
	: Reflector(/* reflector_offset */ ALPHABET_SIZE / 2)
	{ }

uint8_t LetterReflector::map(uint8_t letter) {
	return int_to_upper(upper_to_int(letter) + reflector_offset_);
}

