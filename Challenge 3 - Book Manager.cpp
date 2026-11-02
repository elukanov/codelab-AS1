#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

void showMenu() {
    cout << "\nBook Manager" << endl;
    cout << "1. Add a book" << endl;
    cout << "2. List all books" << endl;
    cout << "3. Search for a book" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    vector<Book> books;
    int choice = 0;

    while (choice != 4) {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                Book newBook;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, newBook.title);
                cout << "Enter author: ";
                getline(cin, newBook.author);
                cout << "Enter year: ";
                cin >> newBook.year;
                books.push_back(newBook);
                cout << "Book added successfully." << endl;
                break;
            }
            case 2:
                if (books.empty()) {
                    cout << "No books saved yet." << endl;
                } else {
                    cout << "\nBooks:" << endl;
                    for (size_t i = 0; i < books.size(); ++i) {
                        cout << i + 1 << ". " << books[i].title
                             << " by " << books[i].author
                             << " (" << books[i].year << ")" << endl;
                    }
                }
                break;
            case 3: {
                string searchTitle;
                cout << "Enter title to search: ";
                cin.ignore();
                getline(cin, searchTitle);

                bool found = false;
                for (const auto& book : books) {
                    if (book.title == searchTitle) {
                        cout << "Found: " << book.title << " by "
                             << book.author << " (" << book.year << ")" << endl;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "No book found with that title." << endl;
                }
                break;
            }
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Please choose 1-4." << endl;
                break;
        }
    }

    return 0;
}
