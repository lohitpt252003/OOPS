# Quiz: Access Modifier Order

**Question:** What happens if you define a class where you switch between access modifiers multiple times, like in the code below? Will it compile? What will be the output?

**Code:**

This code can be found in the `L2_multiple_access_modifiers.cpp` file.

```cpp
#include <iostream>
#include <string>

class Person {
private:
    std::string name;

public:
    int age;

public: // Is this second 'public' okay?
    // Constructor
    Person(std::string n, int a) {
        name = n;
        age = a;
    }

    void printName() {
        std::cout << "Name: " << name << std::endl;
    }
};

int main() {
    Person person1("Lohit", 21);
    person1.age = 22; // Accessing public member
    std::cout << "Age: " << person1.age << std::endl;
    person1.printName();
    // person1.name = "P T"; // This would be a compile error
    return 0;
}

```

**Explanation:**

Yes, the code will compile and run without any issues. In C++, you can switch between `public`, `private`, and `protected` as many times as you need within a class definition.

-   The compiler reads the class definition sequentially.
-   When it sees an access modifier (like `private:`), all subsequent members are given that access level until another modifier is encountered.
-   In the `Person` class, `name` is declared after `private:`, so it is private.
-   Then, `age` is declared after the first `public:`, making it public.
-   The second `public:` is redundant but perfectly legal. It simply reaffirms that the following members (the constructor and the `printName` method) are also public.

This demonstrates that access modifiers apply to sections of the class definition, and you can break them into as many sections as you like.
