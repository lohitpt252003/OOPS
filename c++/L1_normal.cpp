#include <iostream>
#include <string>

class Teacher {
public:
    std::string name;
    std::string department;
    double salary;
    std::string subject;

    // Constructor
    Teacher(std::string n, std::string d, double s, std::string sub) {
        name = n;
        department = d;
        salary = s;
        subject = sub;
    }

    void displayDetails() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Department: " << department << std::endl;
        std::cout << "Salary: " << salary << std::endl;
        std::cout << "Subject: " << subject << std::endl;
    }
};

int main() {
    Teacher teacher1("Dr. Smith", "Computer Science", 60000.0, "Programming");
    // Accessing attributes directly (because they are public)
    std::cout << "Teacher's Name: " << teacher1.name << std::endl;
    teacher1.displayDetails();

    return 0;
}
