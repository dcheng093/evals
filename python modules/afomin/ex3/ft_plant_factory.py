class Plant:

    @staticmethod
    def decorator(func):
        def wrapper(self, *args, **kwargs):
            func(self, *args, **kwargs)
            print(f"Created: {args[0]} ({args[1]}cm, {args[2]} days)")
        return wrapper

    @decorator
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age


a = Plant("Listen", 0, 1)
b = Plant("To", 0, 1)
c = Plant("Darksynth", 0, 1)
d = Plant("Bro", 0, 1)
e = Plant(".", 0, 1)
