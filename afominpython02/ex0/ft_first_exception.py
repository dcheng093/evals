def check_temperature(temp_str: str):
    print(f"Testing temperature: {temp_str}")
    try:
        result = int(temp_str)
        if result > 40:
            print(f"Error: {result}°C is too hot for plants (max 40°C)\n")
            return None
        elif result < 0:
            print(f"Error: {result}°C is too cold for plants (min 0°C)\n")
            return None
        print(f"Temperature {result}°C is perfect for plants!\n")
        return result
    except ValueError:
        print(f"Error: '{temp_str}' is not a valid number\n")
        return None


def test_temperature_input():
    print("=== Garden Temperature Checker ===\n")
    check_temperature("25")
    check_temperature("abc")
    check_temperature("100")
    check_temperature("-100")
    print("All tests completed - program didnt crush!")
