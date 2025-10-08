# JavaScript OOP Examples

This folder contains examples and implementations of Object-Oriented Programming (OOP) concepts using JavaScript.

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

The primary goal of encapsulation is **data hiding**. By making the data members of a class private (using the `#` prefix), we prevent external code from directly manipulating them. Instead, we provide public methods, including **getters and setters**, which allow controlled access to that data.

This approach has several advantages:
-   **Control**: We can enforce validation rules in our setters (e.g., ensuring an age is a positive number).
-   **Security**: It protects the internal state of an object from accidental or malicious corruption.
-   **Flexibility**: We can change the internal implementation of the class without breaking the code that uses it, as long as the public methods remain the same.

The `Access Modifiers` and `Getters and Setters` sections and their corresponding examples demonstrate how to achieve encapsulation in JavaScript.

## Constructors

In JavaScript, the `constructor` is a special method for creating and initializing an object created with a `class`.

-   **What is it?** A special method for creating and initializing an object. There can only be one special method with the name "constructor" in a class.
-   **Is it public or private?** The constructor method is public.
-   **What if you don't mention a constructor?** If you do not provide a constructor, a default constructor is created for you. For a base class, the default constructor is `constructor() {}`. For a derived class, the default constructor is `constructor(...args) { super(...args); }`.

### Types of Constructors in JavaScript

1.  **Default Constructor**: A constructor that takes no arguments. If you don't define a constructor, a default one is provided.
2.  **Parameterized Constructor**: A constructor that accepts arguments to initialize the properties of the object.

### Constructor Overloading

JavaScript does not support constructor overloading in the same way as languages like C++. A class can only have one constructor.

However, you can achieve similar functionality by using default parameters or by checking the number and type of arguments passed to the constructor.

## The `this` Keyword

In JavaScript, the `this` keyword refers to the context in which a function is executed. Its value is determined by how the function is called, not where it is defined.

-   **What is `this`?** It's a special keyword that refers to the object that is currently executing the code.
-   **How `this` is determined:**
    1.  **Global context**: In the global execution context (outside of any function), `this` refers to the global object (e.g., `window` in browsers, `global` in Node.js).
    2.  **Object method**: When a function is called as a method of an object, `this` refers to the object itself.
    3.  **Constructor**: When a function is used as a constructor (with the `new` keyword), `this` refers to the newly created instance.
    4.  **Explicit binding**: Methods like `call()`, `apply()`, and `bind()` can explicitly set the value of `this`.
    5.  **Arrow functions**: Arrow functions do not have their own `this` context; they inherit `this` from their enclosing lexical context.

### JavaScript Example

```javascript
// 1. Global context
console.log(this === window); // In browsers, true (or global in Node.js)

// 2. Object method
const person = {
    name: "Lohit",
    greet: function() {
        console.log(`Hello, my name is ${this.name}`);
    }
};
person.greet(); // 'this' refers to 'person'

// 3. Constructor
class Car {
    constructor(make) {
        this.make = make;
    }
}
const myCar = new Car("Toyota");
console.log(myCar.make); // 'this' refers to 'myCar'

// 4. Explicit binding with call()
function introduce(age) {
    console.log(`I am ${this.name} and I am ${age} years old.`);
}
introduce.call(person, 21); // 'this' is explicitly set to 'person'

// 5. Arrow function (lexical 'this')
const anotherPerson = {
    name: "Jane",
    sayHello: function() {
        const innerFunction = () => {
            console.log(`Hi, I'm ${this.name}`); // 'this' is inherited from sayHello's context (anotherPerson)
        };
        innerFunction();
    }
};
anotherPerson.sayHello();
```

## Copying Objects

JavaScript does not have a direct equivalent of a C++ copy constructor. When you assign one object to another using `=`, you are creating a reference to the original object, not a new copy. Changes to the copied object will affect the original.

To create a true copy, you need to perform either a shallow copy or a deep copy.

### Shallow Copy

A shallow copy creates a new object, but it copies the references to the nested objects. So, if the original object contains other objects, the copied object will still refer to the same nested objects.

Common ways to perform a shallow copy:
-   **Spread syntax (`...`)**: For objects and arrays.
-   **`Object.assign()`**: Copies all enumerable own properties from one or more source objects to a target object.

### Deep Copy

A deep copy creates a new object and recursively copies all nested objects. This means that changes to the copied object will not affect the original, even for nested structures.

Common ways to perform a deep copy:
-   **`JSON.parse(JSON.stringify(object))`**: This is a simple way to deep copy objects that are JSON-safe (i.e., contain no functions, `undefined`, `NaN`, `Infinity`, or circular references).
-   **External libraries**: For complex objects or objects that are not JSON-safe, libraries like Lodash (`_.cloneDeep()`) are often used.

## Destructors and Garbage Collection

JavaScript does not have destructors in the same way as languages like C++ or Python. The concept of manually destroying an object or having a specific function that runs upon destruction does not exist.

-   **No Destructor Function**: You cannot define a `destructor()` or `__del__()` method that is guaranteed to run when an object is no longer in use.
-   **Automatic Garbage Collection**: Memory management is handled automatically by the JavaScript engine's garbage collector (GC). The GC's job is to identify and reclaim memory that is no longer reachable by any part of the program.
-   **Unpredictable Timing**: You cannot predict *when* the garbage collector will run. It might run frequently or very rarely, depending on memory pressure and the engine's algorithm. Therefore, you should never rely on it for timely cleanup of resources like files or network connections.

For advanced and specific use cases, the `FinalizationRegistry` object provides a way to request a cleanup callback when an object is garbage-collected. However, its use is complex, and its behavior is not guaranteed, so it is not recommended for general use.

### Example of an Object Becoming Eligible for Garbage Collection

The following code shows an object being created and then going out of scope, which makes it eligible for garbage collection. It does not define a destructor, as the concept does not apply to JavaScript.

```javascript
class MyClass {
    constructor(name) {
        this.name = name;
        console.log(`${this.name}: Constructor called`);
    }
}

function run() {
    let obj = new MyClass("myObject");
    console.log("Object created");
} // The 'obj' variable ceases to exist here.

run();
console.log("Function 'run' has finished. The object is now out of scope and eligible for garbage collection, but there is no destructor and no guaranteed time of cleanup.");
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

## Getters and Setters

In JavaScript, getters and setters provide a way to get and set the values of an object's properties, while allowing for more control over how the properties are accessed and modified. They are defined using the `get` and `set` keywords.

-   **Getters**: A getter is a method that gets the value of a specific property.
-   **Setters**: A setter is a method that sets the value of a specific property. Setters can include validation logic.

### JavaScript Example

```javascript
class Student {
    #name;
    #age;

    get name() {
        return this.#name;
    }

    set name(newName) {
        this.#name = newName;
    }

    get age() {
        return this.#age;
    }

    set age(newAge) {
        if (newAge > 0) {
            this.#age = newAge;
        }
    }
}

const s1 = new Student();
s1.name = "Lohit";
s1.age = 21;

console.log(`Name: ${s1.name}`);
console.log(`Age: ${s1.age}`);
```

## Constructors

In JavaScript, the `constructor` is a special method for creating and initializing an object created with a `class`.

-   **What is it?** A special method for creating and initializing an object. There can only be one special method with the name "constructor" in a class.
-   **Is it public or private?** The constructor method is public.
-   **What if you don't mention a constructor?** If you do not provide a constructor, a default constructor is created for you. For a base class, the default constructor is `constructor() {}`. For a derived class, the default constructor is `constructor(...args) { super(...args); }`.

### Types of Constructors in JavaScript

1.  **Default Constructor**: A constructor that takes no arguments. If you don't define a constructor, a default one is provided.
2.  **Parameterized Constructor**: A constructor that accepts arguments to initialize the properties of the object.

### Constructor Overloading

JavaScript does not support constructor overloading in the same way as languages like C++. A class can only have one constructor.

However, you can achieve similar functionality by using default parameters or by checking the number and type of arguments passed to the constructor.

## The `this` Keyword

In JavaScript, the `this` keyword refers to the context in which a function is executed. Its value is determined by how the function is called, not where it is defined.

-   **What is `this`?** It's a special keyword that refers to the object that is currently executing the code.
-   **How `this` is determined:**
    1.  **Global context**: In the global execution context (outside of any function), `this` refers to the global object (e.g., `window` in browsers, `global` in Node.js).
    2.  **Object method**: When a function is called as a method of an object, `this` refers to the object itself.
    3.  **Constructor**: When a function is used as a constructor (with the `new` keyword), `this` refers to the newly created instance.
    4.  **Explicit binding**: Methods like `call()`, `apply()`, and `bind()` can explicitly set the value of `this`.
    5.  **Arrow functions**: Arrow functions do not have their own `this` context; they inherit `this` from their enclosing lexical context.

### JavaScript Example

```javascript
// 1. Global context
console.log(this === window); // In browsers, true (or global in Node.js)

// 2. Object method
const person = {
    name: "Lohit",
    greet: function() {
        console.log(`Hello, my name is ${this.name}`);
    }
};
person.greet(); // 'this' refers to 'person'

// 3. Constructor
class Car {
    constructor(make) {
        this.make = make;
    }
}
const myCar = new Car("Toyota");
console.log(myCar.make); // 'this' refers to 'myCar'

// 4. Explicit binding with call()
function introduce(age) {
    console.log(`I am ${this.name} and I am ${age} years old.`);
}
introduce.call(person, 21); // 'this' is explicitly set to 'person'

// 5. Arrow function (lexical 'this')
const anotherPerson = {
    name: "Jane",
    sayHello: function() {
        const innerFunction = () => {
            console.log(`Hi, I'm ${this.name}`); // 'this' is inherited from sayHello's context (anotherPerson)
        };
        innerFunction();
    }
};
anotherPerson.sayHello();
```

## Copying Objects

JavaScript does not have a direct equivalent of a C++ copy constructor. When you assign one object to another using `=`, you are creating a reference to the original object, not a new copy. Changes to the copied object will affect the original.

To create a true copy, you need to perform either a shallow copy or a deep copy.

### Shallow Copy

A shallow copy creates a new object, but it copies the references to the nested objects. So, if the original object contains other objects, the copied object will still refer to the same nested objects.

Common ways to perform a shallow copy:
-   **Spread syntax (`...`)**: For objects and arrays.
-   **`Object.assign()`**: Copies all enumerable own properties from one or more source objects to a target object.

### Deep Copy

A deep copy creates a new object and recursively copies all nested objects. This means that changes to the copied object will not affect the original, even for nested structures.

Common ways to perform a deep copy:
-   **`JSON.parse(JSON.stringify(object))`**: This is a simple way to deep copy objects that are JSON-safe (i.e., contain no functions, `undefined`, `NaN`, `Infinity`, or circular references).
-   **External libraries**: For complex objects or objects that are not JSON-safe, libraries like Lodash (`_.cloneDeep()`) are often used.

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

## Getters and Setters

In JavaScript, getters and setters provide a way to get and set the values of an object's properties, while allowing for more control over how the properties are accessed and modified. They are defined using the `get` and `set` keywords.

-   **Getters**: A getter is a method that gets the value of a specific property.
-   **Setters**: A setter is a method that sets the value of a specific property. Setters can include validation logic.

### JavaScript Example

```javascript
class Student {
    #name;
    #age;

    get name() {
        return this.#name;
    }

    set name(newName) {
        this.#name = newName;
    }

    get age() {
        return this.#age;
    }

    set age(newAge) {
        if (newAge > 0) {
            this.#age = newAge;
        }
    }
}

const s1 = new Student();
s1.name = "Lohit";
s1.age = 21;

console.log(`Name: ${s1.name}`);
console.log(`Age: ${s1.age}`);
```

## Constructors

In JavaScript, the `constructor` is a special method for creating and initializing an object created with a `class`.

-   **What is it?** A special method for creating and initializing an object. There can only be one special method with the name "constructor" in a class.
-   **Is it public or private?** The constructor method is public.
-   **What if you don't mention a constructor?** If you do not provide a constructor, a default constructor is created for you. For a base class, the default constructor is `constructor() {}`. For a derived class, the default constructor is `constructor(...args) { super(...args); }`.

### Types of Constructors in JavaScript

1.  **Default Constructor**: A constructor that takes no arguments. If you don't define a constructor, a default one is provided.
2.  **Parameterized Constructor**: A constructor that accepts arguments to initialize the properties of the object.

### Constructor Overloading

JavaScript does not support constructor overloading in the same way as languages like C++. A class can only have one constructor.

However, you can achieve similar functionality by using default parameters or by checking the number and type of arguments passed to the constructor.

## The `this` Keyword

In JavaScript, the `this` keyword refers to the context in which a function is executed. Its value is determined by how the function is called, not where it is defined.

-   **What is `this`?** It's a special keyword that refers to the object that is currently executing the code.
-   **How `this` is determined:**
    1.  **Global context**: In the global execution context (outside of any function), `this` refers to the global object (e.g., `window` in browsers, `global` in Node.js).
    2.  **Object method**: When a function is called as a method of an object, `this` refers to the object itself.
    3.  **Constructor**: When a function is used as a constructor (with the `new` keyword), `this` refers to the newly created instance.
    4.  **Explicit binding**: Methods like `call()`, `apply()`, and `bind()` can explicitly set the value of `this`.
    5.  **Arrow functions**: Arrow functions do not have their own `this` context; they inherit `this` from their enclosing lexical context.

### JavaScript Example

```javascript
// 1. Global context
console.log(this === window); // In browsers, true (or global in Node.js)

// 2. Object method
const person = {
    name: "Lohit",
    greet: function() {
        console.log(`Hello, my name is ${this.name}`);
    }
};
person.greet(); // 'this' refers to 'person'

// 3. Constructor
class Car {
    constructor(make) {
        this.make = make;
    }
}
const myCar = new Car("Toyota");
console.log(myCar.make); // 'this' refers to 'myCar'

// 4. Explicit binding with call()
function introduce(age) {
    console.log(`I am ${this.name} and I am ${age} years old.`);
}
introduce.call(person, 21); // 'this' is explicitly set to 'person'

// 5. Arrow function (lexical 'this')
const anotherPerson = {
    name: "Jane",
    sayHello: function() {
        const innerFunction = () => {
            console.log(`Hi, I'm ${this.name}`); // 'this' is inherited from sayHello's context (anotherPerson)
        };
        innerFunction();
    }
};
anotherPerson.sayHello();
```

## Copying Objects

JavaScript does not have a direct equivalent of a C++ copy constructor. When you assign one object to another using `=`, you are creating a reference to the original object, not a new copy. Changes to the copied object will affect the original.

To create a true copy, you need to perform either a shallow copy or a deep copy.

### Shallow Copy

A shallow copy creates a new object, but it copies the references to the nested objects. So, if the original object contains other objects, the copied object will still refer to the same nested objects.

Common ways to perform a shallow copy:
-   **Spread syntax (`...`)**: For objects and arrays.
-   **`Object.assign()`**: Copies all enumerable own properties from one or more source objects to a target object.

### Deep Copy

A deep copy creates a new object and recursively copies all nested objects. This means that changes to the copied object will not affect the original, even for nested structures.

Common ways to perform a deep copy:
-   **`JSON.parse(JSON.stringify(object))`**: This is a simple way to deep copy objects that are JSON-safe (i.e., contain no functions, `undefined`, `NaN`, `Infinity`, or circular references).
-   **External libraries**: For complex objects or objects that are not JSON-safe, libraries like Lodash (`_.cloneDeep()`) are often used.

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

## Getters and Setters

In JavaScript, getters and setters provide a way to get and set the values of an object's properties, while allowing for more control over how the properties are accessed and modified. They are defined using the `get` and `set` keywords.

-   **Getters**: A getter is a method that gets the value of a specific property.
-   **Setters**: A setter is a method that sets the value of a specific property. Setters can include validation logic.

### JavaScript Example

```javascript
class Student {
    #name;
    #age;

    get name() {
        return this.#name;
    }

    set name(newName) {
        this.#name = newName;
    }

    get age() {
        return this.#age;
    }

    set age(newAge) {
        if (newAge > 0) {
            this.#age = newAge;
        }
    }
}

const s1 = new Student();
s1.name = "Lohit";
s1.age = 21;

console.log(`Name: ${s1.name}`);
console.log(`Age: ${s1.age}`);
```

## Constructors

In JavaScript, the `constructor` is a special method for creating and initializing an object created with a `class`.

-   **What is it?** A special method for creating and initializing an object. There can only be one special method with the name "constructor" in a class.
-   **Is it public or private?** The constructor method is public.
-   **What if you don't mention a constructor?** If you do not provide a constructor, a default constructor is created for you. For a base class, the default constructor is `constructor() {}`. For a derived class, the default constructor is `constructor(...args) { super(...args); }`.

### Types of Constructors in JavaScript

1.  **Default Constructor**: A constructor that takes no arguments. If you don't define a constructor, a default one is provided.
2.  **Parameterized Constructor**: A constructor that accepts arguments to initialize the properties of the object.

### Constructor Overloading

JavaScript does not support constructor overloading in the same way as languages like C++. A class can only have one constructor.

However, you can achieve similar functionality by using default parameters or by checking the number and type of arguments passed to the constructor.

## The `this` Keyword

In JavaScript, the `this` keyword refers to the context in which a function is executed. Its value is determined by how the function is called, not where it is defined.

-   **What is `this`?** It's a special keyword that refers to the object that is currently executing the code.
-   **How `this` is determined:**
    1.  **Global context**: In the global execution context (outside of any function), `this` refers to the global object (e.g., `window` in browsers, `global` in Node.js).
    2.  **Object method**: When a function is called as a method of an object, `this` refers to the object itself.
    3.  **Constructor**: When a function is used as a constructor (with the `new` keyword), `this` refers to the newly created instance.
    4.  **Explicit binding**: Methods like `call()`, `apply()`, and `bind()` can explicitly set the value of `this`.
    5.  **Arrow functions**: Arrow functions do not have their own `this` context; they inherit `this` from their enclosing lexical context.

### JavaScript Example

```javascript
// 1. Global context
console.log(this === window); // In browsers, true (or global in Node.js)

// 2. Object method
const person = {
    name: "Lohit",
    greet: function() {
        console.log(`Hello, my name is ${this.name}`);
    }
};
person.greet(); // 'this' refers to 'person'

// 3. Constructor
class Car {
    constructor(make) {
        this.make = make;
    }
}
const myCar = new Car("Toyota");
console.log(myCar.make); // 'this' refers to 'myCar'

// 4. Explicit binding with call()
function introduce(age) {
    console.log(`I am ${this.name} and I am ${age} years old.`);
}
introduce.call(person, 21); // 'this' is explicitly set to 'person'

// 5. Arrow function (lexical 'this')
const anotherPerson = {
    name: "Jane",
    sayHello: function() {
        const innerFunction = () => {
            console.log(`Hi, I'm ${this.name}`); // 'this' is inherited from sayHello's context (anotherPerson)
        };
        innerFunction();
    }
};
anotherPerson.sayHello();
```

## Copying Objects

JavaScript does not have a direct equivalent of a C++ copy constructor. When you assign one object to another using `=`, you are creating a reference to the original object, not a new copy. Changes to the copied object will affect the original.

To create a true copy, you need to perform either a shallow copy or a deep copy.

### Shallow Copy

A shallow copy creates a new object, but it copies the references to the nested objects. So, if the original object contains other objects, the copied object will still refer to the same nested objects.

Common ways to perform a shallow copy:
-   **Spread syntax (`...`)**: For objects and arrays.
-   **`Object.assign()`**: Copies all enumerable own properties from one or more source objects to a target object.

### Deep Copy

A deep copy creates a new object and recursively copies all nested objects. This means that changes to the copied object will not affect the original, even for nested structures.

Common ways to perform a deep copy:
-   **`JSON.parse(JSON.stringify(object))`**: This is a simple way to deep copy objects that are JSON-safe (i.e., contain no functions, `undefined`, `NaN`, `Infinity`, or circular references).
-   **External libraries**: For complex objects or objects that are not JSON-safe, libraries like Lodash (`_.cloneDeep()`) are often used.

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

## Getters and Setters

In JavaScript, getters and setters provide a way to get and set the values of an object's properties, while allowing for more control over how the properties are accessed and modified. They are defined using the `get` and `set` keywords.

-   **Getters**: A getter is a method that gets the value of a specific property.
-   **Setters**: A setter is a method that sets the value of a specific property. Setters can include validation logic.

### JavaScript Example

```javascript
class Student {
    #name;
    #age;

    get name() {
        return this.#name;
    }

    set name(newName) {
        this.#name = newName;
    }

    get age() {
        return this.#age;
    }

    set age(newAge) {
        if (newAge > 0) {
            this.#age = newAge;
        }
    }
}

const s1 = new Student();
s1.name = "Lohit";
s1.age = 21;

console.log(`Name: ${s1.name}`);
console.log(`Age: ${s1.age}`);
```

## Constructors

In JavaScript, the `constructor` is a special method for creating and initializing an object created with a `class`.

-   **What is it?** A special method for creating and initializing an object. There can only be one special method with the name "constructor" in a class.
-   **Is it public or private?** The constructor method is public.
-   **What if you don't mention a constructor?** If you do not provide a constructor, a default constructor is created for you. For a base class, the default constructor is `constructor() {}`. For a derived class, the default constructor is `constructor(...args) { super(...args); }`.

### Types of Constructors in JavaScript

1.  **Default Constructor**: A constructor that takes no arguments. If you don't define a constructor, a default one is provided.
2.  **Parameterized Constructor**: A constructor that accepts arguments to initialize the properties of the object.

### Constructor Overloading

JavaScript does not support constructor overloading in the same way as languages like C++. A class can only have one constructor.

However, you can achieve similar functionality by using default parameters or by checking the number and type of arguments passed to the constructor.

## The `this` Keyword

In JavaScript, the `this` keyword refers to the context in which a function is executed. Its value is determined by how the function is called, not where it is defined.

-   **What is `this`?** It's a special keyword that refers to the object that is currently executing the code.
-   **How `this` is determined:**
    1.  **Global context**: In the global execution context (outside of any function), `this` refers to the global object (e.g., `window` in browsers, `global` in Node.js).
    2.  **Object method**: When a function is called as a method of an object, `this` refers to the object itself.
    3.  **Constructor**: When a function is used as a constructor (with the `new` keyword), `this` refers to the newly created instance.
    4.  **Explicit binding**: Methods like `call()`, `apply()`, and `bind()` can explicitly set the value of `this`.
    5.  **Arrow functions**: Arrow functions do not have their own `this` context; they inherit `this` from their enclosing lexical context.

### JavaScript Example

```javascript
// 1. Global context
console.log(this === window); // In browsers, true (or global in Node.js)

// 2. Object method
const person = {
    name: "Lohit",
    greet: function() {
        console.log(`Hello, my name is ${this.name}`);
    }
};
person.greet(); // 'this' refers to 'person'

// 3. Constructor
class Car {
    constructor(make) {
        this.make = make;
    }
}
const myCar = new Car("Toyota");
console.log(myCar.make); // 'this' refers to 'myCar'

// 4. Explicit binding with call()
function introduce(age) {
    console.log(`I am ${this.name} and I am ${age} years old.`);
}
introduce.call(person, 21); // 'this' is explicitly set to 'person'

// 5. Arrow function (lexical 'this')
const anotherPerson = {
    name: "Jane",
    sayHello: function() {
        const innerFunction = () => {
            console.log(`Hi, I'm ${this.name}`); // 'this' is inherited from sayHello's context (anotherPerson)
        };
        innerFunction();
    }
};
anotherPerson.sayHello();
```

## Copying Objects

JavaScript does not have a direct equivalent of a C++ copy constructor. When you assign one object to another using `=`, you are creating a reference to the original object, not a new copy. Changes to the copied object will affect the original.

To create a true copy, you need to perform either a shallow copy or a deep copy.

### Shallow Copy

A shallow copy creates a new object, but it copies the references to the nested objects. So, if the original object contains other objects, the copied object will still refer to the same nested objects.

Common ways to perform a shallow copy:
-   **Spread syntax (`...`)**: For objects and arrays.
-   **`Object.assign()`**: Copies all enumerable own properties from one or more source objects to a target object.

### Deep Copy

A deep copy creates a new object and recursively copies all nested objects. This means that changes to the copied object will not affect the original, even for nested structures.

Common ways to perform a deep copy:
-   **`JSON.parse(JSON.stringify(object))`**: This is a simple way to deep copy objects that are JSON-safe (i.e., contain no functions, `undefined`, `NaN`, `Infinity`, or circular references).
-   **External libraries**: For complex objects or objects that are not JSON-safe, libraries like Lodash (`_.cloneDeep()`) are often used.

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

## Getters and Setters

In JavaScript, getters and setters provide a way to get and set the values of an object's properties, while allowing for more control over how the properties are accessed and modified. They are defined using the `get` and `set` keywords.

-   **Getters**: A getter is a method that gets the value of a specific property.
-   **Setters**: A setter is a method that sets the value of a specific property. Setters can include validation logic.

### JavaScript Example

```javascript
class Student {
    #name;
    #age;

    get name() {
        return this.#name;
    }

    set name(newName) {
        this.#name = newName;
    }

    get age() {
        return this.#age;
    }

    set age(newAge) {
        if (newAge > 0) {
            this.#age = newAge;
        }
    }
}

const s1 = new Student();
s1.name = "Lohit";
s1.age = 21;

console.log(`Name: ${s1.name}`);
console.log(`Age: ${s1.age}`);
```

## Constructors

In JavaScript, the `constructor` is a special method for creating and initializing an object created with a `class`.

-   **What is it?** A special method for creating and initializing an object. There can only be one special method with the name "constructor" in a class.
-   **Is it public or private?** The constructor method is public.
-   **What if you don't mention a constructor?** If you do not provide a constructor, a default constructor is created for you. For a base class, the default constructor is `constructor() {}`. For a derived class, the default constructor is `constructor(...args) { super(...args); }`.

### Types of Constructors in JavaScript

1.  **Default Constructor**: A constructor that takes no arguments. If you don't define a constructor, a default one is provided.
2.  **Parameterized Constructor**: A constructor that accepts arguments to initialize the properties of the object.

### Constructor Overloading

JavaScript does not support constructor overloading in the same way as languages like C++. A class can only have one constructor.

However, you can achieve similar functionality by using default parameters or by checking the number and type of arguments passed to the constructor.

## The `this` Keyword

In JavaScript, the `this` keyword refers to the context in which a function is executed. Its value is determined by how the function is called, not where it is defined.

-   **What is `this`?** It's a special keyword that refers to the object that is currently executing the code.
-   **How `this` is determined:**
    1.  **Global context**: In the global execution context (outside of any function), `this` refers to the global object (e.g., `window` in browsers, `global` in Node.js).
    2.  **Object method**: When a function is called as a method of an object, `this` refers to the object itself.
    3.  **Constructor**: When a function is used as a constructor (with the `new` keyword), `this` refers to the newly created instance.
    4.  **Explicit binding**: Methods like `call()`, `apply()`, and `bind()` can explicitly set the value of `this`.
    5.  **Arrow functions**: Arrow functions do not have their own `this` context; they inherit `this` from their enclosing lexical context.

### JavaScript Example

```javascript
// 1. Global context
console.log(this === window); // In browsers, true (or global in Node.js)

// 2. Object method
const person = {
    name: "Lohit",
    greet: function() {
        console.log(`Hello, my name is ${this.name}`);
    }
};
person.greet(); // 'this' refers to 'person'

// 3. Constructor
class Car {
    constructor(make) {
        this.make = make;
    }
}
const myCar = new Car("Toyota");
console.log(myCar.make); // 'this' refers to 'myCar'

// 4. Explicit binding with call()
function introduce(age) {
    console.log(`I am ${this.name} and I am ${age} years old.`);
}
introduce.call(person, 21); // 'this' is explicitly set to 'person'

// 5. Arrow function (lexical 'this')
const anotherPerson = {
    name: "Jane",
    sayHello: function() {
        const innerFunction = () => {
            console.log(`Hi, I'm ${this.name}`); // 'this' is inherited from sayHello's context (anotherPerson)
        };
        innerFunction();
    }
};
anotherPerson.sayHello();
```

## Copying Objects

JavaScript does not have a direct equivalent of a C++ copy constructor. When you assign one object to another using `=`, you are creating a reference to the original object, not a new copy. Changes to the copied object will affect the original.

To create a true copy, you need to perform either a shallow copy or a deep copy.

### Shallow Copy

A shallow copy creates a new object, but it copies the references to the nested objects. So, if the original object contains other objects, the copied object will still refer to the same nested objects.

Common ways to perform a shallow copy:
-   **Spread syntax (`...`)**: For objects and arrays.
-   **`Object.assign()`**: Copies all enumerable own properties from one or more source objects to a target object.

### Deep Copy

A deep copy creates a new object and recursively copies all nested objects. This means that changes to the copied object will not affect the original, even for nested structures.

Common ways to perform a deep copy:
-   **`JSON.parse(JSON.stringify(object))`**: This is a simple way to deep copy objects that are JSON-safe (i.e., contain no functions, `undefined`, `NaN`, `Infinity`, or circular references).
-   **External libraries**: For complex objects or objects that are not JSON-safe, libraries like Lodash (`_.cloneDeep()`) are often used.

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

## Getters and Setters

In JavaScript, getters and setters provide a way to get and set the values of an object's properties, while allowing for more control over how the properties are accessed and modified. They are defined using the `get` and `set` keywords.

-   **Getters**: A getter is a method that gets the value of a specific property.
-   **Setters**: A setter is a method that sets the value of a specific property. Setters can include validation logic.

### JavaScript Example

```javascript
class Student {
    #name;
    #age;

    get name() {
        return this.#name;
    }

    set name(newName) {
        this.#name = newName;
    }

    get age() {
        return this.#age;
    }

    set age(newAge) {
        if (newAge > 0) {
            this.#age = newAge;
        }
    }
}

const s1 = new Student();
s1.name = "Lohit";
s1.age = 21;

console.log(`Name: ${s1.name}`);
console.log(`Age: ${s1.age}`);
```

## Constructors

In JavaScript, the `constructor` is a special method for creating and initializing an object created with a `class`.

-   **What is it?** A special method for creating and initializing an object. There can only be one special method with the name "constructor" in a class.
-   **Is it public or private?** The constructor method is public.
-   **What if you don't mention a constructor?** If you do not provide a constructor, a default constructor is created for you. For a base class, the default constructor is `constructor() {}`. For a derived class, the default constructor is `constructor(...args) { super(...args); }`.

### Types of Constructors in JavaScript

1.  **Default Constructor**: A constructor that takes no arguments. If you don't define a constructor, a default one is provided.
2.  **Parameterized Constructor**: A constructor that accepts arguments to initialize the properties of the object.

### Constructor Overloading

JavaScript does not support constructor overloading in the same way as languages like C++. A class can only have one constructor.

However, you can achieve similar functionality by using default parameters or by checking the number and type of arguments passed to the constructor.

## The `this` Keyword

In JavaScript, the `this` keyword refers to the context in which a function is executed. Its value is determined by how the function is called, not where it is defined.

-   **What is `this`?** It's a special keyword that refers to the object that is currently executing the code.
-   **How `this` is determined:**
    1.  **Global context**: In the global execution context (outside of any function), `this` refers to the global object (e.g., `window` in browsers, `global` in Node.js).
    2.  **Object method**: When a function is called as a method of an object, `this` refers to the object itself.
    3.  **Constructor**: When a function is used as a constructor (with the `new` keyword), `this` refers to the newly created instance.
    4.  **Explicit binding**: Methods like `call()`, `apply()`, and `bind()` can explicitly set the value of `this`.
    5.  **Arrow functions**: Arrow functions do not have their own `this` context; they inherit `this` from their enclosing lexical context.

### JavaScript Example

```javascript
// 1. Global context
console.log(this === window); // In browsers, true (or global in Node.js)

// 2. Object method
const person = {
    name: "Lohit",
    greet: function() {
        console.log(`Hello, my name is ${this.name}`);
    }
};
person.greet(); // 'this' refers to 'person'

// 3. Constructor
class Car {
    constructor(make) {
        this.make = make;
    }
}
const myCar = new Car("Toyota");
console.log(myCar.make); // 'this' refers to 'myCar'

// 4. Explicit binding with call()
function introduce(age) {
    console.log(`I am ${this.name} and I am ${age} years old.`);
}
introduce.call(person, 21); // 'this' is explicitly set to 'person'

// 5. Arrow function (lexical 'this')
const anotherPerson = {
    name: "Jane",
    sayHello: function() {
        const innerFunction = () => {
            console.log(`Hi, I'm ${this.name}`); // 'this' is inherited from sayHello's context (anotherPerson)
        };
        innerFunction();
    }
};
anotherPerson.sayHello();
```

## Copying Objects

JavaScript does not have a direct equivalent of a C++ copy constructor. When you assign one object to another using `=`, you are creating a reference to the original object, not a new copy. Changes to the copied object will affect the original.

To create a true copy, you need to perform either a shallow copy or a deep copy.

### Shallow Copy

A shallow copy creates a new object, but it copies the references to the nested objects. So, if the original object contains other objects, the copied object will still refer to the same nested objects.

Common ways to perform a shallow copy:
-   **Spread syntax (`...`)**: For objects and arrays.
-   **`Object.assign()`**: Copies all enumerable own properties from one or more source objects to a target object.

### Deep Copy

A deep copy creates a new object and recursively copies all nested objects. This means that changes to the copied object will not affect the original, even for nested structures.

Common ways to perform a deep copy:
-   **`JSON.parse(JSON.stringify(object))`**: This is a simple way to deep copy objects that are JSON-safe (i.e., contain no functions, `undefined`, `NaN`, `Infinity`, or circular references).
-   **External libraries**: For complex objects or objects that are not JSON-safe, libraries like Lodash (`_.cloneDeep()`) are often used.

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

## Getters and Setters

In JavaScript, getters and setters provide a way to get and set the values of an object's properties, while allowing for more control over how the properties are accessed and modified. They are defined using the `get` and `set` keywords.

-   **Getters**: A getter is a method that gets the value of a specific property.
-   **Setters**: A setter is a method that sets the value of a specific property. Setters can include validation logic.

### JavaScript Example

```javascript
class Student {
    #name;
    #age;

    get name() {
        return this.#name;
    }

    set name(newName) {
        this.#name = newName;
    }

    get age() {
        return this.#age;
    }

    set age(newAge) {
        if (newAge > 0) {
            this.#age = newAge;
        }
    }
}

const s1 = new Student();
s1.name = "Lohit";
s1.age = 21;

console.log(`Name: ${s1.name}`);
console.log(`Age: ${s1.age}`);
```

## Constructors

In JavaScript, the `constructor` is a special method for creating and initializing an object created with a `class`.

-   **What is it?** A special method for creating and initializing an object. There can only be one special method with the name "constructor" in a class.
-   **Is it public or private?** The constructor method is public.
-   **What if you don't mention a constructor?** If you do not provide a constructor, a default constructor is created for you. For a base class, the default constructor is `constructor() {}`. For a derived class, the default constructor is `constructor(...args) { super(...args); }`.

### Types of Constructors in JavaScript

1.  **Default Constructor**: A constructor that takes no arguments. If you don't define a constructor, a default one is provided.
2.  **Parameterized Constructor**: A constructor that accepts arguments to initialize the properties of the object.

### Constructor Overloading

JavaScript does not support constructor overloading in the same way as languages like C++. A class can only have one constructor.

However, you can achieve similar functionality by using default parameters or by checking the number and type of arguments passed to the constructor.

## The `this` Keyword

In JavaScript, the `this` keyword refers to the context in which a function is executed. Its value is determined by how the function is called, not where it is defined.

-   **What is `this`?** It's a special keyword that refers to the object that is currently executing the code.
-   **How `this` is determined:**
    1.  **Global context**: In the global execution context (outside of any function), `this` refers to the global object (e.g., `window` in browsers, `global` in Node.js).
    2.  **Object method**: When a function is called as a method of an object, `this` refers to the object itself.
    3.  **Constructor**: When a function is used as a constructor (with the `new` keyword), `this` refers to the newly created instance.
    4.  **Explicit binding**: Methods like `call()`, `apply()`, and `bind()` can explicitly set the value of `this`.
    5.  **Arrow functions**: Arrow functions do not have their own `this` context; they inherit `this` from their enclosing lexical context.

### JavaScript Example

```javascript
// 1. Global context
console.log(this === window); // In browsers, true (or global in Node.js)

// 2. Object method
const person = {
    name: "Lohit",
    greet: function() {
        console.log(`Hello, my name is ${this.name}`);
    }
};
person.greet(); // 'this' refers to 'person'

// 3. Constructor
class Car {
    constructor(make) {
        this.make = make;
    }
}
const myCar = new Car("Toyota");
console.log(myCar.make); // 'this' refers to 'myCar'

// 4. Explicit binding with call()
function introduce(age) {
    console.log(`I am ${this.name} and I am ${age} years old.`);
}
introduce.call(person, 21); // 'this' is explicitly set to 'person'

// 5. Arrow function (lexical 'this')
const anotherPerson = {
    name: "Jane",
    sayHello: function() {
        const innerFunction = () => {
            console.log(`Hi, I'm ${this.name}`); // 'this' is inherited from sayHello's context (anotherPerson)
        };
        innerFunction();
    }
};
anotherPerson.sayHello();
```

## Copying Objects

JavaScript does not have a direct equivalent of a C++ copy constructor. When you assign one object to another using `=`, you are creating a reference to the original object, not a new copy. Changes to the copied object will affect the original.

To create a true copy, you need to perform either a shallow copy or a deep copy.

### Shallow Copy

A shallow copy creates a new object, but it copies the references to the nested objects. So, if the original object contains other objects, the copied object will still refer to the same nested objects.

Common ways to perform a shallow copy:
-   **Spread syntax (`...`)**: For objects and arrays.
-   **`Object.assign()`**: Copies all enumerable own properties from one or more source objects to a target object.

### Deep Copy

A deep copy creates a new object and recursively copies all nested objects. This means that changes to the copied object will not affect the original, even for nested structures.

Common ways to perform a deep copy:
-   **`JSON.parse(JSON.stringify(object))`**: This is a simple way to deep copy objects that are JSON-safe (i.e., contain no functions, `undefined`, `NaN`, `Infinity`, or circular references).
-   **External libraries**: For complex objects or objects that are not JSON-safe, libraries like Lodash (`_.cloneDeep()`) are often used.

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

## Getters and Setters

In JavaScript, getters and setters provide a way to get and set the values of an object's properties, while allowing for more control over how the properties are accessed and modified. They are defined using the `get` and `set` keywords.

-   **Getters**: A getter is a method that gets the value of a specific property.
-   **Setters**: A setter is a method that sets the value of a specific property. Setters can include validation logic.

### JavaScript Example

```javascript
class Student {
    #name;
    #age;

    get name() {
        return this.#name;
    }

    set name(newName) {
        this.#name = newName;
    }

    get age() {
        return this.#age;
    }

    set age(newAge) {
        if (newAge > 0) {
            this.#age = newAge;
        }
    }
}

const s1 = new Student();
s1.name = "Lohit";
s1.age = 21;

console.log(`Name: ${s1.name}`);
console.log(`Age: ${s1.age}`);
```

## Constructors

In JavaScript, the `constructor` is a special method for creating and initializing an object created with a `class`.

-   **What is it?** A special method for creating and initializing an object. There can only be one special method with the name "constructor" in a class.
-   **Is it public or private?** The constructor method is public.
-   **What if you don't mention a constructor?** If you do not provide a constructor, a default constructor is created for you. For a base class, the default constructor is `constructor() {}`. For a derived class, the default constructor is `constructor(...args) { super(...args); }`.

### Types of Constructors in JavaScript

1.  **Default Constructor**: A constructor that takes no arguments. If you't define a constructor, a default one is provided.
2.  **Parameterized Constructor**: A constructor that accepts arguments to initialize the properties of the object.

### Constructor Overloading

JavaScript does not support constructor overloading in the same way as languages like C++. A class can only have one constructor.

However, you can achieve similar functionality by using default parameters or by checking the number and type of arguments passed to the constructor.

## The `this` Keyword

In JavaScript, the `this` keyword refers to the context in which a function is executed. Its value is determined by how the function is called, not where it is defined.

-   **What is `this`?** It's a special keyword that refers to the object that is currently executing the code.
-   **How `this` is determined:**
    1.  **Global context**: In the global execution context (outside of any function), `this` refers to the global object (e.g., `window` in browsers, `global` in Node.js).
    2.  **Object method**: When a function is called as a method of an object, `this` refers to the object itself.
    3.  **Constructor**: When a function is used as a constructor (with the `new` keyword), `this` refers to the newly created instance.
    4.  **Explicit binding**: Methods like `call()`, `apply()`, and `bind()` can explicitly set the value of `this`.
    5.  **Arrow functions**: Arrow functions do not have their own `this` context; they inherit `this` from their enclosing lexical context.

### JavaScript Example

```javascript
// 1. Global context
console.log(this === window); // In browsers, true (or global in Node.js)

// 2. Object method
const person = {
    name: "Lohit",
    greet: function() {
        console.log(`Hello, my name is ${this.name}`);
    }
};
person.greet(); // 'this' refers to 'person'

// 3. Constructor
class Car {
    constructor(make) {
        this.make = make;
    }
}
const myCar = new Car("Toyota");
console.log(myCar.make); // 'this' refers to 'myCar'

// 4. Explicit binding with call()
function introduce(age) {
    console.log(`I am ${this.name} and I am ${age} years old.`);
}
introduce.call(person, 21); // 'this' is explicitly set to 'person'

// 5. Arrow function (lexical 'this')
const anotherPerson = {
    name: "Jane",
    sayHello: function() {
        const innerFunction = () => {
            console.log(`Hi, I'm ${this.name}`); // 'this' is inherited from sayHello's context (anotherPerson)
        };
        innerFunction();
    }
};
anotherPerson.sayHello();
```

## Copying Objects

JavaScript does not have a direct equivalent of a C++ copy constructor. When you assign one object to another using `=`, you are creating a reference to the original object, not a new copy. Changes to the copied object will affect the original.

To create a true copy, you need to perform either a shallow copy or a deep copy.

### Shallow Copy

A shallow copy creates a new object, but it copies the references to the nested objects. So, if the original object contains other objects, the copied object will still refer to the same nested objects.

Common ways to perform a shallow copy:
-   **Spread syntax (`...`)**: For objects and arrays.
-   **`Object.assign()`**: Copies all enumerable own properties from one or more source objects to a target object.

### Deep Copy

A deep copy creates a new object and recursively copies all nested objects. This means that changes to the copied object will not affect the original, even for nested structures.

Common ways to perform a deep copy:
-   **`JSON.parse(JSON.stringify(object))`**: This is a simple way to deep copy objects that are JSON-safe (i.e., contain no functions, `undefined`, `NaN`, `Infinity`, or circular references).
-   **External libraries**: For complex objects or objects that are not JSON-safe, libraries like Lodash (`_.cloneDeep()`) are often used.

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

## Getters and Setters

In JavaScript, getters and setters provide a way to get and set the values of an object's properties, while allowing for more control over how the properties are accessed and modified. They are defined using the `get` and `set` keywords.

-   **Getters**: A getter is a method that gets the value of a specific property.
-   **Setters**: A setter is a method that sets the value of a specific property. Setters can include validation logic.

### JavaScript Example

```javascript
class Student {
    #name;
    #age;

    get name() {
        return this.#name;
    }

    set name(newName) {
        this.#name = newName;
    }

    get age() {
        return this.#age;
    }

    set age(newAge) {
        if (newAge > 0) {
            this.#age = newAge;
        }
    }
}

const s1 = new Student();
s1.name = "Lohit";
s1.age = 21;

console.log(`Name: ${s1.name}`);
console.log(`Age: ${s1.age}`);
```

## Constructors

In JavaScript, the `constructor` is a special method for creating and initializing an object created with a `class`.

-   **What is it?** A special method for creating and initializing an object. There can only be one special method with the name "constructor" in a class.
-   **Is it public or private?** The constructor method is public.
-   **What if you don't mention a constructor?** If you do not provide a constructor, a default constructor is created for you. For a base class, the default constructor is `constructor() {}`. For a derived class, the default constructor is `constructor(...args) { super(...args); }`.

### Types of Constructors in JavaScript

1.  **Default Constructor**: A constructor that takes no arguments. If you don't define a constructor, a default one is provided.
2.  **Parameterized Constructor**: A constructor that accepts arguments to initialize the properties of the object.

### Constructor Overloading

JavaScript does not support constructor overloading in the same way as languages like C++. A class can only have one constructor.

However, you can achieve similar functionality by using default parameters or by checking the number and type of arguments passed to the constructor.

## The `this` Keyword

In JavaScript, the `this` keyword refers to the context in which a function is executed. Its value is determined by how the function is called, not where it is defined.

-   **What is `this`?** It's a special keyword that refers to the object that is currently executing the code.
-   **How `this` is determined:**
    1.  **Global context**: In the global execution context (outside of any function), `this` refers to the global object (e.g., `window` in browsers, `global` in Node.js).
    2.  **Object method**: When a function is called as a method of an object, `this` refers to the object itself.
    3.  **Constructor**: When a function is used as a constructor (with the `new` keyword), `this` refers to the newly created instance.
    4.  **Explicit binding**: Methods like `call()`, `apply()`, and `bind()` can explicitly set the value of `this`.
    5.  **Arrow functions**: Arrow functions do not have their own `this` context; they inherit `this` from their enclosing lexical context.

### JavaScript Example

```javascript
// 1. Global context
console.log(this === window); // In browsers, true (or global in Node.js)

// 2. Object method
const person = {
    name: "Lohit",
    greet: function() {
        console.log(`Hello, my name is ${this.name}`);
    }
};
person.greet(); // 'this' refers to 'person'

// 3. Constructor
class Car {
    constructor(make) {
        this.make = make;
    }
}
const myCar = new Car("Toyota");
console.log(myCar.make); // 'this' refers to 'myCar'

// 4. Explicit binding with call()
function introduce(age) {
    console.log(`I am ${this.name} and I am ${age} years old.`);
}
introduce.call(person, 21); // 'this' is explicitly set to 'person'

// 5. Arrow function (lexical 'this')
const anotherPerson = {
    name: "Jane",
    sayHello: function() {
        const innerFunction = () => {
            console.log(`Hi, I'm ${this.name}`); // 'this' is inherited from sayHello's context (anotherPerson)
        };
        innerFunction();
    }
};
anotherPerson.sayHello();
```

## Copying Objects

JavaScript does not have a direct equivalent of a C++ copy constructor. When you assign one object to another using `=`, you are creating a reference to the original object, not a new copy. Changes to the copied object will affect the original.

To create a true copy, you need to perform either a shallow copy or a deep copy.

### Shallow Copy

A shallow copy creates a new object, but it copies the references to the nested objects. So, if the original object contains other objects, the copied object will still refer to the same nested objects.

Common ways to perform a shallow copy:
-   **Spread syntax (`...`)**: For objects and arrays.
-   **`Object.assign()`**: Copies all enumerable own properties from one or more source objects to a target object.

### Deep Copy

A deep copy creates a new object and recursively copies all nested objects. This means that changes to the copied object will not affect the original, even for nested structures.

Common ways to perform a deep copy:
-   **`JSON.parse(JSON.stringify(object))`**: This is a simple way to deep copy objects that are JSON-safe (i.e., contain no functions, `undefined`, `NaN`, `Infinity`, or circular references).
-   **External libraries**: For complex objects or objects that are not JSON-safe, libraries like Lodash (`_.cloneDeep()`) are often used.

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

## Getters and Setters

In JavaScript, getters and setters provide a way to get and set the values of an object's properties, while allowing for more control over how the properties are accessed and modified. They are defined using the `get` and `set` keywords.

-   **Getters**: A getter is a method that gets the value of a specific property.
-   **Setters**: A setter is a method that sets the value of a specific property. Setters can include validation logic.

### JavaScript Example

```javascript
class Student {
    #name;
    #age;

    get name() {
        return this.#name;
    }

    set name(newName) {
        this.#name = newName;
    }

    get age() {
        return this.#age;
    }

    set age(newAge) {
        if (newAge > 0) {
            this.#age = newAge;
        }
    }
}

const s1 = new Student();
s1.name = "Lohit";
s1.age = 21;

console.log(`Name: ${s1.name}`);
console.log(`Age: ${s1.age}`);
```

## Constructors

In JavaScript, the `constructor` is a special method for creating and initializing an object created with a `class`.

-   **What is it?** A special method for creating and initializing an object. There can only be one special method with the name "constructor" in a class.
-   **Is it public or private?** The constructor method is public.
-   **What if you don't mention a constructor?** If you do not provide a constructor, a default constructor is created for you. For a base class, the default constructor is `constructor() {}`. For a derived class, the default constructor is `constructor(...args) { super(...args); }`.

### Types of Constructors in JavaScript

1.  **Default Constructor**: A constructor that takes no arguments. If you don't define a constructor, a default one is provided.
2.  **Parameterized Constructor**: A constructor that accepts arguments to initialize the properties of the object.

### Constructor Overloading

JavaScript does not support constructor overloading in the same way as languages like C++. A class can only have one constructor.

However, you can achieve similar functionality by using default parameters or by checking the number and type of arguments passed to the constructor.

## The `this` Keyword

In JavaScript, the `this` keyword refers to the context in which a function is executed. Its value is determined by how the function is called, not where it is defined.

-   **What is `this`?** It's a special keyword that refers to the object that is currently executing the code.
-   **How `this` is determined:**
    1.  **Global context**: In the global execution context (outside of any function), `this` refers to the global object (e.g., `window` in browsers, `global` in Node.js).
    2.  **Object method**: When a function is called as a method of an object, `this` refers to the object itself.
    3.  **Constructor**: When a function is used as a constructor (with the `new` keyword), `this` refers to the newly created instance.
    4.  **Explicit binding**: Methods like `call()`, `apply()`, and `bind()` can explicitly set the value of `this`.
    5.  **Arrow functions**: Arrow functions do not have their own `this` context; they inherit `this` from their enclosing lexical context.

### JavaScript Example

```javascript
// 1. Global context
console.log(this === window); // In browsers, true (or global in Node.js)

// 2. Object method
const person = {
    name: "Lohit",
    greet: function() {
        console.log(`Hello, my name is ${this.name}`);
    }
};
person.greet(); // 'this' refers to 'person'

// 3. Constructor
class Car {
    constructor(make) {
        this.make = make;
    }
}
const myCar = new Car("Toyota");
console.log(myCar.make); // 'this' refers to 'myCar'

// 4. Explicit binding with call()
function introduce(age) {
    console.log(`I am ${this.name} and I am ${age} years old.`);
}
introduce.call(person, 21); // 'this' is explicitly set to 'person'

// 5. Arrow function (lexical 'this')
const anotherPerson = {
    name: "Jane",
    sayHello: function() {
        const innerFunction = () => {
            console.log(`Hi, I'm ${this.name}`); // 'this' is inherited from sayHello's context (anotherPerson)
        };
        innerFunction();
    }
};
anotherPerson.sayHello();
```

## Copying Objects

JavaScript does not have a direct equivalent of a C++ copy constructor. When you assign one object to another using `=`, you are creating a reference to the original object, not a new copy. Changes to the copied object will affect the original.

To create a true copy, you need to perform either a shallow copy or a deep copy.

### Shallow Copy

A shallow copy creates a new object, but it copies the references to the nested objects. So, if the original object contains other objects, the copied object will still refer to the same nested objects.

Common ways to perform a shallow copy:
-   **Spread syntax (`...`)**: For objects and arrays.
-   **`Object.assign()`**: Copies all enumerable own properties from one or more source objects to a target object.

### Deep Copy

A deep copy creates a new object and recursively copies all nested objects. This means that changes to the copied object will not affect the original, even for nested structures.

Common ways to perform a deep copy:
-   **`JSON.parse(JSON.stringify(object))`**: This is a simple way to deep copy objects that are JSON-safe (i.e., contain no functions, `undefined`, `NaN`, `Infinity`, or circular references).
-   **External libraries**: For complex objects or objects that are not JSON-safe, libraries like Lodash (`_.cloneDeep()`) are often used.

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

## Getters and Setters

In JavaScript, getters and setters provide a way to get and set the values of an object's properties, while allowing for more control over how the properties are accessed and modified. They are defined using the `get` and `set` keywords.

-   **Getters**: A getter is a method that gets the value of a specific property.
-   **Setters**: A setter is a method that sets the value of a specific property. Setters can include validation logic.

### JavaScript Example

```javascript
class Student {
    #name;
    #age;

    get name() {
        return this.#name;
    }

    set name(newName) {
        this.#name = newName;
    }

    get age() {
        return this.#age;
    }

    set age(newAge) {
        if (newAge > 0) {
            this.#age = newAge;
        }
    }
}

const s1 = new Student();
s1.name = "Lohit";
s1.age = 21;

console.log(`Name: ${s1.name}`);
console.log(`Age: ${s1.age}`);
```

## Constructors

In JavaScript, the `constructor` is a special method for creating and initializing an object created with a `class`.

-   **What is it?** A special method for creating and initializing an object. There can only be one special method with the name "constructor" in a class.
-   **Is it public or private?** The constructor method is public.
-   **What if you don't mention a constructor?** If you do not provide a constructor, a default constructor is created for you. For a base class, the default constructor is `constructor() {}`. For a derived class, the default constructor is `constructor(...args) { super(...args); }`.

### Types of Constructors in JavaScript

1.  **Default Constructor**: A constructor that takes no arguments. If you don't define a constructor, a default one is provided.
2.  **Parameterized Constructor**: A constructor that accepts arguments to initialize the properties of the object.

### Constructor Overloading

JavaScript does not support constructor overloading in the same way as languages like C++. A class can only have one constructor.

However, you can achieve similar functionality by using default parameters or by checking the number and type of arguments passed to the constructor.

## The `this` Keyword

In JavaScript, the `this` keyword refers to the context in which a function is executed. Its value is determined by how the function is called, not where it is defined.

-   **What is `this`?** It's a special keyword that refers to the object that is currently executing the code.
-   **How `this` is determined:**
    1.  **Global context**: In the global execution context (outside of any function), `this` refers to the global object (e.g., `window` in browsers, `global` in Node.js).
    2.  **Object method**: When a function is called as a method of an object, `this` refers to the object itself.
    3.  **Constructor**: When a function is used as a constructor (with the `new` keyword), `this` refers to the newly created instance.
    4.  **Explicit binding**: Methods like `call()`, `apply()`, and `bind()` can explicitly set the value of `this`.
    5.  **Arrow functions**: Arrow functions do not have their own `this` context; they inherit `this` from their enclosing lexical context.

### JavaScript Example

```javascript
// 1. Global context
console.log(this === window); // In browsers, true (or global in Node.js)

// 2. Object method
const person = {
    name: "Lohit",
    greet: function() {
        console.log(`Hello, my name is ${this.name}`);
    }
};
person.greet(); // 'this' refers to 'person'

// 3. Constructor
class Car {
    constructor(make) {
        this.make = make;
    }
}
const myCar = new Car("Toyota");
console.log(myCar.make); // 'this' refers to 'myCar'

// 4. Explicit binding with call()
function introduce(age) {
    console.log(`I am ${this.name} and I am ${age} years old.`);
}
introduce.call(person, 21); // 'this' is explicitly set to 'person'

// 5. Arrow function (lexical 'this')
const anotherPerson = {
    name: "Jane",
    sayHello: function() {
        const innerFunction = () => {
            console.log(`Hi, I'm ${this.name}`); // 'this' is inherited from sayHello's context (anotherPerson)
        };
        innerFunction();
    }
};
anotherPerson.sayHello();
```

## Copying Objects

JavaScript does not have a direct equivalent of a C++ copy constructor. When you assign one object to another using `=`, you are creating a reference to the original object, not a new copy. Changes to the copied object will affect the original.

To create a true copy, you need to perform either a shallow copy or a deep copy.

### Shallow Copy

A shallow copy creates a new object, but it copies the references to the nested objects. So, if the original object contains other objects, the copied object will still refer to the same nested objects.

Common ways to perform a shallow copy:
-   **Spread syntax (`...`)**: For objects and arrays.
-   **`Object.assign()`**: Copies all enumerable own properties from one or more source objects to a target object.

### Deep Copy

A deep copy creates a new object and recursively copies all nested objects. This means that changes to the copied object will not affect the original, even for nested structures.

Common ways to perform a deep copy:
-   **`JSON.parse(JSON.stringify(object))`**: This is a simple way to deep copy objects that are JSON-safe (i.e., contain no functions, `undefined`, `NaN`, `Infinity`, or circular references).
-   **External libraries**: For complex objects or objects that are not JSON-safe, libraries like Lodash (`_.cloneDeep()`) are often used.

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

## Getters and Setters

In JavaScript, getters and setters provide a way to get and set the values of an object's properties, while allowing for more control over how the properties are accessed and modified. They are defined using the `get` and `set` keywords.

-   **Getters**: A getter is a method that gets the value of a specific property.
-   **Setters**: A setter is a method that sets the value of a specific property. Setters can include validation logic.

### JavaScript Example

```javascript
class Student {
    #name;
    #age;

    get name() {
        return this.#name;
    }

    set name(newName) {
        this.#name = newName;
    }

    get age() {
        return this.#age;
    }

    set age(newAge) {
        if (newAge > 0) {
            this.#age = newAge;
        }
    }
}

const s1 = new Student();
s1.name = "Lohit";
s1.age = 21;

console.log(`Name: ${s1.name}`);
console.log(`Age: ${s1.age}`);
```

## Constructors

In JavaScript, the `constructor` is a special method for creating and initializing an object created with a `class`.

-   **What is it?** A special method for creating and initializing an object. There can only be one special method with the name "constructor" in a class.
-   **Is it public or private?** The constructor method is public.
-   **What if you't mention a constructor?** If you do not provide a constructor, a default constructor is created for you. For a base class, the default constructor is `constructor() {}`. For a derived class, the default constructor is `constructor(...args) { super(...args); }`.

### Types of Constructors in JavaScript

1.  **Default Constructor**: A constructor that takes no arguments. If you't define a constructor, a default one is provided.
2.  **Parameterized Constructor**: A constructor that accepts arguments to initialize the properties of the object.

### Constructor Overloading

JavaScript does not support constructor overloading in the same way as languages like C++. A class can only have one constructor.

However, you can achieve similar functionality by using default parameters or by checking the number and type of arguments passed to the constructor.

## The `this` Keyword

In JavaScript, the `this` keyword refers to the context in which a function is executed. Its value is determined by how the function is called, not where it is defined.

-   **What is `this`?** It's a special keyword that refers to the object that is currently executing the code.
-   **How `this` is determined:**
    1.  **Global context**: In the global execution context (outside of any function), `this` refers to the global object (e.g., `window` in browsers, `global` in Node.js).
    2.  **Object method**: When a function is called as a method of an object, `this` refers to the object itself.
    3.  **Constructor**: When a function is used as a constructor (with the `new` keyword), `this` refers to the newly created instance.
    4.  **Explicit binding**: Methods like `call()`, `apply()`, and `bind()` can explicitly set the value of `this`.
    5.  **Arrow functions**: Arrow functions do not have their own `this` context; they inherit `this` from their enclosing lexical context.

### JavaScript Example

```javascript
// 1. Global context
console.log(this === window); // In browsers, true (or global in Node.js)

// 2. Object method
const person = {
    name: "Lohit",
    greet: function() {
        console.log(`Hello, my name is ${this.name}`);
    }
};
person.greet(); // 'this' refers to 'person'

// 3. Constructor
class Car {
    constructor(make) {
        this.make = make;
    }
}
const myCar = new Car("Toyota");
console.log(myCar.make); // 'this' refers to 'myCar'

// 4. Explicit binding with call()
function introduce(age) {
    console.log(`I am ${this.name} and I am ${age} years old.`);
}
introduce.call(person, 21); // 'this' is explicitly set to 'person'

// 5. Arrow function (lexical 'this')
const anotherPerson = {
    name: "Jane",
    sayHello: function() {
        const innerFunction = () => {
            console.log(`Hi, I'm ${this.name}`); // 'this' is inherited from sayHello's context (anotherPerson)
        };
        innerFunction();
    }
};
anotherPerson.sayHello();
```

## Copying Objects

JavaScript does not have a direct equivalent of a C++ copy constructor. When you assign one object to another using `=`, you are creating a reference to the original object, not a new copy. Changes to the copied object will affect the original.

To create a true copy, you need to perform either a shallow copy or a deep copy.

### Shallow Copy

A shallow copy creates a new object, but it copies the references to the nested objects. So, if the original object contains other objects, the copied object will still refer to the same nested objects.

Common ways to perform a shallow copy:
-   **Spread syntax (`...`)**: For objects and arrays.
-   **`Object.assign()`**: Copies all enumerable own properties from one or more source objects to a target object.

### Deep Copy

A deep copy creates a new object and recursively copies all nested objects. This means that changes to the copied object will not affect the original, even for nested structures.

Common ways to perform a deep copy:
-   **`JSON.parse(JSON.stringify(object))`**: This is a simple way to deep copy objects that are JSON-safe (i.e., contain no functions, `undefined`, `NaN`, `Infinity`, or circular references).
-   **External libraries**: For complex objects or objects that are not JSON-safe, libraries like Lodash (`_.cloneDeep()`) are often used.

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

## Getters and Setters

In JavaScript, getters and setters provide a way to get and set the values of an object's properties, while allowing for more control over how the properties are accessed and modified. They are defined using the `get` and `set` keywords.

-   **Getters**: A getter is a method that gets the value of a specific property.
-   **Setters**: A setter is a method that sets the value of a specific property. Setters can include validation logic.

### JavaScript Example

```javascript
class Student {
    #name;
    #age;

    get name() {
        return this.#name;
    }

    set name(newName) {
        this.#name = newName;
    }

    get age() {
        return this.#age;
    }

    set age(newAge) {
        if (newAge > 0) {
            this.#age = newAge;
        }
    }
}

const s1 = new Student();
s1.name = "Lohit";
s1.age = 21;

console.log(`Name: ${s1.name}`);
console.log(`Age: ${s1.age}`);
```

## Constructors

In JavaScript, the `constructor` is a special method for creating and initializing an object created with a `class`.

-   **What is it?** A special method for creating and initializing an object. There can only be one special method with the name "constructor" in a class.
-   **Is it public or private?** The constructor method is public.
-   **What if you't mention a constructor?** If you do not provide a constructor, a default constructor is created for you. For a base class, the default constructor is `constructor() {}`. For a derived class, the default constructor is `constructor(...args) { super(...args); }`.

### Types of Constructors in JavaScript

1.  **Default Constructor**: A constructor that takes no arguments. If you't define a constructor, a default one is provided.
2.  **Parameterized Constructor**: A constructor that accepts arguments to initialize the properties of the object.

### Constructor Overloading

JavaScript does not support constructor overloading in the same way as languages like C++. A class can only have one constructor.

However, you can achieve similar functionality by using default parameters or by checking the number and type of arguments passed to the constructor.

## The `this` Keyword

In JavaScript, the `this` keyword refers to the context in which a function is executed. Its value is determined by how the function is called, not where it is defined.

-   **What is `this`?** It's a special keyword that refers to the object that is currently executing the code.
-   **How `this` is determined:**
    1.  **Global context**: In the global execution context (outside of any function), `this` refers to the global object (e.g., `window` in browsers, `global` in Node.js).
    2.  **Object method**: When a function is called as a method of an object, `this` refers to the object itself.
    3.  **Constructor**: When a function is used as a constructor (with the `new` keyword), `this` refers to the newly created instance.
    4.  **Explicit binding**: Methods like `call()`, `apply()`, and `bind()` can explicitly set the value of `this`.
    5.  **Arrow functions**: Arrow functions do not have their own `this` context; they inherit `this` from their enclosing lexical context.

### JavaScript Example

```javascript
// 1. Global context
console.log(this === window); // In browsers, true (or global in Node.js)

// 2. Object method
const person = {
    name: "Lohit",
    greet: function() {
        console.log(`Hello, my name is ${this.name}`);
    }
};
person.greet(); // 'this' refers to 'person'

// 3. Constructor
class Car {
    constructor(make) {
        this.make = make;
    }
}
const myCar = new Car("Toyota");
console.log(myCar.make); // 'this' refers to 'myCar'

// 4. Explicit binding with call()
function introduce(age) {
    console.log(`I am ${this.name} and I am ${age} years old.`);
}
introduce.call(person, 21); // 'this' is explicitly set to 'person'

// 5. Arrow function (lexical 'this')
const anotherPerson = {
    name: "Jane",
    sayHello: function() {
        const innerFunction = () => {
            console.log(`Hi, I'm ${this.name}`); // 'this' is inherited from sayHello's context (anotherPerson)
        };
        innerFunction();
    }
};
anotherPerson.sayHello();
```

## Copying Objects

JavaScript does not have a direct equivalent of a C++ copy constructor. When you assign one object to another using `=`, you are creating a reference to the original object, not a new copy. Changes to the copied object will affect the original.

To create a true copy, you need to perform either a shallow copy or a deep copy.

### Shallow Copy

A shallow copy creates a new object, but it copies the references to the nested objects. So, if the original object contains other objects, the copied object will still refer to the same nested objects.

Common ways to perform a shallow copy:
-   **Spread syntax (`...`)**: For objects and arrays.
-   **`Object.assign()`**: Copies all enumerable own properties from one or more source objects to a target object.

### Deep Copy

A deep copy creates a new object and recursively copies all nested objects. This means that changes to the copied object will not affect the original, even for nested structures.

Common ways to perform a deep copy:
-   **`JSON.parse(JSON.stringify(object))`**: This is a simple way to deep copy objects that are JSON-safe (i.e., contain no functions, `undefined`, `NaN`, `Infinity`, or circular references).
-   **External libraries**: For complex objects or objects that are not JSON-safe, libraries like Lodash (`_.cloneDeep()`) are often used.

### JavaScript Example

```javascript
class Course {
    constructor(title) {
        this.title = title;
    }
}

class Student {
    constructor(name, course) {
        this.name = name;
        this.course = course;
    }
}

// Original object
const course1 = new Course("Math");
const student1 = new Student("Lohit", course1);

// Shallow copy
const student2 = { ...student1 };

// Deep copy
const student3 = JSON.parse(JSON.stringify(student1));

// Modify the course title
student2.course.title = "Science";

console.log(student1.course.title); // "Science"
console.log(student2.course.title); // "Science"
console.log(student3.course.title); // "Math"
```

## Examples

- [Public Example](./L2_public.js)
- [Private Example](./L2_private.js)
- [Protected Example](./L2_protected_convention.js)
- [Getters and Setters Example](./L3_getters_setters.js)
- [Default Constructor Example](./L4_default_constructor.js)
- [Parameterized Constructor Example](./L4_parameterized_constructor.js)
- [Constructor Overloading Workaround Example](./L5_constructor_overloading_workaround.js)
- [The `this` Keyword Example](./L6_this_keyword.js)
- [Default Copy Constructor Example](./L7_default_copy_constructor.js)
- [Custom Copy Constructor Example](./L8_custom_copy_constructor.js)
- [Garbage Collection Example](./L9_garbage_collection.js)