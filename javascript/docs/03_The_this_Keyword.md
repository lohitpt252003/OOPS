## The `this` Keyword

In JavaScript, the `this` keyword refers to the context in which a function is executed. Its value is determined by how the function is called, not where it is defined.

-   **What is `this`?** It's a special keyword that refers to the object that is currently executing the code.
-   **How `this` is determined:**
    1.  **Global context**: In the global execution context (outside of any function), `this` refers to the global object (e.g., `window` in browsers, `global` in Node.js).
    2.  **Object method**: When a function is called as a method of an object, `this` refers to the object itself.
    3.  **Constructor**: When a function is used as a constructor (with the `new` keyword), `this` refers to the newly created instance.
    4.  **Explicit binding**: Methods like `call()`, `apply()`, and `bind()` can explicitly set the value of `this`.
    5.  **Arrow functions**: Arrow functions do not have their own `this` context; they inherit `this` from their enclosing lexical context.
