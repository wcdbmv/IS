#include "reflector.hpp"

#include "utils.hpp"

char Reflector::map(char c) {
	return int_to_upper(upper_to_int(c) + REFLECTOR_OFFSET);
}
