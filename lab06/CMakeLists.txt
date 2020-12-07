cmake_minimum_required(VERSION 3.5)
project(lab06 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(
	HEADERS
	binary_tree_node.hpp
	huffman.hpp
	huffman_io.hpp
	huffman_tree_node.hpp
)

set(
	SOURCES
	huffman.cpp
	huffman_io.cpp
)

add_executable(huffman main.cpp ${HEADERS} ${SOURCES})
