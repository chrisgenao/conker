#include <ultra64.h>

#include "functions.h"
#include "variables.h"

void func_15000940(void) {
    u8 *var_a0;
    u8 *var_a1;
    u8 *var_a2;
    u8 *var_s0;
    u8 *var_s2;
    u8 *var_s4;
    u8 *var_s5;
    u8 *var_t3;
    u8 *var_t4;
    u8 *var_v0;
    u8 *var_v1;
    u8 *var_s1;
    u8 *var_s3;
    u8 *var_t5;
    u8 temp_t6;
    u8 temp_t7;
    u8 temp_t9;
    u8 (*temp_t4)[3];

    temp_t4 = &D_800A2CD0[D_800B0DF0->unk29];
    var_v0 = &D_800D9EB8[0][0];
    var_a2 = &D_800D9EA8[0][0];
    var_a1 = &D_800D9E98[0][0];
    var_a0 = &D_800D9E88[0][0];
    var_v1 = &D_800D9E70[0][0];
    while (var_v0 != D_800D9EC4) {
        var_s2 = &D_800D9EB4[0][0];
        while (var_s2 != D_800D9EB7) {
            var_t3 = var_v1;
            var_t4 = var_a0;
            var_t5 = &D_800A2CE8[temp_t4[0][0]][0];
            var_s0 = var_a1;
            var_s1 = &D_800A2CEC[temp_t4[0][1]][0];
            var_s3 = &D_800A2D04[temp_t4[0][2]][0];
            var_s4 = var_a2;
            var_s5 = var_v0;
            temp_t9 = *var_s3;
            temp_t6 = *var_t5;
            temp_t7 = *var_s1;
            var_s2 += 1;
            var_t3 += 2;
            var_t4 += 1;
            var_t5 += 1;
            var_s0 += 1;
            var_s1 += 1;
            var_s3 += 1;
            var_s4 += 1;
            var_s5 += 1;
            *(u8 *)((u8 *)var_t3 - 2) = 0;
            *(u8 *)((u8 *)var_s5 - 1) = 0;
            *(u8 *)((u8 *)var_s2 - 1) = temp_t9;
            *(u8 *)((u8 *)var_s4 - 1) = temp_t9;
            *(u8 *)((u8 *)var_t4 - 1) = temp_t6;
            *(u8 *)((u8 *)var_s0 - 1) = temp_t7;
        }
        var_v0 += 3;
        var_v1 += 6;
        var_a0 += 3;
        var_a1 += 3;
        var_a2 += 3;
    }
}
