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

    // Copy constructor
    Book(const Book &b) {
        title = b.title;
        author = b.author;
    }

    void display() {
        std::cout << "Title: " << title << ", Author: " << author << std::endl;
    }
};

int main() {
    Book book1("The Hobbit", "J.R.R. Tolkien");
    Book book2 = book1; // Copy constructor is called

    book1.display();
    book2.display();
    return 0;
}
