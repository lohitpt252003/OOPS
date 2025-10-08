# Python OOP Examples

This folder contains examples and implementations of Object-Oriented Programming (OOP) concepts using Python.

## What is OOP?

Object-Oriented Programming (OOP) is a programming paradigm based on the concept of "objects", which can contain data and code: data in the form of fields (often known as attributes or properties), and code in the form of procedures (often known as methods).

## Pillars of OOP

Object-Oriented Programming is built on four main principles, often called the pillars of OOP. In this chapter, we will focus on **Encapsulation**. The other pillars—Abstraction, Inheritance, and Polymorphism—will be covered in upcoming chapters.

1.  **Encapsulation**: This is the bundling of data (attributes) and the methods (functions) that operate on that data into a single unit called a class. It restricts direct access to some of an object's components.
2.  **Abstraction**: To be covered in an upcoming chapter.
3.  **Inheritance**: To be covered in an upcoming chapter.
4.  **Polymorphism**: To be covered in an upcoming chapter.

## What is Encapsulation?

Encapsulation is the practice of bundling data and the methods that operate on that data within a single unit, or "class". It's a protective wrapper that prevents the data from being accessed and modified by code outside the class.

The primary goal of encapsulation is **data hiding**. In Python, we use naming conventions (single `_` for protected and double `__` for private) to indicate that certain attributes should not be accessed directly. Instead, we provide public methods, including **getters and setters** (often implemented with the `@property` decorator), which allow controlled access to that data.

This approach has several advantages:
-   **Control**: We can enforce validation rules in our setters (e.g., ensuring an age is a positive number).
-   **Security**: It protects the internal state of an object from accidental or malicious corruption.
-   **Flexibility**: We can change the internal implementation of the class without breaking the code that uses it, as long as the public methods remain the same.

The `Access Modifiers` and `Getters and Setters` sections and their corresponding examples demonstrate how to achieve encapsulation in Python.

## Constructors

In Python, the `__init__()` method is the constructor. It is automatically called when a new object of a class is created.

-   **What is it?** The `__init__()` method is a special method used to initialize the attributes of an object.
-   **Is it public or private?** The `__init__()` method is a public method.
-   **What if you don't mention a constructor?** If you do not define an `__init__()` method, Python provides a default one that does nothing.

### Types of Constructors in Python

1.  **Default Constructor**: A constructor that doesn't accept any arguments (other than `self`). Python provides this by default if no other constructor is defined.
2.  **Parameterized Constructor**: A constructor that accepts arguments (in addition to `self`) to initialize the object's attributes.

### Constructor Overloading

Python does not support constructor overloading in the same way as C++. If you define multiple `__init__` methods, the last one will override the previous ones.

However, you can achieve similar functionality by using default arguments in the `__init__` method.

## The `self` Parameter

In Python, `self` is the first parameter of any instance method. It refers to the instance of the class itself. It is a convention, not a keyword, but it is universally used and expected.

-   **What is `self`?** It's a reference to the instance of the class on which the method is called. It allows methods to access the attributes and other methods of that instance.
-   **When is it used?**
    1.  **To access instance variables**: `self.attribute_name` is used to access or modify an instance's attributes.
    2.  **To call other instance methods**: `self.method_name()` is used to call other methods within the same instance.
    3.  **As the first parameter**: Every instance method must have `self` as its first parameter. When you call a method on an object (e.g., `my_object.method()`), Python automatically passes `my_object` as the `self` argument.

### Python Example

```python
class Dog:
    def __init__(self, name, breed):
        self.name = name  # Accessing instance variable 'name'
        self.breed = breed # Accessing instance variable 'breed'

    def bark(self):
        print(f"{self.name} says Woof!") # Using self.name

    def describe(self):
        self.bark() # Calling another instance method using self
        print(f"This is {self.name}, a {self.breed}.")

my_dog = Dog("Buddy", "Golden Retriever")
my_dog.describe()
```

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
objectName = ClassName(value1, value2);

# Accessing attributes and methods
print(objectName.attribute1);
objectName.methodName();
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

### Quiz: A Note on Access Modifier Order

**Question:** In C++, you can switch between `public` and `private` sections. What is the equivalent in Python? What happens if you try to group your methods under a `private` block?

**Explanation:**

This concept does not apply to Python. Python does not use keywords or blocks like `public:` or `private:` to define the visibility of members. Instead, access is determined on a **per-member basis** through naming conventions.

-   If a member name starts with no underscore (e.g., `age`), it is public.
-   If it starts with a single underscore (e.g., `_salary`), it is protected by convention.
-   If it starts with a double underscore (e.g., `__name`), it is considered private and its name is mangled.

The order in which you define methods or attributes in a Python class has no effect on their visibility. Each member's access level is determined individually by its name.

For example, the following class is perfectly normal in Python:

```python
class Person:
    def __init__(self, name, age):
        self.__name = name  # Private
        self.age = age      # Public

    def print_name(self):   # Public
        print(f"Name: {self.__name}")

    def _get_name(self):    # Protected by convention
        return self.__name
```

There is no need to group them, as their visibility is independent of their position in the class definition.

## Default Access Modifier

In Python, all class members (attributes and methods) are **`public`** by default. There are no keywords to declare members as public; they are public unless their names start with underscores.

### Example

```python
class MyClass:
    def __init__(self):
        self.my_public_property = 10

    def my_public_method(self):
        print("This is a public method.")

instance = new MyClass()
print(instance.my_public_property) # 10
instance.my_public_method() # "This is a public method."
```

## Getters and Setters

In Python, getters and setters are used to control access to attributes. The Pythonic way to implement them is by using the `@property` decorator.

-   **Getter**: The method that gets the value of an attribute is decorated with `@property`.
-   **Setter**: The method that sets the value of an attribute is decorated with `@<attribute_name>.setter`. This allows for validation before assigning the value.

### Python Example

```python
class Student:
    def __init__(self, name, age):
        self._name = name
        self._age = age

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, new_name):
        self._name = new_name

    @property
    def age(self):
        return self._age

    @age.setter
    def age(self, new_age):
        if new_age > 0:
            self._age = new_age

s1 = Student("Lohit", 21)
print(f"Name: {s1.name}")
print(f"Age: {s1.age}")

s1.name = "Lohit P T"
s1.age = 22
print(f"New Name: {s1.name}")
print(f"New Age: {s1.age}")
```

## Constructors

In Python, the `__init__()` method is the constructor. It is automatically called when a new object of a class is created.

-   **What is it?** The `__init__()` method is a special method used to initialize the attributes of an object.
-   **Is it public or private?** The `__init__()` method is a public method.
-   **What if you don't mention a constructor?** If you do not define an `__init__()` method, Python provides a default one that does nothing.

### Types of Constructors in Python

1.  **Default Constructor**: A constructor that doesn't accept any arguments (other than `self`). Python provides this by default if no other constructor is defined.
2.  **Parameterized Constructor**: A constructor that accepts arguments (in addition to `self`) to initialize the object's attributes.

### Constructor Overloading

Python does not support constructor overloading in the same way as C++. If you define multiple `__init__` methods, the last one will override the previous ones.

However, you can achieve similar functionality by using default arguments in the `__init__` method.

## Copying Objects

In Python, assignment statements do not copy objects. They create bindings between a target and an object. When we need a copy, we can use the `copy` module.

### Shallow Copy

A shallow copy creates a new object, but it does not create copies of nested objects. The new object will have references to the same nested objects as the original.

### Deep Copy

A deep copy creates a new object and recursively copies all nested objects.

### Python Example

```python
import copy

class Course:
    def __init__(self, title):
        self.title = title

class Student:
    def __init__(self, name, course):
        self.name = name
        self.course = course

# Original object
course1 = Course("Math")
student1 = Student("Lohit", course1)

# Shallow copy
student2 = copy.copy(student1)

# Deep copy
student3 = copy.deepcopy(student1)

# Modify the course title
student2.course.title = "Science"

print(student1.course.title)  # "Science"
print(student2.course.title)  # "Science"
print(student3.course.title)  # "Math"
```

## Destructors

In Python, the `__del__` method is the destructor. It is called when an object's reference count becomes zero and the object is about to be destroyed by the garbage collector.

-   **What is it?** The `__del__` method is a special method that can be defined to perform cleanup tasks before an object is reclaimed.
-   **Purpose:** It can be used for final cleanup, such as closing file handles or database connections.
-   **When is it called?** The `__del__` method is called automatically by the garbage collector. However, the exact timing is not guaranteed. It's not recommended to rely on it for critical cleanup operations that must happen at a specific time.

### Default Behavior vs. Custom Destructor (`__del__`)

1.  **Default Behavior (Garbage Collection)**: If you do not define a `__del__` method, Python does not create a "default destructor" function. Instead, the default behavior is that the garbage collector will automatically reclaim the object's memory when it's no longer referenced. This is sufficient for most classes.

2.  **Custom Destructor (`__del__`)**: You should define a `__del__` method only when you need to perform specific cleanup actions that won't happen automatically, like releasing external resources. Overriding `__del__` can sometimes complicate garbage collection, so it should be used with care.

### Python Example of a Custom Destructor

```python
import time

class MyClass:
    def __init__(self, name):
        self.name = name
        print(f"{self.name}: Constructor called")

    # Custom Destructor
    def __del__(self):
        print(f"{self.name}: Custom Destructor called")

obj1 = MyClass("obj1")
obj2 = obj1
del obj1
print("obj1 deleted")
time.sleep(1)
del obj2
print("obj2 deleted")
```

## Examples

- [Public Example](./L2_public.py)
- [Private Example](./L2_private.py)
- [Protected Example](./L2_protected.py)
- [Getters and Setters Example](./L3_getters_setters.py)
- [Default Constructor Example](./L4_default_constructor.py)
- [Parameterized Constructor Example](./L4_parameterized_constructor.py)
- [Constructor Overloading Workaround Example](./L5_constructor_overloading_workaround.py)
- [Default Copy Constructor Example](./L7_default_copy_constructor.py)
- [Custom Copy Constructor Example](./L8_custom_copy_constructor.py)
- [Default Behavior (Garbage Collection)](./L9_default_behavior.py)
- [Custom Destructor Example](./L9_custom_destructor.py)