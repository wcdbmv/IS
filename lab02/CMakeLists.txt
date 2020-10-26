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
	configurable.hpp
	encryptor.hpp
	mapper.hpp
	reverse.hpp
	enigma.hpp
	io_module.hpp
	plugboard.hpp
	reflector.hpp
	rotor.hpp
	rotor_box.hpp
)

add_executable(enigma main.cpp ${HEADERS})
