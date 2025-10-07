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

teacher2 = Teacher("Ms. Johnson", "Mathematics", 55000.0, "Algebra")
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

teacher2 = Teacher("Ms. Johnson", "Mathematics", 55000.0, "Algebra")
teacher2.display_details()
```
