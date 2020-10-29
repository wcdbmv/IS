#pragma once

#include "reflector.hpp"
#include "rotor.hpp"

template <MapperType MT>
class RotorBox final : public Encryptor {
public:
	uint8_t map(uint8_t byte) final;

	void add(Rotor<MT>&& rotor);

private:
	std::vector<Rotor<MT>> rotors_;
	Reflector<MT> reflector_;
};

template <MapperType MT>
uint8_t RotorBox<MT>::map(uint8_t byte) {
	for (auto& rotor : rotors_) {
		byte = rotor.map(byte);
	}
	byte = reflector_.map(byte);
	for (auto& rotor : reverse(rotors_)) {
		byte = rotor.map(byte);
	}

	for (auto [it, turn_next] = std::tuple{rotors_.begin(), true}; turn_next && it != rotors_.end(); ++it) {
		turn_next = it->turn_next();
	}

	return byte;
}

template <MapperType MT>
void RotorBox<MT>::add(Rotor<MT>&& rotor) {
	rotors_.push_back(rotor);
}
