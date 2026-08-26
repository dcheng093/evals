from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex1 import HealCapability, TransformCapability

if __name__ == "__main__":
    print("Testing Creature with healing capability")
    heal = HealingCreatureFactory()
    base = heal.create_base()
    evolved = heal.create_evolved()
    print(" base:")
    print(base.describe())
    print(base.attack())
    if isinstance(base, HealCapability):
        print(base.heal())
    print(" evolved:")
    print(evolved.describe())
    print(evolved.attack())
    if isinstance(base, HealCapability):
        print(evolved.heal())

    print("\nTesting Creature with transform capability")
    transform = TransformCreatureFactory()
    base = transform.create_base()
    evolved = transform.create_evolved()
    print(" base:")
    print(base.describe())
    print(base.attack())
    if isinstance(base, TransformCapability):
        print(base.transform())
        print(base.attack())
        print(base.revert())
    print(" evolved:")
    print(evolved.describe())
    print(evolved.attack())
    if isinstance(base, TransformCapability):
        print(evolved.transform())
        print(evolved.attack())
        print(evolved.revert())
