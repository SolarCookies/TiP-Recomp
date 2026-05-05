import idaapi
import idc
import re

toml_path = idaapi.ask_file(False, "*.toml", "Select functions TOML file")
if not toml_path:
    print("No file selected.")
else:
    renamed = 0
    skipped = 0
    in_functions = False

    with open(toml_path, "r") as f:
        for line in f:
            line = line.strip()
            if line == "[functions]":
                in_functions = True
                continue
            if in_functions:
                if line.startswith("["):
                    break  # entered a different section
                m = re.match(r'^(0x[0-9A-Fa-f]+)\s*=\s*\{name\s*=\s*"([^"]+)"\}', line)
                if m:
                    addr = int(m.group(1), 16)
                    name = m.group(2)
                    if idc.set_name(addr, name, idc.SN_CHECK):
                        renamed += 1
                    else:
                        print(f"Failed to rename {hex(addr)} -> {name}")
                        skipped += 1

    print(f"Done: {renamed} renamed, {skipped} failed.")