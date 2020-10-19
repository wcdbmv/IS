#pragma once

#include "io_module.hpp"

class Enigma {
public:
	void setup(int argc, char** argv);
	void operate();

private:
	Plugboard plugboard_;
	RotorBox rotorbox_;
	IoModule iomodule_;
};
