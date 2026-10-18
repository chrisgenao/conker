#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void __osPiGetAccess(void);
extern void __osPiRelAccess(void);
extern s32 osPiRawReadIo(u32, void *);

s32 func_151EF040(s32 arg0, s32 *arg1) {
    s32 ret;

    __osPiGetAccess();
    ret = osPiRawReadIo(arg0, arg1);
    __osPiRelAccess();
    return ret;
}

f32 func_151EF080(f32 arg0) {
    return sqrtf(arg0);
}
