# Quiz: Access Modifier Order in JavaScript

**Question:** In a language like C++, you can switch between `public` and `private` sections. What is the equivalent in JavaScript? What happens if you try to group your methods under a `private` block?

**Explanation:**

This concept is not applicable to JavaScript. Much like Python, JavaScript does not use keywords or blocks like `public:` or `private:` to define member visibility. Access level is determined on a **per-member basis**.

-   By default, all properties and methods are **public**.
-   To make a property or method private, you must prefix its name with a hash (`#`).

The order of definition within the class does not affect the visibility of its members. Each member's access level is determined individually by the presence or absence of the `#` prefix.

For example, the following class is perfectly normal in JavaScript:

```javascript
class Person {
    // Private field
    #name;

    // Public field
    age;

    constructor(name, age) {
        this.#name = name; // Private
        this.age = age;     // Public
    }

    // Public method
    printName() {
        console.log(`Name: ${this.#name}`);
    }

    // Private method
    #getSecret() {
        return "This is a secret";
    }
}
```

There is no concept of grouping members under a specific access modifier block in JavaScript.
