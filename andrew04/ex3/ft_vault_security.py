#!/usr/bin/env python3
# andmarti
# ft_vault_security

def do_vault_security() -> None:
    content: str | None = None
    print("=== CYBER ARCHIVES - VAULT SECURITY SYSTEM ===")
    print("")
    print("Initiating secure vault access...")
    print("Vault connection established with failsafe protocols")
    print("")
    print("SECURE EXTRACTION:")
    with open("classified_data.txt", 'r', encoding="utf-8") as f:
        content = f.read()
    print(content)
    print("")
    print("SECURE PRESERVATION:")
    with open("security_protocols.txt", 'r', encoding="utf-8") as f:
        content = f.read()
    print(content)
    print("Vault automatically sealed upon completion")
    print("")
    print("All vault operations completed with maximum security.")


if __name__ == "__main__":
    try:
        do_vault_security()
    except Exception:
        print("files not in folder... use generator")
