class SimpleClass:
    def __init__(self, name):
        self.name = name
        print(f"{self.name}: Constructor called.")

    # No custom __del__ method is defined.


print("Creating an object of SimpleClass.")
obj = SimpleClass("MyObject")
print("The object has been created.")

# When 'obj' is no longer referenced (e.g., at the end of the script),
# Python's garbage collector will automatically reclaim its memory.
# There is no special output because no custom __del__ method was defined.

print("End of script. Garbage collection will happen automatically.")
