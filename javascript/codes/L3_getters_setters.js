class Student {
    #name;
    #age;

    get name() {
        return this.#name;
    }

    set name(newName) {
        this.#name = newName;
    }

    get age() {
        return this.#age;
    }

    set age(newAge) {
        if (newAge > 0) {
            this.#age = newAge;
        }
    }
}

const s1 = new Student();
s1.name = "Lohit";
s1.age = 21;

console.log(`Name: ${s1.name}`);
console.log(`Age: ${s1.age}`);
