# C++ OOP Examples

This folder contains examples and implementations of Object-Oriented Programming (OOP) concepts using C++.

## What is OOP?

Object-Oriented Programming (OOP) is a programming paradigm based on the concept of "objects", which can contain data and code: data in the form of fields (often known as attributes or properties), and code in the form of procedures (often known as methods).

## Pillars of OOP

Object-Oriented Programming is built on four main principles, often called the pillars of OOP:

1.  **Encapsulation**: This is the bundling of data (attributes) and methods that operate on the data into a single unit, a class. It restricts direct access to some of an object's components, which is a means of preventing accidental interference and misuse of the data. Access control (public, private, protected) is the mechanism to achieve encapsulation.

2.  **Abstraction**: Abstraction means hiding the complex implementation details and showing only the essential features of the object. It helps in managing complexity by allowing us to focus on what an object does instead of how it does it. For example, a driver of a car doesn't need to know the internal workings of the engine to drive it.

3.  **Inheritance**: This is a mechanism where a new class (derived or child class) inherits properties and behaviors (methods) from an existing class (base or parent class). It promotes code reusability and establishes a relationship between the classes.

4.  **Polymorphism**: This is the ability of an object to take on many forms. In OOP, it allows objects of different classes to be treated as objects of a common superclass. The most common use of polymorphism in OOP is when a parent class reference is used to refer to a child class object. This can be achieved through function overloading (compile-time polymorphism) and virtual functions (runtime polymorphism).

## Why is OOP Necessary?

OOP offers several benefits, including:

- **Modularity:** Objects create self-contained units, making code easier to understand and maintain.
- **Reusability:** Code can be reused through inheritance and composition, reducing redundancy.
- **Flexibility (Polymorphism):** Allows objects of different classes to be treated as objects of a common type, enabling more flexible and extensible code.
- **Data Hiding (Encapsulation):** Protects data from accidental modification by restricting direct access, improving security and integrity.
- **Easier Debugging:** Encapsulation helps in isolating issues, making debugging more straightforward.

## What is a Class?

In Object-Oriented Programming (OOP), a **class** is a blueprint or a template for creating objects. It defines a common structure and behavior that all objects of that type will possess.

Think of it like this:
*   A **class** is like the blueprint for a house. It specifies how many rooms, windows, doors, etc., the house will have, but it's not an actual house you can live in.
*   An **object** (or instance) is the actual house built from that blueprint. You can have many houses (objects) built from the same blueprint (class), each with its own unique characteristics (e.g., different paint colors, furniture), but all adhering to the blueprint's design.

Key characteristics defined by a class include:
*   **Attributes (Data/Properties):** These are variables that hold the state or characteristics of an object.
*   **Methods (Functions/Behaviors):** These are functions that define the actions an object can perform.

## What is an Object?

An **object** is a physical instance of a class. It's a concrete entity created based on the class's blueprint.

Key differences between a Class and an Object:

| Feature           | Class                                       | Object                                          |
| :---------------- | :------------------------------------------ | :---------------------------------------------- |
| **Nature**        | Blueprint/Template                          | Instance/Real-world Entity                      |
| **Memory**        | Logical entity, no memory allocated         | Physical entity, occupies memory                |
| **Purpose**       | Defines structure and behavior              | Represents real data with specific values       |
| **Creation**      | Declared once                               | Instantiated multiple times from a class        |
| **Interaction**   | Cannot be directly interacted with          | Can be directly interacted with                 |
| **Example**       | `class Car { ... }`                         | `myCar = new Car();`                            |

## Case Study: Teacher Class

Let's consider a `Teacher` class to illustrate OOP concepts. A `Teacher` can have attributes like `name`, `department`, `salary`, and `subject`.

### C++ Example

```cpp
#include <iostream>
#include <string>

class Teacher {
public:
    std::string name;
    std::string department;
    double salary;
    std::string subject;

    // Constructor
    Teacher(std::string n, std::string d, double s, std::string sub) {
        name = n;
        department = d;
        salary = s;
        subject = sub;
    }

    // Method to display teacher details
    void displayDetails() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Department: " << department << std::endl;
        std::cout << "Salary: " << salary << std::endl;
        std::cout << "Subject: " << subject << std::endl;
    }
};

int main() {
    // Creating an object (instance) of the Teacher class
    Teacher teacher1("Dr. Smith", "Computer Science", 60000.0, "Programming");
    teacher1.displayDetails();

    Teacher teacher2("Ms. Johnson", "Mathematics", 55000.0, "Algebra");
    teacher2.displayDetails();

    return 0;
}
```

## Class Syntax and Access (Without Access Modifiers)

Here, we'll demonstrate the basic syntax for defining a class and accessing its attributes and methods, initially without explicit access modifiers. In C++, members are `private` by default, so direct access from `main` would not be allowed without `public:`. For this example, we'll keep the `public:` keyword for simplicity in demonstrating access.

### C++ Example

```cpp
#include <iostream>
#include <string>

class Teacher {
public:
    std::string name;
    std::string department;
    double salary;
    std::string subject;

    // Constructor
    Teacher(std::string n, std::string d, double s, std::string sub) {
        name = n;
        department = d;
        salary = s;
        subject = sub;
    }

    void displayDetails() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Department: " << department << std::endl;
        std::cout << "Salary: " << salary << std::endl;
        std::cout << "Subject: " << subject << std::endl;
    }
};

int main() {
    Teacher teacher1("Dr. Smith", "Computer Science", 60000.0, "Programming");
    // Accessing attributes directly (because they are public)
    std::cout << "Teacher's Name: " << teacher1.name << std::endl;
    teacher1.displayDetails();

    return 0;
}
```

**How to Run:**

1.  Save the code as `teacher_example.cpp`.
2.  Compile using a C++ compiler (e.g., g++):
    ```bash
g++ teacher_example.cpp -o teacher_example
    ```
3.  Run the executable:
    ```bash
./teacher_example
    ```

## C++ Class Syntax Details

In C++, a class is defined using the `class` keyword, followed by the class name and a block of code enclosed in curly braces `{}`. It's important to end the class definition with a semicolon `;`.

```cpp
class ClassName {
public: // Access specifier (members below are accessible from outside the class)
    // Member variables (attributes)
    DataType attribute1;
    DataType attribute2;

    // Constructor (special method called when an object is created)
    ClassName(ParameterType param1, ParameterType param2) {
        attribute1 = param1;
        attribute2 = param2;
    }

    // Member functions (methods)
    void methodName() {
        // Code for the method
    }
}; // Don't forget the semicolon!

int main() {
    // Creating an object (instance) of the class
    ClassName objectName(value1, value2);

    // Accessing attributes and methods
    objectName.attribute1 = newValue; // If attribute1 is public
    objectName.methodName();
    return 0;
}
```

**Key Points for C++:**
*   **`class ClassName { ... };`**: Defines the class.
*   **Access Specifiers (`public`, `private`, `protected`)**: Control the visibility and accessibility of class members. By default, members are `private`.
*   **Constructor**: A method with the same name as the class, used to initialize objects.
*   **`main()` function**: Where the program execution begins and objects are typically created and used.

## Access Modifiers in C++

Access modifiers in C++ are keywords that set the accessibility of class members (attributes and methods). They are crucial for implementing **encapsulation**, which bundles data and the methods that operate on that data, restricting direct access to some of an object's components.

C++ has three access modifiers:

1.  **`public`**: Members are accessible from anywhere outside the class. This is the least restrictive access level.
2.  **`private`**: Members are only accessible from within the class itself. They cannot be accessed from outside the class, not even by derived classes (subclasses). By default, members of a class are `private`.
3.  **`protected`**: Members are accessible within the class and by derived classes (subclasses), but not from outside.

### C++ Example with Access Modifiers

Let's modify the `Teacher` class to use access modifiers properly. We'll make the attributes `private` and provide `public` methods (getters and setters) to access them.

```cpp
#include <iostream>
#include <string>

class Teacher {
private:
    std::string name;
    std::string department;
    double salary;
    std::string subject;

public:
    // Constructor
    Teacher(std::string n, std::string d, double s, std::string sub) {
        name = n;
        department = d;
        salary = s;
        subject = sub;
    }

    // Public method to display details
    void displayDetails() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Department: " << department << std::endl;
        std::cout << "Salary: " << salary << std::endl;
        std::cout << "Subject: " << subject << std::endl;
    }

    // Getter for name
    std::string getName() {
        return name;
    }

    // Setter for name
    void setName(std::string n) {
        name = n;
    }
};

int main() {
    Teacher teacher1("Dr. Smith", "Computer Science", 60000.0, "Programming");

    // Accessing data through public methods
    std::cout << "Teacher's Name: " << teacher1.getName() << std::endl;

    // Changing data through a public method
    teacher1.setName("Dr. Jane Smith");
    std::cout << "Updated Teacher's Name: " << teacher1.getName() << std::endl;

    teacher1.displayDetails();

    // The following line would cause a compile error because 'name' is private
    // teacher1.name = "Dr. John Smith"; // Error: 'std::string Teacher::name' is private

    return 0;
}
```

This example demonstrates how `private` members hide the data, and `public` methods provide controlled access. This prevents direct, uncontrolled modification of the object's state.

## Default Access Modifier

In C++, if you don't specify an access modifier for members of a `class`, they are **`private`** by default.

For `struct`, the default access modifier is **`public`**.

### Example

```cpp
class MyClass {
    int i; // This is private by default
};

struct MyStruct {
    int i; // This is public by default
};

int main() {
    MyClass c;
    // c.i = 10; // Compile Error: 'i' is private

    MyStruct s;
    s.i = 10; // OK: 'i' is public
    return 0;
}
```

## Getters and Setters

Getters and setters are methods used to retrieve (get) and update (set) the values of private class attributes. They provide a layer of abstraction and control over how an object's data is accessed and modified.

-   **Getters (Accessors)**: Methods that return the value of a private attribute. They are typically named `getX()` where `X` is the attribute name.
-   **Setters (Mutators)**: Methods that set the value of a private attribute. They can include validation logic to ensure the new value is valid. They are typically named `setX()` where `X` is the attribute name.

### C++ Example

```cpp
#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int age;

public:
    // Setter for name
    void setName(std::string n) {
        name = n;
    }

    // Getter for name
    std::string getName() {
        return name;
    }

    // Setter for age
    void setAge(int a) {
        if (a > 0) { // Basic validation
            age = a;
        }
    }

    // Getter for age
    int getAge() {
        return age;
    }
};

int main() {
    Student s1;
    s1.setName("Lohit");
    s1.setAge(21);

    std::cout << "Name: " << s1.getName() << std::endl;
    std::cout << "Age: " << s1.getAge() << std::endl;

    return 0;
}
```

## Examples

- [Public Example](./L2_public.cpp)
- [Private Example](./L2_private.cpp)
- [Protected Example](./L2_protected.cpp)
- [Getters and Setters Example](./L3_getters_setters.cpp)