#include "letter_io_module.hpp"

#include <fstream>
#include <iostream>

#include "common/letters.hpp"
#include "rotor/letter_rotor.hpp"

void LetterIoModule::setup_rotorbox(std::unique_ptr<RotorBox>& rotorbox) {
	for (const auto& rfile : rfiles_) {
		std::ifstream fin(rfile.c_str());
		if (!fin) {
			throw std::invalid_argument("No such rotor file");
		}

		auto rotor = std::unique_ptr<Rotor>(new LetterRotor);
		int pos;
		for (int i = 0; i < ALPHABET_SIZE; ++i) {
			fin >> pos;
			rotor->connect(pos, i);
		}
		rotorbox->add(std::move(rotor));
	}
}

bool LetterIoModule::input(uint8_t &letter) {
	return static_cast<bool>(std::cin >> std::skipws >> letter);
}

void LetterIoModule::output(uint8_t letter) {
	std::cout << letter;
}

bool LetterIoModule::check(uint8_t letter) {
	if (!isupper(letter)) {
		throw std::invalid_argument("Char is not upper");
	}
	return true;
}
