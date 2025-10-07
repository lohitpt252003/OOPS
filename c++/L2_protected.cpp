#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
};

class Teacher : public Person {
public:
    std::string department;

    void setName(std::string n) {
        name = n; // 'name' is accessible because Teacher inherits from Person
    }

    void print() {
        std::cout << "Name: " << name << ", Department: " << department << std::endl;
    }
};

int main() {
    Teacher teacher1;
    teacher1.setName("Dr. Smith");
    teacher1.department = "Computer Science";
    teacher1.print();

    // The following line would cause a compile error because 'name' is protected
    // std::cout << teacher1.name; // Error
    return 0;
}
