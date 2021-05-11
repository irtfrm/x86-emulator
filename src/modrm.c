#include "modrm.h"
#include "emulator.h"
#include "emulator_function.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void parse_modrm(Emulator* emu, ModRM* modrm)
{
    uint8_t code;
    
    memset(modrm, 0, sizeof(ModRM));
    
    code = get_code8(emu, 0);
    modrm->mod = ((code & 0xc0) >> 6);
    modrm->opecode = ((code & 0x38) >> 3);
    modrm->rm = code & 0x07;
    emu->eip += 1;

    if (modrm->rm == 4 && modrm->mod != 3){
        modrm->sib = get_code8(emu, 0);
        emu->eip += 1;
    }
    if (modrm->mod == 2 || (modrm->mod == 0 && modrm->rm == 5)){
        modrm->disp32 = get_sign_code32(emu, 0);
        emu->eip += 4;
    } else if (modrm->mod == 1) {
        modrm->disp8 = get_sign_code8(emu, 0);
        emu->eip += 1;
    }
}

uint32_t calc_memory_address(Emulator* emu, ModRM* modrm)
{
    if (modrm->mod == 0) {
        if (modrm->rm == 4) {
            printf("not implemented\n"); // TODO
            exit(0);
        } else if (modrm->rm == 5) {
            return modrm->disp32;
        } else {
            return get_register32(emu, modrm->rm);
        }
    } else if (modrm->mod == 1) {
        if (modrm->rm == 4) {
            printf("not implemented\n"); // TODO
            exit(0);
        } else {
            return get_register32(emu, modrm->rm) + modrm->disp8;
        }
    } else if (modrm->mod == 2) {
        if (modrm->rm == 4) {
            printf("not implemented\n"); // TODO
            exit(0);
        } else {
            return get_register32(emu, modrm->rm) + modrm->disp32;
        }
    } else {
        printf("not implemented\n"); // TODO
        exit(0);
    }
}

void set_rm32(Emulator* emu, ModRM* modrm, uint32_t value)
{
    if (modrm->mod == 3) {
        set_register32(emu, modrm->rm, value);
    } else {
        uint32_t address = calc_memory_address(emu, modrm);
        set_memory32(emu, address, value);
    }
}