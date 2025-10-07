class Person {
    constructor(name) {
        this._name = name; // Protected convention
    }
}

class Teacher extends Person {
    constructor(name, department) {
        super(name);
        this.department = department;
    }

    print() {
        console.log(`Name: ${this._name}, Department: ${this.department}`);
    }
}

const teacher1 = new Teacher("Dr. Smith", "Computer Science");
teacher1.print();

// It's possible to access _name, but the underscore indicates it's not recommended
console.log(teacher1._name);
