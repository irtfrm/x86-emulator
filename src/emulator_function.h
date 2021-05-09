#ifndef EMULATOR_FUNCTION_H_
#define EMULATOR_FUNCTION_H_

#include "emulator.h"

uint32_t get_code8(Emulator* emu, int index);
uint32_t get_sign_code8(Emulator* emu, int index);
uint32_t get_code32(Emulator* emu, int index);
uint32_t get_sign_code32(Emulator* emu, int index);

void mov_r32_imm32(Emulator* emu);
void short_jump(Emulator* emu);
void near_jump(Emulator* emu);

#endif