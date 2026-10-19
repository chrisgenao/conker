#include <ultra64.h>
#include "functions.h"
#include "variables.h"


f32 func_150497E0(f32 *arr, s32 idx, f32 t) {
    f32 x = arr[idx];
    f32 y = arr[idx + 1];
    f32 z = arr[idx + 2];
    f32 w = arr[idx + 3];
    f32 c3 = 0.5f * w + (-0.5f * x + 1.5f * y + -1.5f * z);
    f32 c2 = -0.5f * w + ((x + -2.5f * y) + (z + z));
    f32 c1 = 0.5f * z + -0.5f * x;

    return y + t * (c1 + t * (c2 + t * c3));
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_76C90/func_150498A4.s")
