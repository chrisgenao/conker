#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_CD5A0/func_150A00F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_CD5A0/func_150A019C.s")

extern u8 D_800D3010[];

s32 func_150A0264(s32 arg0, s32 *arg1) {
    s32 *entry = (s32 *)(D_800D3010 + 12 * arg0);
    u32 field0 = (u32)entry[0];
    u8 head = *(u8 *)entry;
    s32 tailword;
    u8 b;

    if ((field0 >> 31) == 0) {
        return 0;
    }
    entry[0] = 0;
    tailword = arg1[1];
    b = (head | 0x80) & 0xBF;
    *(u8 *)entry = ((tailword << 2) & 0x3C) | (b & 0xC3);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_CD5A0/func_150A02D0.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} D3014Struct;

extern D3014Struct D_800D3014[];

s32 func_150A0374(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 == 3) {
        return D_800D3014[arg0].unk0;
    }
    return 0;
}
