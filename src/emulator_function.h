#ifndef EMULATOR_FUNCTION_H_
#define EMULATOR_FUNCTION_H_

#include "emulator.h"
#include "modrm.h"

uint32_t get_code8(Emulator* emu, int index);
uint32_t get_sign_code8(Emulator* emu, int index);
uint32_t get_code32(Emulator* emu, int index);
uint32_t get_sign_code32(Emulator* emu, int index);
uint32_t get_register32(Emulator* emu, uint8_t rm);
void set_register32(Emulator* emu, uint8_t rm, uint32_t value);
void set_memory8(Emulator* emu, uint32_t address, uint32_t value);
void set_memory32(Emulator* emu, uint32_t address, uint32_t value);

#endif