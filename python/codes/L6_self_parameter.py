class Dog:
    def __init__(self, name, breed):
        self.name = name  # Accessing instance variable 'name'
        self.breed = breed # Accessing instance variable 'breed'

    def bark(self):
        print(f"{self.name} says Woof!") # Using self.name

    def describe(self):
        self.bark() # Calling another instance method using self
        print(f"This is {self.name}, a {self.breed}.")

my_dog = Dog("Buddy", "Golden Retriever")
my_dog.describe()
