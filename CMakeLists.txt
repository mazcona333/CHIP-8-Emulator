cmake_minimum_required(VERSION 3.14)
project(chip8_emulator)

set(CMAKE_CXX_STANDARD 11)

#find_package(SDL2 REQUIRED)

set(SOURCE_FILES src/main.cpp src/chip8.cpp src/chip8.h)

add_executable(
	chip8_emulator
	${SOURCE_FILES})

target_link_libraries(chip8_emulator)