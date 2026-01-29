#!/usr/bin/env python3
# andmarti
# ft_stream_management

import sys


def do_stream_management() -> None:
    print("=== CYBER ARCHIVES - COMMUNICATION SYSTEM ===")
    print("")
    # Input Stream active. Enter archivist ID: ARCH_7742
    arch_id = input("Input Stream active. Enter archivist ID: ")
    # Input Stream active. Enter status report: All systems nominal
    status = input("Input Stream active. Enter status report: ")
    print("")
    print(
        "{[}STANDARD{]} Archive status from",
        end="",
        file=sys.stdout)
    print(f" {arch_id}: {status}")
    print(
        "{[}ALERT{]} System diagnostic: Communication channels verified",
        file=sys.stderr)
    print(
        "{[}STANDARD{]} Data transmission complete",
        file=sys.stdout)
    print("")
    print("Three-channel communication test successful.")


if __name__ == "__main__":
    try:
        do_stream_management()
    except Exception as e:
        print(e)
