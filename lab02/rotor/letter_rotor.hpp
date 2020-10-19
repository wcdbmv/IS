#include "rotor.hpp"

class LetterRotor final : public Rotor {
public:
	LetterRotor();

	uint8_t map(uint8_t letter) final;
};
