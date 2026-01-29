from ex4.TournamentCard import TournamentCard


class TournamentPlatform:
    def __init__(self):
        self.registry = {}
        self.matches_played = 0

    def register_card(self, card: TournamentCard) -> str:
        self.registry[card.card_id] = card
        return card.card_id

    def create_match(self, card1_id: str, card2_id: str) -> dict:
        c1 = self.registry[card1_id]
        c2 = self.registry[card2_id]

        win, lose = (c1, c2) if c1.attack_val >= c2.attack_val else (c2, c1)

        win.update_wins(1)
        lose.update_losses(1)
        self.matches_played += 1

        return {
            'winner': win.card_id,
            'loser': lose.card_id,
            'winner_rating': win.rating,
            'loser_rating': lose.rating
        }

    def get_leaderboard(self) -> list:
        s = sorted(self.registry.values(), key=lambda x: x.rating)
        s.reverse()
        r = [f"{c.name} - Rating: {c.rating} ({c.wins}-{c.losses})" for c in s]
        return r

    def generate_tournament_report(self) -> dict:
        total = len(self.registry)
        if total > 0:
            avg = sum(c.rating for c in self.registry.values()) / total
        else:
            avg = 0
        return {
            'total_cards': total,
            'matches_played': self.matches_played,
            'avg_rating': int(avg),
            'platform_status': 'active'
        }
