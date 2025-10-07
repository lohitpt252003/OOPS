# JavaScript OOP Examples

This folder contains examples and implementations of Object-Oriented Programming (OOP) concepts using JavaScript.

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

### JavaScript Example

```javascript
class Teacher {
    constructor(name, department, salary, subject) {
        this.name = name;
        this.department = department;
        this.salary = salary;
        this.subject = subject;
    }

    displayDetails() {
        console.log(`Name: ${this.name}`);
        console.log(`Department: ${this.department}`);
        console.log(`Salary: ${this.salary}`);
        console.log(`Subject: ${this.subject}`);
    }
}

// Creating an object (instance) of the Teacher class
const teacher1 = new Teacher("Dr. Smith", "Computer Science", 60000.0, "Programming");
teacher1.displayDetails();

const teacher2 = new Teacher("Ms. Johnson", "Mathematics", 55000.0, "Algebra");
teacher2.displayDetails();
```

## Class Syntax and Access (Without Access Modifiers)

Here, we'll demonstrate the basic syntax for defining a class and accessing its attributes and methods, initially without explicit access modifiers.

### JavaScript Example

```javascript
class Teacher {
    constructor(name, department, salary, subject) {
        this.name = name;
        this.department = department;
        this.salary = salary;
        this.subject = subject;
    }

    displayDetails() {
        console.log(`Name: ${this.name}`);
        console.log(`Department: ${this.department}`);
        console.log(`Salary: ${this.salary}`);
        console.log(`Subject: ${this.subject}`);
    }
}

const teacher1 = new Teacher("Dr. Smith", "Computer Science", 60000.0, "Programming");
// Accessing attributes directly
console.log(`Teacher's Name: ${teacher1.name}`);
teacher1.displayDetails();
```

**How to Run:**

1.  Save the code as `teacher_example.js`.
2.  Run using Node.js:
    ```bash
node teacher_example.js
    ```

## JavaScript Class Syntax Details

JavaScript classes are primarily syntactic sugar over its existing prototype-based inheritance. They are defined using the `class` keyword.

```javascript
class ClassName {
    // Constructor (special method for creating and initializing objects)
    constructor(attribute1, attribute2) {
        this.attribute1 = attribute1; // 'this' refers to the current object
        this.attribute2 = attribute2;
    }

    // Instance method
    methodName() {
        // Code for the method
        console.log(this.attribute1);
    }
}

// Creating an object (instance) of the class
const objectName = new ClassName(value1, value2);

// Accessing attributes and methods
console.log(objectName.attribute1);
objectName.methodName();
```

**Key Points for JavaScript:**
*   **`class ClassName { ... }`**: Defines the class.
*   **`constructor()`**: A special method for creating and initializing an object created with a class.
*   **`this` keyword**: Refers to the current instance of the class.
*   **No explicit access modifiers**: By convention, properties intended to be private might be prefixed with `_` (e.g., `_privateAttribute`), but they are still technically accessible.

## Access Modifiers in JavaScript

JavaScript, traditionally, did not have built-in access modifiers like `public`, `private`, or `protected`. Encapsulation was achieved through conventions and closures. However, modern JavaScript (ES2022) has introduced a syntax for true private class members.

1.  **Public**: By default, all members (properties and methods) of a JavaScript class are public. They can be accessed from anywhere.
2.  **Private (Convention)**: A common convention is to prefix a member's name with an underscore (`_`) to indicate that it is intended for internal use and should not be accessed from outside the class. However, this is just a hint for developers, and it doesn't prevent access.
3.  **Private (Modern Syntax)**: The `#` prefix (hash) is used to declare true private class members. These members are only accessible from within the class and are completely hidden from the outside. Attempting to access a private member from outside the class will result in a `SyntaxError`.

### JavaScript Example with Access Modifiers

Here’s how the `Teacher` class can be written using both the underscore convention and the new `#` syntax for privacy.

```javascript
class Teacher {
    // Public properties
    department;
    subject;

    // Private properties
    #name;
    #salary;

    constructor(name, department, salary, subject) {
        this.#name = name;
        this.department = department;
        this.#salary = salary;
        this.subject = subject;
    }

    // Public method
    displayDetails() {
        console.log(`Name: ${this.#name}`);
        console.log(`Department: ${this.department}`);
        console.log(`Salary: ${this.#salary}`);
        console.log(`Subject: ${this.subject}`);
    }

    // Getter for name
    getName() {
        return this.#name;
    }

    // Setter for name
    setName(name) {
        this.#name = name;
    }
}

const teacher1 = new Teacher("Dr. Smith", "Computer Science", 60000.0, "Programming");

// Accessing data through public methods
console.log(`Teacher's Name: ${teacher1.getName()}`);

// Changing data through a public method
teacher1.setName("Dr. Jane Smith");
console.log(`Updated Teacher's Name: ${teacher1.getName()}`);

teacher1.displayDetails();

// The following lines would cause an error because #name is a private field
// console.log(teacher1.#name); // SyntaxError
// teacher1.#name = "Dr. John Smith"; // SyntaxError
```

This example shows how modern JavaScript can enforce encapsulation, making code more robust and secure.

## Default Access Modifier

In JavaScript, all class members (properties and methods) are **`public`** by default. There is no `public` keyword; if a member is not explicitly marked as private with `#`, it is public.

### Example

```javascript
class MyClass {
    myPublicProperty = 10; // This is public by default

    myPublicMethod() { // This is also public by default
        console.log("This is a public method.");
    }
}

const instance = new MyClass();
console.log(instance.myPublicProperty); // 10
instance.myPublicMethod(); // "This is a public method."
```

## Examples

- [Public Example](./L2_public.js)
- [Private Example](./L2_private.js)
- [Protected Convention Example](./L2_protected_convention.js)