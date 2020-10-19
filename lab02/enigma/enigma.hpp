#pragma once

#include "io_module/io_module.hpp"

class Enigma {
public:
	Enigma(
		std::unique_ptr<Plugboard>&& plugboard,
		std::unique_ptr<RotorBox>&& rotorbox,
		std::unique_ptr<IoModule>&& iomodule
	);
	virtual ~Enigma() = 0;

	void setup(int argc, char** argv);
	void operate();


protected:
	std::unique_ptr<Plugboard> plugboard_;
	std::unique_ptr<RotorBox> rotorbox_;
	std::unique_ptr<IoModule> iomodule_;
};
