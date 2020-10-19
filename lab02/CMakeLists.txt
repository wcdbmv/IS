cmake_minimum_required(VERSION 3.5)
project(lab02 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_compile_options(
	-Werror

	-Wall
	-Wextra
	-Wpedantic

	# -Wcast-align
	# -Wcast-qual
	# -Wconversion
	-Wctor-dtor-privacy
	-Wenum-compare
	-Wfloat-equal
	-Wnon-virtual-dtor
	-Wold-style-cast
	-Woverloaded-virtual
	-Wredundant-decls
	# -Wsign-conversion
	# -Wsign-promo
)

set(
	HEADERS
	common/configurable.hpp
	common/encryptor.hpp
	common/letters.hpp
	common/reverse.hpp
	enigma/enigma.hpp
	enigma/letter_enigma.hpp
	io_module/io_module.hpp
	io_module/letter_io_module.hpp
	plugboard/letter_plugboard.hpp
	plugboard/plugboard.hpp
	reflector/letter_reflector.hpp
	reflector/reflector.hpp
	rotor/letter_rotor.hpp
	rotor/rotor.hpp
	rotor_box/letter_rotor_box.hpp
	rotor_box/rotor_box.hpp
)

set(
	SOURCES
	enigma/enigma.cpp
	enigma/letter_enigma.cpp
	io_module/io_module.cpp
	io_module/letter_io_module.cpp
	plugboard/letter_plugboard.cpp
	plugboard/plugboard.cpp
	reflector/letter_reflector.cpp
	reflector/reflector.cpp
	rotor/letter_rotor.cpp
	rotor/rotor.cpp
	rotor_box/letter_rotor_box.cpp
	rotor_box/rotor_box.cpp
)

add_executable(enigma main.cpp ${HEADERS} ${SOURCES})
