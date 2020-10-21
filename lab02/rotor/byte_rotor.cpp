#include "byte_rotor.hpp"

#include "common/bytes.hpp"

ByteRotor::ByteRotor()
	: Rotor(BYTES_SIZE)
	{ }

uint8_t ByteRotor::map(uint8_t byte) {
	const auto pos = static_cast<size_t>(rotate_byte(byte, times_rotated_));
	const auto match = rev_map_ ? wire_from_[pos] : wire_to_[pos];
	rev_map_ = !rev_map_;
	return rotate_byte(match, -times_rotated_);
}
