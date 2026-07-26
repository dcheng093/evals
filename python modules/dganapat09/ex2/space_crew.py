from pydantic import BaseModel, Field, model_validator, ValidationError
from enum import Enum
from datetime import datetime


class RankType(str, Enum):
    cadet = "cadet"
    officer = "officer"
    lieutenant = "lieutenant"
    captain = "captain"
    commander = "commander"


class SpaceCrew(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: RankType
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = Field(default=True)


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[SpaceCrew] = Field(min_length=1, max_length=12)
    mission_status: str = Field(default="planned", max_length=10)
    budget_millions: float = Field(ge=1.0, le=10000.0)

    @model_validator(mode='after')
    def validate_info(self) -> "SpaceMission":
        # 1. Mission ID must start with "M"
        if not self.mission_id.startswith("M"):
            raise ValueError("Mission ID must start with 'M'")

        # 2 Must have at least one Commander or Captain
        # This checks if ANY crew member has the required rank
        has_leadership = any(
            member.rank in [RankType.captain, RankType.commander]
            for member in self.crew
        )
        if not has_leadership:
            raise ValueError("Mission must have at least one Commander or "
                             "Captain")

        # Rule 3: Long missions (> 365 days) need 50%
        # experienced crew (5+ years)
        if self.duration_days > 365:
            experience_count = sum(1 for member in self.crew
                                   if member.years_experience >= 5)
            # Now to check if the ratio of crew member has less then 50%
            # experienced crew (5+ years)
            if experience_count / len(self.crew) < 0.5:
                raise ValueError("Missions long require at least "
                                 "50% experienced crew members")

        # Rule4: All Crew members must be active
        if not all(member.is_active for member in self.crew):
            raise ValueError("All crew members must be active")

        return self


def demo() -> None:
    print("Space Mission Crew Validation")
    print("=========================================")

    sarah = SpaceCrew(
        member_id="CM01",
        name="Sarah Connor",
        rank=RankType.commander,
        age=42,
        specialization="Mission Command",
        years_experience=15
    )
    john = SpaceCrew(
        member_id="CM02",
        name="John Smith",
        rank=RankType.lieutenant,
        age=30,
        specialization="Navigation",
        years_experience=6
    )
    alice = SpaceCrew(
        member_id="CM03",
        name="Alice Johnson",
        rank=RankType.officer,
        age=26,
        specialization="Engineering",
        years_experience=2
    )
    try:
        valid_mission = SpaceMission(
            mission_id="M2024_MARS",
            mission_name="Mars Colony Establishment",
            destination="Mars",
            launch_date=datetime.now(),
            duration_days=900,
            crew=[sarah, john, alice],
            budget_millions=2500.0
        )

        print("Valid mission created:")
        print(f"Mission: {valid_mission.mission_name}")
        print(f"ID: {valid_mission.mission_id}")
        print(f"Destination: {valid_mission.destination}")
        print(f"Duration: {valid_mission.duration_days} days")
        print(f"Budget: ${valid_mission.budget_millions}M")
        print(f"Crew size: {len(valid_mission.crew)}")
        print("Crew members:")
        for cm in valid_mission.crew:
            print(f"- {cm.name} ({cm.rank.value}) - {cm.specialization}")

    except ValidationError as e:
        print(f"Unexpected error creating valid mission: {e}")

    try:
        SpaceMission(
            mission_id="M2086_MARS",
            mission_name="Titan Colony Establishment",
            destination="Saturn",
            launch_date=datetime.now(),
            duration_days=90,
            crew=[john, alice],
            budget_millions=500.0
        )
    except ValidationError as e:
        print("\n=========================================")
        print("Expected validation error:")
        for error in e.errors():
            clean_msg = error["msg"].replace("Value error, ", "")
            print(clean_msg)


if __name__ == "__main__":
    demo()
