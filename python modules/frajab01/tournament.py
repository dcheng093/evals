from ex1 import CreatureFactory, FlameFactory, AquaFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import BattleStrategy, NormalStrategy, InvalidCreatureError
from ex2 import AggressiveStrategy, DefensiveStrategy


def battle(opponents: list[tuple[CreatureFactory, BattleStrategy]]) -> None:
    for i in range(len(opponents)):
        for j in range(i+1, len(opponents)):
            creature_fact_a, battle_strat_a = opponents[i]
            creature_fact_b, battle_strat_b = opponents[j]
            creature_a = creature_fact_a.create_base()
            creature_b = creature_fact_b.create_base()
            print("* Battle *\n"
                  f"{creature_a.describe()}\n "
                  f"vs.\n{creature_b.describe()}\n "
                  "now fight!")
            try:
                strat_a = battle_strat_a.act(creature_a)
                strat_b = battle_strat_b.act(creature_b)
            except InvalidCreatureError as e:
                print(f"Battle error, aborting tournament: {e}")
                return
            print(f"{strat_a}\n{strat_b}\n")


if __name__ == "__main__":
    flame = FlameFactory()
    aqua = AquaFactory()
    heal = HealingCreatureFactory()
    transform = TransformCreatureFactory()
    normal_strat = NormalStrategy()
    aggr_strat = AggressiveStrategy()
    def_strat = DefensiveStrategy()

    print("Tournament 0 (basic)")
    opponents = [(flame, normal_strat), (heal, def_strat)]
    print(" [ (Flameling+Normal), (Healing+Defensive) ]")
    print("*** Tournament ***\n2 opponents involved\n")
    battle(opponents)

    print("Tournament 1 (error)")
    opponents = [(flame, aggr_strat), (heal, def_strat)]
    print(" [ (Flameling+Aggressive), (Healing+Defensive) ]")
    print("*** Tournament ***\n2 opponents involved\n")
    battle(opponents)

    print("Tournament 2 (multiple)")
    opponents = [(aqua, normal_strat), (heal, def_strat),
                 (transform, aggr_strat)]
    print(" [ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]")
    print("*** Tournament ***\n3 opponents involved\n")
    battle(opponents)
