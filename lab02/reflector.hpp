#pragma once

#include "encryptor.hpp"

class Reflector : public Encryptor {
public:
	uint8_t map(uint8_t c) override;

	static constexpr int REFLECTOR_OFFSET = 13;
};
