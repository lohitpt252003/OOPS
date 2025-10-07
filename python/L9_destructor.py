import time

class MyClass:
    def __init__(self, name):
        self.name = name
        print(f"{self.name}: Constructor called")

    def __del__(self):
        print(f"{self.name}: Destructor called")

print("Creating obj1")
obj1 = MyClass("obj1")
print("Creating obj2 as a reference to obj1")
obj2 = obj1
print("Deleting obj1")
del obj1
print("Sleeping for 1 second")
time.sleep(1)
print("Deleting obj2")
del obj2
print("End of script")
