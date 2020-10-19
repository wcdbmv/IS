#include "enigma.hpp"

Enigma::Enigma(
	std::unique_ptr<Plugboard>&& plugboard,
	std::unique_ptr<RotorBox>&& rotorbox,
	std::unique_ptr<IoModule>&& iomodule
)
	: plugboard_(std::move(plugboard))
	, rotorbox_(std::move(rotorbox))
	, iomodule_(std::move(iomodule))
	{ }

Enigma::~Enigma() { }

void Enigma::setup(int argc, char** argv) {
	iomodule_->setup(argc, argv);
	iomodule_->setup_plugboard(plugboard_);
	iomodule_->setup_rotorbox(rotorbox_);
}

void Enigma::operate() {
	for (uint8_t byte; iomodule_->input(byte);) {
		iomodule_->check(byte);
		byte = plugboard_->map(byte);
		byte = rotorbox_->map(byte);
		byte = plugboard_->map(byte);
		iomodule_->output(byte);
	}
}

