from ex0.Card import Card
from ex2.Combatable import Combatable
from ex2.Magical import Magical


class EliteCard(Card, Combatable, Magical):
    def __init__(self, name: str, cost: int, rarity: str,
                 attack_val: int, defense_val: int, magic_power: int):
        super().__init__(name, cost, rarity)
        self.attack_val = attack_val
        self.defense_val = defense_val
        self.magic_power = magic_power
        self.current_mana = 4

    def play(self, game_state: dict) -> dict:
        return {
            'card_played': self.name,
            'mana_used': self.cost,
            'effect': 'Elite hero enters the fray'
        }

    def attack(self, target) -> dict:
        return {'attacker': self.name, 'target': target,
                'damage': self.attack_val, 'combat_type': 'melee'}

    def defend(self, incoming_damage: int) -> dict:
        damage_taken = max(0, incoming_damage - self.defense_val)
        return {
            'defender': self.name,
            'damage_taken': damage_taken,
            'damage_blocked': self.defense_val,
            'still_alive': True
        }

    def get_combat_stats(self) -> dict:
        return {"attack": self.attack_val, "defense": self.defense_val}

    def cast_spell(self, spell_name: str, targets: list) -> dict:
        return {'caster': self.name, 'spell': spell_name,
                'targets': targets, 'mana_used': self.magic_power}

    def channel_mana(self, amount: int) -> dict:
        self.current_mana += amount
        return {'channeled': amount, 'total_mana': self.current_mana}

    def get_magic_stats(self) -> dict:
        return {"magic_power": self.magic_power,
                "current_mana": self.current_mana}
