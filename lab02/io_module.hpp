#pragma once

#include <string>

#include "plugboard.hpp"
#include "rotor_box.hpp"

class IoModule {
public:
	void setup(int argc, char** argv);
	void setup_plugboard(Plugboard& plugboard);
	void setup_rotorbox(RotorBox& rotorbox);

	static bool input(char &ch);
	static void output(char ch);

private:
	std::list<std::string> rfiles_;
	std::string pfile_;
};
