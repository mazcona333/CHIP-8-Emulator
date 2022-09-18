cmake_minimum_required(VERSION 3.14)
project(chip8_emulator)

set(CMAKE_CXX_STANDARD 11)

set(SDL2_INCLUDE_DIR "thirdparty/SDL2-2.24.0/include")
set(SDL2_LIBRARY_DIR "thirdparty/SDL2-2.24.0/lib")
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES src/main.cpp src/chip8.cpp src/Platform.cpp)

add_executable(
	chip8_emulator
	${SOURCE_FILES})

target_link_libraries(chip8_emulator -lmingw32 ${SDL2_LIBRARY_DIR}/libSDL2main.a ${SDL2_LIBRARY_DIR}/libSDL2.dll.a -mwindows)