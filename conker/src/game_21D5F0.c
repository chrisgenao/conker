#include <ultra64.h>
#include "functions.h"
#include "variables.h"


/* Standard libultra guMtxXFMF: transform (x,y,z) by 4x4 matrix, write to *ox/*oy/*oz. */
void guMtxXFMF(f32 mf[4][4], f32 x, f32 y, f32 z, f32 *ox, f32 *oy, f32 *oz) {
    *ox = mf[0][0] * x + mf[1][0] * y + mf[2][0] * z + mf[3][0];
    *oy = mf[0][1] * x + mf[1][1] * y + mf[2][1] * z + mf[3][1];
    *oz = mf[0][2] * x + mf[1][2] * y + mf[2][2] * z + mf[3][2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_21D5F0/guMtxCatF.s")
