#pragma once

#include "encryptor.hpp"

class Reflector : public Encryptor {
public:
	char map(char c) override;

	static constexpr int REFLECTOR_OFFSET = 13;
};
