#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_150499A0(f32 arg0[4][4], f32 arg1[4][4]) {
    f32 m00 = arg0[0][0], m01 = arg0[0][1], m02 = arg0[0][2];
    f32 m10 = arg0[1][0], m11 = arg0[1][1], m12 = arg0[1][2];
    f32 m20 = arg0[2][0], m21 = arg0[2][1], m22 = arg0[2][2];
    f32 m30 = arg0[3][0], m31 = arg0[3][1], m32 = arg0[3][2];

    f32 det = m00 * (m11 * m22 - m12 * m21)
            - m01 * (m10 * m22 - m12 * m20)
            + m02 * (m10 * m21 - m11 * m20);
    f32 inv_det = 1.0f / det;

    arg1[0][0] = (m11 * m22 - m12 * m21) * inv_det;
    arg1[1][0] = (m12 * m20 - m22 * m10) * inv_det;
    arg1[2][0] = (m10 * m21 - m20 * m11) * inv_det;
    arg1[0][1] = (m02 * m21 - m22 * m01) * inv_det;
    arg1[1][1] = (m00 * m22 - m20 * m02) * inv_det;
    arg1[2][1] = (m01 * m20 - m21 * m00) * inv_det;
    arg1[0][2] = (m01 * m12 - m11 * m02) * inv_det;
    arg1[1][2] = (m02 * m10 - m00 * m12) * inv_det;
    arg1[2][2] = (m00 * m11 - m10 * m01) * inv_det;

    arg1[3][0] = -(m30 * arg1[0][0] + m31 * arg1[1][0] + m32 * arg1[2][0]);
    arg1[3][1] = -(m30 * arg1[0][1] + m31 * arg1[1][1] + m32 * arg1[2][1]);
    arg1[3][2] = -(m30 * arg1[0][2] + m31 * arg1[1][2] + m32 * arg1[2][2]);

    arg1[3][3] = 1.0f;
    arg1[0][3] = 0.0f;
    arg1[1][3] = 0.0f;
    arg1[2][3] = 0.0f;
}
