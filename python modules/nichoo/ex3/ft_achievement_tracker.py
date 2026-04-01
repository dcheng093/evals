# Sets
# -  A set is an unordered collection with no duplicate elements.
#   Basic uses include membership testing and eliminating duplicate entries.
#   Set objects also support mathematical operations like
#   union, intersection, difference, and symmetric difference.
# - Curly braces or the set() function can be used to create sets.
#   Note: to create an empty set you have to use set(),
#   not {}; the latter creates an empty dictionary


class Player():
    def __init__(self, name: str) -> None:
        self._name = name
        self._achievements = set()

    def add_achievements(self,
                         achievements: list[str]) -> None:
        self._achievements = set(achievements)


def ft_achievement_tracker() -> None:
    alice = Player("alice")
    alice_achievements = ['first_kill',
                          'level_10',
                          'treasure_hunter',
                          'speed_demon']
    alice.add_achievements(alice_achievements)

    bob = Player("bob")
    bob_achievements = ['first_kill',
                        'level_10',
                        'boss_slayer',
                        'collector']
    bob.add_achievements(bob_achievements)

    charlie = Player("charlie")
    charlie_achievements = ['level_10',
                            'treasure_hunter',
                            'boss_slayer',
                            'speed_demon',
                            'perfectionist']
    charlie.add_achievements(charlie_achievements)

    print("=== Achievement Tracker System ===")
    print()
    print(f"Player alice achievements: {alice._achievements}")
    print(f"Player bob achievements: {bob._achievements}")
    print(f"Player charlie achievements: {charlie._achievements}")
    print()

    # Equal to set.union
    # - returns a set with elements from the set and all others
    unique_achievements = (alice._achievements |
                           bob._achievements |
                           charlie._achievements)
    print("=== Achievement Analytics ===")
    print(f"All unique achievements: {unique_achievements}")
    print(f"Total unique achievemtns: {len(unique_achievements)}")
    print()

    # Equal to set.intersection
    # - returns a set with elements common to the set and all others
    common_achievements = (alice._achievements &
                           bob._achievements &
                           charlie._achievements)

    # Set comprehension (like list comprehension)
    only_alice = {e for e in alice._achievements if
                  (e not in bob._achievements and
                   e not in charlie._achievements)}
    only_bob = {e for e in bob._achievements if
                (e not in alice._achievements and
                 e not in charlie._achievements)}
    only_charlie = {e for e in charlie._achievements if
                    (e not in alice._achievements and
                     e not in bob._achievements)}
    rare_achievements = only_alice | only_bob | only_charlie

    print(f"Common to all players: {common_achievements}")
    print(f"Rare achievements (1 player): {rare_achievements}")
    print()

    print(f"Alice vs Bob common: {alice._achievements & bob._achievements}")
    print(f"Alice unique: {alice._achievements - bob._achievements}")
    print(f"Bob unique: {bob._achievements - alice._achievements}")


if __name__ == "__main__":
    ft_achievement_tracker()
