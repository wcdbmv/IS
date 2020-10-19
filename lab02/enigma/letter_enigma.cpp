#include "letter_enigma.hpp"

#include "plugboard/letter_plugboard.hpp"
#include "rotor_box/letter_rotor_box.hpp"
#include "io_module/letter_io_module.hpp"

LetterEnigma::LetterEnigma()
	: Enigma(
		std::unique_ptr<Plugboard>(new LetterPlugboard),
		std::unique_ptr<RotorBox>(new LetterRotorBox),
		std::unique_ptr<IoModule>(new LetterIoModule))
	{ }
