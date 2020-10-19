#include "letter_rotor_box.hpp"

#include "reflector/letter_reflector.hpp"

LetterRotorBox::LetterRotorBox()
	: RotorBox(std::unique_ptr<Reflector>(new LetterReflector))
	{ }
