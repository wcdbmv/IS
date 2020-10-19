#pragma once

#include "io_module.hpp"

class LetterIoModule final : public IoModule {
	void setup_rotorbox(std::unique_ptr<RotorBox>& rotorbox) final;

	bool input(uint8_t& letter) final;
	void output(uint8_t letter) final;
	bool check(uint8_t letter) final;
};

