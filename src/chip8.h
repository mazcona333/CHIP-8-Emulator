#ifndef CHIP8_H
#define CHIP8_H

#include <cstdint>
#include <random>

const unsigned int VIDEO_WIDTH = 64;
const unsigned int VIDEO_HEIGHT = 32;

class Chip8
{
public:
    Chip8();
    bool LoadROM(char const *filename);
    void Cycle();
    uint32_t video[VIDEO_WIDTH * VIDEO_HEIGHT]{};
    uint8_t keypad[16]{};

private:
    uint8_t registers[16]{};
    uint8_t memory[4096]{};
    uint16_t index{};
    uint16_t pc{};
    uint16_t stack[16]{};
    uint8_t sp{};
    uint8_t delayTimer{};
    uint8_t soundTimer{};
    uint16_t opcode{};

    std::default_random_engine randGen;
    std::uniform_int_distribution<uint16_t> randByte;

    void Table0();
    void Table8();
    void TableE();
    void TableF();

    // Do nothing
    void OP_NULL();

    // CLS
    void OP_00E0(); // Clear display

    // RET
    void OP_00EE(); // Return from subroutine

    // JP address
    void OP_1nnn(); // Jump to location nn

    // CALL address
    void OP_2nnn(); // Call subroutine at nnn

    // SE Vx, byte
    void OP_3xkk(); // Skip next instruction if Vx == kk

    // SNE Vx, byte
    void OP_4xkk(); // Skip next instruction if Vx != kk

    // SE Vx, Vy
    void OP_5xy0(); // Skip next instruction if Vx == Vy

    // LD Vx, byte
    void OP_6xkk(); // Set Vx = kk

    // ADD Vx, byte
    void OP_7xkk(); // Set Vx = Vx + kk

    // LD Vx, Vy
    void OP_8xy0(); // Set Vx = Vy

    // OR Vx, Vy
    void OP_8xy1(); // Set Vx = Vx OR Vy

    // AND Vx, Vy
    void OP_8xy2(); // Set Vx = Vx AND Vy

    // XOR Vx, Vy
    void OP_8xy3(); // Set Vx = Vx XOR Vy

    // ADD Vx, Vy
    void OP_8xy4(); // Set Vx = Vx + Vy, set VF = carry. If Vx + Vy > 255, VF = 1, otherwise 0. Only the lowest 8 bits stored in Vx.

    // SUB Vx, Vy
    void OP_8xy5(); // Set Vx = Vx - Vy, set VF = NOT borrow. If Vx > Vy, then VF is set to 1, otherwise 0.

    // SHR Vx
    void OP_8xy6(); // If the least-significant bit of Vx is 1, then VF is set to 1, otherwise 0. Then Vx is divided by 2.

    // SUBN Vx, Vy
    void OP_8xy7(); // Set Vx = Vy - Vx, set VF = NOT borrow. If Vy > Vx, then VF is set to 1, otherwise 0.

    // SHL Vx
    void OP_8xyE(); // Set Vx = Vx SHL 1. If the most-significant bit of Vx is 1, then VF is set to 1, otherwise to 0. Then Vx is multiplied by 2.

    // SNE Vx, Vy
    void OP_9xy0(); // Skip next instruction if Vx != Vy.

    // LD I, address
    void OP_Annn(); // Set I = nnn.

    // JP V0, address
    void OP_Bnnn(); // Jump to location nnn + V0.

    // RND Vx, byte
    void OP_Cxkk(); // Set Vx = random byte AND kk.

    // DRW Vx, Vy, height
    void OP_Dxyn(); // Display n-byte sprite starting at memory location I at (Vx, Vy), set VF = collision.

    // SKP Vx
    void OP_Ex9E(); // Skip next instruction if key with the value of Vx is pressed.

    // SKNP Vx
    void OP_ExA1(); // Skip next instruction if key with the value of Vx is not pressed.

    // LD Vx, DT
    void OP_Fx07(); // Set Vx = delay timer value.

    // LD Vx, K
    void OP_Fx0A(); // Wait for a key press, store the value of the key in Vx.

    // LD DT, Vx
    void OP_Fx15(); // Set delay timer = Vx.

    // LD ST, Vx
    void OP_Fx18(); // Set sound timer = Vx.

    // ADD I, Vx
    void OP_Fx1E(); // Set I = I + Vx.

    // LD F, Vx
    void OP_Fx29(); // Set I = location of sprite for digit Vx.

    // LD B, Vx
    void OP_Fx33(); // Store BCD representation of Vx in memory locations I, I+1, and I+2. The interpreter takes the decimal value of Vx, and places the hundreds digit in memory at location in I, the tens digit at location I+1, and the ones digit at location I+2.

    // LD [I], Vx
    void OP_Fx55(); // Store registers V0 through Vx in memory starting at location I.

    // LD Vx, [I]
    void OP_Fx65(); // Read registers V0 through Vx from memory starting at location I.

	typedef void (Chip8::*Chip8Func)();
    Chip8Func table[0xF + 1];
	Chip8Func table0[0xE + 1];
	Chip8Func table8[0xE + 1];
	Chip8Func tableE[0xE + 1];
	Chip8Func tableF[0x65 + 1];

};

#endif // CHIP8_H