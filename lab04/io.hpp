#pragma once

#include <gmpxx.h>

mpz_class read_mpz(const char* filename);
void write_mpz(const char* filename, const mpz_t n);

std::pair<mpz_class, mpz_class> read_key(const char* filename);
void write_key(const char* filename, const mpz_class& e, const mpz_class& n);
