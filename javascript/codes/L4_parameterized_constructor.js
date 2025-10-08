class Book {
    constructor(title, author) {
        this.title = title;
        this.author = author;
    }

    display() {
        console.log(`Title: ${this.title}, Author: ${this.author}`);
    }
}

const myBook = new Book("The Lord of the Rings", "J.R.R. Tolkien");
myBook.display();
