#pragma once

class Encryptor {
public:
	virtual char map(char c) = 0;
	virtual ~Encryptor() = default;
};
