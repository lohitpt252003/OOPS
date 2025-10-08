#include <iostream>
#include <string>

class Teacher {
public:
    std::string name;
    std::string department;

    void print() {
        std::cout << "Name: " << name << ", Department: " << department << std::endl;
    }
};

int main() {
    Teacher teacher1;
    teacher1.name = "Dr. Smith";
    teacher1.department = "Computer Science";
    teacher1.print();
    return 0;
}
