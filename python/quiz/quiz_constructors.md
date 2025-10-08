# Quiz: Constructor Overloading in Python

**Question:** Does Python support constructor overloading like C++ does? Look at the code below from the `L5_constructor_overloading_workaround.py` file. How does it achieve a similar result without true overloading?

**Code:**

```python
class Box:
    # Single constructor with default arguments
    def __init__(self, length=0, breadth=0, height=0):
        self.length = length
        self.breadth = breadth
        self.height = height
        print("Constructor called.")

    def get_volume(self):
        return self.length * self.breadth * self.height

# Creating objects using the same constructor
box1 = Box()
print(f"Volume of box1: {box1.get_volume()}")

box2 = Box(5.0)
print(f"Volume of box2: {box2.get_volume()}")

box3 = Box(10.0, 5.0, 2.0)
print(f"Volume of box3: {box3.get_volume()}")
```

**Explanation:**

The output will be:

```
Constructor called.
Volume of box1: 0
Constructor called.
Volume of box2: 0
Constructor called.
Volume of box3: 100.0
```

Wait, the volume for `box2` is 0, not 125! Why?

This demonstrates the key difference in Python. Python **does not support constructor overloading**. If you define multiple `__init__` methods, the last one defined will simply overwrite all the previous ones. 

The standard Pythonic workaround is to define a **single constructor with default arguments**.

In our example, `__init__(self, length=0, breadth=0, height=0)` can be called with zero, one, two, or three arguments. However, when we call `Box(5.0)`, it only sets `length` to 5.0, while `breadth` and `height` remain their default value of 0, leading to a volume of 0. 

To properly simulate overloading for a cube, you would need to add logic inside the constructor:

```python
class Box:
    def __init__(self, length=0, breadth=None, height=None):
        # If only length is provided, treat it as a cube
        if breadth is None and height is None:
            self.length = length
            self.breadth = length
            self.height = length
        else: # Otherwise, use the provided dimensions
            self.length = length
            self.breadth = breadth if breadth is not None else 0
            self.height = height if height is not None else 0
        print("Constructor called.")
```
This internal logic is how Python achieves the flexibility of multiple constructor patterns, not by having multiple constructor methods.