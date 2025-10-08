// Original object
const originalObject = {
    name: "Lohit",
    details: {
        age: 21,
        city: "Bangalore"
    },
    hobbies: ["reading", "coding"]
};

// --- Shallow Copy ---
const shallowCopySpread = { ...originalObject };
const shallowCopyAssign = Object.assign({}, originalObject);

console.log("--- Shallow Copy ---");
console.log("Original:", originalObject);
console.log("Shallow (Spread):", shallowCopySpread);
console.log("Shallow (Assign):", shallowCopyAssign);

// Modify shallow copies
shallowCopySpread.name = "Jane";
shallowCopySpread.details.age = 25; // This will affect originalObject.details.age
shallowCopyAssign.hobbies.push("gaming"); // This will affect originalObject.hobbies

console.log("\n--- After Modifying Shallow Copies ---");
console.log("Original:", originalObject); // Notice details.age and hobbies are changed
console.log("Shallow (Spread):", shallowCopySpread);
console.log("Shallow (Assign):", shallowCopyAssign);

// --- Deep Copy ---
const deepCopyJSON = JSON.parse(JSON.stringify(originalObject));

console.log("\n--- Deep Copy ---");
console.log("Original (before deep copy modification):", originalObject);
console.log("Deep (JSON):", deepCopyJSON);

// Modify deep copy
deepCopyJSON.name = "John";
deepCopyJSON.details.age = 30;
deepCopyJSON.hobbies.push("hiking");

console.log("\n--- After Modifying Deep Copy ---");
console.log("Original (after deep copy modification):", originalObject); // Original remains unchanged
console.log("Deep (JSON):", deepCopyJSON);
