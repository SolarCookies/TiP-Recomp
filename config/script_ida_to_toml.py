import idaapi
import idautils
import idc

functions = []

for func_addr in idautils.Functions():
    func_name = idc.get_func_name(func_addr)
    if func_name.startswith("rex_"):
        functions.append({
            "address": func_addr,
            "name": func_name
        })

print("Found functions:")
for func in functions:
    print(f"{hex(func['address']).upper().replace('X', 'x')} = {{name = \"{func['name']}\"}}")