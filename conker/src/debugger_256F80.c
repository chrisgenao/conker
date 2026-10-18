#include <ultra64.h>

#include "functions.h"
#include "variables.h"


// sends controller status command and reads results via SI DMA
s32 func_16001700(void) {
    s32 ret;

    if (__osContLastCmd != 1) {
        func_160018BC();
        func_160019A8(OS_WRITE, __osContPifRam);
        {
            u32 count = osGetCount();
            u32 deadline = count + 0x30D40;
            count = osGetCount();
            while (count < deadline) {
                func_160016F4(count);
                count = osGetCount();
            }
            func_160016F4(count);
        }
    }

    // fill PIF RAM with 0xFF up to __osContLastCmd
    {
        u32 *pif = (u32 *)__osContPifRam;
        u32 *end = (u32 *)&__osContLastCmd;
        while (pif < end) {
            *pif++ = 0xFFFFFFFF;
        }
    }

    D_80042A4C = 0;
    ret = func_160019A8(OS_READ, __osContPifRam);
    __osContLastCmd = 1;

    {
        u32 count = osGetCount();
        u32 deadline = count + 0xC3500;
        count = osGetCount();
        while (count < deadline) {
            func_160016F4(count);
            count = osGetCount();
        }
        func_160016F4(count);
    }

    return ret;
}

// copies PIF controller data into controller structs
void func_16001830(void *arg0) {
    u8 *pif = __osContPifRam;
    u8 *out = arg0;
    s32 count = 0;
    u8 maxc = __osMaxControllers;
    u8 sp6;
    u16 sp8;
    u8 spA;
    u8 spB;

    if ((s32)maxc > 0) {
        do {
            *(u32 *)out = *(u32 *)pif;
            *(u32 *)(out + 4) = *(u32 *)(pif + 4);
            if (((s32)(sp6 >> 4) & 0xC) == 0) {
                out[4] = (s8)(((s32)(sp6 >> 4) & 0xC));
                *(u16 *)out = sp8;
                out[2] = spA;
                out[3] = spB;
            }
            count++;
            pif += 8;
            out += 6;
        } while (count < maxc);
    }
}

// clears PIF RAM up to __osContLastCmd, then builds controller read command block
void func_160018BC(void) {
    u32 *p = (u32 *)(__osContPifRam + 4);
    u32 *end = (u32 *)&__osContLastCmd;
    u8 cmd[8];
    u8 *dst = __osContPifRam;
    s32 i;

    do {
        p--;
        *p = 0;
        p++;
    } while (p < end);

    *(u32 *)(__osContPifRam + 0x3C) = 1;

    cmd[0] = 0xFF;
    cmd[1] = 1;
    cmd[2] = 4;
    cmd[3] = 1;
    cmd[4] = 0xFF;
    cmd[5] = 0xFF;
    cmd[6] = 0xFF;
    cmd[7] = 0xFF;

    if (__osMaxControllers > 0) {
        u8 *slot = cmd;
        i = 0;
        do {
            u32 w0 = *(u32 *)slot;
            u32 w1 = *(u32 *)(slot + 4);
            i++;
            dst += 8;
            *(u32 *)(dst - 8) = w0;
            *(u32 *)(dst - 4) = w1;
        } while (i < __osMaxControllers);
    }
    dst[0] = 0xFE;
}

// another __osSiDeviceBusy function
s32 func_16001984()
{
    register u32 stat = IO_READ(SI_STATUS_REG);
    if (stat & (SI_STATUS_DMA_BUSY | SI_STATUS_RD_BUSY))
        return 1;
    return 0;
}

// very similar to __osSiRawStartDma
s32 func_160019A8(s32 direction, void *dramAddr) {
    if ((s32)dramAddr & 3) { // what is this checking?
        return -1;
    }
    if (func_16001984()) {
        return -1;
    }

    if (direction == OS_WRITE) {
        osWritebackDCache(dramAddr, 64);
    }

    IO_WRITE(SI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));

    if (direction == OS_READ) {
        IO_WRITE(SI_PIF_ADDR_RD64B_REG, 0x1FC007C0);
    } else {
        IO_WRITE(SI_PIF_ADDR_WR64B_REG, 0x1FC007C0);
    }
    if (direction == OS_READ) {
        osInvalDCache(dramAddr, 64);
    }

    return 0;
}

void func_16001A64(void) {
}

s32 func_16001A6C(f32 arg0) {
    s32 tmp = *(s32*) &arg0;

    if ((tmp * 2) == 0) {
        return 0;
    }
    tmp = (tmp & 0x7F800000) >> 0x17;
    if ((tmp <= 0) || (tmp >= 255)) {
        return 1;
    }
    return 0;
}
