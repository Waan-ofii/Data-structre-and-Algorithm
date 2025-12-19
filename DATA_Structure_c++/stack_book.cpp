
#include <iostream>
#include <stack>
 #include <string>

using namespace std;

struct Book {
      int id;
      string title;
      string author;
 };
void displayBook(const Book& a) {
    cout << "ID: " << a.id << endl;
    cout << "Title: " << a.title << endl;
    cout << "Author: " << a.author << endl;
}

    int main() {
        stack<Book>library;
        int choice;
        do{

cout << "1. Push New Book\n";
cout << "2. View Top Book\n";
 cout << "3. Pop  Book\n";
  cout << "4. Display All Books\n";
  cout << "5. Exit\n";
  cout << "Enter your choice: ";
  cin >> choice;
  cin.ignore(); // Clear newline
  if (choice == 1) {
        Book newBook;
  cout << "Enter Book ID: ";
  cin >> newBook.id;
  cin.ignore();
  cout << "Enter Book Title: ";
  getline(cin, newBook.title);
  cout << "Enter Book Author: ";
  getline(cin, newBook.author);
   library.push(newBook);//add data to the stack
  cout << "Book added to the stack.\n"; }
  else if (choice == 2) {
        if (!library.empty()) {
            cout << "\nTop Book:\n";
            displayBook(library.top());
  }
 else { cout << "Stack is empty.\n"; } }
 else if (choice == 3) {
        if (!library.empty()) {
            cout << "Removing top book:\n";
displayBook(library.top());
library.pop(); }
else { cout << "Stack is empty.\n"; } }
else if (choice == 4) {
        if (library.empty()) {
            cout << "No books in the stack.\n"; }
else {
        stack<Book> tempStack = library; // Copy stack to preserve original
cout << "\nAll Books in Stack:\n";
while (!tempStack.empty()) {
    displayBook(tempStack.top());
tempStack.pop();
}
}
} else if (choice == 5) {
    cout << "Exiting program.\n"; }
    else { cout << "Invalid choice. Try again.\n"; } }
    while (choice != 5);
    return 0; }

