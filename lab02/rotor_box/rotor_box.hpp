#pragma once

#include <list>

#include "reflector/reflector.hpp"
#include "rotor/rotor.hpp"

class RotorBox : public Encryptor {
public:
	explicit RotorBox(std::unique_ptr<Reflector>&& reflector);
	~RotorBox() override = 0;

	void add(std::unique_ptr<Rotor> rotor);
	uint8_t map(uint8_t byte) final;

protected:
	std::list<std::unique_ptr<Rotor>> rotors_;
	std::unique_ptr<Reflector> reflector_;
};
