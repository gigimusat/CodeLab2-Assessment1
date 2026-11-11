// Book Manager - Programming Skills Portfolio
// Reads bookData.txt (title,author,pages,id,flag), lets the user rent and return books.

//
#include <iostream> // for cout, cin
#include <fstream> // for ifstream, ofstream  
#include <string> // for string
#include <vector> // for vector
using namespace std; // avoid std:: prefix for common names
 
// Book class: represents a single book in the library
class Book {
    // Private member variables: only accessible within the class
private: 
    string title, author, id;
    int pages;
    bool available;  // true = on the shelf, false = rented out

 // Public member functions: accessible from outside the class
public: 
    Book(string t, string a, int p, string i, bool av) {  // constructor to initialize a Book object
        title = t;
        author = a;
        pages = p;
        id = i;
        available = av;
    }
// Getters for book properties
    string getTitle() { return title; }
    string getId() { return id; }
    int getPages() { return pages; }

    // Rent a book: only works if it is available. Returns true if it worked.
    bool rent() {
        if (available) {
            available = false;
            return true;
        }
        return false;
    }

    // Return a book: only works if it is rented out. Returns true if it worked.
    bool giveBack() {
        if (!available) {
            available = true;
            return true;
        }
        return false;
    }
// Print book details to the console
    void print() {
        cout << id << ": " << title << " by " << author << ", " << pages << " pages, ";
        if (available) cout << "available\n";
        else cout << "rented out\n";
    }
 // Save book details to a file
    void save(ofstream& file) {
        file << title << "," << author << "," << pages << "," << id << ",";
        if (available) file << "true\n";
        else file << "false\n";
    }
};
// Function to read an integer from the user with input validation
int readInt(string prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cin.clear();            // reset the error state
        cin.ignore(1000, '\n'); // throw away the bad input
        cout << "That is not a number. Try again: ";
    }
    cin.ignore(1000, '\n');
    return value;
}
// Main function: entry point of the program
int main() {
    vector<Book> books;

    // Read book data from a file
    ifstream file("bookData.txt");
    if (!file.is_open()) {
        cout << "Could not open bookData.txt\n";
        return 1;
    }
    string title, author, pages, id, flag;
    while (getline(file, title, ',')) {
        getline(file, author, ',');
        getline(file, pages, ',');
        getline(file, id, ',');
        getline(file, flag);
        // Create a Book object and add it to the vector
        books.push_back(Book(title, author, stoi(pages), id, flag.find("true") != string::npos));
    }
    file.close();
// User interaction loop: lets the user list, rent, or return books
    int choice = -1;
    while (choice != 0) {
        cout << "\n1. List books\n2. Rent a book\n";
        cout << "3. Return a book\n0. Save and exit\nChoice: ";
        cin >> choice;
        cin.ignore();  // ignore the newline after the number input
// Handle user choices
        if (choice == 1) {
            for (int i = 0; i < books.size(); i++) books[i].print();
        } else if (choice == 2 || choice == 3) {
            string wanted;
            bool found = false;
            cout << "Book ID: ";
            getline(cin, wanted);
            for (int i = 0; i < books.size(); i++) {
                if (books[i].getId() == wanted) {
                    found = true;
                    if (choice == 2) {
                        if (books[i].rent()) cout << "You rented " << books[i].getTitle() << ".\n";
                        else cout << "Sorry, that book is not available.\n";
                    } else {
                        if (books[i].giveBack()) cout << "You returned " << books[i].getTitle() << ".\n";
                        else cout << "That book was not rented out.\n";
                    }
                }
            }
            if (!found) cout << "No book with that ID.\n";
        }
    }

    // Save book data back to the file
    ofstream out("bookData.txt");
    for (int i = 0; i < books.size(); i++) books[i].save(out);
    out.close();
    cout << "Saved. Goodbye!\n";
    return 0;
}