#pragma once

#include <list>

#include "reflector.hpp"
#include "rotor.hpp"

class RotorBox : public Encryptor {
public:
	RotorBox() = default;

	void add(Rotor&& rotor);
	uint8_t map(uint8_t c) override;

private:
	std::list<Rotor> rotors_;
	Reflector reflector_;
};
