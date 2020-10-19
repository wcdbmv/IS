#include "reflector.hpp"

#include "utils.hpp"

uint8_t Reflector::map(uint8_t c) {
	return int_to_upper(upper_to_int(c) + REFLECTOR_OFFSET);
}
