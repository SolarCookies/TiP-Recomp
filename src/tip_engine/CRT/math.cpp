/** 
******************************************************************************
* ReTiP: Viva Pinata Recompiled                                              *
******************************************************************************
* Copyright (c) 2026 SolarCookies. Licensed under custom noncommercial terms.
*
* This software is licensed for non-commercial, private, and educational use 
* only. You may modify, rewrite, and optimize this code provided that full 
* attribution is given to the original authors listed on the project repository. 
* Commercial use is prohibited.
*
* DISCLAIMER: This software is provided "as-is" without warranty of any kind. 
* This project is an unofficial fan translation layer and does NOT provide, 
* distribute, or package any copyrighted game assets, binaries, or media belonging 
* to Microsoft or Rare. Users must provide their own legally obtained game assets. 
* This software must not be used in any manner that violates Microsoft's copyrights.
* DO NOT REDISTRIBUTE GAME ASSETS OR PROMOTE PIRACY.
*
* AI USE GUIDELINES:
* This project is built with minimal AI usage. We may utilize basic inline code 
* suggestions or rely on AI assistance for debugging, but the vast majority of 
* this codebase is written by hand. We manually decompile functions,
* reverse engineer structs, and write hooks to ensure accuracy and maintainability.
*
* The core goal of ReTiP is not only to get the software running, but to 
* research, document, and learn exactly how the game operates under the hood so that 
* we can provide modding support. We do not support using AI for creative 
* task or problem solving. i.e asking an AI agent to "find a way to 
* make freecam work". Instead, AI should only be used for small, boilerplate tasks or
* parsing a 1000 line crash log to isolate an error. We actively encourage all project 
* contributors to avoid the use of AI agents entirely when writing code or decompiling functions.
*
* The truth of the matter is that AI when used currectly by people who understand the output
* can be incredibly useful just like intelisense, being able to press Tab to autocomplete a
* for loop can save time. However, AI is not a replacement for human understanding and
* should not be used to replace the process of learning and understanding how the game works.
*
* We strongly prefer the use of local models that do not harm the environment and 
* can run entirely on your own local hardware over cloud based AI services. Ultimately, 
* all pull requests and code contributions will be strictly reviewed by people who 
* understand the codebase and the game. If you list Claude or any other AI as a coauthor 
* or contributor, your PR will be rejected regardless of whether it works.
******************************************************************************
*/

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