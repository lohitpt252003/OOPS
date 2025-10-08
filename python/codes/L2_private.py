class Teacher:
    def __init__(self, name, department):
        self.__name = name
        self.__department = department

    def print_details(self):
        print(f"Name: {self.__name}, Department: {self.__department}")

teacher1 = Teacher("Dr. Smith", "Computer Science")
teacher1.print_details()

# The following line would cause an error because '__name' is private
# print(teacher1.__name) # Error

# Accessing through name mangling (not recommended)
# print(teacher1._Teacher__name)
