# Quiz: Constructor Overloading

**Question:** Look at the code below from the `L5_constructor_overloading.cpp` file. What will the output be when this program is executed? Why is a different constructor called each time?

**Code:**

```cpp
#include <iostream>

class Box {
private:
    double length;
    double breadth;
    double height;

public:
    // Default constructor
    Box() {
        length = 0.0;
        breadth = 0.0;
        height = 0.0;
        std::cout << "Default constructor called." << std::endl;
    }

    // Parameterized constructor for a cube
    Box(double side) {
        length = side;
        breadth = side;
        height = side;
        std::cout << "Parameterized constructor for a cube called." << std::endl;
    }

    // Parameterized constructor for a cuboid
    Box(double l, double b, double h) {
        length = l;
        breadth = b;
        height = h;
        std::cout << "Parameterized constructor for a cuboid called." << std::endl;
    }

    double getVolume() {
        return length * breadth * height;
    }
};

int main() {
    Box box1; // Calls the default constructor
    std::cout << "Volume of box1: " << box1.getVolume() << std::endl;

    Box box2(5.0); // Calls the constructor for a cube
    std::cout << "Volume of box2: " << box2.getVolume() << std::endl;

    Box box3(10.0, 5.0, 2.0); // Calls the constructor for a cuboid
    std::cout << "Volume of box3: " << box3.getVolume() << std::endl;

    return 0;
}
```

**Explanation:**

The output will be:

```
Default constructor called.
Volume of box1: 0
Parameterized constructor for a cube called.
Volume of box2: 125
Parameterized constructor for a cuboid called.
Volume of box3: 100
```

This happens because C++ supports **constructor overloading**. This means you can define multiple constructors in the same class, as long as they have a different number of parameters or different types of parameters.

The C++ compiler automatically chooses the correct constructor to call based on the number and types of arguments you provide when creating an object:

1.  `Box box1;` matches `Box()`, the default constructor with no arguments.
2.  `Box box2(5.0);` matches `Box(double side)`, the constructor with one double argument.
3.  `Box box3(10.0, 5.0, 2.0);` matches `Box(double l, double b, double h)`, the constructor with three double arguments.
