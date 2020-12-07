#include "huffman.hpp"

#include <unordered_map>

using HuffmanMap = std::unordered_map<HuffmanData::character_type, BitsSequence>;

struct HuffmanNodeCompare {
	bool operator()(HuffmanNode* lhs, HuffmanNode* rhs) {
		return lhs->data.frequency > rhs->data.frequency;
	}
};

HuffmanNode* build_tree(const HuffmanFrequencyTable& frequency_table) {
	using HuffmanPriorityQueue = std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, HuffmanNodeCompare>;
	HuffmanPriorityQueue queue;
	for (auto [character, frequency] : frequency_table) {
		auto node = new HuffmanNode{{character, frequency}};
		queue.push(node);
	}

	while (queue.size() > 1) {
		auto left = queue.top();
		queue.pop();

		auto right = queue.top();
		queue.pop();

		auto node = new HuffmanNode{{0, left->data.frequency + right->data.frequency}, left, right};
		queue.push(node);
	}

	return queue.empty() ? nullptr : queue.top();
}

HuffmanMap build_lookup_table(HuffmanNode* root) {
	HuffmanMap lookup;
	std::deque<std::pair<HuffmanNode*, BitsSequence>> deque{{root, {}}};
	while (!deque.empty()) {
		auto [node, code] = deque.front();
		deque.pop_front();

		if (node->left) {
			auto& code_left = code;
			auto code_right = code;
			code_left.push_back(false);
			code_right.push_back(true);
			deque.emplace_back(node->left, code_left);
			deque.emplace_back(node->right, code_right);
		} else {
			lookup.emplace(node->data.character, code);
		}
	}
	return lookup;
}

BitsSequence encode(const BytesSequence& input, const HuffmanMap& lookup) {
	BitsSequence encoded;
	for (auto character : input) {
		auto& bits = lookup.at(character);
		encoded.insert(encoded.end(), bits.begin(), bits.end());
	}
	return encoded;
}

BitsSequence encode(const BytesSequence& input, HuffmanNode* root) {
	const auto lookup = build_lookup_table(root);
	return encode(input, lookup);
}

BitsSequence encode(const BytesSequence& input, const HuffmanFrequencyTable& frequency_table) {
	auto root = build_tree(frequency_table);
	return encode(input, root);
}

HuffmanData::character_type code_lookup(BitsSequence::const_iterator& begin, BitsSequence::const_iterator end, const HuffmanNode* node) {

	for (; node->left; (node->right ? 0 : throw std::invalid_argument("Invalid tree")), node = *begin++ ? node->right : node->left) {
		if (begin == end) {
			throw std::out_of_range("Expected more bits");
		}
	}
	return node->data.character;
}

BytesSequence decode(const BitsSequence& encoded, const HuffmanNode *root) {
	BytesSequence decoded;
	for (auto begin = encoded.begin();;) {
		try {
			decoded.emplace_back(code_lookup(begin, encoded.end(), root));
		} catch (const std::out_of_range& error) {
			break;
		}
	}
	return decoded;
}

BytesSequence decode(const BitsSequence& encoded, const HuffmanFrequencyTable& frequency_table) {
	auto root = build_tree(frequency_table);
	if (!root) {
		throw std::invalid_argument("Empty frequency table");
	}
	return decode(encoded, root);
}

HuffmanFrequencyTable build_frequency_table(const BytesSequence& input) {
	HuffmanFrequencyTable frequency_table;
	for (auto byte : input) {
		++frequency_table[byte];
	}
	return frequency_table;
}
