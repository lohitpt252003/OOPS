import copy

class MyString:
    def __init__(self, data):
        self.data = data

    def __copy__(self):
        print("Shallow copy constructor called")
        return MyString(self.data)

    def __deepcopy__(self, memo):
        print("Deep copy constructor called")
        return MyString(copy.deepcopy(self.data, memo))

s1 = MyString("Hello")

# Shallow copy
s2 = copy.copy(s1)

# Deep copy
s3 = copy.deepcopy(s1)

s1.data += " World"

print(f"s1.data: {s1.data}")
print(f"s2.data: {s2.data}")
print(f"s3.data: {s3.data}")
