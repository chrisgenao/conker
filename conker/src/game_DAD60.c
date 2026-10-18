#include <ultra64.h>
#include "functions.h"
#include "variables.h"


// arg2 = arg0 x arg1 (vector cross product).
// The asm stores z (offset 8) before x (offset 0): that is IDO store scheduling, not
// source order -- the three assignments read in the natural x, y, z order.
void func_150AD8B0(f32 *arg0, f32 *arg1, f32 *arg2) {
    arg2[0] = (arg0[1] * arg1[2]) - (arg0[2] * arg1[1]);
    arg2[1] = (arg0[2] * arg1[0]) - (arg0[0] * arg1[2]);
    arg2[2] = (arg0[0] * arg1[1]) - (arg0[1] * arg1[0]);
}
