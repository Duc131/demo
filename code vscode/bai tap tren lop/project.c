#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_BORROWERS 100

int i, j;

struct book
{
    char title[50];
    char author[50];
    int quantity;
};

struct borrower
{
    int id;
    char name[50];
    char book[50];
    int num_books;
    char borrow_date[20];
    char due_date[20];
    int loan_term;
};

struct library
{
    struct book books[MAX_BOOKS];
    int num_books;
    struct borrower borrowers[MAX_BORROWERS];
    int num_borrowers;
};

void display_books(struct library *lib)
{
    int choice;
    printf("Sort by:\n1. Title\n2. Author\n3. Quantity\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        for (i = 0; i < lib->num_books; i++)
        {
            for ( j = i + 1; j < lib->num_books; j++)
            {
                if (strcmp(lib->books[i].title, lib->books[j].title) > 0)
                {
                    struct book temp = lib->books[i];
                    lib->books[i] = lib->books[j];
                    lib->books[j] = temp;
                }
            }
        }
        printf("Books sorted by title:\n");
        break;
    case 2:
        for (i = 0; i < lib->num_books; i++)
        {
            for (j = i + 1; j < lib->num_books; j++)
            {
                if (strcmp(lib->books[i].author, lib->books[j].author) > 0)
                {
                    struct book temp = lib->books[i];
                    lib->books[i] = lib->books[j];
                    lib->books[j] = temp;
                }
            }
        }
        printf("Books sorted by author:\n");
        break;
    case 3:
        for (i = 0; i < lib->num_books; i++)
        {
            for (j = i + 1; j < lib->num_books; j++)
            {
                if (lib->books[i].quantity > lib->books[j].quantity)
                {
                    struct book temp = lib->books[i];
                    lib->books[i] = lib->books[j];
                    lib->books[j] = temp;
                }
            }
        }
        printf("Books sorted by quantity:\n");
        break;
    default:
        printf("Invalid choice.\n");
        return;
    }
    for (i = 0; i < lib->num_books; i++)
    {
        printf("%s by %s, quantity: %d\n", lib->books[i].title, lib->books[i].author, lib->books[i].quantity);
    }
}


void manage_books(struct library *lib)
{
    int choice;
    printf("Do you want to:\n1. Display books\n2. Update book details\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        display_books(lib);
        break;
    case 2:
        // code for updating book details
        break;
    default:
        printf("Invalid choice.\n");
        break;
    }
}


void enter_book(struct library *lib)
{
    if (lib->num_books == MAX_BOOKS)
    {
        printf("The library is full, cannot add more books.\n");
        return;
    }
	printf("Enter the book title: ");
	fflush(stdin);
	fgets(lib->books[lib->num_books].title, 50, stdin);
	lib->books[lib->num_books].title[strcspn(lib->books[lib->num_books].title, "\n")] = 0;
	
	printf("Enter the author name: ");
	fflush(stdin);
	fgets(lib->books[lib->num_books].author, 50, stdin);
	lib->books[lib->num_books].author[strcspn(lib->books[lib->num_books].author, "\n")] = 0;
	
    printf("Enter the quantity: ");
    scanf("%d", &lib->books[lib->num_books].quantity);
    
    lib->num_books++;
    printf("Book added successfully.\n");
}


void book_status(struct library *lib)
{
    char title[100];
    printf("Enter the book title: ");
    fflush(stdin);   
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = '\0';
    
    for (i = 0; i < lib->num_books; i++)
    {
        if (strcmp(lib->books[i].title, title) == 0)
        {
            printf("%s by %s, quantity: %d\n", lib->books[i].title, lib->books[i].author, lib->books[i].quantity);
            int choice;
            printf("Do you want to:\n1. Increase quantity\n2. Decrease quantity\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter the quantity to add: ");
                int quantity;
                scanf("%d", &quantity);
                lib->books[i].quantity += quantity;
                printf("Quantity updated successfully.\n");
                break;
            case 2:
                printf("Enter the quantity to remove: ");
                scanf("%d", &quantity);
                if (quantity > lib->books[i].quantity)
                {
                    printf("Cannot remove more books than available.\n");
                }
                else
                {
                    lib->books[i].quantity -= quantity;
                    printf("Quantity updated successfully.\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
                return;
            }
            return;
        }
    }
    printf("Book not found.\n");
}

void lend_book(struct library *lib)
{
    int id, quantity;
    char title[100], borrow_date[20], due_date[20];

    printf("Enter borrower ID: ");
    fflush(stdin);    
    scanf("%d", &id);
    
    
    printf("Enter the book title: ");
    fflush(stdin);
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = '\0';
    
    printf("Enter the number of books to borrow: ");
    fflush(stdin);
    scanf("%d", &quantity);
    
    printf("Enter the borrow date (dd-mm-yyyy): ");
    fflush(stdin);
    scanf("%s", borrow_date);
    
    printf("Enter the due date (dd-mm-yyyy): ");
    fflush(stdin);
    scanf("%s", due_date);

    printf("Enter the loan term (in days): ");
    int loan_term;
    fflush(stdin);
    scanf("%d", &loan_term);
    for (i = 0; i < lib->num_books; i++)
    {
        if (strcmp(lib->books[i].title, title) == 0)
        {
            if (lib->books[i].quantity < quantity)
            {
                printf("Not enough books available to lend.\n");
                return;
            }
            lib->books[i].quantity -= quantity;
            strcpy(lib->borrowers[lib->num_borrowers].book, title);
            lib->borrowers[lib->num_borrowers].id = id;
            lib->borrowers[lib->num_borrowers].num_books = quantity;
            strcpy(lib->borrowers[lib->num_borrowers].borrow_date, borrow_date);
            strcpy(lib->borrowers[lib->num_borrowers].due_date, due_date);
            lib->borrowers[lib->num_borrowers].loan_term = loan_term;
            lib->num_borrowers++;
            printf("%d book(s) borrowed successfully by borrower %d.\n", quantity, id);
            return;
        }
    }
    printf("Book not found.\n");
}

int main()
{
    struct library lib;
    lib.num_books = 0;
    lib.num_borrowers = 0;
    int choice;
    do
    {
        printf("\n===Menu===\n");
        printf("1. Enter a book\n");
        printf("2. Manage library books\n");
        printf("3. Book status\n");
        printf("4. Lend book\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enter_book(&lib);
            break;
        case 2:
            manage_books(&lib);
            break;
        case 3:
            book_status(&lib);
            break;
        case 4:
            lend_book(&lib);
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (choice != 5);
    return 0;
}
