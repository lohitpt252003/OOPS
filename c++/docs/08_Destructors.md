## Destructors

A destructor is a special member function that is automatically called when an object of a class is destroyed. It is the counterpart to the constructor.

-   **What is it?** A destructor has the same name as the class, preceded by a tilde (`~`), and it does not have a return type or any parameters.
-   **Purpose:** The primary purpose of a destructor is to release resources that the object may have acquired during its lifetime (e.g., dynamically allocated memory).

### Default vs. Custom Destructors

1.  **Default Destructor**: If you do not provide a destructor, the C++ compiler will create a **default destructor** for you. It is sufficient for simple classes that do not manage any dynamic resources.
2.  **Custom Destructor**: You should define a custom destructor whenever your class manages a resource that needs to be explicitly released.
