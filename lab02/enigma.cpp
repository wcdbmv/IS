#include "enigma.hpp"

void Enigma::setup(int argc, char** argv) {
	iomodule_.setup(argc, argv);
	iomodule_.setup_plugboard(plugboard_);
	iomodule_.setup_rotorbox(rotorbox_);
}

void Enigma::operate() {
	for (char ch; IoModule::input(ch);) {
		if (!isupper(ch)) {
			throw std::invalid_argument("Char is not upper");
		}
		ch = plugboard_.map(ch);
		ch = rotorbox_.map(ch);
		ch = plugboard_.map(ch);
		IoModule::output(ch);
	}
}

