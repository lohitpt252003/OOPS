class Student {
    constructor(name = "Unknown", age = 0) {
        this.name = name;
        this.age = age;
    }

    display() {
        console.log(`Name: ${this.name}, Age: ${this.age}`);
    }
}

const s1 = new Student(); // Uses default parameters
s1.display();

const s2 = new Student("Lohit"); // Overrides the default name
s2.display();

const s3 = new Student("Lohit P T", 21); // Provides all arguments
s3.display();
