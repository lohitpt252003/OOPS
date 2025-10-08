class Student:
    def __init__(self, name, age):
        self._name = name
        self._age = age

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, new_name):
        self._name = new_name

    @property
    def age(self):
        return self._age

    @age.setter
    def age(self, new_age):
        if new_age > 0:
            self._age = new_age

s1 = Student("Lohit", 21)
print(f"Name: {s1.name}")
print(f"Age: {s1.age}")

s1.name = "Lohit P T"
s1.age = 22
print(f"New Name: {s1.name}")
print(f"New Age: {s1.age}")
