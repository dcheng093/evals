# Generators
# - https://stackoverflow.com/a/1756156


from typing import Generator


class Event():
    def __init__(self, name: str) -> None:
        self._name = name
        self._count = 0

    def increment(self) -> None:
        self._count += 1


class Player():
    def __init__(self, name: str, level: int) -> None:
        self._name = name
        self._level = level


class DataStream():
    def __init__(self) -> None:
        self._alice = Player("alice", 5)
        self._bob = Player("bob", 12)
        self._charlie = Player("charlie", 8)

        self._kill_monster = Event("kill_monster")
        self._found_treasure = Event("found_treasure")
        self._level_up = Event("level_up")

    def kill_monster(self) -> None:
        self._kill_monster.increment()

    def found_treasure(self) -> None:
        self._found_treasure.increment()

    def level_up(self, player: Player) -> None:
        self._level_up.increment()
        player._level += 1

    def generate_events(self,
                        n: int) -> Generator[tuple[str, Player], None, None]:
        """Generates random events. Yields a (str, player) tuple
        to be passed into the event stream."""

        players = [self._alice, self._bob, self._charlie]

        for i in range(n):
            current_player = players[i % len(players)]  # randomness simulation

            if i % 7 == 0:
                yield ("treasure", current_player)

            elif i % 5 == 0:
                yield ("level", current_player)

            else:
                yield ("monster", current_player)

    def event_stream(self, n: int) -> Generator[tuple[str, int], None, None]:
        """Event stream generator to track player levels at each event state
        for accurate data tracking."""

        for event_type, player in self.generate_events(n):
            if event_type == "level":
                self.level_up(player)
                msg = f"Player {player._name} "
                msg += f"(level {player._level}) leveled up"

            elif event_type == "treasure":
                self.found_treasure()
                msg = f"Player {player._name} "
                msg += f"(level {player._level}) found treasure"

            else:
                self.kill_monster()
                msg = f"Player {player._name} "
                msg += f"(level {player._level}) killed monster"

            yield (msg, player._level)


def fibonacci(n: int) -> Generator[int, None, None]:
    """Generator function for fibonacci sequence"""
    a, b = 0, 1
    for _ in range(n):
        yield a
        a, b = b, b + a


def is_prime(n: int) -> bool:
    """Function to check if n is prime"""
    if n < 2:
        return False

    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False

    return True


def find_prime(n: int) -> Generator[int, None, None]:
    count, num = 0, 2
    while count < n:
        if is_prime(num):
            yield num
            count += 1
        num += 1


def main() -> None:
    print("=== Game Data Stream Processor ===")
    print()

    stream = DataStream()
    no_of_events = 1000
    generate_event = stream.event_stream(no_of_events)
    print(f"Processing {no_of_events} game events...")
    print()

    count = 1
    high_level_events = 0

    for event, level in generate_event:
        if count <= 3:
            print(f"Event {count}: {event}")
            count += 1

        if level >= 10:
            high_level_events += 1

    print("...")
    print()

    print("=== Stream Analytics ===")
    print(f"Total events processed: {no_of_events}")
    print("High-level player events (10+): "
          f"{high_level_events}")
    print("Treasure events: "
          f"{stream._found_treasure._count}")
    print("Level-up events: "
          f"{stream._level_up._count}")
    print()

    print("=== Generator Demonstration ===")
    fibonacci_count = 10
    print(f"Fibonacci sequence (first {fibonacci_count}): "
          f"{list(fibonacci(fibonacci_count))}")
    prime_count = 10
    print(f"Prime numbers (first {prime_count}): "
          f"{list(find_prime(prime_count))}")


if __name__ == "__main__":
    main()
