cmake_minimum_required(VERSION 3.14)
project(chip8_emulator)

set(CMAKE_CXX_STANDARD 11)

set(SDL2_DIR D:/Repos/SDL2-2.24.0/cmake)

find_package(SDL2 REQUIRED)

set(SOURCE_FILES src/main.cpp src/chip8.cpp src/Platform.cpp)

add_executable(
	chip8_emulator
	${SOURCE_FILES})

target_link_libraries(chip8_emulator PRIVATE SDL2::SDL2)