from ex3.GameStrategy import GameStrategy


class AggressiveStrategy(GameStrategy):
    def get_strategy_name(self) -> str:
        return "AggressiveStrategy"

    def prioritize_targets(self, available_targets: list) -> list:
        if "Enemy Player" in available_targets:
            return ["Enemy Player"]
        return available_targets

    def execute_turn(self, hand: list, battlefield: list) -> dict:
        print("!!!", hand)
        hand.sort(key=lambda x: x.cost)
        played = []
        mana_spent = 0
        mana_pool = 5
        damage = 0

        for card in hand:
            if card.cost <= (mana_pool - mana_spent):
                played.append(card.name)
                mana_spent += card.cost
                damage += getattr(card, 'attack', 0)
        return {
            'cards_played': played,
            'mana_used': mana_spent,
            'targets_attacked': self.prioritize_targets(['Enemy Player']),
            'damage_dealt': damage
        }
