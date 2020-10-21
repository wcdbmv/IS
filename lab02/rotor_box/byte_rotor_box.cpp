#include "byte_rotor_box.hpp"

#include "reflector/byte_reflector.hpp"

ByteRotorBox::ByteRotorBox()
	: RotorBox(std::unique_ptr<Reflector>(new ByteReflector))
	{ }
