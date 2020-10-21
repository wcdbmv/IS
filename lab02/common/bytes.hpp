#pragma once

static constexpr int BYTES_SIZE = 256;

static constexpr int rotate_byte(int n, int rot) {
	return (n + rot + BYTES_SIZE) % BYTES_SIZE;
}
