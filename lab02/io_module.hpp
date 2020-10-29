#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "plugboard.hpp"
#include "rotor_box.hpp"

template <MapperType MT>
class IoModule {
public:
	void setup(int argc, char** argv);
	void setup_plugboard(Plugboard<MT>& plugboard);
	void setup_rotorbox(RotorBox<MT>& rotorbox);

	bool input(uint8_t& byte);
	void output(uint8_t byte);
	bool check(uint8_t& byte);

private:
	std::vector<std::string> rfiles_{};
	std::string pfile_{};
};

template <MapperType MT>
void IoModule<MT>::setup(int argc, char** argv) {
	if (constexpr int MIN_ARGS = 3; argc < MIN_ARGS) {
		throw std::invalid_argument("Usage: " + std::string(argv[0]) + " <byte|letter> [rotor ...] <plugboard>\n");
	}

	const size_t first_rotor_arg = 2;
	const size_t last_rotor_arg = argc - 2;
	const size_t plugboard_arg = argc - 1;

	for (size_t i = first_rotor_arg; i <= last_rotor_arg; ++i) {
		rfiles_.emplace_back(argv[i]);
	}

	pfile_ = argv[plugboard_arg];
}

template <MapperType MT>
void IoModule<MT>::setup_plugboard(Plugboard<MT>& plugboard) {
	std::ifstream ifs(pfile_.c_str());
	if (!ifs) {
		throw std::invalid_argument("No such plugboard file");
	}

	plugboard.reset();
	for (;;) {
		int plug_a, plug_b;
		if (!(ifs >> plug_a >> plug_b)) {
			break;
		}
		plugboard.connect(plug_a, plug_b);
	}
}

template <MapperType MT>
void IoModule<MT>::setup_rotorbox(RotorBox<MT>& rotorbox) {
	for (const auto& rfile : rfiles_) {
		std::ifstream ifs(rfile.c_str());
		if (!ifs) {
			throw std::invalid_argument("No such rotor file: \"" + rfile + "\"");
		}

		Rotor<MT> rotor;
		for (int to = 0; to < Mapper<MT>::ALPHABET_SIZE; ++to) {
			int from;
			ifs >> from;
			rotor.connect(from, to);
		}
		rotorbox.add(std::move(rotor));
	}
}

template <MapperType MT>
bool IoModule<MT>::input(uint8_t& byte) {
	return static_cast<bool>(std::cin.read(reinterpret_cast<char*>(&byte), 1));
}

template <MapperType MT>
void IoModule<MT>::output(uint8_t byte) {
	std::cout.write(reinterpret_cast<char*>(&byte), 1);
}

template <MapperType MT>
bool IoModule<MT>::check(uint8_t& byte) {
	if constexpr (MT == Letter) {
		byte = toupper(byte);
		if (!isupper(byte)) {
			return false;
		}
	}
	return true;
}
