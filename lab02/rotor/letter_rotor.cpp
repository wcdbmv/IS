#include "letter_rotor.hpp"

#include "common/letters.hpp"

LetterRotor::LetterRotor()
	: Rotor(ALPHABET_SIZE)
	{ }

uint8_t LetterRotor::map(uint8_t letter) {
	const auto pos = static_cast<size_t>(rotate_letter(upper_to_int(letter), times_rotated_));
	const auto match = rev_map_ ? wire_from_[pos] : wire_to_[pos];
	rev_map_ = !rev_map_;
	return int_to_upper(rotate_letter(match, -times_rotated_));
}
