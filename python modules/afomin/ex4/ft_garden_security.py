class SecurePlant:
    @staticmethod
    def decorator_created(func):
        def wrapper(self, *args, **kwargs):
            func(self, *args, **kwargs)
            print(f"Plant created: {args[0]}")
        return wrapper

    def __init__(self, name, height, age):
        self.__name = name
        self.__height = height
        self.__age = age

    def get_name(self):
        return self.__name

    def set_name(self, value: str):
        self.__name = value

    def get_height(self):
        return self.__height

    def set_height(self, value: int):
        if (value >= 0):
            self.__height = value
            print(f"Height updated: {value}cm [OK]")
        else:
            print(f"Invalid operation attempted: height {value}cm [REJECTED]")
            print("Security: Negative height rejected")

    def get_age(self):
        return (self.__age)

    def set_age(self, value):
        if (value >= 0):
            self.__age = value
            print(f"Age updated: {value} days [OK]")
        else:
            print(f"Invalid operation attempted: age {value} days [REJECTED]")
            print("Security: Negative age rejected")


a = SecurePlant("Plant", 23, 2)
a.set_age(5)
a.set_height(645908)
a.set_name("poop")
print(a._SecurePlant__age)
