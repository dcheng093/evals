import sys


def get_arguments() -> list[int]:
    score_list: list[int] = []
    no_of_arguments = len(sys.argv)

    if no_of_arguments <= 1:
        raise Exception("No scores provided. "
                        "Usage: python3 "
                        "ft_score_analytics.py "
                        "<score1> <score2> ...")

    for argument in range(1, no_of_arguments):
        score_list += [int(sys.argv[argument])]

    return score_list


def ft_score_analytics() -> None:
    print("=== Player Score Analytics ===")
    try:
        score_list = get_arguments()
        total_players = len(score_list)
        print(f"Scores processed: {score_list}")
        print(f"Total players: {total_players}")

        total_score = sum(score_list)
        print(f"Total score: {total_score}")
        print("Average score: %.1f" % (total_score/total_players))

        score_list.sort()
        high_score = score_list[total_players - 1]
        low_score = score_list[0]
        print(f"High score: {high_score}")
        print(f"Low score: {low_score}")
        print(f"Score range: {high_score - low_score}")

    except Exception as e:
        print(f"Caught Error: {e}")


if __name__ == "__main__":
    ft_score_analytics()
