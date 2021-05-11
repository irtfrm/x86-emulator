#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include "emulator.h"

void init_instructions(void);
typedef void instruction_func_t(Emulator*);
extern instruction_func_t* instructions[256];

void mov_r32_imm32(Emulator* emu);
static void mov_rm32_imm32(Emulator* emu);
void short_jump(Emulator* emu);
void near_jump(Emulator* emu);

#endif