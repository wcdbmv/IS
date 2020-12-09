#pragma once

#include <queue>
#include <map>
#include "huffman_tree_node.hpp"

using BitsSequence = std::vector<bool>;
using BytesSequence = std::vector<HuffmanData::character_type>;
using HuffmanFrequencyTable = std::map<HuffmanData::character_type, HuffmanData::frequency_type>;

HuffmanFrequencyTable build_frequency_table(const BytesSequence& input);

BitsSequence encode(const BytesSequence& input, const HuffmanFrequencyTable& frequency_table);
BytesSequence decode(const BitsSequence& encoded, const HuffmanFrequencyTable& frequency_table);
