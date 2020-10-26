#pragma once

#include <vector>

#include "configurable.hpp"
#include "encryptor.hpp"
#include "mapper.hpp"

template <MapperType MT>
class Plugboard final : public Encryptor, public Configurable {
public:
	Plugboard();

	uint8_t map(uint8_t byte) final;
	void connect(int from, int to) final;

	void reset();

private:
	std::vector<int> char_wire_;
};

template <MapperType MT>
Plugboard<MT>::Plugboard() : char_wire_(Mapper<MT>::ALPHABET_SIZE) {
	reset();
}

template <MapperType MT>
uint8_t Plugboard<MT>::map(uint8_t byte) {
	return Mapper<MT>::from_int(Plugboard::char_wire_[Mapper<MT>::to_int(byte)]);
}

template <MapperType MT>
void Plugboard<MT>::connect(int from, int to) {
	char_wire_[from] = to;
	char_wire_[to] = from;
}

template <MapperType MT>
void Plugboard<MT>:: reset() {
	for (size_t i = 0; i < Mapper<MT>::ALPHABET_SIZE; ++i) {
		char_wire_[i] = i;
	}
}
