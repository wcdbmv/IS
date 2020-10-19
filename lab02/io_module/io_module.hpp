#pragma once

#include <string>

#include "plugboard/plugboard.hpp"
#include "rotor_box/rotor_box.hpp"

class IoModule {
public:
	virtual ~IoModule() = default;

	void setup(int argc, char** argv);
	void setup_plugboard(std::unique_ptr<Plugboard>& plugboard);
	virtual void setup_rotorbox(std::unique_ptr<RotorBox>& rotorbox) = 0;

	virtual bool input(uint8_t& byte) = 0;
	virtual void output(uint8_t byte) = 0;
	virtual bool check(uint8_t byte) = 0;

protected:
	std::list<std::string> rfiles_;
	std::string pfile_;
};
