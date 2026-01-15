#!/usr/bin/env python3
# andmarti
# https://www.youtube.com/watch?v=a_O1kI6B9Bc
# ft_crisis_response


def do_crisis_response(filename: str) -> None:
    content: str | None = None
    print(f"CRISIS ALERT: Attempting access to {filename}...")
    try:
        with open(filename, 'r', encoding="utf-8") as f:
            content = f.read()
        print(f"SUCCESS: Archive recovered - ``{content}''")
        print("STATUS: Normal operations resumed")
    except FileNotFoundError:
        print("RESPONSE: Archive not found in storage matrix")
        print("STATUS: Crisis handled, system stable")
    except PermissionError:
        print("RESPONSE: Security protocols deny access")
        print("STATUS: Crisis handled, security maintained")


if __name__ == "__main__":
    print("=== CYBER ARCHIVES - CRISIS RESPONSE SYSTEM ===")
    print("")
    try:
        do_crisis_response('lost_archive.txt')
        print("")
        do_crisis_response('classified_vault.txt')
        print("")
        do_crisis_response('standard_archive.txt')
        print("")
    except Exception as e:
        print(e)
    finally:
        print("All crisis scenarios handled successfully. Archives secure.")
