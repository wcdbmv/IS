#pragma once

#include <vector>

#include "common/configurable.hpp"
#include "common/encryptor.hpp"

class Plugboard : public Encryptor, public Configurable {
public:
	explicit Plugboard(size_t alphabet_size);
	~Plugboard() override = 0;

	virtual void reset();

	void connect(int from, int to) final;

protected:
	const size_t alphabet_size_;
	std::vector<int> char_wire_;
};
