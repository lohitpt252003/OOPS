
#include <iostream>
#include <string>

class Person {
private:
    std::string name;

public:
    int age;

public: // Is this second 'public' okay?
    // Constructor
    Person(std::string n, int a) {
        name = n;
        age = a;
    }

    void printName() {
        std::cout << "Name: " << name << std::endl;
    }
};

int main() {
    Person person1("Lohit", 21);
    person1.age = 22; // Accessing public member
    std::cout << "Age: " << person1.age << std::endl;
    person1.printName();
    // person1.name = "P T"; // This would be a compile error because name is private
    return 0;
}
