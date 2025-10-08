## Constructors

A constructor is a special member function of a class that is automatically called when an object of that class is created. Its primary job is to initialize the object's data members.

-   **What is it?** A constructor has the same name as the class and does not have a return type.
-   **Is it public or private?** Constructors are typically declared in the `public` section of the class.
-   **What if you don't mention a constructor?** If you do not define any constructor, the C++ compiler provides a **default constructor** on its own.

### Types of Constructors in C++

1.  **Default Constructor**: A constructor that takes no arguments.
2.  **Parameterized Constructor**: A constructor that accepts arguments to initialize the data members.
3.  **Copy Constructor**: A constructor that creates an object by initializing it with an object of the same class.

### Constructor Overloading

Constructor overloading is a feature in C++ that allows a class to have more than one constructor, as long as they have different parameter lists. The compiler determines which constructor to call based on the arguments provided during object creation.

-   For a practical code example, see the `L5_constructor_overloading.cpp` file.
