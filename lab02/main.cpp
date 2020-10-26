#include <iostream>

#include "enigma.hpp"

int usage(const char* argv0) {
	std::cerr << "Usage: " << argv0 << " <byte|letter> [rotor ...] <plugboard>\n";
	return EXIT_FAILURE;
}

int main(int argc, char** argv) {
	if (argc < 3) {
		return usage(argv[0]);
	}

	if (strcmp(argv[1], "byte") == 0) {
		Enigma<Byte> enigma;
		enigma.setup(argc, argv);
		enigma.operate();
	} else if (strcmp(argv[1], "letter") == 0) {
		Enigma<Letter> enigma;
		enigma.setup(argc, argv);
		enigma.operate();
	} else {
		return usage(argv[0]);
	}
}
