#include "chip8.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Chip8 chip8;

    if(chip8.LoadROM("../../roms/Tetris [Fran Dachille, 1991].ch8")){
        std::cout << "True";
    }else{
        std::cout << "False";
    }

    return 0;
}
