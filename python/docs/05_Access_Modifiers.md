## Access Modifiers in Python

Python does not have strict access modifiers like C++ or Java. Instead, it relies on naming conventions to indicate the intended visibility of class members.

1.  **Public**: By default, all members of a class are public.
2.  **Protected (by convention)**: A single underscore prefix (e.g., `_salary`) is a convention to indicate that a member is "protected" and intended for internal use.
3.  **Private (by convention)**: A double underscore prefix (e.g., `__name`) triggers "name mangling," making it harder to access from outside the class.

### A Note on Access Modifier Order

Unlike in C++, the concept of ordering or grouping members under `public` or `private` blocks does not apply to Python. In Python, visibility is determined on a per-member basis by its name (e.g., `__my_private_var`). The order of definition does not affect accessibility.

