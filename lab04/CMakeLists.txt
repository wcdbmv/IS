cmake_minimum_required(VERSION 3.17)
project(lab04)

set(CMAKE_CXX_STANDARD 20)

include_directories(/usr/local/Cellar/gmp/6.2.1/include/)
link_directories(/usr/local/Cellar/gmp/6.2.1/lib/)

set(CMAKE_CXX_FLAGS "-lgmpxx -lgmp")

add_executable(rsa main.cpp io.cpp io.hpp keygen.cpp keygen.hpp rsa.cpp rsa.hpp)

