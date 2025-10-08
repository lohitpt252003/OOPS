// 1. Global context
console.log(this === window); // In browsers, true (or global in Node.js)

// 2. Object method
const person = {
    name: "Lohit",
    greet: function() {
        console.log(`Hello, my name is ${this.name}`);
    }
};
person.greet(); // 'this' refers to 'person'

// 3. Constructor
class Car {
    constructor(make) {
        this.make = make;
    }
}
const myCar = new Car("Toyota");
console.log(myCar.make); // 'this' refers to 'myCar'

// 4. Explicit binding with call()
function introduce(age) {
    console.log(`I am ${this.name} and I am ${age} years old.`);
}
introduce.call(person, 21); // 'this' is explicitly set to 'person'

// 5. Arrow function (lexical 'this')
const anotherPerson = {
    name: "Jane",
    sayHello: function() {
        const innerFunction = () => {
            console.log(`Hi, I'm ${this.name}`); // 'this' is inherited from sayHello's context (anotherPerson)
        };
        innerFunction();
    }
};
anotherPerson.sayHello();
