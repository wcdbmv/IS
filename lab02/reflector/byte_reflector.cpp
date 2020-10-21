#include "byte_reflector.hpp"

#include "common/bytes.hpp"

ByteReflector::ByteReflector()
	: Reflector(/* reflector_offset */ BYTES_SIZE / 2)
	{ }

uint8_t ByteReflector::map(uint8_t byte) {
	return (byte + reflector_offset_) % BYTES_SIZE;
}

