#include <ultra64.h>

#include "functions.h"
#include "variables.h"


// whats wrong with bcopy?
u8* func_16001AD0(u8 *arg0, u8 *arg1, u32 arg2) {
    u8 *tmp0 = arg0;
    u8 *tmp1 = arg1;

    while (arg2 > 0) {
        *tmp0++ = *tmp1++;
        arg2 -= 1;
    }

    return arg0;
}

// strlen
s32 func_16001B00(u8 *arg0) {
    u8 *ptr = arg0;
    s32 i = 0;

    if (*arg0 != 0) {
        do {
            i++;
            ptr++;
        } while (*ptr != 0);
    }
    return i;
}

s32 func_16001B34(s32 arg0, void *arg1, void *arg2, void *arg3, f64 arg4) {
    struct05 *s = (struct05 *)arg1;
    s32 idx = func_16001BB4(&func_16001B8C, (u8 *)s, (u8 *)arg1, (s32 *)arg2);
    if (idx >= 0) {
        ((u8 *)arg0)[idx] = 0;
    }
    return idx;
}

s32 func_16001B8C(u8 *arg0, u8 *arg1, u32 arg2) {
    return func_16001AD0(arg0, arg1, arg2) + arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/debugger_257350/func_16001BB4.s")
// uses jump table
#pragma GLOBAL_ASM("asm/nonmatchings/debugger_257350/func_160021FC.s")
// contains delay slot
#pragma GLOBAL_ASM("asm/nonmatchings/debugger_257350/func_1600288C.s")

// validates controller PIF data
s32 func_16002D2C(s16 *arg0, struct05 *arg1) {
    u16 temp_a2 = arg1->unk0;
    s32 temp_t6 = (s32)(temp_a2 & 0x7FF0) >> 4;

    if ((s16)temp_t6 == 0x7FF) {
        *arg0 = 0;
        if ((arg1->unk0 & 0xF) || (arg1->unk2 != 0) || (arg1->unk4 != 0) || (arg1->unk6 != 0)) {
            return 2;
        }
        return 1;
    }
    if ((s16)temp_t6 > 0) {
        arg1->unk0 = (u16)((temp_a2 & 0x800F) | 0x3FF0);
        *arg0 = (s16)temp_t6 - 0x3FE;
        return -1;
    }
    if ((s16)temp_t6 < 0) {
        return 2;
    }
    *arg0 = 0;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/debugger_257350/func_16002DE4.s")
#pragma GLOBAL_ASM("asm/nonmatchings/debugger_257350/func_160033A8.s")
