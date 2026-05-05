import idaapi
import idc
import re


def split_params(s):
    """Split parameter string by commas, respecting nested parentheses."""
    parts = []
    depth = 0
    current = []
    for ch in s:
        if ch == '(':
            depth += 1
            current.append(ch)
        elif ch == ')':
            depth -= 1
            current.append(ch)
        elif ch == ',' and depth == 0:
            parts.append(''.join(current).strip())
            current = []
        else:
            current.append(ch)
    if current:
        parts.append(''.join(current).strip())
    return parts


def split_ret_and_params(cleaned):
    """Split 'returnType (params)' handling nested parens in the param list."""
    # Find the last top-level '(' ... ')' pair
    depth = 0
    last_open = -1
    for i in range(len(cleaned) - 1, -1, -1):
        if cleaned[i] == ')':
            if depth == 0:
                end = i
            depth += 1
        elif cleaned[i] == '(':
            depth -= 1
            if depth == 0:
                last_open = i
                break
    if last_open == -1:
        return None, None
    ret_type = cleaned[:last_open].strip()
    params = cleaned[last_open + 1:end].strip()
    return ret_type, params

toml_path = idaapi.ask_file(False, "*.toml", "Select functions TOML file")
if not toml_path:
    print("No file selected.")
else:
    output_path = idaapi.ask_file(True, "*.h", "Save hooks header file")
    if not output_path:
        print("No output file selected.")
    else:
        functions = []
        in_functions = False

        with open(toml_path, "r") as f:
            for line in f:
                line = line.strip()
                if line == "[functions]":
                    in_functions = True
                    continue
                if in_functions:
                    if line.startswith("["):
                        break
                    m = re.match(r'^(0x[0-9A-Fa-f]+)\s*=\s*\{name\s*=\s*"([^"]+)"\}', line)
                    if m:
                        addr = int(m.group(1), 16)
                        name = m.group(2)
                        functions.append((addr, name))

        generated = 0

        with open(output_path, "w") as out:
            out.write("#pragma once\n\n")
            out.write('#include "generated/retip_config.h"\n')
            out.write('#include "generated/retip_init.h"\n')
            out.write("\n")
            out.write("#include <rex/cvar.h>\n")
            out.write('#include "tip_engine/rex_macros.h"\n')
            out.write('#include "tip_engine/Log.h"\n')
            out.write('#include "tip_engine/hooks.h"\n')
            out.write('#include "tip_engine/Overlays/DebugInfo.h"\n')
            out.write("\n")
            out.write("#include <rex/ppc/types.h>\n")
            out.write("#include <rex/logging.h>\n")
            out.write("\n")
            out.write("typedef uint32_t _DWORD;\n")
            out.write("typedef unsigned long long _QWORD;\n")
            out.write("typedef unsigned char _BYTE;\n")

            for addr, full_name in functions:
                # Strip "rex_" prefix for macro names
                if full_name.startswith("rex_"):
                    macro_name = full_name[4:]
                else:
                    macro_name = full_name

                # Get function type info from IDA
                func_type = idc.get_type(addr)

                ret_type = "void"
                params_str = ""
                arg_names = []

                if func_type:
                    # Parse type string, e.g. "int __cdecl(int a1, char *a2)"
                    # Remove calling convention keywords
                    cleaned = re.sub(r'\b(__cdecl|__stdcall|__fastcall|__thiscall|__usercall|__userpurge)\b', '', func_type).strip()
                    # Replace HRESULT with int
                    cleaned = re.sub(r'\bHRESULT\b', 'int', cleaned)
                    # Split return type and params handling nested parens
                    ret_type, params_raw = split_ret_and_params(cleaned)
                    if ret_type is not None:
                        # Skip variadic functions
                        if '...' in params_raw:
                            print(f"Warning: Variadic function {full_name} at {hex(addr)}, skipping")
                            out.write(f"// WARNING: Variadic function {full_name} at {hex(addr)}, skipped\n\n")
                            continue
                        # Extract argument names for forwarding, add synthetic names if missing
                        if params_raw and params_raw.lower() != "void":
                            new_params = []
                            for i, param in enumerate(split_params(params_raw)):
                                param = param.strip()
                                # Replace pointer/function-pointer types with int
                                if '*' in param or '(' in param:
                                    synthetic_name = f"a{i + 1}"
                                    arg_names.append(synthetic_name)
                                    new_params.append(f"int {synthetic_name}")
                                    continue
                                # Check if param has a name (more than just a type)
                                has_name = re.match(r'^.*[\s\*](\w+)\s*$', param)
                                if has_name:
                                    arg_names.append(has_name.group(1))
                                    new_params.append(param)
                                else:
                                    # No name, generate one
                                    synthetic_name = f"a{i + 1}"
                                    arg_names.append(synthetic_name)
                                    new_params.append(f"{param} {synthetic_name}")
                            params_str = ", ".join(new_params)
                        else:
                            params_str = ""
                else:
                    print(f"Warning: No type info for {full_name} at {hex(addr)}, skipping")
                    out.write(f"// WARNING: No type info for {full_name} at {hex(addr)}\n\n")
                    continue

                args_forward = ", ".join(arg_names)

                # Comment
                out.write(f"//{full_name}\n")

                # Extern import
                out.write(f"REX_PPC_EXTERN_IMPORT({macro_name});\n\n")

                # Function definition
                if params_str:
                    out.write(f"{ret_type} {macro_name}_Hook({params_str}) {{\n")
                else:
                    out.write(f"{ret_type} {macro_name}_Hook() {{\n")

                # FPS counter
                out.write(f'    auto fpshook = fpsManager.GetCreateCounter("{macro_name}");\n')
                out.write(f"    fpshook->Tick();\n\n")

                # Body
                if ret_type == "void":
                    if args_forward:
                        out.write(f"    rex::GuestToHostFunction<void>(__imp__{full_name}, {args_forward});\n")
                    else:
                        out.write(f"    rex::GuestToHostFunction<void>(__imp__{full_name});\n")
                else:
                    if args_forward:
                        out.write(f"    return rex::GuestToHostFunction<{ret_type}>(__imp__{full_name}, {args_forward});\n")
                    else:
                        out.write(f"    return rex::GuestToHostFunction<{ret_type}>(__imp__{full_name});\n")

                out.write("}\n\n")

                # Hook macro
                out.write(f"REX_PPC_HOOK({macro_name});\n\n")

                generated += 1

        print(f"Done: {generated} hooks generated -> {output_path}")