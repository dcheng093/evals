from ex0 import CreatureFactory, FlameFactory, AquaFactory


def factorytest(obj: CreatureFactory) -> None:
    base_creature = obj.create_base()
    evolved_creature = obj.create_evolved()
    print(base_creature.describe())
    print(base_creature.attack())
    print(evolved_creature.describe())
    print(evolved_creature.attack())


def battletest(factory1: type[CreatureFactory],
               factory2: type[CreatureFactory]) -> None:
    fact_1 = factory1()
    fact_2 = factory2()
    fighter1 = fact_1.create_base()
    fighter2 = fact_2.create_base()
    print(f"{fighter1.describe()}\n vs.\n{fighter2.describe()}\n fight!")
    print(fighter1.attack())
    print(fighter2.attack())


if __name__ == "__main__":
    print("Testing factory")
    flame = FlameFactory()
    factorytest(flame)

    print("\nTesting factory")
    aqua = AquaFactory()
    factorytest(aqua)

    print("\nTesting battle")
    battletest(FlameFactory, AquaFactory)
