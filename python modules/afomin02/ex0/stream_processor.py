from abc import ABC, abstractmethod
from typing import Any, List


class DataProcessor(ABC):
    @abstractmethod
    def process(self, data: Any) -> str:
        pass

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    def format_output(self, result: str) -> str:
        return result


class TextProcessor(DataProcessor):
    def __init__(self):
        print("\nInitializing Text Processor...")

    def process(self, data: str) -> str:
        return f"Processing data: \"{data}\""

    def validate(self, data: str) -> bool:
        if not isinstance(data, str):
            return False
        return type(data) is str

    def format_output(self, data: str):
        return (f"Processed text: {len(data)} " +
                f"characters, {len(data.split())} words")


class NumericProcessor(DataProcessor):
    def __init__(self):
        print("\nInitializing Numeric Processor...")

    def process(self, data: List[int]) -> str:
        return f"Processing data: {data}"

    def validate(self, data: List[int]) -> bool:
        if not isinstance(data, List):
            return False
        for i in data:
            if type(i) is not int:
                return False
        return True

    def format_output(self, data: List[int]) -> str:
        return (f"Processed {len(data)} numeric values, " +
                f"sum={sum(data)}, avg={sum(data) / len(data)}")


class LogProcessor(DataProcessor):
    def __init__(self):
        print("\nInitializing Log Processor...")

    def process(self, data: str) -> str:
        return f"Processing data: \"{data}\""

    def validate(self, data: str) -> bool:
        if not isinstance(data, str):
            return False
        return "ERROR:" in data or "INFO:" in data

    def format_output(self, data: str) -> str:
        parts = data.split(maxsplit=1)
        if parts[0] == "INFO:":
            return f"[INFO] INFO level detected: {parts[1]}"
        elif parts[0] == "ERROR:":
            return f"[ALERT] ERROR level detected: {parts[1]}"


def test(processor: DataProcessor) -> None:
    print("Result:", processor.format_output("Limb"))


print("=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===")

nums = [1, 5, 2, 11]
numeric = NumericProcessor()
print(numeric.process(nums))
if numeric.validate(nums):
    print("Validation: Numeric data verified")
print("Output: ", numeric.format_output(nums))

line = "That's not the way I pictured me"
text = TextProcessor()
print(text.process(line))
if text.validate(line):
    print("Validation: Text data verified")
print("Output:", text.format_output(line))

log_line = "ERROR: Connetion timeout"
log = LogProcessor()
print(log.process(log_line))
if log.validate(log_line):
    print("Validation: Log data verified")
print("Output:", log.format_output(log_line))

print("\n=== Polymorphic Processing Demo ===")
print("Processing multiple data types through same interface...")

processors = [numeric, text, log]
data_streams = [
    [1, 2, 3],
    "Hello Matrix",
    "INFO: System ready"
]

for i, (processor, data) in enumerate(zip(processors, data_streams), start=1):
    print(f"Result {i}: {processor.format_output(data)}")

print("\nFoundation systems online. Nexus ready for advanced streams.")
