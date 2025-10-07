#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int age;

public:
    // Setter for name
    void setName(std::string n) {
        name = n;
    }

    // Getter for name
    std::string getName() {
        return name;
    }

    // Setter for age
    void setAge(int a) {
        if (a > 0) { // Basic validation
            age = a;
        }
    }

    // Getter for age
    int getAge() {
        return age;
    }
};

int main() {
    Student s1;
    s1.setName("Lohit");
    s1.setAge(21);

    std::cout << "Name: " << s1.getName() << std::endl;
    std::cout << "Age: " << s1.getAge() << std::endl;

    return 0;
}
