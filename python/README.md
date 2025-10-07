# Python OOP Examples

This folder contains examples and implementations of Object-Oriented Programming (OOP) concepts using Python.

## What is OOP?

Object-Oriented Programming (OOP) is a programming paradigm based on the concept of "objects", which can contain data and code: data in the form of fields (often known as attributes or properties), and code in the form of procedures (often known as methods).

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

### Python Example

```python
class Teacher:
    def __init__(self, name, department, salary, subject):
        self.name = name
        self.department = department
        self.salary = salary
        self.subject = subject

    def display_details(self):
        print(f"Name: {self.name}")
        print(f"Department: {self.department}")
        print(f"Salary: {self.salary}")
        print(f"Subject: {self.subject}")

# Creating an object (instance) of the Teacher class
teacher1 = Teacher("Dr. Smith", "Computer Science", 60000.0, "Programming")
teacher1.display_details()

teacher2 = Teacher("Ms. Johnson", "Mathematics", 55000.0, "Algebra");
teacher2.display_details()
```

## Class Syntax and Access (Without Access Modifiers)

Here, we'll demonstrate the basic syntax for defining a class and accessing its attributes and methods, initially without explicit access modifiers.

### Python Example

```python
class Teacher:
    def __init__(self, name, department, salary, subject):
        self.name = name
        self.department = department
        self.salary = salary
        self.subject = subject

    def display_details(self):
        print(f"Name: {self.name}")
        print(f"Department: {self.department}")
        print(f"Salary: {self.salary}")
        print(f"Subject: {self.subject}")

teacher1 = Teacher("Dr. Smith", "Computer Science", 60000.0, "Programming")
# Accessing attributes directly
print(f"Teacher's Name: {teacher1.name}")
teacher1.display_details()
```

**How to Run:**

1.  Save the code as `teacher_example.py`.
2.  Run using the Python interpreter:
    ```bash
python teacher_example.py
    ```

## Python Class Syntax Details

In Python, a class is defined using the `class` keyword, followed by the class name and a colon `:`. Indentation defines the class body.

```python
class ClassName:
    # Constructor (special method for initializing objects)
    def __init__(self, attribute1, attribute2):
        self.attribute1 = attribute1 # 'self' refers to the current object
        self.attribute2 = attribute2

    # Instance method
    def methodName(self):
        # Code for the method
        print(self.attribute1)

# Creating an object (instance) of the class
objectName = ClassName(value1, value2)

# Accessing attributes and methods
print(objectName.attribute1)
objectName.methodName()
```

**Key Points for Python:**
*   **`class ClassName:`**: Defines the class.
*   **`__init__(self, ...)`**: The constructor method, automatically called when a new object is created. `self` is a reference to the instance of the class.
*   **`self` parameter**: Must be the first parameter of any instance method, referring to the instance itself.
*   **No explicit access modifiers**: Python uses conventions for "private" members (e.g., `_attribute` for protected, `__attribute` for name mangling), but they are not strictly enforced. All members are technically accessible.


## Access Modifiers in Python

Python does not have strict access modifiers like C++ or Java. Instead, it relies on naming conventions to indicate the intended visibility of class members. This philosophy is sometimes summarized as "we're all consenting adults here."

1.  **Public**: By default, all members of a class are public. They can be accessed from anywhere.
2.  **Protected (by convention)**: A single underscore prefix (e.g., `_salary`) is a convention to indicate that a member is "protected" and intended for internal use or for use by subclasses. It's a hint to other programmers that a member is not part of the public API of the class and could change without notice. However, it does not prevent access.
3.  **Private (by convention)**: A double underscore prefix (e.g., `__name`) triggers "name mangling." The interpreter changes the name of the attribute to `_ClassName__attributeName`, making it harder to access from outside the class. This is not true privacy, but it's a stronger signal than the single underscore.

### Python Example with Access Modifiers

Here’s how the `Teacher` class can be written using these conventions.

```python
class Teacher:
    def __init__(self, name, department, salary, subject):
        self.__name = name  # Private attribute
        self.department = department  # Public attribute
        self._salary = salary  # Protected attribute
        self.subject = subject

    def display_details(self):
        print(f"Name: {self.__name}")
        print(f"Department: {self.department}")
        print(f"Salary: {self._salary}")
        print(f"Subject: {self.subject}")

    # Getter for name
    def get_name(self):
        return self.__name

    # Setter for name
    def set_name(self, name):
        self.__name = name

# Creating an object
teacher1 = Teacher("Dr. Smith", "Computer Science", 60000.0, "Programming")

# Accessing data through public methods
print(f"Teacher's Name: {teacher1.get_name()}")

# Changing data through a public method
teacher1.set_name("Dr. Jane Smith")
print(f"Updated Teacher's Name: {teacher1.get_name()}")

teacher1.display_details()

# Accessing a protected member (possible, but not recommended)
print(f"Salary (protected): {teacher1._salary}")

# Attempting to access a private member directly will fail
try:
    print(teacher1.__name)
except AttributeError as e:
    print(e)

# Accessing the mangled name (possible, but strongly discouraged)
print(f"Name (mangled): {teacher1._Teacher__name}")

```

This example illustrates Python's approach to encapsulation, which relies on programmer discipline and naming conventions rather than strict enforcement by the language.

## Default Access Modifier

In Python, all class members (attributes and methods) are **`public`** by default. There are no keywords to declare members as public; they are public unless their names start with underscores.

### Example

```python
class MyClass:
    def __init__(self):
        self.my_public_property = 10

    def my_public_method(self):
        print("This is a public method.")

instance = MyClass()
print(instance.my_public_property) # 10
instance.my_public_method() # "This is a public method."
```

## Examples

- [Public Example](./L2_public.py)
- [Private Example](./L2_private.py)
- [Protected Example](./L2_protected.py)