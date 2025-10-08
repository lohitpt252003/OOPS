class Teacher:
    def __init__(self, name, department):
        self.name = name
        self.department = department

    def print_details(self):
        print(f"Name: {self.name}, Department: {self.department}")

teacher1 = Teacher("Dr. Smith", "Computer Science")
teacher1.print_details()
