#include "byte_plugboard.hpp"

#include "common/bytes.hpp"

BytePlugboard::BytePlugboard()
	: Plugboard(BYTES_SIZE)
	{ }

uint8_t BytePlugboard::map(uint8_t byte) {
	return Plugboard::char_wire_[byte];
}
