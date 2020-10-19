#include "rotor_box.hpp"

#include <tuple>

RotorBox::RotorBox(std::unique_ptr<Reflector>&& reflector)
	: reflector_(std::move(reflector))
	{ }

RotorBox::~RotorBox() { }

void RotorBox::add(std::unique_ptr<Rotor> rotor) {
	rotors_.push_back(std::move(rotor));
}

uint8_t RotorBox::map(uint8_t byte) {
	for (auto& rotor : rotors_) {
		byte = rotor->map(byte);
	}
	byte = reflector_->map(byte);
	for (auto& rotor : reverse(rotors_)) {
		byte = rotor->map(byte);
	}

	for (auto [it, turn_next] = std::tuple{rotors_.begin(), true}; turn_next && it != rotors_.end(); ++it) {
		turn_next = (*it)->turn_next();
	}

	return byte;
}
