def input_temperature(temp_str: str) -> int:
    return int(temp_str)


def test_temperature() -> None:
    print("=== Garden Temperature ===")
    x = "25"
    print(f"Input data is '{x}'")
    try:
        temperature = input_temperature(x)
        print(f"Temperature is now {temperature}°C")
    except Exception as e:
        print(f"Caught input_temperature error: {e}")
    print()
    x = "abc"
    print(f"Input data is '{x}'")
    try:
        input_temperature(x)
    except Exception as e:
        print(f"Caught input_temperature error: {e}")


if __name__ == "__main__":
    test_temperature()
    print("All tests completed - program didn't crash!")
