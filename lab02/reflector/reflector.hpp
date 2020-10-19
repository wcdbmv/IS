#pragma once

#include "common/encryptor.hpp"

class Reflector : public Encryptor {
public:
	explicit Reflector(int reflector_offset);
	virtual ~Reflector() = 0;

protected:
	const int reflector_offset_;
};
