class Teacher {
    constructor(name, department) {
        this.name = name;
        this.department = department;
    }

    print() {
        console.log(`Name: ${this.name}, Department: ${this.department}`);
    }
}

const teacher1 = new Teacher("Dr. Smith", "Computer Science");
teacher1.print();
