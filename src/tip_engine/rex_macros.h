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

// Yoinked from https://github.com/twist84/halo3_cache_release_recomp/blob/06c7f0740d9bee47e2c0be047a5c7562fe9e1fa5/halo3/source/rex_macros.h
#pragma once
#include <rex/rex_app.h>
#include <rex/ppc.h>
#include <rex/runtime.h>
#include <rex/system/thread_state.h>
#include <rex/system/xthread.h>
#include "Log.h"

#include <type_traits>

#define REX_PPC_EXTERN_IMPORT(function) \
	REX_EXTERN(__imp__rex_##function)

#define REX_PPC_INVOKE(function, ...) \
	rex::ppc::GuestToHostFunction<function_return_t<decltype(function)>>(__imp__rex_##function, __VA_ARGS__)

#define REX_PPC_INVOKE2(return_type, function, ...) \
	rex::ppc::GuestToHostFunction<return_type>(__imp__rex_##function, __VA_ARGS__)

#define REX_PPC_HOOK(function) \
    REX_HOOK(rex_##function, function##_Hook)

#define REX_DATA_REFERENCE_DECLARE(address, type, name) \
	type& name = *reinterpret_cast<type*>(0x100000000 + address)

#define REX_DATA_REFERENCE_DECLARE_ARRAY(address, type, name, count) \
	type(&name)[count] = *reinterpret_cast<type(*)[count]>(0x100000000 + address)

#define REX_PPC_CONTEXT_REF(name) \
	auto current_thread = rex::system::XThread::GetCurrentThread(); \
	assert(current_thread != nullptr); \
	auto context = current_thread->thread_state()->context(); \
	assert(context != nullptr); \
	PPCContext& __restrict name = *context

#define REX_PPC_MEMBASE_PTR(name) \
auto* runtime = rex::Runtime::instance(); \
auto* memory = runtime->memory(); \
uint8_t* name = memory->virtual_membase()

template <typename t_type>
struct function_t;

template <typename t_return_type, typename... t_args>
struct function_t<t_return_type(t_args...)>
{
	using return_type = t_return_type;
};

template <typename t_return_type, typename... t_args>
struct function_t<t_return_type(*)(t_args...)>
{
	using return_type = t_return_type;
};

template <typename t_return_type, typename t_class, typename... t_args>
struct function_t<t_return_type(t_class::*)(t_args...)>
{
	using return_type = t_return_type;
};

template <typename t_return_type, typename t_class, typename... t_args>
struct function_t<t_return_type(t_class::*)(t_args...) const>
{
	using return_type = t_return_type;
};

template <typename t_function>
using function_return_t =
typename function_t<std::remove_cvref_t<t_function>>::return_type;
