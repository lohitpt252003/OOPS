## Access Modifiers in C++

Access modifiers in C++ are keywords that set the accessibility of class members (attributes and methods). They are crucial for implementing **encapsulation**.

C++ has three access modifiers:

1.  **`public`**: Members are accessible from anywhere outside the class. This is the least restrictive access level.
2.  **`private`**: Members are only accessible from within the class itself. They cannot be accessed from outside the class, not even by derived classes (subclasses). By default, members of a `class` are `private`.
3.  **`protected`**: Members are accessible within the class and by derived classes (subclasses), but not from outside.

### Using Multiple Access Modifiers

In C++, you can switch between `public`, `private`, and `protected` access modifiers multiple times within a single class definition. The compiler reads the class sequentially, and each modifier applies to all subsequent members until the next modifier is found. While it is common practice to group all `public`, `private`, and `protected` members together, it is not a requirement of the language.

-   For a practical code example, see the `L2_multiple_access_modifiers.cpp` file.
