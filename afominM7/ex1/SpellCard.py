from ex0.Card import Card


class SpellCard(Card):
    def __init__(self, name: str, cost: int, rarity: str, effect_type: str):
        super().__init__(name, cost, rarity)
        self.effect_type = effect_type
        self.type = 'Spell'

    def play(self, game_state: dict) -> dict:
        return {
            'card_played': self.name,
            'mana_used': self.cost,
            'effect': self.resolve_effect([])['effect_description']
        }

    def resolve_effect(self, targets: list) -> dict:
        effects = {
            "damage": "Deal 3 damage to target",
            "heal": "Restore 5 health",
            "buff": "Increase attack by 2"
        }
        return {
            "spell_name": self.name,
            "effect_description":
            effects.get(self.effect_type, "Magic effect resolved")
        }
