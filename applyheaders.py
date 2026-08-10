import os
import re

LICENSE_HEADER = """/**
******************************************************************************
* ReTiP: Viva Pinata Recompiled                                              *
******************************************************************************
* Copyright (c) 2026 SolarCookies. Licensed under custom noncommercial terms.
*
* This software is licensed for non-commercial, private, and educational use 
* only. You may modify, rewrite, and optimize this code provided that full 
* attribution is given to the original authors listed on the project repository. 
* Commercial use is prohibited.
******************************************************************************
*/
"""

TARGET_EXTENSIONS = ('.cpp', '.h', '.hpp', '.cc')

HEADER_MARKER = "ReTiP: Viva Pinata Recompiled"

EXISTING_HEADER_PATTERN = re.compile(
    r"/\*(?:(?!\*/).)*?" + re.escape(HEADER_MARKER) + r"(?:(?!\*/).)*?\*/[ \t]*\r?\n?\s*",
    re.DOTALL
)

def apply_headers(target_directory):
    added = 0
    updated = 0
    unchanged = 0

    for root, _, files in os.walk(target_directory):
        for file in files:
            if not file.endswith(TARGET_EXTENSIONS):
                continue

            file_path = os.path.join(root, file)
            with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read()

            body, found = EXISTING_HEADER_PATTERN.subn("", content)
            if found:
                new_content = LICENSE_HEADER + "\n" + body
                if new_content == content:
                    print(f"[-] Skipping (Header up to date): {file_path}")
                    unchanged += 1
                    continue
                print(f"[~] Updating header in: {file_path}")
                updated += 1
            else:
                print(f"[+] Prepending header to: {file_path}")
                new_content = LICENSE_HEADER + "\n" + content
                added += 1

            with open(file_path, 'w', encoding='utf-8') as f:
                f.write(new_content)

    print(f"\n[!] Finished processing. Added {added}, updated {updated}, "
          f"already up to date {unchanged}.")

if __name__ == "__main__":
    current_dir = os.getcwd()
    apply_headers(current_dir)
