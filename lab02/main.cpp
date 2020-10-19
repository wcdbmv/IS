#include "enigma.hpp"

int main(int argc, char** argv) {
	Enigma enigma;
	enigma.setup(argc, argv);
	enigma.operate();
}
