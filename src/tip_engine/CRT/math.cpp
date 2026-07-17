#include "crt.h"

inline float to_byteswapped_float(float f) {
    uint32_t i = std::byteswap(*reinterpret_cast<uint32_t*>(&f));
    return *reinterpret_cast<float*>(&i);
}

inline double to_byteswapped_double(double d) {
    uint64_t i = std::byteswap(*reinterpret_cast<uint64_t*>(&d));
    return *reinterpret_cast<double*>(&i);
}

/*
//double rex_mathSin_8292A588(double sinAngle)
REX_HOOK_RAW(rex_math_mathSin_8292A588)
{
    ctx.f1.f64 = std::asin(ctx.f1.f64);
}

//float mathATan2(double opposite, double adjacent)
REX_HOOK_RAW(rex_math_mathATan2_8292A6A0)
{
    ctx.f1.f64 = std::atan2(ctx.f1.f64, ctx.f2.f64);
}
*/

//void rex_avatarPosGet_821EBC08(int avInst, float *pos)
REX_HOOK_RAW(rex_avatarPosGet_821EBC08)
{
    uint32_t avInst = ctx.r3.u32;
    float* pos = reinterpret_cast<float*>(0x100000000ull + ctx.r4.u32);

    auto readFloat = [avInst](uint32_t offset) {
        return to_byteswapped_float(*reinterpret_cast<float*>(0x100000000ull + avInst + offset));
    };

    if (std::byteswap(*reinterpret_cast<uint32_t*>(0x100000000ull + avInst + 116)))
    {
        double v2 = readFloat(708);
        double v3 = readFloat(712);
        double v4 = (float)((float)(readFloat(692) + readFloat(676)) + readFloat(660));
        double v5 = (float)((float)(readFloat(696) + readFloat(680)) + readFloat(664));

        float pos0 = (float)((float)((float)(readFloat(688) + readFloat(672)) + readFloat(656)) * (float)0.0)
                   + readFloat(704);
        float pos1 = (float)((float)v4 * (float)0.0) + (float)v2;
        float pos2 = (float)((float)v5 * (float)0.0) + (float)v3;

        pos[0] = to_byteswapped_float(pos0);
        pos[1] = to_byteswapped_float(pos1);
        pos[2] = to_byteswapped_float(pos2);
    }
    else
    {
        // raw big-endian bit patterns copied through untouched, no byteswap needed
        pos[0] = *reinterpret_cast<float*>(0x100000000ull + avInst + 104);
        pos[1] = *reinterpret_cast<float*>(0x100000000ull + avInst + 108);
        pos[2] = *reinterpret_cast<float*>(0x100000000ull + avInst + 112);
    }
}