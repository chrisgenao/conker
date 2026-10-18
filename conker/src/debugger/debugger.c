#include <ultra64.h>

#include "functions.h"
#include "variables.h"


void func_16000000(void) {
    func_160012B0(278, &D_160046AC);
}

s32 func_16000028(void) {
    if (D_16003890 & 0xC000) {
        D_16003AF4 = 1;
        return 3;
    }
    return 0;
}

void func_16000058(void) {
    s32 i;
    s32 phi_s2;

    func_16001338(255, 255, 255);
    func_160012B0(44, &D_160046D0); // "MAIN MENU"
    phi_s2 = 108;
    for(i = 0; i < 2; i++) {
        if (D_16003B1C == i) {
            func_16001338(255, 0, 0);     // red
        } else {
            func_16001338(255, 255, 255); // white
        }
        func_160012B0(phi_s2, D_16003B20[i]);
        phi_s2 += 32;
    }
    if (D_16003B1C == 2) {
        func_16001338(255, 0, 0);     // red
    } else {
        func_16001338(255, 255, 255); // white
    }
    if (D_16003AF0 != 0) {
        if ((D_1600389C->unk120 == 32) && (D_160038A4 == 0)) {
            func_160012B0(phi_s2, &D_160046DC);
        } else if (D_16003AF0 != 0) {
            func_160012B0(phi_s2, &D_160046E8);
        }
    } else {
        func_160012B0(phi_s2, &D_160046F4); // "RETRY CODE"
    }
    func_16001338(255, 255, 255);
    func_160012B0(611, &D_16004700); // "Version"
    func_16001044(619, 1, 163);
    func_160012B0(643, &D_16004708); // "Built"
    func_160012B0(651, &D_16004710); // "Dec 19 2000"
    func_160012B0(663, &D_1600471C); // "09:57:42"
}

s32 func_16000224(void) {
    s32 res = 0;

    if (D_16003890 & 0x40000) { // D_JPAD is 0x0400
        D_16003B1C -= 1;
        res = 1;
    }
    if (D_16003890 & 0x80000) { // U_JPAD is 0x0800
        D_16003B1C += 1;
        res = 1;
    }
    if (D_16003B1C >= 3) {
        D_16003B1C = 0;
    }
    if (D_16003B1C < 0) {
        D_16003B1C = 2;
    }
    if (D_16003890 & A_BUTTON) {
        switch(D_16003B1C) {
            case 0:
                res = 3;
                D_16003AF4 = 2;
                break;
            case 1:
                res = 3;
                D_16003AF4 = 3;
                break;
            case 2:
                res = 4;
                break;
        }
    }
    return res;
}

void func_16000304(void) {
}

void func_1600030C(void) {
}

void func_16000314(void) {
    switch(D_16003B28) {
        case 0:
            func_16000424(D_1600389C);
            func_160006CC((u32 *)D_1600389C);
            break;
        case 1:
        case 2:
            func_16000590(D_1600389C);
            break;
    }
}

s32 func_16000384(void) {
    s32 res = 0;

    if (D_16003890 & (R_CBUTTONS | D_CBUTTONS)) {
        D_16003B28 += 1;
        if (D_16003B28 >= 3) {
            D_16003B28 = 0;
        }
        return 3;
    }
    if (D_16003890 & (L_CBUTTONS | U_CBUTTONS)) {
        D_16003B28 -= 1;
        if (D_16003B28 < 0) {
            D_16003B28 = 2;
        }
        return 3;
    }
    if (D_16003890 & B_BUTTON) {
        D_16003AF4 = 1;
        res = 3;
    }
    return res;
}

void func_16000424(struct118 *arg0) {
    // TODO is this a RGB struct?
    u32 tmp0;
    u32 tmp1;
    s32 pad;

    func_16001338(255, 255, 255);
    func_160012B0(35, &D_16004728);     // "Pc"
    func_16001044(43, 0, arg0->unk11C);
    func_160012B0(67, &D_1600472C);     // "Cause"
    func_16001044(75, 0, arg0->unk120);
    func_16001338(128, 128, 255);
    tmp0 = arg0->unk120;
    tmp1 = (tmp0 >> 2) & 0xF;

    func_160012B0(107, D_16003848[tmp1]);
    if (tmp1 == 11) {
        func_16001044(111, 1, (tmp0 >> 28) & 3);
    }
    func_16001338(255, 255, 255);
    func_160012B0(131, &D_16004734);      // "Sr"
    func_16001044(139, 0, arg0->unk118);
    func_160012B0(163, &D_16004738);      // "Badvadr"
    func_16001044(171, 0, arg0->unk124);
    func_160012B0(195, &D_16004740);      // "Thread"
    func_16001044(203, 1, arg0->unk14);
    if (D_160038A4 != 0) {
        func_160012B0(52, &D_16004748);   // "Lockup_Now"
    }
}

// prints labeled register/memory values from crash dump struct
void func_16000590(struct118 *arg0) {
    s32 flags = *(s32 *)((u8 *)arg0 + 0x12C);
    s32 bit = (u32)flags >> 12;
    s32 idx = 0;
    s32 pos = 0x2C;
    s32 base;
    s32 start;

    func_160012B0(3, &D_160047A4);
    func_16001044(10, 0, flags);

    while (idx < 6) {
        if (bit & 1) {
            func_160012B0(pos, D_16003B30[idx]);
            pos += 0x20;
        }
        idx++;
        bit >>= 1;
    }

    if (D_16003B28 == 1) {
        pos = 0xC3;
        start = 0x10;
    } else {
        pos = 0x6C;
        start = 0x4C;
    }
    idx = 0;
    base = start;
    while (idx < 0x10) {
        func_160012B0(pos, &D_160047AC);
        func_16001044(pos + 2, 1, base);
        func_16001044(pos + 5, 2, *(s32 *)((u8 *)arg0 + base * 4 + 4));
        idx++;
        base++;
        arg0 = (struct118 *)((u8 *)arg0 + 8);
        pos += 0x20;
    }
}

// prints labeled register values from D_160037F0 table
void func_160006CC(u32 *arg0) {
    u8 *table = D_160037F0;
    u8 buf[4];
    s32 pos = 0x123;

    *(u32 *)buf = D_16003B48;
    func_16001338(0xC0, 0xC0, 0xFF);
    buf[0] = table[0];

    while (buf[0] != 0) {
        buf[1] = table[1];
        func_160012B0(pos, buf);
        pos += 3;
        func_16001044(pos, 0, arg0[table[2] + 1]);
        pos += 0xD;
        table += 3;
        buf[0] = table[0];
    }
}
// crash debugger memory/stack dump display
void func_1600078C(void) {
    u32 *base = (u32 *)D_1600389C->unkF4;
    u32 row_index = D_16003B4C;
    u32 *ptr = base + row_index;
    s32 screen_row = 0x61;
    s32 col;
    u32 value;

    if (((u32)ptr & 3U) || (u32)ptr < 0x80000000U || (u32)ptr >= 0x80800001U) {
        return;
    }

    func_16001338(0, 0xFF, 0);  // green
    func_160012B0(0xB, &D_160047B0[0]);

    if (row_index == 0) {
        func_16001338(0xFF, 0, 0);  // red
    } else if ((u32)ptr >= (u32)&D_8002D4B0 && (u32)ptr < (u32)&D_8002D4B0 + 0x400) {
        func_16001338(0x80, 0x80, 0xFF);  // purple
    } else if ((u32)ptr >= (u32)&D_8002D8B0 && (u32)ptr < (u32)&D_8002D8B0 + 0x4000) {
        func_16001338(0xFF, 0x80, 0x80);  // light red
    } else {
        func_16001338(0xFF, 0xFF, 0xFF);  // white
    }

    col = 0;
    do {
        func_16001044(screen_row, 0, (s32)ptr);
        func_160012B0(screen_row + 8, &D_160047BC[0]);
        value = *ptr;

        if ((value >> 24) == 0x80) {
            func_16001338(0x80, 0x80, 0xFF);
        } else if ((value >> 24) == 0x15) {
            func_16001338(0xFF, 0, 0);
        } else if ((value >> 24) == 0x16) {
            func_16001338(0x80, 0xFF, 0x80);
        } else if ((value >> 24) == 0x10) {
            func_16001338(0xFF, 0, 0);
        } else {
            func_16001338(0xFF, 0xFF, 0xFF);
        }

        func_16001044(screen_row + 0xC, 0, value);
        func_160012B0(screen_row + 0x16, &D_160047C0[0]);
        func_16001338(0xFF, 0xFF, 0xFF);
        func_16001044(screen_row + 0x16, 1, value);

        if ((u32)ptr >= (u32)&D_8002D4B0 && (u32)ptr < (u32)&D_8002D4B0 + 0x400) {
            func_16001338(0x80, 0x80, 0xFF);
        } else if ((u32)ptr >= (u32)&D_8002D8B0 && (u32)ptr < (u32)&D_8002D8B0 + 0x4000) {
            func_16001338(0xFF, 0x80, 0x80);
        } else {
            func_16001338(0xFF, 0xFF, 0xFF);
        }

        screen_row += 0x20;
        col++;
    } while (col != 0x16);

    ptr += 1;
}
s32 func_16000A5C(void) {
    s32 res = 0;

    if ((D_160036F3 >= 41) || (D_16003890 & U_CBUTTONS)) {
        D_16003B4C -= 1;
        if (D_16003B4C < 0) {
            D_16003B4C = 0;
        } else {
            res = 3;
        }
    } else if ((D_160036F3 < -40) || (D_16003890 & D_CBUTTONS)) {
        D_16003B4C += 1;
        if (D_16003B4C >= 201) {
            D_16003B4C = 200;
        }
        res = 3;
    }
    if ((D_16003890 & B_BUTTON)) {
        D_16003AF4 = 1;
        res = 3;
    }
    return res;
}

// called from func_10007DAC
#pragma GLOBAL_ASM("asm/nonmatchings/debugger/debugger/func_16000B14.s")
void func_16000F8C(s32 arg0, f32 arg1) {
    s32 sp54;
    u8 sp28[8];
    u32 bits;
    u32 temp_t9;

    if ((arg0 >= (D_160038A0 << 5)) && (arg0 < 0x341)) {
        bits = *(u32 *)&arg1;
        sp54 = (s32)bits;
        temp_t9 = (bits & 0x7F800000u) >> 23;
        if (((temp_t9 == 0) || (temp_t9 >= 0xFFU)) && ((sp54 * 2) != 0)) {
            func_160012B0(arg0, &D_160047D0);
            return;
        }
        func_16001B34(arg0, sp28, &D_160047D4, &D_160047DC, (f64)arg1);
        func_160012B0(arg0, sp28);
    }
}

// prints a value at screen position: mode 0=hex, 1=signed decimal, 2=float
void func_16001044(s32 arg0, s32 arg1, u32 arg2) {
    s32 fb;
    s32 mode = arg1;
    u32 value = arg2;
    s32 val = (s32)value;
    s32 i;
    s32 pos;
    s32 started;
    s32 digit;
    u32 pow10;

    if ((arg0 < (D_160038A0 << 5)) || (arg0 >= 0x341)) {
        return;
    }
    fb = func_1600160C(arg0);

    if (mode == 0) {
        // hex: 8 digits (all drawn at fb + 0x70 in the original)
        pos = fb + 0x70;
        for (i = 0; i < 8; i++) {
            s32 nyb = value & 0xF;
            s32 c = nyb < 10 ? nyb + '0' : nyb + 'A' - 10;
            func_160014F0(pos, c);
            value >>= 4;
        }
        return;
    } else if (mode == 1) {
        // signed decimal
        pos = fb;
        started = 0;
        if (val < 0) {
            pos = func_160014F0(fb, '-');
            val = -val;
        }
        if (val == 0) {
            pos = func_160014F0(pos, '0');
            return;
        }
        for (i = 9; i >= 0; i--) {
            pow10 = D_16003B50[i];
            digit = val / pow10;
            val = val % pow10;
            if (digit != 0 || started) {
                started = 1;
                pos = func_160014F0(pos, (u8)(digit + '0'));
            }
        }
        return;
    } else if (mode == 2) {
        // float
        u32 exp = (value & 0x7F800000u) >> 23;
        if (exp == 0xFF) {
            // Inf or NaN
            func_160012B0(arg0, &D_160047E4[0]);
            return;
        }
        if (exp == 0 && (value << 9) != 0) {
            // denormal
            func_160012B0(arg0, &D_160047E4[0]);
            return;
        }
        {
            u8 buf[32];
            func_16001B34(buf, &D_160047E8[0], &D_160047F0[0], &D_160047F4[0], (double)(f32)value);
            func_160012B0(arg0, buf);
        }
        return;
    }
    // invalid mode: nothing printed
}

void func_160012B0(s32 arg0, u8 *arg1) {
    if (arg1 && (arg0 >= (D_160038A0 << 5)) && (arg0 < 833)) {
        s32 fb = func_1600160C(arg0);
        while (*arg1 != 0) {
            fb = func_160014F0(fb, *arg1 & 0xFF);
            *arg1++;
        }
    }
}
// convert rgb to rgba16
void func_16001338(u8 arg0, u8 arg1, u8 arg2) {
    D_1600388C = ((arg0 & 0xF8) << 8) | ((arg1 & 0xF8) << 3) | ((arg2 & 0xF8) >> 2) | 1;
}

// draw filled rectangle (inclusive 16-bit coords) with D_1600388C color
void func_16001390(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 fb_base;
    s16 w;
    s16 h;
    u16 *dst;

    if (arg2 < arg0) {
        return;
    }
    if (arg3 < arg1) {
        return;
    }
    if (arg0 < 0) {
        return;
    }
    if (arg1 < 0) {
        return;
    }
    fb_base = func_1600160C(0);
    w = (arg2 + 1) - arg0;
    h = (arg3 + 1) - arg1;
    if (h <= 0) {
        return;
    }
    dst = (u16 *)(fb_base + (arg1 * D_160038A8 + arg0) * 2);
    do {
        s32 i;
        u16 *p = dst;
        for (i = 0; i < w; i++) {
            *p++ = D_1600388C;
        }
        h--;
        dst += D_160038A8;
    } while (h > 0);
}

// renders an 8x8 font character to the framebuffer as RGBA16 pixels
s32 func_160014F0(s32 fb, u8 ch) {
    u16 color = D_1600388C;
    u8 *font;
    u16 *dst = (u16 *)fb;
    s32 row;
    u8 byte;

    if (ch < 0x20) {
        ch = 0x20;
    }
    font = &D_16003CE0[(ch - 0x20) * 8];

    for (row = 0; row < 8; row++) {
        s32 bit;
        byte = *font++;
        for (bit = 0; bit < 8; bit++) {
            *dst++ = (byte & 0x80) ? color : 1;
            byte <<= 1;
        }
        dst += (D_160038A8 - 8);
    }
    return fb + 0x10;
}

// splat into framebuffer
s32 func_1600160C(s32 arg0) {
    s32 var_v0 = arg0 & 0xFFE0;
    s32 var_v1 = var_v0;
    s32 off;

    if (D_160038A8 != 0x124) {
        var_v1 = (var_v0 >> 2) + var_v0;
    }
    off = ((var_v1 >> 2) * (D_160038A8 << 1)) + ((arg0 & 0x1F) * 0x10) + (D_160038A8 * 4) + 0x10;
    return D_8002AAE8[D_16003888] + off;
}

// clears framebuffer area in 16-byte chunks; contains delay slot
void func_16001678(void) {
    u8 *fbp = D_8002AAE8[D_16003888];
    s32 val = D_160038A8 == 0x124 ? 0xD7 : 0x108;
    u32 end = (u32)fbp + ((u32)((s32)D_160038A8 >> 1) * (u32)val * 4);

    if ((u32)fbp < end) {
        do {
            fbp += 0x10;
            ((u32 *)fbp)[-4] = 0x10001;
            ((u32 *)fbp)[-3] = 0x10001;
            ((u32 *)fbp)[-2] = 0x10001;
            ((u32 *)fbp)[-1] = 0x10001;
        } while ((u32)fbp < end);
    }
}

s32 func_160016F4(s32 arg0) {
    return arg0;
}
