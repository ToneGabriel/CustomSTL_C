import os
import re

def cleanup_macro_backslashes(filepath: str, start_line: int, end_line: int):
    """
    Removes trailing backslashes and all spaces/tabs before them in the given
    range of lines. Useful for cleaning multiline macros before reformatting.
    """
    with open(filepath, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    # Validate range
    if start_line < 1 or end_line > len(lines) or start_line > end_line:
        raise ValueError("Invalid line range.")

    start_idx = start_line - 1
    end_idx = end_line

    # Regex: match spaces/tabs + optional backslash at line end
    cleanup_pattern = re.compile(r'[ \t]*\\\s*$')

    cleaned_lines = []
    for line in lines[start_idx:end_idx]:
        cleaned_line = cleanup_pattern.sub('', line.rstrip('\n'))  # remove backslash and trailing spaces
        cleaned_lines.append(cleaned_line)

    # Replace cleaned lines in the original list
    lines[start_idx:end_idx] = [l + '\n' for l in cleaned_lines]

    # Backup original file
    backup_path = filepath + '.bak'
    os.replace(filepath, backup_path)

    # Write modified file
    with open(filepath, 'w', encoding='utf-8') as f:
        f.writelines(lines)

    print(f"Cleaned lines {start_line}-{end_line} in '{filepath}' (removed '\\' and trailing spaces)")
    print(f"Backup saved as '{backup_path}'")


if __name__ == "__main__":
    print("=== Multiline Macro Backslash Cleaner ===")
    filepath = input("Enter path to C file: ").strip()
    start_line = int(input("Enter start line number: ").strip())
    end_line = int(input("Enter end line number: ").strip())

    cleanup_macro_backslashes(filepath, start_line, end_line)
