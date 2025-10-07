class Teacher {
    constructor(name, department, salary, subject) {
        this.name = name;
        this.department = department;
        this.salary = salary;
        this.subject = subject;
    }

    displayDetails() {
        console.log(`Name: ${this.name}`);
        console.log(`Department: ${this.department}`);
        console.log(`Salary: ${this.salary}`);
        console.log(`Subject: ${this.subject}`);
    }
}

const teacher1 = new Teacher("Dr. Smith", "Computer Science", 60000.0, "Programming");
// Accessing attributes directly
console.log(`Teacher's Name: ${teacher1.name}`);
teacher1.displayDetails();
