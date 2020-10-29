#pragma once

#include <cstdlib>

enum MapperType {
	Byte = 0,
	Letter = 1,
};

template <MapperType mapper_type>
struct Mapper {
	static constexpr int to_int(uint8_t byte) = delete;
	static constexpr uint8_t from_int(int idx) = delete;
};

template <>
struct Mapper<Byte> {
	static constexpr int to_int(uint8_t byte) { return byte; }
	static constexpr uint8_t from_int(int idx) { return idx; }

	static constexpr int ALPHABET_SIZE = 256;
};

template <>
struct Mapper<Letter> {
	static constexpr int to_int(uint8_t upper) { return upper - 'A'; }
	static constexpr uint8_t from_int(int idx) {
		return static_cast<uint8_t>((idx + ALPHABET_SIZE) % ALPHABET_SIZE + 'A');
	}

	static constexpr int ALPHABET_SIZE = 26;
};

