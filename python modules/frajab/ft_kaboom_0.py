import alchemy.grimoire

if __name__ == "__main__":
    result = alchemy.grimoire.light_spell_record(
      'Fantasy', 'Earth, wind and fire')
    print("=== Kaboom 0 ===\n"
          "Using grimoire module directly\n"
          "Testing record light spell: "
          f"{result}\n")
