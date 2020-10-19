#pragma once

#include <vector>

#include "common/configurable.hpp"
#include "common/encryptor.hpp"
#include "common/reverse.hpp"

class Rotor : public Encryptor, public Configurable {
public:
	explicit Rotor(size_t alphabet_size);
	~Rotor() override = 0;

	void connect(int from, int to) override;
	bool turn_next();

protected:
	const size_t alphabet_size_;
	size_t times_rotated_;
	bool rev_map_;
	std::vector<int> wire_to_;
	std::vector<int> wire_from_;
};
