#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    std::string author;

    // Parameterized constructor
    Book(std::string t, std::string a) {
        title = t;
        author = a;
    }

    void display() {
        std::cout << "Title: " << title << ", Author: " << author << std::endl;
    }
};

int main() {
    Book myBook("The Lord of the Rings", "J.R.R. Tolkien");
    myBook.display();
    return 0;
}
