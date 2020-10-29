#pragma once

#include "encryptor.hpp"
#include "mapper.hpp"

template <MapperType MT>
class Reflector final : public Encryptor {
public:
	uint8_t map(uint8_t byte) final;

private:
	static constexpr int REFLECTOR_OFFSET = Mapper<MT>::ALPHABET_SIZE / 2;
};

template <MapperType MT>
uint8_t Reflector<MT>::map(uint8_t byte) {
	return Mapper<MT>::from_int(Mapper<MT>::to_int(byte) + REFLECTOR_OFFSET);
}
