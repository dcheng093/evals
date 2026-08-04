if __name__ == "__main__":
    print("=== Kaboom 1 ===\n"
          "Access to alchemy/grimoire/dark_spellbook.py directly\n"
          "Test import now - THIS WILL RAISE AN UNCAUGHT EXCEPTION")
    from alchemy.grimoire.dark_spellbook import dark_spell_record
    dark_spell_record('Fantasy', 'Frogs, Candy and Chocolate')
