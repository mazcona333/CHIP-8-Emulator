cmake_minimum_required(VERSION 3.14)
project(chip8_emulator)

set(CMAKE_CXX_STANDARD 11)

#set(SDL2_INCLUDE_DIR "D:/Repos/CHIP-8-Emulator/thirdparty/SDL2-2.24.0/i686-w64-mingw32/include/SDL2")
#set(SDL2_LIBRARY_DIR "C:/Users/Mario/Downloads/SDL2-devel-2.24.0-mingw.zip/SDL2-2.24.0/i686-w64-mingw32/lib")
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES src/main.cpp src/chip8.cpp src/Platform.cpp)

add_executable(
	chip8_emulator
	${SOURCE_FILES})

#target_compile_options(chip8_emulator PRIVATE -Wall)

target_link_libraries(chip8_emulator)