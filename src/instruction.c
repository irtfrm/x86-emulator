#include <string.h>
#include <stdint.h>

#include "instruction.h"
#include "emulator.h"
#include "emulator_function.h"

instruction_func_t* instructions[256];

void init_instructions(void) {
    int i;
    memset(instructions, 0, sizeof(instructions));
    for (i = 0; i < 8; i++) {
        instructions[ 0xB8 + i ] = mov_r32_imm32;
    }
    instructions[0xE9] = near_jump;
    instructions[0xEB] = short_jump;
}