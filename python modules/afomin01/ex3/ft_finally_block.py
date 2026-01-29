def water_plants(plant_list):
    print("Opening watering system")
    text = "Wateing system completed successfully!\n"
    try:
        for plant in plant_list:
            if plant is None:
                raise Exception("Error: Cannot water None - invalid plant!")
            print(f"Watering {plant}")
    except Exception as e:
        print(e)
        text = ""
    finally:
        print("Closing watering system (cleanup)")
        print(text)


def test_watering_system():
    plants = ["plant1", "plant2", "plant3"]
    print("=== Garden Watering System ===\n")
    water_plants(plants)
    plants[2] = None
    water_plants(plants)
    print("Cleanup always happens, even with errors!")
