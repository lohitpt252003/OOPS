## Constructors

In JavaScript, the `constructor` is a special method for creating and initializing an object created with a `class`.

-   **What is it?** A special method for creating and initializing an object. There can only be one special method with the name "constructor" in a class.
-   **Is it public or private?** The constructor method is public.
-   **What if you don't mention a constructor?** If you do not provide a constructor, a default constructor is created for you. For a base class, the default constructor is `constructor() {}`. For a derived class, the default constructor is `constructor(...args) { super(...args); }`.

### Types of Constructors in JavaScript

1.  **Default Constructor**: A constructor that takes no arguments. If you don't define a constructor, a default one is provided.
2.  **Parameterized Constructor**: A constructor that accepts arguments to initialize the properties of the object.

### Constructor Overloading

JavaScript does not support constructor overloading. A class can only have one special method named `constructor`. The common workaround is to have a single constructor that checks the number or types of arguments passed to it and behaves accordingly.

-   For a practical code example, see the `L5_constructor_overloading_workaround.js` file.
