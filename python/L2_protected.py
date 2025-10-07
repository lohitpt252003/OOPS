class Person:
    def __init__(self, name):
        self._name = name # Protected convention

class Teacher(Person):
    def __init__(self, name, department):
        super().__init__(name)
        self.department = department

    def print_details(self):
        print(f"Name: {self._name}, Department: {self.department}")

teacher1 = Teacher("Dr. Smith", "Computer Science")
teacher1.print_details()

# It's possible to access _name, but the underscore indicates it's not recommended
print(teacher1._name)
