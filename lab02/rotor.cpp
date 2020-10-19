#include "rotor.hpp"

uint8_t Rotor::map(uint8_t c) {
	const auto pos = static_cast<size_t>(rotate(upper_to_int(c), times_rotated_));
	const auto match = rev_map_ ? wire_from_[pos] : wire_to_[pos];
	rev_map_ = !rev_map_;
	return int_to_upper(rotate(match, -times_rotated_));
}

bool Rotor::turn_next() {
	return !(times_rotated_ = (times_rotated_ + 1) % ALPHABET_SIZE);
}

void Rotor::connect(int from, int to) {
	wire_to_[to] = from;
	wire_from_[from] = to;
}
