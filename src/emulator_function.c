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

uint32_t get_register32(Emulator* emu, uint8_t rm)
{
    return emu->registers[rm];
}

void set_register32(Emulator* emu, uint8_t rm, uint32_t value)
{
    emu->registers[rm] = value;
}

void set_memory8(Emulator* emu, uint32_t address, uint32_t value)
{
    emu->memory[address] = value & 0xFF;
}

void set_memory32(Emulator* emu, uint32_t address, uint32_t value)
{
    int i;
    for (i = 0; i < 4; i++) {
        set_memory32(emu, address + i, value >> (i * 8));
    }
}