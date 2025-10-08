# Quiz: Constructor Overloading in JavaScript

**Question:** Does JavaScript support constructor overloading? Look at the code from the `L5_constructor_overloading_workaround.js` file. How does it simulate the idea of multiple constructors?

**Code:**

```javascript
class Box {
    // Single constructor with logic to handle different numbers of arguments
    constructor(length, breadth, height) {
        console.log("Constructor called.");

        // If only one argument is provided, treat it as a cube
        if (breadth === undefined && height === undefined) {
            this.length = length;
            this.breadth = length;
            this.height = length;
        } else {
            this.length = length || 0;
            this.breadth = breadth || 0;
            this.height = height || 0;
        }
    }

    getVolume() {
        return this.length * this.breadth * this.height;
    }
}

// Creating objects using the same constructor
let box1 = new Box(); // 0 arguments
console.log(`Volume of box1: ${box1.getVolume()}`);

let box2 = new Box(5.0); // 1 argument
console.log(`Volume of box2: ${box2.getVolume()}`);

let box3 = new Box(10.0, 5.0, 2.0); // 3 arguments
console.log(`Volume of box3: ${box3.getVolume()}`);
```

**Explanation:**

The output will be:

```
Constructor called.
Volume of box1: 0
Constructor called.
Volume of box2: 125
Constructor called.
Volume of box3: 100
```

JavaScript **does not support constructor overloading**. A JavaScript class can only have one method with the name `constructor`.

To work around this limitation, you must use a single constructor and write logic inside it to handle different numbers or types of arguments.

In this example:
1.  `new Box()`: All parameters are `undefined`. The `else` block runs, and the `|| 0` ensures the properties are initialized to 0.
2.  `new Box(5.0)`: `breadth` and `height` are `undefined`. The `if` condition is true, and the object is constructed as a cube.
3.  `new Box(10.0, 5.0, 2.0)`: All arguments are provided. The `if` condition is false, and the `else` block runs, assigning each property its respective value.

This pattern of checking arguments inside the constructor is the standard way to achieve constructor flexibility in JavaScript.