#!/usr/bin/env python3
# andmarti
# ft_ancient_text


def do_ancient_text(filename: str):
    print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===")
    print("")
    print("Accessing Storage Vault: ancient_fragment.txt")
    file = open(filename, 'r', encoding="utf-8")
    print("Connection established...")
    data = file.read()
    print("")
    print("RECOVERED DATA:")
    file.close()
    print(data)
    print("")
    print("Data recovery complete. Storage unit disconnected.")


if __name__ == "__main__":
    try:
        do_ancient_text("ancient_fragment.txt")
    except Exception:
        print("ERROR: Storage vault not found.")
