#pragma once

#include <string>

#include "plugboard.hpp"
#include "rotor_box.hpp"

class IoModule {
public:
	void setup(int argc, char** argv);
	void setup_plugboard(Plugboard& plugboard);
	void setup_rotorbox(RotorBox& rotorbox);

	static bool input(uint8_t &ch);
	static void output(uint8_t ch);

private:
	std::list<std::string> rfiles_;
	std::string pfile_;
};
