## Copying Objects

In Python, assignment statements do not copy objects. They create bindings between a target and an object. When we need a copy, we can use the `copy` module, which provides methods for both shallow and deep copies.

- **Shallow Copy**: Creates a new object but does not create copies of nested objects.
- **Deep Copy**: Creates a new object and recursively copies all nested objects.
