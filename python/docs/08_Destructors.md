## Destructors

In Python, the `__del__` method is the destructor. It is called when an object's reference count becomes zero and the object is about to be destroyed by the garbage collector.

-   **What is it?** The `__del__` method is a special method that can be defined to perform cleanup tasks before an object is reclaimed.
-   **Purpose:** It can be used for final cleanup, such as closing file handles or database connections.
-   **When is it called?** The `__del__` method is called automatically by the garbage collector, but the exact timing is not guaranteed.

### Default Behavior vs. Custom Destructor (`__del__`)

1.  **Default Behavior (Garbage Collection)**: If you do not define a `__del__` method, the garbage collector will still automatically reclaim the object's memory when it's no longer referenced.
2.  **Custom Destructor (`__del__`)**: You should define a `__del__` method only when you need to perform specific cleanup actions that won't happen automatically.
