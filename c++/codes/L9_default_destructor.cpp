#include <iostream>

class SimpleClass {
public:
    SimpleClass() {
        std::cout << "Constructor called." << std::endl;
    }

    // No custom destructor is defined here.
    // The compiler will provide a default destructor.
    // ~SimpleClass() { }
};

int main() {
    std::cout << "Creating an object of SimpleClass." << std::endl;
    SimpleClass obj;
    std::cout << "The object is about to go out of scope." << std::endl;
    
    // When 'obj' goes out of scope, the compiler-provided default destructor
    // is called automatically. Since it's empty and we have no dynamic
    // resources, no special output will be shown, but the cleanup happens correctly.
    
    return 0;
}
