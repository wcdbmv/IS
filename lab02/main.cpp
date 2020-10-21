#include "enigma/byte_enigma.hpp"
#include "enigma/letter_enigma.hpp"

int main(int argc, char** argv) {
	auto enigma = std::unique_ptr<Enigma>(new ByteEnigma);
	enigma->setup(argc, argv);
	enigma->operate();
}
