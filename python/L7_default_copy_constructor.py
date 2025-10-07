import copy

class MyClass:
    def __init__(self, value):
        self.value = value

# Default copy constructor (shallow copy)
obj1 = MyClass(10)
obj2 = copy.copy(obj1)

print(f"obj1.value: {obj1.value}")
print(f"obj2.value: {obj2.value}")

obj1.value = 20

print("After modifying obj1.value:")
print(f"obj1.value: {obj1.value}")
print(f"obj2.value: {obj2.value}")
