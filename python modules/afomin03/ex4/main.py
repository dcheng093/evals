from ex4.TournamentCard import TournamentCard
from ex4.TournamentPlatform import TournamentPlatform


def main():
    print("=== DataDeck Tournament Platform ===")
    platform = TournamentPlatform()

    dragon = TournamentCard("dragon_001", "Fire Dragon", 5, "Legendary", 7)
    wizard = TournamentCard("wizard_001", "Ice Wizard", 4, "Rare", 5)

    print("Registering Tournament Cards...")
    for c in [dragon, wizard]:
        platform.register_card(c)
        stats = c.get_tournament_stats()
        print(f"{c.name} (ID: {stats['id']}):")
        print("- Interfaces: [Card, Combatable, Rankable]")
        print(f"- Rating: {stats['rating']}")
        print(f"- Record: {stats['record']}")

    print("\nCreating tournament match...")
    match = platform.create_match("dragon_001", "wizard_001")
    print(f"Match result: {match}")

    print("\nTournament Leaderboard:")
    for i, entry in enumerate(platform.get_leaderboard(), 1):
        print(f"{i}. {entry}")

    print("\nPlatform Report:")
    print(platform.generate_tournament_report())
    print("\n=== Tournament Platform Successfully Deployed! ===")


if __name__ == "__main__":
    main()
