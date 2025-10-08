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
