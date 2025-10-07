class Teacher {
    #name;
    #department;

    constructor(name, department) {
        this.#name = name;
        this.#department = department;
    }

    print() {
        console.log(`Name: ${this.#name}, Department: ${this.#department}`);
    }
}

const teacher1 = new Teacher("Dr. Smith", "Computer Science");
teacher1.print();

// The following line would cause an error because '#name' is private
// console.log(teacher1.#name); // Error
