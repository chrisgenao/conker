#include <ultra64.h>
#include "functions.h"
#include "variables.h"


f32 func_150AD900(f32 *arg0, f32 *arg1) {
    return (arg0[0] * arg1[0]) + (arg0[1] * arg1[1]) + (arg0[2] * arg1[2]);
}

f32 func_150AD930(f32 *arg0) {
    return sqrtf((arg0[0] * arg0[0]) + (arg0[1] * arg0[1]) + (arg0[2] * arg0[2]));
}
