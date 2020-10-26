#pragma once

#include <vector>

#include "configurable.hpp"
#include "encryptor.hpp"
#include "mapper.hpp"
#include "reverse.hpp"

template <MapperType MT>
class Rotor final : public Encryptor, public Configurable {
public:
	Rotor();

	uint8_t map(uint8_t byte) final;
	void connect(int from, int to) final;

	bool turn_next();

private:
	size_t times_rotated_;
	bool rev_map_;
	std::vector<int> wire_to_;
	std::vector<int> wire_from_;

	int rotate(int idx, int rot);
};

template <MapperType MT>
Rotor<MT>::Rotor()
	: times_rotated_(0)
	, rev_map_(false)
	, wire_to_(Mapper<MT>::ALPHABET_SIZE)
	, wire_from_(Mapper<MT>::ALPHABET_SIZE)
	{ }

template <MapperType MT>
uint8_t Rotor<MT>::map(uint8_t byte) {
	const auto pos = static_cast<size_t>(rotate(Mapper<MT>::to_int(byte), times_rotated_));
	const auto match = rev_map_ ? wire_from_[pos] : wire_to_[pos];
	rev_map_ = !rev_map_;
	return Mapper<MT>::from_int(rotate(match, -times_rotated_));
}

template <MapperType MT>
void Rotor<MT>::connect(int from, int to) {
	wire_to_[to] = from;
	wire_from_[from] = to;
}

template <MapperType MT>
bool Rotor<MT>::turn_next() {
	return !(times_rotated_ = (times_rotated_ + 1) % Mapper<MT>::ALPHABET_SIZE);
}

template <MapperType MT>
int Rotor<MT>::rotate(int idx, int rot) {
	return (idx + rot + Mapper<MT>::ALPHABET_SIZE) % Mapper<MT>::ALPHABET_SIZE;
}
