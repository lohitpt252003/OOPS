## Constructors

In Python, the `__init__()` method is the constructor. It is automatically called when a new object of a class is created.

-   **What is it?** The `__init__()` method is a special method used to initialize the attributes of an object.
-   **What if you don't mention a constructor?** If you do not define an `__init__()` method, Python provides a default one that does nothing.

### Types of Constructors in Python

1.  **Default Constructor**: A constructor that doesn't accept any arguments (other than `self`).
2.  **Parameterized Constructor**: A constructor that accepts arguments (in addition to `self`) to initialize the object's attributes.

### Constructor Overloading

Python does not support constructor overloading in the same way as C++. If you define multiple `__init__` methods in a class, the last one defined will overwrite the previous ones. The common Pythonic workaround is to define a single constructor with default values for its parameters.

-   For a practical code example, see the `L5_constructor_overloading_workaround.py` file.
