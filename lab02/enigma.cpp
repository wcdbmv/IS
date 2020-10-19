#include "enigma.hpp"

void Enigma::setup(int argc, char** argv) {
	iomodule_.setup(argc, argv);
	iomodule_.setup_plugboard(plugboard_);
	iomodule_.setup_rotorbox(rotorbox_);
}

void Enigma::operate() {
	for (uint8_t byte; IoModule::input(byte);) {
		if (!isupper(byte)) {
			throw std::invalid_argument("Char is not upper");
		}
		byte = plugboard_.map(byte);
		byte = rotorbox_.map(byte);
		byte = plugboard_.map(byte);
		IoModule::output(byte);
	}
}

