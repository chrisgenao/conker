#include <ultra64.h>

#include "functions.h"
#include "variables.h"

void func_151D3354(struct224 *arg0);
void func_151D3308(struct224 *arg0);
void func_151D33FC(struct224 *arg0, struct223 *arg1);
extern void (*D_8008FC64[])(struct224*, struct223*, u8);

void func_151D2AB0(s32 arg0) {
    u32 tmp;

    (&D_800E0950)[arg0] = (&D_800E0950)[arg0] + 1;

    if ((&D_800E0950)[arg0] < 2) {
        D_800E0990[arg0] = func_1502B5C8(&tmp, 2, 9, D_800AB140[arg0]);
        D_800E0968[arg0] = tmp >> 4;
    }
}

void func_151D2B4C(s32 arg0) {
    if ((&D_800E0950)[arg0] != 0) {
        (&D_800E0950)[arg0] = (&D_800E0950)[arg0] - 1;
        if ((&D_800E0950)[arg0] == 0) {
            func_100043B4(D_800E0990[arg0], 4);
        }
    }
}

typedef struct { s32 a[9]; } struct_36b;
s32 func_15167A68(s32, s32, s32, s32, s32, s32);
typedef struct { s32 a[3]; } struct_12b;
typedef struct { s32 a[1]; } struct_4b;
struct224 *func_151D2BA4(s32 arg0, struct00 *arg1, s32 arg2, u8 arg3, s32 arg4) {
    struct224 *tmp = func_15167A68(0x3D, arg4, arg2 + 0x48, 1, arg3, 1);

    if (tmp == 0) {
        return 0;
    }

    memcpy(&tmp->unk10, arg0, 36);
    
    *(struct_12b*)&tmp->unk34 = *(struct_12b*)arg1;

    func_151D3308(tmp);
    return tmp;
}

#define S_U8(ptr, offset)  (*(u8*)((u8*)(ptr) + (offset)))
#define S_S8(ptr, offset)  (*(s8*)((u8*)(ptr) + (offset)))
#define S_S16(ptr, offset) (*(s16*)((u8*)(ptr) + (offset)))
#define S_S32(ptr, offset) (*(s32*)((u8*)(ptr) + (offset)))
#define S_U32(ptr, offset) (*(u32*)((u8*)(ptr) + (offset)))
#define S_PTR(ptr, offset) (*(void**)((u8*)(ptr) + (offset)))

extern void (*D_8008FC48[])(struct224*, struct_12b*);
extern s32 (*D_8008FC40[])(struct224*, struct_12b*);
extern void func_15143134(void*, void*, void*);

typedef struct {
    u8 pad0[0x10];
    void *unk10;
    u8 unk14;
    u8 pad15[0xB];
    s16 unk20;
    u8 pad22[0x2];
    u8 unk24;
    u8 unk25;
    s16 unk26;
    u8 unk28;
    s8 unk29;
    s8 unk2A;
    u8 pad2B;
    s32 unk2C;
    void *unk30;
    struct_12b unk34;
} struct_1FFF60_node;

void func_151D2C40(struct_1FFF60_node *arg0) {
    void *temp_v0;
    struct_12b sp28;
    void *temp_v1;

    temp_v0 = arg0->unk10;
    if (S_U32(temp_v0, 0) == 0 || S_U8(temp_v0, 4) == 0xFF || arg0->unk14 != S_U8(temp_v0, 0x3B) || (temp_v1 = S_PTR(temp_v0, 0x1D4)) == 0 || (S_U8(temp_v0, 0x74) & 0xF) == 0xF) {
        func_1516972C((struct224 *)arg0);
        return;
    }

    func_15143134((u8 *)arg0 + 0x18, &sp28, (u8 *)temp_v1 + (arg0->unk24 << 6));

    if (arg0->unk28 & 1) {
        arg0->unk26 -= D_800BE9E4;
        if (arg0->unk26 < 0) {
            if (arg0->unk2A != -1) {
                D_8008FC48[arg0->unk2A]((struct224 *)arg0, &sp28);
            }
            arg0->unk2C = 0;
            func_1516972C((struct224 *)arg0);
            return;
        }
    }

    if (arg0->unk29 != -1) {
        if (D_8008FC40[arg0->unk29]((struct224 *)arg0, &sp28) == 0) {
            func_1516972C((struct224 *)arg0);
            return;
        }
    }

    arg0->unk34 = sp28;
}

void func_151D2DAC(struct102 *arg0) {
    func_151D3354(arg0);
}

void func_151D2DCC(struct102 *arg0) {
    struct102 *tmp = arg0;

    func_151D2DAC(tmp);

    if (tmp->unk2C != 0) {
        func_1516972C(tmp->unk2C);
    }
    func_15169804(tmp);
}

void func_151D2E14(struct102 *arg0) {
    struct102 *tmp = arg0;

    func_151D2DAC(tmp);

    if (tmp->unk2C != 0) {
        func_1516979C(tmp->unk2C);
    }
    func_15169824(tmp);
}

void func_151D2E5C(struct224 *arg0, struct223 *arg1, u8 arg2) {
    s32 *new_var;

    if (arg2 == 0) {
        s32 tmp0;
        s32 tmp1;
        s32 tmp2;
        s32 tmp3;

        tmp0 = arg0->unk10;
        tmp1 = arg0->unk14;
        tmp2 = arg1->unk4.ub;
        tmp3 = arg1->unk0;
        if ((tmp0 == tmp3) || (tmp2 == tmp1)) {
            func_1516972C(arg0);
        }
        return;
    }
    new_var = &arg0->unk10;
    if (arg2 != 0x2D) {
        return;
    }
    {
        s32 unk0 = arg1->unk0;

        if (unk0 == (*new_var)) {
            arg0->unk10 = arg1->unk4.w;
            arg0->unk14 = arg1->unk9;
            return;
        }
        if (arg1->unk4.w == (*new_var)) {
            arg0->unk10 = unk0;
            arg0->unk14 = arg1->unk8;
        }
    }
}

struct224 *func_151D2F00(void *arg0, s32 arg1, u8 arg2, struct224 *arg3) {
    struct224 *tmp = func_15167A68(0x3E, arg3, arg1 + 0x30, 1, arg2, 1);
    
    if (tmp == 0) {
        return 0;
    }
    
    memcpy(&tmp->unk10, arg0, 0x10);
    tmp->unk20 = 0;
    tmp->unk24 = 0;
    tmp->unk28 = 0;
    tmp->pad15[3] &= ~2;
    
    return tmp;
}
void func_151D2F90(struct102 *arg0) {
    u32 ptr;
    u8 t8, t9, t0, a1 = 0;
    u32 v1 = 0;
    u16 t8_val;
    u32 t1_val;

    ptr = *(u32 *)(arg0 + 0x10);
    t8 = *(u8 *)(arg0 + 0x18);
    a1 = t8 & 0x2;

    if (ptr != 0) {
        t8 = *(u8 *)(ptr + 4);
        a1 = ptr & 0x2;
        if (t8 != 0xFF) {
            t1_val = *(u32 *)(ptr + 0x1D4);
        }
    }

    t9 = *(u8 *)(arg0 + 0x14);
    t0 = *(u8 *)(ptr + 0x3B);

    if (t9 != t0) {
        t1_val = *(u32 *)(ptr + 0x1D4);
    }

    // .L151D2FD4:
    // Both paths converge here
    func_1516972C(arg0);
    goto L_end;

    // .L151D2FE8:
    // t1_val = *(u32 *)(ptr + 0x1D4);  // already loaded above

    // .L151D301C section:
    v1 = t8 & 0xFFFD;
    if (t1_val != 0) {
        *(u8 *)(arg0 + 0x18) = v1;
        t8 = *(u8 *)(ptr + 0x74);
        if ((t8 & 0xF) != 0xF) {
            *(u8 *)(arg0 + 0x18) = v1;
        }
    }

    // .L151D3088:
    t8 = *(u8 *)(arg0 + 0x18);
    if ((t8 & 1) != 0) {
        // t8 already loaded
        t8_val = *(u16 *)(arg0 + 0x16);
        // D_800BE9E4 is a function pointer table
        t1_val = D_800BE9E4[t9 & 0xFFFF];
        t9_val = t8_val - t1_val;
        *(u16 *)(arg0 + 0x16) = t9_val;
        t1_val = *(u16 *)(arg0 + 0x16);
        if (t1_val < 0) {
            t8 = *(u8 *)(arg0 + 0x18);
            // v0 = *(u8 *)(arg0 + 0x1C)
            if (*(u8 *)(arg0 + 0x1C) != 0xFF) {
                // D_8008FC58 is a function pointer table
                switch (*(u8 *)(arg0 + 0x1C)) {
                case 0:
                    D_8008FC58[0](arg0);
                    break;
                case 1:
                    D_8008FC58[1](arg0);
                    break;
                case 2:
                    D_8008FC58[2](arg0);
                    break;
                case 3:
                    D_8008FC58[3](arg0);
                    break;
                case 4:
                    D_8008FC58[4](arg0);
                    break;
                case 5:
                    D_8008FC58[5](arg0);
                    break;
                case 6:
                    D_8008FC58[6](arg0);
                    break;
                case 7:
                    D_8008FC58[7](arg0);
                    break;
                case 8:
                    D_8008FC58[8](arg0);
                    break;
                case 9:
                    D_8008FC58[9](arg0);
                    break;
                case 10:
                    D_8008FC58[10](arg0);
                    break;
                case 11:
                    D_8008FC58[11](arg0);
                    break;
                case 12:
                    D_8008FC58[12](arg0);
                    break;
                case 13:
                    D_8008FC58[13](arg0);
                    break;
                case 14:
                    D_8008FC58[14](arg0);
                    break;
                case 15:
                    D_8008FC58[15](arg0);
                    break;
                default:
                    break;
                }
            }
        }
    }

    // .L151D30EC:
    if ((t8 & 2) != a1) {
        // v0 = *(u8 *)(arg0 + 0x19)
        // D_8008FC50 is a function pointer table
        switch (*(u8 *)(arg0 + 0x19)) {
        case 0:
            D_8008FC50[0](arg0);
            break;
        case 1:
            D_8008FC50[1](arg0);
            break;
        case 2:
            D_8008FC50[2](arg0);
            break;
        case 3:
            D_8008FC50[3](arg0);
            break;
        case 4:
            D_8008FC50[4](arg0);
            break;
        case 5:
            D_8008FC50[5](arg0);
            break;
        case 6:
            D_8008FC50[6](arg0);
            break;
        case 7:
            D_8008FC50[7](arg0);
            break;
        case 8:
            D_8008FC50[8](arg0);
            break;
        case 9:
            D_8008FC50[9](arg0);
            break;
        case 10:
            D_8008FC50[10](arg0);
            break;
        case 11:
            D_8008FC50[11](arg0);
            break;
        case 12:
            D_8008FC50[12](arg0);
            break;
        case 13:
            D_8008FC50[13](arg0);
            break;
        case 14:
            D_8008FC50[14](arg0);
            break;
        case 15:
            D_8008FC50[15](arg0);
            break;
        default:
            break;
        }
    }

    // .L151D30C8:
    // t7 = *(u8 *)(arg0 + 0x1B)
    // D_8008FC54 is a function pointer table
    switch (*(u8 *)(arg0 + 0x1B)) {
    case 0:
        D_8008FC54[0](arg0);
        break;
    case 1:
        D_8008FC54[1](arg0);
        break;
    case 2:
        D_8008FC54[2](arg0);
        break;
    case 3:
        D_8008FC54[3](arg0);
        break;
    case 4:
        D_8008FC54[4](arg0);
        break;
    case 5:
        D_8008FC54[5](arg0);
        break;
    case 6:
        D_8008FC54[6](arg0);
        break;
    case 7:
        D_8008FC54[7](arg0);
        break;
    case 8:
        D_8008FC54[8](arg0);
        break;
    case 9:
        D_8008FC54[9](arg0);
        break;
    case 10:
        D_8008FC54[10](arg0);
        break;
    case 11:
        D_8008FC54[11](arg0);
        break;
    case 12:
        D_8008FC54[12](arg0);
        break;
    case 13:
        D_8008FC54[13](arg0);
        break;
    case 14:
        D_8008FC54[14](arg0);
        break;
    case 15:
        D_8008FC54[15](arg0);
        break;
    default:
        break;
    }

    // .L151D30E8:
    // v0 = *(u8 *)(arg0 + 0x19)
    if (*(u8 *)(arg0 + 0x19) != 0xFF) {
        // D_8008FC4C is a function pointer table
        switch (*(u8 *)(arg0 + 0x19)) {
        case 0:
            D_8008FC4C[0](arg0);
            break;
        case 1:
            D_8008FC4C[1](arg0);
            break;
        case 2:
            D_8008FC4C[2](arg0);
            break;
        case 3:
            D_8008FC4C[3](arg0);
            break;
        case 4:
            D_8008FC4C[4](arg0);
            break;
        case 5:
            D_8008FC4C[5](arg0);
            break;
        case 6:
            D_8008FC4C[6](arg0);
            break;
        case 7:
            D_8008FC4C[7](arg0);
            break;
        case 8:
            D_8008FC4C[8](arg0);
            break;
        case 9:
            D_8008FC4C[9](arg0);
            break;
        case 10:
            D_8008FC4C[10](arg0);
            break;
        case 11:
            D_8008FC4C[11](arg0);
            break;
        case 12:
            D_8008FC4C[12](arg0);
            break;
        case 13:
            D_8008FC4C[13](arg0);
            break;
        case 14:
            D_8008FC4C[14](arg0);
            break;
        case 15:
            D_8008FC4C[15](arg0);
            break;
        default:
            break;
        }
    }

    // .L151D3124:
L_end:
    addiu , , 0x18;
    jr ;
}extern void (*D_8008FC5C[])(struct102 *);
extern void func_1514EDF0(struct102 *, void *);

void func_151D3130(struct102 *arg0) {
    struct224 *curr;
    struct224 *next;
    void (*func)(struct102 *);
    u32 neg_one;

    func = D_8008FC5C[S_U8(arg0, 0x1D)];
    if (func != NULL) {
        func(arg0);
    }

    neg_one = -1;
    curr = (struct224 *)S_PTR(arg0, 0x24);
    if (curr != NULL) {
        do {
            s8 unk2A = S_S8(curr, 0x2A);
            next = curr->unk40;
            if (neg_one != unk2A) {
                D_8008FC48[unk2A](curr, (struct_12b *)&curr->unk34);
            }
            S_S32(curr, 0x2C) = 0;
            func_1516972C(curr);
            curr = next;
        } while (curr != NULL);
    }

    func_1514EDF0(arg0, S_PTR(arg0, 0x10));
}

void func_151D31F4(struct102 *arg0) {
    func_151D3130(arg0);
    func_15169804(arg0);
}

void func_151D3220(struct102 *arg0) {
    func_151D3130(arg0);
    func_15169824(arg0);
}

void func_151D324C(struct224 *arg0, struct223 *arg1, u8 arg2) {
    if (arg2 == 0) {
        func_151D33FC(arg0, arg1);
        dummy: ;
    } else if (arg2 == 0x2D) {
        if (arg0->unk10 == arg1->unk0) {
            arg0->unk10 = arg1->unk4.w;
            arg0->unk14 = arg1->unk9;
        } else if (arg0->unk10 == arg1->unk4.w) {
            arg0->unk10 = arg1->unk0;
            arg0->unk14 = arg1->unk8;
        }
    }
    if (D_8008FC64[arg0->unk1D] != 0) {
        D_8008FC64[arg0->unk1D](arg0, arg1, arg2);
    }
}

void func_151D3308(struct224 *arg0) {
    struct224 *temp_v0;
    struct224 *temp_v1;

    temp_v0 = arg0->unk30;
    if (temp_v0 != 0) {
        arg0->unk40 = temp_v0->unk24;
        temp_v1 = temp_v0->unk24;
        if (temp_v1 != 0) {
            temp_v1->unk44 = arg0;
        } else {
            temp_v0->unk28 = arg0;
        }
        arg0->unk44 = 0;
        temp_v0->unk24 = arg0;
        temp_v0->unk20 += 1;
        arg0->unk30 = temp_v0;
    }
}

void func_151D3354(struct224 *arg0) {
    struct224 *temp_v0;
    struct224 *temp_v1;
    struct224 *temp_v2;

    if (arg0->unk30) {
        temp_v0 = arg0->unk30;
        if (temp_v1 = arg0->unk44) {
            temp_v1->unk40 = arg0->unk40;
        } else {
            temp_v0->unk24 = arg0->unk40;
        }

        if (temp_v2 = arg0->unk40) {
            temp_v2->unk44 = arg0->unk44;
        } else {
            temp_v0->unk28 = arg0->unk44;
        }

        temp_v0->unk20 -= 1;
    }
}

void func_151D33B8(struct224 *arg0) {
    while (arg0->unk20 > 0) {
        func_1516972C(arg0->unk24);
    };
}

void func_151D33FC(struct224 *arg0, struct223 *arg1) {
    s32 tmp0;
    s32 tmp1;
    s32 tmp2;
    s32 tmp3;

    tmp0 = arg0->unk10;
    tmp1 = arg0->unk14;
    tmp2 = arg1->unk4.ub;
    tmp3 = arg1->unk0;
    if ((tmp0 == tmp3) || (tmp2 == tmp1)) {
        func_1516972C(arg0);
    }
}

void func_151D343C(s32 arg0, u8 arg1) {
    struct_4b sp1C;
    sp1C = *(struct_4b *)D_800AB168;
    func_15169260(&sp1C, 1, arg0, arg1);
}

