#include "byte_enigma.hpp"

#include "plugboard/byte_plugboard.hpp"
#include "rotor_box/byte_rotor_box.hpp"
#include "io_module/byte_io_module.hpp"

ByteEnigma::ByteEnigma()
	: Enigma(
		std::unique_ptr<Plugboard>(new BytePlugboard),
		std::unique_ptr<RotorBox>(new ByteRotorBox),
		std::unique_ptr<IoModule>(new ByteIoModule))
	{ }
