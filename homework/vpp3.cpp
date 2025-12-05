#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Book
{
    string title;
    string author;
    string publisher;
    string genre;
};

// Edit a book
Book* EditBook(Book* book, const string& newTitle, const string& newAuthor, const string& newPub, const string& newGenre)
{
    book->title = newTitle;
    book->author = newAuthor;
    book->publisher = newPub;
    book->genre = newGenre;
    return book;
}

// Print the library
void PrintBooks(const Book* books, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Publisher: " << books[i].publisher << endl;
        cout << "Genre: " << books[i].genre << endl;
        cout << "------------------------" << endl;
    }
}

// Search by title
Book* FindBookByTitle(Book* books, int size, const string& title)
{
    for (int i = 0; i < size; i++)
    {
        if (books[i].title == title)
            return &books[i];
    }
    return nullptr;
}

// Search by author
Book* FindBookByAuthor(Book* books, int size, const string& author)
{
    for (int i = 0; i < size; i++)
    {
        if (books[i].author == author)
            return &books[i];
    }
    return nullptr;
}

// Bubble sort by a specific field
void SortBooksBy(Book* books, int size, bool title, bool author, bool publisher)
{
    if (title)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (books[j].title > books[j + 1].title)
                    swap(books[j], books[j + 1]);
            }
        }
    }
    else if (author)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (books[j].author > books[j + 1].author)
                    swap(books[j], books[j + 1]);
            }
        }
    }
    else if (publisher)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (books[j].publisher > books[j + 1].publisher)
                    swap(books[j], books[j + 1]);
            }
        }
    }
}

// Trim spaces from start/end
string Trim(const string& str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    if (start == string::npos) return "";
    return str.substr(start, end - start + 1);
}

int main()
{
    Book library[10] = {
        {"The Great Gatsby", "F. Scott Fitzgerald", "Scribner", "Fiction"},
        {"To Kill a Mockingbird", "Harper Lee", "J.B. Lippincott & Co.", "Fiction"},
        {"1984", "George Orwell", "Secker & Warburg", "Dystopian"},
        {"Pride and Prejudice", "Jane Austen", "T. Egerton", "Romance"},
        {"The Catcher in the Rye", "J.D. Salinger", "Little, Brown and Company", "Fiction"},
        {"The Hobbit", "J.R.R. Tolkien", "George Allen & Unwin", "Fantasy"},
        {"Moby Dick", "Herman Melville", "Harper & Brothers", "Adventure"},
        {"War and Peace", "Leo Tolstoy", "The Russian Messenger", "Historical Fiction"},
        {"The Odyssey", "Homer", "Ancient Greece", "Epic"},
        {"Hamlet", "William Shakespeare", "N/A", "Tragedy"}
    };

    cout << "Original Library:\n";
    PrintBooks(library, 10);

    SortBooksBy(library, 10, true, false, false);
    cout << "\n\nSorted by Title:\n";
    PrintBooks(library, 10);

    cout << "TESTING SEARCH\n";
    cout << "Enter title to search >>> ";
    string title;
    getline(cin, title);
    title = Trim(title); // remove extra spaces

    Book* foundBook = FindBookByTitle(library, 10, title);
    cout << "Found Book: " << (foundBook ? foundBook->title : "Not Found") << endl;

    // Edit the real book by searching first
    Book* bookToEdit = FindBookByTitle(library, 10, "The Great Gatsby");
    if (bookToEdit)
        EditBook(bookToEdit, "The Great Gatsby - Edited", "F. Scott Fitzgerald", "Scribner", "Fiction");

    cout << "\nLibrary after editing:\n";
    PrintBooks(library, 10);
}
