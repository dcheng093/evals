def input_temperature(temp_str: str) -> int:
    temp = int(temp_str)
    if 0 <= temp <= 40:
        return temp
    elif temp > 40:
        raise Exception(f"{temp}°C is too hot for plants (max 40°C)")
    else:
        raise Exception(f"{temp}°C is too cold for plants (min 0°C)")


def test_temperature() -> None:
    print("=== Garden Temperature Checker ===")
    for x in ("25", "abc", "100", "-50"):
        print(f"Input data is '{x}'")
        try:
            temperature = input_temperature(x)
            print(f"Temperature is now {temperature}°C")
        except Exception as e:
            print(f"Caught input_temperature error: {e}")
        print()
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
