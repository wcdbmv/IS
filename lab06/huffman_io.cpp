#include "huffman_io.hpp"

#include <fstream>

constexpr size_t BITS_IN_BYTES = 8;
using FrequencyTableSizeType = uint16_t;
using NPaddedBitsType = uint8_t;

BytesSequence convert(const BitsSequence& bits) {
	if (bits.empty()) {
		return {};
	}

	const auto n_bits = bits.size();
	const auto n_bytes = (n_bits - 1) / BITS_IN_BYTES + 1;

	BytesSequence bytes;
	bytes.reserve(n_bytes);

	for (BytesSequence::size_type i = 0; i < n_bytes; ++i) {
		BytesSequence::value_type byte{};
		for (BytesSequence::size_type j = 0; j < BITS_IN_BYTES; ++j) {
			byte = (byte << 1u) | (i * BITS_IN_BYTES + j < n_bits ? bits[i * BITS_IN_BYTES + j] : 0u);
		}
		bytes.push_back(byte);
	}

	return bytes;
}

BitsSequence convert(const BytesSequence& bytes, NPaddedBitsType n_padding_bits) {
	if (bytes.empty()) {
		return {};
	}

	const auto n_bytes = bytes.size();
	const auto n_bits = n_bytes * BITS_IN_BYTES - n_padding_bits;

	BitsSequence bits;
	bits.reserve(n_bits);

	for (BitsSequence::size_type i = 0; i < n_bits; ++i) {
		bits.push_back(bytes[i / BITS_IN_BYTES] & (1u << (BITS_IN_BYTES - 1 - i % BITS_IN_BYTES)));
	}

	return bits;
}

void encode(const char* input_filename, const char* output_filename) {
	std::ifstream input_file(input_filename, std::ios::binary);
	if (!input_file) {
		throw std::invalid_argument("can't open input file");
	}

	BytesSequence input(
		(std::istreambuf_iterator<char>(input_file)),
		(std::istreambuf_iterator<char>()));
	input_file.close();

	const auto frequency_table = build_frequency_table(input);

	const auto encoded_bits = encode(input, frequency_table);
	const auto encoded_bytes = convert(encoded_bits);

	std::ofstream output_file(output_filename, std::ios::binary);
	if (!output_file) {
		throw std::invalid_argument("can't open output file");
	}

	const auto frequency_table_size = static_cast<FrequencyTableSizeType>(frequency_table.size());
	output_file.write(reinterpret_cast<const char*>(&frequency_table_size), sizeof frequency_table_size);
	const auto n_padded_bits = static_cast<NPaddedBitsType>((BITS_IN_BYTES - encoded_bits.size() % BITS_IN_BYTES) % BITS_IN_BYTES);
	output_file.write(reinterpret_cast<const char*>(&n_padded_bits), sizeof n_padded_bits);
	for (auto [character, frequency] : frequency_table) {
		output_file.write(reinterpret_cast<const char*>(&character), sizeof character);
		output_file.write(reinterpret_cast<const char*>(&frequency), sizeof frequency);
	}
	output_file.write(reinterpret_cast<const char*>(&encoded_bytes[0]), encoded_bytes.size());
	output_file.close();
}

void decode(const char* input_filename, const char* output_filename) {
	std::ifstream input_file(input_filename, std::ios::binary);
	if (!input_file) {
		throw std::invalid_argument("can't open input file");
	}
	FrequencyTableSizeType frequency_table_size{};
	input_file.read(reinterpret_cast<char*>(&frequency_table_size), sizeof frequency_table_size);
	NPaddedBitsType n_padded_bits{};
	input_file.read(reinterpret_cast<char*>(&n_padded_bits), sizeof n_padded_bits);
	HuffmanFrequencyTable frequency_table;
	for (decltype(frequency_table_size) i = 0; i < frequency_table_size; ++i) {
		HuffmanFrequencyTable::key_type character{};
		input_file.read(reinterpret_cast<char*>(&character), sizeof character);
		HuffmanFrequencyTable::mapped_type frequency{};
		input_file.read(reinterpret_cast<char*>(&frequency), sizeof frequency);
		frequency_table[character] = frequency;
	}
	BytesSequence encoded_bytes(
		(std::istreambuf_iterator<char>(input_file)),
		(std::istreambuf_iterator<char>()));
	input_file.close();

	const auto encoded_bits = convert(encoded_bytes, n_padded_bits);
	const auto decoded_bytes = decode(encoded_bits, frequency_table);

	std::ofstream output_file(output_filename, std::ios::binary);
	if (!output_file) {
		throw std::invalid_argument("can't open output file");
	}

	output_file.write(reinterpret_cast<const char*>(&decoded_bytes[0]), decoded_bytes.size());
	output_file.close();
}
