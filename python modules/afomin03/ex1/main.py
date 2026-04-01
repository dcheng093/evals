from ex0.CreatureCard import CreatureCard
from ex1.SpellCard import SpellCard
from ex1.ArtifactCard import ArtifactCard
from ex1.Deck import Deck


def main():
    print("=== DataDeck Deck Builder ===")
    print("\nBuilding deck with different card types...\n")

    deck = Deck()
    deck.add_card(SpellCard("Lightning Bolt", 3, "Common", "damage"))
    deck.add_card(ArtifactCard("Mana Crystal", 2,
                               "Rare", 3, "+1 mana per turn"))
    deck.add_card(CreatureCard("Fire Dragon", 5, "Legendary", 7, 5))
    deck.shuffle
    print(f"Deck stats: {deck.get_deck_stats()}")

    print("\nDrawing and playing cards:\n")
    mana = 20
    for _ in range(3):
        card = deck.draw_card()
        print(f"Drew: {card.name} ({card.type})")
        print(f"Play result: {card.play({'mana': mana})}\n")

    print("Polymorphism in action: Same interface, different card behaviors!")


if __name__ == "__main__":
    main()
