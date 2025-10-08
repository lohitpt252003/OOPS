#include <iostream>

class Book {
public:
    // Default constructor
    Book() {
        std::cout << "A new book is created." << std::endl;
    }
};

int main() {
    Book myBook; // Default constructor is called
    return 0;
}
