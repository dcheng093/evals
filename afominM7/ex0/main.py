from ex0.CreatureCard import CreatureCard


def main():
    print('=== DataDeck Card Foundation ===\n')

    print('Testing Abstract Base Class Design:\n')

    dragon = CreatureCard('Fire Dragon', 5, 'Legendary', 7, 5)

    print('CreatureCard Info:')
    print(dragon.get_card_info())

    mana = 6
    print(f'\nPlaying {dragon.name} with {mana} mana available:')
    print(f'Playable: {dragon.is_playable(mana)}')
    print(f'Play result: {dragon.play({"mana": mana})}')

    print(f'\n{dragon.name} attacks Goblin Warrior:')
    print(f"Attack result: {dragon.attack_target('Goblin Warrior')}")

    mana = 3
    print(f'\nTesting insufficient mana ({mana} available):')
    print(f'Playable: {dragon.is_playable(mana)}')
    print('\nAbstract pattern successfully demonstrated!')


if __name__ == '__main__':
    main()
