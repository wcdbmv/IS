#include "rotor_box.hpp"

#include <tuple>

void RotorBox::add(Rotor&& rotor) {
	rotors_.push_back(std::move(rotor));
}

char RotorBox::map(char c) {
	for (auto& rotor : rotors_) {
		c = rotor.map(c);
	}
	c = reflector_.map(c);
	for (auto& rotor : reverse(rotors_)) {
		c = rotor.map(c);
	}

	for (auto [it, turn_next] = std::tuple{rotors_.begin(), true}; turn_next && it != rotors_.end(); ++it) {
		turn_next = it->turn_next();
	}

	return c;
}
