#include "emulator.h"
#include "emulator_function.h"

uint32_t get_code8(Emulator* emu, int index)
{
    return emu->memory[emu->eip + index];
}

uint32_t get_sign_code8(Emulator* emu, int index)
{
    return (int8_t)emu->memory[emu->eip + index];
}

uint32_t get_code32(Emulator* emu, int index)
{
    int32_t i;
    uint32_t ret = 0;
    for (i=0; i<4; i++) {
        ret |= get_code8(emu, index + i) << (i * 8);
    }
    return ret;
}

uint32_t get_sign_code32(Emulator* emu, int index)
{
    return (int32_t) get_code32(emu, index);
}

void mov_r32_imm32(Emulator* emu)
{
    uint8_t reg = get_code8(emu, 0) - 0xB8;
    uint32_t value = get_code32(emu, 1);
    emu->registers[reg] = value;
    emu->eip += 5;
}

void short_jump(Emulator* emu)
{
    int8_t diff = get_sign_code8(emu, 1);
    emu->eip += (diff + 2);
}

void near_jump(Emulator* emu)
{
    int32_t diff = get_sign_code32(emu, 1);
    emu->eip += (diff+5);
}