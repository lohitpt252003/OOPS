class Teacher:
    def __init__(self, name, department, salary, subject):
        self.name = name
        self.department = department
        self.salary = salary
        self.subject = subject

    def display_details(self):
        print(f"Name: {self.name}")
        print(f"Department: {self.department}")
        print(f"Salary: {self.salary}")
        print(f"Subject: {self.subject}")

teacher1 = Teacher("Dr. Smith", "Computer Science", 60000.0, "Programming")
# Accessing attributes directly
print(f"Teacher's Name: {teacher1.name}")
teacher1.display_details()
