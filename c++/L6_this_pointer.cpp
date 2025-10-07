#include <iostream>
#include <string>

class Box {
private:
    double length;
    double breadth;
    double height;

public:
    // Constructor
    Box(double length, double breadth, double height) {
        // Using 'this' to distinguish between member variables and parameters
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }

    double calculateVolume() {
        return length * breadth * height;
    }

    // Function that returns the current object by reference
    Box& setLength(double length) {
        this->length = length;
        return *this; // Returns the current object
    }

    Box& setBreadth(double breadth) {
        this->breadth = breadth;
        return *this;
    }

    Box& setHeight(double height) {
        this->height = height;
        return *this;
    }
};

int main() {
    Box box1(10.0, 5.0, 2.0);
    std::cout << "Volume of box1: " << box1.calculateVolume() << std::endl;

    // Method chaining using 'this' pointer
    box1.setLength(15.0).setBreadth(7.0).setHeight(3.0);
    std::cout << "New volume of box1: " << box1.calculateVolume() << std::endl;

    return 0;
}
