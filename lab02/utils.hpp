#pragma once

#include <iterator>

static constexpr int ALPHABET_SIZE = 26;

static constexpr int upper_to_int(uint8_t upper) {
	return upper - 'A';
}

static constexpr uint8_t int_to_upper(int n) {
	return static_cast<uint8_t>((n + ALPHABET_SIZE) % ALPHABET_SIZE + 'A');
}

static constexpr int rotate(int n, int rot) {
	return (n + rot + ALPHABET_SIZE) % ALPHABET_SIZE;
}

template <typename T>
struct reversion_wrapper { T& iterable; };

template <typename T>
auto begin (reversion_wrapper<T> w) { return std::rbegin(w.iterable); }

template <typename T>
auto end (reversion_wrapper<T> w) { return std::rend(w.iterable); }

template <typename T>
reversion_wrapper<T> reverse (T&& iterable) { return { iterable }; }
