from ex2.EliteCard import EliteCard


def main():
    print("=== DataDeck Ability System ===")

    print("EliteCard capabilities:")
    print("- Card: ['play', 'get_card_info', 'is_playable']")
    print("- Combatable: ['attack', 'defend', 'get_combat_stats']")
    print("- Magical: ['cast_spell', 'channel_mana', 'get_magic_stats']")

    hero = EliteCard("Arcane Warrior", 4, "Epic", 5, 3, 4)

    print(f"\nPlaying {hero.name} (Elite Card):")

    print("Combat phase:")
    print(f"Attack result: {hero.attack('Enemy')}")
    print(f"Defense result: {hero.defend(5)}")

    print("\nMagic phase:")
    print(f"Spell cast: {hero.cast_spell('Fireball', ['Enemy1', 'Enemy2'])}")
    print(f"Mana channel: {hero.channel_mana(3)}")

    print("\nMultiple interface implementation successful!")


if __name__ == "__main__":
    main()
