from abc import ABC, abstractmethod
from ex1.creatures import Creature
from ex1.capabilities import HealCapability, TransformCapability


class InvalidCreatureError(Exception):
    pass


class BattleStrategy(ABC):
    @abstractmethod
    def act(self, creature: Creature) -> str:
        pass

    @abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        pass


class NormalStrategy(BattleStrategy):
    def act(self, creature: Creature) -> str:
        return creature.attack()

    def is_valid(self, creature: Creature) -> bool:
        return True


class AggressiveStrategy(BattleStrategy):
    def act(self, creature: Creature) -> str:
        if not isinstance(creature, TransformCapability):
            raise InvalidCreatureError(f"Invalid Creature '{creature.name}' "
                                       "for this aggressive strategy")
        transform_msg = creature.transform()
        attack_msg = creature.attack()
        revert_msg = creature.revert()
        return f"{transform_msg}\n{attack_msg}\n{revert_msg}"

    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, TransformCapability)


class DefensiveStrategy(BattleStrategy):
    def act(self, creature: Creature) -> str:
        if not isinstance(creature, HealCapability):
            raise InvalidCreatureError(f"Invalid Creature '{creature.name}' "
                                       "for this defensive strategy")
        attack_msg = creature.attack()
        heal_msg = creature.heal()
        return f"{attack_msg}\n{heal_msg}"

    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, HealCapability)
