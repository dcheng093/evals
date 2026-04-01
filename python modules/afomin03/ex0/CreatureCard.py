from ex0.Card import Card


class CreatureCard(Card):
    def __init__(self, name: str, cost: int, rarity: str,
                 attack: int, health: int):
        super().__init__(name, cost, rarity)

        if not isinstance(attack, int) or not isinstance(health, int):
            raise ValueError('Attack and health must be integers.')
        if attack < 0 or health < 0:
            raise ValueError('Attack and health must be positive.')

        self.attack = attack
        self.health = health
        self.type = 'Creature'

    def get_card_info(self) -> dict:
        info = super().get_card_info()
        info.update({
            'type': 'Creature',
            'attack': self.attack,
            'health': self.health
        })
        return info

    def play(self, game_state: dict) -> dict:
        print(f'Playing {self.name}, {game_state["mana"]} mana available:')
        return {
                'card_played': self.name,
                'mana_used': self.cost,
                'effect': 'Creature summoned to battlefield'
        }

    def attack_target(self, target: str) -> dict:
        return {
            'attacker': self.name,
            'target': target,
            'damage_dealt': self.attack,
            'combat_resolved': True
        }
