class Student:
    def __init__(self, name="Unknown", age=0):
        self.name = name
        self.age = age

    def display(self):
        print(f"Name: {self.name}, Age: {self.age}")

s1 = Student() # Uses default arguments
s1.display()

s2 = Student("Lohit") # Overrides the default name
s2.display()

s3 = Student("Lohit P T", 21) # Provides all arguments
s3.display()
