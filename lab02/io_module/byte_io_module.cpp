#include "byte_io_module.hpp"

#include <fstream>
#include <iostream>

#include "common/bytes.hpp"
#include "rotor/byte_rotor.hpp"

ByteIoModule::ByteIoModule()
	: ifs_("../in.dat", std::ios::binary)
	, ofs_("../out.dat", std::ios::binary)
{
	if (!ifs_) {
		throw std::invalid_argument("no in.dat");
	}

	if (!ofs_) {
		throw std::invalid_argument("no on.dat");
	}
}

void ByteIoModule::setup_rotorbox(std::unique_ptr<RotorBox>& rotorbox) {
	for (const auto& rfile : rfiles_) {
		std::ifstream fin(rfile.c_str());
		if (!fin) {
			throw std::invalid_argument("No such rotor file");
		}

		auto rotor = std::unique_ptr<Rotor>(new ByteRotor);
		int pos;
		for (int i = 0; i < BYTES_SIZE; ++i) {
			fin >> pos;
			rotor->connect(pos, i);
		}
		rotorbox->add(std::move(rotor));
	}
}

bool ByteIoModule::input(uint8_t& byte) {
	return static_cast<bool>(ifs_.read(reinterpret_cast<char*>(&byte), 1));
}

void ByteIoModule::output(uint8_t byte) {
	ofs_.write(reinterpret_cast<char*>(&byte), 1);
}

bool ByteIoModule::check(uint8_t /* byte */) {
	return true;
}
