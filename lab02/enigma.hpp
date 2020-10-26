#pragma once

#include "io_module.hpp"

template <MapperType MT>
class Enigma {
public:
	void setup(int argc, char** argv) {
		iomodule_.setup(argc, argv);
		iomodule_.setup_plugboard(plugboard_);
		iomodule_.setup_rotorbox(rotorbox_);
	}

	void operate() {
		for (uint8_t byte; iomodule_.input(byte);) {
			if (iomodule_.check(byte)) {
				byte = plugboard_.map(byte);
				byte = rotorbox_.map(byte);
				byte = plugboard_.map(byte);
			}
			iomodule_.output(byte);
		}
	}

private:
	Plugboard<MT> plugboard_;
	RotorBox<MT> rotorbox_;
	IoModule<MT> iomodule_;
};
