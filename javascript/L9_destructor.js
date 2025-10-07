class MyClass {
    constructor(name) {
        this.name = name;
        console.log(`${this.name}: Constructor called`);
    }
}

function run() {
    let obj = new MyClass("myObject");
    console.log("Object created");
}

run();
console.log("Function 'run' has finished. The object is now out of scope and eligible for garbage collection, but there's no guaranteed destructor call.");
