#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_D7980/func_150AA4D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_D7980/func_150AA5A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_D7980/func_150AA644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_D7980/func_150AA678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_D7980/func_150AA778.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_D7980/func_150AA814.s")

void func_150AA9A0(f32 f23, f32 f24, f32 f25, f32 f26, f32 f27, f32 f28, f32 f29, f32 f30, f32 f31) {
    f32 f4 = f24 - f27;
    f32 f8 = f25 - f31;
    f32 f7 = f24 - f30;
    f32 f19 = f4 * f8;
    f32 f5 = f25 - f28;
    f32 f3 = f23 - f26;
    f32 f9 = f5 * f7;
    f32 f6 = f23 - f29;
    f32 f20 = f3 * f8;
    f19 = f19 - f9;
    f9 = f5 * f6;
    f32 f21 = f3 * f7;
    f20 = f9 - f20;
    f9 = f4 * f6;
    f32 f10 = f20 * f24;
    f21 = f21 - f9;
    f9 = f19 * f23;
    f32 f22 = f9 + f10;
    f10 = f21 * f25;
    f22 = f22 + f10;

    D_800CC210 = f19;
    D_800CC214 = f20;
    D_800CC218 = f21;
    D_800CC21C = f22;
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_D7980/func_150AAA20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_D7980/func_150AAD98.s")
