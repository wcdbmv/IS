#pragma once

#include <cstdint>
#include "binary_tree_node.hpp"

struct HuffmanData {
	using character_type = uint8_t;
	using frequency_type = uint32_t;

	character_type character;
	frequency_type frequency;
};

using HuffmanNode = BinaryTreeNode<HuffmanData>;
