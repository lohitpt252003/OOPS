#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int age;

public:
    // 1. Default constructor
    Student() {
        name = "Unknown";
        age = 0;
    }

    // 2. Parameterized constructor with name
    Student(std::string n) {
        name = n;
        age = 0;
    }

    // 3. Parameterized constructor with name and age
    Student(std::string n, int a) {
        name = n;
        age = a;
    }

    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    Student s1; // Calls default constructor
    s1.display();

    Student s2("Lohit"); // Calls constructor with one parameter
    s2.display();

    Student s3("Lohit P T", 21); // Calls constructor with two parameters
    s3.display();

    return 0;
}
