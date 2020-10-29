#pragma once

#include <cstdint>

class Encryptor {
public:
	virtual uint8_t map(uint8_t byte) = 0;
	virtual ~Encryptor() = default;
};
