#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/game_188440/func_1515AF90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game_188440/func_1515B21C.s")

extern void func_1515572C(s16 *, s32);

void func_1515B5F4(s16 arg0) {
    s16 sp1C[2];

    sp1C[0] = arg0;
    func_1515572C(sp1C, 0xB);
}

void func_1515B62C(struct102 *arg0, s16 *arg1, u8 arg2) {
    if (arg2 == 0xB) {
        if (*(s16 *)((u8 *)arg0 + 0x70) == arg1[0]) {
            func_1516972C(arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/game_188440/func_1515B674.s")

void func_1515B994(f32 *arg0) {
    f32 *src = *(f32 **)&D_800BE9A4;
    f32 scale = *src;
    f32 old_unk78 = arg0[0x78 / 4];
    f32 unk74 = arg0[0x74 / 4];
    f32 unk14 = arg0[0x14 / 4];
    f32 unk7C = arg0[0x7C / 4];
    f32 unk80 = arg0[0x80 / 4];

    arg0[0x14 / 4] = unk14 + old_unk78 * scale + unk74 * scale;
    arg0[0x78 / 4] = old_unk78 + unk74 * scale;
    arg0[0x1C / 4] = unk7C + unk80 * (2.0f * old_unk78 + unk74 * scale);
}

void func_1515BA10(s32 arg0) {
}

extern void func_1515AF90(s16);

void func_1515BA1C(s16 arg0) {
    func_1515AF90(arg0);
}

void func_1515BA48(s32 arg0) {
}

extern void func_1515B674(s16);

void func_1515BA54(s16 arg0) {
    func_1515B674(arg0);
}

extern void func_1515B5F4(s16);

void func_1515BA80(s16 arg0) {
    func_1515B5F4(arg0);
}

void func_1515BAAC(s16 arg0) {
    func_1515B5F4(arg0);
}
