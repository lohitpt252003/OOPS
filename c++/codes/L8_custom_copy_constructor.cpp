#include <iostream>
#include <string>
#include <cstring> // For strlen and strcpy

class MyString {
private:
    char* data;
    int length;

public:
    // Constructor
    MyString(const char* str = "") {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
        std::cout << "Constructor called for: " << data << std::endl;
    }

    // Custom Copy Constructor (Deep Copy)
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1]; // Allocate new memory
        strcpy(data, other.data);    // Copy content
        std::cout << "Copy constructor called for: " << data << std::endl;
    }

    // Destructor
    ~MyString() {
        std::cout << "Destructor called for: " << data << std::endl;
        delete[] data;
    }

    void display() {
        std::cout << "String: " << data << ", Length: " << length << std::endl;
    }

    void append(const char* str) {
        int newLength = length + strlen(str);
        char* newData = new char[newLength + 1];
        strcpy(newData, data);
        strcat(newData, str);
        delete[] data; // Free old memory
        data = newData;
        length = newLength;
    }
};

int main() {
    MyString s1("Hello");
    s1.display();

    MyString s2 = s1; // Custom copy constructor is called
    s2.display();

    s1.append(" World"); // Modifying s1
    s1.display();
    s2.display(); // s2 remains unchanged due to deep copy

    return 0;
}
