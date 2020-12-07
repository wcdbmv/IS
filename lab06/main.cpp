#include <iostream>
#include "huffman_io.hpp"

int main(int argc, char** argv) {
	const auto usage = [=]() {
		std::cerr << "Usage: " << argv[0] << " <mode: e|c> <input> <output>\n";
		return EXIT_FAILURE;
	};

	if (argc != 4) {
		return usage();
	}

	const std::string mode(argv[1]);
	if (mode == "e") {
		encode(argv[2], argv[3]);
	} else if (mode == "d") {
		decode(argv[2], argv[3]);
	} else {
		return usage();
	}
}
