#include "rotor.hpp"

class ByteRotor final : public Rotor {
public:
	ByteRotor();

	uint8_t map(uint8_t byte) final;
};
