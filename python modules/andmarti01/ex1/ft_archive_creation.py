#!/usr/bin/env python3
# andmarti
# ft_archive_creation


def do_archive_creation(filename: str, data: str) -> None:
    print("=== CYBER ARCHIVES - PRESERVATION SYSTEM ===")
    print("")
    print("Initializing new storage unit: {filename}")
    file = open(filename, 'w', encoding="utf-8")
    print("Storage unit created successfully...")
    print("")
    print("Inscribing preservation data...")
    file.write(data)
    print(data)
    print("")
    print("Data inscription complete. Storage unit sealed.")
    file.close()
    print("Archive 'new_discovery.txt' ready for long-term preservation.")


if __name__ == "__main__":
    data: str = ""
    data += "{[}ENTRY 001{]} New quantum algorithm discovered\n"
    data += "{[}ENTRY 002{]} Efficiency increased by 347%\n"
    data += "{[}ENTRY 003{]} Archived by Data Archivist trainee\n"
    try:
        do_archive_creation("new_discovery.txt", data)
    except Exception as e:
        print(e)
