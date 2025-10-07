class MyString {
    constructor(data) {
        this.data = data;
    }

    clone() {
        return new MyString(this.data);
    }
}

const s1 = new MyString("Hello");

// Custom copy constructor (deep copy)
const s2 = s1.clone();

s1.data += " World";

console.log(`s1.data: ${s1.data}`);
console.log(`s2.data: ${s2.data}`);
