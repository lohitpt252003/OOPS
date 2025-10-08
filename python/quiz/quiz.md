# Quiz: Access Modifier Order in Python

**Question:** In C++, you can switch between `public` and `private` sections to group members. What is the equivalent in Python? What happens if you try to group your methods under a `private` block?

**Explanation:**

This concept does not apply to Python. Python does not use keywords or blocks like `public:` or `private:` to define the visibility of members. Instead, access is determined on a **per-member basis** through naming conventions.

-   If a member name starts with no underscore (e.g., `age`), it is public.
-   If it starts with a single underscore (e.g., `_salary`), it is considered "protected" by convention.
-   If it starts with a double underscore (e.g., `__name`), it is considered "private" and its name is mangled by the interpreter to make it harder to access from outside.

The order in which you define methods or attributes in a Python class has no effect on their visibility. Each member's access level is determined individually by its name, not by its position in the class.

For example, the following class is perfectly normal in Python, and there is no need to group members by visibility:

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
