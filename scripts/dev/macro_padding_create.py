import os

def align_macro_backslashes(filepath: str, start_line: int, end_line: int, extra_spaces: int = 4):
    """
    Aligns backslashes in a selected range of lines so that all '\' 
    are vertically aligned with the longest line + some extra spacing.
    """
    PAD_CHAR = ' '

    # Read file
    with open(filepath, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    # Validate line range
    if start_line < 1 or end_line > len(lines) or start_line > end_line:
        raise ValueError("Invalid line range.")

    start_idx = start_line - 1
    end_idx = end_line

    # Strip newline from target lines
    target_lines = [lines[i].rstrip('\n') for i in range(start_idx, end_idx)]

    # Find longest visible line
    max_length = max(len(line.expandtabs(4)) for line in target_lines)
    target_column = max_length + extra_spaces

    # Prepare aligned lines
    aligned_lines = []
    for line in target_lines:
        visible_length = len(line.expandtabs(4))
        pad_size = target_column - visible_length
        new_line = f"{line}{PAD_CHAR * pad_size}\\"
        aligned_lines.append(new_line)

    # Replace lines in original
    lines[start_idx:end_idx] = [l + '\n' for l in aligned_lines]

    # Backup file
    backup_path = filepath + '.bak'
    os.replace(filepath, backup_path)

    # Write new version
    with open(filepath, 'w', encoding='utf-8') as f:
        f.writelines(lines)

    print(f"Aligned backslashes for lines {start_line}-{end_line} in '{filepath}'")
    print(f"(Added {extra_spaces} extra spaces beyond longest line)")
    print(f"Backup saved as '{backup_path}'")


if __name__ == "__main__":
    print("=== Multiline Macro Backslash Aligner ===")
    filepath = input("Enter path to C file: ").strip()
    start_line = int(input("Enter start line number: ").strip())
    end_line = int(input("Enter end line number: ").strip())
    extra_spaces = input("Extra spaces before backslash (default 4): ").strip()
    extra_spaces = int(extra_spaces) if extra_spaces else 4

    align_macro_backslashes(filepath, start_line, end_line, extra_spaces)
