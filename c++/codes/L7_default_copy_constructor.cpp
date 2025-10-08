#include <iostream>

class MyClass {
public:
    int value;

    MyClass(int v = 0) : value(v) {
        std::cout << "Parameterized/Default constructor called for value: " << value << std::endl;
    }

    // No custom copy constructor defined, so the default one will be used.
    // The default copy constructor performs a shallow copy.
};

int main() {
    MyClass obj1(10);
    MyClass obj2 = obj1; // Default copy constructor is implicitly called

    std::cout << "obj1.value: " << obj1.value << std::endl;
    std::cout << "obj2.value: " << obj2.value << std::endl;

    obj1.value = 20; // Modifying obj1 does not affect obj2 for primitive types

    std::cout << "After modifying obj1.value:" << std::endl;
    std::cout << "obj1.value: " << obj1.value << std::endl;
    std::cout << "obj2.value: " << obj2.value << std::endl;

    return 0;
}
