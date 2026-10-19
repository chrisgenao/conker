#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150A7D00(s16 *m, f32 x, f32 y, f32 z) {
    s32 xi = (s32)(x * 65536.0f);
    s32 yi = (s32)(y * 65536.0f);
    s32 zi = (s32)(z * 65536.0f);
    s32 i;
    s32 *w = (s32 *)m;

    // 8x sd zero: m[0..31] as s16 = w[0..15] as s32
    for (i = 0; i < 16; i++) {
        w[i] = 0;
    }
    m[0] = 1;
    m[5] = 1;
    m[10] = 1;
    m[15] = 1;
    m[12] = (s16)(xi >> 16);
    m[13] = (s16)(yi >> 16);
    m[14] = (s16)(zi >> 16);
    m[28] = (s16)xi;
    m[29] = (s16)yi;
    m[30] = (s16)zi;
}
