class Book:
    def __init__(self, title, author):
        self.title = title
        self.author = author

    def display(self):
        print(f"Title: {self.title}, Author: {self.author}")

my_book = Book("The Lord of the Rings", "J.R.R. Tolkien")
my_book.display()
