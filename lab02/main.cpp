#include "enigma/letter_enigma.hpp"

int main(int argc, char** argv) {
	auto enigma = std::unique_ptr<Enigma>(new LetterEnigma);
	enigma->setup(argc, argv);
	enigma->operate();
}
