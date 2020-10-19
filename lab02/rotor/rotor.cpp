#include "rotor.hpp"

Rotor::Rotor(size_t alphabet_size)
	: alphabet_size_(alphabet_size)
	, times_rotated_(0)
	, rev_map_(false)
	, wire_to_(alphabet_size)
	, wire_from_(alphabet_size)
	{ }

Rotor::~Rotor() { }

bool Rotor::turn_next() {
	return !(times_rotated_ = (times_rotated_ + 1) % alphabet_size_);
}

void Rotor::connect(int from, int to) {
	wire_to_[to] = from;
	wire_from_[from] = to;
}
