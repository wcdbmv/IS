#include "io_module.hpp"

#include <fstream>

void IoModule::setup(int argc, char** argv) {
	if (constexpr int MIN_ARGS = 2; argc < MIN_ARGS) {
		throw std::invalid_argument("Wrong usage");
	}

	const size_t first_rotor_arg = 1;
	const size_t last_rotor_arg = argc - 2;
	const size_t plugboard_arg = argc - 1;

	for (size_t i = first_rotor_arg; i <= last_rotor_arg; ++i) {
		rfiles_.emplace_back(argv[i]);
	}

	pfile_ = argv[plugboard_arg];
}

void IoModule::setup_plugboard(std::unique_ptr<Plugboard>& plugboard) {
	std::ifstream fin(pfile_.c_str());
	if (!fin) {
		throw std::invalid_argument("No such plugboard file");
	}

	plugboard->reset();
	for (;;) {
		int plugA, plugB;
		if (!(fin >> plugA >> plugB)) {
			break;
		}
		plugboard->connect(plugA, plugB);
	}
}
