#include <iostream>

class MyClass {
public:
    MyClass() {
        std::cout << "Constructor called" << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructor called" << std::endl;
    }
};

int main() {
    std::cout << "Creating an object of MyClass." << std::endl;
    MyClass obj;
    std::cout << "The object is about to go out of scope." << std::endl;
    return 0;
}
