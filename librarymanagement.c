#include <stdio.h>
#include <string.h>

// Structure for storing book information
struct Book {
    int book_id;
    char title[100];
    char author[100];
    int quantity;
};

// Structure for storing library member information
struct Member {
    int member_id;
    char name[100];
    int books_borrowed;
};

// Function to add a book to the library
void addBook(struct Book library[], int *bookCount) {
    printf("Enter book title: ");
    scanf("%s", library[*bookCount].title);
    printf("Enter author: ");
    scanf("%s", library[*bookCount].author);
    printf("Enter quantity: ");
    scanf("%d", &library[*bookCount].quantity);
    library[*bookCount].book_id = *bookCount + 1;
    (*bookCount)++;
    printf("Book added successfully!\n");
}

// Function to display all books in the library
void displayBooks(struct Book library[], int bookCount) {
    printf("Books in the library:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book ID: %d\n", library[i].book_id);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Quantity: %d\n", library[i].quantity);
        printf("\n");
    }
}

int main() {
    struct Book library[100]; // Array to store books
    struct Member members[100]; // Array to store members
    int bookCount = 0;
    int memberCount = 0;

    int choice;
    do {
        printf("Library Management System\n");
        printf("1. Add a Book\n");
        printf("2. Display Books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
