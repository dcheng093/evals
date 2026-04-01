def initialize_player_data() -> dict:
    players_dict = {
        "players":
        [
            {
                "name": "alice",
                "player_data":
                {
                    "login": True,
                    "score": 2300,
                    "achievements":
                    {
                        'money_generator',
                        'speed_demon',
                        'collector',
                        'perfectionist',
                        'limit_tester'
                    },
                    "regions": 'north'
                }
            },
            {
                "name": "bob",
                "player_data":
                {
                    "login": True,
                    "score": 1800,
                    "achievements":
                    {
                        'explorer',
                        'completionist',
                        'survivor',
                    },
                    "regions": 'east'
                }
            },
            {
                "name": "charlie",
                "player_data":
                {
                    "login": True,
                    "score": 2150,
                    "achievements":
                    {
                        'first_kill',
                        'level_10',
                        'boss_slayer',
                        'treasure_hunter',
                        'speed_demon',
                        'collector',
                        'perfectionist'
                    },
                    "regions": 'central'
                }
            },
            {
                "name": "diana",
                "player_data":
                {
                    "login": False,
                    "score": 2050,
                    "achievements":
                    {
                        'treasure_hunter',
                        'speed_demon',
                        'collector',
                        'perfectionist',
                        'limit_tester',
                        'explorer',
                        'completionist',
                        'survivor',
                        'money_generator'
                    },
                    "regions": 'central'
                }
            }
        ]
    }
    return players_dict


def main() -> None:
    d = initialize_player_data()

    print("=== List Comprehension Examples ===")
    high_scores = [player['name'] for player in d['players']
                   if player['player_data']['score'] >= 2000]
    print(f"High scorers (>2000): {high_scores}")
    scores_doubled = [player['player_data']['score']*2 for player in
                      d['players']]
    print(f"Scores doubled: {scores_doubled}")
    active_players = [player['name'] for player in d['players']
                      if player['player_data']['login']]
    print(f"Active players: {active_players}")
    print()

    print("=== Dict Comprehension Examples ===")
    active_scores = {
        player['name']: player['player_data']['score'] for player
        in d['players'] if player['player_data']['login']
    }
    print(f"Player scores: {active_scores}")
    score_categories = {
        "high": len([player['player_data']['score'] for player
                     in d['players'] if
                     player['player_data']['score'] >= 2000]),
        "medium": len([player['player_data']['score'] for player
                      in d['players'] if player['player_data']['score'] >= 1900
                      and player['player_data']['score'] <= 2200]),
        "low": len([player['player_data']['score'] for player
                   in d['players'] if player['player_data']['score'] <= 1900])
    }
    print(f"Score categories: {score_categories}")
    achievement_counts = {
        player['name']: len(player['player_data']['achievements']) for player
        in d['players'] if player['player_data']['login']
    }
    print(f"Achievement counts: {achievement_counts}")
    print()

    print("=== Set Comprehension Examples ===")
    unique_players = {player['name'] for player in d['players']}
    print(f"Unique players: {unique_players}")

    all_achievements = [ach for player in d['players']
                        for ach in player['player_data']['achievements']]
    achievement_frequency = {achieve: all_achievements.count(achieve)
                             for achieve in set(all_achievements)}
    rare_achievements = {ach for ach, count in achievement_frequency.items()
                         if count == min(achievement_frequency.values())}
    print(f"Rare achievements: {rare_achievements}")
    active_regions = {player['player_data']['regions'] for player
                      in d['players'] if player['player_data']['login']}
    print(f"Active regions: {active_regions}")
    print()

    print("=== Combined Analysis ===")
    total_players = len([player['name'] for player in d['players']])
    print("Total players: "
          f"{total_players}")
    print("Total unique achievements "
          f"{len(set(all_achievements))}")
    print("Average score: "
          f"{sum(scores_doubled) / 2 / total_players}")
    player_stats = [
        (
            p['name'],
            p['player_data']['score'],
            len(p['player_data']['achievements'])
        ) for p in d['players']
    ]
    top_performer = max(player_stats, key=lambda x: x[1])
    print(f"Top performer: {top_performer[0]} "
          f"({top_performer[1]} points, {top_performer[2]} achievements)")


if __name__ == "__main__":
    main()
