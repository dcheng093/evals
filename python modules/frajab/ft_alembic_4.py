import alchemy

if __name__ == "__main__":
    print("=== Alembic 4 ===\n"
          "Accessing the alchemy module using 'import alchemy'\n"
          f"Testing create_air: {alchemy.create_air()}\n"
          "This will raise an exception!\n"
          "Testing the hidden create_earth: ", end="")
    print(f"{alchemy.create_earth()}\n")
