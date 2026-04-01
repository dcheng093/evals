from ex0.Card import Card


class ArtifactCard(Card):
    def __init__(self, name: str, cost: int, rarity: str,
                 durability: int, effect: str):
        super().__init__(name, cost, rarity)
        self.type = 'Artifact'
        self.durability = durability
        self.effect_description = effect

    def play(self, game_state: dict) -> dict:
        return {
            'card_played': self.name,
            'mana_used': self.cost,
            'effect': f"Permanent: {self.effect_description}"
        }

    def activate_ability(self) -> dict:
        self.durability -= 1
        return {"action": "Ability activated",
                "remaining_durability": self.durability}
