#include <iostream>
#include <string>

class Teacher {
private:
    std::string name;
    std::string department;

public:
    Teacher(std::string n, std::string d) {
        name = n;
        department = d;
    }

    void print() {
        std::cout << "Name: " << name << ", Department: " << department << std::endl;
    }
};

int main() {
    Teacher teacher1("Dr. Smith", "Computer Science");
    teacher1.print();

    // The following line would cause a compile error because 'name' is private
    // std::cout << teacher1.name; // Error
    return 0;
}
