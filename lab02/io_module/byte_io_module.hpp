#pragma once

#include "io_module.hpp"

#include <fstream>

class ByteIoModule final : public IoModule {
public:
	ByteIoModule();

	void setup_rotorbox(std::unique_ptr<RotorBox>& rotorbox) final;

	bool input(uint8_t& byte) final;
	void output(uint8_t byte) final;
	bool check(uint8_t byte) final;

private:
	std::ifstream ifs_;
	std::ofstream ofs_;
};

